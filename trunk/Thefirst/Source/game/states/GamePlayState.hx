package game.states;
import flash.events.Event;
import flash.Vector.Vector;
import qtframework.events.QTEvent;
import qtframework.display.Image;
import qtframework.gui.QTButton;
import qtframework.qtanimation.IAnimatable;
import qtframework.qtcore.Starling;
import qtframework.defines.DisplayAlign;
import qtframework.texts.QTBitmapFont;
import qtframework.texts.QTTextField;
import qtframework.utils.Util;
import game.entitys.EntityRip;
import game.Misc;

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
	
	private var m_zombie_list : Vector<EntityRip>;
	private var m_delay : Float = 0.5;
	private var m_last_appear: Float = 0;
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
		
		intZomebieList();
	}
	
	private function intZomebieList():Void
	{
		m_zombie_list = new Vector<EntityRip>(7);
		var index : Int = 0;
		for ( i in 0...7 )
		{
			index = 6 - i;
			m_zombie_list[index]  = new EntityRip();
			addChild(m_zombie_list[index]  );
		}
		m_zombie_list[0]  .x = 250;
		m_zombie_list[0]  .y = 475;
		
		m_zombie_list[1]  .x = 695;
		m_zombie_list[1]  .y = 475;
		
		m_zombie_list[2]  .x = 210;
		m_zombie_list[2]  .y = 362;
		m_zombie_list[2] .setScale(0.8);
		
		m_zombie_list[3]  .x = 478;
		m_zombie_list[3]  .y = 362;
		m_zombie_list[3] .setScale(0.8);
		
		m_zombie_list[4]  .x = 783;
		m_zombie_list[4]  .y = 362;
		m_zombie_list[4] .setScale(0.8);
		
		m_zombie_list[5]  .x = 383;
		m_zombie_list[5]  .y = 285;
		m_zombie_list[5] .setScale(0.7);
		
		m_zombie_list[6]  .x = 615;
		m_zombie_list[6]  .y = 285;
		m_zombie_list[6] .setScale(0.7);
	}
	
	override public function dispose():Void
	{
		super.dispose();
	}
	
	override public function onAddToStage(e : Event):Void
	{
		super.onAddToStage(e);
	}
	
	override public function onRemoveFromStage(e : Event):Void
	{
		super.onRemoveFromStage(e);
	}
	
	override public function advanceTime(passedTime:Float):Void
	{
		m_last_appear += passedTime;
		 if (m_last_appear > m_delay )
		{
			for ( i in 0...7)
			{
				var rip : EntityRip = m_zombie_list[getRandomZombie()];
				if ( rip.isFree() )
				{
					rip.setState(EntityRip.APPEAR);
					m_last_appear = 0;
					return;
				}
			}

		}
	}
	
	private function getRandomZombie():Int
	{
		var num : Int = Misc.randomRange(0, 700);
		return num%7;
	}
	
	
}