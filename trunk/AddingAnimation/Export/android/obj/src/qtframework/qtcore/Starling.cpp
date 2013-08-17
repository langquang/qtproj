#include <hxcpp.h>

#ifndef INCLUDED_flash_Lib
#include <flash/Lib.h>
#endif
#ifndef INCLUDED_flash_display_DisplayObject
#include <flash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_flash_display_DisplayObjectContainer
#include <flash/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_flash_display_IBitmapDrawable
#include <flash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_flash_display_InteractiveObject
#include <flash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_flash_display_Sprite
#include <flash/display/Sprite.h>
#endif
#ifndef INCLUDED_flash_display_Stage
#include <flash/display/Stage.h>
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
#ifndef INCLUDED_flash_events_KeyboardEvent
#include <flash/events/KeyboardEvent.h>
#endif
#ifndef INCLUDED_flash_geom_Rectangle
#include <flash/geom/Rectangle.h>
#endif
#ifndef INCLUDED_qtframework_qtanimation_IAnimatable
#include <qtframework/qtanimation/IAnimatable.h>
#endif
#ifndef INCLUDED_qtframework_qtanimation_Juggler
#include <qtframework/qtanimation/Juggler.h>
#endif
#ifndef INCLUDED_qtframework_qtcore_Starling
#include <qtframework/qtcore/Starling.h>
#endif
namespace qtframework{
namespace qtcore{

Void Starling_obj::__construct(::flash::display::Stage stage)
{
HX_STACK_PUSH("Starling::new","qtframework/qtcore/Starling.hx",30);
{
	HX_STACK_LINE(31)
	super::__construct(null());
	HX_STACK_LINE(32)
	if (((stage == null()))){
		HX_STACK_LINE(32)
		hx::Throw (HX_CSTRING("Stage must not be null"));
	}
	HX_STACK_LINE(34)
	this->mNativeOverlay = ::flash::display::Sprite_obj::__new();
	HX_STACK_LINE(35)
	this->mNativeStage = stage;
	HX_STACK_LINE(36)
	this->mNativeStage->addChild(this->mNativeOverlay);
	HX_STACK_LINE(37)
	this->mViewPort = ::flash::geom::Rectangle_obj::__new((int)0,(int)0,stage->get_stageWidth(),stage->get_stageHeight());
	HX_STACK_LINE(39)
	this->mJuggler = ::qtframework::qtanimation::Juggler_obj::__new();
	HX_STACK_LINE(40)
	this->mLastFrameTimestamp = this->getSecond();
	HX_STACK_LINE(42)
	stage->addEventListener(::flash::events::Event_obj::ENTER_FRAME,this->onEnterFrame_dyn(),null(),null(),null());
	HX_STACK_LINE(44)
	stage->addEventListener(::flash::events::KeyboardEvent_obj::KEY_DOWN,this->onKey_dyn(),null(),null(),null());
	HX_STACK_LINE(45)
	stage->addEventListener(::flash::events::KeyboardEvent_obj::KEY_UP,this->onKey_dyn(),null(),null(),null());
	HX_STACK_LINE(46)
	stage->addEventListener(::flash::events::Event_obj::RESIZE,this->onResize_dyn(),null(),null(),null());
}
;
	return null();
}

Starling_obj::~Starling_obj() { }

Dynamic Starling_obj::__CreateEmpty() { return  new Starling_obj; }
hx::ObjectPtr< Starling_obj > Starling_obj::__new(::flash::display::Stage stage)
{  hx::ObjectPtr< Starling_obj > result = new Starling_obj();
	result->__construct(stage);
	return result;}

Dynamic Starling_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Starling_obj > result = new Starling_obj();
	result->__construct(inArgs[0]);
	return result;}

Float Starling_obj::getSecond( ){
	HX_STACK_PUSH("Starling::getSecond","qtframework/qtcore/Starling.hx",122);
	HX_STACK_THIS(this);
	HX_STACK_LINE(123)
	int time = ::flash::Lib_obj::getTimer();		HX_STACK_VAR(time,"time");
	HX_STACK_LINE(124)
	return (Float(time) / Float(1000.0));
}


HX_DEFINE_DYNAMIC_FUNC0(Starling_obj,getSecond,return )

::qtframework::qtanimation::Juggler Starling_obj::get_juggler( ){
	HX_STACK_PUSH("Starling::get_juggler","qtframework/qtcore/Starling.hx",118);
	HX_STACK_THIS(this);
	HX_STACK_LINE(118)
	return this->mJuggler;
}


HX_DEFINE_DYNAMIC_FUNC0(Starling_obj,get_juggler,return )

bool Starling_obj::isStarted( ){
	HX_STACK_PUSH("Starling::isStarted","qtframework/qtcore/Starling.hx",115);
	HX_STACK_THIS(this);
	HX_STACK_LINE(115)
	return this->mStarted;
}


HX_DEFINE_DYNAMIC_FUNC0(Starling_obj,isStarted,return )

Void Starling_obj::advanceTime( Float passedTime){
{
		HX_STACK_PUSH("Starling::advanceTime","qtframework/qtcore/Starling.hx",110);
		HX_STACK_THIS(this);
		HX_STACK_ARG(passedTime,"passedTime");
		HX_STACK_LINE(110)
		this->mJuggler->advanceTime(passedTime);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Starling_obj,advanceTime,(void))

Void Starling_obj::nextFrame( ){
{
		HX_STACK_PUSH("Starling::nextFrame","qtframework/qtcore/Starling.hx",99);
		HX_STACK_THIS(this);
		HX_STACK_LINE(100)
		Float now = this->getSecond();		HX_STACK_VAR(now,"now");
		HX_STACK_LINE(101)
		Float passedTime = (now - this->mLastFrameTimestamp);		HX_STACK_VAR(passedTime,"passedTime");
		HX_STACK_LINE(102)
		this->mLastFrameTimestamp = now;
		HX_STACK_LINE(104)
		this->advanceTime(passedTime);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Starling_obj,nextFrame,(void))

Void Starling_obj::onResize( ::flash::events::Event event){
{
		HX_STACK_PUSH("Starling::onResize","qtframework/qtcore/Starling.hx",92);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Starling_obj,onResize,(void))

Void Starling_obj::onKey( ::flash::events::KeyboardEvent event){
{
		HX_STACK_PUSH("Starling::onKey","qtframework/qtcore/Starling.hx",86);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(86)
		if ((!(this->mStarted))){
			HX_STACK_LINE(87)
			return null();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Starling_obj,onKey,(void))

Void Starling_obj::onEnterFrame( ::flash::events::Event event){
{
		HX_STACK_PUSH("Starling::onEnterFrame","qtframework/qtcore/Starling.hx",79);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(79)
		if ((this->mStarted)){
			HX_STACK_LINE(82)
			this->nextFrame();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Starling_obj,onEnterFrame,(void))

Void Starling_obj::stop( ){
{
		HX_STACK_PUSH("Starling::stop","qtframework/qtcore/Starling.hx",74);
		HX_STACK_THIS(this);
		HX_STACK_LINE(74)
		this->mStarted = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Starling_obj,stop,(void))

Void Starling_obj::start( ){
{
		HX_STACK_PUSH("Starling::start","qtframework/qtcore/Starling.hx",67);
		HX_STACK_THIS(this);
		HX_STACK_LINE(68)
		this->mStarted = true;
		HX_STACK_LINE(69)
		this->mLastFrameTimestamp = this->getSecond();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Starling_obj,start,(void))

Void Starling_obj::dispose( ){
{
		HX_STACK_PUSH("Starling::dispose","qtframework/qtcore/Starling.hx",52);
		HX_STACK_THIS(this);
		HX_STACK_LINE(53)
		this->stop();
		HX_STACK_LINE(55)
		this->mNativeStage->removeEventListener(::flash::events::Event_obj::ENTER_FRAME,this->onEnterFrame_dyn(),false);
		HX_STACK_LINE(56)
		this->mNativeStage->removeEventListener(::flash::events::KeyboardEvent_obj::KEY_DOWN,this->onKey_dyn(),false);
		HX_STACK_LINE(57)
		this->mNativeStage->removeEventListener(::flash::events::KeyboardEvent_obj::KEY_UP,this->onKey_dyn(),false);
		HX_STACK_LINE(58)
		this->mNativeStage->removeEventListener(::flash::events::Event_obj::RESIZE,this->onResize_dyn(),false);
		HX_STACK_LINE(59)
		if (((::qtframework::qtcore::Starling_obj::sCurrent == hx::ObjectPtr<OBJ_>(this)))){
			HX_STACK_LINE(59)
			::qtframework::qtcore::Starling_obj::sCurrent = null();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Starling_obj,dispose,(void))

::qtframework::qtcore::Starling Starling_obj::sCurrent;

bool Starling_obj::sHandleLostContext;


Starling_obj::Starling_obj()
{
}

void Starling_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Starling);
	HX_MARK_MEMBER_NAME(mLastFrameTimestamp,"mLastFrameTimestamp");
	HX_MARK_MEMBER_NAME(mStarted,"mStarted");
	HX_MARK_MEMBER_NAME(mJuggler,"mJuggler");
	HX_MARK_MEMBER_NAME(mViewPort,"mViewPort");
	HX_MARK_MEMBER_NAME(mNativeOverlay,"mNativeOverlay");
	HX_MARK_MEMBER_NAME(mNativeStage,"mNativeStage");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Starling_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(mLastFrameTimestamp,"mLastFrameTimestamp");
	HX_VISIT_MEMBER_NAME(mStarted,"mStarted");
	HX_VISIT_MEMBER_NAME(mJuggler,"mJuggler");
	HX_VISIT_MEMBER_NAME(mViewPort,"mViewPort");
	HX_VISIT_MEMBER_NAME(mNativeOverlay,"mNativeOverlay");
	HX_VISIT_MEMBER_NAME(mNativeStage,"mNativeStage");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Starling_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"stop") ) { return stop_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"onKey") ) { return onKey_dyn(); }
		if (HX_FIELD_EQ(inName,"start") ) { return start_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"sCurrent") ) { return sCurrent; }
		if (HX_FIELD_EQ(inName,"onResize") ) { return onResize_dyn(); }
		if (HX_FIELD_EQ(inName,"mStarted") ) { return mStarted; }
		if (HX_FIELD_EQ(inName,"mJuggler") ) { return mJuggler; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"getSecond") ) { return getSecond_dyn(); }
		if (HX_FIELD_EQ(inName,"isStarted") ) { return isStarted_dyn(); }
		if (HX_FIELD_EQ(inName,"nextFrame") ) { return nextFrame_dyn(); }
		if (HX_FIELD_EQ(inName,"mViewPort") ) { return mViewPort; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"get_juggler") ) { return get_juggler_dyn(); }
		if (HX_FIELD_EQ(inName,"advanceTime") ) { return advanceTime_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"onEnterFrame") ) { return onEnterFrame_dyn(); }
		if (HX_FIELD_EQ(inName,"mNativeStage") ) { return mNativeStage; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"mNativeOverlay") ) { return mNativeOverlay; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"sHandleLostContext") ) { return sHandleLostContext; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"mLastFrameTimestamp") ) { return mLastFrameTimestamp; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Starling_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"sCurrent") ) { sCurrent=inValue.Cast< ::qtframework::qtcore::Starling >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mStarted") ) { mStarted=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mJuggler") ) { mJuggler=inValue.Cast< ::qtframework::qtanimation::Juggler >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"mViewPort") ) { mViewPort=inValue.Cast< ::flash::geom::Rectangle >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"mNativeStage") ) { mNativeStage=inValue.Cast< ::flash::display::Stage >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"mNativeOverlay") ) { mNativeOverlay=inValue.Cast< ::flash::display::Sprite >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"sHandleLostContext") ) { sHandleLostContext=inValue.Cast< bool >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"mLastFrameTimestamp") ) { mLastFrameTimestamp=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Starling_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("mLastFrameTimestamp"));
	outFields->push(HX_CSTRING("mStarted"));
	outFields->push(HX_CSTRING("mJuggler"));
	outFields->push(HX_CSTRING("mViewPort"));
	outFields->push(HX_CSTRING("mNativeOverlay"));
	outFields->push(HX_CSTRING("mNativeStage"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("sCurrent"),
	HX_CSTRING("sHandleLostContext"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getSecond"),
	HX_CSTRING("get_juggler"),
	HX_CSTRING("isStarted"),
	HX_CSTRING("advanceTime"),
	HX_CSTRING("nextFrame"),
	HX_CSTRING("onResize"),
	HX_CSTRING("onKey"),
	HX_CSTRING("onEnterFrame"),
	HX_CSTRING("stop"),
	HX_CSTRING("start"),
	HX_CSTRING("dispose"),
	HX_CSTRING("mLastFrameTimestamp"),
	HX_CSTRING("mStarted"),
	HX_CSTRING("mJuggler"),
	HX_CSTRING("mViewPort"),
	HX_CSTRING("mNativeOverlay"),
	HX_CSTRING("mNativeStage"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Starling_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Starling_obj::sCurrent,"sCurrent");
	HX_MARK_MEMBER_NAME(Starling_obj::sHandleLostContext,"sHandleLostContext");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Starling_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Starling_obj::sCurrent,"sCurrent");
	HX_VISIT_MEMBER_NAME(Starling_obj::sHandleLostContext,"sHandleLostContext");
};

Class Starling_obj::__mClass;

void Starling_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("qtframework.qtcore.Starling"), hx::TCanCast< Starling_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Starling_obj::__boot()
{
}

} // end namespace qtframework
} // end namespace qtcore
