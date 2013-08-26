package ;
import flash.display.Sprite;
import openfl.display.FPS;
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

	public function new() 
	{
		super();
	}
	
	override public function gameInit():Void
	{
		addChild( new FPS());
		for (i in 0...300)
		{
			var frames : Array<Texture> = Starling.sCurrent.resources.getSequenceFrame("rada","Rada");
			var mc : MovieClips = new MovieClips(frames,24);
			mc.x =  Math.random()*600.0;
			mc.y =  Math.random() * 800.0;
			addChild(mc);
			
			Starling.sCurrent.juggler.add(mc);
		}
	}
	
}