package qtframework.gui;
import flash.display.Sprite;
import flash.events.Event;
import flash.events.MouseEvent;
import flash.events.TouchEvent;
import motion.Actuate;
import motion.easing.Quad;
import qtframework.display.Image;
import qtframework.textures.Texture;
import qtframework.defines.DisplayAlign;


/**
 * ...
 * @author butin
 */
class QTButton extends Sprite
{
	private var mDisplay : Image;
	public var mAniScale: Float;
	public function new(skin : Texture) 
	{
		super();
		if (skin != null)
		{
			mDisplay = new Image(skin);
			mDisplay.mAlign = DisplayAlign.CENTER;
			addChild(mDisplay);
		}
		else
		{
			throw "QTButton: skin must not null";
		}
		
		addEventListener(Event.ADDED_TO_STAGE, onAddToStage);
		mAniScale = 0.9;
		
	}
	
	private function onAddToStage(e : Event):Void
	{
		removeEventListener(Event.ADDED_TO_STAGE, onAddToStage);
		addEventListener(MouseEvent.CLICK, onMouseClick);
		addEventListener(Event.REMOVED_FROM_STAGE, onRemoveFromStage);
		#if flash
		addEventListener(MouseEvent.ROLL_OVER, onMouseOver);
		addEventListener(MouseEvent.ROLL_OUT, onMouseOut);
		#else
		addEventListener(TouchEvent.TOUCH_ROLL_OVER, onMouseOver);
		addEventListener(TouchEvent.TOUCH_ROLL_OUT, onMouseOut);
		#end
	}
	
	private function onRemoveFromStage(e : Event):Void
	{
		removeEventListener(MouseEvent.CLICK, onMouseClick);
		removeEventListener(Event.REMOVED_FROM_STAGE, onRemoveFromStage);
		addEventListener(Event.ADDED_TO_STAGE, onAddToStage);	
		#if flash
		removeEventListener(MouseEvent.ROLL_OVER, onMouseOver);
		removeEventListener(MouseEvent.ROLL_OUT, onMouseOut);
		#else
		removeEventListener(TouchEvent.TOUCH_ROLL_OVER, onMouseOver);
		removeEventListener(TouchEvent.TOUCH_ROLL_OUT, onMouseOut);
		#end
	}
	
	private function onMouseOver(e : Event):Void
	{
		Actuate.stop(mDisplay,null,true);
		Actuate.tween (mDisplay, 0.1, { scaleX: mAniScale, scaleY: mAniScale }, false).ease (Quad.easeInOut);
	}
	
	private function onMouseOut(e : Event):Void
	{
		Actuate.stop(mDisplay,null,true);
		Actuate.tween (mDisplay, 0.1, { scaleX: 1, scaleY: 1 }, false).ease (Quad.easeInOut);
	}
	
	private function onMouseClick(e : Event):Void
	{
		Actuate.stop(mDisplay,null,true);
		Actuate.tween (mDisplay, 0.1, { scaleX: 1.1, scaleY: 1.1 }, false).ease (Quad.easeInOut).onComplete (onMouseOver, [ null ]);
	}
	
}