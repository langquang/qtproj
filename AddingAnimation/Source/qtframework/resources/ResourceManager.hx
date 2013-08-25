package qtframework.resources;
import flash.display.BitmapData;
import flash.utils.ByteArray;
import openfl.Assets;
import qtframework.textures.Texture;
import qtframework.textures.TextureAtlas;

/**
 * ...
 * @author butin
 */
class ResourceManager
{

	private var mAtlasDesc : AtlasDes;
	private var mDefaultTexture : Texture;
	private var mPacks :Map<String, TextureAtlas>;
	
	public function new() 
	{
		mAtlasDesc = new AtlasDes();
		mPacks = new Map<String, TextureAtlas>();
	}
	
	public function getFrame(pack : String, name : String):Texture
	{
		var atlas : TextureAtlas = getPack(pack);
		if ( atlas != null )
		{
			return atlas.getTexture(name);
		}
		return null;
	}
	
	public function getSequenceFrame(pack : String, refix : String): Array<Texture> 
	{
		var atlas : TextureAtlas = getPack(pack);
		if ( atlas != null )
		{
			return atlas.getTextures(refix);
		}
		return null;
	}
	
	private function getPack(name : String):TextureAtlas
	{
		if ( mPacks[name] != null )
		{
				return  mPacks[name];
		}
		else
		{
			var desc : ByteArray = mAtlasDesc.getPackDesc(name);
			var bm : BitmapData = Assets.getBitmapData("images/" +name + ".png");
			var texture : Texture = new Texture(bm);
			if ( desc != null && bm != null ){
				var atlas : TextureAtlas = new TextureAtlas(texture, desc);
				mPacks[name] = atlas;
				return atlas;
			}
			else {
				trace("[ResourceManager] There is no Pack  of \"" + name + "\"");				
			}					
		}
		return null;
	
	}
	
}