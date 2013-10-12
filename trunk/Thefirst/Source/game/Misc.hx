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
	
}