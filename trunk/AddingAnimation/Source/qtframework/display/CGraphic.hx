package qtframework.display;

import flash.display.Sprite;
import flash.display.BitmapData;
import flash.display.Bitmap;
import flash.display.TriangleCulling;
import flash.geom.Rectangle;
import flash.geom.Point;
import flash.Lib;
import flash.Vector;
import flash.events.Event;
import openfl.Assets;
import openfl.display.FPS;


/**
 * ...
 * @author butin
 */
class CGraphic extends Sprite
{

	var vs:Vector<Float>;
    var idx:Vector<Int>;
    var uvt:Vector<Float>;
    var bd:BitmapData;
	public var bms : Vector<BitmapData>;
	
	var cur : Int = 0;
	var max : Int = 31;
	var curtime : Float = 0;
	
	public function new(vc : Vector<BitmapData>) 
	{
		super();
		bms = vc;
		curtime =  Lib.getTimer();

		vs = new Vector<Float>();
        idx = new Vector<Int>();
        uvt = new Vector<Float>();
		
		var w : Int = bms[0].width;
		var h : Int = bms[0].height;
		
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
	}
	
	public function onEnterFrame(e : Event):Void
	{
		draw();
	}
	
	 public function clearBuffers () {

        vs = new Vector<Float>();
        idx = new Vector<Int>();
        uvt = new Vector<Float>();
    }
	
	public function draw () 
	{
		var time : Float = Lib.getTimer();
		if ( curtime + 35  < time)
		{
			cur++;
			if ( cur == max )
				cur = 0;
			curtime = time;
		}
	//	bd = Assets.getBitmapData("assets/Rada_" + Std.string(cur)+".png");
		graphics.clear();
		graphics.beginBitmapFill(bms[cur], null, true, true);
		graphics.drawTriangles(vs, idx, uvt, TriangleCulling.NONE);
		graphics.endFill();
        
     }
	
}