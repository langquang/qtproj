package;


import flash.display.Bitmap;
import flash.display.BitmapData;
import flash.display.Sprite;
import flash.events.TextEvent;
import flash.filters.GlowFilter;
import flash.geom.Point;
import flash.events.Event;
import flash.text.TextField;
import motion.easing.Elastic;
import motion.Actuate;
import openfl.Assets;
import qtframework.display.Image;
import qtframework.display.MovieClips;
import qtframework.qtanimation.DelayedCall;
import qtframework.qtcore.Starling;
import qtframework.events.QTEvent;
import qtframework.textures.Texture;
import qtframework.textures.TextureAtlas;


class Main extends Sprite {
	
	private var  tf : TextField;

	public function new () {
		
		super ();
		
		var mStarling : Starling = new Starling(stage);
		mStarling.start();
		
		var content = Assets.getBytes("assets/starling.xml");
		var root = Xml.parse(content.toString()).firstElement();
		
		var texture : Texture = new Texture(Assets.getBitmapData("assets/starling.png"));
		var fast = new haxe.xml.Fast(root);
		var textatlas : TextureAtlas = new TextureAtlas(texture, fast);
		
		var frame1 : Texture = textatlas.getTexture("Symbol 10000");
		
/*		var bitmap : Image = new Image(frame1);
		bitmap.x = 200;
		bitmap.y = 200;
		addChild(bitmap);*/
		
		var frames : Array<Texture> = textatlas.getTextures("Symbol");
		var mc : MovieClips = new MovieClips(frames,1);
		mc.x = 200;
		mc.y = 200;
		addChild(mc);
		
		mStarling.juggler.add(mc);
	}
	
	private function onEnterFrame(event:Event):Void
	{
		var t1 : Int = flash.Lib.getTimer();
		tf.text = Std.string(t1);
	}
	
	private var count : Int = 0;
	private function delay3s( args:Array<Dynamic>)
	{
		tf.text = Std.string(count);
		count++;
	}
	
		/** Removes an object from the juggler. */
	public function onRemove(event  : QTEvent):Void
	{
		tf.text = "Remove Delay";
	}
	
	
}