package game.states;
import flash.events.Event;
import qtframework.display.Image;
import qtframework.qtanimation.IAnimatable;
import qtframework.qtcore.Starling;
import qtframework.defines.DisplayAlign;

/**
 * ...
 * @author butin
 */
class MenuState  extends BaseState implements IAnimatable
{

private var m_logoImg : Image;
	private var m_loadingImg : Image;
	public function new() 
	{
		super();
	}
	
	override public function initState():Void
	{
		super.initState();
		m_background = new Image(Starling.sCurrent.resources.getFrame("menu", "Menu_Screen"));
		m_background.mAlign = DisplayAlign.CENTER;
		m_background.x = Starling.sCurrent.mMainGame.gameWidth / 2;
		m_background.y = Starling.sCurrent.mMainGame.gameHeight / 2;
		addChild(m_background);
	}
	
	override public function dispose():Void
	{
		super.dispose();
	}
	
	override public function advanceTime(passedTime:Float):Void
	{
		
	}
	
	override public function onAddToStage(e : Event):Void
	{
		super.onAddToStage(e);
	}
	
	override public function onRemoveFromStage(e : Event):Void
	{
		super.onRemoveFromStage(e);
	}
	
	
}