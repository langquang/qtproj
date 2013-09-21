package qtframework.events;
import flash.events.EventDispatcher;

/**
 * ...
 * @author butin
 */
class QTEvent extends flash.events.Event
{
	/** Event type for a display object that is added to a parent. */
	inline public static var ADDED:String = "added";
	/** Event type for a display object that is added to the stage */
	inline public static var ADDED_TO_STAGE:String = "addedToStage";
	/** Event type for a display object that is entering a new frame. */
	inline public static var ENTER_FRAME:String = "enterFrame";
	/** Event type for a display object that is removed from its parent. */
	inline public static var REMOVED:String = "removed";
	/** Event type for a display object that is removed from the stage. */
	inline public static var REMOVED_FROM_STAGE:String = "removedFromStage";
	/** Event type for a triggered button. */
	inline public static var TRIGGERED:String = "triggered";
	/** Event type for a display object that is being flattened. */
	inline public static var FLATTEN:String = "flatten";
	/** Event type for a resized Flash Player. */
	inline public static var RESIZE:String = "resize";
	/** Event type that may be used whenever something finishes. */
	inline public static var COMPLETE:String = "complete";
	/** Event type for a (re)created stage3D rendering context. */
	inline public static var CONTEXT3D_CREATE:String = "context3DCreate";
	/** Event type that indicates that the root DisplayObject has been created. */
	inline public static var ROOT_CREATED:String = "rootCreated";
	/** Event type for an animated object that requests to be removed from the juggler. */
	inline public static var REMOVE_FROM_JUGGLER:String = "removeFromJuggler";
	
//	private static var sEventPool:Array<QTEvent> = new Array<QTEvent>();
	// @Butin next update :  Pool events
	
	private var mData:Dynamic;
	
	public function new(type:String, data:Dynamic=null, bubbles:Bool=false) 
	{
			super(type, bubbles);
            mData = data;
	}
}