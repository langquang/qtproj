package qtframework.qtcore;
import flash.display.DisplayObject;
import flash.display.Sprite;
import flash.display.Stage;
import flash.events.EventDispatcher;
import flash.geom.Rectangle;
import flash.events.Event;
import flash.events.KeyboardEvent;
import flash.events.ErrorEvent;
import qtframework.qtanimation.Juggler;
import qtframework.resources.ResourceManager;

/**
 * ...
 * @author butin
 */
class Starling extends EventDispatcher
{
	inline private static var VERSION:String = "1.2";
	private var mNativeStage:Stage;
	private var mMainGame:Game;
	private var mViewPort:Rectangle;
	
	 private var mJuggler:Juggler;
	 public var juggler (get_juggler, null):Juggler;
	 
	 private var mResources : ResourceManager;
	 public var resources(get_resources, null):ResourceManager;
	 
	 private var mStarted:Bool;   
	 private var mLastFrameTimestamp : Float;
	
	public  static var sCurrent(get_sCurrent, null):Starling;
    private static var sHandleLostContext:Bool;
		
	private function new( stage:Stage, mainGame: Game) 
	{
		super();
		if (stage == null) throw ("Stage must not be null");
		
		mNativeStage = stage;
		mMainGame = mainGame;
		mNativeStage.addChild(mMainGame);
		

		mViewPort = new Rectangle(0, 0, stage.stageWidth, stage.stageHeight);
		
		mJuggler = new Juggler();
		mResources = new ResourceManager();
		mLastFrameTimestamp = getSecond();
		// register other event handlers
		stage.addEventListener(Event.ENTER_FRAME, onEnterFrame);
		//stage.addEventListener(Event.ENTER_FRAME, onEnterFrame, false, 0, true);// ???? can't use weak reference
		stage.addEventListener(KeyboardEvent.KEY_DOWN, onKey);
		stage.addEventListener(KeyboardEvent.KEY_UP, onKey);
		stage.addEventListener(Event.RESIZE, onResize);
	}
	
	
	//Disposes Shader programs and render context. 
	public function dispose():Void
	{
		stop();
		
		mNativeStage.removeEventListener(Event.ENTER_FRAME, onEnterFrame, false);
		mNativeStage.removeEventListener(KeyboardEvent.KEY_DOWN, onKey, false);
		mNativeStage.removeEventListener(KeyboardEvent.KEY_UP, onKey, false);
		mNativeStage.removeEventListener(Event.RESIZE, onResize, false);
		if (sCurrent == this) sCurrent = null;
	}
		
	  /** As soon as Starling is started, it will queue input events (keyboard/mouse/touch);   
	 *  furthermore, the method <code>nextFrame</code> will be called once per Flash Player
	 *  frame. (Except when <code>shareContext</code> is enabled: in that case, you have to
	 *  call that method manually.) */
        public function start():Void 
        { 		
            mStarted = true; 
            mLastFrameTimestamp = getSecond();
			mMainGame.gameInit();
        }
        
        /** Stops rendering. */
        public function stop():Void 
        { 
            mStarted = false; 
        }
		
		private function onEnterFrame(event:Event):Void
        {
			//trace("onEnterFrame");
            if (mStarted ) 
			{
				nextFrame();
				mMainGame.gameUpdate();
			}
        }
        
        private function onKey(event:KeyboardEvent):Void
        {
            if (!mStarted) return;

        }
        
        private function onResize(event:flash.events.Event):Void
        {

        }
		
		 /** Calls <code>advanceTime()</code> (with the time that has passed since the last frame)
         *  and <code>render()</code>. */ 
        public function nextFrame():Void
        {
            var now:Float = getSecond();
            var passedTime:Float = now - mLastFrameTimestamp;
            mLastFrameTimestamp = now;
            
            advanceTime(passedTime);
        }
		
		 /** Dispatches ENTER_FRAME events on the display list, advances the Juggler 
         *  and processes touches. */
        public function advanceTime(passedTime:Float):Void
        {        
            mJuggler.advanceTime(passedTime);
        }
		
		/** Indicates if this Starling instance is started. */
        public function isStarted():Bool { return mStarted; }
        
        /** The default juggler of this instance. Will be advanced once per frame. */
        public function get_juggler():Juggler { return mJuggler; }
		
		  /** The default resource Manager*/
        public function get_resources():ResourceManager { return mResources; }
		
		public static  function get_sCurrent():Starling
		{
			return sCurrent;
		}
		
		public static function create(stage:Stage, mainGame: Game) : Starling
		{
			sCurrent = new Starling(stage, mainGame);
			return sCurrent;
		}
		
		
		// return in second
		private function getSecond()  : Float
		{
			var time = flash.Lib.getTimer();
			return time/1000.0;
		}

		
		


	
}