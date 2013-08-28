package qtframework.display;
import flash.display.BitmapData;
import flash.filters.GlowFilter;
import flash.geom.Point;
import flash.Vector.Vector;
import qtframework.qtanimation.IAnimatable;
import qtframework.textures.Texture;
import qtframework.events.QTEvent;
/**
 * ...
 * @author butin
 */
class MovieClips extends Image implements IAnimatable
{
	private var mTextures:Array<Texture>;
	private var mTextureFilters:Array<Texture>;
	private var mDurations:Array<Float>;
	private var mStartTimes:Array<Float>;

	private var mDefaultFrameDuration:Float;
	private var mTotalTime:Float;
	private var mCurrentTime:Float;
	private var mCurrentFrame:Int;
	private var mLoop:Bool;
	private var mPlaying:Bool;
	public var numFrames(get_numFrames, null) : Int;
	public var currentFrame(get_currentFrame, set_currentFrame) : Int;

	
	 /** Creates a movie clip from the provided textures and with the specified default framerate.*/  
	public function new(textures:Array<Texture>, fps:Float=12) 
	{
		 if (textures.length > 0)
		{
			super(textures[0]);
			init(textures, fps);
		}
		else
		{
			throw("Empty texture array");
		}
	}
	
	private function init(textures:Array<Texture>, fps:Float):Void
	{
		if (fps <= 0) throw("Invalid fps: " + fps);
		var numFrames:Int = textures.length;
		
		mDefaultFrameDuration = 1.0 / fps;
		mLoop = true;
		mPlaying = true; 
		mCurrentTime = 0.0;
		mCurrentFrame = 0;
		mTotalTime = mDefaultFrameDuration * numFrames;
		mTextures = textures;
		mDurations = new Array<Float>();
		mStartTimes = new Array<Float>();
		
		for (i in 0...numFrames)
		{
			mDurations[i] = mDefaultFrameDuration;
			mStartTimes[i] = i * mDefaultFrameDuration;
		}
	}
	
	// frame manipulation
        
	/** Adds an additional frame, optionally with a sound and a custom duration. If the 
	 *  duration is omitted, the default framerate is used (as specified in the constructor). */   
	public function addFrame(texture:Texture, duration:Float=-1):Void
	{
		addFrameAt(numFrames, texture, duration);
	}
	
	/** Adds a frame at a certain index, optionally with a sound and a custom duration. */
	public function addFrameAt(frameID:Int, texture:Texture, duration:Float=-1):Void
	{
		if (frameID < 0 || frameID > numFrames) throw("Invalid frame id");
		if (duration < 0) duration = mDefaultFrameDuration;
		
		mTextures.insert(frameID, texture);
		mDurations.insert(frameID, duration);
		if ( isFilter == true )
		{
			var filterData : BitmapData = createBitmapFilter(mCurrentFilter, mTextures[frameID]);
			mFilterTexture = new Texture(filterData, false);
			mTextureFilters.insert(frameID, mFilterTexture);
		}
		mTotalTime += duration;
		
		if (frameID > 0 && frameID == numFrames) 
			mStartTimes[frameID] = mStartTimes[frameID-1] + mDurations[frameID-1];
		else
			updateStartTimes();
	}
	
	/** Removes the frame at a certain ID. The successors will move down. */
	public function removeFrameAt(frameID:Int):Void
	{
		if (frameID < 0 || frameID >= numFrames) throw("Invalid frame id");
		if (numFrames == 1) throw("Movie clip must not be empty");
		
		mTotalTime -= getFrameDuration(frameID);
		mTextures.splice(frameID, 1);
		mDurations.splice(frameID, 1);
		if ( isFilter == true  )
			mTextureFilters.splice(frameID, 1);
		
		
		updateStartTimes();
	}
	
	 /** Returns the texture of a certain frame. */
	public function getFrameTexture(frameID:Int):Texture
	{
		if (frameID < 0 || frameID >= numFrames) throw("Invalid frame id");
		return mTextures[frameID];
	}
	
	/** Sets the texture of a certain frame. */
	public function setFrameTexture(frameID:Int, texture:Texture):Void
	{
		if (frameID < 0 || frameID >= numFrames) throw("Invalid frame id");
		mTextures[frameID] = texture;
	}
	
	 /** Returns the duration of a certain frame (in seconds). */
	public function getFrameDuration(frameID:Int):Float
	{
		if (frameID < 0 || frameID >= numFrames) throw("Invalid frame id");
		return mDurations[frameID];
	}
	
	/** Sets the duration of a certain frame (in seconds). */
	public function setFrameDuration(frameID:Int, duration:Float):Void
	{
		if (frameID < 0 || frameID >= numFrames) throw("Invalid frame id");
		mTotalTime -= getFrameDuration(frameID);
		mTotalTime += duration;
		mDurations[frameID] = duration;
		updateStartTimes();
	}
	
	 // playback methods
        
	/** Starts playback. Beware that the clip has to be added to a juggler, too! */
	public function play():Void
	{
		mPlaying = true;
	}
	
	/** Pauses playback. */
	public function pause():Void
	{
		mPlaying = false;
	}
	
	/** Stops playback, resetting "currentFrame" to zero. */
	public function stop():Void
	{
		mPlaying = false;
		currentFrame = 0;
	}
	
	// helpers
	
	private function updateStartTimes():Void
	{
		var numFrames:Int = this.numFrames;
		
		mStartTimes = new Array<Float>();
		mStartTimes[0] = 0;
		
		for (i in 1...numFrames)
			mStartTimes[i] = mStartTimes[i-1] + mDurations[i-1];
	}
	
	// IAnimatable
	
	/** @inheritDoc */
	public function advanceTime(passedTime:Float):Void
	{
		var finalFrame:Int;
		var previousFrame:Int = mCurrentFrame;
		
		if (mLoop && mCurrentTime == mTotalTime) { mCurrentTime = 0.0; mCurrentFrame = 0; }
		if (!mPlaying || passedTime == 0.0 || mCurrentTime == mTotalTime) return;
		
		mCurrentTime += passedTime;
		finalFrame = mTextures.length - 1;
		
		while (mCurrentTime >= mStartTimes[mCurrentFrame] + mDurations[mCurrentFrame])
		{
			if (mCurrentFrame == finalFrame)
			{
				if (hasEventListener(QTEvent.COMPLETE))
				{
					var restTime:Float = mCurrentTime - mTotalTime;
					mCurrentTime = mTotalTime;
					dispatchEvent(new QTEvent(QTEvent.COMPLETE));
					
					// user might have changed movie clip settings, so we restart the method
					advanceTime(restTime);
					return;
				}
				
				if (mLoop)
				{
					mCurrentTime -= mTotalTime;
					mCurrentFrame = 0;
				}
				else
				{
					mCurrentTime = mTotalTime;
					break;
				}
			}
			else
			{
				mCurrentFrame++;
			}
		}
		
		if (mCurrentFrame != previousFrame)
		{
			if( isFilter == false )
				mBitmap.bitmapData = mTextures[mCurrentFrame].mBitmapData;
			else
				mBitmap.bitmapData = mTextureFilters[mCurrentFrame].mBitmapData;
		}
	}
	
	/** Indicates if a (non-looping) movie has come to its end. */
	public function get_isComplete():Bool
	{
		return !mLoop && mCurrentTime >= mTotalTime;
	}
	
	// properties  
	
	/** The total duration of the clip in seconds. */
	public function get_totalTime():Float { return mTotalTime; }
	
	/** The total Float of frames. */
	public function get_numFrames():Int { return mTextures.length; }
	
	/** Indicates if the clip should loop. */
	public function get_loop():Bool { return mLoop; }
	public function set_loop(value:Bool):Void { mLoop = value; }
	
	/** The index of the frame that is currently displayed. */
	public function get_currentFrame():Int { return mCurrentFrame; }
	public function set_currentFrame(value:Int):Int
	{
		mCurrentFrame = value;
		mCurrentTime = 0.0;
		
		for (i in 0...value)
			mCurrentTime += getFrameDuration(i);
		
		texture = mTextures[mCurrentFrame];
		return 0;
	}
	
	/** The default number of frames per second. Individual frames can have different 
	 *  durations. If you change the fps, the durations of all frames will be scaled 
	 *  relatively to the previous value. */
	public function get_fps():Float { return 1.0 / mDefaultFrameDuration; }
	public function set_fps(value:Float):Void
	{
		if (value <= 0) throw("Invalid fps: " + value);
		
		var newFrameDuration:Float = 1.0 / value;
		var acceleration:Float = newFrameDuration / mDefaultFrameDuration;
		mCurrentTime *= acceleration;
		mDefaultFrameDuration = newFrameDuration;
		
		for (i in 0...numFrames)
			setFrameDuration(i, getFrameDuration(i) * acceleration);
	}
	
	/** Indicates if the clip is still playing. Returns <code>false</code> when the end 
	 *  is reached. */
	public function get_isPlaying():Bool 
	{
		if (mPlaying)
			return mLoop || mCurrentTime < mTotalTime;
		else
			return false;
	}
	
	override public function setGlowFilter(color : UInt = 16711680, alpha : Float = 1, blurX : Float = 6, blurY : Float = 6, strength : Float = 4, quality : Int = 1, inner : Bool = false, knockout : Bool = false):Void
	{
		mTextureFilters = new Array<Texture>();
		mCurrentFilter = new GlowFilter(color, alpha, blurX, blurY, strength, quality, inner, knockout);
		for ( i in 0...numFrames)
		{
			var filterData : BitmapData = createBitmapFilter(mCurrentFilter, mTextures[i]);
			mFilterTexture = new Texture(filterData, false);
			mTextureFilters.push(mFilterTexture);

		}
		mBitmap.bitmapData = mTextureFilters[mCurrentFrame].mBitmapData;

		isFilter = true;
	}
	
	override public function clearGlowFilter():Void
	{
		for ( i in 0...numFrames) mTextureFilters[i].dispose();		
		mBitmap.bitmapData = mTexture.mBitmapData;
		mTextureFilters = null;
		isFilter = false;
	}
	

	
}