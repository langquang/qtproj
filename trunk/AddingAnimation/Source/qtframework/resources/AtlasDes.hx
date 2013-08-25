package qtframework.resources;

import flash.utils.ByteArray;
import flash.utils.Endian;
import openfl.Assets;
import qtframework.defines.ResourceDefine;
import qtframework.utils.Util;
/**
 * ...
 * @author butin
 */
class AtlasDes
{
	private var mPacks:Map<String, ByteArray>;
	public function new() 
	{
		load();
	}
	
	public  function load( ):Void
	{
		mPacks = new Map<String, ByteArray>();
		var buff : ByteArray = Assets.getBytes(ResourceDefine.ATLAS_DESC);
		buff.endian = Endian.BIG_ENDIAN;
		var nPack : Int = buff.readShort();
		while (nPack > 0)
		{
			var name : String = Util.readString(buff);
			name = name.split(".")[0];
			var num : Int = buff.readShort();
			var data : ByteArray = new ByteArray();
			var module : String = "";
			var x:Int           = 0;
			var y:Int           = 0;
			var width:Int       = 0;
			var height:Int      = 0;		
			var frameX:Int  = 0;
			var frameY:Int = 0;
			var frameWidth:Int = 0;
			var frameHeight:Int = 0;
			
			data.endian = Endian.BIG_ENDIAN;
			
			data.writeShort(num);
			for (i in 0...num)
			{
				module  = Util.readString(buff);
				x = buff.readShort();
				y = buff.readShort();
				width = buff.readShort();
				height  = buff.readShort();			
				frameX  = buff.readShort();
				frameY = buff.readShort();
				frameWidth = buff.readShort();
				frameHeight = buff.readShort();
				
				data.writeUTF(module);
				data.writeShort(x);
				data.writeShort(y);
				data.writeShort(width);
				data.writeShort(height);
				data.writeShort(frameX);
				data.writeShort(frameY);
				data.writeShort(frameWidth);
				data.writeShort(frameHeight);
			}
			data.position = 0;
			mPacks[name] = data;
			nPack--;
			
		}
		
	}
	
	public function getPackDesc(name : String):ByteArray
	{
		if ( mPacks[name]  != null)
			return mPacks[name];
		else
			trace("[AtlasDes] There is no Pack description of \"" + name + "\"");
		return null;
	}
	
}