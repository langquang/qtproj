package qtframework.resources;
import flash.utils.ByteArray;
import openfl.Assets;
import flash.utils.Endian;
import qtframework.utils.Util;
/**
 * ...
 * @author butin
 */
class TextBin
{
	inline public static var TEXT_BIN_NAME:String = "texts/text.bin";
	private var m_isLoaded:Bool;
	private var m_Data : Map<String, String>;
	public function new() 
	{
		m_isLoaded = false;
		m_Data = new Map<String, String>();
	}
	
	public function loadData():Void
	{
		var buff : ByteArray = Assets.getBytes(TEXT_BIN_NAME);
		buff.endian = Endian.BIG_ENDIAN;
		var nPack : Int = buff.readShort();
		while (nPack > 0)
		{
			var id : String = Util.readString(buff);
			var value : String = Util.readString(buff);
			m_Data[id] = value;
			nPack--;
		}
		m_isLoaded = true;
	}
	
	public function getText(id : String):String
	{
		if ( m_Data[id] != null )
		{
				return  m_Data[id];
		}
		else
		{
			throw("TextBin - not exist id = " + id);
		}
	}
	
	public function isLoaded():Bool
	{
		return m_isLoaded;
	}
	
}