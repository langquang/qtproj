#include <hxcpp.h>

#ifndef INCLUDED_Main
#include <Main.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_flash_Lib
#include <flash/Lib.h>
#endif
#ifndef INCLUDED_flash_display_Bitmap
#include <flash/display/Bitmap.h>
#endif
#ifndef INCLUDED_flash_display_BitmapData
#include <flash/display/BitmapData.h>
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
#ifndef INCLUDED_flash_display_PixelSnapping
#include <flash/display/PixelSnapping.h>
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
#ifndef INCLUDED_flash_filters_BitmapFilter
#include <flash/filters/BitmapFilter.h>
#endif
#ifndef INCLUDED_flash_filters_DropShadowFilter
#include <flash/filters/DropShadowFilter.h>
#endif
#ifndef INCLUDED_flash_filters_GlowFilter
#include <flash/filters/GlowFilter.h>
#endif
#ifndef INCLUDED_flash_geom_Point
#include <flash/geom/Point.h>
#endif
#ifndef INCLUDED_flash_geom_Rectangle
#include <flash/geom/Rectangle.h>
#endif
#ifndef INCLUDED_flash_text_TextField
#include <flash/text/TextField.h>
#endif
#ifndef INCLUDED_openfl_Assets
#include <openfl/Assets.h>
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
#ifndef INCLUDED_qtframework_qtcore_Starling
#include <qtframework/qtcore/Starling.h>
#endif

Void Main_obj::__construct()
{
HX_STACK_PUSH("Main::new","Main.hx",20);
{
	HX_STACK_LINE(75)
	this->count = (int)0;
	HX_STACK_LINE(26)
	super::__construct();
	HX_STACK_LINE(32)
	::flash::display::BitmapData bmData = ::openfl::Assets_obj::getBitmapData(HX_CSTRING("assets/B11S2Building.png"),null());		HX_STACK_VAR(bmData,"bmData");
	HX_STACK_LINE(33)
	::flash::display::Bitmap bitmap = ::flash::display::Bitmap_obj::__new(null(),null(),null());		HX_STACK_VAR(bitmap,"bitmap");
	HX_STACK_LINE(34)
	bitmap->set_x((Float(-(bitmap->get_width())) / Float((int)2)));
	HX_STACK_LINE(35)
	bitmap->set_y((Float(-(bitmap->get_height())) / Float((int)2)));
	HX_STACK_LINE(36)
	bitmap->set_smoothing(true);
	HX_STACK_LINE(38)
	::flash::display::Sprite container = ::flash::display::Sprite_obj::__new();		HX_STACK_VAR(container,"container");
	HX_STACK_LINE(39)
	container->addChild(bitmap);
	HX_STACK_LINE(40)
	container->set_x((Float(this->get_stage()->get_stageWidth()) / Float((int)2)));
	HX_STACK_LINE(41)
	container->set_y((Float(this->get_stage()->get_stageHeight()) / Float((int)2)));
	HX_STACK_LINE(43)
	this->addChild(container);
	HX_STACK_LINE(45)
	this->tf = ::flash::text::TextField_obj::__new();
	HX_STACK_LINE(46)
	this->tf->set_text(HX_CSTRING("Butin"));
	HX_STACK_LINE(47)
	this->addChild(this->tf);
	HX_STACK_LINE(49)
	::flash::filters::GlowFilter filter = ::flash::filters::GlowFilter_obj::__new((int)16711680,(int)1,(int)10,(int)10,(int)5,null(),null(),null());		HX_STACK_VAR(filter,"filter");
	HX_STACK_LINE(51)
	::flash::display::BitmapData bmFilter = ::flash::display::BitmapData_obj::__new(bmData->get_width(),bmData->get_height(),null(),null(),null());		HX_STACK_VAR(bmFilter,"bmFilter");
	HX_STACK_LINE(52)
	bmFilter->applyFilter(bmData,bmData->get_rect(),::flash::geom::Point_obj::__new((int)0,(int)0),filter);
	HX_STACK_LINE(54)
	bitmap->set_bitmapData(bmFilter);
	HX_STACK_LINE(60)
	::qtframework::qtcore::Starling mStarling = ::qtframework::qtcore::Starling_obj::__new(this->get_stage());		HX_STACK_VAR(mStarling,"mStarling");
	HX_STACK_LINE(61)
	mStarling->start();
	HX_STACK_LINE(62)
	::qtframework::qtanimation::DelayedCall delay = mStarling->get_juggler()->delayCall(this->delay3s_dyn(),(int)1,null());		HX_STACK_VAR(delay,"delay");
	HX_STACK_LINE(63)
	delay->set_repeatCount((int)2);
	HX_STACK_LINE(65)
	delay->addEventListener(HX_CSTRING("removeFromJuggler"),this->onRemove_dyn(),null(),null(),null());
}
;
	return null();
}

Main_obj::~Main_obj() { }

Dynamic Main_obj::__CreateEmpty() { return  new Main_obj; }
hx::ObjectPtr< Main_obj > Main_obj::__new()
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Dynamic Main_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Void Main_obj::onRemove( ::qtframework::events::QTEvent event){
{
		HX_STACK_PUSH("Main::onRemove","Main.hx",84);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(84)
		this->tf->set_text(HX_CSTRING("Remove Delay"));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,onRemove,(void))

Void Main_obj::delay3s( Dynamic args){
{
		HX_STACK_PUSH("Main::delay3s","Main.hx",77);
		HX_STACK_THIS(this);
		HX_STACK_ARG(args,"args");
		HX_STACK_LINE(78)
		this->tf->set_text(::Std_obj::string(this->count));
		HX_STACK_LINE(79)
		(this->count)++;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,delay3s,(void))

Void Main_obj::onEnterFrame( ::flash::events::Event event){
{
		HX_STACK_PUSH("Main::onEnterFrame","Main.hx",70);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(71)
		int t1 = ::flash::Lib_obj::getTimer();		HX_STACK_VAR(t1,"t1");
		HX_STACK_LINE(72)
		this->tf->set_text(::Std_obj::string(t1));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,onEnterFrame,(void))


Main_obj::Main_obj()
{
}

void Main_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Main);
	HX_MARK_MEMBER_NAME(count,"count");
	HX_MARK_MEMBER_NAME(tf,"tf");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Main_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(count,"count");
	HX_VISIT_MEMBER_NAME(tf,"tf");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Main_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"tf") ) { return tf; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"count") ) { return count; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"delay3s") ) { return delay3s_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"onRemove") ) { return onRemove_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"onEnterFrame") ) { return onEnterFrame_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Main_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"tf") ) { tf=inValue.Cast< ::flash::text::TextField >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"count") ) { count=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Main_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("count"));
	outFields->push(HX_CSTRING("tf"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("onRemove"),
	HX_CSTRING("delay3s"),
	HX_CSTRING("count"),
	HX_CSTRING("onEnterFrame"),
	HX_CSTRING("tf"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Main_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Main_obj::__mClass,"__mClass");
};

Class Main_obj::__mClass;

void Main_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Main"), hx::TCanCast< Main_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Main_obj::__boot()
{
}

