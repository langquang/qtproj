package ;
import flash.display.Bitmap;
import flash.display.Sprite;
import flash.events.Event;
import flash.text.TextField;
import flash.Vector.Vector;
import flash.events.TouchEvent;
import flash.events.MouseEvent;
import flash.events.KeyboardEvent;
import game.entitys.EntityRip;
import game.states.BaseState;
import game.states.GamePlayState;
import game.states.LoadingState;
import game.states.MenuState;
import game.Wolverine;
import haxe.Utf8;
import openfl.display.FPS;
import qtframework.display.Image;
import qtframework.gui.QTButton;
import qtframework.qtanimation.IAnimatable;
import qtframework.qtcore.Game;
import qtframework.textures.Texture;
import qtframework.display.MovieClips;
import qtframework.qtcore.Starling;
import qtframework.events.QTEvent;
import motion.Actuate;
import motion.easing.Quad;
import qtframework.texts.QTBitmapFont;
import qtframework.texts.QTDefaultFontGenerator;
import qtframework.texts.QTFontSymbol;
import qtframework.texts.QTTextAlign;
import qtframework.texts.QTTextField;
import openfl.Assets;
import qtframework.utils.Util;
import qtframework.resources.TextBin;
import qtframework.defines.DisplayAlign;

import motion.Actuate;
import motion.easing.Quad;
import motion.easing.Quint;

/**
 * ...
 * @author butin
 */
class YourGame extends  Game implements IAnimatable
{

	private var m_LoadingState : LoadingState;
	private var m_MenuState : MenuState;
	private var m_PlayState : GamePlayState;
	//private var m_EndState : LoadingState;



	public function new(game_width : Float, game_height : Float) 
	{
		super(game_width, game_height);
		showStats(true);
		
		graphics.beginFill(0xffffff, 0.2);
		graphics.drawRect(0, 0, gameWidth, gameHeight);
		graphics.endFill();
		
		flash.Lib.current.stage.addEventListener (KeyboardEvent.KEY_UP, stage_onKeyUp);
	}
	
	override public function gameInit():Void
	{
		//m_LoadingState = new LoadingState();
		//m_LoadingState.addEventListener(QTEvent.DOWNLOAD_COMPLETE, onRunMenu);
		//addChild(m_LoadingState);
		

		var gameplay : GamePlayState = new GamePlayState();
		addChild(gameplay);
		
		var m_background  : Image = new Image(Starling.sCurrent.resources.getFrame("game_play_bg", "game_play_bg"));
		m_background.mAlign = DisplayAlign.CENTER;
		m_background.x = Starling.sCurrent.mMainGame.gameWidth / 2;
		m_background.y = Starling.sCurrent.mMainGame.gameHeight / 2;
		//addChild(m_background);
		rip  = new EntityRip();
		rip.x = gameWidth / 2;
		rip.y = gameHeight / 2;
		//addChild(rip);
		
		Starling.sCurrent.juggler.add(this);
	}
	
	var m_time : Float = 0;
	var rip : EntityRip  = null;
	public function advanceTime(time:Float):Void
	 {
		 m_time += time;
		 if (m_time > 1.5  && rip.isFree())
			{
				rip.setState(EntityRip.APPEAR);
				m_time = 0;
			}
	 }
	
	override public function calculateQuality():String
	{
		#if p770
			return Version.P770;
		#else
			return Version.HD;
		#end
	}
	
	private function onRunMenu( e : QTEvent):Void
	{
		removeChild(m_LoadingState);
		m_LoadingState.removeEventListener(QTEvent.DOWNLOAD_COMPLETE, onRunMenu);
		m_LoadingState.dispose();
		m_LoadingState = null;
		m_MenuState = new MenuState();
		m_MenuState.addEventListener(QTEvent.DOWNLOAD_COMPLETE, onRunGamePlay);
		addChild(m_MenuState);
		
	}
	
	private function onRunGamePlay( e : QTEvent):Void
	{
		removeChild(m_MenuState);
		m_MenuState.removeEventListener(QTEvent.DOWNLOAD_COMPLETE, onRunGamePlay);
		m_MenuState.dispose();
		m_MenuState = null;
		m_PlayState = new GamePlayState();
		//m_PlayState.addEventListener(QTEvent.DOWNLOAD_COMPLETE, onRunGamePlay);
		addChild(m_PlayState);
	}
	
	private function stage_onKeyUp(event : KeyboardEvent):Void
	{
		#if android
			// exit game
			if (event.keyCode == 27) 
			{
				event.stopImmediatePropagation ();
				flash.Lib.exit ();
			}
		#end
	}
	

}