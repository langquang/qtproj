package game.states;
import flash.events.Event;
import flash.events.MouseEvent;
import qtframework.events.QTEvent;
import qtframework.display.Image;
import qtframework.gui.QTButton;
import qtframework.gui.QTButtonText;
import qtframework.qtanimation.IAnimatable;
import qtframework.qtcore.Starling;
import qtframework.defines.DisplayAlign;
import qtframework.texts.QTBitmapFont;
import qtframework.texts.QTTextField;
import qtframework.utils.Util;
import qtframework.texts.QTTextAlign;

/**
 * ...
 * @author butin
 */
class MenuState  extends BaseState implements IAnimatable
{
	private var m_timeLife : Float = 2; // second
	private var m_logoImg : Image;
	private var m_loadingImg : Image;
	private var m_btn_hight_score : QTButton;
	private var m_btn_sound: QTButton;
	private var m_btn_music: QTButton;
	private var m_btn_about_us: QTButton;
	private var m_btn_play: QTButton;
	private var m_img_loading: Image;
	public function new() 
	{
		super();
	}
	
	override public function initState():Void
	{
		super.initState();
		m_background = new Image(Starling.sCurrent.resources.getFrame("menu_bg", "menu_bg"));
		m_background.mAlign = DisplayAlign.CENTER;
		m_background.x = Starling.sCurrent.mMainGame.gameWidth / 2;
		m_background.y = Starling.sCurrent.mMainGame.gameHeight / 2;
		addChild(m_background);
		
		m_btn_hight_score = new QTButtonText( Starling.sCurrent.resources.getFrame("Menu", "btn_hight_score") , 10);
		m_btn_hight_score.x = 170;
		m_btn_hight_score.y = 350;
		addChild(m_btn_hight_score);
		
		m_btn_music = new QTButtonText( Starling.sCurrent.resources.getFrame("Menu", "btn_music") , 20);
		m_btn_music.x = 170;
		m_btn_music.y = 470;
		addChild(m_btn_music);		
		
		m_btn_about_us = new QTButton( Starling.sCurrent.resources.getFrame("Menu", "btn_about") );
		m_btn_about_us.x = 785;
		m_btn_about_us.y = 350;
		addChild(m_btn_about_us);	
		
		m_btn_sound = new QTButtonText( Starling.sCurrent.resources.getFrame("Menu", "btn_sound") , -30);
		m_btn_sound.x = 785;
		m_btn_sound.y = 470;
		addChild(m_btn_sound);
		
		m_btn_play = new QTButton( Starling.sCurrent.resources.getFrame("Menu", "btn_Play") );
		m_btn_play.x = Starling.sCurrent.mMainGame.gameWidth / 2;
		m_btn_play.y = Starling.sCurrent.mMainGame.gameHeight - m_btn_play.height / 2 - 15;
		m_btn_play.addEventListener(MouseEvent.CLICK, onBtnPlayClick);
		addChild(m_btn_play);	
		
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
	
	private function onBtnPlayClick(e : Event = null):Void
	{
		var beginTime : Float = Util.getSecond();
		
		// disable iteraction
		this.mouseChildren = false;
		this.mouseEnabled = false;
		// display loading
		m_img_loading = new Image(Starling.sCurrent.resources.getFrame("Menu", "loading_img"), DisplayAlign.CENTER );
		m_img_loading.x = m_btn_play.x;
		m_img_loading.y = m_btn_play.y;
		addChild(m_img_loading);
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