package qtframework.textures;
import flash.geom.Rectangle;
import flash.utils.ByteArray;
import haxe.xml.Fast;
import qtframework.utils.Util;
/**
 * ...
 * @author butin
 */
class TextureAtlas
{
	private var mAtlasTexture:Texture;
	private var mTextureRegions:Map<String, Rectangle>;
	private var mTextureFrames:Map<String, Rectangle>;
	public function new(texture:Texture, buff:ByteArray) 
	{
		mTextureRegions = new Map<String, Rectangle>();
		mTextureFrames  = new Map<String, Rectangle>();
		mAtlasTexture   = texture;
		
		if (buff != null)
			parseDescription(buff);
	}
	
	  /** Disposes the atlas texture. */
	public function dispose():Void
	{
		mAtlasTexture.dispose();
	}
	
	private function parseDescription(buff:ByteArray):Void
	{
		var name : String = "";
		var x:Float           = 0;
		var y:Float           = 0;
		var width:Float       = 0;
		var height:Float      = 0;		
		var frameX:Float  = 0;
		var frameY:Float = 0;
		var frameWidth:Float = 0;
		var frameHeight:Float = 0;
		var num : Int = buff.readShort();
		for (i in 0...num)
		{
			//name  = Util.readString(buff);
			name = buff.readUTF();
			x = buff.readShort();
			y = buff.readShort();
			width = buff.readShort();
			height  = buff.readShort();			
			frameX  = buff.readShort();
			frameY = buff.readShort();
			frameWidth = buff.readShort();
			frameHeight = buff.readShort();
			var region:Rectangle = new Rectangle(x, y, width, height);
			var frame:Rectangle  = frameWidth > 0 && frameHeight > 0 ? new Rectangle(frameX, frameY, frameWidth, frameHeight) : null;

			addRegion(name, region, frame);
		}
	}
	
	/** Retrieves a subtexture by name. Returns <code>null</code> if it is not found. */
	public function getTexture(name:String):Texture
	{
		var region:Rectangle = mTextureRegions[name];
		
		if (region == null) {
			trace("[TextureAtlas] There is no Texture of  \"" + name + "\"");
			return null;
		}
		else return Texture.fromTexture(mAtlasTexture, region, mTextureFrames[name]);
	}
	
	 /** Returns all textures that start with a certain string, sorted alphabetically
         *  (especially useful for "MovieClip"). */
	public function getTextures(prefix:String=""):Array<Texture>
	{
		var textures:Array<Texture> = new Array<Texture>();
		var names:Array<String> = new Array<String>();
				
		for ( name in mTextureRegions.keys() ) 
		{
		  		if (name.indexOf(prefix) == 0)                
					names.push(name);      
		}
		
		names.sort(compareSubTextureIndex);	
			
		for (i in 0...names.length)
		{
			textures.push(getTexture(names[i])); 
		}
		
		return textures;
	}
	
	private function compareSubTextureIndex(str1 : String, str2 : String) : Int
	{
		var  t1 : Int = Std.parseInt(str1.substr(str1.length - 4, 4));
		var t2  : Int= Std.parseInt(str2.substr(str2.length - 4, 4));
		return t1 - t2;
	}
	
	 /** Returns the region rectangle associated with a specific name. */
	public function getRegion(name:String):Rectangle
	{
		return mTextureRegions[name];
	}
	
	/** Returns the frame rectangle of a specific region, or <code>null</code> if that region 
	 *  has no frame. */
	public function getFrame(name:String):Rectangle
	{
		return mTextureFrames[name];
	}
	
	/** Adds a named region for a subtexture (described by rectangle with coordinates in 
	 *  pixels) with an optional frame. */
	public function addRegion(name:String, region:Rectangle, frame:Rectangle=null):Void
	{
		mTextureRegions[name] = region;
		mTextureFrames[name]  = frame;
	}
	
	/** Removes a region with a certain name. */
	public function removeRegion(name:String):Void
	{
		mTextureRegions.remove(name);
		mTextureFrames.remove(name);
	}
	
}