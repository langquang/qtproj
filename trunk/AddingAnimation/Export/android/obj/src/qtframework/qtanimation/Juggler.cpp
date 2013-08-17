#include <hxcpp.h>

#ifndef INCLUDED_Lambda
#include <Lambda.h>
#endif
#ifndef INCLUDED_flash_events_Event
#include <flash/events/Event.h>
#endif
#ifndef INCLUDED_flash_events_EventDispatcher
#include <flash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_IEventDispatcher
#include <flash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
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
#ifndef INCLUDED_qtframework_qtanimation_Juggler
#include <qtframework/qtanimation/Juggler.h>
#endif
namespace qtframework{
namespace qtanimation{

Void Juggler_obj::__construct()
{
HX_STACK_PUSH("Juggler::new","qtframework/qtanimation/Juggler.hx",17);
{
	HX_STACK_LINE(18)
	this->mElapsedTime = (int)0;
	HX_STACK_LINE(19)
	this->mObjects = Array_obj< ::Dynamic >::__new();
}
;
	return null();
}

Juggler_obj::~Juggler_obj() { }

Dynamic Juggler_obj::__CreateEmpty() { return  new Juggler_obj; }
hx::ObjectPtr< Juggler_obj > Juggler_obj::__new()
{  hx::ObjectPtr< Juggler_obj > result = new Juggler_obj();
	result->__construct();
	return result;}

Dynamic Juggler_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Juggler_obj > result = new Juggler_obj();
	result->__construct();
	return result;}

hx::Object *Juggler_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::qtframework::qtanimation::IAnimatable_obj)) return operator ::qtframework::qtanimation::IAnimatable_obj *();
	return super::__ToInterface(inType);
}

Void Juggler_obj::onRemove( ::qtframework::events::QTEvent event){
{
		HX_STACK_PUSH("Juggler::onRemove","qtframework/qtanimation/Juggler.hx",88);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(88)
		this->remove(event->get_target());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Juggler_obj,onRemove,(void))

Float Juggler_obj::get_ElapsedTime( ){
	HX_STACK_PUSH("Juggler::get_ElapsedTime","qtframework/qtanimation/Juggler.hx",85);
	HX_STACK_THIS(this);
	HX_STACK_LINE(85)
	return this->mElapsedTime;
}


HX_DEFINE_DYNAMIC_FUNC0(Juggler_obj,get_ElapsedTime,return )

Void Juggler_obj::advanceTime( Float time){
{
		HX_STACK_PUSH("Juggler::advanceTime","qtframework/qtanimation/Juggler.hx",65);
		HX_STACK_THIS(this);
		HX_STACK_ARG(time,"time");
		HX_STACK_LINE(66)
		int numObjects = this->mObjects->length;		HX_STACK_VAR(numObjects,"numObjects");
		HX_STACK_LINE(67)
		int currentIndex = (int)0;		HX_STACK_VAR(currentIndex,"currentIndex");
		HX_STACK_LINE(68)
		int i;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(70)
		hx::AddEq(this->mElapsedTime,time);
		HX_STACK_LINE(71)
		if (((numObjects == (int)0))){
			HX_STACK_LINE(71)
			return null();
		}
		HX_STACK_LINE(73)
		{
			HX_STACK_LINE(73)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = this->mObjects->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(73)
			while(((_g1 < _g))){
				HX_STACK_LINE(73)
				int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(75)
				::qtframework::qtanimation::IAnimatable object = this->mObjects->__get(i1).StaticCast< ::qtframework::qtanimation::IAnimatable >();		HX_STACK_VAR(object,"object");
				HX_STACK_LINE(76)
				if (((object == null()))){
					HX_STACK_LINE(77)
					this->mObjects->splice(i1,(int)1);
				}
				else{
					HX_STACK_LINE(79)
					object->advanceTime(time);
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Juggler_obj,advanceTime,(void))

::qtframework::qtanimation::DelayedCall Juggler_obj::delayCall( Dynamic func,Float delay,Dynamic args){
	HX_STACK_PUSH("Juggler::delayCall","qtframework/qtanimation/Juggler.hx",55);
	HX_STACK_THIS(this);
	HX_STACK_ARG(func,"func");
	HX_STACK_ARG(delay,"delay");
	HX_STACK_ARG(args,"args");
	HX_STACK_LINE(56)
	if (((func == null()))){
		HX_STACK_LINE(56)
		return null();
	}
	HX_STACK_LINE(58)
	::qtframework::qtanimation::DelayedCall delayedCall = ::qtframework::qtanimation::DelayedCall_obj::__new(func,delay,args);		HX_STACK_VAR(delayedCall,"delayedCall");
	HX_STACK_LINE(59)
	this->add(delayedCall);
	HX_STACK_LINE(60)
	return delayedCall;
}


HX_DEFINE_DYNAMIC_FUNC3(Juggler_obj,delayCall,return )

Void Juggler_obj::purge( ){
{
		HX_STACK_PUSH("Juggler::purge","qtframework/qtanimation/Juggler.hx",46);
		HX_STACK_THIS(this);
		HX_STACK_LINE(47)
		this->mObjects = null();
		HX_STACK_LINE(48)
		this->mObjects = Array_obj< ::Dynamic >::__new();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Juggler_obj,purge,(void))

Void Juggler_obj::remove( ::qtframework::qtanimation::IAnimatable object){
{
		HX_STACK_PUSH("Juggler::remove","qtframework/qtanimation/Juggler.hx",37);
		HX_STACK_THIS(this);
		HX_STACK_ARG(object,"object");
		HX_STACK_LINE(38)
		::haxe::Log_obj::trace(HX_CSTRING("Juggler: remove Object"),hx::SourceInfo(HX_CSTRING("Juggler.hx"),38,HX_CSTRING("qtframework.qtanimation.Juggler"),HX_CSTRING("remove")));
		HX_STACK_LINE(39)
		if (((object == null()))){
			HX_STACK_LINE(39)
			return null();
		}
		HX_STACK_LINE(41)
		this->mObjects->remove(object);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Juggler_obj,remove,(void))

Void Juggler_obj::add( ::qtframework::qtanimation::IAnimatable object){
{
		HX_STACK_PUSH("Juggler::add","qtframework/qtanimation/Juggler.hx",24);
		HX_STACK_THIS(this);
		HX_STACK_ARG(object,"object");
		HX_STACK_LINE(24)
		if (((bool((object != null())) && bool((::Lambda_obj::indexOf(this->mObjects,object) == (int)-1))))){
			HX_STACK_LINE(27)
			this->mObjects->push(object);
			HX_STACK_LINE(29)
			::flash::events::EventDispatcher dispatcher = object;		HX_STACK_VAR(dispatcher,"dispatcher");
			HX_STACK_LINE(30)
			if (((dispatcher != null()))){
				HX_STACK_LINE(31)
				dispatcher->addEventListener(HX_CSTRING("removeFromJuggler"),this->onRemove_dyn(),null(),null(),null());
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Juggler_obj,add,(void))


Juggler_obj::Juggler_obj()
{
}

void Juggler_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Juggler);
	HX_MARK_MEMBER_NAME(mElapsedTime,"mElapsedTime");
	HX_MARK_MEMBER_NAME(mObjects,"mObjects");
	HX_MARK_END_CLASS();
}

void Juggler_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(mElapsedTime,"mElapsedTime");
	HX_VISIT_MEMBER_NAME(mObjects,"mObjects");
}

Dynamic Juggler_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"add") ) { return add_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"purge") ) { return purge_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"remove") ) { return remove_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"onRemove") ) { return onRemove_dyn(); }
		if (HX_FIELD_EQ(inName,"mObjects") ) { return mObjects; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"delayCall") ) { return delayCall_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"advanceTime") ) { return advanceTime_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"mElapsedTime") ) { return mElapsedTime; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"get_ElapsedTime") ) { return get_ElapsedTime_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Juggler_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"mObjects") ) { mObjects=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"mElapsedTime") ) { mElapsedTime=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Juggler_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("mElapsedTime"));
	outFields->push(HX_CSTRING("mObjects"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("onRemove"),
	HX_CSTRING("get_ElapsedTime"),
	HX_CSTRING("advanceTime"),
	HX_CSTRING("delayCall"),
	HX_CSTRING("purge"),
	HX_CSTRING("remove"),
	HX_CSTRING("add"),
	HX_CSTRING("mElapsedTime"),
	HX_CSTRING("mObjects"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Juggler_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Juggler_obj::__mClass,"__mClass");
};

Class Juggler_obj::__mClass;

void Juggler_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("qtframework.qtanimation.Juggler"), hx::TCanCast< Juggler_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Juggler_obj::__boot()
{
}

} // end namespace qtframework
} // end namespace qtanimation
