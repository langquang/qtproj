package qtframework.qtanimation;
import flash.events.EventDispatcher;
import qtframework.events.QTEvent;

/**
 * ...
 * @author butin
 */
class DelayedCall extends EventDispatcher implements IAnimatable
{
		private var mCurrentTime:Float = 0;
        private var mTotalTime:Float;
        private var mCall:Dynamic;
        private var mArgs:Array<Dynamic>;
        private var mRepeatCount:Int = 1;
		

		public function new(func:Dynamic, delay:Float, args:Array<Dynamic>=null) 
		{
			super();
			mCall = func;
            mTotalTime = Math.max(delay, 0.0001);
            mArgs = args;
		}
		
		public function advanceTime(time:Float):Void
        {
            var previousTime:Float = mCurrentTime;
            mCurrentTime = Math.min(mTotalTime, mCurrentTime + time);
            
            if (previousTime < mTotalTime && mCurrentTime >= mTotalTime)
            {                
                mCall(mArgs);
                
                if (mRepeatCount > 1)
                {
                    mRepeatCount -= 1;
                    mCurrentTime = 0;
                    advanceTime((previousTime + time) - mTotalTime);
                }
                else
                {
                    dispatchEvent(new QTEvent(QTEvent.REMOVE_FROM_JUGGLER));
                }
            }
        }
		
		        /** Indicates if enough time has passed, and the call has already been executed. */
        public function get_isComplete():Bool
        { 
            return mRepeatCount == 1 && mCurrentTime >= mTotalTime; 
        }
        
        /** The time for which calls will be delayed (in seconds). */
        public function get_totalTime():Float { return mTotalTime; }
        
        /** The time that has already passed (in seconds). */
        public function get_currentTime():Float { return mCurrentTime; }
        
        /** The number of times the call will be repeated. */
        public function get_repeatCount():Int { return mRepeatCount; }
        public function set_repeatCount(value:Int):Void { mRepeatCount = value; }
}