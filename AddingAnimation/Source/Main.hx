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
import flash.Vector.Vector;
import motion.easing.Elastic;
import motion.Actuate;
import openfl.Assets;
import openfl.display.FPS;
import qtframework.display.CGraphic;
import qtframework.display.Image;
import qtframework.display.MovieClips;
import qtframework.qtanimation.DelayedCall;
import qtframework.qtcore.Starling;
import qtframework.events.QTEvent;
import qtframework.textures.Texture;
import qtframework.textures.TextureAtlas;


class Main extends Sprite {
	
	private var  tf : TextField;
	public var bms : Vector<BitmapData>;
	public function new () {
		
		super ();
		
		addChild(new FPS());
		
		var tf : TextField = new TextField();
		addChild(tf);
		#if  flash
		tf.text = "flash";
		#else
		tf.text = "other";
		#end				
	
		var mStarling : Starling = new Starling(stage);
		mStarling.start();
		var frames : Vector<Texture> = mStarling.resources.getSequenceFrame("rada","Rada");

		for (i in 0...300)
		{
			var mc : MovieClips = new MovieClips(frames,24);
			mc.x =  Math.random()*600.0;
			mc.y =  Math.random() * 800.0;
			addChild(mc);
			
			//var qq : CGraphic ;
			 //qq  = new CGraphic(frames);
			//qq.x = Math.random()*700 + 100;
			//qq.y = Math.random() * 600;
			//addChild(qq);
			//
			mStarling.juggler.add(mc);
		}

				
		
		//bms = mStarling.resources.getSequenceBitmapData("rada", "Rada");
		//
		//bms = new Vector<BitmapData>();
		//for ( i in 0...31 )
		//{
			//bms[i] = Assets.getBitmapData("images/Rada_" + Std.string(i)+".png");	
		//}
		//
		//for ( i in 0...300 )
		//{
			//var image : CGraphic = new CGraphic(bms);
			//image.x = Math.random()*500 ;
			//image.y = Math.random() * 800;
			//addChild(image);
		//}
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