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

	public function new() 
	{
		super();
	}
	
	override public function gameInit():Void
	{
		addChild( new FPS());
		//for (i in 0...300)
		//{
			var frames : Array<Texture> = Starling.sCurrent.resources.getSequenceFrame("rada","Rada");
			var mc : MovieClips = new MovieClips(frames,24);
			mc.x =  150.0;
			mc.y = 300.0;
			mc.setGlowFilter(0xff0000);
			addChild(mc);
			
			Starling.sCurrent.juggler.add(mc);
		//}
		
		var image : Image = new Image(Starling.sCurrent.resources.getFrame("rada", "Rada0001"));
		image.x = cast stage.width/2;
		image.y = cast stage.height / 2;
		image.setGlowFilter(0x00ff00);
		addChild(image);
	}
	
}