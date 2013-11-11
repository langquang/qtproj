package game.entitys;
import flash.display.Sprite;
import flash.events.Event;
import flash.events.MouseEvent;
import flash.geom.Point;
import qtframework.display.MovieClips;
import qtframework.qtanimation.DelayedCall;
import qtframework.qtanimation.IAnimatable;
import qtframework.qtcore.Starling;
import qtframework.display.Image;
import qtframework.defines.DisplayAlign;
import qtframework.events.QTEvent;

import motion.Actuate;
import motion.easing.Quad;
import motion.easing.Quint;
/**
 * ...
 * @author butin
 */
class EntityRip extends Sprite
{

	inline public static var APPEAR: Int = 0;
	inline public static var DIS_APPEAR: Int = 1;
	inline public static var HOLD_ON: Int = 2;
	inline public static var SLEEP: Int = 3;
	
	var m_hole : Image;
	var m_hole_border : Image;
	var m_zombie: Image;
	var m_hold_on_time : Float = 0;
	var m_knockout : Bool = false;
	var m_is_free : Bool = false;
	var m_life : Float = 0;
	var m_delayCall : DelayedCall = null;
	private var m_hitTest : Sprite;
	private var m_state : Int;
	private var m_curType:Int;
	private var m_skins : Array<String>;
	private var m_anim : MovieClips;
	
	public function new() 
	{
		super();
		m_skins = ["zombie_1","zombie_2"];
		m_hole  = new Image(Starling.sCurrent.resources.getFrame("game_play_items", "gp_ho"), DisplayAlign.CENTER);
		addChild(m_hole);
		m_zombie  = new Image(Starling.sCurrent.resources.getFrame("game_play_items", "zombie_1"), DisplayAlign.CENTER_BOTTOM);
		m_zombie.x += 5;
		m_zombie.y += 20;
		m_zombie.addEventListener(MouseEvent.CLICK, onKnockout);
		addChild(m_zombie);
		m_hole_border  = new Image(Starling.sCurrent.resources.getFrame("game_play_items", "gp_vien"), DisplayAlign.CENTER);
		addChild(m_hole_border);		
		// create hittest for this zombie
		var game_scale : Float = Starling.sCurrent.mGameScale;
		m_hitTest = new Sprite();
		m_hitTest.graphics.beginFill(0xff0000,0.5);
		m_hitTest.graphics.drawRect(0, 0, 145*game_scale, 195*game_scale);
		m_hitTest.graphics.endFill();
		m_hitTest.x = m_zombie.x - m_hitTest.width / 2;
		m_hitTest.y = m_zombie.y - m_zombie.height;
		m_hitTest.mouseEnabled = false;
		m_hitTest.visible = false;
		addChild(m_hitTest);
		
		m_anim = new MovieClips(Starling.sCurrent.resources.getSequenceFrame("fadeout", "animation_mc"), 12, DisplayAlign.CENTER);
		m_anim.y = -20;
		m_anim.visible = false;
		addChild(m_anim);
		m_anim.addEventListener(QTEvent.COMPLETE, onFadeComplete);
		// info
		m_hold_on_time = 0.5;
		setState(SLEEP);
	}
	
	public function showDebug( show : Bool ):Void
	{
		if ( show == true )
		{
			m_hitTest.visible = true;
		}
		else
		{
			m_hitTest.visible = false;
		}
	}
	
	public function setState(state : Int):Void
	{
		m_state = state;
		if ( m_state == APPEAR )	zombieAppear();
		else if  (m_state == DIS_APPEAR) zombieDisappear();
		else if  (m_state == HOLD_ON) zombieHoldOn();
		else if ( m_state == SLEEP ) zombieSleep();

		
	}
	
	
	private function zombieAppear():Void
	{
		Actuate.stop(m_zombie, null, true);
		m_zombie.visible = true;
		m_is_free = false;
		m_zombie.mouseChildren = true;
		Actuate.tween (m_zombie, 0.5 , { scaleY: 1 }, false).ease (Quint.easeOut).onComplete(onAppearComplete);
	}
	
	private function zombieDisappear(params : Dynamic = null):Void
	{
		Actuate.stop(m_zombie, null, true);
		m_zombie.visible = true;
		m_zombie.mouseChildren = false;
		Actuate.tween (m_zombie, 0.3 , { scaleY: 0 }, false).ease (Quint.easeOut).onComplete(onDisAppearComplete);
	}
	
	private function zombieHoldOn():Void
	{
		Actuate.stop(m_zombie, null, true);
		m_zombie.visible = true;
		m_zombie.scaleY = 1;
		m_delayCall = Starling.sCurrent.juggler.delayCall(zombieDisappear, m_hold_on_time);
	}
	
	private function zombieSleep():Void
	{
		Actuate.stop(m_zombie, null, true);
		m_zombie.visible = false;
		m_zombie.scaleY = 0;
		m_zombie.mouseChildren = true;
		m_is_free = true;
	}
	
	private function onKnockout(e : MouseEvent):Void
	{
		var _p : Point = new Point(e.localX, e.localY);
		_p = m_zombie.localToGlobal( _p );
		if ( m_hitTest.hitTestPoint( _p.x, _p.y) == true )
		{
			if ( m_delayCall != null )	Starling.sCurrent.juggler.remove(m_delayCall);
			zombieSleep();
			//animation 
			m_anim.visible = true;
			Starling.sCurrent.juggler.add(m_anim);
			m_anim.rePlay();
		}

	}
	
	private function onDisAppearComplete():Void
	{
		zombieSleep();
	}
	
	private function onAppearComplete():Void
	{
		setState(HOLD_ON);
	}
	
	public function isFree():Bool
	{
		return m_is_free;
	}
	
	public function setScale(scale : Float):Void
	{
		this.scaleX = scale;
		this.scaleY = scale;
	}
	
	public function setType(type : Int):Int
	{
		m_curType = type;
		m_zombie.texture = Starling.sCurrent.resources.getFrame("game_play_items", m_skins[m_curType]);
		return m_curType;
	}
	
	public function getType():Int
	{
		return m_curType;
	}
	
	public function onFadeComplete(e : QTEvent)
	{
		m_anim.visible = false;
		Starling.sCurrent.juggler.remove(m_anim);
		
	}
}