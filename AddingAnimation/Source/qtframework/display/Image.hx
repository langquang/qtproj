package qtframework.display;
import flash.display.Bitmap;
import flash.display.Sprite;
import flash.geom.Rectangle;
import flash.Vector;
import flash.display.TriangleCulling;
import flash.events.Event;
import qtframework.textures.Texture;

/**
 * ...
 * @author butin
 */
class Image extends Sprite
{
	#if flash
	private var mBitmap : Bitmap;
	#else
	private var vs:Vector<Float>;
    private var idx:Vector<Int>;
    private var uvt:Vector<Float>;
	#end
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
			#if  flash
			mBitmap = new Bitmap();
			mBitmap.x = frame != null ? frame.x : 0;
			mBitmap.y = frame != null ? frame.y : 0;
			mBitmap.bitmapData = mTexture.mBitmapData;
			addChild(mBitmap);
			#else
			vs = new Vector<Float>();
			idx = new Vector<Int>();
			uvt = new Vector<Float>();
			var w : Int = cast frame.width;
			var h : Int = cast frame.height;

			vs[0] = 0; vs[1] = h;
			vs[2] = w; vs[3] = h;
			vs[4] = 0; vs[5] = 0;
			vs[6] = w; vs[7] = 0;

			idx[0] = 0; idx[1] = 1; idx[2] = 2;
			idx[3] = 2; idx[4] = 3; idx[5] = 1;

			uvt[0] = 0.0; uvt[1] = 1.0;
			uvt[2] = 1.0; uvt[3] = 1.0;
			uvt[4] = 0.0; uvt[5] = 0.0;
			uvt[6] = 1.0; uvt[7] = 0.0;

			addEventListener(Event.ENTER_FRAME, onEnterFrame);
			#end
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
			#if  flash
			mBitmap.x = frame != null ? frame.x : 0;
			mBitmap.y = frame != null ? frame.y : 0;
			mBitmap.bitmapData = mTexture.mBitmapData;
			#end
		}
		return mTexture;
	}
	
	#if !flash
		public function onEnterFrame(e : Event):Void
		{
			draw();
		}

		public function clearBuffers ()
		{
			vs = new Vector<Float>();
			idx = new Vector<Int>();
			uvt = new Vector<Float>();
		}

		public function draw () 
		{
			graphics.clear();
			graphics.beginBitmapFill(mTexture.mBitmapData, null, true, true);
			graphics.drawTriangles(vs, idx, uvt, TriangleCulling.NONE);
			graphics.endFill();
		}
	#end
	
}