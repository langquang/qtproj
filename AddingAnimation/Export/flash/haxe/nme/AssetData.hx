package nme;


import openfl.Assets;


class AssetData {

	
	public static var className = new #if haxe3 Map <String, #else Hash <#end Dynamic> ();
	public static var library = new #if haxe3 Map <String, #else Hash <#end LibraryType> ();
	public static var type = new #if haxe3 Map <String, #else Hash <#end AssetType> ();
	
	private static var initialized:Bool = false;
	
	
	public static function initialize ():Void {
		
		if (!initialized) {
			
			className.set ("assets/B11S2Building.png", nme.NME_assets_b11s2building_png);
			type.set ("assets/B11S2Building.png", Reflect.field (AssetType, "image".toUpperCase ()));
			className.set ("assets/openfl.png", nme.NME_assets_openfl_png);
			type.set ("assets/openfl.png", Reflect.field (AssetType, "image".toUpperCase ()));
			
			
			initialized = true;
			
		}
		
	}
	
	
}


class NME_assets_b11s2building_png extends flash.display.BitmapData { public function new () { super (0, 0); } }
class NME_assets_openfl_png extends flash.display.BitmapData { public function new () { super (0, 0); } }
