package game.states;
import flash.events.Event;
import qtframework.utils.Util;
import qtframework.display.Image;
import qtframework.qtanimation.IAnimatable;
import qtframework.qtcore.Starling;
import qtframework.defines.DisplayAlign;
import qtframework.events.QTEvent;
import qtframework.texts.QTBitmapFont;
/**
 * ...
 * @author butin
 */
class LoadingState  extends BaseState implements IAnimatable
{
	private var m_timeLife : Float = 1; // second
	private var m_logoImg : Image;
	private var m_loadingImg : Image;
	public function new() 
	{
		super();
	}
	
	override public function initState():Void
	{
		super.initState();
		m_background = new Image(Starling.sCurrent.resources.getFrame("splash", "lenovo770_splash.png"));
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
		
		// load texts
		Starling.sCurrent.texts.loadData();
		// load bitmapfont
		var font:QTBitmapFont = Starling.sCurrent.texts.createPixelizerFont("fontData10pt", " !\"#$%&'()*+,-./" + "0123456789:;<=>?" + "@ABCDEFGHIJKLMNO" + "PQRSTUVWXYZ[]^_" + "abcdefghijklmno" + "pqrstuvwxyz{|}~\\");
		var font2:QTBitmapFont = Starling.sCurrent.texts.createAngleCodeFont("damnnoisy");
		var font3:QTBitmapFont = Starling.sCurrent.texts.createAngleCodeFont("vn");
		Starling.sCurrent.texts.registerFont('asc2', font);
		Starling.sCurrent.texts.registerFont('damnnoisy', font2);
		Starling.sCurrent.texts.registerFont('vn', font3);
		// load graphic
		Starling.sCurrent.resources.loadPack("Menu");
		Starling.sCurrent.resources.loadPack("menu_bg");
		Starling.sCurrent.resources.loadPack("menu_items");
		Starling.sCurrent.resources.loadPack("zombie_boss");
		Starling.sCurrent.resources.loadPack("end_game_bg");
		Starling.sCurrent.resources.loadPack("end_game_items");
		Starling.sCurrent.resources.loadPack("game_play_items");
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