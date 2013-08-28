package qtframework.textures;
import flash.display.Bitmap;
import flash.display.BitmapData;
import flash.geom.Point;
import flash.geom.Rectangle;

/**
 * ...
 * @author butin
 */
class Texture
{

	public  var mFrame(get_mFrame, null):Rectangle;
	public  var mBitmapData(default, null) : BitmapData;
	public var mClipping(default, null):Rectangle;
	
	public function new(data:BitmapData, isCache : Bool = true) 
	{
		if ( isCache == true ) {
			mClipping = data.rect.clone();
			mBitmapData =  new BitmapData(cast mClipping.width,  cast mClipping.height, true, 0);
			mBitmapData.copyPixels(data, mClipping, new Point(0, 0));
		}else {
			mClipping = data.rect;
			mBitmapData = data;
		}

	}
	
	public static function fromTexture(parentTexture:Texture, region:Rectangle, frame : Rectangle = null)
	{		
		var clipping : Rectangle;
		if (region == null) 
			clipping = new Rectangle(0, 0, 1, 1);
		else 
			clipping = new Rectangle(region.x, region.y, region.width, region.height);
			
		var bmData : BitmapData = new BitmapData(cast clipping.width,  cast clipping.height, true, 0);
		bmData.copyPixels(parentTexture.mBitmapData, clipping, new Point(0, 0));	
		var texture  : Texture = new Texture(bmData);
		texture.mFrame = frame;
		return texture;
	}
	
	/** Disposes the underlying texture data. */
	public function dispose():Void
	{ 
		mBitmapData.dispose();
		mFrame = null;
		mClipping = null;
	}
	
	/** The clipping rectangle, which is the region provided on initialization 
	*  scaled into [0.0, 1.0]. */
	public function get_clipping():Rectangle { return mClipping.clone(); }

	/** @inheritDoc */
	public  function get_width():Int { return cast mClipping.width; }

	/** @inheritDoc */
	public  function get_height():Int { return cast mClipping.height; }
	
	public function get_mFrame():Rectangle 
	{ 
		return mFrame != null ? mFrame.clone() : new Rectangle(0, 0, get_width(), get_height() );
	}
}