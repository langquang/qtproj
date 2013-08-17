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
import qtframework.qtanimation.DelayedCall;
import qtframework.qtcore.Starling;
import qtframework.events.QTEvent;


class Main extends Sprite {
	
	private var  tf : TextField;

	public function new () {
		
		super ();
		

		
		
		
		var bmData :  BitmapData = Assets.getBitmapData ("assets/B11S2Building.png");
		var bitmap = new Bitmap ();
		bitmap.x = - bitmap.width / 2;
		bitmap.y = - bitmap.height / 2;
		bitmap.smoothing = true;
		
		var container = new Sprite ();
		container.addChild (bitmap);
		container.x = stage.stageWidth / 2;
		container.y = stage.stageHeight / 2;
		
		addChild (container);
		
		tf  = new TextField();
		tf.text = "Butin";
		addChild(tf);
		
		var filter : GlowFilter = new GlowFilter(0xff0000, 1,10,10,5);

		var bmFilter = new BitmapData(bmData.width, bmData.height);
		bmFilter.applyFilter(bmData, bmData.rect, new Point(0, 0), filter);
		
		bitmap.bitmapData  = bmFilter;
		

		
		//stage.addEventListener(Event.ENTER_FRAME, onEnterFrame);
		
	var mStarling : Starling = new Starling(stage);
	mStarling.start();
	var delay : DelayedCall = mStarling.get_juggler().delayCall(delay3s, 1, null);
	delay.set_repeatCount(2);
	
	delay.addEventListener(QTEvent.REMOVE_FROM_JUGGLER, onRemove);
		
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