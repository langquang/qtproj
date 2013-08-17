#ifndef INCLUDED_qtframework_events_QTEvent
#define INCLUDED_qtframework_events_QTEvent

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flash/events/Event.h>
HX_DECLARE_CLASS2(flash,events,Event)
HX_DECLARE_CLASS2(qtframework,events,QTEvent)
namespace qtframework{
namespace events{


class HXCPP_CLASS_ATTRIBUTES  QTEvent_obj : public ::flash::events::Event_obj{
	public:
		typedef ::flash::events::Event_obj super;
		typedef QTEvent_obj OBJ_;
		QTEvent_obj();
		Void __construct(::String type,Dynamic data,hx::Null< bool >  __o_bubbles);

	public:
		static hx::ObjectPtr< QTEvent_obj > __new(::String type,Dynamic data,hx::Null< bool >  __o_bubbles);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~QTEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("QTEvent"); }

		Dynamic mData;
};

} // end namespace qtframework
} // end namespace events

#endif /* INCLUDED_qtframework_events_QTEvent */ 
