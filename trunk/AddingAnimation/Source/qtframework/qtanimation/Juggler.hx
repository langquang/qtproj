package qtframework.qtanimation;

import flash.events.EventDispatcher;
import qtframework.events.QTEvent;

/**
 * ...
 * @author butin
 */
class Juggler implements IAnimatable
{
	private var mObjects:Array<IAnimatable>;
	private var mElapsedTime :Float;
	
	/** Create an empty juggler. */
	public function new() 
	{
		mElapsedTime = 0;
        mObjects = new Array<IAnimatable>();
	}
	
	/** Adds an object to the juggler. */
	public function add(object:IAnimatable):Void
	{
		if (object  != null && Lambda.indexOf(mObjects,object) == -1) 
		{
			mObjects.push(object);
			
			var dispatcher:EventDispatcher = cast object;
            if (dispatcher != null) 
				dispatcher.addEventListener(QTEvent.REMOVE_FROM_JUGGLER, onRemove);
		}
	}
	
	/** Removes an object from the juggler. */
	public function remove(object:IAnimatable):Void
	{
		//trace("Juggler: remove Object");
		if (object == null) return;

		mObjects.remove(object);
	}
	
	 /** Removes all objects at once. */
	public function purge():Void
	{
		mObjects = null;
		mObjects = new Array<IAnimatable>();
	}
	
	 /** Delays the execution of a function until a certain time has passed. Creates an
         *  object of type 'DelayedCall' internally and returns it. Remove that object
         *  from the juggler to cancel the function func. */
	public function delayCall(func:Dynamic, delay:Float, args:Array<Dynamic>):DelayedCall
	{
		if (func == null) return null;
		
		var delayedCall:DelayedCall = new DelayedCall(func, delay, args);
		add(delayedCall);
		return delayedCall;
	}
	
	 /** Advances all objects by a certain time (in seconds). */
        public function advanceTime(time:Float):Void
        {   
            var numObjects:Int = mObjects.length;
            var currentIndex:Int = 0;
            var i:Int;
            
            mElapsedTime += time;
            if (numObjects == 0) return;
            
			for (i in 0...mObjects.length)
			{
				 var object:IAnimatable = mObjects[i];
				 if(object == null)
					mObjects.splice(i, 1);
				else
					object.advanceTime(time);
			}
					
        }
             
        /** The total life time of the juggler. */
        public function  get_ElapsedTime():Float { return mElapsedTime; }   
		
		private function onRemove(event:QTEvent):Void
        {
            remove(cast event.target);
        }
	
}