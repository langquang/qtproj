#include <hxcpp.h>

#ifndef INCLUDED_flash_events_Event
#include <flash/events/Event.h>
#endif
#ifndef INCLUDED_flash_events_EventDispatcher
#include <flash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_IEventDispatcher
#include <flash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_qtframework_events_QTEvent
#include <qtframework/events/QTEvent.h>
#endif
#ifndef INCLUDED_qtframework_qtanimation_DelayedCall
#include <qtframework/qtanimation/DelayedCall.h>
#endif
#ifndef INCLUDED_qtframework_qtanimation_IAnimatable
#include <qtframework/qtanimation/IAnimatable.h>
#endif
namespace qtframework{
namespace qtanimation{

Void DelayedCall_obj::__construct(Dynamic func,Float delay,Dynamic args)
{
HX_STACK_PUSH("DelayedCall::new","qtframework/qtanimation/DelayedCall.hx",9);
{
	HX_STACK_LINE(15)
	this->mRepeatCount = (int)1;
	HX_STACK_LINE(11)
	this->mCurrentTime = (int)0;
	HX_STACK_LINE(20)
	super::__construct(null());
	HX_STACK_LINE(21)
	this->mCall = func;
	HX_STACK_LINE(22)
	this->mTotalTime = ::Math_obj::max(delay,0.0001);
	HX_STACK_LINE(23)
	this->mArgs = args;
}
;
	return null();
}

DelayedCall_obj::~DelayedCall_obj() { }

Dynamic DelayedCall_obj::__CreateEmpty() { return  new DelayedCall_obj; }
hx::ObjectPtr< DelayedCall_obj > DelayedCall_obj::__new(Dynamic func,Float delay,Dynamic args)
{  hx::ObjectPtr< DelayedCall_obj > result = new DelayedCall_obj();
	result->__construct(func,delay,args);
	return result;}

Dynamic DelayedCall_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< DelayedCall_obj > result = new DelayedCall_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

hx::Object *DelayedCall_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::qtframework::qtanimation::IAnimatable_obj)) return operator ::qtframework::qtanimation::IAnimatable_obj *();
	return super::__ToInterface(inType);
}

Void DelayedCall_obj::set_repeatCount( int value){
{
		HX_STACK_PUSH("DelayedCall::set_repeatCount","qtframework/qtanimation/DelayedCall.hx",62);
		HX_STACK_THIS(this);
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(62)
		this->mRepeatCount = value;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DelayedCall_obj,set_repeatCount,(void))

int DelayedCall_obj::get_repeatCount( ){
	HX_STACK_PUSH("DelayedCall::get_repeatCount","qtframework/qtanimation/DelayedCall.hx",61);
	HX_STACK_THIS(this);
	HX_STACK_LINE(61)
	return this->mRepeatCount;
}


HX_DEFINE_DYNAMIC_FUNC0(DelayedCall_obj,get_repeatCount,return )

Float DelayedCall_obj::get_currentTime( ){
	HX_STACK_PUSH("DelayedCall::get_currentTime","qtframework/qtanimation/DelayedCall.hx",58);
	HX_STACK_THIS(this);
	HX_STACK_LINE(58)
	return this->mCurrentTime;
}


HX_DEFINE_DYNAMIC_FUNC0(DelayedCall_obj,get_currentTime,return )

Float DelayedCall_obj::get_totalTime( ){
	HX_STACK_PUSH("DelayedCall::get_totalTime","qtframework/qtanimation/DelayedCall.hx",55);
	HX_STACK_THIS(this);
	HX_STACK_LINE(55)
	return this->mTotalTime;
}


HX_DEFINE_DYNAMIC_FUNC0(DelayedCall_obj,get_totalTime,return )

bool DelayedCall_obj::get_isComplete( ){
	HX_STACK_PUSH("DelayedCall::get_isComplete","qtframework/qtanimation/DelayedCall.hx",50);
	HX_STACK_THIS(this);
	HX_STACK_LINE(50)
	return (bool((this->mRepeatCount == (int)1)) && bool((this->mCurrentTime >= this->mTotalTime)));
}


HX_DEFINE_DYNAMIC_FUNC0(DelayedCall_obj,get_isComplete,return )

Void DelayedCall_obj::advanceTime( Float time){
{
		HX_STACK_PUSH("DelayedCall::advanceTime","qtframework/qtanimation/DelayedCall.hx",27);
		HX_STACK_THIS(this);
		HX_STACK_ARG(time,"time");
		HX_STACK_LINE(28)
		Float previousTime = this->mCurrentTime;		HX_STACK_VAR(previousTime,"previousTime");
		HX_STACK_LINE(29)
		this->mCurrentTime = ::Math_obj::min(this->mTotalTime,(this->mCurrentTime + time));
		HX_STACK_LINE(31)
		if (((bool((previousTime < this->mTotalTime)) && bool((this->mCurrentTime >= this->mTotalTime))))){
			HX_STACK_LINE(33)
			this->mCall(this->mArgs);
			HX_STACK_LINE(35)
			if (((this->mRepeatCount > (int)1))){
				HX_STACK_LINE(37)
				hx::SubEq(this->mRepeatCount,(int)1);
				HX_STACK_LINE(38)
				this->mCurrentTime = (int)0;
				HX_STACK_LINE(39)
				this->advanceTime(((previousTime + time) - this->mTotalTime));
			}
			else{
				HX_STACK_LINE(42)
				this->dispatchEvent(::qtframework::events::QTEvent_obj::__new(HX_CSTRING("removeFromJuggler"),null(),null()));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(DelayedCall_obj,advanceTime,(void))


DelayedCall_obj::DelayedCall_obj()
{
}

void DelayedCall_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(DelayedCall);
	HX_MARK_MEMBER_NAME(mRepeatCount,"mRepeatCount");
	HX_MARK_MEMBER_NAME(mArgs,"mArgs");
	HX_MARK_MEMBER_NAME(mCall,"mCall");
	HX_MARK_MEMBER_NAME(mTotalTime,"mTotalTime");
	HX_MARK_MEMBER_NAME(mCurrentTime,"mCurrentTime");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void DelayedCall_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(mRepeatCount,"mRepeatCount");
	HX_VISIT_MEMBER_NAME(mArgs,"mArgs");
	HX_VISIT_MEMBER_NAME(mCall,"mCall");
	HX_VISIT_MEMBER_NAME(mTotalTime,"mTotalTime");
	HX_VISIT_MEMBER_NAME(mCurrentTime,"mCurrentTime");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic DelayedCall_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"mArgs") ) { return mArgs; }
		if (HX_FIELD_EQ(inName,"mCall") ) { return mCall; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"mTotalTime") ) { return mTotalTime; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"advanceTime") ) { return advanceTime_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"mRepeatCount") ) { return mRepeatCount; }
		if (HX_FIELD_EQ(inName,"mCurrentTime") ) { return mCurrentTime; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"get_totalTime") ) { return get_totalTime_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_isComplete") ) { return get_isComplete_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"set_repeatCount") ) { return set_repeatCount_dyn(); }
		if (HX_FIELD_EQ(inName,"get_repeatCount") ) { return get_repeatCount_dyn(); }
		if (HX_FIELD_EQ(inName,"get_currentTime") ) { return get_currentTime_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic DelayedCall_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"mArgs") ) { mArgs=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mCall") ) { mCall=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"mTotalTime") ) { mTotalTime=inValue.Cast< Float >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"mRepeatCount") ) { mRepeatCount=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mCurrentTime") ) { mCurrentTime=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void DelayedCall_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("mRepeatCount"));
	outFields->push(HX_CSTRING("mArgs"));
	outFields->push(HX_CSTRING("mCall"));
	outFields->push(HX_CSTRING("mTotalTime"));
	outFields->push(HX_CSTRING("mCurrentTime"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("set_repeatCount"),
	HX_CSTRING("get_repeatCount"),
	HX_CSTRING("get_currentTime"),
	HX_CSTRING("get_totalTime"),
	HX_CSTRING("get_isComplete"),
	HX_CSTRING("advanceTime"),
	HX_CSTRING("mRepeatCount"),
	HX_CSTRING("mArgs"),
	HX_CSTRING("mCall"),
	HX_CSTRING("mTotalTime"),
	HX_CSTRING("mCurrentTime"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(DelayedCall_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(DelayedCall_obj::__mClass,"__mClass");
};

Class DelayedCall_obj::__mClass;

void DelayedCall_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("qtframework.qtanimation.DelayedCall"), hx::TCanCast< DelayedCall_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void DelayedCall_obj::__boot()
{
}

} // end namespace qtframework
} // end namespace qtanimation
