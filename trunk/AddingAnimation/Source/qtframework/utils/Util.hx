package qtframework.utils;
import flash.utils.ByteArray;

/**
 * ...
 * @author butin
 */
class Util
{

	public function new() 
	{
		
	}
	
	public static function readString(buffer : ByteArray):String
	{
		var length : Int = buffer.readByte();
		return buffer.readUTFBytes(length);
	}
	
}