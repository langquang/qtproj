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
	private var mAtlasRef:Map<String, Int>;
	
	public function new() 
	{
		mAtlasDesc = new AtlasDes();
		mPacks = new Map<String, TextureAtlas>();
		mAtlasRef = new Map<String, Int>();
	}
	
	public function getFrame(pack : String, name : String):Texture
	{
		var atlas : TextureAtlas = getPack(pack);
		if ( atlas != null )
		{
			incReference(pack);
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
				//free mem
				bm.dispose();
				bm = null;
				return atlas;
			}
			else {
				throw("[ResourceManager] There is no Pack  of \"" + name + "\"");				
			}					
		}
		return null;
	}
	
	private function incReference(pack : String):Int
	{
		var count : Int  = 0;
		if ( mAtlasRef[pack] != null ) {
			count = mAtlasRef[pack] ;
			count++;
			mAtlasRef.set(pack, count);
		}else {
			mAtlasRef.set(pack, 0);
		}
		return mAtlasRef[pack];
	}
	
	private function decReference(pack : String):Int
	{
		var count : Int  = 0;
		if ( mAtlasRef[pack] != null ) {
			count = mAtlasRef[pack] ;
			count--;
			if ( count <= 0 ) {
				var atlas : TextureAtlas = getPack(pack);
				atlas.dispose();
			}	
			mAtlasRef.set(pack, 0);

		}
		return mAtlasRef[pack];
	}
	
	public function release( pack : String ):Int
	{
		return decReference(pack);
	}
}