package ;
import flash.display.Sprite;
import flash.text.TextField;
import flash.Vector.Vector;
import flash.events.TouchEvent;
import flash.events.MouseEvent;
import game.Wolverine;
import openfl.display.FPS;
import qtframework.display.Image;
import qtframework.gui.QTButton;
import qtframework.qtanimation.IAnimatable;
import qtframework.qtcore.Game;
import qtframework.textures.Texture;
import qtframework.display.MovieClips;
import qtframework.qtcore.Starling;
import motion.Actuate;
import motion.easing.Quad;

/**
 * ...
 * @author butin
 */
class YourGame extends  Game implements IAnimatable
{

	private var mBackground : Image;
	private var mCreeds : Vector<Wolverine>;
	private var mtime : Float = 1;//2 s
	private var mtotaltime : Float = 0;
	
	//display
	private var mScoreImg : Image;
	private var mScoreTxt : TextField;
	// login
	private var mScoreNum : Int;
	private var mLastWolverine : Int;

	public function new(game_width : Float, game_height : Float) 
	{
		super(game_width, game_height);
		
		graphics.beginFill(0xffffff, 0.2);
		graphics.drawRect(0, 0, gameWidth, gameHeight);
		graphics.endFill();
	}
	
	override public function gameInit():Void
	{
		mBackground = new Image(Starling.sCurrent.resources.getFrame("bg", "bg0000"));
		addChild(mBackground);
		
		
		mScoreImg = new Image(Starling.sCurrent.resources.getFrame("coin", "gold0000"));
		mScoreImg.x = gameWidth - (mScoreImg.width + 50);
		addChild(mScoreImg);
		
		mScoreTxt = new TextField();
		mScoreTxt.x = gameWidth - 45;
		mScoreTxt.y = cast mScoreImg.height/2;
		mScoreTxt.textColor = 0xff0000;
		mScoreTxt.text = "0";
		addChild(mScoreTxt);
		
		
		//mCreeds = new Vector<Wolverine>(6);
		//var row : Int = 0;
		//var col : Int = 0;
		//for ( i in 0...6)
		//{
				//row = cast  i / 3;
				//col = i % 3;
				//mCreeds[i] = new Wolverine();
				//mCreeds[i].x = 50 + col*mCreeds[i].width;
				//mCreeds[i].y = 170 + row * ( mCreeds[i].height + 20 );
				//mCreeds[i].addEventListener(MouseEvent.CLICK, onTap);
				//addChild(mCreeds[i]);
		//}
		//
		//Starling.sCurrent.juggler.add(this);
		//
		//mCreeds[0].setStatus(Wolverine.Appear);
		
		

		addChild( new FPS() );
		
		
		var button : QTButton = new QTButton(Starling.sCurrent.resources.getFrame("coin", "gold0000"));
		button.x = 200;
		button.y = 200;
		addChild(button);
	}
	
	public function advanceTime(time:Float):Void
	{
		mtotaltime += time;
		if ( mtotaltime >= mtime )
		{
			mtotaltime = 0;
			var index : Int = 0;
			while (index == mLastWolverine)
			{
				index = cast ( (Math.random()*600)/100);
			}
			mCreeds[index].setStatus(Wolverine.Appear);
			mLastWolverine = index;
		}
	}
	
	public function onTap(e : MouseEvent):Void
	{
		var wolverine : Wolverine = cast e.currentTarget;		
		if( wolverine.canKick() )
		{
			wolverine.setStatus(Wolverine.Knockout);
			addScore(50,wolverine);
			
		}
	}
	
	public function addScore(value : Int, wolverine : Wolverine = null):Void
	{
		mScoreNum += value;
		if ( wolverine != null )
		{
			var mc : MovieClips = new MovieClips(Starling.sCurrent.resources.getSequenceFrame("coin", "coin"), 15);
			mc.x = wolverine.x + mc.width;
			mc.y = wolverine.y - mc.height;
			addChild(mc);
			Starling.sCurrent.juggler.add(mc);
			Actuate.tween (mc, 1, { x: mScoreTxt.x, y: mScoreTxt.y }, false).ease (Quad.easeInOut).onComplete (animateCircle, [ mc ]);
		}
		else {
			mScoreTxt.text = Std.string(mScoreNum);
		}

		

	}
	
	private function animateCircle (mc:MovieClips):Void 
	{
		mScoreTxt.text = Std.string(mScoreNum);
		removeChild(mc);
		mc = null;
	}

}