package qtframework.qtcore;

import flash.display.Sprite;
import flash.geom.Point;
import flash.geom.Rectangle;
import flash.events.Event;
import flash.Lib;
import qtframework.debug.Stats;
/**
 * ...
 * @author butin
 */
class Game extends Sprite
{
	public var gameWidth(default, null):Float;
	public var gameHeight(default, null):Float;
	public var gameScale(default, null):Float;
	public var gameOffset(default, null):Point;
	
	private var mRectTop : Rectangle;
	private var mRectBottom : Rectangle;
	private var mRectLeft : Rectangle;
	private var mRectRight : Rectangle;
	
	public var realWidth : Float;
	public var realHeight : Float;
	public var deviceWidth(default, null) : Float;
	public var deviceHeight(default, null) : Float;
	
	private var mDebugContainer : Sprite;
	private var mStats : Stats;
	
	function new(game_width : Float, game_height : Float) 
	{
		super();
		gameWidth = game_width;
		gameHeight = game_height;
		addEventListener(Event.ADDED_TO_STAGE, onAddToStage);
	};
	public function gameInit():Void{};
	public function gameUpdate():Void {};
	public function checkdevice():Void
	{
		deviceWidth 	= Lib.current.stage.stageWidth ;
		deviceHeight = Lib.current.stage.stageHeight ;

		// Scale and position game
		if (deviceWidth > deviceHeight) {
			gameScale = deviceHeight / gameHeight;
			if ((gameWidth * gameScale) > deviceWidth) {
				gameScale = deviceWidth / gameWidth;
			}
		}
		else {
			gameScale = deviceWidth / gameWidth;
			if ((gameHeight * gameScale) > deviceHeight) {
				gameScale = deviceHeight / gameHeight;
			}
		}
		realWidth  		= gameWidth * gameScale;
		realHeight		= gameHeight * gameScale;
		
		scaleX = scaleY = gameScale;
		gameOffset = new Point((deviceWidth - realWidth) * 0.5,
							   (deviceHeight - realHeight) * 0.5);
		x = gameOffset.x;
		y = gameOffset.y;
		
		//caculate mergin
		mRectTop = new Rectangle(0,0,Lib.current.stage.stageWidth,y);
		mRectBottom = new Rectangle(0,y+realHeight,deviceWidth, deviceHeight - (y+realHeight) );
		mRectLeft = new Rectangle(0,0,x, Lib.current.stage.stageHeight);
		mRectRight = new Rectangle(x + realWidth, 0, deviceWidth - (x + realWidth), deviceHeight);
		// draw margin
		//drawLeftMargin();
		//drawRightMargin();
		//drawTopMargin();
		//drawBottomMargin();
		
	}
	
	private function drawLeftMargin():Void
	{
		var maskobj : Sprite = new Sprite();
		maskobj.graphics.beginFill(0x000000);
		maskobj.graphics.drawRect(0, 0, mRectLeft.width, mRectLeft.height);
		maskobj.graphics.endFill();
		maskobj.x = mRectLeft.x;
		maskobj.y = mRectLeft.y;
		Lib.current.stage.addChild(maskobj);
	}
	
	private function drawRightMargin():Void
	{
		var maskobj : Sprite = new Sprite();
		maskobj.graphics.beginFill(0x000000);
		maskobj.graphics.drawRect(0, 0, mRectRight.width, mRectRight.height);
		maskobj.graphics.endFill();
		maskobj.x = mRectRight.x;
		maskobj.y = mRectRight.y;
		Lib.current.stage.addChild(maskobj);		
	}
	
	private function drawTopMargin():Void
	{
		var maskobj : Sprite = new Sprite();
		maskobj.graphics.beginFill(0x000000);
		maskobj.graphics.drawRect(0, 0, mRectTop.width, mRectTop.height);
		maskobj.graphics.endFill();
		maskobj.x = mRectTop.x;
		maskobj.y = mRectTop.y;
		Lib.current.stage.addChild(maskobj);	
	}
	
	private function drawBottomMargin():Void
	{
		var maskobj : Sprite = new Sprite();
		maskobj.graphics.beginFill(0x000000);
		maskobj.graphics.drawRect(0, 0, mRectBottom.width, mRectBottom.height);
		maskobj.graphics.endFill();
		maskobj.x = mRectBottom.x;
		maskobj.y = mRectBottom.y;
		Lib.current.stage.addChild(maskobj);
	}
	
	private function onAddToStage(e : Event):Void
	{
		removeEventListener(Event.ADDED_TO_STAGE, onAddToStage);
		if ( mDebugContainer == null ) 
			mDebugContainer = new Sprite();
		Lib.current.stage.addChild(mDebugContainer);
	}
	
	public function showStats( value : Bool ):Void
	{
		if ( value == true )
		{
			if ( mDebugContainer == null ) 
				mDebugContainer = new Sprite();
			if ( mStats == null )  
				mStats = new Stats();
			mDebugContainer.addChild(mStats);
		}
		else if ( mStats != null  )
		{
			removeChild(mStats);
			mStats = null;	
		}
	}
	
	
}