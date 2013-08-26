package;


import flash.display.Bitmap;
import flash.display.BitmapData;
import flash.display.Sprite;
import flash.events.TextEvent;
import flash.filters.GlowFilter;
import flash.geom.Point;
import flash.events.Event;
import flash.text.TextField;
import flash.utils.ByteArray;
import motion.easing.Elastic;
import motion.Actuate;
import openfl.Assets;
import openfl.display.FPS;
import qtframework.display.Image;
import qtframework.display.MovieClips;
import qtframework.qtanimation.DelayedCall;
import qtframework.qtcore.Starling;
import qtframework.events.QTEvent;
import qtframework.textures.Texture;
import qtframework.textures.TextureAtlas;


class Main extends Sprite {
	
	private var  tf : TextField;

	public function new () 
	{
		super ();	
		var mStarling : Starling =Starling.create(stage, new YourGame() );
		mStarling.start();
	}		
}