#include <hxcpp.h>

#ifndef INCLUDED_flash_events_Event
#include <flash/events/Event.h>
#endif
#ifndef INCLUDED_qtframework_events_QTEvent
#include <qtframework/events/QTEvent.h>
#endif
namespace qtframework{
namespace events{

Void QTEvent_obj::__construct(::String type,Dynamic data,hx::Null< bool >  __o_bubbles)
{
HX_STACK_PUSH("QTEvent::new","qtframework/events/QTEvent.hx",41);
bool bubbles = __o_bubbles.Default(false);
{
	HX_STACK_LINE(42)
	super::__construct(type,bubbles,null());
	HX_STACK_LINE(43)
	this->mData = data;
}
;
	return null();
}

QTEvent_obj::~QTEvent_obj() { }

Dynamic QTEvent_obj::__CreateEmpty() { return  new QTEvent_obj; }
hx::ObjectPtr< QTEvent_obj > QTEvent_obj::__new(::String type,Dynamic data,hx::Null< bool >  __o_bubbles)
{  hx::ObjectPtr< QTEvent_obj > result = new QTEvent_obj();
	result->__construct(type,data,__o_bubbles);
	return result;}

Dynamic QTEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< QTEvent_obj > result = new QTEvent_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}


QTEvent_obj::QTEvent_obj()
{
}

void QTEvent_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(QTEvent);
	HX_MARK_MEMBER_NAME(mData,"mData");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void QTEvent_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(mData,"mData");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic QTEvent_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"mData") ) { return mData; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic QTEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"mData") ) { mData=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void QTEvent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("mData"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("mData"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(QTEvent_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(QTEvent_obj::__mClass,"__mClass");
};

Class QTEvent_obj::__mClass;

void QTEvent_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("qtframework.events.QTEvent"), hx::TCanCast< QTEvent_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void QTEvent_obj::__boot()
{
}

} // end namespace qtframework
} // end namespace events
