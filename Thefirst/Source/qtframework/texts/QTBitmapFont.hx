package qtframework.texts;

import flash.display.BitmapData;
import haxe.Utf8;
//import nme.display.BitmapInt32;
import flash.display.Graphics;
import flash.geom.ColorTransform;
import flash.geom.Matrix;
import flash.geom.Point;
import flash.geom.Rectangle;
import flash.utils.ByteArray;
#if (cpp || neko)
import openfl.display.Tilesheet;
#end

//Starling.sCurrent.texts.loadData();
//var font:QTBitmapFont = Starling.sCurrent.texts.createPixelizerFont("fontData10pt", " !\"#$%&'()*+,-./" + "0123456789:;<=>?" + "@ABCDEFGHIJKLMNO" + "PQRSTUVWXYZ[]^_" + "abcdefghijklmno" + "pqrstuvwxyz{|}~\\");
//var font2:QTBitmapFont = Starling.sCurrent.texts.createAngleCodeFont("vn");
//Starling.sCurrent.texts.registerFont('asc2', font);
//Starling.sCurrent.texts.registerFont('unicode', font2);
//var tf : QTTextField = new QTTextField(Starling.sCurrent.texts.getFont('unicode') );
//tf.x = gameWidth * Math.random();
//tf.y = gameHeight  * Math.random();
//tf.color = 0x0000ff;
//tf.background = true;
//tf.fixedWidth = false;
//tf.multiLine = true;
//tf.alignment = QTTextAlign.CENTER;
//tf.lineSpacing = 5;
//tf.text =  Starling.sCurrent.texts.getText("text1");
//addChild(tf);

/**
 * Holds information and bitmap glpyhs for a bitmap font.
 * @author Johan Peitz
 * 
 */
class QTBitmapFont 
{
	private static var _storedFonts:Map<String,QTBitmapFont> = new Map<String,QTBitmapFont>();
	
	private static var ZERO_POINT:Point = new Point();
	
	#if (flash || js)
	private var _glyphs:Array<BitmapData>;
	#else
	private var _glyphs:Map<Int,QTFontSymbol>;
	private var _num_letters:Int;
	private var _tileSheet:Tilesheet;
	private static var _flags = Tilesheet.TILE_SCALE | Tilesheet.TILE_ROTATION | Tilesheet.TILE_ALPHA | Tilesheet.TILE_RGB;
	#end
	private var _glyphString:String;
	private var _maxHeight:Int;
	
	#if (flash || js)
	private var _matrix:Matrix;
	private var _colorTransform:ColorTransform;
	#end
	
	private var _point:Point;
	
	/**
	 * Creates a new bitmap font using specified bitmap data and letter input.
	 * @param	pBitmapData	The bitmap data to copy letters from.
	 * @param	pLetters	String of letters available in the bitmap data.
	 */
	public function new() 
	{
		_maxHeight = 0;
		_point = new Point();
		#if (flash || js)
		_matrix = new Matrix();
		_colorTransform = new ColorTransform();
		_glyphs = [];
		#else
		_glyphs = new Map<Int,QTFontSymbol>();
		_num_letters = 0;
		#end
	}
	
	/**
	 * Loads font data in Pixelizer's format
	 * @param	pBitmapData	font source image
	 * @param	pLetters	all letters contained in this font
	 * @return				this font
	 */
	public function loadPixelizer(pBitmapData:BitmapData, pLetters:String):QTBitmapFont
	{
		reset();
		_glyphString = pLetters;
		
		if (pBitmapData != null) 
		{
			var tileRects:Array<Rectangle> = [];
			var result:BitmapData = prepareBitmapData(pBitmapData, tileRects);
			var currRect:Rectangle;
			
			#if (cpp || neko)
			_tileSheet = new Tilesheet(result);
			#end
			
			for (letterID in 0...(tileRects.length))
			{
				currRect = tileRects[letterID];
				
				// create glyph
				#if (flash || js)
				var bd:BitmapData = new BitmapData(Math.floor(currRect.width), Math.floor(currRect.height), true, 0x0);
				bd.copyPixels(pBitmapData, currRect, ZERO_POINT, null, null, true);
				
				// store glyph
				setGlyph(_glyphString.charCodeAt(letterID), bd);
				#else
				setGlyph(_glyphString.charCodeAt(letterID), currRect, letterID, 0, 0, Math.floor(currRect.width));
				#end
			}
		}
		
		return this;
	}
	
	/**
	 * Loads font data in AngelCode's format
	 * @param	pBitmapData	font image source
	 * @param	buff	font data in ByteArray format
	 * @return				this font
	 */
	public function loadAngelCode(pBitmapData:BitmapData, buff:ByteArray):QTBitmapFont
	{
		reset();
		
		if (pBitmapData != null) 
		{
			_glyphString = "";
			var rect:Rectangle = new Rectangle();
			var point:Point = new Point();
			var bd:BitmapData;
			var letterID:Int = 0;
			var charCode:Int;
			var charString:String;
			var letter_height : Int;
			var yoffset : Int;
			
			#if (cpp || neko)
			_tileSheet = new Tilesheet(pBitmapData);
			#end
			var num_char : Int = buff.readShort();
			var letterID : Int = 0;
			while ( letterID < num_char )
			{
						rect.x =  buff.readShort();	//x
						rect.y =  buff.readShort(); //y
						rect.width  =  buff.readByte();//width
						letter_height = buff.readByte();//height
						rect.height = letter_height;
						
						
						point.x = buff.readByte();//xoffset
						yoffset = buff.readByte();//yoffset
						point.y = yoffset;
						
						charCode = buff.readShort();//id
						charString = String.fromCharCode(charCode);
						_glyphString += charString;
						
						var xadvance:Int = buff.readByte();//xadvance
						var charWidth:Int = xadvance;
						
						if (rect.width > xadvance)
						{
							charWidth = Std.int(rect.width);
							point.x = 0;
						}
						
						// create glyph
						#if (flash || js)
						bd = null;
						if (charString != " " && charString != "")
						{
							bd = new BitmapData(charWidth, letter_height+ yoffset, true, 0x0);
						}
						else
						{
							bd = new BitmapData(charWidth, 1, true, 0x0);
						}
						bd.copyPixels(pBitmapData, rect, point, null, null, true);
						
						// store glyph
						setGlyph(charCode, bd);
						#else
						if (charString != " " && charString != "")
						{
							setGlyph(charCode, rect, letterID, Math.floor(point.x), Math.floor(point.y), charWidth);
						}
						else
						{
							setGlyph(charCode, rect, letterID, Math.floor(point.x), 1, charWidth);
						}
						#end
						
						letterID++;
			}
		}
		
		return this;
	}
	
	/**
	 * internal function. Resets current font
	 */
	private function reset():Void
	{
		dispose();
		_maxHeight = 0;
		#if (flash || js)
		_glyphs = [];
		#else
		_glyphs = new Map<Int,QTFontSymbol>();
		#end
		_glyphString = "";
	}
	
	public function prepareBitmapData(pBitmapData:BitmapData, pRects:Array<Rectangle>):BitmapData
	{
		var bgColor:Int = pBitmapData.getPixel(0, 0);
		var cy:Int = 0;
		var cx:Int;
		
		while (cy < pBitmapData.height)
		{
			var rowHeight:Int = 0;
			cx = 0;
			
			while (cx < pBitmapData.width)
			{
				if (Std.int(pBitmapData.getPixel(cx, cy)) != bgColor) 
				{
					// found non bg pixel
					var gx:Int = cx;
					var gy:Int = cy;
					// find width and height of glyph
					while (Std.int(pBitmapData.getPixel(gx, cy)) != bgColor)
					{
						gx++;
					}
					while (Std.int(pBitmapData.getPixel(cx, gy)) != bgColor)
					{
						gy++;
					}
					var gw:Int = gx - cx;
					var gh:Int = gy - cy;
					
					pRects.push(new Rectangle(cx, cy, gw, gh));
					
					// store max size
					if (gh > rowHeight) 
					{
						rowHeight = gh;
					}
					if (gh > _maxHeight) 
					{
						_maxHeight = gh;
					}
					
					// go to next glyph
					cx += gw;
				}
				
				cx++;
			}
			// next row
			cy += (rowHeight + 1);
		}
		
		#if neko
		var resultBitmapData:BitmapData = pBitmapData.clone();
		#else
		var resultBitmapData:BitmapData = pBitmapData.clone();
		#end
		
		#if flash
		var pixelColor:UInt;
		var bgColor32:UInt = pBitmapData.getPixel(0, 0);
		#elseif js
		var pixelColor:Int;
		var bgColor32:Int = pBitmapData.getPixel(0, 0);
		#else
		var pixelColor:Int;
		var bgColor32:Int = pBitmapData.getPixel32(0, 0);
		#end
		
		cy = 0;
		while (cy < pBitmapData.height)
		{
			cx = 0;
			while (cx < pBitmapData.width)
			{
				pixelColor = pBitmapData.getPixel32(cx, cy);
				#if neko
				//if (pixelColor.rgb == bgColor32.rgb && pixelColor.a == bgColor32.a)
				//{
					//resultBitmapData.setPixel32(cx, cy, {rgb: 0x000000, a: 0x00});
				//}
				if (pixelColor == bgColor32)
				{
					resultBitmapData.setPixel32(cx, cy, 0x00000000);
				}
				#else
				if (pixelColor == bgColor32)
				{
					resultBitmapData.setPixel32(cx, cy, 0x00000000);
				}
				#end
				cx++;
			}
			cy++;
		}
		
		return resultBitmapData;
	}
	
	#if (flash || js)
	public function getPreparedGlyphs(pScale:Float, pColor:Int, ?pUseColorTransform:Bool = true):Array<BitmapData>
	{
		var result:Array<BitmapData> = [];
		
		_matrix.identity();
		_matrix.scale(pScale, pScale);
		
		var colorMultiplier:Float = 0.00392;
		_colorTransform.redOffset = 0;
		_colorTransform.greenOffset = 0;
		_colorTransform.blueOffset = 0;
		_colorTransform.redMultiplier = (pColor >> 16) * colorMultiplier;
		_colorTransform.greenMultiplier = (pColor >> 8 & 0xff) * colorMultiplier;
		_colorTransform.blueMultiplier = (pColor & 0xff) * colorMultiplier;
		
		var glyph:BitmapData;
		var preparedGlyph:BitmapData;
		for (i in 0...(_glyphs.length))
		{
			glyph = _glyphs[i];
			var bdWidth:Int;
			var bdHeight:Int;
			if (glyph != null)
			{
				if (pScale > 0)
				{
					bdWidth = Math.ceil(glyph.width * pScale);
					bdHeight = Math.ceil(glyph.height * pScale);
				}
				else
				{
					bdWidth = 1;
					bdHeight = 1;
				}
				
				preparedGlyph = new BitmapData(bdWidth, bdHeight, true, 0x00000000);
				if (pUseColorTransform)
				{
					preparedGlyph.draw(glyph,  _matrix, _colorTransform);
				}
				else
				{
					preparedGlyph.draw(glyph,  _matrix);
				}
				result[i] = preparedGlyph;
			}
		}
		
		return result;
	}
	#end
	
	/**
	 * Clears all resources used by the font.
	 */
	public function dispose():Void 
	{
		#if (flash || js)
		var bd:BitmapData;
		for (i in 0...(_glyphs.length)) 
		{
			bd = _glyphs[i];
			if (bd != null) 
			{
				_glyphs[i].dispose();
			}
		}
		#else
		_tileSheet = null;
		_num_letters = 0;
		#end
		_glyphs = null;
	}
	
	#if (flash || js)
	/**
	 * Serializes font data to cryptic bit string.
	 * @return	Cryptic string with font as bits.
	 */
	public function getFontData():String 
	{
		var output:String = "";
		for (i in 0...(_glyphString.length)) 
		{
			var charCode:Int = _glyphString.charCodeAt(i);
			var glyph:BitmapData = _glyphs[charCode];
			output += _glyphString.substr(i, 1);
			output += glyph.width;
			output += glyph.height;
			for (py in 0...(glyph.height)) 
			{
				for (px in 0...(glyph.width)) 
				{
					output += (glyph.getPixel32(px, py) != 0 ? "1":"0");
				}
			}
		}
		return output;
	}
	#end
	
	#if (flash || js)
	private function setGlyph(pCharID:Int, pBitmapData:BitmapData):Void 
	{
		if (_glyphs[pCharID] != null) 
		{
			_glyphs[pCharID].dispose();
		}
		
		_glyphs[pCharID] = pBitmapData;
		
		if (pBitmapData.height > _maxHeight) 
		{
			_maxHeight = pBitmapData.height;
		}
	}
	#else
	private function setGlyph(pCharID:Int, pRect:Rectangle, pGlyphID:Int, ?pOffsetX:Int = 0, ?pOffsetY:Int = 0, ?pAdvanceX:Int = 0):Void 
	{
		_tileSheet.addTileRect(pRect);
		
		var symbol:QTFontSymbol = new QTFontSymbol();
		symbol.tileID = pGlyphID;
		symbol.xoffset = pOffsetX;
		symbol.yoffset = pOffsetY;
		symbol.xadvance = pAdvanceX;
		
		_glyphs.set(pCharID, symbol);
		_num_letters++;
		
		if ((Math.floor(pRect.height) + pOffsetY) > _maxHeight) 
		{
			_maxHeight = Math.floor(pRect.height) + pOffsetY;
		}
	}
	#end
	
	/**
	 * Renders a string of text onto bitmap data using the font.
	 * @param	pBitmapData	Where to render the text.
	 * @param	pText	Test to render.
	 * @param	pColor	Color of text to render.
	 * @param	pOffsetX	X position of thext output.
	 * @param	pOffsetY	Y position of thext output.
	 */
	#if flash 
	public function render(pBitmapData:BitmapData, pFontData:Array<BitmapData>, pText:String, pColor:UInt, pOffsetX:Float, pOffsetY:Float, pLetterSpacing:Int, ?pAngle:Float = 0):Void 
	#elseif js
	public function render(pBitmapData:BitmapData, pFontData:Array<BitmapData>, pText:String, pColor:Int, pOffsetX:Float, pOffsetY:Float, pLetterSpacing:Int, ?pAngle:Float = 0):Void 
	#else
	public function render(drawData:Array<Float>, pText:String, pColor:Int, pAlpha:Float, pOffsetX:Float, pOffsetY:Float, pLetterSpacing:Int, pScale:Float, ?pAngle:Float = 0, ?pUseColorTransform:Bool = true):Void 
	#end
	{
		_point.x = pOffsetX;
		_point.y = pOffsetY;
		#if (flash || js)
		var glyph:BitmapData;
		var length : Int = pText.length;
		#else
		var glyph:QTFontSymbol;
		var glyphWidth:Int;
		var length : Int = Utf8.length(pText);
		#end
		
		for (i in 0...length) 
		{	
			#if (flash || js)
			var charCode:Int = pText.charCodeAt(i);
			glyph = pFontData[charCode];
			if (glyph != null) 
			#else
			var charCode:Int = Utf8.charCodeAt(pText, i);
			glyph = _glyphs.get(charCode);
			if (_glyphs.exists(charCode))
			#end
			{
				#if (flash || js)
				pBitmapData.copyPixels(glyph, glyph.rect, _point, null, null, true);
				_point.x += glyph.width + pLetterSpacing;
				#else
				glyphWidth = glyph.xadvance;
				var red:Float = (pColor >> 16 & 0xFF) / 255;
				var green:Float = (pColor >> 8 & 0xFF) / 255;
				var blue:Float = (pColor & 0xFF) / 255;
				// x, y, tile_ID, scale, rotation, red, green, blue, alpha
				drawData.push(_point.x + glyph.xoffset * pScale);			// x
				drawData.push(_point.y + glyph.yoffset * pScale);			// y
				drawData.push(glyph.tileID);								// tile_ID
				drawData.push(pScale);										// scale
				drawData.push(0);											// rotation
				if (pUseColorTransform)
				{
					drawData.push(red);			
					drawData.push(green);
					drawData.push(blue);
				}
				else
				{
					drawData.push(1);			
					drawData.push(1);
					drawData.push(1);
				}
				drawData.push(pAlpha);										// alpha
				_point.x += glyphWidth * pScale + pLetterSpacing;
				#end
			}
		}
	}
	
	#if (cpp || neko)
	/**
	 * Internal method for actually drawing text on cpp and neko targets
	 * @param	graphics
	 * @param	drawData
	 */
	public function drawText(graphics:Graphics, drawData:Array<Float>):Void
	{
		trace(drawData.length);
		_tileSheet.drawTiles(graphics, drawData, false, _flags);
	}
	#end
	
	/**
	 * Returns the width of a certain test string.
	 * @param	pText	String to measure.
	 * @param	pLetterSpacing	distance between letters
	 * @param	pFontScale	"size" of the font
	 * @return	Width in pixels.
	 */
	public function getTextWidth(pText:String, ?pLetterSpacing:Int = 0, ?pFontScale:Float = 1.0):Int 
	{
		var w:Int = 0;
#if (flash || js)		
		var textLength:Int = pText.length;
#else
		var textLength:Int = Utf8.length(pText);
#end
		for (i in 0...(textLength)) 
		{
			
			#if (flash || js)
			var charCode:Int = pText.charCodeAt(i);
			var glyph:BitmapData = _glyphs[charCode];
			if (glyph != null) 
			{
				
				w += glyph.width;
			}
			#else
			var charCode:Int = Utf8.charCodeAt(pText,i);
			if (_glyphs.exists(charCode)) 
			{
				
				w += _glyphs.get(charCode).xadvance;
			}
			#end
		}
		
		w = Math.round(w * pFontScale);
		
		if (textLength > 1)
		{
			w += (textLength - 1) * pLetterSpacing;
		}
		
		return w;
	}
	
	/**
	 * Returns height of font in pixels.
	 * @return Height of font in pixels.
	 */
	public function getFontHeight():Int 
	{
		return _maxHeight;
	}
	
	/**
	 * Returns number of letters available in this font.
	 * @return Number of letters available in this font.
	 */
	public var numLetters(get_numLetters, null):Int;
	
	public function get_numLetters():Int 
	{
		#if (flash || js)
		return _glyphs.length;
		#else
		return _num_letters;
		#end
	}
	
	/**
	 * Stores a font for global use using an identifier.
	 * @param	pHandle	String identifer for the font.
	 * @param	pFont	Font to store.
	 */
	public static function store(pHandle:String, pFont:QTBitmapFont):Void 
	{
		_storedFonts.set(pHandle, pFont);
	}
	
	/**
	 * Retrieves a font previously stored.
	 * @param	pHandle	Identifier of font to fetch.
	 * @return	Stored font, or null if no font was found.
	 */
	public static function fetch(pHandle:String):QTBitmapFont 
	{
		var f:QTBitmapFont = _storedFonts.get(pHandle);
		return f;
	}

}