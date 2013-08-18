package qtframework.display;
import flash.display.Bitmap;
import flash.display.Sprite;
import flash.geom.Rectangle;
import qtframework.textures.Texture;

/**
 * ...
 * @author butin
 */
class Image extends Sprite
{
	private var mBitmap : Bitmap;
	private var mTexture:Texture;
	public var texture(get_texture, set_texture):Texture;

	//@Butin next update: TextureSmoothing.BILINEAR
	public function new(texture:Texture) 
	{
		super();
		 if (texture != null)
		{
			mTexture = texture;
			var frame:Rectangle = texture.mFrame;
			mBitmap = new Bitmap();
			mBitmap.x = frame != null ? frame.x : 0;
			mBitmap.y = frame != null ? frame.y : 0;
			mBitmap.bitmapData = mTexture.mBitmapData;
			addChild(mBitmap);
		}
		else
		{
			throw("Texture cannot be null");
		}
	}
	
	public function get_texture():Texture { return mTexture; }
	public function set_texture(texture:Texture):Texture 
	{ 
		if (texture == null)
		{
			throw("Texture cannot be null");
		}
		else if (texture != mTexture)
		{
			mTexture = texture;
			var frame:Rectangle = texture.mFrame;
			mBitmap.x = frame != null ? frame.x : 0;
			mBitmap.y = frame != null ? frame.y : 0;
			mBitmap.bitmapData = mTexture.mBitmapData;
		}
		return mTexture;
	}
	
}