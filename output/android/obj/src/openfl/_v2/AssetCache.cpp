#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_openfl__v2_AssetCache
#include <openfl/_v2/AssetCache.h>
#endif
namespace openfl{
namespace _v2{

Void AssetCache_obj::__construct()
{
HX_STACK_FRAME("openfl._v2.AssetCache","new",0x0b04b855,"openfl._v2.AssetCache.new","openfl/_v2/Assets.hx",1373,0x2846aac8)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(1377)
	this->enabled = true;
	HX_STACK_LINE(1384)
	::haxe::ds::StringMap _g = ::haxe::ds::StringMap_obj::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(1384)
	this->bitmapData = _g;
	HX_STACK_LINE(1385)
	::haxe::ds::StringMap _g1 = ::haxe::ds::StringMap_obj::__new();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(1385)
	this->font = _g1;
	HX_STACK_LINE(1386)
	::haxe::ds::StringMap _g2 = ::haxe::ds::StringMap_obj::__new();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(1386)
	this->sound = _g2;
}
;
	return null();
}

//AssetCache_obj::~AssetCache_obj() { }

Dynamic AssetCache_obj::__CreateEmpty() { return  new AssetCache_obj; }
hx::ObjectPtr< AssetCache_obj > AssetCache_obj::__new()
{  hx::ObjectPtr< AssetCache_obj > result = new AssetCache_obj();
	result->__construct();
	return result;}

Dynamic AssetCache_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AssetCache_obj > result = new AssetCache_obj();
	result->__construct();
	return result;}

Void AssetCache_obj::clear( ::String prefix){
{
		HX_STACK_FRAME("openfl._v2.AssetCache","clear",0x0f0e00c2,"openfl._v2.AssetCache.clear","openfl/_v2/Assets.hx",1393,0x2846aac8)
		HX_STACK_THIS(this)
		HX_STACK_ARG(prefix,"prefix")
		HX_STACK_LINE(1393)
		if (((prefix == null()))){
			HX_STACK_LINE(1395)
			::haxe::ds::StringMap _g = ::haxe::ds::StringMap_obj::__new();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(1395)
			this->bitmapData = _g;
			HX_STACK_LINE(1396)
			::haxe::ds::StringMap _g1 = ::haxe::ds::StringMap_obj::__new();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(1396)
			this->font = _g1;
			HX_STACK_LINE(1397)
			::haxe::ds::StringMap _g2 = ::haxe::ds::StringMap_obj::__new();		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(1397)
			this->sound = _g2;
		}
		else{
			HX_STACK_LINE(1401)
			Dynamic keys = this->bitmapData->keys();		HX_STACK_VAR(keys,"keys");
			HX_STACK_LINE(1403)
			for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(keys);  __it->hasNext(); ){
				::String key = __it->next();
				if ((::StringTools_obj::startsWith(key,prefix))){
					HX_STACK_LINE(1407)
					this->bitmapData->remove(key);
				}
;
			}
			HX_STACK_LINE(1413)
			Dynamic keys1 = this->font->keys();		HX_STACK_VAR(keys1,"keys1");
			HX_STACK_LINE(1415)
			for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(keys1);  __it->hasNext(); ){
				::String key = __it->next();
				if ((::StringTools_obj::startsWith(key,prefix))){
					HX_STACK_LINE(1419)
					this->font->remove(key);
				}
;
			}
			HX_STACK_LINE(1425)
			Dynamic keys2 = this->sound->keys();		HX_STACK_VAR(keys2,"keys2");
			HX_STACK_LINE(1427)
			for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(keys2);  __it->hasNext(); ){
				::String key = __it->next();
				if ((::StringTools_obj::startsWith(key,prefix))){
					HX_STACK_LINE(1431)
					this->sound->remove(key);
				}
;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AssetCache_obj,clear,(void))


AssetCache_obj::AssetCache_obj()
{
}

void AssetCache_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AssetCache);
	HX_MARK_MEMBER_NAME(bitmapData,"bitmapData");
	HX_MARK_MEMBER_NAME(enabled,"enabled");
	HX_MARK_MEMBER_NAME(font,"font");
	HX_MARK_MEMBER_NAME(sound,"sound");
	HX_MARK_END_CLASS();
}

void AssetCache_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(bitmapData,"bitmapData");
	HX_VISIT_MEMBER_NAME(enabled,"enabled");
	HX_VISIT_MEMBER_NAME(font,"font");
	HX_VISIT_MEMBER_NAME(sound,"sound");
}

Dynamic AssetCache_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"font") ) { return font; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"sound") ) { return sound; }
		if (HX_FIELD_EQ(inName,"clear") ) { return clear_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"enabled") ) { return enabled; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"bitmapData") ) { return bitmapData; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic AssetCache_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"font") ) { font=inValue.Cast< ::haxe::ds::StringMap >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"sound") ) { sound=inValue.Cast< ::haxe::ds::StringMap >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"enabled") ) { enabled=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"bitmapData") ) { bitmapData=inValue.Cast< ::haxe::ds::StringMap >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void AssetCache_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("bitmapData"));
	outFields->push(HX_CSTRING("enabled"));
	outFields->push(HX_CSTRING("font"));
	outFields->push(HX_CSTRING("sound"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxe::ds::StringMap*/ ,(int)offsetof(AssetCache_obj,bitmapData),HX_CSTRING("bitmapData")},
	{hx::fsBool,(int)offsetof(AssetCache_obj,enabled),HX_CSTRING("enabled")},
	{hx::fsObject /*::haxe::ds::StringMap*/ ,(int)offsetof(AssetCache_obj,font),HX_CSTRING("font")},
	{hx::fsObject /*::haxe::ds::StringMap*/ ,(int)offsetof(AssetCache_obj,sound),HX_CSTRING("sound")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("bitmapData"),
	HX_CSTRING("enabled"),
	HX_CSTRING("font"),
	HX_CSTRING("sound"),
	HX_CSTRING("clear"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AssetCache_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(AssetCache_obj::__mClass,"__mClass");
};

#endif

Class AssetCache_obj::__mClass;

void AssetCache_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("openfl._v2.AssetCache"), hx::TCanCast< AssetCache_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , sMemberStorageInfo
#endif
);
}

void AssetCache_obj::__boot()
{
}

} // end namespace openfl
} // end namespace _v2
