package ;
import flash.display.Sprite;
import openfl.display.FPS;
import qtframework.display.Image;
import qtframework.qtcore.Game;
import qtframework.textures.Texture;
import qtframework.display.MovieClips;
import qtframework.qtcore.Starling;

/**
 * ...
 * @author butin
 */
class YourGame extends  Game
{

	public function new(game_width : Float, game_height : Float) 
	{
		super(game_width, game_height);
		
		graphics.beginFill(0xffffff, 0.2);
		graphics.drawRect(0, 0, gameWidth, gameHeight);
		graphics.endFill();
	}
	
	override public function gameInit():Void
	{
	
		var image : Image = new Image(Starling.sCurrent.resources.getFrame("bg", "bg0000"));
		image.x = 0;
		image.y = 0;
		//image.setGlowFilter(0x00ff00);
		addChild(image);
		
		for(i in 0...500)
		{
			var frames : Array<Texture> = Starling.sCurrent.resources.getSequenceFrame("rada","Rada");
			var mc : MovieClips = new MovieClips(frames,30);
			mc.x =  Math.random()*gameWidth;
			mc.y = Math.random()*gameHeight;
			//mc.setGlowFilter(0xff0000);
			addChild(mc);
			Starling.sCurrent.juggler.add(mc);
		}
		
		
		addChild( new FPS() );
	}
	
}