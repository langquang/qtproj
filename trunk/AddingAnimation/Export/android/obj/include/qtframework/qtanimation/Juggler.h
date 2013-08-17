#ifndef INCLUDED_qtframework_qtanimation_Juggler
#define INCLUDED_qtframework_qtanimation_Juggler

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <qtframework/qtanimation/IAnimatable.h>
HX_DECLARE_CLASS2(flash,events,Event)
HX_DECLARE_CLASS2(flash,events,EventDispatcher)
HX_DECLARE_CLASS2(flash,events,IEventDispatcher)
HX_DECLARE_CLASS2(qtframework,events,QTEvent)
HX_DECLARE_CLASS2(qtframework,qtanimation,DelayedCall)
HX_DECLARE_CLASS2(qtframework,qtanimation,IAnimatable)
HX_DECLARE_CLASS2(qtframework,qtanimation,Juggler)
namespace qtframework{
namespace qtanimation{


class HXCPP_CLASS_ATTRIBUTES  Juggler_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Juggler_obj OBJ_;
		Juggler_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Juggler_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Juggler_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::qtframework::qtanimation::IAnimatable_obj *()
			{ return new ::qtframework::qtanimation::IAnimatable_delegate_< Juggler_obj >(this); }
		hx::Object *__ToInterface(const hx::type_info &inType);
		::String __ToString() const { return HX_CSTRING("Juggler"); }

		virtual Void onRemove( ::qtframework::events::QTEvent event);
		Dynamic onRemove_dyn();

		virtual Float get_ElapsedTime( );
		Dynamic get_ElapsedTime_dyn();

		virtual Void advanceTime( Float time);
		Dynamic advanceTime_dyn();

		virtual ::qtframework::qtanimation::DelayedCall delayCall( Dynamic func,Float delay,Dynamic args);
		Dynamic delayCall_dyn();

		virtual Void purge( );
		Dynamic purge_dyn();

		virtual Void remove( ::qtframework::qtanimation::IAnimatable object);
		Dynamic remove_dyn();

		virtual Void add( ::qtframework::qtanimation::IAnimatable object);
		Dynamic add_dyn();

		Float mElapsedTime;
		Array< ::Dynamic > mObjects;
};

} // end namespace qtframework
} // end namespace qtanimation

#endif /* INCLUDED_qtframework_qtanimation_Juggler */ 
