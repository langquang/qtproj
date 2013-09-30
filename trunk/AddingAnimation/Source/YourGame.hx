package ;
import flash.display.Bitmap;
import flash.display.BitmapData;
import flash.display.Sprite;
import flash.Lib;
import flash.text.TextField;
import openfl.display.FPS;
import qtframework.display.Image;
import qtframework.qtcore.Game;
import qtframework.textures.Texture;
import qtframework.display.MovieClips;
import qtframework.qtcore.Starling;
import flash.events.KeyboardEvent;
import flash.ui.Keyboard;
import flash.events.MouseEvent;
import flash.events.Event;
import openfl.Assets;
/**
 * ...
 * @author butin
 */
class YourGame extends  Game
{

	private var mTxt : TextField ;
	private var mNum : TextField ;
	public function new(game_width : Float, game_height : Float) 
	{
		super(game_width, game_height);
		
		graphics.beginFill(0xffffff, 0.2);
		graphics.drawRect(0, 0, gameWidth, gameHeight);
		graphics.endFill();
	}
	
	override public function gameInit():Void
	{
	
		var bg : Image = new Image(Starling.sCurrent.resources.getFrame("bg", "bg0000"));
		bg.x = 0;
		bg.y = 0;
		addChild(bg);
		
		var bitmapData : BitmapData = new BitmapData(100, 100, false,0xFF0000);
		var image : Image = new Image(new Texture(bitmapData), 0);
		image.x = -40;
		image.y = 200;
		image.alpha = 0.5;
		addChild(image);
		
		
		addChild( new FPS() );
		mTxt = new TextField();
		mTxt.x = 200;
		addChild(mTxt);
		
		mNum = new TextField();
		mNum.x = 400;
		addChild(mNum);
		
		
		stage.addEventListener(KeyboardEvent.KEY_DOWN, onKeyDown);
		stage.addEventListener (Event.ENTER_FRAME, this_onEnterFrame);
		stage.addEventListener (KeyboardEvent.KEY_UP, stage_onKeyUp);
		stage.addEventListener (MouseEvent.CLICK, stage_MouseClick);
	
	}
	
	public var zoomIn : Bool;
	public var zoomOut : Bool;
	public function onKeyDown(e : KeyboardEvent):Void
	{
		if ( e.keyCode == Keyboard.UP )
		{
			zoomOut = true;
		}
		else if(e.keyCode == Keyboard.DOWN){
			zoomIn = true;
		}
	}
	
	private function this_onEnterFrame (event:Event):Void 
	{
		if ( zoomIn )
		{
			scaleX  += 0.01;
			scaleY  += 0.01;
		}
		else if(zoomOut){
			scaleX  -= 0.01;
			scaleY  -= 0.01;
		}
		
		mTxt.text = Std.string(scaleX);
	}
	
	private var mN : Int = 0;
	private function stage_onKeyUp (event:Event):Void {
		zoomOut = false;
		zoomIn = false;
		
					//for(i in 0...500)
					//{
						//var frames : Array<Texture> = Starling.sCurrent.resources.getSequenceFrame("rada","Rada");
						//var mc : MovieClips = new MovieClips(frames,30);
						//mc.x =  Math.random()*gameWidth;
						//mc.y = Math.random()*gameHeight + 20;
						//addChild(mc);
						//Starling.sCurrent.juggler.add(mc);
						//
						//var mc : Image = new Image(Starling.sCurrent.resources.getFrame("rada", "Rada0001"));
						//mc.x =  Math.random()*gameWidth;
						//mc.y = Math.random()*gameHeight+ 20;
						//addChild(mc);
//
					//
					//
					//}
					//mN += 500;
					//mNum.text = Std.string(mN);

	}
	
	public function stage_MouseClick(e:Event)
	{
			var lasttime : Int = Lib.getTimer() ;
		

			var bitmap2 = new Bitmap (Assets.getBitmapData ("images_sd/image 1.png"));
			bitmap2.y = 80;
			bitmap2.scaleX = 1/2.25;
			bitmap2.scaleY = 1/2.25;
			addChild (bitmap2);
			
			mTxt.text = Std.string(Lib.getTimer() - lasttime );
	}
	
}