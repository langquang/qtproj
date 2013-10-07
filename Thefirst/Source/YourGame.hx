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
import qtframework.resources.TextBin;

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
		
		var font:QTBitmapFont = Starling.sCurrent.texts.createPixelizerFont("fontData10pt", " !\"#$%&'()*+,-./" + "0123456789:;<=>?" + "@ABCDEFGHIJKLMNO" + "PQRSTUVWXYZ[]^_" + "abcdefghijklmno" + "pqrstuvwxyz{|}~\\");
		var font2:QTBitmapFont = Starling.sCurrent.texts.createAngleCodeFont("vn");
		Starling.sCurrent.texts.registerFont('asc2', font);
		Starling.sCurrent.texts.registerFont('unicode', font2);
		
		
		addEventListener(MouseEvent.CLICK, onKeyDown);
	}
	
	private function onDownloaded( e : QTEvent):Void
	{
		removeChild(m_LoadingState);
		m_LoadingState.dispose();
		m_LoadingState = null;
		m_MenuState = new MenuState();
		addChild(m_MenuState);
		
	}
	
	private function onKeyDown(e : Event):Void
	{
			for ( i in 0...50 )
			{
				var tf : QTTextField = new QTTextField(Starling.sCurrent.texts.getFont('unicode') );
				tf.x = gameWidth * Math.random();
				tf.y = gameHeight  * Math.random();
				tf.color = 0x0000ff;
				//tf.background = true;
				tf.fixedWidth = false;
				tf.multiLine = true;
				tf.alignment = QTTextAlign.CENTER;
				tf.lineSpacing = 5;
				tf.text =  Starling.sCurrent.texts.getText("text1");
				addChild(tf);
			}
	}
	

}