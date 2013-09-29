package game.states;
import flash.display.Sprite;
import flash.events.Event;
import qtframework.display.Image;
import qtframework.qtanimation.IAnimatable;
import qtframework.qtcore.Starling;
/**
 * ...
 * @author butin
 */
class BaseState extends Sprite   implements IAnimatable
{
	inline public static var LOADING:Int = 1;
	inline public static var MENU:Int = 2;
	inline public static var PLAY:Int = 3;
	inline public static var SCORE:Int = 4;
	inline public static var US : Int = 5;
	private var m_background : Image;

	
	public function new( ) 
	{
		super();
		initState();
	}
	
	public function initState():Void
	{
		this.addEventListener(Event.ADDED_TO_STAGE, onAddToStage);
		this.addEventListener(Event.REMOVED_FROM_STAGE, onRemoveFromStage);
	}
	
	public function dispose():Void
	{
		this.removeEventListener(Event.ADDED_TO_STAGE, onAddToStage);
		this.removeEventListener(Event.REMOVED_FROM_STAGE, onRemoveFromStage);
	}
	
	public function advanceTime(passedTime:Float):Void
	{

	}
	
	public function onAddToStage(e : Event):Void
	{
		Starling.sCurrent.juggler.add(this);
	}
	
	public function onRemoveFromStage(e : Event):Void
	{
		Starling.sCurrent.juggler.remove(this);
	}
}