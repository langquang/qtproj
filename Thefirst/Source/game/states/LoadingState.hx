package game.states;
import flash.events.Event;
import qtframework.utils.Util;
import qtframework.display.Image;
import qtframework.qtanimation.IAnimatable;
import qtframework.qtcore.Starling;
import qtframework.defines.DisplayAlign;
import qtframework.events.QTEvent;

/**
 * ...
 * @author butin
 */
class LoadingState  extends BaseState implements IAnimatable
{
	private var m_timeLife : Float = 5; // second
	private var m_logoImg : Image;
	private var m_loadingImg : Image;
	public function new() 
	{
		super();
	}
	
	override public function initState():Void
	{
		super.initState();
		m_background = new Image(Starling.sCurrent.resources.getFrame("splashscreen", "sketch1.png"));
		m_background.mAlign = DisplayAlign.CENTER;
		m_background.x = Starling.sCurrent.mMainGame.gameWidth / 2;
		m_background.y = Starling.sCurrent.mMainGame.gameHeight / 2;
		addChild(m_background);
		
		//m_logoImg = new Image(Starling.sCurrent.resources.getFrame("loading", "loading0001"));
		//m_logoImg .mAlign = DisplayAlign.CENTER;
		//m_logoImg.x = Starling.mMainGame.gameWidth / 2;
		//m_logoImg.y = Starling.mMainGame.gameHeight * 0.3;
		//addChild(m_logoImg);
		
		//m_loadingImg = new Image(Starling.sCurrent.resources.getFrame("loading", "loading0002"));
		//m_loadingImg .mAlign = DisplayAlign.CENTER;
		//m_loadingImg.x = Starling.mMainGame.gameWidth / 2;
		//m_loadingImg.y = Starling.mMainGame.gameHeight * 0.7;
		//addChild(m_loadingImg);
	}
	
	override public function dispose():Void
	{
		super.dispose();
		removeChild(m_background);
		m_background = null;
	}
	
	override public function advanceTime(passedTime:Float):Void
	{

	}
	
	override public function onAddToStage(e : Event):Void
	{
		super.onAddToStage(e);
		Starling.sCurrent.juggler.delayCall(loadData,0.1);
	}
	
	override public function onRemoveFromStage(e : Event):Void
	{
		super.onRemoveFromStage(e);
	}
	
	private function loadData(param : Dynamic = null):Void
	{
		var beginTime : Float = Util.getSecond();
		Starling.sCurrent.resources.loadPack("gui");
		Starling.sCurrent.resources.loadPack("chacractor");
		Starling.sCurrent.resources.loadPack("menu");
		Starling.sCurrent.resources.loadPack("play");
		Starling.sCurrent.resources.loadPack("endmenu");
		var delayTime : Float = Util.getSecond()- beginTime;
		if ( delayTime < m_timeLife ){
			Starling.sCurrent.juggler.delayCall(onLoadDataComplete, m_timeLife - delayTime);
		}
		else {
			onLoadDataComplete();
		}
	}
	
	private function onLoadDataComplete(param : Dynamic = null):Void 
	{
		this.dispatchEvent(new QTEvent(QTEvent.DOWNLOAD_COMPLETE));
	}
	
}