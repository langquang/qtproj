package ;
import flash.display.Bitmap;
import flash.display.Sprite;
import flash.events.Event;
import flash.text.TextField;
import flash.Vector.Vector;
import flash.events.TouchEvent;
import flash.events.MouseEvent;
import game.states.BaseState;
import game.states.LoadingState;
import game.states.MenuState;
import game.Wolverine;
import haxe.Utf8;
import openfl.display.FPS;
import qtframework.display.Image;
import qtframework.gui.QTButton;
import qtframework.qtanimation.IAnimatable;
import qtframework.qtcore.Game;
import qtframework.textures.Texture;
import qtframework.display.MovieClips;
import qtframework.qtcore.Starling;
import qtframework.events.QTEvent;
import motion.Actuate;
import motion.easing.Quad;
import qtframework.texts.QTBitmapFont;
import qtframework.texts.QTDefaultFontGenerator;
import qtframework.texts.QTFontSymbol;
import qtframework.texts.QTTextAlign;
import qtframework.texts.QTTextField;
import openfl.Assets;
import qtframework.utils.Util;

/**
 * ...
 * @author butin
 */
class YourGame extends  Game
{

	private var m_LoadingState : LoadingState;
	private var m_MenuState : MenuState;
	//private var m_PlayState : LoadingState;
	//private var m_EndState : LoadingState;



	public function new(game_width : Float, game_height : Float) 
	{
		super(game_width, game_height);
		showStats(true);
		
		graphics.beginFill(0xffffff, 0.2);
		graphics.drawRect(0, 0, gameWidth, gameHeight);
		graphics.endFill();
	}
	
	override public function gameInit():Void
	{
		//m_LoadingState = new LoadingState();
		//m_LoadingState.addEventListener(QTEvent.DOWNLOAD_COMPLETE, onDownloaded);
		//addChild(m_LoadingState);
		
		Starling.sCurrent.texts.loadData();
		
		var font:QTBitmapFont = new QTBitmapFont().loadPixelizer(Assets.getBitmapData("images_hd/fontData10pt.png"), " !\"#$%&'()*+,-./" + "0123456789:;<=>?" + "@ABCDEFGHIJKLMNO" + "PQRSTUVWXYZ[]^_" + "abcdefghijklmno" + "pqrstuvwxyz{|}~\\");
		
		var content = Assets.getBytes("images_hd/vn.fnt");
		var textBytes : String = content.toString();
		
		//var str : String = Starling.sCurrent.texts.getText("text1");
		var str : String  = "11111111";
		trace(str.length);
		
		
		var XMLData = Xml.parse(textBytes);
		var font2:QTBitmapFont = new QTBitmapFont().loadAngelCode(Assets.getBitmapData("images_hd/vn.png"), XMLData);
		
		var tf : QTTextField = new QTTextField(font2);
		tf.scaleX = 1 / Starling.sCurrent.mGameScale;
		tf.scaleY = 1 / Starling.sCurrent.mGameScale;
		tf.x = gameWidth / 2;
		addChild(tf); // I don't add this component to display list as you can see

	
		tf.text =  str;
		tf.color = 0x0000ff;
		tf.background = true;
		tf.fixedWidth = false;
		tf.multiLine = true;
		tf.alignment = QTTextAlign.CENTER;
		tf.lineSpacing = 5;

		

	}
	
	private function onDownloaded( e : QTEvent):Void
	{
		removeChild(m_LoadingState);
		m_LoadingState.dispose();
		m_LoadingState = null;
		m_MenuState = new MenuState();
		addChild(m_MenuState);
		
	}
	

}