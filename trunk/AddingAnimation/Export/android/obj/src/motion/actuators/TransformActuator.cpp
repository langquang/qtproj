#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_flash_display_DisplayObject
#include <flash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_flash_display_IBitmapDrawable
#include <flash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_flash_events_EventDispatcher
#include <flash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_IEventDispatcher
#include <flash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_flash_geom_ColorTransform
#include <flash/geom/ColorTransform.h>
#endif
#ifndef INCLUDED_flash_media_SoundTransform
#include <flash/media/SoundTransform.h>
#endif
#ifndef INCLUDED_motion_actuators_GenericActuator
#include <motion/actuators/GenericActuator.h>
#endif
#ifndef INCLUDED_motion_actuators_IGenericActuator
#include <motion/actuators/IGenericActuator.h>
#endif
#ifndef INCLUDED_motion_actuators_PropertyDetails
#include <motion/actuators/PropertyDetails.h>
#endif
#ifndef INCLUDED_motion_actuators_SimpleActuator
#include <motion/actuators/SimpleActuator.h>
#endif
#ifndef INCLUDED_motion_actuators_TransformActuator
#include <motion/actuators/TransformActuator.h>
#endif
namespace motion{
namespace actuators{

Void TransformActuator_obj::__construct(Dynamic target,Float duration,Dynamic properties)
{
HX_STACK_PUSH("TransformActuator::new","motion/actuators/TransformActuator.hx",24);
{
	HX_STACK_LINE(24)
	super::__construct(target,duration,properties);
}
;
	return null();
}

TransformActuator_obj::~TransformActuator_obj() { }

Dynamic TransformActuator_obj::__CreateEmpty() { return  new TransformActuator_obj; }
hx::ObjectPtr< TransformActuator_obj > TransformActuator_obj::__new(Dynamic target,Float duration,Dynamic properties)
{  hx::ObjectPtr< TransformActuator_obj > result = new TransformActuator_obj();
	result->__construct(target,duration,properties);
	return result;}

Dynamic TransformActuator_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TransformActuator_obj > result = new TransformActuator_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void TransformActuator_obj::update( Float currentTime){
{
		HX_STACK_PUSH("TransformActuator::update","motion/actuators/TransformActuator.hx",175);
		HX_STACK_THIS(this);
		HX_STACK_ARG(currentTime,"currentTime");
		HX_STACK_LINE(177)
		this->super::update(currentTime);
		HX_STACK_LINE(179)
		if (((this->endColorTransform != null()))){
			HX_STACK_LINE(179)
			this->target->__Field(HX_CSTRING("transform"),true)->__FieldRef(HX_CSTRING("colorTransform")) = this->tweenColorTransform;
		}
		HX_STACK_LINE(185)
		if (((this->endSoundTransform != null()))){
			HX_STACK_LINE(185)
			this->target->__FieldRef(HX_CSTRING("soundTransform")) = this->tweenSoundTransform;
		}
	}
return null();
}


Void TransformActuator_obj::initializeSound( ){
{
		HX_STACK_PUSH("TransformActuator::initializeSound","motion/actuators/TransformActuator.hx",146);
		HX_STACK_THIS(this);
		HX_STACK_LINE(148)
		if (((this->target->__Field(HX_CSTRING("soundTransform"),true) == null()))){
			HX_STACK_LINE(148)
			this->target->__FieldRef(HX_CSTRING("soundTransform")) = ::flash::media::SoundTransform_obj::__new(null(),null());
		}
		HX_STACK_LINE(154)
		::flash::media::SoundTransform start = this->target->__Field(HX_CSTRING("soundTransform"),true);		HX_STACK_VAR(start,"start");
		HX_STACK_LINE(155)
		this->endSoundTransform = this->target->__Field(HX_CSTRING("soundTransform"),true);
		HX_STACK_LINE(156)
		this->tweenSoundTransform = ::flash::media::SoundTransform_obj::__new(null(),null());
		HX_STACK_LINE(158)
		if ((::Reflect_obj::hasField(this->properties,HX_CSTRING("soundVolume")))){
			HX_STACK_LINE(160)
			this->endSoundTransform->volume = this->properties->__Field(HX_CSTRING("soundVolume"),true);
			HX_STACK_LINE(161)
			this->propertyDetails->push(::motion::actuators::PropertyDetails_obj::__new(this->tweenSoundTransform,HX_CSTRING("volume"),start->volume,(this->endSoundTransform->volume - start->volume),null()));
		}
		HX_STACK_LINE(165)
		if ((::Reflect_obj::hasField(this->properties,HX_CSTRING("soundPan")))){
			HX_STACK_LINE(167)
			this->endSoundTransform->pan = this->properties->__Field(HX_CSTRING("soundPan"),true);
			HX_STACK_LINE(168)
			this->propertyDetails->push(::motion::actuators::PropertyDetails_obj::__new(this->tweenSoundTransform,HX_CSTRING("pan"),start->pan,(this->endSoundTransform->pan - start->pan),null()));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TransformActuator_obj,initializeSound,(void))

Void TransformActuator_obj::initializeColor( ){
{
		HX_STACK_PUSH("TransformActuator::initializeColor","motion/actuators/TransformActuator.hx",70);
		HX_STACK_THIS(this);
		HX_STACK_LINE(72)
		this->endColorTransform = ::flash::geom::ColorTransform_obj::__new(null(),null(),null(),null(),null(),null(),null(),null());
		HX_STACK_LINE(74)
		int color = this->properties->__Field(HX_CSTRING("colorValue"),true);		HX_STACK_VAR(color,"color");
		HX_STACK_LINE(75)
		Float strength = this->properties->__Field(HX_CSTRING("colorStrength"),true);		HX_STACK_VAR(strength,"strength");
		HX_STACK_LINE(77)
		if (((strength < (int)1))){
			HX_STACK_LINE(79)
			Float multiplier;		HX_STACK_VAR(multiplier,"multiplier");
			HX_STACK_LINE(80)
			Float offset;		HX_STACK_VAR(offset,"offset");
			HX_STACK_LINE(82)
			if (((strength < 0.5))){
				HX_STACK_LINE(84)
				multiplier = (int)1;
				HX_STACK_LINE(85)
				offset = (strength * (int)2);
			}
			else{
				HX_STACK_LINE(89)
				multiplier = ((int)1 - (((strength - 0.5)) * (int)2));
				HX_STACK_LINE(90)
				offset = (int)1;
			}
			HX_STACK_LINE(94)
			this->endColorTransform->redMultiplier = multiplier;
			HX_STACK_LINE(95)
			this->endColorTransform->greenMultiplier = multiplier;
			HX_STACK_LINE(96)
			this->endColorTransform->blueMultiplier = multiplier;
			HX_STACK_LINE(98)
			this->endColorTransform->redOffset = (offset * ((int((int(color) >> int((int)16))) & int((int)255))));
			HX_STACK_LINE(99)
			this->endColorTransform->greenOffset = (offset * ((int((int(color) >> int((int)8))) & int((int)255))));
			HX_STACK_LINE(100)
			this->endColorTransform->blueOffset = (offset * ((int(color) & int((int)255))));
		}
		else{
			HX_STACK_LINE(106)
			this->endColorTransform->redMultiplier = (int)0;
			HX_STACK_LINE(107)
			this->endColorTransform->greenMultiplier = (int)0;
			HX_STACK_LINE(108)
			this->endColorTransform->blueMultiplier = (int)0;
			HX_STACK_LINE(110)
			this->endColorTransform->redOffset = (int((int(color) >> int((int)16))) & int((int)255));
			HX_STACK_LINE(111)
			this->endColorTransform->greenOffset = (int((int(color) >> int((int)8))) & int((int)255));
			HX_STACK_LINE(112)
			this->endColorTransform->blueOffset = (int(color) & int((int)255));
		}
		HX_STACK_LINE(116)
		Array< ::String > propertyNames = Array_obj< ::String >::__new().Add(HX_CSTRING("redMultiplier")).Add(HX_CSTRING("greenMultiplier")).Add(HX_CSTRING("blueMultiplier")).Add(HX_CSTRING("redOffset")).Add(HX_CSTRING("greenOffset")).Add(HX_CSTRING("blueOffset"));		HX_STACK_VAR(propertyNames,"propertyNames");
		HX_STACK_LINE(118)
		if ((::Reflect_obj::hasField(this->properties,HX_CSTRING("colorAlpha")))){
			HX_STACK_LINE(120)
			this->endColorTransform->alphaMultiplier = this->properties->__Field(HX_CSTRING("colorAlpha"),true);
			HX_STACK_LINE(121)
			propertyNames->push(HX_CSTRING("alphaMultiplier"));
		}
		else{
			HX_STACK_LINE(123)
			this->endColorTransform->alphaMultiplier = this->target->__Field(HX_CSTRING("alpha"),true);
		}
		HX_STACK_LINE(129)
		::flash::geom::ColorTransform begin = this->target->__Field(HX_CSTRING("transform"),true)->__Field(HX_CSTRING("colorTransform"),true);		HX_STACK_VAR(begin,"begin");
		HX_STACK_LINE(130)
		this->tweenColorTransform = ::flash::geom::ColorTransform_obj::__new(null(),null(),null(),null(),null(),null(),null(),null());
		HX_STACK_LINE(132)
		::motion::actuators::PropertyDetails details;		HX_STACK_VAR(details,"details");
		HX_STACK_LINE(133)
		Float start;		HX_STACK_VAR(start,"start");
		HX_STACK_LINE(135)
		{
			HX_STACK_LINE(135)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(135)
			while(((_g < propertyNames->length))){
				HX_STACK_LINE(135)
				::String propertyName = propertyNames->__get(_g);		HX_STACK_VAR(propertyName,"propertyName");
				HX_STACK_LINE(135)
				++(_g);
				HX_STACK_LINE(137)
				start = ::Reflect_obj::field(begin,propertyName);
				HX_STACK_LINE(138)
				details = ::motion::actuators::PropertyDetails_obj::__new(this->tweenColorTransform,propertyName,start,(::Reflect_obj::field(this->endColorTransform,propertyName) - start),null());
				HX_STACK_LINE(139)
				this->propertyDetails->push(details);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TransformActuator_obj,initializeColor,(void))

Void TransformActuator_obj::initialize( ){
{
		HX_STACK_PUSH("TransformActuator::initialize","motion/actuators/TransformActuator.hx",50);
		HX_STACK_THIS(this);
		HX_STACK_LINE(52)
		if (((bool(::Reflect_obj::hasField(this->properties,HX_CSTRING("colorValue"))) && bool(::Std_obj::is(this->target,hx::ClassOf< ::flash::display::DisplayObject >()))))){
			HX_STACK_LINE(52)
			this->initializeColor();
		}
		HX_STACK_LINE(58)
		if (((bool(::Reflect_obj::hasField(this->properties,HX_CSTRING("soundVolume"))) || bool(::Reflect_obj::hasField(this->properties,HX_CSTRING("soundPan")))))){
			HX_STACK_LINE(58)
			this->initializeSound();
		}
		HX_STACK_LINE(64)
		this->detailsLength = this->propertyDetails->length;
		HX_STACK_LINE(65)
		this->initialized = true;
	}
return null();
}


Void TransformActuator_obj::apply( ){
{
		HX_STACK_PUSH("TransformActuator::apply","motion/actuators/TransformActuator.hx",31);
		HX_STACK_THIS(this);
		HX_STACK_LINE(33)
		this->initialize();
		HX_STACK_LINE(35)
		if (((this->endColorTransform != null()))){
			HX_STACK_LINE(35)
			this->target->__Field(HX_CSTRING("transform"),true)->__FieldRef(HX_CSTRING("colorTransform")) = this->endColorTransform;
		}
		HX_STACK_LINE(41)
		if (((this->endSoundTransform != null()))){
			HX_STACK_LINE(41)
			this->target->__FieldRef(HX_CSTRING("soundTransform")) = this->endSoundTransform;
		}
	}
return null();
}



TransformActuator_obj::TransformActuator_obj()
{
}

void TransformActuator_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TransformActuator);
	HX_MARK_MEMBER_NAME(tweenSoundTransform,"tweenSoundTransform");
	HX_MARK_MEMBER_NAME(tweenColorTransform,"tweenColorTransform");
	HX_MARK_MEMBER_NAME(endSoundTransform,"endSoundTransform");
	HX_MARK_MEMBER_NAME(endColorTransform,"endColorTransform");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void TransformActuator_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(tweenSoundTransform,"tweenSoundTransform");
	HX_VISIT_MEMBER_NAME(tweenColorTransform,"tweenColorTransform");
	HX_VISIT_MEMBER_NAME(endSoundTransform,"endSoundTransform");
	HX_VISIT_MEMBER_NAME(endColorTransform,"endColorTransform");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic TransformActuator_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"apply") ) { return apply_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"initialize") ) { return initialize_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"initializeSound") ) { return initializeSound_dyn(); }
		if (HX_FIELD_EQ(inName,"initializeColor") ) { return initializeColor_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"endSoundTransform") ) { return endSoundTransform; }
		if (HX_FIELD_EQ(inName,"endColorTransform") ) { return endColorTransform; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"tweenSoundTransform") ) { return tweenSoundTransform; }
		if (HX_FIELD_EQ(inName,"tweenColorTransform") ) { return tweenColorTransform; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TransformActuator_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 17:
		if (HX_FIELD_EQ(inName,"endSoundTransform") ) { endSoundTransform=inValue.Cast< ::flash::media::SoundTransform >(); return inValue; }
		if (HX_FIELD_EQ(inName,"endColorTransform") ) { endColorTransform=inValue.Cast< ::flash::geom::ColorTransform >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"tweenSoundTransform") ) { tweenSoundTransform=inValue.Cast< ::flash::media::SoundTransform >(); return inValue; }
		if (HX_FIELD_EQ(inName,"tweenColorTransform") ) { tweenColorTransform=inValue.Cast< ::flash::geom::ColorTransform >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TransformActuator_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("tweenSoundTransform"));
	outFields->push(HX_CSTRING("tweenColorTransform"));
	outFields->push(HX_CSTRING("endSoundTransform"));
	outFields->push(HX_CSTRING("endColorTransform"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("update"),
	HX_CSTRING("initializeSound"),
	HX_CSTRING("initializeColor"),
	HX_CSTRING("initialize"),
	HX_CSTRING("apply"),
	HX_CSTRING("tweenSoundTransform"),
	HX_CSTRING("tweenColorTransform"),
	HX_CSTRING("endSoundTransform"),
	HX_CSTRING("endColorTransform"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TransformActuator_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TransformActuator_obj::__mClass,"__mClass");
};

Class TransformActuator_obj::__mClass;

void TransformActuator_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("motion.actuators.TransformActuator"), hx::TCanCast< TransformActuator_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void TransformActuator_obj::__boot()
{
}

} // end namespace motion
} // end namespace actuators
