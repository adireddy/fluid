#include <hxcpp.h>

#ifndef INCLUDED_Reflect
#include <Reflect.h>
#endif
#ifndef INCLUDED_msignal_SlotList
#include <msignal/SlotList.h>
#endif
namespace msignal{

Void SlotList_obj::__construct(Dynamic head,::msignal::SlotList tail)
{
HX_STACK_FRAME("msignal.SlotList","new",0x5eabee07,"msignal.SlotList.new","msignal/SlotList.hx",51,0xabc95ce8)
HX_STACK_THIS(this)
HX_STACK_ARG(head,"head")
HX_STACK_ARG(tail,"tail")
{
	HX_STACK_LINE(52)
	this->nonEmpty = false;
	HX_STACK_LINE(54)
	if (((bool((head == null())) && bool((tail == null()))))){
		HX_STACK_LINE(56)
		if (((::msignal::SlotList_obj::NIL != null()))){
			HX_STACK_LINE(58)
			HX_STACK_DO_THROW(HX_CSTRING("Parameters head and tail are null. Use the NIL element instead."));
		}
		HX_STACK_LINE(62)
		this->nonEmpty = false;
	}
	else{
		HX_STACK_LINE(64)
		if (((head == null()))){
			HX_STACK_LINE(66)
			HX_STACK_DO_THROW(HX_CSTRING("Parameter head cannot be null."));
		}
		else{
			HX_STACK_LINE(70)
			this->head = head;
			HX_STACK_LINE(71)
			if (((tail == null()))){
				HX_STACK_LINE(71)
				this->tail = ::msignal::SlotList_obj::NIL;
			}
			else{
				HX_STACK_LINE(71)
				this->tail = tail;
			}
			HX_STACK_LINE(72)
			this->nonEmpty = true;
		}
	}
}
;
	return null();
}

//SlotList_obj::~SlotList_obj() { }

Dynamic SlotList_obj::__CreateEmpty() { return  new SlotList_obj; }
hx::ObjectPtr< SlotList_obj > SlotList_obj::__new(Dynamic head,::msignal::SlotList tail)
{  hx::ObjectPtr< SlotList_obj > result = new SlotList_obj();
	result->__construct(head,tail);
	return result;}

Dynamic SlotList_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SlotList_obj > result = new SlotList_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

void SlotList_obj::__init__() {
HX_STACK_FRAME("msignal.SlotList","__init__",0x0133e249,"msignal.SlotList.__init__","msignal/SlotList.hx",28,0xabc95ce8)
{
	HX_STACK_LINE(28)
	::msignal::SlotList _g = ::msignal::SlotList_obj::__new(null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(28)
	::msignal::SlotList_obj::NIL = _g;
}
}

int SlotList_obj::get_length( ){
	HX_STACK_FRAME("msignal.SlotList","get_length",0x330cf9e8,"msignal.SlotList.get_length","msignal/SlotList.hx",81,0xabc95ce8)
	HX_STACK_THIS(this)
	HX_STACK_LINE(82)
	if ((!(this->nonEmpty))){
		HX_STACK_LINE(82)
		return (int)0;
	}
	HX_STACK_LINE(83)
	if (((this->tail == ::msignal::SlotList_obj::NIL))){
		HX_STACK_LINE(83)
		return (int)1;
	}
	HX_STACK_LINE(89)
	int result = (int)0;		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(90)
	::msignal::SlotList p = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(p,"p");
	HX_STACK_LINE(92)
	while((true)){
		HX_STACK_LINE(92)
		if ((!(p->nonEmpty))){
			HX_STACK_LINE(92)
			break;
		}
		HX_STACK_LINE(94)
		++(result);
		HX_STACK_LINE(95)
		p = p->tail;
	}
	HX_STACK_LINE(98)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC0(SlotList_obj,get_length,return )

::msignal::SlotList SlotList_obj::prepend( Dynamic slot){
	HX_STACK_FRAME("msignal.SlotList","prepend",0x68f61435,"msignal.SlotList.prepend","msignal/SlotList.hx",108,0xabc95ce8)
	HX_STACK_THIS(this)
	HX_STACK_ARG(slot,"slot")
	HX_STACK_LINE(108)
	return ::msignal::SlotList_obj::__new(slot,hx::ObjectPtr<OBJ_>(this));
}


HX_DEFINE_DYNAMIC_FUNC1(SlotList_obj,prepend,return )

::msignal::SlotList SlotList_obj::append( Dynamic slot){
	HX_STACK_FRAME("msignal.SlotList","append",0x520e8693,"msignal.SlotList.append","msignal/SlotList.hx",120,0xabc95ce8)
	HX_STACK_THIS(this)
	HX_STACK_ARG(slot,"slot")
	HX_STACK_LINE(121)
	if (((slot == null()))){
		HX_STACK_LINE(121)
		return hx::ObjectPtr<OBJ_>(this);
	}
	HX_STACK_LINE(122)
	if ((!(this->nonEmpty))){
		HX_STACK_LINE(122)
		return ::msignal::SlotList_obj::__new(slot,null());
	}
	HX_STACK_LINE(125)
	if (((this->tail == ::msignal::SlotList_obj::NIL))){
		HX_STACK_LINE(127)
		return ::msignal::SlotList_obj::__new(slot,null())->prepend(this->head);
	}
	HX_STACK_LINE(132)
	::msignal::SlotList wholeClone = ::msignal::SlotList_obj::__new(this->head,null());		HX_STACK_VAR(wholeClone,"wholeClone");
	HX_STACK_LINE(133)
	::msignal::SlotList subClone = wholeClone;		HX_STACK_VAR(subClone,"subClone");
	HX_STACK_LINE(134)
	::msignal::SlotList current = this->tail;		HX_STACK_VAR(current,"current");
	HX_STACK_LINE(136)
	while((true)){
		HX_STACK_LINE(136)
		if ((!(current->nonEmpty))){
			HX_STACK_LINE(136)
			break;
		}
		HX_STACK_LINE(138)
		::msignal::SlotList _g = ::msignal::SlotList_obj::__new(current->head,null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(138)
		::msignal::SlotList _g1 = subClone->tail = _g;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(138)
		subClone = _g1;
		HX_STACK_LINE(139)
		current = current->tail;
	}
	HX_STACK_LINE(143)
	::msignal::SlotList _g2 = ::msignal::SlotList_obj::__new(slot,null());		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(143)
	subClone->tail = _g2;
	HX_STACK_LINE(144)
	return wholeClone;
}


HX_DEFINE_DYNAMIC_FUNC1(SlotList_obj,append,return )

::msignal::SlotList SlotList_obj::insertWithPriority( Dynamic slot){
	HX_STACK_FRAME("msignal.SlotList","insertWithPriority",0xe3d67a9c,"msignal.SlotList.insertWithPriority","msignal/SlotList.hx",154,0xabc95ce8)
	HX_STACK_THIS(this)
	HX_STACK_ARG(slot,"slot")
	HX_STACK_LINE(155)
	if ((!(this->nonEmpty))){
		HX_STACK_LINE(155)
		return ::msignal::SlotList_obj::__new(slot,null());
	}
	HX_STACK_LINE(157)
	int priority = slot->__Field(HX_CSTRING("priority"),true);		HX_STACK_VAR(priority,"priority");
	HX_STACK_LINE(160)
	if (((priority >= this->head->__Field(HX_CSTRING("priority"),true)))){
		HX_STACK_LINE(160)
		return this->prepend(slot);
	}
	HX_STACK_LINE(162)
	::msignal::SlotList wholeClone = ::msignal::SlotList_obj::__new(this->head,null());		HX_STACK_VAR(wholeClone,"wholeClone");
	HX_STACK_LINE(163)
	::msignal::SlotList subClone = wholeClone;		HX_STACK_VAR(subClone,"subClone");
	HX_STACK_LINE(164)
	::msignal::SlotList current = this->tail;		HX_STACK_VAR(current,"current");
	HX_STACK_LINE(167)
	while((true)){
		HX_STACK_LINE(167)
		if ((!(current->nonEmpty))){
			HX_STACK_LINE(167)
			break;
		}
		HX_STACK_LINE(169)
		if (((priority > current->head->__Field(HX_CSTRING("priority"),true)))){
			HX_STACK_LINE(171)
			::msignal::SlotList _g = current->prepend(slot);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(171)
			subClone->tail = _g;
			HX_STACK_LINE(172)
			return wholeClone;
		}
		HX_STACK_LINE(175)
		::msignal::SlotList _g1 = ::msignal::SlotList_obj::__new(current->head,null());		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(175)
		::msignal::SlotList _g2 = subClone->tail = _g1;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(175)
		subClone = _g2;
		HX_STACK_LINE(176)
		current = current->tail;
	}
	HX_STACK_LINE(180)
	::msignal::SlotList _g3 = ::msignal::SlotList_obj::__new(slot,null());		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(180)
	subClone->tail = _g3;
	HX_STACK_LINE(181)
	return wholeClone;
}


HX_DEFINE_DYNAMIC_FUNC1(SlotList_obj,insertWithPriority,return )

::msignal::SlotList SlotList_obj::filterNot( Dynamic listener){
	HX_STACK_FRAME("msignal.SlotList","filterNot",0xa0af6922,"msignal.SlotList.filterNot","msignal/SlotList.hx",192,0xabc95ce8)
	HX_STACK_THIS(this)
	HX_STACK_ARG(listener,"listener")
	HX_STACK_LINE(193)
	if (((bool(!(this->nonEmpty)) || bool((listener == null()))))){
		HX_STACK_LINE(193)
		return hx::ObjectPtr<OBJ_>(this);
	}
	HX_STACK_LINE(195)
	Dynamic _g = this->head->__Field(HX_CSTRING("get_listener"),true)();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(195)
	if ((::Reflect_obj::compareMethods(_g,listener))){
		HX_STACK_LINE(195)
		return this->tail;
	}
	HX_STACK_LINE(198)
	::msignal::SlotList wholeClone = ::msignal::SlotList_obj::__new(this->head,null());		HX_STACK_VAR(wholeClone,"wholeClone");
	HX_STACK_LINE(199)
	::msignal::SlotList subClone = wholeClone;		HX_STACK_VAR(subClone,"subClone");
	HX_STACK_LINE(200)
	::msignal::SlotList current = this->tail;		HX_STACK_VAR(current,"current");
	HX_STACK_LINE(202)
	while((true)){
		HX_STACK_LINE(202)
		if ((!(current->nonEmpty))){
			HX_STACK_LINE(202)
			break;
		}
		HX_STACK_LINE(204)
		Dynamic _g1 = current->head->__Field(HX_CSTRING("get_listener"),true)();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(204)
		if ((::Reflect_obj::compareMethods(_g1,listener))){
			HX_STACK_LINE(207)
			subClone->tail = current->tail;
			HX_STACK_LINE(208)
			return wholeClone;
		}
		HX_STACK_LINE(211)
		::msignal::SlotList _g2 = ::msignal::SlotList_obj::__new(current->head,null());		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(211)
		::msignal::SlotList _g3 = subClone->tail = _g2;		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(211)
		subClone = _g3;
		HX_STACK_LINE(212)
		current = current->tail;
	}
	HX_STACK_LINE(216)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(SlotList_obj,filterNot,return )

bool SlotList_obj::contains( Dynamic listener){
	HX_STACK_FRAME("msignal.SlotList","contains",0xee335f18,"msignal.SlotList.contains","msignal/SlotList.hx",224,0xabc95ce8)
	HX_STACK_THIS(this)
	HX_STACK_ARG(listener,"listener")
	HX_STACK_LINE(225)
	if ((!(this->nonEmpty))){
		HX_STACK_LINE(225)
		return false;
	}
	HX_STACK_LINE(227)
	::msignal::SlotList p = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(p,"p");
	HX_STACK_LINE(228)
	while((true)){
		HX_STACK_LINE(228)
		if ((!(p->nonEmpty))){
			HX_STACK_LINE(228)
			break;
		}
		HX_STACK_LINE(230)
		Dynamic _g = p->head->__Field(HX_CSTRING("get_listener"),true)();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(230)
		if ((::Reflect_obj::compareMethods(_g,listener))){
			HX_STACK_LINE(230)
			return true;
		}
		HX_STACK_LINE(231)
		p = p->tail;
	}
	HX_STACK_LINE(234)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(SlotList_obj,contains,return )

Dynamic SlotList_obj::find( Dynamic listener){
	HX_STACK_FRAME("msignal.SlotList","find",0x727da4b2,"msignal.SlotList.find","msignal/SlotList.hx",245,0xabc95ce8)
	HX_STACK_THIS(this)
	HX_STACK_ARG(listener,"listener")
	HX_STACK_LINE(246)
	if ((!(this->nonEmpty))){
		HX_STACK_LINE(246)
		return null();
	}
	HX_STACK_LINE(248)
	::msignal::SlotList p = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(p,"p");
	HX_STACK_LINE(249)
	while((true)){
		HX_STACK_LINE(249)
		if ((!(p->nonEmpty))){
			HX_STACK_LINE(249)
			break;
		}
		HX_STACK_LINE(251)
		Dynamic _g = p->head->__Field(HX_CSTRING("get_listener"),true)();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(251)
		if ((::Reflect_obj::compareMethods(_g,listener))){
			HX_STACK_LINE(251)
			return p->head;
		}
		HX_STACK_LINE(252)
		p = p->tail;
	}
	HX_STACK_LINE(255)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SlotList_obj,find,return )

::msignal::SlotList SlotList_obj::NIL;


SlotList_obj::SlotList_obj()
{
}

void SlotList_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SlotList);
	HX_MARK_MEMBER_NAME(head,"head");
	HX_MARK_MEMBER_NAME(tail,"tail");
	HX_MARK_MEMBER_NAME(nonEmpty,"nonEmpty");
	HX_MARK_MEMBER_NAME(length,"length");
	HX_MARK_END_CLASS();
}

void SlotList_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(head,"head");
	HX_VISIT_MEMBER_NAME(tail,"tail");
	HX_VISIT_MEMBER_NAME(nonEmpty,"nonEmpty");
	HX_VISIT_MEMBER_NAME(length,"length");
}

Dynamic SlotList_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"NIL") ) { return NIL; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"head") ) { return head; }
		if (HX_FIELD_EQ(inName,"tail") ) { return tail; }
		if (HX_FIELD_EQ(inName,"find") ) { return find_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { return inCallProp ? get_length() : length; }
		if (HX_FIELD_EQ(inName,"append") ) { return append_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"prepend") ) { return prepend_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"nonEmpty") ) { return nonEmpty; }
		if (HX_FIELD_EQ(inName,"contains") ) { return contains_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"filterNot") ) { return filterNot_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_length") ) { return get_length_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"insertWithPriority") ) { return insertWithPriority_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic SlotList_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"NIL") ) { NIL=inValue.Cast< ::msignal::SlotList >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"head") ) { head=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"tail") ) { tail=inValue.Cast< ::msignal::SlotList >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { length=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"nonEmpty") ) { nonEmpty=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SlotList_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("head"));
	outFields->push(HX_CSTRING("tail"));
	outFields->push(HX_CSTRING("nonEmpty"));
	outFields->push(HX_CSTRING("length"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("NIL"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(SlotList_obj,head),HX_CSTRING("head")},
	{hx::fsObject /*::msignal::SlotList*/ ,(int)offsetof(SlotList_obj,tail),HX_CSTRING("tail")},
	{hx::fsBool,(int)offsetof(SlotList_obj,nonEmpty),HX_CSTRING("nonEmpty")},
	{hx::fsInt,(int)offsetof(SlotList_obj,length),HX_CSTRING("length")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("head"),
	HX_CSTRING("tail"),
	HX_CSTRING("nonEmpty"),
	HX_CSTRING("length"),
	HX_CSTRING("get_length"),
	HX_CSTRING("prepend"),
	HX_CSTRING("append"),
	HX_CSTRING("insertWithPriority"),
	HX_CSTRING("filterNot"),
	HX_CSTRING("contains"),
	HX_CSTRING("find"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SlotList_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(SlotList_obj::NIL,"NIL");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SlotList_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(SlotList_obj::NIL,"NIL");
};

#endif

Class SlotList_obj::__mClass;

void SlotList_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("msignal.SlotList"), hx::TCanCast< SlotList_obj> ,sStaticFields,sMemberFields,
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

void SlotList_obj::__boot()
{
}

} // end namespace msignal
