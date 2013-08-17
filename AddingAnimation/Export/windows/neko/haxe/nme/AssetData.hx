package nme;


import openfl.Assets;


class AssetData {
	
	
	public static var library:Map <String, LibraryType>;
	public static var path:Map <String, String>;
	public static var type:Map <String, AssetType>;
	
	private static var initialized:Bool = false;
	
	
	public static function initialize ():Void {
		
		if (!initialized) {
			
			path = new Map<String, String> ();
			type = new Map<String, AssetType> ();
			library = new Map<String, LibraryType> ();
			
			path.set ("assets/B11S2Building.png", "assets/B11S2Building.png");
			type.set ("assets/B11S2Building.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("assets/openfl.png", "assets/openfl.png");
			type.set ("assets/openfl.png", Reflect.field (AssetType, "image".toUpperCase ()));
			
			
			initialized = true;
			
		}
		
	}
	
	
}