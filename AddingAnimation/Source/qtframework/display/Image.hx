package qtframework.display;
import flash.display.Bitmap;
import flash.display.BitmapData;
import flash.display.Sprite;
import flash.filters.BitmapFilter;
import flash.filters.GlowFilter;
import flash.geom.Point;
import flash.geom.Rectangle;
import qtframework.textures.Texture;
import qtframework.qtcore.Starling;
import qtframework.defines.DisplayAlign;

/**
 * ...
 * @author butin
 */
class Image extends Sprite
{
	private var mBitmap : Bitmap;
	private var mTexture:Texture;
	private var mFilterTexture : Texture;
	public var texture(get_texture, set_texture):Texture;
	public var isFilter(default, null) : Bool;
	private var mCurrentFilter : BitmapFilter;
	public var mAlign ( default, set_mAlign): Int;
	private var mAlignX : Float;
	private var mAlignY : Float;

	//@Butin next update: TextureSmoothing.BILINEAR
	public function new(texture:Texture, align : Int = 0) 
	{
		super();
		 if (texture != null)
		{
			mTexture = texture;
			mBitmap = new Bitmap();
			mBitmap.bitmapData = mTexture.mBitmapData;
			mBitmap.smoothing = true;
			addChild(mBitmap);
			mAlign = align;
		}
		else
		{
			throw("Texture cannot be null");
		}
		var gameScale : Float = Starling.sCurrent.mGameScale;
		scaleX = scaleY = 1 / gameScale;
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
			mBitmap.bitmapData = mTexture.mBitmapData;
			mAlign = mAlign;
		}
		return mTexture;
	}
	
	public function setGlowFilter(color : UInt = 16711680, alpha : Float = 1, blurX : Float = 6, blurY : Float = 6, strength : Float = 4, quality : Int = 1, inner : Bool = false, knockout : Bool = false):Void
	{
		mCurrentFilter = new GlowFilter(color, alpha,blurX,blurY,strength,quality,inner,knockout);
		var filterData : BitmapData = createBitmapFilter(mCurrentFilter, mTexture);
		mFilterTexture = new Texture(filterData, false);
		mBitmap.bitmapData = filterData;
		isFilter = true;
	}
	
	public function clearGlowFilter():Void
	{
		mFilterTexture.dispose();
		mBitmap.bitmapData = mTexture.mBitmapData;
		isFilter = false;
	}
	
	private function createBitmapFilter(filter : BitmapFilter, texture : Texture):BitmapData
	{
			var filterData : BitmapData = new BitmapData(texture.get_width(), texture.get_height() );
			filterData.applyFilter(texture.mBitmapData, texture.mClipping, new Point(0, 0), filter);	
			return filterData;
	}
	
	public function set_mAlign( value : Int ):Int
	{
		mAlign = value;
		if ( mAlign == DisplayAlign.CENTER )
		{
			mAlignX = cast mTexture.mBitmapData.width >> 1;
			mAlignY = cast mTexture.mBitmapData.height >> 1;
		}
		var frame:Rectangle = texture.mFrame;
		mBitmap.x = frame != null ? frame.x : 0;
		mBitmap.y = frame != null ? frame.y : 0;
		mBitmap.x -= mAlignX;
		mBitmap.y -= mAlignY;
		return value;
	}
	
}