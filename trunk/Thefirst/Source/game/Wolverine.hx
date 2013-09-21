package game;
import flash.display.DisplayObject;
import flash.display.Sprite;
import flash.geom.Rectangle;
import flash.geom.Vector3D;
import flash.Vector.Vector;
import qtframework.display.Image;
import qtframework.qtanimation.IAnimatable;
import qtframework.qtcore.Game;
import qtframework.textures.Texture;
import qtframework.display.MovieClips;
import qtframework.qtcore.Starling;
import qtframework.events.QTEvent;

/**
 * ...
 * @author butin
 */
class Wolverine extends Sprite
{

	inline public static var  Normal : Int = 0;
	inline public static var Appear : Int = 1;
	inline public static var  Disappear : Int = 2;
	inline public static var  Knockout : Int = 3;
	
	private  var mState : Int = 0;
	private var mDisplay : Vector<MovieClips>;
	

	public function new() 
	{
		super();
			var frames : Array<Texture> = null;
			mState = Wolverine.Normal;
			mDisplay = new Vector<MovieClips>(4);
			
			frames = Starling.sCurrent.resources.getSequenceFrame("chacractor", "normal");
			mDisplay[Wolverine.Normal] = new MovieClips(frames,20);
			mDisplay[Wolverine.Normal] .loop = false;
			mDisplay[Wolverine.Normal] .stop();
			mDisplay[Wolverine.Normal].x = 2;
			mDisplay[Wolverine.Normal].y = -1;
			addChild(mDisplay[Wolverine.Normal] );
			Starling.sCurrent.juggler.add(mDisplay[Wolverine.Normal] );
			
			frames = Starling.sCurrent.resources.getSequenceFrame("chacractor", "appear");
			mDisplay[Wolverine.Appear] = new MovieClips(frames,20);
			mDisplay[Wolverine.Appear] .loop = false;
			mDisplay[Wolverine.Appear] .stop();
			mDisplay[Wolverine.Appear] .y = -28;
			addChild(mDisplay[Wolverine.Appear] );
			mDisplay[Wolverine.Appear] .addEventListener(QTEvent.COMPLETE, onAppearComplete);
			Starling.sCurrent.juggler.add(mDisplay[Wolverine.Appear] );
			
			frames = Starling.sCurrent.resources.getSequenceFrame("chacractor", "disappear");
			mDisplay[Wolverine.Disappear] = new MovieClips(frames,20);
			mDisplay[Wolverine.Disappear].loop = false;
			mDisplay[Wolverine.Disappear] .x= 2;
			mDisplay[Wolverine.Disappear] .stop();
			mDisplay[Wolverine.Disappear] .y = -38;
			addChild(mDisplay[Wolverine.Disappear]);
			mDisplay[Wolverine.Appear] .addEventListener(QTEvent.COMPLETE, onDisAppearComplete);
			Starling.sCurrent.juggler.add(mDisplay[Wolverine.Disappear]);
			
			frames = Starling.sCurrent.resources.getSequenceFrame("chacractor", "knockout");
			mDisplay[Wolverine.Knockout] = new MovieClips(frames,20);
			mDisplay[Wolverine.Knockout] .loop = false;
			mDisplay[Wolverine.Knockout] .stop();
			mDisplay[Wolverine.Knockout] .y = -38;
			addChild(mDisplay[Wolverine.Knockout] );
			Starling.sCurrent.juggler.add(mDisplay[Wolverine.Knockout]);
			
			updateStatus();
	}
	
	private function updateStatus():Void
	{
		mDisplay[Wolverine.Normal] .visible = false;
		mDisplay[Wolverine.Appear] .visible = false;
		mDisplay[Wolverine.Disappear] .visible = false;
		mDisplay[Wolverine.Knockout] .visible = false;
		mDisplay[mState].visible = true;
		mDisplay[mState].rePlay();
	}
	
	public function setStatus(state : Int):Void
	{
		mState = state;
		updateStatus();
	}

	
	public function onAppearComplete(e : QTEvent)
	{
		//Starling.sCurrent.juggler.delayCall(disappear, 0.5, null);
		disappear(null);
	}
	
	public function disappear(args:Array<Dynamic>):Void
	{
		if ( mState == Wolverine.Appear )
		{
			setStatus(Wolverine.Disappear);
		}
	}
	
	public function onDisAppearComplete(e : QTEvent)
	{
		Starling.sCurrent.juggler.delayCall(toNormal, 0.1, null);
	}
	
	public function toNormal(args:Array<Dynamic>):Void
	{
		if ( mState == Wolverine.Disappear )
		{
			setStatus(Wolverine.Normal);
		}
	}
	
	public function isCollide(x : Float, y : Float) : Bool
	{
		var rect : Rectangle = mDisplay[mState].rect;
		trace( Std.string(rect.x) +"  "  + Std.string(rect.y) );
		return rect.contains( x,y );
	}
	
	public function canKick():Bool
	{
		return mState == Wolverine.Appear;
	}
	
}