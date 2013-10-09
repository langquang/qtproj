package game.states;
import flash.events.Event;
import qtframework.events.QTEvent;
import qtframework.display.Image;
import qtframework.gui.QTButton;
import qtframework.qtanimation.IAnimatable;
import qtframework.qtcore.Starling;
import qtframework.defines.DisplayAlign;
import qtframework.texts.QTBitmapFont;
import qtframework.texts.QTTextField;
import qtframework.utils.Util;

/**
 * ...
 * @author butin
 */
class GamePlayState  extends BaseState implements IAnimatable
{

	private var m_timeLife : Float = 2; // second
	private var m_bar_img : Image;
	private var m_img_combo : Image;
	private var m_btn_pause : QTButton;
	public function new() 
	{
		super();
	}
	
	override public function initState():Void
	{
		super.initState();
		m_background = new Image(Starling.sCurrent.resources.getFrame("game_play_bg", "game_play_bg"));
		m_background.mAlign = DisplayAlign.CENTER;
		m_background.x = Starling.sCurrent.mMainGame.gameWidth / 2;
		m_background.y = Starling.sCurrent.mMainGame.gameHeight / 2;
		addChild(m_background);
		
		m_bar_img = new Image(Starling.sCurrent.resources.getFrame("game_play_items", "game_play_bar"));
		m_bar_img.mAlign = DisplayAlign.CENTER;
		m_bar_img.x = Starling.sCurrent.mMainGame.gameWidth / 2;
		m_bar_img.y =  m_bar_img.height / 2;
		addChild(m_bar_img);
		
		m_img_combo= new Image(Starling.sCurrent.resources.getFrame("game_play_items", "btn_combo"));
		m_img_combo.mAlign = DisplayAlign.CENTER;
		m_img_combo.x = 40 + m_img_combo.width/2;
		m_img_combo.y =  40 + m_img_combo.height/2;
		addChild(m_img_combo);
		
		m_btn_pause = new QTButton( Starling.sCurrent.resources.getFrame("game_play_items", "btn_pause") );
		m_btn_pause.x = 837;
		m_btn_pause.y = 40 + m_btn_pause.height/2;
		addChild(m_btn_pause);	
		
		var _font : QTBitmapFont = Starling.sCurrent.texts.getFont("damnnoisy");
		var tf : QTTextField = new QTTextField(_font);
		tf.x = 250;
		tf.y = 250;
		tf.text = "asddd0123456789";
		tf.color = 0xff0000;
		tf.fixedWidth = false;
		tf.multiLine = true;
		tf.lineSpacing = 5;
		//addChild(tf);
		
	}
	
	private function loadData(param : Dynamic = null):Void
	{
		var beginTime : Float = Util.getSecond();
		
		// load graphic
		Starling.sCurrent.resources.loadPack("zombie_boss");
		Starling.sCurrent.resources.loadPack("end_game_bg");
		Starling.sCurrent.resources.loadPack("end_game_items");
		Starling.sCurrent.resources.loadPack("game_play_items");
		Starling.sCurrent.resources.loadPack("game_play_bg");
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