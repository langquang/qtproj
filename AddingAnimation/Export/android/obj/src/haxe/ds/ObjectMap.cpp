#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_IntMap
#include <haxe/ds/IntMap.h>
#endif
#ifndef INCLUDED_haxe_ds_ObjectMap
#include <haxe/ds/ObjectMap.h>
#endif
namespace haxe{
namespace ds{

Void ObjectMap_obj::__construct()
{
HX_STACK_PUSH("ObjectMap::new","C:\\HaxeToolkit\\haxe/std/cpp/_std/haxe/ds/ObjectMap.hx",29);
{
	HX_STACK_LINE(29)
	this->__Internal = ::haxe::ds::IntMap_obj::__new();
}
;
	return null();
}

ObjectMap_obj::~ObjectMap_obj() { }

Dynamic ObjectMap_obj::__CreateEmpty() { return  new ObjectMap_obj; }
hx::ObjectPtr< ObjectMap_obj > ObjectMap_obj::__new()
{  hx::ObjectPtr< ObjectMap_obj > result = new ObjectMap_obj();
	result->__construct();
	return result;}

Dynamic ObjectMap_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ObjectMap_obj > result = new ObjectMap_obj();
	result->__construct();
	return result;}

hx::Object *ObjectMap_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::IMap_obj)) return operator ::IMap_obj *();
	return super::__ToInterface(inType);
}

Dynamic ObjectMap_obj::iterator( ){
	HX_STACK_PUSH("ObjectMap::iterator","C:\\HaxeToolkit\\haxe/std/cpp/_std/haxe/ds/ObjectMap.hx",57);
	HX_STACK_THIS(this);
	HX_STACK_LINE(57)
	return this->__Internal->iterator();
}


HX_DEFINE_DYNAMIC_FUNC0(ObjectMap_obj,iterator,return )

Dynamic ObjectMap_obj::get( Dynamic key){
	HX_STACK_PUSH("ObjectMap::get","C:\\HaxeToolkit\\haxe/std/cpp/_std/haxe/ds/ObjectMap.hx",37);
	HX_STACK_THIS(this);
	HX_STACK_ARG(key,"key");
	HX_STACK_LINE(37)
	return this->__Internal->get(::__hxcpp_obj_id(key));
}


HX_DEFINE_DYNAMIC_FUNC1(ObjectMap_obj,get,return )


ObjectMap_obj::ObjectMap_obj()
{
}

void ObjectMap_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ObjectMap);
	HX_MARK_MEMBER_NAME(__Internal,"__Internal");
	HX_MARK_END_CLASS();
}

void ObjectMap_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(__Internal,"__Internal");
}

Dynamic ObjectMap_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"get") ) { return get_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"iterator") ) { return iterator_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"__Internal") ) { return __Internal; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ObjectMap_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"__Internal") ) { __Internal=inValue.Cast< ::haxe::ds::IntMap >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ObjectMap_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("__Internal"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("iterator"),
	HX_CSTRING("get"),
	HX_CSTRING("__Internal"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ObjectMap_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ObjectMap_obj::__mClass,"__mClass");
};

Class ObjectMap_obj::__mClass;

void ObjectMap_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.ds.ObjectMap"), hx::TCanCast< ObjectMap_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void ObjectMap_obj::__boot()
{
}

} // end namespace haxe
} // end namespace ds
