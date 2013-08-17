#include <hxcpp.h>

#ifndef INCLUDED_qtframework_qtanimation_IAnimatable
#include <qtframework/qtanimation/IAnimatable.h>
#endif
namespace qtframework{
namespace qtanimation{

HX_DEFINE_DYNAMIC_FUNC1(IAnimatable_obj,advanceTime,)


static ::String sMemberFields[] = {
	HX_CSTRING("advanceTime"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(IAnimatable_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(IAnimatable_obj::__mClass,"__mClass");
};

Class IAnimatable_obj::__mClass;

void IAnimatable_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("qtframework.qtanimation.IAnimatable"), hx::TCanCast< IAnimatable_obj> ,0,sMemberFields,
	0, 0,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void IAnimatable_obj::__boot()
{
}

} // end namespace qtframework
} // end namespace qtanimation
