// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dOdOdIsrcdIeventdictT

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "../src/T2Event.h"
#include "../src/T1Event.h"
#include "../src/TriggerData.h"
#include "../src/EventMetaData.h"
#include "../src/RPRootDumpDigiInfo.h"
#include "../src/RPEvent.h"
#include "../src/RPRootDumpPattern.h"
#include "../src/RPRootDumpPatternInfo.h"
#include "../src/RPRootDumpReconstructedProton.h"
#include "../src/RPRootDumpReconstructedProtonPair.h"
#include "../src/RPRootDumpTrackInfo.h"
#include "../src/NtupleInfo.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_T2Event(void *p = 0);
   static void *newArray_T2Event(Long_t size, void *p);
   static void delete_T2Event(void *p);
   static void deleteArray_T2Event(void *p);
   static void destruct_T2Event(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::T2Event*)
   {
      ::T2Event *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::T2Event >(0);
      static ::ROOT::TGenericClassInfo 
         instance("T2Event", ::T2Event::Class_Version(), "../src/T2Event.h", 7,
                  typeid(::T2Event), DefineBehavior(ptr, ptr),
                  &::T2Event::Dictionary, isa_proxy, 4,
                  sizeof(::T2Event) );
      instance.SetNew(&new_T2Event);
      instance.SetNewArray(&newArray_T2Event);
      instance.SetDelete(&delete_T2Event);
      instance.SetDeleteArray(&deleteArray_T2Event);
      instance.SetDestructor(&destruct_T2Event);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::T2Event*)
   {
      return GenerateInitInstanceLocal((::T2Event*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::T2Event*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_T1Event(void *p = 0);
   static void *newArray_T1Event(Long_t size, void *p);
   static void delete_T1Event(void *p);
   static void deleteArray_T1Event(void *p);
   static void destruct_T1Event(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::T1Event*)
   {
      ::T1Event *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::T1Event >(0);
      static ::ROOT::TGenericClassInfo 
         instance("T1Event", ::T1Event::Class_Version(), "../src/T1Event.h", 7,
                  typeid(::T1Event), DefineBehavior(ptr, ptr),
                  &::T1Event::Dictionary, isa_proxy, 4,
                  sizeof(::T1Event) );
      instance.SetNew(&new_T1Event);
      instance.SetNewArray(&newArray_T1Event);
      instance.SetDelete(&delete_T1Event);
      instance.SetDeleteArray(&deleteArray_T1Event);
      instance.SetDestructor(&destruct_T1Event);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::T1Event*)
   {
      return GenerateInitInstanceLocal((::T1Event*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::T1Event*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_TriggerData(void *p = 0);
   static void *newArray_TriggerData(Long_t size, void *p);
   static void delete_TriggerData(void *p);
   static void deleteArray_TriggerData(void *p);
   static void destruct_TriggerData(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TriggerData*)
   {
      ::TriggerData *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TriggerData >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TriggerData", ::TriggerData::Class_Version(), "../src/TriggerData.h", 6,
                  typeid(::TriggerData), DefineBehavior(ptr, ptr),
                  &::TriggerData::Dictionary, isa_proxy, 4,
                  sizeof(::TriggerData) );
      instance.SetNew(&new_TriggerData);
      instance.SetNewArray(&newArray_TriggerData);
      instance.SetDelete(&delete_TriggerData);
      instance.SetDeleteArray(&deleteArray_TriggerData);
      instance.SetDestructor(&destruct_TriggerData);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TriggerData*)
   {
      return GenerateInitInstanceLocal((::TriggerData*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::TriggerData*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_EventMetaData(void *p = 0);
   static void *newArray_EventMetaData(Long_t size, void *p);
   static void delete_EventMetaData(void *p);
   static void deleteArray_EventMetaData(void *p);
   static void destruct_EventMetaData(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EventMetaData*)
   {
      ::EventMetaData *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::EventMetaData >(0);
      static ::ROOT::TGenericClassInfo 
         instance("EventMetaData", ::EventMetaData::Class_Version(), "../src/EventMetaData.h", 7,
                  typeid(::EventMetaData), DefineBehavior(ptr, ptr),
                  &::EventMetaData::Dictionary, isa_proxy, 4,
                  sizeof(::EventMetaData) );
      instance.SetNew(&new_EventMetaData);
      instance.SetNewArray(&newArray_EventMetaData);
      instance.SetDelete(&delete_EventMetaData);
      instance.SetDeleteArray(&deleteArray_EventMetaData);
      instance.SetDestructor(&destruct_EventMetaData);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EventMetaData*)
   {
      return GenerateInitInstanceLocal((::EventMetaData*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EventMetaData*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_RPRootDumpDigiInfo(void *p = 0);
   static void *newArray_RPRootDumpDigiInfo(Long_t size, void *p);
   static void delete_RPRootDumpDigiInfo(void *p);
   static void deleteArray_RPRootDumpDigiInfo(void *p);
   static void destruct_RPRootDumpDigiInfo(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RPRootDumpDigiInfo*)
   {
      ::RPRootDumpDigiInfo *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::RPRootDumpDigiInfo >(0);
      static ::ROOT::TGenericClassInfo 
         instance("RPRootDumpDigiInfo", ::RPRootDumpDigiInfo::Class_Version(), "../src/RPRootDumpDigiInfo.h", 12,
                  typeid(::RPRootDumpDigiInfo), DefineBehavior(ptr, ptr),
                  &::RPRootDumpDigiInfo::Dictionary, isa_proxy, 4,
                  sizeof(::RPRootDumpDigiInfo) );
      instance.SetNew(&new_RPRootDumpDigiInfo);
      instance.SetNewArray(&newArray_RPRootDumpDigiInfo);
      instance.SetDelete(&delete_RPRootDumpDigiInfo);
      instance.SetDeleteArray(&deleteArray_RPRootDumpDigiInfo);
      instance.SetDestructor(&destruct_RPRootDumpDigiInfo);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RPRootDumpDigiInfo*)
   {
      return GenerateInitInstanceLocal((::RPRootDumpDigiInfo*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::RPRootDumpDigiInfo*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_RPEvent(void *p = 0);
   static void *newArray_RPEvent(Long_t size, void *p);
   static void delete_RPEvent(void *p);
   static void deleteArray_RPEvent(void *p);
   static void destruct_RPEvent(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RPEvent*)
   {
      ::RPEvent *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::RPEvent >(0);
      static ::ROOT::TGenericClassInfo 
         instance("RPEvent", ::RPEvent::Class_Version(), "../src/RPEvent.h", 17,
                  typeid(::RPEvent), DefineBehavior(ptr, ptr),
                  &::RPEvent::Dictionary, isa_proxy, 4,
                  sizeof(::RPEvent) );
      instance.SetNew(&new_RPEvent);
      instance.SetNewArray(&newArray_RPEvent);
      instance.SetDelete(&delete_RPEvent);
      instance.SetDeleteArray(&deleteArray_RPEvent);
      instance.SetDestructor(&destruct_RPEvent);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RPEvent*)
   {
      return GenerateInitInstanceLocal((::RPEvent*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::RPEvent*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_RPRootDumpPattern(void *p = 0);
   static void *newArray_RPRootDumpPattern(Long_t size, void *p);
   static void delete_RPRootDumpPattern(void *p);
   static void deleteArray_RPRootDumpPattern(void *p);
   static void destruct_RPRootDumpPattern(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RPRootDumpPattern*)
   {
      ::RPRootDumpPattern *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::RPRootDumpPattern >(0);
      static ::ROOT::TGenericClassInfo 
         instance("RPRootDumpPattern", ::RPRootDumpPattern::Class_Version(), "../src/RPRootDumpPattern.h", 11,
                  typeid(::RPRootDumpPattern), DefineBehavior(ptr, ptr),
                  &::RPRootDumpPattern::Dictionary, isa_proxy, 4,
                  sizeof(::RPRootDumpPattern) );
      instance.SetNew(&new_RPRootDumpPattern);
      instance.SetNewArray(&newArray_RPRootDumpPattern);
      instance.SetDelete(&delete_RPRootDumpPattern);
      instance.SetDeleteArray(&deleteArray_RPRootDumpPattern);
      instance.SetDestructor(&destruct_RPRootDumpPattern);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RPRootDumpPattern*)
   {
      return GenerateInitInstanceLocal((::RPRootDumpPattern*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::RPRootDumpPattern*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_RPRootDumpPatternInfo(void *p = 0);
   static void *newArray_RPRootDumpPatternInfo(Long_t size, void *p);
   static void delete_RPRootDumpPatternInfo(void *p);
   static void deleteArray_RPRootDumpPatternInfo(void *p);
   static void destruct_RPRootDumpPatternInfo(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RPRootDumpPatternInfo*)
   {
      ::RPRootDumpPatternInfo *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::RPRootDumpPatternInfo >(0);
      static ::ROOT::TGenericClassInfo 
         instance("RPRootDumpPatternInfo", ::RPRootDumpPatternInfo::Class_Version(), "../src/RPRootDumpPatternInfo.h", 13,
                  typeid(::RPRootDumpPatternInfo), DefineBehavior(ptr, ptr),
                  &::RPRootDumpPatternInfo::Dictionary, isa_proxy, 4,
                  sizeof(::RPRootDumpPatternInfo) );
      instance.SetNew(&new_RPRootDumpPatternInfo);
      instance.SetNewArray(&newArray_RPRootDumpPatternInfo);
      instance.SetDelete(&delete_RPRootDumpPatternInfo);
      instance.SetDeleteArray(&deleteArray_RPRootDumpPatternInfo);
      instance.SetDestructor(&destruct_RPRootDumpPatternInfo);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RPRootDumpPatternInfo*)
   {
      return GenerateInitInstanceLocal((::RPRootDumpPatternInfo*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::RPRootDumpPatternInfo*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_RPRootDumpReconstructedProton(void *p = 0);
   static void *newArray_RPRootDumpReconstructedProton(Long_t size, void *p);
   static void delete_RPRootDumpReconstructedProton(void *p);
   static void deleteArray_RPRootDumpReconstructedProton(void *p);
   static void destruct_RPRootDumpReconstructedProton(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RPRootDumpReconstructedProton*)
   {
      ::RPRootDumpReconstructedProton *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::RPRootDumpReconstructedProton >(0);
      static ::ROOT::TGenericClassInfo 
         instance("RPRootDumpReconstructedProton", ::RPRootDumpReconstructedProton::Class_Version(), "../src/RPRootDumpReconstructedProton.h", 10,
                  typeid(::RPRootDumpReconstructedProton), DefineBehavior(ptr, ptr),
                  &::RPRootDumpReconstructedProton::Dictionary, isa_proxy, 4,
                  sizeof(::RPRootDumpReconstructedProton) );
      instance.SetNew(&new_RPRootDumpReconstructedProton);
      instance.SetNewArray(&newArray_RPRootDumpReconstructedProton);
      instance.SetDelete(&delete_RPRootDumpReconstructedProton);
      instance.SetDeleteArray(&deleteArray_RPRootDumpReconstructedProton);
      instance.SetDestructor(&destruct_RPRootDumpReconstructedProton);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RPRootDumpReconstructedProton*)
   {
      return GenerateInitInstanceLocal((::RPRootDumpReconstructedProton*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::RPRootDumpReconstructedProton*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_RPRootDumpReconstructedProtonPair(void *p = 0);
   static void *newArray_RPRootDumpReconstructedProtonPair(Long_t size, void *p);
   static void delete_RPRootDumpReconstructedProtonPair(void *p);
   static void deleteArray_RPRootDumpReconstructedProtonPair(void *p);
   static void destruct_RPRootDumpReconstructedProtonPair(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RPRootDumpReconstructedProtonPair*)
   {
      ::RPRootDumpReconstructedProtonPair *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::RPRootDumpReconstructedProtonPair >(0);
      static ::ROOT::TGenericClassInfo 
         instance("RPRootDumpReconstructedProtonPair", ::RPRootDumpReconstructedProtonPair::Class_Version(), "../src/RPRootDumpReconstructedProtonPair.h", 10,
                  typeid(::RPRootDumpReconstructedProtonPair), DefineBehavior(ptr, ptr),
                  &::RPRootDumpReconstructedProtonPair::Dictionary, isa_proxy, 4,
                  sizeof(::RPRootDumpReconstructedProtonPair) );
      instance.SetNew(&new_RPRootDumpReconstructedProtonPair);
      instance.SetNewArray(&newArray_RPRootDumpReconstructedProtonPair);
      instance.SetDelete(&delete_RPRootDumpReconstructedProtonPair);
      instance.SetDeleteArray(&deleteArray_RPRootDumpReconstructedProtonPair);
      instance.SetDestructor(&destruct_RPRootDumpReconstructedProtonPair);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RPRootDumpReconstructedProtonPair*)
   {
      return GenerateInitInstanceLocal((::RPRootDumpReconstructedProtonPair*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::RPRootDumpReconstructedProtonPair*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_RPRootDumpTrackInfo(void *p = 0);
   static void *newArray_RPRootDumpTrackInfo(Long_t size, void *p);
   static void delete_RPRootDumpTrackInfo(void *p);
   static void deleteArray_RPRootDumpTrackInfo(void *p);
   static void destruct_RPRootDumpTrackInfo(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RPRootDumpTrackInfo*)
   {
      ::RPRootDumpTrackInfo *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::RPRootDumpTrackInfo >(0);
      static ::ROOT::TGenericClassInfo 
         instance("RPRootDumpTrackInfo", ::RPRootDumpTrackInfo::Class_Version(), "../src/RPRootDumpTrackInfo.h", 16,
                  typeid(::RPRootDumpTrackInfo), DefineBehavior(ptr, ptr),
                  &::RPRootDumpTrackInfo::Dictionary, isa_proxy, 4,
                  sizeof(::RPRootDumpTrackInfo) );
      instance.SetNew(&new_RPRootDumpTrackInfo);
      instance.SetNewArray(&newArray_RPRootDumpTrackInfo);
      instance.SetDelete(&delete_RPRootDumpTrackInfo);
      instance.SetDeleteArray(&deleteArray_RPRootDumpTrackInfo);
      instance.SetDestructor(&destruct_RPRootDumpTrackInfo);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RPRootDumpTrackInfo*)
   {
      return GenerateInitInstanceLocal((::RPRootDumpTrackInfo*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::RPRootDumpTrackInfo*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_NtupleInfo(void *p = 0);
   static void *newArray_NtupleInfo(Long_t size, void *p);
   static void delete_NtupleInfo(void *p);
   static void deleteArray_NtupleInfo(void *p);
   static void destruct_NtupleInfo(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::NtupleInfo*)
   {
      ::NtupleInfo *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::NtupleInfo >(0);
      static ::ROOT::TGenericClassInfo 
         instance("NtupleInfo", ::NtupleInfo::Class_Version(), "../src/NtupleInfo.h", 8,
                  typeid(::NtupleInfo), DefineBehavior(ptr, ptr),
                  &::NtupleInfo::Dictionary, isa_proxy, 4,
                  sizeof(::NtupleInfo) );
      instance.SetNew(&new_NtupleInfo);
      instance.SetNewArray(&newArray_NtupleInfo);
      instance.SetDelete(&delete_NtupleInfo);
      instance.SetDeleteArray(&deleteArray_NtupleInfo);
      instance.SetDestructor(&destruct_NtupleInfo);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::NtupleInfo*)
   {
      return GenerateInitInstanceLocal((::NtupleInfo*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::NtupleInfo*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr T2Event::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *T2Event::Class_Name()
{
   return "T2Event";
}

//______________________________________________________________________________
const char *T2Event::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::T2Event*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int T2Event::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::T2Event*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *T2Event::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::T2Event*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *T2Event::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::T2Event*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr T1Event::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *T1Event::Class_Name()
{
   return "T1Event";
}

//______________________________________________________________________________
const char *T1Event::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::T1Event*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int T1Event::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::T1Event*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *T1Event::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::T1Event*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *T1Event::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::T1Event*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr TriggerData::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TriggerData::Class_Name()
{
   return "TriggerData";
}

//______________________________________________________________________________
const char *TriggerData::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TriggerData*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TriggerData::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TriggerData*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TriggerData::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TriggerData*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TriggerData::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TriggerData*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr EventMetaData::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *EventMetaData::Class_Name()
{
   return "EventMetaData";
}

//______________________________________________________________________________
const char *EventMetaData::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EventMetaData*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int EventMetaData::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EventMetaData*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *EventMetaData::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EventMetaData*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *EventMetaData::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EventMetaData*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr RPRootDumpDigiInfo::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *RPRootDumpDigiInfo::Class_Name()
{
   return "RPRootDumpDigiInfo";
}

//______________________________________________________________________________
const char *RPRootDumpDigiInfo::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RPRootDumpDigiInfo*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int RPRootDumpDigiInfo::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RPRootDumpDigiInfo*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *RPRootDumpDigiInfo::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RPRootDumpDigiInfo*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *RPRootDumpDigiInfo::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RPRootDumpDigiInfo*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr RPEvent::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *RPEvent::Class_Name()
{
   return "RPEvent";
}

//______________________________________________________________________________
const char *RPEvent::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RPEvent*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int RPEvent::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RPEvent*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *RPEvent::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RPEvent*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *RPEvent::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RPEvent*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr RPRootDumpPattern::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *RPRootDumpPattern::Class_Name()
{
   return "RPRootDumpPattern";
}

//______________________________________________________________________________
const char *RPRootDumpPattern::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RPRootDumpPattern*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int RPRootDumpPattern::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RPRootDumpPattern*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *RPRootDumpPattern::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RPRootDumpPattern*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *RPRootDumpPattern::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RPRootDumpPattern*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr RPRootDumpPatternInfo::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *RPRootDumpPatternInfo::Class_Name()
{
   return "RPRootDumpPatternInfo";
}

//______________________________________________________________________________
const char *RPRootDumpPatternInfo::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RPRootDumpPatternInfo*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int RPRootDumpPatternInfo::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RPRootDumpPatternInfo*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *RPRootDumpPatternInfo::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RPRootDumpPatternInfo*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *RPRootDumpPatternInfo::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RPRootDumpPatternInfo*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr RPRootDumpReconstructedProton::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *RPRootDumpReconstructedProton::Class_Name()
{
   return "RPRootDumpReconstructedProton";
}

//______________________________________________________________________________
const char *RPRootDumpReconstructedProton::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RPRootDumpReconstructedProton*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int RPRootDumpReconstructedProton::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RPRootDumpReconstructedProton*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *RPRootDumpReconstructedProton::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RPRootDumpReconstructedProton*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *RPRootDumpReconstructedProton::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RPRootDumpReconstructedProton*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr RPRootDumpReconstructedProtonPair::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *RPRootDumpReconstructedProtonPair::Class_Name()
{
   return "RPRootDumpReconstructedProtonPair";
}

//______________________________________________________________________________
const char *RPRootDumpReconstructedProtonPair::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RPRootDumpReconstructedProtonPair*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int RPRootDumpReconstructedProtonPair::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RPRootDumpReconstructedProtonPair*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *RPRootDumpReconstructedProtonPair::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RPRootDumpReconstructedProtonPair*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *RPRootDumpReconstructedProtonPair::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RPRootDumpReconstructedProtonPair*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr RPRootDumpTrackInfo::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *RPRootDumpTrackInfo::Class_Name()
{
   return "RPRootDumpTrackInfo";
}

//______________________________________________________________________________
const char *RPRootDumpTrackInfo::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RPRootDumpTrackInfo*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int RPRootDumpTrackInfo::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::RPRootDumpTrackInfo*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *RPRootDumpTrackInfo::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RPRootDumpTrackInfo*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *RPRootDumpTrackInfo::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::RPRootDumpTrackInfo*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr NtupleInfo::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *NtupleInfo::Class_Name()
{
   return "NtupleInfo";
}

//______________________________________________________________________________
const char *NtupleInfo::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::NtupleInfo*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int NtupleInfo::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::NtupleInfo*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *NtupleInfo::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::NtupleInfo*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *NtupleInfo::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::NtupleInfo*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void T2Event::Streamer(TBuffer &R__b)
{
   // Stream an object of class T2Event.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(T2Event::Class(),this);
   } else {
      R__b.WriteClassBuffer(T2Event::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_T2Event(void *p) {
      return  p ? new(p) ::T2Event : new ::T2Event;
   }
   static void *newArray_T2Event(Long_t nElements, void *p) {
      return p ? new(p) ::T2Event[nElements] : new ::T2Event[nElements];
   }
   // Wrapper around operator delete
   static void delete_T2Event(void *p) {
      delete ((::T2Event*)p);
   }
   static void deleteArray_T2Event(void *p) {
      delete [] ((::T2Event*)p);
   }
   static void destruct_T2Event(void *p) {
      typedef ::T2Event current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::T2Event

//______________________________________________________________________________
void T1Event::Streamer(TBuffer &R__b)
{
   // Stream an object of class T1Event.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(T1Event::Class(),this);
   } else {
      R__b.WriteClassBuffer(T1Event::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_T1Event(void *p) {
      return  p ? new(p) ::T1Event : new ::T1Event;
   }
   static void *newArray_T1Event(Long_t nElements, void *p) {
      return p ? new(p) ::T1Event[nElements] : new ::T1Event[nElements];
   }
   // Wrapper around operator delete
   static void delete_T1Event(void *p) {
      delete ((::T1Event*)p);
   }
   static void deleteArray_T1Event(void *p) {
      delete [] ((::T1Event*)p);
   }
   static void destruct_T1Event(void *p) {
      typedef ::T1Event current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::T1Event

//______________________________________________________________________________
void TriggerData::Streamer(TBuffer &R__b)
{
   // Stream an object of class TriggerData.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TriggerData::Class(),this);
   } else {
      R__b.WriteClassBuffer(TriggerData::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TriggerData(void *p) {
      return  p ? new(p) ::TriggerData : new ::TriggerData;
   }
   static void *newArray_TriggerData(Long_t nElements, void *p) {
      return p ? new(p) ::TriggerData[nElements] : new ::TriggerData[nElements];
   }
   // Wrapper around operator delete
   static void delete_TriggerData(void *p) {
      delete ((::TriggerData*)p);
   }
   static void deleteArray_TriggerData(void *p) {
      delete [] ((::TriggerData*)p);
   }
   static void destruct_TriggerData(void *p) {
      typedef ::TriggerData current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TriggerData

//______________________________________________________________________________
void EventMetaData::Streamer(TBuffer &R__b)
{
   // Stream an object of class EventMetaData.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(EventMetaData::Class(),this);
   } else {
      R__b.WriteClassBuffer(EventMetaData::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_EventMetaData(void *p) {
      return  p ? new(p) ::EventMetaData : new ::EventMetaData;
   }
   static void *newArray_EventMetaData(Long_t nElements, void *p) {
      return p ? new(p) ::EventMetaData[nElements] : new ::EventMetaData[nElements];
   }
   // Wrapper around operator delete
   static void delete_EventMetaData(void *p) {
      delete ((::EventMetaData*)p);
   }
   static void deleteArray_EventMetaData(void *p) {
      delete [] ((::EventMetaData*)p);
   }
   static void destruct_EventMetaData(void *p) {
      typedef ::EventMetaData current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EventMetaData

//______________________________________________________________________________
void RPRootDumpDigiInfo::Streamer(TBuffer &R__b)
{
   // Stream an object of class RPRootDumpDigiInfo.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(RPRootDumpDigiInfo::Class(),this);
   } else {
      R__b.WriteClassBuffer(RPRootDumpDigiInfo::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_RPRootDumpDigiInfo(void *p) {
      return  p ? new(p) ::RPRootDumpDigiInfo : new ::RPRootDumpDigiInfo;
   }
   static void *newArray_RPRootDumpDigiInfo(Long_t nElements, void *p) {
      return p ? new(p) ::RPRootDumpDigiInfo[nElements] : new ::RPRootDumpDigiInfo[nElements];
   }
   // Wrapper around operator delete
   static void delete_RPRootDumpDigiInfo(void *p) {
      delete ((::RPRootDumpDigiInfo*)p);
   }
   static void deleteArray_RPRootDumpDigiInfo(void *p) {
      delete [] ((::RPRootDumpDigiInfo*)p);
   }
   static void destruct_RPRootDumpDigiInfo(void *p) {
      typedef ::RPRootDumpDigiInfo current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RPRootDumpDigiInfo

//______________________________________________________________________________
void RPEvent::Streamer(TBuffer &R__b)
{
   // Stream an object of class RPEvent.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(RPEvent::Class(),this);
   } else {
      R__b.WriteClassBuffer(RPEvent::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_RPEvent(void *p) {
      return  p ? new(p) ::RPEvent : new ::RPEvent;
   }
   static void *newArray_RPEvent(Long_t nElements, void *p) {
      return p ? new(p) ::RPEvent[nElements] : new ::RPEvent[nElements];
   }
   // Wrapper around operator delete
   static void delete_RPEvent(void *p) {
      delete ((::RPEvent*)p);
   }
   static void deleteArray_RPEvent(void *p) {
      delete [] ((::RPEvent*)p);
   }
   static void destruct_RPEvent(void *p) {
      typedef ::RPEvent current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RPEvent

//______________________________________________________________________________
void RPRootDumpPattern::Streamer(TBuffer &R__b)
{
   // Stream an object of class RPRootDumpPattern.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(RPRootDumpPattern::Class(),this);
   } else {
      R__b.WriteClassBuffer(RPRootDumpPattern::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_RPRootDumpPattern(void *p) {
      return  p ? new(p) ::RPRootDumpPattern : new ::RPRootDumpPattern;
   }
   static void *newArray_RPRootDumpPattern(Long_t nElements, void *p) {
      return p ? new(p) ::RPRootDumpPattern[nElements] : new ::RPRootDumpPattern[nElements];
   }
   // Wrapper around operator delete
   static void delete_RPRootDumpPattern(void *p) {
      delete ((::RPRootDumpPattern*)p);
   }
   static void deleteArray_RPRootDumpPattern(void *p) {
      delete [] ((::RPRootDumpPattern*)p);
   }
   static void destruct_RPRootDumpPattern(void *p) {
      typedef ::RPRootDumpPattern current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RPRootDumpPattern

//______________________________________________________________________________
void RPRootDumpPatternInfo::Streamer(TBuffer &R__b)
{
   // Stream an object of class RPRootDumpPatternInfo.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(RPRootDumpPatternInfo::Class(),this);
   } else {
      R__b.WriteClassBuffer(RPRootDumpPatternInfo::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_RPRootDumpPatternInfo(void *p) {
      return  p ? new(p) ::RPRootDumpPatternInfo : new ::RPRootDumpPatternInfo;
   }
   static void *newArray_RPRootDumpPatternInfo(Long_t nElements, void *p) {
      return p ? new(p) ::RPRootDumpPatternInfo[nElements] : new ::RPRootDumpPatternInfo[nElements];
   }
   // Wrapper around operator delete
   static void delete_RPRootDumpPatternInfo(void *p) {
      delete ((::RPRootDumpPatternInfo*)p);
   }
   static void deleteArray_RPRootDumpPatternInfo(void *p) {
      delete [] ((::RPRootDumpPatternInfo*)p);
   }
   static void destruct_RPRootDumpPatternInfo(void *p) {
      typedef ::RPRootDumpPatternInfo current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RPRootDumpPatternInfo

//______________________________________________________________________________
void RPRootDumpReconstructedProton::Streamer(TBuffer &R__b)
{
   // Stream an object of class RPRootDumpReconstructedProton.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(RPRootDumpReconstructedProton::Class(),this);
   } else {
      R__b.WriteClassBuffer(RPRootDumpReconstructedProton::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_RPRootDumpReconstructedProton(void *p) {
      return  p ? new(p) ::RPRootDumpReconstructedProton : new ::RPRootDumpReconstructedProton;
   }
   static void *newArray_RPRootDumpReconstructedProton(Long_t nElements, void *p) {
      return p ? new(p) ::RPRootDumpReconstructedProton[nElements] : new ::RPRootDumpReconstructedProton[nElements];
   }
   // Wrapper around operator delete
   static void delete_RPRootDumpReconstructedProton(void *p) {
      delete ((::RPRootDumpReconstructedProton*)p);
   }
   static void deleteArray_RPRootDumpReconstructedProton(void *p) {
      delete [] ((::RPRootDumpReconstructedProton*)p);
   }
   static void destruct_RPRootDumpReconstructedProton(void *p) {
      typedef ::RPRootDumpReconstructedProton current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RPRootDumpReconstructedProton

//______________________________________________________________________________
void RPRootDumpReconstructedProtonPair::Streamer(TBuffer &R__b)
{
   // Stream an object of class RPRootDumpReconstructedProtonPair.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(RPRootDumpReconstructedProtonPair::Class(),this);
   } else {
      R__b.WriteClassBuffer(RPRootDumpReconstructedProtonPair::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_RPRootDumpReconstructedProtonPair(void *p) {
      return  p ? new(p) ::RPRootDumpReconstructedProtonPair : new ::RPRootDumpReconstructedProtonPair;
   }
   static void *newArray_RPRootDumpReconstructedProtonPair(Long_t nElements, void *p) {
      return p ? new(p) ::RPRootDumpReconstructedProtonPair[nElements] : new ::RPRootDumpReconstructedProtonPair[nElements];
   }
   // Wrapper around operator delete
   static void delete_RPRootDumpReconstructedProtonPair(void *p) {
      delete ((::RPRootDumpReconstructedProtonPair*)p);
   }
   static void deleteArray_RPRootDumpReconstructedProtonPair(void *p) {
      delete [] ((::RPRootDumpReconstructedProtonPair*)p);
   }
   static void destruct_RPRootDumpReconstructedProtonPair(void *p) {
      typedef ::RPRootDumpReconstructedProtonPair current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RPRootDumpReconstructedProtonPair

//______________________________________________________________________________
void RPRootDumpTrackInfo::Streamer(TBuffer &R__b)
{
   // Stream an object of class RPRootDumpTrackInfo.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(RPRootDumpTrackInfo::Class(),this);
   } else {
      R__b.WriteClassBuffer(RPRootDumpTrackInfo::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_RPRootDumpTrackInfo(void *p) {
      return  p ? new(p) ::RPRootDumpTrackInfo : new ::RPRootDumpTrackInfo;
   }
   static void *newArray_RPRootDumpTrackInfo(Long_t nElements, void *p) {
      return p ? new(p) ::RPRootDumpTrackInfo[nElements] : new ::RPRootDumpTrackInfo[nElements];
   }
   // Wrapper around operator delete
   static void delete_RPRootDumpTrackInfo(void *p) {
      delete ((::RPRootDumpTrackInfo*)p);
   }
   static void deleteArray_RPRootDumpTrackInfo(void *p) {
      delete [] ((::RPRootDumpTrackInfo*)p);
   }
   static void destruct_RPRootDumpTrackInfo(void *p) {
      typedef ::RPRootDumpTrackInfo current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RPRootDumpTrackInfo

//______________________________________________________________________________
void NtupleInfo::Streamer(TBuffer &R__b)
{
   // Stream an object of class NtupleInfo.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(NtupleInfo::Class(),this);
   } else {
      R__b.WriteClassBuffer(NtupleInfo::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_NtupleInfo(void *p) {
      return  p ? new(p) ::NtupleInfo : new ::NtupleInfo;
   }
   static void *newArray_NtupleInfo(Long_t nElements, void *p) {
      return p ? new(p) ::NtupleInfo[nElements] : new ::NtupleInfo[nElements];
   }
   // Wrapper around operator delete
   static void delete_NtupleInfo(void *p) {
      delete ((::NtupleInfo*)p);
   }
   static void deleteArray_NtupleInfo(void *p) {
      delete [] ((::NtupleInfo*)p);
   }
   static void destruct_NtupleInfo(void *p) {
      typedef ::NtupleInfo current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::NtupleInfo

namespace ROOT {
   static TClass *vectorlEunsignedsPintgR_Dictionary();
   static void vectorlEunsignedsPintgR_TClassManip(TClass*);
   static void *new_vectorlEunsignedsPintgR(void *p = 0);
   static void *newArray_vectorlEunsignedsPintgR(Long_t size, void *p);
   static void delete_vectorlEunsignedsPintgR(void *p);
   static void deleteArray_vectorlEunsignedsPintgR(void *p);
   static void destruct_vectorlEunsignedsPintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<unsigned int>*)
   {
      vector<unsigned int> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<unsigned int>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<unsigned int>", -2, "vector", 214,
                  typeid(vector<unsigned int>), DefineBehavior(ptr, ptr),
                  &vectorlEunsignedsPintgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<unsigned int>) );
      instance.SetNew(&new_vectorlEunsignedsPintgR);
      instance.SetNewArray(&newArray_vectorlEunsignedsPintgR);
      instance.SetDelete(&delete_vectorlEunsignedsPintgR);
      instance.SetDeleteArray(&deleteArray_vectorlEunsignedsPintgR);
      instance.SetDestructor(&destruct_vectorlEunsignedsPintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<unsigned int> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<unsigned int>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEunsignedsPintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<unsigned int>*)0x0)->GetClass();
      vectorlEunsignedsPintgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEunsignedsPintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEunsignedsPintgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<unsigned int> : new vector<unsigned int>;
   }
   static void *newArray_vectorlEunsignedsPintgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<unsigned int>[nElements] : new vector<unsigned int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEunsignedsPintgR(void *p) {
      delete ((vector<unsigned int>*)p);
   }
   static void deleteArray_vectorlEunsignedsPintgR(void *p) {
      delete [] ((vector<unsigned int>*)p);
   }
   static void destruct_vectorlEunsignedsPintgR(void *p) {
      typedef vector<unsigned int> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<unsigned int>

namespace ROOT {
   static TClass *vectorlEintgR_Dictionary();
   static void vectorlEintgR_TClassManip(TClass*);
   static void *new_vectorlEintgR(void *p = 0);
   static void *newArray_vectorlEintgR(Long_t size, void *p);
   static void delete_vectorlEintgR(void *p);
   static void deleteArray_vectorlEintgR(void *p);
   static void destruct_vectorlEintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<int>*)
   {
      vector<int> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<int>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<int>", -2, "vector", 214,
                  typeid(vector<int>), DefineBehavior(ptr, ptr),
                  &vectorlEintgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<int>) );
      instance.SetNew(&new_vectorlEintgR);
      instance.SetNewArray(&newArray_vectorlEintgR);
      instance.SetDelete(&delete_vectorlEintgR);
      instance.SetDeleteArray(&deleteArray_vectorlEintgR);
      instance.SetDestructor(&destruct_vectorlEintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<int> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<int>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<int>*)0x0)->GetClass();
      vectorlEintgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEintgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<int> : new vector<int>;
   }
   static void *newArray_vectorlEintgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<int>[nElements] : new vector<int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEintgR(void *p) {
      delete ((vector<int>*)p);
   }
   static void deleteArray_vectorlEintgR(void *p) {
      delete [] ((vector<int>*)p);
   }
   static void destruct_vectorlEintgR(void *p) {
      typedef vector<int> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<int>

namespace ROOT {
   static TClass *vectorlEdoublegR_Dictionary();
   static void vectorlEdoublegR_TClassManip(TClass*);
   static void *new_vectorlEdoublegR(void *p = 0);
   static void *newArray_vectorlEdoublegR(Long_t size, void *p);
   static void delete_vectorlEdoublegR(void *p);
   static void deleteArray_vectorlEdoublegR(void *p);
   static void destruct_vectorlEdoublegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<double>*)
   {
      vector<double> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<double>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<double>", -2, "vector", 214,
                  typeid(vector<double>), DefineBehavior(ptr, ptr),
                  &vectorlEdoublegR_Dictionary, isa_proxy, 0,
                  sizeof(vector<double>) );
      instance.SetNew(&new_vectorlEdoublegR);
      instance.SetNewArray(&newArray_vectorlEdoublegR);
      instance.SetDelete(&delete_vectorlEdoublegR);
      instance.SetDeleteArray(&deleteArray_vectorlEdoublegR);
      instance.SetDestructor(&destruct_vectorlEdoublegR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<double> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<double>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEdoublegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<double>*)0x0)->GetClass();
      vectorlEdoublegR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEdoublegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEdoublegR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<double> : new vector<double>;
   }
   static void *newArray_vectorlEdoublegR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<double>[nElements] : new vector<double>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEdoublegR(void *p) {
      delete ((vector<double>*)p);
   }
   static void deleteArray_vectorlEdoublegR(void *p) {
      delete [] ((vector<double>*)p);
   }
   static void destruct_vectorlEdoublegR(void *p) {
      typedef vector<double> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<double>

namespace ROOT {
   static TClass *vectorlERPRootDumpTrackInfogR_Dictionary();
   static void vectorlERPRootDumpTrackInfogR_TClassManip(TClass*);
   static void *new_vectorlERPRootDumpTrackInfogR(void *p = 0);
   static void *newArray_vectorlERPRootDumpTrackInfogR(Long_t size, void *p);
   static void delete_vectorlERPRootDumpTrackInfogR(void *p);
   static void deleteArray_vectorlERPRootDumpTrackInfogR(void *p);
   static void destruct_vectorlERPRootDumpTrackInfogR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<RPRootDumpTrackInfo>*)
   {
      vector<RPRootDumpTrackInfo> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<RPRootDumpTrackInfo>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<RPRootDumpTrackInfo>", -2, "vector", 214,
                  typeid(vector<RPRootDumpTrackInfo>), DefineBehavior(ptr, ptr),
                  &vectorlERPRootDumpTrackInfogR_Dictionary, isa_proxy, 4,
                  sizeof(vector<RPRootDumpTrackInfo>) );
      instance.SetNew(&new_vectorlERPRootDumpTrackInfogR);
      instance.SetNewArray(&newArray_vectorlERPRootDumpTrackInfogR);
      instance.SetDelete(&delete_vectorlERPRootDumpTrackInfogR);
      instance.SetDeleteArray(&deleteArray_vectorlERPRootDumpTrackInfogR);
      instance.SetDestructor(&destruct_vectorlERPRootDumpTrackInfogR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<RPRootDumpTrackInfo> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<RPRootDumpTrackInfo>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlERPRootDumpTrackInfogR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<RPRootDumpTrackInfo>*)0x0)->GetClass();
      vectorlERPRootDumpTrackInfogR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlERPRootDumpTrackInfogR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlERPRootDumpTrackInfogR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<RPRootDumpTrackInfo> : new vector<RPRootDumpTrackInfo>;
   }
   static void *newArray_vectorlERPRootDumpTrackInfogR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<RPRootDumpTrackInfo>[nElements] : new vector<RPRootDumpTrackInfo>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlERPRootDumpTrackInfogR(void *p) {
      delete ((vector<RPRootDumpTrackInfo>*)p);
   }
   static void deleteArray_vectorlERPRootDumpTrackInfogR(void *p) {
      delete [] ((vector<RPRootDumpTrackInfo>*)p);
   }
   static void destruct_vectorlERPRootDumpTrackInfogR(void *p) {
      typedef vector<RPRootDumpTrackInfo> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<RPRootDumpTrackInfo>

namespace ROOT {
   static TClass *vectorlERPRootDumpPatterngR_Dictionary();
   static void vectorlERPRootDumpPatterngR_TClassManip(TClass*);
   static void *new_vectorlERPRootDumpPatterngR(void *p = 0);
   static void *newArray_vectorlERPRootDumpPatterngR(Long_t size, void *p);
   static void delete_vectorlERPRootDumpPatterngR(void *p);
   static void deleteArray_vectorlERPRootDumpPatterngR(void *p);
   static void destruct_vectorlERPRootDumpPatterngR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<RPRootDumpPattern>*)
   {
      vector<RPRootDumpPattern> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<RPRootDumpPattern>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<RPRootDumpPattern>", -2, "vector", 214,
                  typeid(vector<RPRootDumpPattern>), DefineBehavior(ptr, ptr),
                  &vectorlERPRootDumpPatterngR_Dictionary, isa_proxy, 0,
                  sizeof(vector<RPRootDumpPattern>) );
      instance.SetNew(&new_vectorlERPRootDumpPatterngR);
      instance.SetNewArray(&newArray_vectorlERPRootDumpPatterngR);
      instance.SetDelete(&delete_vectorlERPRootDumpPatterngR);
      instance.SetDeleteArray(&deleteArray_vectorlERPRootDumpPatterngR);
      instance.SetDestructor(&destruct_vectorlERPRootDumpPatterngR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<RPRootDumpPattern> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<RPRootDumpPattern>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlERPRootDumpPatterngR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<RPRootDumpPattern>*)0x0)->GetClass();
      vectorlERPRootDumpPatterngR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlERPRootDumpPatterngR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlERPRootDumpPatterngR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<RPRootDumpPattern> : new vector<RPRootDumpPattern>;
   }
   static void *newArray_vectorlERPRootDumpPatterngR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<RPRootDumpPattern>[nElements] : new vector<RPRootDumpPattern>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlERPRootDumpPatterngR(void *p) {
      delete ((vector<RPRootDumpPattern>*)p);
   }
   static void deleteArray_vectorlERPRootDumpPatterngR(void *p) {
      delete [] ((vector<RPRootDumpPattern>*)p);
   }
   static void destruct_vectorlERPRootDumpPatterngR(void *p) {
      typedef vector<RPRootDumpPattern> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<RPRootDumpPattern>

namespace ROOT {
   static TClass *maplEunsignedsPintcOvectorlEintgRsPgR_Dictionary();
   static void maplEunsignedsPintcOvectorlEintgRsPgR_TClassManip(TClass*);
   static void *new_maplEunsignedsPintcOvectorlEintgRsPgR(void *p = 0);
   static void *newArray_maplEunsignedsPintcOvectorlEintgRsPgR(Long_t size, void *p);
   static void delete_maplEunsignedsPintcOvectorlEintgRsPgR(void *p);
   static void deleteArray_maplEunsignedsPintcOvectorlEintgRsPgR(void *p);
   static void destruct_maplEunsignedsPintcOvectorlEintgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<unsigned int,vector<int> >*)
   {
      map<unsigned int,vector<int> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<unsigned int,vector<int> >));
      static ::ROOT::TGenericClassInfo 
         instance("map<unsigned int,vector<int> >", -2, "map", 96,
                  typeid(map<unsigned int,vector<int> >), DefineBehavior(ptr, ptr),
                  &maplEunsignedsPintcOvectorlEintgRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(map<unsigned int,vector<int> >) );
      instance.SetNew(&new_maplEunsignedsPintcOvectorlEintgRsPgR);
      instance.SetNewArray(&newArray_maplEunsignedsPintcOvectorlEintgRsPgR);
      instance.SetDelete(&delete_maplEunsignedsPintcOvectorlEintgRsPgR);
      instance.SetDeleteArray(&deleteArray_maplEunsignedsPintcOvectorlEintgRsPgR);
      instance.SetDestructor(&destruct_maplEunsignedsPintcOvectorlEintgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<unsigned int,vector<int> > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const map<unsigned int,vector<int> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEunsignedsPintcOvectorlEintgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<unsigned int,vector<int> >*)0x0)->GetClass();
      maplEunsignedsPintcOvectorlEintgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEunsignedsPintcOvectorlEintgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEunsignedsPintcOvectorlEintgRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) map<unsigned int,vector<int> > : new map<unsigned int,vector<int> >;
   }
   static void *newArray_maplEunsignedsPintcOvectorlEintgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) map<unsigned int,vector<int> >[nElements] : new map<unsigned int,vector<int> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEunsignedsPintcOvectorlEintgRsPgR(void *p) {
      delete ((map<unsigned int,vector<int> >*)p);
   }
   static void deleteArray_maplEunsignedsPintcOvectorlEintgRsPgR(void *p) {
      delete [] ((map<unsigned int,vector<int> >*)p);
   }
   static void destruct_maplEunsignedsPintcOvectorlEintgRsPgR(void *p) {
      typedef map<unsigned int,vector<int> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<unsigned int,vector<int> >

namespace {
  void TriggerDictionaryInitialization_eventdictT_Impl() {
    static const char* headers[] = {
"../src/T2Event.h",
"../src/T1Event.h",
"../src/TriggerData.h",
"../src/EventMetaData.h",
"../src/RPRootDumpDigiInfo.h",
"../src/RPEvent.h",
"../src/RPRootDumpPattern.h",
"../src/RPRootDumpPatternInfo.h",
"../src/RPRootDumpReconstructedProton.h",
"../src/RPRootDumpReconstructedProtonPair.h",
"../src/RPRootDumpTrackInfo.h",
"../src/NtupleInfo.h",
0
    };
    static const char* includePaths[] = {
"/cvmfs/cms.cern.ch/slc6_amd64_gcc493/lcg/root/6.02.12-kpegke4/include",
"/afs/cern.ch/user/e/eliza/private/TOTEM_JPSI/RPSIM/CMSSW_7_6_3/src/CMS-TOTEM-Ntuples/TOTEMdataFormat/utilities/",
0
    };
    static const char* fwdDeclCode = 
R"DICTFWDDCLS(
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$../src/T2Event.h")))  T2Event;
class __attribute__((annotate("$clingAutoload$../src/T1Event.h")))  T1Event;
class __attribute__((annotate("$clingAutoload$../src/TriggerData.h")))  TriggerData;
class __attribute__((annotate("$clingAutoload$../src/EventMetaData.h")))  EventMetaData;
class __attribute__((annotate("$clingAutoload$../src/RPRootDumpDigiInfo.h")))  RPRootDumpDigiInfo;
class __attribute__((annotate("$clingAutoload$../src/RPEvent.h")))  RPEvent;
class __attribute__((annotate("$clingAutoload$../src/RPRootDumpPattern.h")))  RPRootDumpPattern;
struct __attribute__((annotate("$clingAutoload$../src/RPRootDumpPatternInfo.h")))  RPRootDumpPatternInfo;
class __attribute__((annotate("$clingAutoload$../src/RPEvent.h")))  RPRootDumpReconstructedProton;
class __attribute__((annotate("$clingAutoload$../src/RPEvent.h")))  RPRootDumpReconstructedProtonPair;
class __attribute__((annotate("$clingAutoload$../src/RPRootDumpTrackInfo.h")))  RPRootDumpTrackInfo;
namespace std{template <typename _Tp> class __attribute__((annotate("$clingAutoload$string")))  allocator;
}
class __attribute__((annotate("$clingAutoload$../src/NtupleInfo.h")))  NtupleInfo;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "../src/T2Event.h"
#include "../src/T1Event.h"
#include "../src/TriggerData.h"
#include "../src/EventMetaData.h"
#include "../src/RPRootDumpDigiInfo.h"
#include "../src/RPEvent.h"
#include "../src/RPRootDumpPattern.h"
#include "../src/RPRootDumpPatternInfo.h"
#include "../src/RPRootDumpReconstructedProton.h"
#include "../src/RPRootDumpReconstructedProtonPair.h"
#include "../src/RPRootDumpTrackInfo.h"
#include "../src/NtupleInfo.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"EventMetaData", payloadCode, "@",
"NtupleInfo", payloadCode, "@",
"RPEvent", payloadCode, "@",
"RPRootDumpDigiInfo", payloadCode, "@",
"RPRootDumpPattern", payloadCode, "@",
"RPRootDumpPatternInfo", payloadCode, "@",
"RPRootDumpReconstructedProton", payloadCode, "@",
"RPRootDumpReconstructedProtonPair", payloadCode, "@",
"RPRootDumpTrackInfo", payloadCode, "@",
"T1Event", payloadCode, "@",
"T2Event", payloadCode, "@",
"TriggerData", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("eventdictT",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_eventdictT_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_eventdictT_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_eventdictT() {
  TriggerDictionaryInitialization_eventdictT_Impl();
}
