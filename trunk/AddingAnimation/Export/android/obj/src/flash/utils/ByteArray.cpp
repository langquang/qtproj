#include <hxcpp.h>

#ifndef INCLUDED_cpp_zip_Compress
#include <cpp/zip/Compress.h>
#endif
#ifndef INCLUDED_cpp_zip_Uncompress
#include <cpp/zip/Uncompress.h>
#endif
#ifndef INCLUDED_flash_Lib
#include <flash/Lib.h>
#endif
#ifndef INCLUDED_flash_errors_EOFError
#include <flash/errors/EOFError.h>
#endif
#ifndef INCLUDED_flash_errors_Error
#include <flash/errors/Error.h>
#endif
#ifndef INCLUDED_flash_utils_ByteArray
#include <flash/utils/ByteArray.h>
#endif
#ifndef INCLUDED_flash_utils_CompressionAlgorithm
#include <flash/utils/CompressionAlgorithm.h>
#endif
#ifndef INCLUDED_flash_utils_IDataInput
#include <flash/utils/IDataInput.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_openfl_utils_IMemoryRange
#include <openfl/utils/IMemoryRange.h>
#endif
namespace flash{
namespace utils{

Void ByteArray_obj::__construct(hx::Null< int >  __o_size)
{
HX_STACK_PUSH("ByteArray::new","flash/utils/ByteArray.hx",37);
int size = __o_size.Default(0);
{
	HX_STACK_LINE(39)
	this->bigEndian = true;
	HX_STACK_LINE(40)
	this->position = (int)0;
	HX_STACK_LINE(42)
	if (((size >= (int)0))){
		HX_STACK_LINE(52)
		Array< unsigned char > data = Array_obj< unsigned char >::__new();		HX_STACK_VAR(data,"data");
		HX_STACK_LINE(54)
		if (((size > (int)0))){
			HX_STACK_LINE(54)
			data[(size - (int)1)] = (int)0;
		}
		HX_STACK_LINE(60)
		super::__construct(size,data);
	}
}
;
	return null();
}

ByteArray_obj::~ByteArray_obj() { }

Dynamic ByteArray_obj::__CreateEmpty() { return  new ByteArray_obj; }
hx::ObjectPtr< ByteArray_obj > ByteArray_obj::__new(hx::Null< int >  __o_size)
{  hx::ObjectPtr< ByteArray_obj > result = new ByteArray_obj();
	result->__construct(__o_size);
	return result;}

Dynamic ByteArray_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ByteArray_obj > result = new ByteArray_obj();
	result->__construct(inArgs[0]);
	return result;}

hx::Object *ByteArray_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::openfl::utils::IMemoryRange_obj)) return operator ::openfl::utils::IMemoryRange_obj *();
	if (inType==typeid( ::flash::utils::IDataInput_obj)) return operator ::flash::utils::IDataInput_obj *();
	return super::__ToInterface(inType);
}

void ByteArray_obj::__init__() {
HX_STACK_PUSH("ByteArray::__init__","flash/utils/ByteArray.hx",695);
{

	HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_1)
	::flash::utils::ByteArray run(int length){
		HX_STACK_PUSH("*::_Function_1_1","flash/utils/ByteArray.hx",697);
		HX_STACK_ARG(length,"length");
		{
			HX_STACK_LINE(697)
			return ::flash::utils::ByteArray_obj::__new(length);
		}
		return null();
	}
	HX_END_LOCAL_FUNC1(return)

	HX_STACK_LINE(697)
	Dynamic factory =  Dynamic(new _Function_1_1());		HX_STACK_VAR(factory,"factory");

	HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_2)
	Void run(::flash::utils::ByteArray bytes,int length){
		HX_STACK_PUSH("*::_Function_1_2","flash/utils/ByteArray.hx",698);
		HX_STACK_ARG(bytes,"bytes");
		HX_STACK_ARG(length,"length");
		{
			HX_STACK_LINE(700)
			if (((length > (int)0))){
				HX_STACK_LINE(700)
				bytes->__Field(HX_CSTRING("ensureElem"),true)((length - (int)1),true);
			}
			HX_STACK_LINE(706)
			bytes->__FieldRef(HX_CSTRING("length")) = length;
		}
		return null();
	}
	HX_END_LOCAL_FUNC2((void))

	HX_STACK_LINE(698)
	Dynamic resize =  Dynamic(new _Function_1_2());		HX_STACK_VAR(resize,"resize");

	HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_3)
	Array< unsigned char > run(::flash::utils::ByteArray bytes){
		HX_STACK_PUSH("*::_Function_1_3","flash/utils/ByteArray.hx",710);
		HX_STACK_ARG(bytes,"bytes");
		{
			HX_STACK_LINE(710)
			return (  (((bytes == null()))) ? Array< unsigned char >(null()) : Array< unsigned char >(bytes->__Field(HX_CSTRING("b"),true)) );
		}
		return null();
	}
	HX_END_LOCAL_FUNC1(return)

	HX_STACK_LINE(710)
	Dynamic bytes =  Dynamic(new _Function_1_3());		HX_STACK_VAR(bytes,"bytes");

	HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_4)
	int run(::flash::utils::ByteArray bytes1){
		HX_STACK_PUSH("*::_Function_1_4","flash/utils/ByteArray.hx",711);
		HX_STACK_ARG(bytes1,"bytes1");
		{
			HX_STACK_LINE(711)
			return (  (((bytes1 == null()))) ? int((int)0) : int(bytes1->__Field(HX_CSTRING("length"),true)) );
		}
		return null();
	}
	HX_END_LOCAL_FUNC1(return)

	HX_STACK_LINE(711)
	Dynamic slen =  Dynamic(new _Function_1_4());		HX_STACK_VAR(slen,"slen");
	HX_STACK_LINE(713)
	Dynamic init = ::flash::Lib_obj::load(HX_CSTRING("nme"),HX_CSTRING("nme_byte_array_init"),(int)4);		HX_STACK_VAR(init,"init");
	HX_STACK_LINE(714)
	init(factory,slen,resize,bytes);
}
}

::String ByteArray_obj::set_endian( ::String value){
	HX_STACK_PUSH("ByteArray::set_endian","flash/utils/ByteArray.hx",750);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(750)
	this->bigEndian = (value == HX_CSTRING("bigEndian"));
	HX_STACK_LINE(750)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,set_endian,return )

::String ByteArray_obj::get_endian( ){
	HX_STACK_PUSH("ByteArray::get_endian","flash/utils/ByteArray.hx",749);
	HX_STACK_THIS(this);
	HX_STACK_LINE(749)
	return (  ((this->bigEndian)) ? ::String(HX_CSTRING("bigEndian")) : ::String(HX_CSTRING("littleEndian")) );
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,get_endian,return )

int ByteArray_obj::get_byteLength( ){
	HX_STACK_PUSH("ByteArray::get_byteLength","flash/utils/ByteArray.hx",748);
	HX_STACK_THIS(this);
	HX_STACK_LINE(748)
	return this->length;
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,get_byteLength,return )

int ByteArray_obj::get_bytesAvailable( ){
	HX_STACK_PUSH("ByteArray::get_bytesAvailable","flash/utils/ByteArray.hx",747);
	HX_STACK_THIS(this);
	HX_STACK_LINE(747)
	return (this->length - this->position);
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,get_bytesAvailable,return )

int ByteArray_obj::__throwEOFi( ){
	HX_STACK_PUSH("ByteArray::__throwEOFi","flash/utils/ByteArray.hx",732);
	HX_STACK_THIS(this);
	HX_STACK_LINE(734)
	hx::Throw (::flash::errors::EOFError_obj::__new());
	HX_STACK_LINE(735)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,__throwEOFi,return )

Void ByteArray_obj::__set( int pos,int v){
{
		HX_STACK_PUSH("ByteArray::__set","flash/utils/ByteArray.hx",721);
		HX_STACK_THIS(this);
		HX_STACK_ARG(pos,"pos");
		HX_STACK_ARG(v,"v");
		HX_STACK_LINE(721)
		this->b[pos] = v;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ByteArray_obj,__set,(void))

int ByteArray_obj::__get( int pos){
	HX_STACK_PUSH("ByteArray::__get","flash/utils/ByteArray.hx",682);
	HX_STACK_THIS(this);
	HX_STACK_ARG(pos,"pos");
	HX_STACK_LINE(682)
	return this->b->__get(pos);
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,__get,return )

Void ByteArray_obj::__fromBytes( ::haxe::io::Bytes bytes){
{
		HX_STACK_PUSH("ByteArray::__fromBytes","flash/utils/ByteArray.hx",670);
		HX_STACK_THIS(this);
		HX_STACK_ARG(bytes,"bytes");
		HX_STACK_LINE(672)
		this->b = bytes->b;
		HX_STACK_LINE(673)
		this->length = bytes->length;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,__fromBytes,(void))

Void ByteArray_obj::writeUTFBytes( ::String s){
{
		HX_STACK_PUSH("ByteArray::writeUTFBytes","flash/utils/ByteArray.hx",657);
		HX_STACK_THIS(this);
		HX_STACK_ARG(s,"s");
		HX_STACK_LINE(662)
		::haxe::io::Bytes bytes = ::haxe::io::Bytes_obj::ofString(s);		HX_STACK_VAR(bytes,"bytes");
		HX_STACK_LINE(665)
		this->writeBytes(bytes,null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,writeUTFBytes,(void))

Void ByteArray_obj::writeUTF( ::String s){
{
		HX_STACK_PUSH("ByteArray::writeUTF","flash/utils/ByteArray.hx",643);
		HX_STACK_THIS(this);
		HX_STACK_ARG(s,"s");
		HX_STACK_LINE(648)
		::haxe::io::Bytes bytes = ::haxe::io::Bytes_obj::ofString(s);		HX_STACK_VAR(bytes,"bytes");
		HX_STACK_LINE(651)
		this->writeShort(bytes->length);
		HX_STACK_LINE(652)
		this->writeBytes(bytes,null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,writeUTF,(void))

Void ByteArray_obj::writeUnsignedInt( int value){
{
		HX_STACK_PUSH("ByteArray::writeUnsignedInt","flash/utils/ByteArray.hx",636);
		HX_STACK_THIS(this);
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(636)
		this->writeInt(value);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,writeUnsignedInt,(void))

Void ByteArray_obj::writeShort( int value){
{
		HX_STACK_PUSH("ByteArray::writeShort","flash/utils/ByteArray.hx",617);
		HX_STACK_THIS(this);
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(619)
		this->ensureElem((this->position + (int)1),true);
		HX_STACK_LINE(621)
		if ((this->bigEndian)){
			HX_STACK_LINE(623)
			this->b->__unsafe_set((this->position)++,(int(value) >> int((int)8)));
			HX_STACK_LINE(624)
			this->b->__unsafe_set((this->position)++,value);
		}
		else{
			HX_STACK_LINE(628)
			this->b->__unsafe_set((this->position)++,value);
			HX_STACK_LINE(629)
			this->b->__unsafe_set((this->position)++,(int(value) >> int((int)8)));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,writeShort,(void))

Void ByteArray_obj::writeInt( int value){
{
		HX_STACK_PUSH("ByteArray::writeInt","flash/utils/ByteArray.hx",594);
		HX_STACK_THIS(this);
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(596)
		this->ensureElem((this->position + (int)3),true);
		HX_STACK_LINE(598)
		if ((this->bigEndian)){
			HX_STACK_LINE(600)
			this->b->__unsafe_set((this->position)++,(int(value) >> int((int)24)));
			HX_STACK_LINE(601)
			this->b->__unsafe_set((this->position)++,(int(value) >> int((int)16)));
			HX_STACK_LINE(602)
			this->b->__unsafe_set((this->position)++,(int(value) >> int((int)8)));
			HX_STACK_LINE(603)
			this->b->__unsafe_set((this->position)++,value);
		}
		else{
			HX_STACK_LINE(607)
			this->b->__unsafe_set((this->position)++,value);
			HX_STACK_LINE(608)
			this->b->__unsafe_set((this->position)++,(int(value) >> int((int)8)));
			HX_STACK_LINE(609)
			this->b->__unsafe_set((this->position)++,(int(value) >> int((int)16)));
			HX_STACK_LINE(610)
			this->b->__unsafe_set((this->position)++,(int(value) >> int((int)24)));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,writeInt,(void))

Void ByteArray_obj::writeFloat( Float x){
{
		HX_STACK_PUSH("ByteArray::writeFloat","flash/utils/ByteArray.hx",581);
		HX_STACK_THIS(this);
		HX_STACK_ARG(x,"x");
		HX_STACK_LINE(586)
		::haxe::io::Bytes bytes = ::haxe::io::Bytes_obj::ofData(::flash::utils::ByteArray_obj::_float_bytes(x,this->bigEndian));		HX_STACK_VAR(bytes,"bytes");
		HX_STACK_LINE(589)
		this->writeBytes(bytes,null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,writeFloat,(void))

Void ByteArray_obj::writeFile( ::String path){
{
		HX_STACK_PUSH("ByteArray::writeFile","flash/utils/ByteArray.hx",572);
		HX_STACK_THIS(this);
		HX_STACK_ARG(path,"path");
		HX_STACK_LINE(572)
		::flash::utils::ByteArray_obj::nme_byte_array_overwrite_file(path,hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,writeFile,(void))

Void ByteArray_obj::writeDouble( Float x){
{
		HX_STACK_PUSH("ByteArray::writeDouble","flash/utils/ByteArray.hx",557);
		HX_STACK_THIS(this);
		HX_STACK_ARG(x,"x");
		HX_STACK_LINE(562)
		::haxe::io::Bytes bytes = ::haxe::io::Bytes_obj::ofData(::flash::utils::ByteArray_obj::_double_bytes(x,this->bigEndian));		HX_STACK_VAR(bytes,"bytes");
		HX_STACK_LINE(565)
		this->writeBytes(bytes,null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,writeDouble,(void))

Void ByteArray_obj::writeBytes( ::haxe::io::Bytes bytes,hx::Null< int >  __o_offset,hx::Null< int >  __o_length){
int offset = __o_offset.Default(0);
int length = __o_length.Default(0);
	HX_STACK_PUSH("ByteArray::writeBytes","flash/utils/ByteArray.hx",546);
	HX_STACK_THIS(this);
	HX_STACK_ARG(bytes,"bytes");
	HX_STACK_ARG(offset,"offset");
	HX_STACK_ARG(length,"length");
{
		HX_STACK_LINE(548)
		if (((length == (int)0))){
			HX_STACK_LINE(548)
			length = (bytes->length - offset);
		}
		HX_STACK_LINE(549)
		this->ensureElem(((this->position + length) - (int)1),true);
		HX_STACK_LINE(550)
		int opos = this->position;		HX_STACK_VAR(opos,"opos");
		HX_STACK_LINE(551)
		hx::AddEq(this->position,length);
		HX_STACK_LINE(552)
		this->blit(opos,bytes,offset,length);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(ByteArray_obj,writeBytes,(void))

Void ByteArray_obj::writeByte( int value){
{
		HX_STACK_PUSH("ByteArray::writeByte","flash/utils/ByteArray.hx",533);
		HX_STACK_THIS(this);
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(535)
		this->ensureElem(this->position,true);
		HX_STACK_LINE(538)
		this->b[(this->position)++] = value;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,writeByte,(void))

Void ByteArray_obj::writeBoolean( bool value){
{
		HX_STACK_PUSH("ByteArray::writeBoolean","flash/utils/ByteArray.hx",526);
		HX_STACK_THIS(this);
		HX_STACK_ARG(value,"value");
		HX_STACK_LINE(528)
		this->ensureElem(this->position,true);
		HX_STACK_LINE(528)
		this->b[(this->position)++] = (  ((value)) ? int((int)1) : int((int)0) );
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,writeBoolean,(void))

Void ByteArray_obj::write_uncheck( int byte){
{
		HX_STACK_PUSH("ByteArray::write_uncheck","flash/utils/ByteArray.hx",515);
		HX_STACK_THIS(this);
		HX_STACK_ARG(byte,"byte");
		HX_STACK_LINE(515)
		this->b->__unsafe_set((this->position)++,byte);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,write_uncheck,(void))

Void ByteArray_obj::uncompress( ::flash::utils::CompressionAlgorithm algorithm){
{
		HX_STACK_PUSH("ByteArray::uncompress","flash/utils/ByteArray.hx",471);
		HX_STACK_THIS(this);
		HX_STACK_ARG(algorithm,"algorithm");
		HX_STACK_LINE(473)
		if (((algorithm == null()))){
			HX_STACK_LINE(473)
			algorithm = ::flash::utils::CompressionAlgorithm_obj::ZLIB;
		}
		HX_STACK_LINE(478)
		::flash::utils::ByteArray src = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(src,"src");
		HX_STACK_LINE(481)
		::haxe::io::Bytes result;		HX_STACK_VAR(result,"result");
		HX_STACK_LINE(483)
		if (((algorithm == ::flash::utils::CompressionAlgorithm_obj::LZMA))){
			HX_STACK_LINE(483)
			result = ::haxe::io::Bytes_obj::ofData(::flash::utils::ByteArray_obj::nme_lzma_decode(src->b));
		}
		else{
			struct _Function_2_1{
				inline static int Block( ::flash::utils::CompressionAlgorithm &algorithm){
					HX_STACK_PUSH("*::closure","flash/utils/ByteArray.hx",489);
					{
						HX_STACK_LINE(489)
						{
							::flash::utils::CompressionAlgorithm _switch_1 = (algorithm);
							switch((_switch_1)->GetIndex()){
								case 0: {
									HX_STACK_LINE(491)
									return (int)-15;
								}
								;break;
								case 3: {
									HX_STACK_LINE(492)
									return (int)31;
								}
								;break;
								default: {
									HX_STACK_LINE(493)
									return (int)15;
								}
							}
						}
					}
					return null();
				}
			};
			HX_STACK_LINE(489)
			int windowBits = _Function_2_1::Block(algorithm);		HX_STACK_VAR(windowBits,"windowBits");
			HX_STACK_LINE(500)
			result = ::cpp::zip::Uncompress_obj::run(src,null());
		}
		HX_STACK_LINE(505)
		this->b = result->b;
		HX_STACK_LINE(506)
		this->length = result->length;
		HX_STACK_LINE(507)
		this->position = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,uncompress,(void))

::flash::utils::ByteArray ByteArray_obj::slice( int begin,Dynamic end){
	HX_STACK_PUSH("ByteArray::slice","flash/utils/ByteArray.hx",423);
	HX_STACK_THIS(this);
	HX_STACK_ARG(begin,"begin");
	HX_STACK_ARG(end,"end");
	HX_STACK_LINE(425)
	if (((begin < (int)0))){
		HX_STACK_LINE(427)
		hx::AddEq(begin,this->length);
		HX_STACK_LINE(429)
		if (((begin < (int)0))){
			HX_STACK_LINE(429)
			begin = (int)0;
		}
	}
	HX_STACK_LINE(437)
	if (((end == null()))){
		HX_STACK_LINE(437)
		end = this->length;
	}
	HX_STACK_LINE(443)
	if (((end < (int)0))){
		HX_STACK_LINE(445)
		hx::AddEq(end,this->length);
		HX_STACK_LINE(447)
		if (((end < (int)0))){
			HX_STACK_LINE(447)
			end = (int)0;
		}
	}
	HX_STACK_LINE(455)
	if (((begin >= end))){
		HX_STACK_LINE(455)
		return ::flash::utils::ByteArray_obj::__new(null());
	}
	HX_STACK_LINE(461)
	::flash::utils::ByteArray result = ::flash::utils::ByteArray_obj::__new((end - begin));		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(463)
	int opos = this->position;		HX_STACK_VAR(opos,"opos");
	HX_STACK_LINE(464)
	result->blit((int)0,hx::ObjectPtr<OBJ_>(this),begin,(end - begin));
	HX_STACK_LINE(466)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC2(ByteArray_obj,slice,return )

Void ByteArray_obj::setLength( int length){
{
		HX_STACK_PUSH("ByteArray::setLength","flash/utils/ByteArray.hx",410);
		HX_STACK_THIS(this);
		HX_STACK_ARG(length,"length");
		HX_STACK_LINE(412)
		if (((length > (int)0))){
			HX_STACK_LINE(412)
			this->ensureElem((length - (int)1),false);
		}
		HX_STACK_LINE(418)
		this->length = length;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,setLength,(void))

::String ByteArray_obj::readUTFBytes( int length){
	HX_STACK_PUSH("ByteArray::readUTFBytes","flash/utils/ByteArray.hx",388);
	HX_STACK_THIS(this);
	HX_STACK_ARG(length,"length");
	HX_STACK_LINE(390)
	if ((((this->position + length) > this->length))){
		HX_STACK_LINE(390)
		this->__throwEOFi();
	}
	HX_STACK_LINE(396)
	int p = this->position;		HX_STACK_VAR(p,"p");
	HX_STACK_LINE(397)
	hx::AddEq(this->position,length);
	HX_STACK_LINE(402)
	::String result = HX_CSTRING("");		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(403)
	::__hxcpp_string_of_bytes(this->b,result,p,length);
	HX_STACK_LINE(404)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,readUTFBytes,return )

::String ByteArray_obj::readUTF( ){
	HX_STACK_PUSH("ByteArray::readUTF","flash/utils/ByteArray.hx",380);
	HX_STACK_THIS(this);
	HX_STACK_LINE(382)
	int len = this->readUnsignedShort();		HX_STACK_VAR(len,"len");
	HX_STACK_LINE(383)
	return this->readUTFBytes(len);
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,readUTF,return )

int ByteArray_obj::readUnsignedShort( ){
	HX_STACK_PUSH("ByteArray::readUnsignedShort","flash/utils/ByteArray.hx",370);
	HX_STACK_THIS(this);
	HX_STACK_LINE(372)
	int ch1 = (  (((this->position < this->length))) ? int(this->b->__get((this->position)++)) : int(this->__throwEOFi()) );		HX_STACK_VAR(ch1,"ch1");
	HX_STACK_LINE(373)
	int ch2 = (  (((this->position < this->length))) ? int(this->b->__get((this->position)++)) : int(this->__throwEOFi()) );		HX_STACK_VAR(ch2,"ch2");
	HX_STACK_LINE(375)
	return (  ((this->bigEndian)) ? int((int((int(ch1) << int((int)8))) | int(ch2))) : int((((int(ch2) << int((int)8))) + ch1)) );
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,readUnsignedShort,return )

int ByteArray_obj::readUnsignedInt( ){
	HX_STACK_PUSH("ByteArray::readUnsignedInt","flash/utils/ByteArray.hx",358);
	HX_STACK_THIS(this);
	HX_STACK_LINE(360)
	int ch1 = (  (((this->position < this->length))) ? int(this->b->__get((this->position)++)) : int(this->__throwEOFi()) );		HX_STACK_VAR(ch1,"ch1");
	HX_STACK_LINE(361)
	int ch2 = (  (((this->position < this->length))) ? int(this->b->__get((this->position)++)) : int(this->__throwEOFi()) );		HX_STACK_VAR(ch2,"ch2");
	HX_STACK_LINE(362)
	int ch3 = (  (((this->position < this->length))) ? int(this->b->__get((this->position)++)) : int(this->__throwEOFi()) );		HX_STACK_VAR(ch3,"ch3");
	HX_STACK_LINE(363)
	int ch4 = (  (((this->position < this->length))) ? int(this->b->__get((this->position)++)) : int(this->__throwEOFi()) );		HX_STACK_VAR(ch4,"ch4");
	HX_STACK_LINE(365)
	return (  ((this->bigEndian)) ? int((int((int((int((int(ch1) << int((int)24))) | int((int(ch2) << int((int)16))))) | int((int(ch3) << int((int)8))))) | int(ch4))) : int((int((int((int((int(ch4) << int((int)24))) | int((int(ch3) << int((int)16))))) | int((int(ch2) << int((int)8))))) | int(ch1))) );
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,readUnsignedInt,return )

int ByteArray_obj::readUnsignedByte( ){
	HX_STACK_PUSH("ByteArray::readUnsignedByte","flash/utils/ByteArray.hx",351);
	HX_STACK_THIS(this);
	HX_STACK_LINE(351)
	return (  (((this->position < this->length))) ? int(this->b->__get((this->position)++)) : int(this->__throwEOFi()) );
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,readUnsignedByte,return )

int ByteArray_obj::readShort( ){
	HX_STACK_PUSH("ByteArray::readShort","flash/utils/ByteArray.hx",339);
	HX_STACK_THIS(this);
	HX_STACK_LINE(341)
	int ch1 = (  (((this->position < this->length))) ? int(this->b->__get((this->position)++)) : int(this->__throwEOFi()) );		HX_STACK_VAR(ch1,"ch1");
	HX_STACK_LINE(342)
	int ch2 = (  (((this->position < this->length))) ? int(this->b->__get((this->position)++)) : int(this->__throwEOFi()) );		HX_STACK_VAR(ch2,"ch2");
	HX_STACK_LINE(344)
	int value = (  ((this->bigEndian)) ? int((int((int(ch1) << int((int)8))) | int(ch2))) : int((int((int(ch2) << int((int)8))) | int(ch1))) );		HX_STACK_VAR(value,"value");
	HX_STACK_LINE(346)
	return (  (((((int(value) & int((int)32768))) != (int)0))) ? int((value - (int)65536)) : int(value) );
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,readShort,return )

::String ByteArray_obj::readMultiByte( int length,::String charSet){
	HX_STACK_PUSH("ByteArray::readMultiByte","flash/utils/ByteArray.hx",332);
	HX_STACK_THIS(this);
	HX_STACK_ARG(length,"length");
	HX_STACK_ARG(charSet,"charSet");
	HX_STACK_LINE(332)
	return this->readUTFBytes(length);
}


HX_DEFINE_DYNAMIC_FUNC2(ByteArray_obj,readMultiByte,return )

int ByteArray_obj::readInt( ){
	HX_STACK_PUSH("ByteArray::readInt","flash/utils/ByteArray.hx",320);
	HX_STACK_THIS(this);
	HX_STACK_LINE(322)
	int ch1 = (  (((this->position < this->length))) ? int(this->b->__get((this->position)++)) : int(this->__throwEOFi()) );		HX_STACK_VAR(ch1,"ch1");
	HX_STACK_LINE(323)
	int ch2 = (  (((this->position < this->length))) ? int(this->b->__get((this->position)++)) : int(this->__throwEOFi()) );		HX_STACK_VAR(ch2,"ch2");
	HX_STACK_LINE(324)
	int ch3 = (  (((this->position < this->length))) ? int(this->b->__get((this->position)++)) : int(this->__throwEOFi()) );		HX_STACK_VAR(ch3,"ch3");
	HX_STACK_LINE(325)
	int ch4 = (  (((this->position < this->length))) ? int(this->b->__get((this->position)++)) : int(this->__throwEOFi()) );		HX_STACK_VAR(ch4,"ch4");
	HX_STACK_LINE(327)
	return (  ((this->bigEndian)) ? int((int((int((int((int(ch1) << int((int)24))) | int((int(ch2) << int((int)16))))) | int((int(ch3) << int((int)8))))) | int(ch4))) : int((int((int((int((int(ch4) << int((int)24))) | int((int(ch3) << int((int)16))))) | int((int(ch2) << int((int)8))))) | int(ch1))) );
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,readInt,return )

Float ByteArray_obj::readFloat( ){
	HX_STACK_PUSH("ByteArray::readFloat","flash/utils/ByteArray.hx",300);
	HX_STACK_THIS(this);
	HX_STACK_LINE(302)
	if ((((this->position + (int)4) > this->length))){
		HX_STACK_LINE(302)
		this->__throwEOFi();
	}
	HX_STACK_LINE(311)
	::haxe::io::Bytes bytes = ::haxe::io::Bytes_obj::__new((int)4,this->b->slice(this->position,(this->position + (int)4)));		HX_STACK_VAR(bytes,"bytes");
	HX_STACK_LINE(314)
	hx::AddEq(this->position,(int)4);
	HX_STACK_LINE(315)
	return ::flash::utils::ByteArray_obj::_float_of_bytes(bytes->b,this->bigEndian);
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,readFloat,return )

Float ByteArray_obj::readDouble( ){
	HX_STACK_PUSH("ByteArray::readDouble","flash/utils/ByteArray.hx",269);
	HX_STACK_THIS(this);
	HX_STACK_LINE(271)
	if ((((this->position + (int)8) > this->length))){
		HX_STACK_LINE(271)
		this->__throwEOFi();
	}
	HX_STACK_LINE(280)
	::haxe::io::Bytes bytes = ::haxe::io::Bytes_obj::__new((int)8,this->b->slice(this->position,(this->position + (int)8)));		HX_STACK_VAR(bytes,"bytes");
	HX_STACK_LINE(283)
	hx::AddEq(this->position,(int)8);
	HX_STACK_LINE(284)
	return ::flash::utils::ByteArray_obj::_double_of_bytes(bytes->b,this->bigEndian);
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,readDouble,return )

Void ByteArray_obj::readBytes( ::flash::utils::ByteArray data,hx::Null< int >  __o_offset,hx::Null< int >  __o_length){
int offset = __o_offset.Default(0);
int length = __o_length.Default(0);
	HX_STACK_PUSH("ByteArray::readBytes","flash/utils/ByteArray.hx",231);
	HX_STACK_THIS(this);
	HX_STACK_ARG(data,"data");
	HX_STACK_ARG(offset,"offset");
	HX_STACK_ARG(length,"length");
{
		HX_STACK_LINE(233)
		if (((length == (int)0))){
			HX_STACK_LINE(233)
			length = (this->length - this->position);
		}
		HX_STACK_LINE(239)
		if ((((this->position + length) > this->length))){
			HX_STACK_LINE(239)
			this->__throwEOFi();
		}
		HX_STACK_LINE(245)
		if (((data->length < (offset + length)))){
			HX_STACK_LINE(245)
			data->ensureElem(((offset + length) - (int)1),true);
		}
		HX_STACK_LINE(254)
		Array< unsigned char > b1 = this->b;		HX_STACK_VAR(b1,"b1");
		HX_STACK_LINE(255)
		Array< unsigned char > b2 = data->b;		HX_STACK_VAR(b2,"b2");
		HX_STACK_LINE(256)
		int p = this->position;		HX_STACK_VAR(p,"p");
		HX_STACK_LINE(257)
		{
			HX_STACK_LINE(257)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(257)
			while(((_g < length))){
				HX_STACK_LINE(257)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(259)
				b2[(offset + i)] = b1->__get((p + i));
			}
		}
		HX_STACK_LINE(264)
		hx::AddEq(this->position,length);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(ByteArray_obj,readBytes,(void))

int ByteArray_obj::readByte( ){
	HX_STACK_PUSH("ByteArray::readByte","flash/utils/ByteArray.hx",223);
	HX_STACK_THIS(this);
	HX_STACK_LINE(225)
	int value = (  (((this->position < this->length))) ? int(this->b->__get((this->position)++)) : int(this->__throwEOFi()) );		HX_STACK_VAR(value,"value");
	HX_STACK_LINE(226)
	return (  (((((int(value) & int((int)128))) != (int)0))) ? int((value - (int)256)) : int(value) );
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,readByte,return )

bool ByteArray_obj::readBoolean( ){
	HX_STACK_PUSH("ByteArray::readBoolean","flash/utils/ByteArray.hx",216);
	HX_STACK_THIS(this);
	HX_STACK_LINE(216)
	return (  (((this->position < this->length))) ? bool((this->b->__get((this->position)++) != (int)0)) : bool((this->__throwEOFi() != (int)0)) );
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,readBoolean,return )

Void ByteArray_obj::inflate( ){
{
		HX_STACK_PUSH("ByteArray::inflate","flash/utils/ByteArray.hx",209);
		HX_STACK_THIS(this);
		HX_STACK_LINE(209)
		this->uncompress(::flash::utils::CompressionAlgorithm_obj::DEFLATE);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,inflate,(void))

int ByteArray_obj::getStart( ){
	HX_STACK_PUSH("ByteArray::getStart","flash/utils/ByteArray.hx",202);
	HX_STACK_THIS(this);
	HX_STACK_LINE(202)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,getStart,return )

int ByteArray_obj::getLength( ){
	HX_STACK_PUSH("ByteArray::getLength","flash/utils/ByteArray.hx",195);
	HX_STACK_THIS(this);
	HX_STACK_LINE(195)
	return this->length;
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,getLength,return )

::flash::utils::ByteArray ByteArray_obj::getByteBuffer( ){
	HX_STACK_PUSH("ByteArray::getByteBuffer","flash/utils/ByteArray.hx",188);
	HX_STACK_THIS(this);
	HX_STACK_LINE(188)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,getByteBuffer,return )

Void ByteArray_obj::ensureElem( int size,bool updateLength){
{
		HX_STACK_PUSH("ByteArray::ensureElem","flash/utils/ByteArray.hx",150);
		HX_STACK_THIS(this);
		HX_STACK_ARG(size,"size");
		HX_STACK_ARG(updateLength,"updateLength");
		HX_STACK_LINE(151)
		int len = (size + (int)1);		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(163)
		if (((this->b->length < len))){
			HX_STACK_LINE(163)
			this->b->__SetSize(len);
		}
		HX_STACK_LINE(170)
		if (((bool(updateLength) && bool((this->length < len))))){
			HX_STACK_LINE(170)
			this->length = len;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(ByteArray_obj,ensureElem,(void))

Void ByteArray_obj::deflate( ){
{
		HX_STACK_PUSH("ByteArray::deflate","flash/utils/ByteArray.hx",143);
		HX_STACK_THIS(this);
		HX_STACK_LINE(143)
		this->compress(::flash::utils::CompressionAlgorithm_obj::DEFLATE);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,deflate,(void))

Void ByteArray_obj::compress( ::flash::utils::CompressionAlgorithm algorithm){
{
		HX_STACK_PUSH("ByteArray::compress","flash/utils/ByteArray.hx",95);
		HX_STACK_THIS(this);
		HX_STACK_ARG(algorithm,"algorithm");
		HX_STACK_LINE(100)
		::flash::utils::ByteArray src = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(src,"src");
		HX_STACK_LINE(103)
		if (((algorithm == null()))){
			HX_STACK_LINE(103)
			algorithm = ::flash::utils::CompressionAlgorithm_obj::ZLIB;
		}
		HX_STACK_LINE(109)
		::haxe::io::Bytes result;		HX_STACK_VAR(result,"result");
		HX_STACK_LINE(111)
		if (((algorithm == ::flash::utils::CompressionAlgorithm_obj::LZMA))){
			HX_STACK_LINE(111)
			result = ::haxe::io::Bytes_obj::ofData(::flash::utils::ByteArray_obj::nme_lzma_encode(src->b));
		}
		else{
			struct _Function_2_1{
				inline static int Block( ::flash::utils::CompressionAlgorithm &algorithm){
					HX_STACK_PUSH("*::closure","flash/utils/ByteArray.hx",117);
					{
						HX_STACK_LINE(117)
						{
							::flash::utils::CompressionAlgorithm _switch_2 = (algorithm);
							switch((_switch_2)->GetIndex()){
								case 0: {
									HX_STACK_LINE(119)
									return (int)-15;
								}
								;break;
								case 3: {
									HX_STACK_LINE(120)
									return (int)31;
								}
								;break;
								default: {
									HX_STACK_LINE(121)
									return (int)15;
								}
							}
						}
					}
					return null();
				}
			};
			HX_STACK_LINE(117)
			int windowBits = _Function_2_1::Block(algorithm);		HX_STACK_VAR(windowBits,"windowBits");
			HX_STACK_LINE(128)
			result = ::cpp::zip::Compress_obj::run(src,(int)8);
		}
		HX_STACK_LINE(133)
		this->b = result->b;
		HX_STACK_LINE(134)
		this->length = result->length;
		HX_STACK_LINE(135)
		this->position = this->length;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,compress,(void))

Void ByteArray_obj::clear( ){
{
		HX_STACK_PUSH("ByteArray::clear","flash/utils/ByteArray.hx",87);
		HX_STACK_THIS(this);
		HX_STACK_LINE(89)
		this->position = (int)0;
		HX_STACK_LINE(90)
		this->length = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,clear,(void))

Void ByteArray_obj::checkData( int length){
{
		HX_STACK_PUSH("ByteArray::checkData","flash/utils/ByteArray.hx",76);
		HX_STACK_THIS(this);
		HX_STACK_ARG(length,"length");
		HX_STACK_LINE(76)
		if ((((length + this->position) > this->length))){
			HX_STACK_LINE(78)
			this->__throwEOFi();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,checkData,(void))

::String ByteArray_obj::asString( ){
	HX_STACK_PUSH("ByteArray::asString","flash/utils/ByteArray.hx",69);
	HX_STACK_THIS(this);
	HX_STACK_LINE(69)
	return this->readUTFBytes(this->length);
}


HX_DEFINE_DYNAMIC_FUNC0(ByteArray_obj,asString,return )

::flash::utils::ByteArray ByteArray_obj::fromBytes( ::haxe::io::Bytes bytes){
	HX_STACK_PUSH("ByteArray::fromBytes","flash/utils/ByteArray.hx",179);
	HX_STACK_ARG(bytes,"bytes");
	HX_STACK_LINE(181)
	::flash::utils::ByteArray result = ::flash::utils::ByteArray_obj::__new((int)-1);		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(182)
	{
		HX_STACK_LINE(182)
		result->b = bytes->b;
		HX_STACK_LINE(182)
		result->length = bytes->length;
	}
	HX_STACK_LINE(183)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,fromBytes,return )

::flash::utils::ByteArray ByteArray_obj::readFile( ::String path){
	HX_STACK_PUSH("ByteArray::readFile","flash/utils/ByteArray.hx",291);
	HX_STACK_ARG(path,"path");
	HX_STACK_LINE(291)
	return ::flash::utils::ByteArray_obj::nme_byte_array_read_file(path);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(ByteArray_obj,readFile,return )

Dynamic ByteArray_obj::_double_bytes;

Dynamic ByteArray_obj::_double_of_bytes;

Dynamic ByteArray_obj::_float_bytes;

Dynamic ByteArray_obj::_float_of_bytes;

Dynamic ByteArray_obj::nme_byte_array_overwrite_file;

Dynamic ByteArray_obj::nme_byte_array_read_file;

Dynamic ByteArray_obj::nme_lzma_encode;

Dynamic ByteArray_obj::nme_lzma_decode;


ByteArray_obj::ByteArray_obj()
{
}

void ByteArray_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ByteArray);
	HX_MARK_MEMBER_NAME(byteLength,"byteLength");
	HX_MARK_MEMBER_NAME(position,"position");
	HX_MARK_MEMBER_NAME(bytesAvailable,"bytesAvailable");
	HX_MARK_MEMBER_NAME(bigEndian,"bigEndian");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void ByteArray_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(byteLength,"byteLength");
	HX_VISIT_MEMBER_NAME(position,"position");
	HX_VISIT_MEMBER_NAME(bytesAvailable,"bytesAvailable");
	HX_VISIT_MEMBER_NAME(bigEndian,"bigEndian");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic ByteArray_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"__set") ) { return __set_dyn(); }
		if (HX_FIELD_EQ(inName,"__get") ) { return __get_dyn(); }
		if (HX_FIELD_EQ(inName,"slice") ) { return slice_dyn(); }
		if (HX_FIELD_EQ(inName,"clear") ) { return clear_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"endian") ) { return get_endian(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"readUTF") ) { return readUTF_dyn(); }
		if (HX_FIELD_EQ(inName,"readInt") ) { return readInt_dyn(); }
		if (HX_FIELD_EQ(inName,"inflate") ) { return inflate_dyn(); }
		if (HX_FIELD_EQ(inName,"deflate") ) { return deflate_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"readFile") ) { return readFile_dyn(); }
		if (HX_FIELD_EQ(inName,"writeUTF") ) { return writeUTF_dyn(); }
		if (HX_FIELD_EQ(inName,"writeInt") ) { return writeInt_dyn(); }
		if (HX_FIELD_EQ(inName,"readByte") ) { return readByte_dyn(); }
		if (HX_FIELD_EQ(inName,"getStart") ) { return getStart_dyn(); }
		if (HX_FIELD_EQ(inName,"compress") ) { return compress_dyn(); }
		if (HX_FIELD_EQ(inName,"asString") ) { return asString_dyn(); }
		if (HX_FIELD_EQ(inName,"position") ) { return position; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"fromBytes") ) { return fromBytes_dyn(); }
		if (HX_FIELD_EQ(inName,"writeFile") ) { return writeFile_dyn(); }
		if (HX_FIELD_EQ(inName,"writeByte") ) { return writeByte_dyn(); }
		if (HX_FIELD_EQ(inName,"setLength") ) { return setLength_dyn(); }
		if (HX_FIELD_EQ(inName,"readShort") ) { return readShort_dyn(); }
		if (HX_FIELD_EQ(inName,"readFloat") ) { return readFloat_dyn(); }
		if (HX_FIELD_EQ(inName,"readBytes") ) { return readBytes_dyn(); }
		if (HX_FIELD_EQ(inName,"getLength") ) { return getLength_dyn(); }
		if (HX_FIELD_EQ(inName,"checkData") ) { return checkData_dyn(); }
		if (HX_FIELD_EQ(inName,"bigEndian") ) { return bigEndian; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"set_endian") ) { return set_endian_dyn(); }
		if (HX_FIELD_EQ(inName,"get_endian") ) { return get_endian_dyn(); }
		if (HX_FIELD_EQ(inName,"writeShort") ) { return writeShort_dyn(); }
		if (HX_FIELD_EQ(inName,"writeFloat") ) { return writeFloat_dyn(); }
		if (HX_FIELD_EQ(inName,"writeBytes") ) { return writeBytes_dyn(); }
		if (HX_FIELD_EQ(inName,"uncompress") ) { return uncompress_dyn(); }
		if (HX_FIELD_EQ(inName,"readDouble") ) { return readDouble_dyn(); }
		if (HX_FIELD_EQ(inName,"ensureElem") ) { return ensureElem_dyn(); }
		if (HX_FIELD_EQ(inName,"byteLength") ) { return inCallProp ? get_byteLength() : byteLength; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"__throwEOFi") ) { return __throwEOFi_dyn(); }
		if (HX_FIELD_EQ(inName,"__fromBytes") ) { return __fromBytes_dyn(); }
		if (HX_FIELD_EQ(inName,"writeDouble") ) { return writeDouble_dyn(); }
		if (HX_FIELD_EQ(inName,"readBoolean") ) { return readBoolean_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_float_bytes") ) { return _float_bytes; }
		if (HX_FIELD_EQ(inName,"writeBoolean") ) { return writeBoolean_dyn(); }
		if (HX_FIELD_EQ(inName,"readUTFBytes") ) { return readUTFBytes_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_double_bytes") ) { return _double_bytes; }
		if (HX_FIELD_EQ(inName,"writeUTFBytes") ) { return writeUTFBytes_dyn(); }
		if (HX_FIELD_EQ(inName,"write_uncheck") ) { return write_uncheck_dyn(); }
		if (HX_FIELD_EQ(inName,"readMultiByte") ) { return readMultiByte_dyn(); }
		if (HX_FIELD_EQ(inName,"getByteBuffer") ) { return getByteBuffer_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_byteLength") ) { return get_byteLength_dyn(); }
		if (HX_FIELD_EQ(inName,"bytesAvailable") ) { return inCallProp ? get_bytesAvailable() : bytesAvailable; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_float_of_bytes") ) { return _float_of_bytes; }
		if (HX_FIELD_EQ(inName,"nme_lzma_encode") ) { return nme_lzma_encode; }
		if (HX_FIELD_EQ(inName,"nme_lzma_decode") ) { return nme_lzma_decode; }
		if (HX_FIELD_EQ(inName,"readUnsignedInt") ) { return readUnsignedInt_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_double_of_bytes") ) { return _double_of_bytes; }
		if (HX_FIELD_EQ(inName,"writeUnsignedInt") ) { return writeUnsignedInt_dyn(); }
		if (HX_FIELD_EQ(inName,"readUnsignedByte") ) { return readUnsignedByte_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"readUnsignedShort") ) { return readUnsignedShort_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"get_bytesAvailable") ) { return get_bytesAvailable_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"nme_byte_array_read_file") ) { return nme_byte_array_read_file; }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"nme_byte_array_overwrite_file") ) { return nme_byte_array_overwrite_file; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ByteArray_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"endian") ) { return set_endian(inValue); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"position") ) { position=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"bigEndian") ) { bigEndian=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"byteLength") ) { byteLength=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_float_bytes") ) { _float_bytes=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_double_bytes") ) { _double_bytes=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"bytesAvailable") ) { bytesAvailable=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"_float_of_bytes") ) { _float_of_bytes=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_lzma_encode") ) { nme_lzma_encode=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nme_lzma_decode") ) { nme_lzma_decode=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"_double_of_bytes") ) { _double_of_bytes=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"nme_byte_array_read_file") ) { nme_byte_array_read_file=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"nme_byte_array_overwrite_file") ) { nme_byte_array_overwrite_file=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ByteArray_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("byteLength"));
	outFields->push(HX_CSTRING("position"));
	outFields->push(HX_CSTRING("endian"));
	outFields->push(HX_CSTRING("bytesAvailable"));
	outFields->push(HX_CSTRING("bigEndian"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("fromBytes"),
	HX_CSTRING("readFile"),
	HX_CSTRING("_double_bytes"),
	HX_CSTRING("_double_of_bytes"),
	HX_CSTRING("_float_bytes"),
	HX_CSTRING("_float_of_bytes"),
	HX_CSTRING("nme_byte_array_overwrite_file"),
	HX_CSTRING("nme_byte_array_read_file"),
	HX_CSTRING("nme_lzma_encode"),
	HX_CSTRING("nme_lzma_decode"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("set_endian"),
	HX_CSTRING("get_endian"),
	HX_CSTRING("get_byteLength"),
	HX_CSTRING("get_bytesAvailable"),
	HX_CSTRING("__throwEOFi"),
	HX_CSTRING("__set"),
	HX_CSTRING("__get"),
	HX_CSTRING("__fromBytes"),
	HX_CSTRING("writeUTFBytes"),
	HX_CSTRING("writeUTF"),
	HX_CSTRING("writeUnsignedInt"),
	HX_CSTRING("writeShort"),
	HX_CSTRING("writeInt"),
	HX_CSTRING("writeFloat"),
	HX_CSTRING("writeFile"),
	HX_CSTRING("writeDouble"),
	HX_CSTRING("writeBytes"),
	HX_CSTRING("writeByte"),
	HX_CSTRING("writeBoolean"),
	HX_CSTRING("write_uncheck"),
	HX_CSTRING("uncompress"),
	HX_CSTRING("slice"),
	HX_CSTRING("setLength"),
	HX_CSTRING("readUTFBytes"),
	HX_CSTRING("readUTF"),
	HX_CSTRING("readUnsignedShort"),
	HX_CSTRING("readUnsignedInt"),
	HX_CSTRING("readUnsignedByte"),
	HX_CSTRING("readShort"),
	HX_CSTRING("readMultiByte"),
	HX_CSTRING("readInt"),
	HX_CSTRING("readFloat"),
	HX_CSTRING("readDouble"),
	HX_CSTRING("readBytes"),
	HX_CSTRING("readByte"),
	HX_CSTRING("readBoolean"),
	HX_CSTRING("inflate"),
	HX_CSTRING("getStart"),
	HX_CSTRING("getLength"),
	HX_CSTRING("getByteBuffer"),
	HX_CSTRING("ensureElem"),
	HX_CSTRING("deflate"),
	HX_CSTRING("compress"),
	HX_CSTRING("clear"),
	HX_CSTRING("checkData"),
	HX_CSTRING("asString"),
	HX_CSTRING("byteLength"),
	HX_CSTRING("position"),
	HX_CSTRING("bytesAvailable"),
	HX_CSTRING("bigEndian"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ByteArray_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(ByteArray_obj::_double_bytes,"_double_bytes");
	HX_MARK_MEMBER_NAME(ByteArray_obj::_double_of_bytes,"_double_of_bytes");
	HX_MARK_MEMBER_NAME(ByteArray_obj::_float_bytes,"_float_bytes");
	HX_MARK_MEMBER_NAME(ByteArray_obj::_float_of_bytes,"_float_of_bytes");
	HX_MARK_MEMBER_NAME(ByteArray_obj::nme_byte_array_overwrite_file,"nme_byte_array_overwrite_file");
	HX_MARK_MEMBER_NAME(ByteArray_obj::nme_byte_array_read_file,"nme_byte_array_read_file");
	HX_MARK_MEMBER_NAME(ByteArray_obj::nme_lzma_encode,"nme_lzma_encode");
	HX_MARK_MEMBER_NAME(ByteArray_obj::nme_lzma_decode,"nme_lzma_decode");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ByteArray_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(ByteArray_obj::_double_bytes,"_double_bytes");
	HX_VISIT_MEMBER_NAME(ByteArray_obj::_double_of_bytes,"_double_of_bytes");
	HX_VISIT_MEMBER_NAME(ByteArray_obj::_float_bytes,"_float_bytes");
	HX_VISIT_MEMBER_NAME(ByteArray_obj::_float_of_bytes,"_float_of_bytes");
	HX_VISIT_MEMBER_NAME(ByteArray_obj::nme_byte_array_overwrite_file,"nme_byte_array_overwrite_file");
	HX_VISIT_MEMBER_NAME(ByteArray_obj::nme_byte_array_read_file,"nme_byte_array_read_file");
	HX_VISIT_MEMBER_NAME(ByteArray_obj::nme_lzma_encode,"nme_lzma_encode");
	HX_VISIT_MEMBER_NAME(ByteArray_obj::nme_lzma_decode,"nme_lzma_decode");
};

Class ByteArray_obj::__mClass;

void ByteArray_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flash.utils.ByteArray"), hx::TCanCast< ByteArray_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void ByteArray_obj::__boot()
{
	_double_bytes= ::flash::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("double_bytes"),(int)2);
	_double_of_bytes= ::flash::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("double_of_bytes"),(int)2);
	_float_bytes= ::flash::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("float_bytes"),(int)2);
	_float_of_bytes= ::flash::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("float_of_bytes"),(int)2);
	nme_byte_array_overwrite_file= ::flash::Lib_obj::load(HX_CSTRING("nme"),HX_CSTRING("nme_byte_array_overwrite_file"),(int)2);
	nme_byte_array_read_file= ::flash::Lib_obj::load(HX_CSTRING("nme"),HX_CSTRING("nme_byte_array_read_file"),(int)1);
	nme_lzma_encode= ::flash::Lib_obj::load(HX_CSTRING("nme"),HX_CSTRING("nme_lzma_encode"),(int)1);
	nme_lzma_decode= ::flash::Lib_obj::load(HX_CSTRING("nme"),HX_CSTRING("nme_lzma_decode"),(int)1);
}

} // end namespace flash
} // end namespace utils
