package;


import flash.display.Bitmap;
import flash.display.BitmapData;
import flash.display.Sprite;
import flash.events.TextEvent;
import flash.filters.GlowFilter;
import flash.geom.Point;
import flash.events.Event;
import flash.text.TextField;
import flash.utils.ByteArray;
import motion.easing.Elastic;
import motion.Actuate;
import openfl.Assets;
import openfl.display.FPS;
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
		
		var tfFPS : FPS = new FPS();
		addChild(tfFPS);
		
		var tf : TextField = new TextField();
			#if  flash
			tf.text = "flash";
			#else
			tf.text = "other";
			#end
				
				
		addChild(tf);
		
		var mStarling : Starling = new Starling(stage);
		mStarling.start();
		
		for (i in 0...100)
		{
			var frames : Array<Texture> = mStarling.resources.getSequenceFrame("rada","Rada");
			var mc : MovieClips = new MovieClips(frames,24);
			mc.x =  Math.random()*600.0 + 100;
			mc.y =  Math.random() * 800.0;
			addChild(mc);
			
			mStarling.juggler.add(mc);
		}

		
		addEventListener(Event.ENTER_FRAME, onEnterFrame);
	}
	
	private function onEnterFrame(event:Event):Void
	{	
		//trace("butin");
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