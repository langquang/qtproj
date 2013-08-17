#ifndef INCLUDED_qtframework_qtanimation_IAnimatable
#define INCLUDED_qtframework_qtanimation_IAnimatable

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(qtframework,qtanimation,IAnimatable)
namespace qtframework{
namespace qtanimation{


class HXCPP_CLASS_ATTRIBUTES  IAnimatable_obj : public hx::Interface{
	public:
		typedef hx::Interface super;
		typedef IAnimatable_obj OBJ_;
		HX_DO_INTERFACE_RTTI;
		static void __boot();
virtual Void advanceTime( Float time)=0;
		Dynamic advanceTime_dyn();
};

#define DELEGATE_qtframework_qtanimation_IAnimatable \
virtual Void advanceTime( Float time) { return mDelegate->advanceTime(time);}  \
virtual Dynamic advanceTime_dyn() { return mDelegate->advanceTime_dyn();}  \


template<typename IMPL>
class IAnimatable_delegate_ : public IAnimatable_obj
{
	protected:
		IMPL *mDelegate;
	public:
		IAnimatable_delegate_(IMPL *inDelegate) : mDelegate(inDelegate) {}
		hx::Object *__GetRealObject() { return mDelegate; }
		void __Visit(HX_VISIT_PARAMS) { HX_VISIT_OBJECT(mDelegate); }
		DELEGATE_qtframework_qtanimation_IAnimatable
};

} // end namespace qtframework
} // end namespace qtanimation

#endif /* INCLUDED_qtframework_qtanimation_IAnimatable */ 
