#ifndef INCLUDED_qtframework_qtcore_Starling
#define INCLUDED_qtframework_qtcore_Starling

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flash/events/EventDispatcher.h>
HX_DECLARE_CLASS2(flash,display,DisplayObject)
HX_DECLARE_CLASS2(flash,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(flash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(flash,display,InteractiveObject)
HX_DECLARE_CLASS2(flash,display,Sprite)
HX_DECLARE_CLASS2(flash,display,Stage)
HX_DECLARE_CLASS2(flash,events,Event)
HX_DECLARE_CLASS2(flash,events,EventDispatcher)
HX_DECLARE_CLASS2(flash,events,IEventDispatcher)
HX_DECLARE_CLASS2(flash,events,KeyboardEvent)
HX_DECLARE_CLASS2(flash,geom,Rectangle)
HX_DECLARE_CLASS2(qtframework,qtanimation,IAnimatable)
HX_DECLARE_CLASS2(qtframework,qtanimation,Juggler)
HX_DECLARE_CLASS2(qtframework,qtcore,Starling)
namespace qtframework{
namespace qtcore{


class HXCPP_CLASS_ATTRIBUTES  Starling_obj : public ::flash::events::EventDispatcher_obj{
	public:
		typedef ::flash::events::EventDispatcher_obj super;
		typedef Starling_obj OBJ_;
		Starling_obj();
		Void __construct(::flash::display::Stage stage);

	public:
		static hx::ObjectPtr< Starling_obj > __new(::flash::display::Stage stage);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Starling_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Starling"); }

		virtual Float getSecond( );
		Dynamic getSecond_dyn();

		virtual ::qtframework::qtanimation::Juggler get_juggler( );
		Dynamic get_juggler_dyn();

		virtual bool isStarted( );
		Dynamic isStarted_dyn();

		virtual Void advanceTime( Float passedTime);
		Dynamic advanceTime_dyn();

		virtual Void nextFrame( );
		Dynamic nextFrame_dyn();

		virtual Void onResize( ::flash::events::Event event);
		Dynamic onResize_dyn();

		virtual Void onKey( ::flash::events::KeyboardEvent event);
		Dynamic onKey_dyn();

		virtual Void onEnterFrame( ::flash::events::Event event);
		Dynamic onEnterFrame_dyn();

		virtual Void stop( );
		Dynamic stop_dyn();

		virtual Void start( );
		Dynamic start_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		Float mLastFrameTimestamp;
		bool mStarted;
		::qtframework::qtanimation::Juggler mJuggler;
		::flash::geom::Rectangle mViewPort;
		::flash::display::Sprite mNativeOverlay;
		::flash::display::Stage mNativeStage;
		static ::qtframework::qtcore::Starling sCurrent;
		static bool sHandleLostContext;
};

} // end namespace qtframework
} // end namespace qtcore

#endif /* INCLUDED_qtframework_qtcore_Starling */ 
