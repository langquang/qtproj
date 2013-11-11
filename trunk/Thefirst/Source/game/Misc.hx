package game;

/**
 * ...
 * @author butin
 */
class Misc
{

	public function new() 
	{
		
	}
	
	public static function randomRange(minNum:Int, maxNum:Int):Int 
	{
		return (Math.floor(Math.random() * (maxNum - minNum + 1)) + minNum);
	}
	
	public static function randomArray(rates : Array<Float>):Int 
	{
		var total : Float = 0;
		for ( i in 0...rates.length )
		{
			if ( rates[i] > 0 )
				total += rates[i];			
		}
		
		var value : Float = Math.random() * total;
		total = 0;
		for ( i in 0...rates.length )
		{
				if ( rates[i] > 0 )
				{
					total += rates[i];
					if ( total > value  )
						return i;
				}
		}
		
		return -1;
		
	}
	
}