package qtframework.resources;
import flash.utils.ByteArray;
import openfl.Assets;
import flash.utils.Endian;
import qtframework.utils.Util;
import qtframework.texts.QTBitmapFont;
/**
 * ...
 * @author butin
 */
class TextBin
{
	inline public static var TEXT_BIN_NAME:String = "texts/text.bin";
	private var mQuanlity : String;
	private var m_isLoaded:Bool;
	private var m_TextData : Map<String, String>;
	private var m_FontData : Map<String, QTBitmapFont>;
	public function new(quanlity : String) 
	{
		mQuanlity = quanlity;
		m_isLoaded = false;
		m_TextData = new Map<String, String>();
		m_FontData = new Map<String, QTBitmapFont>();
	}
	
	public function loadData():Void
	{
		var buff : ByteArray = Assets.getBytes(TEXT_BIN_NAME);
		buff.endian = Endian.BIG_ENDIAN;
		var nPack : Int = buff.readShort();
		while (nPack > 0)
		{
			var id : String = Util.readString(buff);
			var value : String = Util.readString(buff);
			m_TextData[id] = value;
			nPack--;
		}
		m_isLoaded = true;
	}
	
	public function registerFont(font_name : String, font : QTBitmapFont ):Void
	{
		if( font != null )
			m_FontData[font_name] = font;
		else
			throw("can not register NULL font!");
	}
	
	public function getText(id : String):String
	{
		if ( m_TextData[id] != null )
		{
				return  m_TextData[id];
		}
		else
		{
			throw("TextBin - not exist textid = " + id);
		}
	}
	
	public function getFont(font_name : String):QTBitmapFont
	{
		if ( m_FontData[font_name] != null )
		{
				return  m_FontData[font_name];
		}
		else
		{
			throw("TextBin - not exist font name = " + font_name);
		}
		return null;
	}
	
	public function isLoaded():Bool
	{
		return m_isLoaded;
	}
	
	public   function createAngleCodeFont(name : String):QTBitmapFont
	{
		if ( m_FontData[name] == null )
		{
			var buff : ByteArray = Assets.getBytes("images" + mQuanlity+ "/" +name+".bin");
			buff.endian = Endian.BIG_ENDIAN;
			return new QTBitmapFont().loadAngelCode(Assets.getBitmapData("images" + mQuanlity + "/" +name + ".png"), buff);		
		}
		return null;
	}
	
	public   function createPixelizerFont(name : String, charactors : String):QTBitmapFont
	{
			return new QTBitmapFont().loadPixelizer(Assets.getBitmapData("images" + mQuanlity + "/" +name + ".png"), charactors);
	}
	
}