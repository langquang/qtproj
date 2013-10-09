package qtframework.gui;
import flash.display.Sprite;
import flash.events.Event;
import motion.Actuate;
import motion.easing.Quad;
import qtframework.qtcore.Starling;
import qtframework.texts.QTBitmapFont;
import qtframework.texts.QTTextAlign;
import qtframework.texts.QTTextField;
import qtframework.textures.Texture;

/**
 * ...
 * @author butin
 */
class QTButtonText extends QTButton
{
	private var m_container : Sprite;
	private var m_textfield : QTTextField;
	private var m_offset_textX : Int;
	private var m_offset_textY : Int;
	#if flash
	public function new(skin : Texture, offTxtX : Int = 0, offTxtY : Int = -3) 
	#else
	public function new(skin : Texture, offTxtX : Int = 0, offTxtY : Int = -9) 
	#end
	{
		super(skin);
		m_offset_textX = offTxtX;
		m_offset_textY = offTxtY;
		m_container = new Sprite();
		addChild(m_container);
		m_container.addChild(mDisplay);
		
		var _font : QTBitmapFont = Starling.sCurrent.texts.getFont("damnnoisy");
		m_textfield = new QTTextField(_font);
		m_textfield.color = 0xffffff;
		m_textfield.fixedWidth = false;
		m_textfield.lineSpacing = 5;
		m_textfield.text = "text";
		m_textfield.mouseChildren = false;
		locationText();
		m_container.addChild(m_textfield);
	}
	
	public function setText( str : String):Void
	{
		m_textfield.text = str;
		locationText();
	}
	
	public function setTextColor( color : Int ):Void
	{
		m_textfield.color = color;
	}
	
	private function locationText():Void
	{
		m_textfield.x = -m_textfield.width / 2;
		m_textfield.y = -m_textfield.height / 2;
		m_textfield.x += m_offset_textX;
		m_textfield.y += m_offset_textY;
	}
	
	override private function onMouseOver(e : Event):Void
	{
		Actuate.stop(m_container,null,true);
		Actuate.tween (m_container, 0.1, { scaleX: mAniScale, scaleY: mAniScale }, false).ease (Quad.easeInOut);
	}
	
	override private function onMouseOut(e : Event):Void
	{
		Actuate.stop(m_container,null,true);
		Actuate.tween (m_container, 0.1, { scaleX: 1, scaleY: 1 }, false).ease (Quad.easeInOut);
	}
	
	override private function onMouseClick(e : Event):Void
	{
		Actuate.stop(m_container,null,true);
		Actuate.tween (m_container, 0.1, { scaleX: 1.1, scaleY: 1.1 }, false).ease (Quad.easeInOut).onComplete (onMouseOver, [ null ]);
	}
	
}