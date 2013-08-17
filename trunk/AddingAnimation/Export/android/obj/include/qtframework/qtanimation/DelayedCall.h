#ifndef INCLUDED_qtframework_qtanimation_DelayedCall
#define INCLUDED_qtframework_qtanimation_DelayedCall

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flash/events/EventDispatcher.h>
#include <qtframework/qtanimation/IAnimatable.h>
HX_DECLARE_CLASS2(flash,events,EventDispatcher)
HX_DECLARE_CLASS2(flash,events,IEventDispatcher)
HX_DECLARE_CLASS2(qtframework,qtanimation,DelayedCall)
HX_DECLARE_CLASS2(qtframework,qtanimation,IAnimatable)
namespace qtframework{
namespace qtanimation{


class HXCPP_CLASS_ATTRIBUTES  DelayedCall_obj : public ::flash::events::EventDispatcher_obj{
	public:
		typedef ::flash::events::EventDispatcher_obj super;
		typedef DelayedCall_obj OBJ_;
		DelayedCall_obj();
		Void __construct(Dynamic func,Float delay,Dynamic args);

	public:
		static hx::ObjectPtr< DelayedCall_obj > __new(Dynamic func,Float delay,Dynamic args);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~DelayedCall_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::qtframework::qtanimation::IAnimatable_obj *()
			{ return new ::qtframework::qtanimation::IAnimatable_delegate_< DelayedCall_obj >(this); }
		hx::Object *__ToInterface(const hx::type_info &inType);
		::String __ToString() const { return HX_CSTRING("DelayedCall"); }

		virtual Void set_repeatCount( int value);
		Dynamic set_repeatCount_dyn();

		virtual int get_repeatCount( );
		Dynamic get_repeatCount_dyn();

		virtual Float get_currentTime( );
		Dynamic get_currentTime_dyn();

		virtual Float get_totalTime( );
		Dynamic get_totalTime_dyn();

		virtual bool get_isComplete( );
		Dynamic get_isComplete_dyn();

		virtual Void advanceTime( Float time);
		Dynamic advanceTime_dyn();

		int mRepeatCount;
		Dynamic mArgs;
		Dynamic mCall;
		Float mTotalTime;
		Float mCurrentTime;
};

} // end namespace qtframework
} // end namespace qtanimation

#endif /* INCLUDED_qtframework_qtanimation_DelayedCall */ 
