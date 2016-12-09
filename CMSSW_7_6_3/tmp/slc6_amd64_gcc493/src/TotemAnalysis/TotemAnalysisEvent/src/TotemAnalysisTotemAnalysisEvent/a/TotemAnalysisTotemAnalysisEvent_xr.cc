// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME tmpdIslc6_amd64_gcc493dIsrcdITotemAnalysisdITotemAnalysisEventdIsrcdITotemAnalysisTotemAnalysisEventdIadITotemAnalysisTotemAnalysisEvent_xr

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
#include "src/TotemAnalysis/TotemAnalysisEvent/src/classes.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static TClass *TotemRPEvent_Dictionary();
   static void TotemRPEvent_TClassManip(TClass*);
   static void *new_TotemRPEvent(void *p = 0);
   static void *newArray_TotemRPEvent(Long_t size, void *p);
   static void delete_TotemRPEvent(void *p);
   static void deleteArray_TotemRPEvent(void *p);
   static void destruct_TotemRPEvent(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TotemRPEvent*)
   {
      ::TotemRPEvent *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::TotemRPEvent));
      static ::ROOT::TGenericClassInfo 
         instance("TotemRPEvent", "TotemAnalysis/TotemAnalysisEvent/interface/TotemRPEvent.h", 14,
                  typeid(::TotemRPEvent), DefineBehavior(ptr, ptr),
                  &TotemRPEvent_Dictionary, isa_proxy, 0,
                  sizeof(::TotemRPEvent) );
      instance.SetNew(&new_TotemRPEvent);
      instance.SetNewArray(&newArray_TotemRPEvent);
      instance.SetDelete(&delete_TotemRPEvent);
      instance.SetDeleteArray(&deleteArray_TotemRPEvent);
      instance.SetDestructor(&destruct_TotemRPEvent);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TotemRPEvent*)
   {
      return GenerateInitInstanceLocal((::TotemRPEvent*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::TotemRPEvent*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TotemRPEvent_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::TotemRPEvent*)0x0)->GetClass();
      TotemRPEvent_TClassManip(theClass);
   return theClass;
   }

   static void TotemRPEvent_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RPRootDumpTrackInfo_Dictionary();
   static void RPRootDumpTrackInfo_TClassManip(TClass*);
   static void *new_RPRootDumpTrackInfo(void *p = 0);
   static void *newArray_RPRootDumpTrackInfo(Long_t size, void *p);
   static void delete_RPRootDumpTrackInfo(void *p);
   static void deleteArray_RPRootDumpTrackInfo(void *p);
   static void destruct_RPRootDumpTrackInfo(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RPRootDumpTrackInfo*)
   {
      ::RPRootDumpTrackInfo *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RPRootDumpTrackInfo));
      static ::ROOT::TGenericClassInfo 
         instance("RPRootDumpTrackInfo", "TotemAnalysis/TotemAnalysisEvent/interface/RPRootTrackInfo.h", 7,
                  typeid(::RPRootDumpTrackInfo), DefineBehavior(ptr, ptr),
                  &RPRootDumpTrackInfo_Dictionary, isa_proxy, 0,
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

   // Dictionary for non-ClassDef classes
   static TClass *RPRootDumpTrackInfo_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RPRootDumpTrackInfo*)0x0)->GetClass();
      RPRootDumpTrackInfo_TClassManip(theClass);
   return theClass;
   }

   static void RPRootDumpTrackInfo_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RPRootDumpDigiInfo_Dictionary();
   static void RPRootDumpDigiInfo_TClassManip(TClass*);
   static void *new_RPRootDumpDigiInfo(void *p = 0);
   static void *newArray_RPRootDumpDigiInfo(Long_t size, void *p);
   static void delete_RPRootDumpDigiInfo(void *p);
   static void deleteArray_RPRootDumpDigiInfo(void *p);
   static void destruct_RPRootDumpDigiInfo(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RPRootDumpDigiInfo*)
   {
      ::RPRootDumpDigiInfo *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RPRootDumpDigiInfo));
      static ::ROOT::TGenericClassInfo 
         instance("RPRootDumpDigiInfo", "TotemAnalysis/TotemAnalysisEvent/interface/RPRootTrackInfo.h", 36,
                  typeid(::RPRootDumpDigiInfo), DefineBehavior(ptr, ptr),
                  &RPRootDumpDigiInfo_Dictionary, isa_proxy, 0,
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

   // Dictionary for non-ClassDef classes
   static TClass *RPRootDumpDigiInfo_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RPRootDumpDigiInfo*)0x0)->GetClass();
      RPRootDumpDigiInfo_TClassManip(theClass);
   return theClass;
   }

   static void RPRootDumpDigiInfo_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RPRootDumpReconstructedProton_Dictionary();
   static void RPRootDumpReconstructedProton_TClassManip(TClass*);
   static void *new_RPRootDumpReconstructedProton(void *p = 0);
   static void *newArray_RPRootDumpReconstructedProton(Long_t size, void *p);
   static void delete_RPRootDumpReconstructedProton(void *p);
   static void deleteArray_RPRootDumpReconstructedProton(void *p);
   static void destruct_RPRootDumpReconstructedProton(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RPRootDumpReconstructedProton*)
   {
      ::RPRootDumpReconstructedProton *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RPRootDumpReconstructedProton));
      static ::ROOT::TGenericClassInfo 
         instance("RPRootDumpReconstructedProton", "TotemAnalysis/TotemAnalysisEvent/interface/RPRootTrackInfo.h", 62,
                  typeid(::RPRootDumpReconstructedProton), DefineBehavior(ptr, ptr),
                  &RPRootDumpReconstructedProton_Dictionary, isa_proxy, 0,
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

   // Dictionary for non-ClassDef classes
   static TClass *RPRootDumpReconstructedProton_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RPRootDumpReconstructedProton*)0x0)->GetClass();
      RPRootDumpReconstructedProton_TClassManip(theClass);
   return theClass;
   }

   static void RPRootDumpReconstructedProton_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RPRootDumpReconstructedProtonPair_Dictionary();
   static void RPRootDumpReconstructedProtonPair_TClassManip(TClass*);
   static void *new_RPRootDumpReconstructedProtonPair(void *p = 0);
   static void *newArray_RPRootDumpReconstructedProtonPair(Long_t size, void *p);
   static void delete_RPRootDumpReconstructedProtonPair(void *p);
   static void deleteArray_RPRootDumpReconstructedProtonPair(void *p);
   static void destruct_RPRootDumpReconstructedProtonPair(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RPRootDumpReconstructedProtonPair*)
   {
      ::RPRootDumpReconstructedProtonPair *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RPRootDumpReconstructedProtonPair));
      static ::ROOT::TGenericClassInfo 
         instance("RPRootDumpReconstructedProtonPair", "TotemAnalysis/TotemAnalysisEvent/interface/RPRootTrackInfo.h", 82,
                  typeid(::RPRootDumpReconstructedProtonPair), DefineBehavior(ptr, ptr),
                  &RPRootDumpReconstructedProtonPair_Dictionary, isa_proxy, 0,
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

   // Dictionary for non-ClassDef classes
   static TClass *RPRootDumpReconstructedProtonPair_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RPRootDumpReconstructedProtonPair*)0x0)->GetClass();
      RPRootDumpReconstructedProtonPair_TClassManip(theClass);
   return theClass;
   }

   static void RPRootDumpReconstructedProtonPair_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RPRootDumpPattern_Dictionary();
   static void RPRootDumpPattern_TClassManip(TClass*);
   static void *new_RPRootDumpPattern(void *p = 0);
   static void *newArray_RPRootDumpPattern(Long_t size, void *p);
   static void delete_RPRootDumpPattern(void *p);
   static void deleteArray_RPRootDumpPattern(void *p);
   static void destruct_RPRootDumpPattern(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RPRootDumpPattern*)
   {
      ::RPRootDumpPattern *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RPRootDumpPattern));
      static ::ROOT::TGenericClassInfo 
         instance("RPRootDumpPattern", "TotemAnalysis/TotemAnalysisEvent/interface/RPRootTrackInfo.h", 114,
                  typeid(::RPRootDumpPattern), DefineBehavior(ptr, ptr),
                  &RPRootDumpPattern_Dictionary, isa_proxy, 0,
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

   // Dictionary for non-ClassDef classes
   static TClass *RPRootDumpPattern_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RPRootDumpPattern*)0x0)->GetClass();
      RPRootDumpPattern_TClassManip(theClass);
   return theClass;
   }

   static void RPRootDumpPattern_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RPRootDumpPatternInfo_Dictionary();
   static void RPRootDumpPatternInfo_TClassManip(TClass*);
   static void *new_RPRootDumpPatternInfo(void *p = 0);
   static void *newArray_RPRootDumpPatternInfo(Long_t size, void *p);
   static void delete_RPRootDumpPatternInfo(void *p);
   static void deleteArray_RPRootDumpPatternInfo(void *p);
   static void destruct_RPRootDumpPatternInfo(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RPRootDumpPatternInfo*)
   {
      ::RPRootDumpPatternInfo *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RPRootDumpPatternInfo));
      static ::ROOT::TGenericClassInfo 
         instance("RPRootDumpPatternInfo", "TotemAnalysis/TotemAnalysisEvent/interface/RPRootTrackInfo.h", 130,
                  typeid(::RPRootDumpPatternInfo), DefineBehavior(ptr, ptr),
                  &RPRootDumpPatternInfo_Dictionary, isa_proxy, 0,
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

   // Dictionary for non-ClassDef classes
   static TClass *RPRootDumpPatternInfo_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RPRootDumpPatternInfo*)0x0)->GetClass();
      RPRootDumpPatternInfo_TClassManip(theClass);
   return theClass;
   }

   static void RPRootDumpPatternInfo_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *edmcLcLWrapperlETotemRPEventgR_Dictionary();
   static void edmcLcLWrapperlETotemRPEventgR_TClassManip(TClass*);
   static void *new_edmcLcLWrapperlETotemRPEventgR(void *p = 0);
   static void *newArray_edmcLcLWrapperlETotemRPEventgR(Long_t size, void *p);
   static void delete_edmcLcLWrapperlETotemRPEventgR(void *p);
   static void deleteArray_edmcLcLWrapperlETotemRPEventgR(void *p);
   static void destruct_edmcLcLWrapperlETotemRPEventgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::edm::Wrapper<TotemRPEvent>*)
   {
      ::edm::Wrapper<TotemRPEvent> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::edm::Wrapper<TotemRPEvent>));
      static ::ROOT::TGenericClassInfo 
         instance("edm::Wrapper<TotemRPEvent>", ::edm::Wrapper<TotemRPEvent>::Class_Version(), "DataFormats/Common/interface/Wrapper.h", 25,
                  typeid(::edm::Wrapper<TotemRPEvent>), DefineBehavior(ptr, ptr),
                  &edmcLcLWrapperlETotemRPEventgR_Dictionary, isa_proxy, 0,
                  sizeof(::edm::Wrapper<TotemRPEvent>) );
      instance.SetNew(&new_edmcLcLWrapperlETotemRPEventgR);
      instance.SetNewArray(&newArray_edmcLcLWrapperlETotemRPEventgR);
      instance.SetDelete(&delete_edmcLcLWrapperlETotemRPEventgR);
      instance.SetDeleteArray(&deleteArray_edmcLcLWrapperlETotemRPEventgR);
      instance.SetDestructor(&destruct_edmcLcLWrapperlETotemRPEventgR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::edm::Wrapper<TotemRPEvent>*)
   {
      return GenerateInitInstanceLocal((::edm::Wrapper<TotemRPEvent>*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::edm::Wrapper<TotemRPEvent>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *edmcLcLWrapperlETotemRPEventgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::edm::Wrapper<TotemRPEvent>*)0x0)->GetClass();
      edmcLcLWrapperlETotemRPEventgR_TClassManip(theClass);
   return theClass;
   }

   static void edmcLcLWrapperlETotemRPEventgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *edmcLcLWrapperlERPRootDumpTrackInfogR_Dictionary();
   static void edmcLcLWrapperlERPRootDumpTrackInfogR_TClassManip(TClass*);
   static void *new_edmcLcLWrapperlERPRootDumpTrackInfogR(void *p = 0);
   static void *newArray_edmcLcLWrapperlERPRootDumpTrackInfogR(Long_t size, void *p);
   static void delete_edmcLcLWrapperlERPRootDumpTrackInfogR(void *p);
   static void deleteArray_edmcLcLWrapperlERPRootDumpTrackInfogR(void *p);
   static void destruct_edmcLcLWrapperlERPRootDumpTrackInfogR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::edm::Wrapper<RPRootDumpTrackInfo>*)
   {
      ::edm::Wrapper<RPRootDumpTrackInfo> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::edm::Wrapper<RPRootDumpTrackInfo>));
      static ::ROOT::TGenericClassInfo 
         instance("edm::Wrapper<RPRootDumpTrackInfo>", ::edm::Wrapper<RPRootDumpTrackInfo>::Class_Version(), "DataFormats/Common/interface/Wrapper.h", 25,
                  typeid(::edm::Wrapper<RPRootDumpTrackInfo>), DefineBehavior(ptr, ptr),
                  &edmcLcLWrapperlERPRootDumpTrackInfogR_Dictionary, isa_proxy, 0,
                  sizeof(::edm::Wrapper<RPRootDumpTrackInfo>) );
      instance.SetNew(&new_edmcLcLWrapperlERPRootDumpTrackInfogR);
      instance.SetNewArray(&newArray_edmcLcLWrapperlERPRootDumpTrackInfogR);
      instance.SetDelete(&delete_edmcLcLWrapperlERPRootDumpTrackInfogR);
      instance.SetDeleteArray(&deleteArray_edmcLcLWrapperlERPRootDumpTrackInfogR);
      instance.SetDestructor(&destruct_edmcLcLWrapperlERPRootDumpTrackInfogR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::edm::Wrapper<RPRootDumpTrackInfo>*)
   {
      return GenerateInitInstanceLocal((::edm::Wrapper<RPRootDumpTrackInfo>*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::edm::Wrapper<RPRootDumpTrackInfo>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *edmcLcLWrapperlERPRootDumpTrackInfogR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::edm::Wrapper<RPRootDumpTrackInfo>*)0x0)->GetClass();
      edmcLcLWrapperlERPRootDumpTrackInfogR_TClassManip(theClass);
   return theClass;
   }

   static void edmcLcLWrapperlERPRootDumpTrackInfogR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *edmcLcLWrapperlERPRootDumpDigiInfogR_Dictionary();
   static void edmcLcLWrapperlERPRootDumpDigiInfogR_TClassManip(TClass*);
   static void *new_edmcLcLWrapperlERPRootDumpDigiInfogR(void *p = 0);
   static void *newArray_edmcLcLWrapperlERPRootDumpDigiInfogR(Long_t size, void *p);
   static void delete_edmcLcLWrapperlERPRootDumpDigiInfogR(void *p);
   static void deleteArray_edmcLcLWrapperlERPRootDumpDigiInfogR(void *p);
   static void destruct_edmcLcLWrapperlERPRootDumpDigiInfogR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::edm::Wrapper<RPRootDumpDigiInfo>*)
   {
      ::edm::Wrapper<RPRootDumpDigiInfo> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::edm::Wrapper<RPRootDumpDigiInfo>));
      static ::ROOT::TGenericClassInfo 
         instance("edm::Wrapper<RPRootDumpDigiInfo>", ::edm::Wrapper<RPRootDumpDigiInfo>::Class_Version(), "DataFormats/Common/interface/Wrapper.h", 25,
                  typeid(::edm::Wrapper<RPRootDumpDigiInfo>), DefineBehavior(ptr, ptr),
                  &edmcLcLWrapperlERPRootDumpDigiInfogR_Dictionary, isa_proxy, 0,
                  sizeof(::edm::Wrapper<RPRootDumpDigiInfo>) );
      instance.SetNew(&new_edmcLcLWrapperlERPRootDumpDigiInfogR);
      instance.SetNewArray(&newArray_edmcLcLWrapperlERPRootDumpDigiInfogR);
      instance.SetDelete(&delete_edmcLcLWrapperlERPRootDumpDigiInfogR);
      instance.SetDeleteArray(&deleteArray_edmcLcLWrapperlERPRootDumpDigiInfogR);
      instance.SetDestructor(&destruct_edmcLcLWrapperlERPRootDumpDigiInfogR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::edm::Wrapper<RPRootDumpDigiInfo>*)
   {
      return GenerateInitInstanceLocal((::edm::Wrapper<RPRootDumpDigiInfo>*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::edm::Wrapper<RPRootDumpDigiInfo>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *edmcLcLWrapperlERPRootDumpDigiInfogR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::edm::Wrapper<RPRootDumpDigiInfo>*)0x0)->GetClass();
      edmcLcLWrapperlERPRootDumpDigiInfogR_TClassManip(theClass);
   return theClass;
   }

   static void edmcLcLWrapperlERPRootDumpDigiInfogR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *edmcLcLWrapperlERPRootDumpReconstructedProtongR_Dictionary();
   static void edmcLcLWrapperlERPRootDumpReconstructedProtongR_TClassManip(TClass*);
   static void *new_edmcLcLWrapperlERPRootDumpReconstructedProtongR(void *p = 0);
   static void *newArray_edmcLcLWrapperlERPRootDumpReconstructedProtongR(Long_t size, void *p);
   static void delete_edmcLcLWrapperlERPRootDumpReconstructedProtongR(void *p);
   static void deleteArray_edmcLcLWrapperlERPRootDumpReconstructedProtongR(void *p);
   static void destruct_edmcLcLWrapperlERPRootDumpReconstructedProtongR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::edm::Wrapper<RPRootDumpReconstructedProton>*)
   {
      ::edm::Wrapper<RPRootDumpReconstructedProton> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::edm::Wrapper<RPRootDumpReconstructedProton>));
      static ::ROOT::TGenericClassInfo 
         instance("edm::Wrapper<RPRootDumpReconstructedProton>", ::edm::Wrapper<RPRootDumpReconstructedProton>::Class_Version(), "DataFormats/Common/interface/Wrapper.h", 25,
                  typeid(::edm::Wrapper<RPRootDumpReconstructedProton>), DefineBehavior(ptr, ptr),
                  &edmcLcLWrapperlERPRootDumpReconstructedProtongR_Dictionary, isa_proxy, 0,
                  sizeof(::edm::Wrapper<RPRootDumpReconstructedProton>) );
      instance.SetNew(&new_edmcLcLWrapperlERPRootDumpReconstructedProtongR);
      instance.SetNewArray(&newArray_edmcLcLWrapperlERPRootDumpReconstructedProtongR);
      instance.SetDelete(&delete_edmcLcLWrapperlERPRootDumpReconstructedProtongR);
      instance.SetDeleteArray(&deleteArray_edmcLcLWrapperlERPRootDumpReconstructedProtongR);
      instance.SetDestructor(&destruct_edmcLcLWrapperlERPRootDumpReconstructedProtongR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::edm::Wrapper<RPRootDumpReconstructedProton>*)
   {
      return GenerateInitInstanceLocal((::edm::Wrapper<RPRootDumpReconstructedProton>*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::edm::Wrapper<RPRootDumpReconstructedProton>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *edmcLcLWrapperlERPRootDumpReconstructedProtongR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::edm::Wrapper<RPRootDumpReconstructedProton>*)0x0)->GetClass();
      edmcLcLWrapperlERPRootDumpReconstructedProtongR_TClassManip(theClass);
   return theClass;
   }

   static void edmcLcLWrapperlERPRootDumpReconstructedProtongR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *edmcLcLWrapperlERPRootDumpReconstructedProtonPairgR_Dictionary();
   static void edmcLcLWrapperlERPRootDumpReconstructedProtonPairgR_TClassManip(TClass*);
   static void *new_edmcLcLWrapperlERPRootDumpReconstructedProtonPairgR(void *p = 0);
   static void *newArray_edmcLcLWrapperlERPRootDumpReconstructedProtonPairgR(Long_t size, void *p);
   static void delete_edmcLcLWrapperlERPRootDumpReconstructedProtonPairgR(void *p);
   static void deleteArray_edmcLcLWrapperlERPRootDumpReconstructedProtonPairgR(void *p);
   static void destruct_edmcLcLWrapperlERPRootDumpReconstructedProtonPairgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::edm::Wrapper<RPRootDumpReconstructedProtonPair>*)
   {
      ::edm::Wrapper<RPRootDumpReconstructedProtonPair> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::edm::Wrapper<RPRootDumpReconstructedProtonPair>));
      static ::ROOT::TGenericClassInfo 
         instance("edm::Wrapper<RPRootDumpReconstructedProtonPair>", ::edm::Wrapper<RPRootDumpReconstructedProtonPair>::Class_Version(), "DataFormats/Common/interface/Wrapper.h", 25,
                  typeid(::edm::Wrapper<RPRootDumpReconstructedProtonPair>), DefineBehavior(ptr, ptr),
                  &edmcLcLWrapperlERPRootDumpReconstructedProtonPairgR_Dictionary, isa_proxy, 0,
                  sizeof(::edm::Wrapper<RPRootDumpReconstructedProtonPair>) );
      instance.SetNew(&new_edmcLcLWrapperlERPRootDumpReconstructedProtonPairgR);
      instance.SetNewArray(&newArray_edmcLcLWrapperlERPRootDumpReconstructedProtonPairgR);
      instance.SetDelete(&delete_edmcLcLWrapperlERPRootDumpReconstructedProtonPairgR);
      instance.SetDeleteArray(&deleteArray_edmcLcLWrapperlERPRootDumpReconstructedProtonPairgR);
      instance.SetDestructor(&destruct_edmcLcLWrapperlERPRootDumpReconstructedProtonPairgR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::edm::Wrapper<RPRootDumpReconstructedProtonPair>*)
   {
      return GenerateInitInstanceLocal((::edm::Wrapper<RPRootDumpReconstructedProtonPair>*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::edm::Wrapper<RPRootDumpReconstructedProtonPair>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *edmcLcLWrapperlERPRootDumpReconstructedProtonPairgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::edm::Wrapper<RPRootDumpReconstructedProtonPair>*)0x0)->GetClass();
      edmcLcLWrapperlERPRootDumpReconstructedProtonPairgR_TClassManip(theClass);
   return theClass;
   }

   static void edmcLcLWrapperlERPRootDumpReconstructedProtonPairgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *edmcLcLWrapperlERPRootDumpPatterngR_Dictionary();
   static void edmcLcLWrapperlERPRootDumpPatterngR_TClassManip(TClass*);
   static void *new_edmcLcLWrapperlERPRootDumpPatterngR(void *p = 0);
   static void *newArray_edmcLcLWrapperlERPRootDumpPatterngR(Long_t size, void *p);
   static void delete_edmcLcLWrapperlERPRootDumpPatterngR(void *p);
   static void deleteArray_edmcLcLWrapperlERPRootDumpPatterngR(void *p);
   static void destruct_edmcLcLWrapperlERPRootDumpPatterngR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::edm::Wrapper<RPRootDumpPattern>*)
   {
      ::edm::Wrapper<RPRootDumpPattern> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::edm::Wrapper<RPRootDumpPattern>));
      static ::ROOT::TGenericClassInfo 
         instance("edm::Wrapper<RPRootDumpPattern>", ::edm::Wrapper<RPRootDumpPattern>::Class_Version(), "DataFormats/Common/interface/Wrapper.h", 25,
                  typeid(::edm::Wrapper<RPRootDumpPattern>), DefineBehavior(ptr, ptr),
                  &edmcLcLWrapperlERPRootDumpPatterngR_Dictionary, isa_proxy, 0,
                  sizeof(::edm::Wrapper<RPRootDumpPattern>) );
      instance.SetNew(&new_edmcLcLWrapperlERPRootDumpPatterngR);
      instance.SetNewArray(&newArray_edmcLcLWrapperlERPRootDumpPatterngR);
      instance.SetDelete(&delete_edmcLcLWrapperlERPRootDumpPatterngR);
      instance.SetDeleteArray(&deleteArray_edmcLcLWrapperlERPRootDumpPatterngR);
      instance.SetDestructor(&destruct_edmcLcLWrapperlERPRootDumpPatterngR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::edm::Wrapper<RPRootDumpPattern>*)
   {
      return GenerateInitInstanceLocal((::edm::Wrapper<RPRootDumpPattern>*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::edm::Wrapper<RPRootDumpPattern>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *edmcLcLWrapperlERPRootDumpPatterngR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::edm::Wrapper<RPRootDumpPattern>*)0x0)->GetClass();
      edmcLcLWrapperlERPRootDumpPatterngR_TClassManip(theClass);
   return theClass;
   }

   static void edmcLcLWrapperlERPRootDumpPatterngR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *edmcLcLWrapperlERPRootDumpPatternInfogR_Dictionary();
   static void edmcLcLWrapperlERPRootDumpPatternInfogR_TClassManip(TClass*);
   static void *new_edmcLcLWrapperlERPRootDumpPatternInfogR(void *p = 0);
   static void *newArray_edmcLcLWrapperlERPRootDumpPatternInfogR(Long_t size, void *p);
   static void delete_edmcLcLWrapperlERPRootDumpPatternInfogR(void *p);
   static void deleteArray_edmcLcLWrapperlERPRootDumpPatternInfogR(void *p);
   static void destruct_edmcLcLWrapperlERPRootDumpPatternInfogR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::edm::Wrapper<RPRootDumpPatternInfo>*)
   {
      ::edm::Wrapper<RPRootDumpPatternInfo> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::edm::Wrapper<RPRootDumpPatternInfo>));
      static ::ROOT::TGenericClassInfo 
         instance("edm::Wrapper<RPRootDumpPatternInfo>", ::edm::Wrapper<RPRootDumpPatternInfo>::Class_Version(), "DataFormats/Common/interface/Wrapper.h", 25,
                  typeid(::edm::Wrapper<RPRootDumpPatternInfo>), DefineBehavior(ptr, ptr),
                  &edmcLcLWrapperlERPRootDumpPatternInfogR_Dictionary, isa_proxy, 0,
                  sizeof(::edm::Wrapper<RPRootDumpPatternInfo>) );
      instance.SetNew(&new_edmcLcLWrapperlERPRootDumpPatternInfogR);
      instance.SetNewArray(&newArray_edmcLcLWrapperlERPRootDumpPatternInfogR);
      instance.SetDelete(&delete_edmcLcLWrapperlERPRootDumpPatternInfogR);
      instance.SetDeleteArray(&deleteArray_edmcLcLWrapperlERPRootDumpPatternInfogR);
      instance.SetDestructor(&destruct_edmcLcLWrapperlERPRootDumpPatternInfogR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::edm::Wrapper<RPRootDumpPatternInfo>*)
   {
      return GenerateInitInstanceLocal((::edm::Wrapper<RPRootDumpPatternInfo>*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::edm::Wrapper<RPRootDumpPatternInfo>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *edmcLcLWrapperlERPRootDumpPatternInfogR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::edm::Wrapper<RPRootDumpPatternInfo>*)0x0)->GetClass();
      edmcLcLWrapperlERPRootDumpPatternInfogR_TClassManip(theClass);
   return theClass;
   }

   static void edmcLcLWrapperlERPRootDumpPatternInfogR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *edmcLcLWrapperlEvectorlERPRootDumpTrackInfogRsPgR_Dictionary();
   static void edmcLcLWrapperlEvectorlERPRootDumpTrackInfogRsPgR_TClassManip(TClass*);
   static void *new_edmcLcLWrapperlEvectorlERPRootDumpTrackInfogRsPgR(void *p = 0);
   static void *newArray_edmcLcLWrapperlEvectorlERPRootDumpTrackInfogRsPgR(Long_t size, void *p);
   static void delete_edmcLcLWrapperlEvectorlERPRootDumpTrackInfogRsPgR(void *p);
   static void deleteArray_edmcLcLWrapperlEvectorlERPRootDumpTrackInfogRsPgR(void *p);
   static void destruct_edmcLcLWrapperlEvectorlERPRootDumpTrackInfogRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::edm::Wrapper<vector<RPRootDumpTrackInfo> >*)
   {
      ::edm::Wrapper<vector<RPRootDumpTrackInfo> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::edm::Wrapper<vector<RPRootDumpTrackInfo> >));
      static ::ROOT::TGenericClassInfo 
         instance("edm::Wrapper<vector<RPRootDumpTrackInfo> >", ::edm::Wrapper<vector<RPRootDumpTrackInfo> >::Class_Version(), "DataFormats/Common/interface/Wrapper.h", 25,
                  typeid(::edm::Wrapper<vector<RPRootDumpTrackInfo> >), DefineBehavior(ptr, ptr),
                  &edmcLcLWrapperlEvectorlERPRootDumpTrackInfogRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(::edm::Wrapper<vector<RPRootDumpTrackInfo> >) );
      instance.SetNew(&new_edmcLcLWrapperlEvectorlERPRootDumpTrackInfogRsPgR);
      instance.SetNewArray(&newArray_edmcLcLWrapperlEvectorlERPRootDumpTrackInfogRsPgR);
      instance.SetDelete(&delete_edmcLcLWrapperlEvectorlERPRootDumpTrackInfogRsPgR);
      instance.SetDeleteArray(&deleteArray_edmcLcLWrapperlEvectorlERPRootDumpTrackInfogRsPgR);
      instance.SetDestructor(&destruct_edmcLcLWrapperlEvectorlERPRootDumpTrackInfogRsPgR);

      ROOT::AddClassAlternate("edm::Wrapper<vector<RPRootDumpTrackInfo> >","edm::Wrapper<std::vector<RPRootDumpTrackInfo> >");
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::edm::Wrapper<vector<RPRootDumpTrackInfo> >*)
   {
      return GenerateInitInstanceLocal((::edm::Wrapper<vector<RPRootDumpTrackInfo> >*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::edm::Wrapper<vector<RPRootDumpTrackInfo> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *edmcLcLWrapperlEvectorlERPRootDumpTrackInfogRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::edm::Wrapper<vector<RPRootDumpTrackInfo> >*)0x0)->GetClass();
      edmcLcLWrapperlEvectorlERPRootDumpTrackInfogRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void edmcLcLWrapperlEvectorlERPRootDumpTrackInfogRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *edmcLcLWrapperlEvectorlERPRootDumpDigiInfogRsPgR_Dictionary();
   static void edmcLcLWrapperlEvectorlERPRootDumpDigiInfogRsPgR_TClassManip(TClass*);
   static void *new_edmcLcLWrapperlEvectorlERPRootDumpDigiInfogRsPgR(void *p = 0);
   static void *newArray_edmcLcLWrapperlEvectorlERPRootDumpDigiInfogRsPgR(Long_t size, void *p);
   static void delete_edmcLcLWrapperlEvectorlERPRootDumpDigiInfogRsPgR(void *p);
   static void deleteArray_edmcLcLWrapperlEvectorlERPRootDumpDigiInfogRsPgR(void *p);
   static void destruct_edmcLcLWrapperlEvectorlERPRootDumpDigiInfogRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::edm::Wrapper<vector<RPRootDumpDigiInfo> >*)
   {
      ::edm::Wrapper<vector<RPRootDumpDigiInfo> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::edm::Wrapper<vector<RPRootDumpDigiInfo> >));
      static ::ROOT::TGenericClassInfo 
         instance("edm::Wrapper<vector<RPRootDumpDigiInfo> >", ::edm::Wrapper<vector<RPRootDumpDigiInfo> >::Class_Version(), "DataFormats/Common/interface/Wrapper.h", 25,
                  typeid(::edm::Wrapper<vector<RPRootDumpDigiInfo> >), DefineBehavior(ptr, ptr),
                  &edmcLcLWrapperlEvectorlERPRootDumpDigiInfogRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(::edm::Wrapper<vector<RPRootDumpDigiInfo> >) );
      instance.SetNew(&new_edmcLcLWrapperlEvectorlERPRootDumpDigiInfogRsPgR);
      instance.SetNewArray(&newArray_edmcLcLWrapperlEvectorlERPRootDumpDigiInfogRsPgR);
      instance.SetDelete(&delete_edmcLcLWrapperlEvectorlERPRootDumpDigiInfogRsPgR);
      instance.SetDeleteArray(&deleteArray_edmcLcLWrapperlEvectorlERPRootDumpDigiInfogRsPgR);
      instance.SetDestructor(&destruct_edmcLcLWrapperlEvectorlERPRootDumpDigiInfogRsPgR);

      ROOT::AddClassAlternate("edm::Wrapper<vector<RPRootDumpDigiInfo> >","edm::Wrapper<std::vector<RPRootDumpDigiInfo> >");
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::edm::Wrapper<vector<RPRootDumpDigiInfo> >*)
   {
      return GenerateInitInstanceLocal((::edm::Wrapper<vector<RPRootDumpDigiInfo> >*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::edm::Wrapper<vector<RPRootDumpDigiInfo> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *edmcLcLWrapperlEvectorlERPRootDumpDigiInfogRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::edm::Wrapper<vector<RPRootDumpDigiInfo> >*)0x0)->GetClass();
      edmcLcLWrapperlEvectorlERPRootDumpDigiInfogRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void edmcLcLWrapperlEvectorlERPRootDumpDigiInfogRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *edmcLcLWrapperlEvectorlERPRootDumpPatternInfogRsPgR_Dictionary();
   static void edmcLcLWrapperlEvectorlERPRootDumpPatternInfogRsPgR_TClassManip(TClass*);
   static void *new_edmcLcLWrapperlEvectorlERPRootDumpPatternInfogRsPgR(void *p = 0);
   static void *newArray_edmcLcLWrapperlEvectorlERPRootDumpPatternInfogRsPgR(Long_t size, void *p);
   static void delete_edmcLcLWrapperlEvectorlERPRootDumpPatternInfogRsPgR(void *p);
   static void deleteArray_edmcLcLWrapperlEvectorlERPRootDumpPatternInfogRsPgR(void *p);
   static void destruct_edmcLcLWrapperlEvectorlERPRootDumpPatternInfogRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::edm::Wrapper<vector<RPRootDumpPatternInfo> >*)
   {
      ::edm::Wrapper<vector<RPRootDumpPatternInfo> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::edm::Wrapper<vector<RPRootDumpPatternInfo> >));
      static ::ROOT::TGenericClassInfo 
         instance("edm::Wrapper<vector<RPRootDumpPatternInfo> >", ::edm::Wrapper<vector<RPRootDumpPatternInfo> >::Class_Version(), "DataFormats/Common/interface/Wrapper.h", 25,
                  typeid(::edm::Wrapper<vector<RPRootDumpPatternInfo> >), DefineBehavior(ptr, ptr),
                  &edmcLcLWrapperlEvectorlERPRootDumpPatternInfogRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(::edm::Wrapper<vector<RPRootDumpPatternInfo> >) );
      instance.SetNew(&new_edmcLcLWrapperlEvectorlERPRootDumpPatternInfogRsPgR);
      instance.SetNewArray(&newArray_edmcLcLWrapperlEvectorlERPRootDumpPatternInfogRsPgR);
      instance.SetDelete(&delete_edmcLcLWrapperlEvectorlERPRootDumpPatternInfogRsPgR);
      instance.SetDeleteArray(&deleteArray_edmcLcLWrapperlEvectorlERPRootDumpPatternInfogRsPgR);
      instance.SetDestructor(&destruct_edmcLcLWrapperlEvectorlERPRootDumpPatternInfogRsPgR);

      ROOT::AddClassAlternate("edm::Wrapper<vector<RPRootDumpPatternInfo> >","edm::Wrapper<std::vector<RPRootDumpPatternInfo> >");
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::edm::Wrapper<vector<RPRootDumpPatternInfo> >*)
   {
      return GenerateInitInstanceLocal((::edm::Wrapper<vector<RPRootDumpPatternInfo> >*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::edm::Wrapper<vector<RPRootDumpPatternInfo> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *edmcLcLWrapperlEvectorlERPRootDumpPatternInfogRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::edm::Wrapper<vector<RPRootDumpPatternInfo> >*)0x0)->GetClass();
      edmcLcLWrapperlEvectorlERPRootDumpPatternInfogRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void edmcLcLWrapperlEvectorlERPRootDumpPatternInfogRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *edmcLcLWrapperlEvectorlERPRootDumpReconstructedProtongRsPgR_Dictionary();
   static void edmcLcLWrapperlEvectorlERPRootDumpReconstructedProtongRsPgR_TClassManip(TClass*);
   static void *new_edmcLcLWrapperlEvectorlERPRootDumpReconstructedProtongRsPgR(void *p = 0);
   static void *newArray_edmcLcLWrapperlEvectorlERPRootDumpReconstructedProtongRsPgR(Long_t size, void *p);
   static void delete_edmcLcLWrapperlEvectorlERPRootDumpReconstructedProtongRsPgR(void *p);
   static void deleteArray_edmcLcLWrapperlEvectorlERPRootDumpReconstructedProtongRsPgR(void *p);
   static void destruct_edmcLcLWrapperlEvectorlERPRootDumpReconstructedProtongRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::edm::Wrapper<vector<RPRootDumpReconstructedProton> >*)
   {
      ::edm::Wrapper<vector<RPRootDumpReconstructedProton> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::edm::Wrapper<vector<RPRootDumpReconstructedProton> >));
      static ::ROOT::TGenericClassInfo 
         instance("edm::Wrapper<vector<RPRootDumpReconstructedProton> >", ::edm::Wrapper<vector<RPRootDumpReconstructedProton> >::Class_Version(), "DataFormats/Common/interface/Wrapper.h", 25,
                  typeid(::edm::Wrapper<vector<RPRootDumpReconstructedProton> >), DefineBehavior(ptr, ptr),
                  &edmcLcLWrapperlEvectorlERPRootDumpReconstructedProtongRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(::edm::Wrapper<vector<RPRootDumpReconstructedProton> >) );
      instance.SetNew(&new_edmcLcLWrapperlEvectorlERPRootDumpReconstructedProtongRsPgR);
      instance.SetNewArray(&newArray_edmcLcLWrapperlEvectorlERPRootDumpReconstructedProtongRsPgR);
      instance.SetDelete(&delete_edmcLcLWrapperlEvectorlERPRootDumpReconstructedProtongRsPgR);
      instance.SetDeleteArray(&deleteArray_edmcLcLWrapperlEvectorlERPRootDumpReconstructedProtongRsPgR);
      instance.SetDestructor(&destruct_edmcLcLWrapperlEvectorlERPRootDumpReconstructedProtongRsPgR);

      ROOT::AddClassAlternate("edm::Wrapper<vector<RPRootDumpReconstructedProton> >","edm::Wrapper<std::vector<RPRootDumpReconstructedProton> >");
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::edm::Wrapper<vector<RPRootDumpReconstructedProton> >*)
   {
      return GenerateInitInstanceLocal((::edm::Wrapper<vector<RPRootDumpReconstructedProton> >*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::edm::Wrapper<vector<RPRootDumpReconstructedProton> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *edmcLcLWrapperlEvectorlERPRootDumpReconstructedProtongRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::edm::Wrapper<vector<RPRootDumpReconstructedProton> >*)0x0)->GetClass();
      edmcLcLWrapperlEvectorlERPRootDumpReconstructedProtongRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void edmcLcLWrapperlEvectorlERPRootDumpReconstructedProtongRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpTrackInfogRsPgR_Dictionary();
   static void edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpTrackInfogRsPgR_TClassManip(TClass*);
   static void *new_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpTrackInfogRsPgR(void *p = 0);
   static void *newArray_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpTrackInfogRsPgR(Long_t size, void *p);
   static void delete_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpTrackInfogRsPgR(void *p);
   static void deleteArray_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpTrackInfogRsPgR(void *p);
   static void destruct_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpTrackInfogRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::edm::Wrapper<map<unsigned int,RPRootDumpTrackInfo> >*)
   {
      ::edm::Wrapper<map<unsigned int,RPRootDumpTrackInfo> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::edm::Wrapper<map<unsigned int,RPRootDumpTrackInfo> >));
      static ::ROOT::TGenericClassInfo 
         instance("edm::Wrapper<map<unsigned int,RPRootDumpTrackInfo> >", ::edm::Wrapper<map<unsigned int,RPRootDumpTrackInfo> >::Class_Version(), "DataFormats/Common/interface/Wrapper.h", 25,
                  typeid(::edm::Wrapper<map<unsigned int,RPRootDumpTrackInfo> >), DefineBehavior(ptr, ptr),
                  &edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpTrackInfogRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(::edm::Wrapper<map<unsigned int,RPRootDumpTrackInfo> >) );
      instance.SetNew(&new_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpTrackInfogRsPgR);
      instance.SetNewArray(&newArray_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpTrackInfogRsPgR);
      instance.SetDelete(&delete_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpTrackInfogRsPgR);
      instance.SetDeleteArray(&deleteArray_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpTrackInfogRsPgR);
      instance.SetDestructor(&destruct_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpTrackInfogRsPgR);

      ROOT::AddClassAlternate("edm::Wrapper<map<unsigned int,RPRootDumpTrackInfo> >","edm::Wrapper<std::map<unsigned int,RPRootDumpTrackInfo> >");
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::edm::Wrapper<map<unsigned int,RPRootDumpTrackInfo> >*)
   {
      return GenerateInitInstanceLocal((::edm::Wrapper<map<unsigned int,RPRootDumpTrackInfo> >*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::edm::Wrapper<map<unsigned int,RPRootDumpTrackInfo> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpTrackInfogRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::edm::Wrapper<map<unsigned int,RPRootDumpTrackInfo> >*)0x0)->GetClass();
      edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpTrackInfogRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpTrackInfogRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpDigiInfogRsPgR_Dictionary();
   static void edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpDigiInfogRsPgR_TClassManip(TClass*);
   static void *new_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpDigiInfogRsPgR(void *p = 0);
   static void *newArray_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpDigiInfogRsPgR(Long_t size, void *p);
   static void delete_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpDigiInfogRsPgR(void *p);
   static void deleteArray_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpDigiInfogRsPgR(void *p);
   static void destruct_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpDigiInfogRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::edm::Wrapper<map<unsigned int,RPRootDumpDigiInfo> >*)
   {
      ::edm::Wrapper<map<unsigned int,RPRootDumpDigiInfo> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::edm::Wrapper<map<unsigned int,RPRootDumpDigiInfo> >));
      static ::ROOT::TGenericClassInfo 
         instance("edm::Wrapper<map<unsigned int,RPRootDumpDigiInfo> >", ::edm::Wrapper<map<unsigned int,RPRootDumpDigiInfo> >::Class_Version(), "DataFormats/Common/interface/Wrapper.h", 25,
                  typeid(::edm::Wrapper<map<unsigned int,RPRootDumpDigiInfo> >), DefineBehavior(ptr, ptr),
                  &edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpDigiInfogRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(::edm::Wrapper<map<unsigned int,RPRootDumpDigiInfo> >) );
      instance.SetNew(&new_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpDigiInfogRsPgR);
      instance.SetNewArray(&newArray_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpDigiInfogRsPgR);
      instance.SetDelete(&delete_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpDigiInfogRsPgR);
      instance.SetDeleteArray(&deleteArray_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpDigiInfogRsPgR);
      instance.SetDestructor(&destruct_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpDigiInfogRsPgR);

      ROOT::AddClassAlternate("edm::Wrapper<map<unsigned int,RPRootDumpDigiInfo> >","edm::Wrapper<std::map<unsigned int,RPRootDumpDigiInfo> >");
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::edm::Wrapper<map<unsigned int,RPRootDumpDigiInfo> >*)
   {
      return GenerateInitInstanceLocal((::edm::Wrapper<map<unsigned int,RPRootDumpDigiInfo> >*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::edm::Wrapper<map<unsigned int,RPRootDumpDigiInfo> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpDigiInfogRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::edm::Wrapper<map<unsigned int,RPRootDumpDigiInfo> >*)0x0)->GetClass();
      edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpDigiInfogRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpDigiInfogRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpPatternInfogRsPgR_Dictionary();
   static void edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpPatternInfogRsPgR_TClassManip(TClass*);
   static void *new_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpPatternInfogRsPgR(void *p = 0);
   static void *newArray_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpPatternInfogRsPgR(Long_t size, void *p);
   static void delete_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpPatternInfogRsPgR(void *p);
   static void deleteArray_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpPatternInfogRsPgR(void *p);
   static void destruct_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpPatternInfogRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::edm::Wrapper<map<unsigned int,RPRootDumpPatternInfo> >*)
   {
      ::edm::Wrapper<map<unsigned int,RPRootDumpPatternInfo> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::edm::Wrapper<map<unsigned int,RPRootDumpPatternInfo> >));
      static ::ROOT::TGenericClassInfo 
         instance("edm::Wrapper<map<unsigned int,RPRootDumpPatternInfo> >", ::edm::Wrapper<map<unsigned int,RPRootDumpPatternInfo> >::Class_Version(), "DataFormats/Common/interface/Wrapper.h", 25,
                  typeid(::edm::Wrapper<map<unsigned int,RPRootDumpPatternInfo> >), DefineBehavior(ptr, ptr),
                  &edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpPatternInfogRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(::edm::Wrapper<map<unsigned int,RPRootDumpPatternInfo> >) );
      instance.SetNew(&new_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpPatternInfogRsPgR);
      instance.SetNewArray(&newArray_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpPatternInfogRsPgR);
      instance.SetDelete(&delete_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpPatternInfogRsPgR);
      instance.SetDeleteArray(&deleteArray_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpPatternInfogRsPgR);
      instance.SetDestructor(&destruct_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpPatternInfogRsPgR);

      ROOT::AddClassAlternate("edm::Wrapper<map<unsigned int,RPRootDumpPatternInfo> >","edm::Wrapper<std::map<unsigned int,RPRootDumpPatternInfo> >");
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::edm::Wrapper<map<unsigned int,RPRootDumpPatternInfo> >*)
   {
      return GenerateInitInstanceLocal((::edm::Wrapper<map<unsigned int,RPRootDumpPatternInfo> >*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::edm::Wrapper<map<unsigned int,RPRootDumpPatternInfo> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpPatternInfogRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::edm::Wrapper<map<unsigned int,RPRootDumpPatternInfo> >*)0x0)->GetClass();
      edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpPatternInfogRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpPatternInfogRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *edmcLcLWrapperlEmaplEunsignedsPintcOvectorlERPRootDumpTrackInfogRsPgRsPgR_Dictionary();
   static void edmcLcLWrapperlEmaplEunsignedsPintcOvectorlERPRootDumpTrackInfogRsPgRsPgR_TClassManip(TClass*);
   static void *new_edmcLcLWrapperlEmaplEunsignedsPintcOvectorlERPRootDumpTrackInfogRsPgRsPgR(void *p = 0);
   static void *newArray_edmcLcLWrapperlEmaplEunsignedsPintcOvectorlERPRootDumpTrackInfogRsPgRsPgR(Long_t size, void *p);
   static void delete_edmcLcLWrapperlEmaplEunsignedsPintcOvectorlERPRootDumpTrackInfogRsPgRsPgR(void *p);
   static void deleteArray_edmcLcLWrapperlEmaplEunsignedsPintcOvectorlERPRootDumpTrackInfogRsPgRsPgR(void *p);
   static void destruct_edmcLcLWrapperlEmaplEunsignedsPintcOvectorlERPRootDumpTrackInfogRsPgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::edm::Wrapper<map<unsigned int,vector<RPRootDumpTrackInfo> > >*)
   {
      ::edm::Wrapper<map<unsigned int,vector<RPRootDumpTrackInfo> > > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::edm::Wrapper<map<unsigned int,vector<RPRootDumpTrackInfo> > >));
      static ::ROOT::TGenericClassInfo 
         instance("edm::Wrapper<map<unsigned int,vector<RPRootDumpTrackInfo> > >", ::edm::Wrapper<map<unsigned int,vector<RPRootDumpTrackInfo> > >::Class_Version(), "DataFormats/Common/interface/Wrapper.h", 25,
                  typeid(::edm::Wrapper<map<unsigned int,vector<RPRootDumpTrackInfo> > >), DefineBehavior(ptr, ptr),
                  &edmcLcLWrapperlEmaplEunsignedsPintcOvectorlERPRootDumpTrackInfogRsPgRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(::edm::Wrapper<map<unsigned int,vector<RPRootDumpTrackInfo> > >) );
      instance.SetNew(&new_edmcLcLWrapperlEmaplEunsignedsPintcOvectorlERPRootDumpTrackInfogRsPgRsPgR);
      instance.SetNewArray(&newArray_edmcLcLWrapperlEmaplEunsignedsPintcOvectorlERPRootDumpTrackInfogRsPgRsPgR);
      instance.SetDelete(&delete_edmcLcLWrapperlEmaplEunsignedsPintcOvectorlERPRootDumpTrackInfogRsPgRsPgR);
      instance.SetDeleteArray(&deleteArray_edmcLcLWrapperlEmaplEunsignedsPintcOvectorlERPRootDumpTrackInfogRsPgRsPgR);
      instance.SetDestructor(&destruct_edmcLcLWrapperlEmaplEunsignedsPintcOvectorlERPRootDumpTrackInfogRsPgRsPgR);

      ROOT::AddClassAlternate("edm::Wrapper<map<unsigned int,vector<RPRootDumpTrackInfo> > >","edm::Wrapper<std::map<unsigned int,std::vector<RPRootDumpTrackInfo> > >");
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::edm::Wrapper<map<unsigned int,vector<RPRootDumpTrackInfo> > >*)
   {
      return GenerateInitInstanceLocal((::edm::Wrapper<map<unsigned int,vector<RPRootDumpTrackInfo> > >*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::edm::Wrapper<map<unsigned int,vector<RPRootDumpTrackInfo> > >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *edmcLcLWrapperlEmaplEunsignedsPintcOvectorlERPRootDumpTrackInfogRsPgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::edm::Wrapper<map<unsigned int,vector<RPRootDumpTrackInfo> > >*)0x0)->GetClass();
      edmcLcLWrapperlEmaplEunsignedsPintcOvectorlERPRootDumpTrackInfogRsPgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void edmcLcLWrapperlEmaplEunsignedsPintcOvectorlERPRootDumpTrackInfogRsPgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpReconstructedProtongRsPgR_Dictionary();
   static void edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpReconstructedProtongRsPgR_TClassManip(TClass*);
   static void *new_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpReconstructedProtongRsPgR(void *p = 0);
   static void *newArray_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpReconstructedProtongRsPgR(Long_t size, void *p);
   static void delete_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpReconstructedProtongRsPgR(void *p);
   static void deleteArray_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpReconstructedProtongRsPgR(void *p);
   static void destruct_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpReconstructedProtongRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::edm::Wrapper<map<unsigned int,RPRootDumpReconstructedProton> >*)
   {
      ::edm::Wrapper<map<unsigned int,RPRootDumpReconstructedProton> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::edm::Wrapper<map<unsigned int,RPRootDumpReconstructedProton> >));
      static ::ROOT::TGenericClassInfo 
         instance("edm::Wrapper<map<unsigned int,RPRootDumpReconstructedProton> >", ::edm::Wrapper<map<unsigned int,RPRootDumpReconstructedProton> >::Class_Version(), "DataFormats/Common/interface/Wrapper.h", 25,
                  typeid(::edm::Wrapper<map<unsigned int,RPRootDumpReconstructedProton> >), DefineBehavior(ptr, ptr),
                  &edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpReconstructedProtongRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(::edm::Wrapper<map<unsigned int,RPRootDumpReconstructedProton> >) );
      instance.SetNew(&new_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpReconstructedProtongRsPgR);
      instance.SetNewArray(&newArray_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpReconstructedProtongRsPgR);
      instance.SetDelete(&delete_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpReconstructedProtongRsPgR);
      instance.SetDeleteArray(&deleteArray_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpReconstructedProtongRsPgR);
      instance.SetDestructor(&destruct_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpReconstructedProtongRsPgR);

      ROOT::AddClassAlternate("edm::Wrapper<map<unsigned int,RPRootDumpReconstructedProton> >","edm::Wrapper<std::map<unsigned int,RPRootDumpReconstructedProton> >");
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::edm::Wrapper<map<unsigned int,RPRootDumpReconstructedProton> >*)
   {
      return GenerateInitInstanceLocal((::edm::Wrapper<map<unsigned int,RPRootDumpReconstructedProton> >*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::edm::Wrapper<map<unsigned int,RPRootDumpReconstructedProton> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpReconstructedProtongRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::edm::Wrapper<map<unsigned int,RPRootDumpReconstructedProton> >*)0x0)->GetClass();
      edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpReconstructedProtongRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpReconstructedProtongRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_TotemRPEvent(void *p) {
      return  p ? new(p) ::TotemRPEvent : new ::TotemRPEvent;
   }
   static void *newArray_TotemRPEvent(Long_t nElements, void *p) {
      return p ? new(p) ::TotemRPEvent[nElements] : new ::TotemRPEvent[nElements];
   }
   // Wrapper around operator delete
   static void delete_TotemRPEvent(void *p) {
      delete ((::TotemRPEvent*)p);
   }
   static void deleteArray_TotemRPEvent(void *p) {
      delete [] ((::TotemRPEvent*)p);
   }
   static void destruct_TotemRPEvent(void *p) {
      typedef ::TotemRPEvent current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TotemRPEvent

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

namespace ROOT {
   // Wrappers around operator new
   static void *new_edmcLcLWrapperlETotemRPEventgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::edm::Wrapper<TotemRPEvent> : new ::edm::Wrapper<TotemRPEvent>;
   }
   static void *newArray_edmcLcLWrapperlETotemRPEventgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::edm::Wrapper<TotemRPEvent>[nElements] : new ::edm::Wrapper<TotemRPEvent>[nElements];
   }
   // Wrapper around operator delete
   static void delete_edmcLcLWrapperlETotemRPEventgR(void *p) {
      delete ((::edm::Wrapper<TotemRPEvent>*)p);
   }
   static void deleteArray_edmcLcLWrapperlETotemRPEventgR(void *p) {
      delete [] ((::edm::Wrapper<TotemRPEvent>*)p);
   }
   static void destruct_edmcLcLWrapperlETotemRPEventgR(void *p) {
      typedef ::edm::Wrapper<TotemRPEvent> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::edm::Wrapper<TotemRPEvent>

namespace ROOT {
   // Wrappers around operator new
   static void *new_edmcLcLWrapperlERPRootDumpTrackInfogR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::edm::Wrapper<RPRootDumpTrackInfo> : new ::edm::Wrapper<RPRootDumpTrackInfo>;
   }
   static void *newArray_edmcLcLWrapperlERPRootDumpTrackInfogR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::edm::Wrapper<RPRootDumpTrackInfo>[nElements] : new ::edm::Wrapper<RPRootDumpTrackInfo>[nElements];
   }
   // Wrapper around operator delete
   static void delete_edmcLcLWrapperlERPRootDumpTrackInfogR(void *p) {
      delete ((::edm::Wrapper<RPRootDumpTrackInfo>*)p);
   }
   static void deleteArray_edmcLcLWrapperlERPRootDumpTrackInfogR(void *p) {
      delete [] ((::edm::Wrapper<RPRootDumpTrackInfo>*)p);
   }
   static void destruct_edmcLcLWrapperlERPRootDumpTrackInfogR(void *p) {
      typedef ::edm::Wrapper<RPRootDumpTrackInfo> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::edm::Wrapper<RPRootDumpTrackInfo>

namespace ROOT {
   // Wrappers around operator new
   static void *new_edmcLcLWrapperlERPRootDumpDigiInfogR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::edm::Wrapper<RPRootDumpDigiInfo> : new ::edm::Wrapper<RPRootDumpDigiInfo>;
   }
   static void *newArray_edmcLcLWrapperlERPRootDumpDigiInfogR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::edm::Wrapper<RPRootDumpDigiInfo>[nElements] : new ::edm::Wrapper<RPRootDumpDigiInfo>[nElements];
   }
   // Wrapper around operator delete
   static void delete_edmcLcLWrapperlERPRootDumpDigiInfogR(void *p) {
      delete ((::edm::Wrapper<RPRootDumpDigiInfo>*)p);
   }
   static void deleteArray_edmcLcLWrapperlERPRootDumpDigiInfogR(void *p) {
      delete [] ((::edm::Wrapper<RPRootDumpDigiInfo>*)p);
   }
   static void destruct_edmcLcLWrapperlERPRootDumpDigiInfogR(void *p) {
      typedef ::edm::Wrapper<RPRootDumpDigiInfo> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::edm::Wrapper<RPRootDumpDigiInfo>

namespace ROOT {
   // Wrappers around operator new
   static void *new_edmcLcLWrapperlERPRootDumpReconstructedProtongR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::edm::Wrapper<RPRootDumpReconstructedProton> : new ::edm::Wrapper<RPRootDumpReconstructedProton>;
   }
   static void *newArray_edmcLcLWrapperlERPRootDumpReconstructedProtongR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::edm::Wrapper<RPRootDumpReconstructedProton>[nElements] : new ::edm::Wrapper<RPRootDumpReconstructedProton>[nElements];
   }
   // Wrapper around operator delete
   static void delete_edmcLcLWrapperlERPRootDumpReconstructedProtongR(void *p) {
      delete ((::edm::Wrapper<RPRootDumpReconstructedProton>*)p);
   }
   static void deleteArray_edmcLcLWrapperlERPRootDumpReconstructedProtongR(void *p) {
      delete [] ((::edm::Wrapper<RPRootDumpReconstructedProton>*)p);
   }
   static void destruct_edmcLcLWrapperlERPRootDumpReconstructedProtongR(void *p) {
      typedef ::edm::Wrapper<RPRootDumpReconstructedProton> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::edm::Wrapper<RPRootDumpReconstructedProton>

namespace ROOT {
   // Wrappers around operator new
   static void *new_edmcLcLWrapperlERPRootDumpReconstructedProtonPairgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::edm::Wrapper<RPRootDumpReconstructedProtonPair> : new ::edm::Wrapper<RPRootDumpReconstructedProtonPair>;
   }
   static void *newArray_edmcLcLWrapperlERPRootDumpReconstructedProtonPairgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::edm::Wrapper<RPRootDumpReconstructedProtonPair>[nElements] : new ::edm::Wrapper<RPRootDumpReconstructedProtonPair>[nElements];
   }
   // Wrapper around operator delete
   static void delete_edmcLcLWrapperlERPRootDumpReconstructedProtonPairgR(void *p) {
      delete ((::edm::Wrapper<RPRootDumpReconstructedProtonPair>*)p);
   }
   static void deleteArray_edmcLcLWrapperlERPRootDumpReconstructedProtonPairgR(void *p) {
      delete [] ((::edm::Wrapper<RPRootDumpReconstructedProtonPair>*)p);
   }
   static void destruct_edmcLcLWrapperlERPRootDumpReconstructedProtonPairgR(void *p) {
      typedef ::edm::Wrapper<RPRootDumpReconstructedProtonPair> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::edm::Wrapper<RPRootDumpReconstructedProtonPair>

namespace ROOT {
   // Wrappers around operator new
   static void *new_edmcLcLWrapperlERPRootDumpPatterngR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::edm::Wrapper<RPRootDumpPattern> : new ::edm::Wrapper<RPRootDumpPattern>;
   }
   static void *newArray_edmcLcLWrapperlERPRootDumpPatterngR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::edm::Wrapper<RPRootDumpPattern>[nElements] : new ::edm::Wrapper<RPRootDumpPattern>[nElements];
   }
   // Wrapper around operator delete
   static void delete_edmcLcLWrapperlERPRootDumpPatterngR(void *p) {
      delete ((::edm::Wrapper<RPRootDumpPattern>*)p);
   }
   static void deleteArray_edmcLcLWrapperlERPRootDumpPatterngR(void *p) {
      delete [] ((::edm::Wrapper<RPRootDumpPattern>*)p);
   }
   static void destruct_edmcLcLWrapperlERPRootDumpPatterngR(void *p) {
      typedef ::edm::Wrapper<RPRootDumpPattern> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::edm::Wrapper<RPRootDumpPattern>

namespace ROOT {
   // Wrappers around operator new
   static void *new_edmcLcLWrapperlERPRootDumpPatternInfogR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::edm::Wrapper<RPRootDumpPatternInfo> : new ::edm::Wrapper<RPRootDumpPatternInfo>;
   }
   static void *newArray_edmcLcLWrapperlERPRootDumpPatternInfogR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::edm::Wrapper<RPRootDumpPatternInfo>[nElements] : new ::edm::Wrapper<RPRootDumpPatternInfo>[nElements];
   }
   // Wrapper around operator delete
   static void delete_edmcLcLWrapperlERPRootDumpPatternInfogR(void *p) {
      delete ((::edm::Wrapper<RPRootDumpPatternInfo>*)p);
   }
   static void deleteArray_edmcLcLWrapperlERPRootDumpPatternInfogR(void *p) {
      delete [] ((::edm::Wrapper<RPRootDumpPatternInfo>*)p);
   }
   static void destruct_edmcLcLWrapperlERPRootDumpPatternInfogR(void *p) {
      typedef ::edm::Wrapper<RPRootDumpPatternInfo> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::edm::Wrapper<RPRootDumpPatternInfo>

namespace ROOT {
   // Wrappers around operator new
   static void *new_edmcLcLWrapperlEvectorlERPRootDumpTrackInfogRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::edm::Wrapper<vector<RPRootDumpTrackInfo> > : new ::edm::Wrapper<vector<RPRootDumpTrackInfo> >;
   }
   static void *newArray_edmcLcLWrapperlEvectorlERPRootDumpTrackInfogRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::edm::Wrapper<vector<RPRootDumpTrackInfo> >[nElements] : new ::edm::Wrapper<vector<RPRootDumpTrackInfo> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_edmcLcLWrapperlEvectorlERPRootDumpTrackInfogRsPgR(void *p) {
      delete ((::edm::Wrapper<vector<RPRootDumpTrackInfo> >*)p);
   }
   static void deleteArray_edmcLcLWrapperlEvectorlERPRootDumpTrackInfogRsPgR(void *p) {
      delete [] ((::edm::Wrapper<vector<RPRootDumpTrackInfo> >*)p);
   }
   static void destruct_edmcLcLWrapperlEvectorlERPRootDumpTrackInfogRsPgR(void *p) {
      typedef ::edm::Wrapper<vector<RPRootDumpTrackInfo> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::edm::Wrapper<vector<RPRootDumpTrackInfo> >

namespace ROOT {
   // Wrappers around operator new
   static void *new_edmcLcLWrapperlEvectorlERPRootDumpDigiInfogRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::edm::Wrapper<vector<RPRootDumpDigiInfo> > : new ::edm::Wrapper<vector<RPRootDumpDigiInfo> >;
   }
   static void *newArray_edmcLcLWrapperlEvectorlERPRootDumpDigiInfogRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::edm::Wrapper<vector<RPRootDumpDigiInfo> >[nElements] : new ::edm::Wrapper<vector<RPRootDumpDigiInfo> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_edmcLcLWrapperlEvectorlERPRootDumpDigiInfogRsPgR(void *p) {
      delete ((::edm::Wrapper<vector<RPRootDumpDigiInfo> >*)p);
   }
   static void deleteArray_edmcLcLWrapperlEvectorlERPRootDumpDigiInfogRsPgR(void *p) {
      delete [] ((::edm::Wrapper<vector<RPRootDumpDigiInfo> >*)p);
   }
   static void destruct_edmcLcLWrapperlEvectorlERPRootDumpDigiInfogRsPgR(void *p) {
      typedef ::edm::Wrapper<vector<RPRootDumpDigiInfo> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::edm::Wrapper<vector<RPRootDumpDigiInfo> >

namespace ROOT {
   // Wrappers around operator new
   static void *new_edmcLcLWrapperlEvectorlERPRootDumpPatternInfogRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::edm::Wrapper<vector<RPRootDumpPatternInfo> > : new ::edm::Wrapper<vector<RPRootDumpPatternInfo> >;
   }
   static void *newArray_edmcLcLWrapperlEvectorlERPRootDumpPatternInfogRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::edm::Wrapper<vector<RPRootDumpPatternInfo> >[nElements] : new ::edm::Wrapper<vector<RPRootDumpPatternInfo> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_edmcLcLWrapperlEvectorlERPRootDumpPatternInfogRsPgR(void *p) {
      delete ((::edm::Wrapper<vector<RPRootDumpPatternInfo> >*)p);
   }
   static void deleteArray_edmcLcLWrapperlEvectorlERPRootDumpPatternInfogRsPgR(void *p) {
      delete [] ((::edm::Wrapper<vector<RPRootDumpPatternInfo> >*)p);
   }
   static void destruct_edmcLcLWrapperlEvectorlERPRootDumpPatternInfogRsPgR(void *p) {
      typedef ::edm::Wrapper<vector<RPRootDumpPatternInfo> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::edm::Wrapper<vector<RPRootDumpPatternInfo> >

namespace ROOT {
   // Wrappers around operator new
   static void *new_edmcLcLWrapperlEvectorlERPRootDumpReconstructedProtongRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::edm::Wrapper<vector<RPRootDumpReconstructedProton> > : new ::edm::Wrapper<vector<RPRootDumpReconstructedProton> >;
   }
   static void *newArray_edmcLcLWrapperlEvectorlERPRootDumpReconstructedProtongRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::edm::Wrapper<vector<RPRootDumpReconstructedProton> >[nElements] : new ::edm::Wrapper<vector<RPRootDumpReconstructedProton> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_edmcLcLWrapperlEvectorlERPRootDumpReconstructedProtongRsPgR(void *p) {
      delete ((::edm::Wrapper<vector<RPRootDumpReconstructedProton> >*)p);
   }
   static void deleteArray_edmcLcLWrapperlEvectorlERPRootDumpReconstructedProtongRsPgR(void *p) {
      delete [] ((::edm::Wrapper<vector<RPRootDumpReconstructedProton> >*)p);
   }
   static void destruct_edmcLcLWrapperlEvectorlERPRootDumpReconstructedProtongRsPgR(void *p) {
      typedef ::edm::Wrapper<vector<RPRootDumpReconstructedProton> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::edm::Wrapper<vector<RPRootDumpReconstructedProton> >

namespace ROOT {
   // Wrappers around operator new
   static void *new_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpTrackInfogRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::edm::Wrapper<map<unsigned int,RPRootDumpTrackInfo> > : new ::edm::Wrapper<map<unsigned int,RPRootDumpTrackInfo> >;
   }
   static void *newArray_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpTrackInfogRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::edm::Wrapper<map<unsigned int,RPRootDumpTrackInfo> >[nElements] : new ::edm::Wrapper<map<unsigned int,RPRootDumpTrackInfo> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpTrackInfogRsPgR(void *p) {
      delete ((::edm::Wrapper<map<unsigned int,RPRootDumpTrackInfo> >*)p);
   }
   static void deleteArray_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpTrackInfogRsPgR(void *p) {
      delete [] ((::edm::Wrapper<map<unsigned int,RPRootDumpTrackInfo> >*)p);
   }
   static void destruct_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpTrackInfogRsPgR(void *p) {
      typedef ::edm::Wrapper<map<unsigned int,RPRootDumpTrackInfo> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::edm::Wrapper<map<unsigned int,RPRootDumpTrackInfo> >

namespace ROOT {
   // Wrappers around operator new
   static void *new_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpDigiInfogRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::edm::Wrapper<map<unsigned int,RPRootDumpDigiInfo> > : new ::edm::Wrapper<map<unsigned int,RPRootDumpDigiInfo> >;
   }
   static void *newArray_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpDigiInfogRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::edm::Wrapper<map<unsigned int,RPRootDumpDigiInfo> >[nElements] : new ::edm::Wrapper<map<unsigned int,RPRootDumpDigiInfo> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpDigiInfogRsPgR(void *p) {
      delete ((::edm::Wrapper<map<unsigned int,RPRootDumpDigiInfo> >*)p);
   }
   static void deleteArray_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpDigiInfogRsPgR(void *p) {
      delete [] ((::edm::Wrapper<map<unsigned int,RPRootDumpDigiInfo> >*)p);
   }
   static void destruct_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpDigiInfogRsPgR(void *p) {
      typedef ::edm::Wrapper<map<unsigned int,RPRootDumpDigiInfo> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::edm::Wrapper<map<unsigned int,RPRootDumpDigiInfo> >

namespace ROOT {
   // Wrappers around operator new
   static void *new_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpPatternInfogRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::edm::Wrapper<map<unsigned int,RPRootDumpPatternInfo> > : new ::edm::Wrapper<map<unsigned int,RPRootDumpPatternInfo> >;
   }
   static void *newArray_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpPatternInfogRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::edm::Wrapper<map<unsigned int,RPRootDumpPatternInfo> >[nElements] : new ::edm::Wrapper<map<unsigned int,RPRootDumpPatternInfo> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpPatternInfogRsPgR(void *p) {
      delete ((::edm::Wrapper<map<unsigned int,RPRootDumpPatternInfo> >*)p);
   }
   static void deleteArray_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpPatternInfogRsPgR(void *p) {
      delete [] ((::edm::Wrapper<map<unsigned int,RPRootDumpPatternInfo> >*)p);
   }
   static void destruct_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpPatternInfogRsPgR(void *p) {
      typedef ::edm::Wrapper<map<unsigned int,RPRootDumpPatternInfo> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::edm::Wrapper<map<unsigned int,RPRootDumpPatternInfo> >

namespace ROOT {
   // Wrappers around operator new
   static void *new_edmcLcLWrapperlEmaplEunsignedsPintcOvectorlERPRootDumpTrackInfogRsPgRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::edm::Wrapper<map<unsigned int,vector<RPRootDumpTrackInfo> > > : new ::edm::Wrapper<map<unsigned int,vector<RPRootDumpTrackInfo> > >;
   }
   static void *newArray_edmcLcLWrapperlEmaplEunsignedsPintcOvectorlERPRootDumpTrackInfogRsPgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::edm::Wrapper<map<unsigned int,vector<RPRootDumpTrackInfo> > >[nElements] : new ::edm::Wrapper<map<unsigned int,vector<RPRootDumpTrackInfo> > >[nElements];
   }
   // Wrapper around operator delete
   static void delete_edmcLcLWrapperlEmaplEunsignedsPintcOvectorlERPRootDumpTrackInfogRsPgRsPgR(void *p) {
      delete ((::edm::Wrapper<map<unsigned int,vector<RPRootDumpTrackInfo> > >*)p);
   }
   static void deleteArray_edmcLcLWrapperlEmaplEunsignedsPintcOvectorlERPRootDumpTrackInfogRsPgRsPgR(void *p) {
      delete [] ((::edm::Wrapper<map<unsigned int,vector<RPRootDumpTrackInfo> > >*)p);
   }
   static void destruct_edmcLcLWrapperlEmaplEunsignedsPintcOvectorlERPRootDumpTrackInfogRsPgRsPgR(void *p) {
      typedef ::edm::Wrapper<map<unsigned int,vector<RPRootDumpTrackInfo> > > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::edm::Wrapper<map<unsigned int,vector<RPRootDumpTrackInfo> > >

namespace ROOT {
   // Wrappers around operator new
   static void *new_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpReconstructedProtongRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::edm::Wrapper<map<unsigned int,RPRootDumpReconstructedProton> > : new ::edm::Wrapper<map<unsigned int,RPRootDumpReconstructedProton> >;
   }
   static void *newArray_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpReconstructedProtongRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::edm::Wrapper<map<unsigned int,RPRootDumpReconstructedProton> >[nElements] : new ::edm::Wrapper<map<unsigned int,RPRootDumpReconstructedProton> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpReconstructedProtongRsPgR(void *p) {
      delete ((::edm::Wrapper<map<unsigned int,RPRootDumpReconstructedProton> >*)p);
   }
   static void deleteArray_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpReconstructedProtongRsPgR(void *p) {
      delete [] ((::edm::Wrapper<map<unsigned int,RPRootDumpReconstructedProton> >*)p);
   }
   static void destruct_edmcLcLWrapperlEmaplEunsignedsPintcORPRootDumpReconstructedProtongRsPgR(void *p) {
      typedef ::edm::Wrapper<map<unsigned int,RPRootDumpReconstructedProton> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::edm::Wrapper<map<unsigned int,RPRootDumpReconstructedProton> >

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
   static TClass *vectorlERPRootDumpReconstructedProtongR_Dictionary();
   static void vectorlERPRootDumpReconstructedProtongR_TClassManip(TClass*);
   static void *new_vectorlERPRootDumpReconstructedProtongR(void *p = 0);
   static void *newArray_vectorlERPRootDumpReconstructedProtongR(Long_t size, void *p);
   static void delete_vectorlERPRootDumpReconstructedProtongR(void *p);
   static void deleteArray_vectorlERPRootDumpReconstructedProtongR(void *p);
   static void destruct_vectorlERPRootDumpReconstructedProtongR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<RPRootDumpReconstructedProton>*)
   {
      vector<RPRootDumpReconstructedProton> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<RPRootDumpReconstructedProton>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<RPRootDumpReconstructedProton>", -2, "vector", 214,
                  typeid(vector<RPRootDumpReconstructedProton>), DefineBehavior(ptr, ptr),
                  &vectorlERPRootDumpReconstructedProtongR_Dictionary, isa_proxy, 4,
                  sizeof(vector<RPRootDumpReconstructedProton>) );
      instance.SetNew(&new_vectorlERPRootDumpReconstructedProtongR);
      instance.SetNewArray(&newArray_vectorlERPRootDumpReconstructedProtongR);
      instance.SetDelete(&delete_vectorlERPRootDumpReconstructedProtongR);
      instance.SetDeleteArray(&deleteArray_vectorlERPRootDumpReconstructedProtongR);
      instance.SetDestructor(&destruct_vectorlERPRootDumpReconstructedProtongR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<RPRootDumpReconstructedProton> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<RPRootDumpReconstructedProton>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlERPRootDumpReconstructedProtongR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<RPRootDumpReconstructedProton>*)0x0)->GetClass();
      vectorlERPRootDumpReconstructedProtongR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlERPRootDumpReconstructedProtongR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlERPRootDumpReconstructedProtongR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<RPRootDumpReconstructedProton> : new vector<RPRootDumpReconstructedProton>;
   }
   static void *newArray_vectorlERPRootDumpReconstructedProtongR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<RPRootDumpReconstructedProton>[nElements] : new vector<RPRootDumpReconstructedProton>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlERPRootDumpReconstructedProtongR(void *p) {
      delete ((vector<RPRootDumpReconstructedProton>*)p);
   }
   static void deleteArray_vectorlERPRootDumpReconstructedProtongR(void *p) {
      delete [] ((vector<RPRootDumpReconstructedProton>*)p);
   }
   static void destruct_vectorlERPRootDumpReconstructedProtongR(void *p) {
      typedef vector<RPRootDumpReconstructedProton> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<RPRootDumpReconstructedProton>

namespace ROOT {
   static TClass *vectorlERPRootDumpPatternInfogR_Dictionary();
   static void vectorlERPRootDumpPatternInfogR_TClassManip(TClass*);
   static void *new_vectorlERPRootDumpPatternInfogR(void *p = 0);
   static void *newArray_vectorlERPRootDumpPatternInfogR(Long_t size, void *p);
   static void delete_vectorlERPRootDumpPatternInfogR(void *p);
   static void deleteArray_vectorlERPRootDumpPatternInfogR(void *p);
   static void destruct_vectorlERPRootDumpPatternInfogR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<RPRootDumpPatternInfo>*)
   {
      vector<RPRootDumpPatternInfo> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<RPRootDumpPatternInfo>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<RPRootDumpPatternInfo>", -2, "vector", 214,
                  typeid(vector<RPRootDumpPatternInfo>), DefineBehavior(ptr, ptr),
                  &vectorlERPRootDumpPatternInfogR_Dictionary, isa_proxy, 4,
                  sizeof(vector<RPRootDumpPatternInfo>) );
      instance.SetNew(&new_vectorlERPRootDumpPatternInfogR);
      instance.SetNewArray(&newArray_vectorlERPRootDumpPatternInfogR);
      instance.SetDelete(&delete_vectorlERPRootDumpPatternInfogR);
      instance.SetDeleteArray(&deleteArray_vectorlERPRootDumpPatternInfogR);
      instance.SetDestructor(&destruct_vectorlERPRootDumpPatternInfogR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<RPRootDumpPatternInfo> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<RPRootDumpPatternInfo>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlERPRootDumpPatternInfogR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<RPRootDumpPatternInfo>*)0x0)->GetClass();
      vectorlERPRootDumpPatternInfogR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlERPRootDumpPatternInfogR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlERPRootDumpPatternInfogR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<RPRootDumpPatternInfo> : new vector<RPRootDumpPatternInfo>;
   }
   static void *newArray_vectorlERPRootDumpPatternInfogR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<RPRootDumpPatternInfo>[nElements] : new vector<RPRootDumpPatternInfo>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlERPRootDumpPatternInfogR(void *p) {
      delete ((vector<RPRootDumpPatternInfo>*)p);
   }
   static void deleteArray_vectorlERPRootDumpPatternInfogR(void *p) {
      delete [] ((vector<RPRootDumpPatternInfo>*)p);
   }
   static void destruct_vectorlERPRootDumpPatternInfogR(void *p) {
      typedef vector<RPRootDumpPatternInfo> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<RPRootDumpPatternInfo>

namespace ROOT {
   static TClass *vectorlERPRootDumpDigiInfogR_Dictionary();
   static void vectorlERPRootDumpDigiInfogR_TClassManip(TClass*);
   static void *new_vectorlERPRootDumpDigiInfogR(void *p = 0);
   static void *newArray_vectorlERPRootDumpDigiInfogR(Long_t size, void *p);
   static void delete_vectorlERPRootDumpDigiInfogR(void *p);
   static void deleteArray_vectorlERPRootDumpDigiInfogR(void *p);
   static void destruct_vectorlERPRootDumpDigiInfogR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<RPRootDumpDigiInfo>*)
   {
      vector<RPRootDumpDigiInfo> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<RPRootDumpDigiInfo>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<RPRootDumpDigiInfo>", -2, "vector", 214,
                  typeid(vector<RPRootDumpDigiInfo>), DefineBehavior(ptr, ptr),
                  &vectorlERPRootDumpDigiInfogR_Dictionary, isa_proxy, 4,
                  sizeof(vector<RPRootDumpDigiInfo>) );
      instance.SetNew(&new_vectorlERPRootDumpDigiInfogR);
      instance.SetNewArray(&newArray_vectorlERPRootDumpDigiInfogR);
      instance.SetDelete(&delete_vectorlERPRootDumpDigiInfogR);
      instance.SetDeleteArray(&deleteArray_vectorlERPRootDumpDigiInfogR);
      instance.SetDestructor(&destruct_vectorlERPRootDumpDigiInfogR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<RPRootDumpDigiInfo> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<RPRootDumpDigiInfo>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlERPRootDumpDigiInfogR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<RPRootDumpDigiInfo>*)0x0)->GetClass();
      vectorlERPRootDumpDigiInfogR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlERPRootDumpDigiInfogR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlERPRootDumpDigiInfogR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<RPRootDumpDigiInfo> : new vector<RPRootDumpDigiInfo>;
   }
   static void *newArray_vectorlERPRootDumpDigiInfogR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<RPRootDumpDigiInfo>[nElements] : new vector<RPRootDumpDigiInfo>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlERPRootDumpDigiInfogR(void *p) {
      delete ((vector<RPRootDumpDigiInfo>*)p);
   }
   static void deleteArray_vectorlERPRootDumpDigiInfogR(void *p) {
      delete [] ((vector<RPRootDumpDigiInfo>*)p);
   }
   static void destruct_vectorlERPRootDumpDigiInfogR(void *p) {
      typedef vector<RPRootDumpDigiInfo> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<RPRootDumpDigiInfo>

namespace ROOT {
   static TClass *maplEunsignedsPintcOvectorlERPRootDumpTrackInfogRsPgR_Dictionary();
   static void maplEunsignedsPintcOvectorlERPRootDumpTrackInfogRsPgR_TClassManip(TClass*);
   static void *new_maplEunsignedsPintcOvectorlERPRootDumpTrackInfogRsPgR(void *p = 0);
   static void *newArray_maplEunsignedsPintcOvectorlERPRootDumpTrackInfogRsPgR(Long_t size, void *p);
   static void delete_maplEunsignedsPintcOvectorlERPRootDumpTrackInfogRsPgR(void *p);
   static void deleteArray_maplEunsignedsPintcOvectorlERPRootDumpTrackInfogRsPgR(void *p);
   static void destruct_maplEunsignedsPintcOvectorlERPRootDumpTrackInfogRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<unsigned int,vector<RPRootDumpTrackInfo> >*)
   {
      map<unsigned int,vector<RPRootDumpTrackInfo> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<unsigned int,vector<RPRootDumpTrackInfo> >));
      static ::ROOT::TGenericClassInfo 
         instance("map<unsigned int,vector<RPRootDumpTrackInfo> >", -2, "map", 96,
                  typeid(map<unsigned int,vector<RPRootDumpTrackInfo> >), DefineBehavior(ptr, ptr),
                  &maplEunsignedsPintcOvectorlERPRootDumpTrackInfogRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(map<unsigned int,vector<RPRootDumpTrackInfo> >) );
      instance.SetNew(&new_maplEunsignedsPintcOvectorlERPRootDumpTrackInfogRsPgR);
      instance.SetNewArray(&newArray_maplEunsignedsPintcOvectorlERPRootDumpTrackInfogRsPgR);
      instance.SetDelete(&delete_maplEunsignedsPintcOvectorlERPRootDumpTrackInfogRsPgR);
      instance.SetDeleteArray(&deleteArray_maplEunsignedsPintcOvectorlERPRootDumpTrackInfogRsPgR);
      instance.SetDestructor(&destruct_maplEunsignedsPintcOvectorlERPRootDumpTrackInfogRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<unsigned int,vector<RPRootDumpTrackInfo> > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const map<unsigned int,vector<RPRootDumpTrackInfo> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEunsignedsPintcOvectorlERPRootDumpTrackInfogRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<unsigned int,vector<RPRootDumpTrackInfo> >*)0x0)->GetClass();
      maplEunsignedsPintcOvectorlERPRootDumpTrackInfogRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEunsignedsPintcOvectorlERPRootDumpTrackInfogRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEunsignedsPintcOvectorlERPRootDumpTrackInfogRsPgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) map<unsigned int,vector<RPRootDumpTrackInfo> > : new map<unsigned int,vector<RPRootDumpTrackInfo> >;
   }
   static void *newArray_maplEunsignedsPintcOvectorlERPRootDumpTrackInfogRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) map<unsigned int,vector<RPRootDumpTrackInfo> >[nElements] : new map<unsigned int,vector<RPRootDumpTrackInfo> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEunsignedsPintcOvectorlERPRootDumpTrackInfogRsPgR(void *p) {
      delete ((map<unsigned int,vector<RPRootDumpTrackInfo> >*)p);
   }
   static void deleteArray_maplEunsignedsPintcOvectorlERPRootDumpTrackInfogRsPgR(void *p) {
      delete [] ((map<unsigned int,vector<RPRootDumpTrackInfo> >*)p);
   }
   static void destruct_maplEunsignedsPintcOvectorlERPRootDumpTrackInfogRsPgR(void *p) {
      typedef map<unsigned int,vector<RPRootDumpTrackInfo> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<unsigned int,vector<RPRootDumpTrackInfo> >

namespace ROOT {
   static TClass *maplEunsignedsPintcORPRootDumpTrackInfogR_Dictionary();
   static void maplEunsignedsPintcORPRootDumpTrackInfogR_TClassManip(TClass*);
   static void *new_maplEunsignedsPintcORPRootDumpTrackInfogR(void *p = 0);
   static void *newArray_maplEunsignedsPintcORPRootDumpTrackInfogR(Long_t size, void *p);
   static void delete_maplEunsignedsPintcORPRootDumpTrackInfogR(void *p);
   static void deleteArray_maplEunsignedsPintcORPRootDumpTrackInfogR(void *p);
   static void destruct_maplEunsignedsPintcORPRootDumpTrackInfogR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<unsigned int,RPRootDumpTrackInfo>*)
   {
      map<unsigned int,RPRootDumpTrackInfo> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<unsigned int,RPRootDumpTrackInfo>));
      static ::ROOT::TGenericClassInfo 
         instance("map<unsigned int,RPRootDumpTrackInfo>", -2, "map", 96,
                  typeid(map<unsigned int,RPRootDumpTrackInfo>), DefineBehavior(ptr, ptr),
                  &maplEunsignedsPintcORPRootDumpTrackInfogR_Dictionary, isa_proxy, 4,
                  sizeof(map<unsigned int,RPRootDumpTrackInfo>) );
      instance.SetNew(&new_maplEunsignedsPintcORPRootDumpTrackInfogR);
      instance.SetNewArray(&newArray_maplEunsignedsPintcORPRootDumpTrackInfogR);
      instance.SetDelete(&delete_maplEunsignedsPintcORPRootDumpTrackInfogR);
      instance.SetDeleteArray(&deleteArray_maplEunsignedsPintcORPRootDumpTrackInfogR);
      instance.SetDestructor(&destruct_maplEunsignedsPintcORPRootDumpTrackInfogR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<unsigned int,RPRootDumpTrackInfo> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const map<unsigned int,RPRootDumpTrackInfo>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEunsignedsPintcORPRootDumpTrackInfogR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<unsigned int,RPRootDumpTrackInfo>*)0x0)->GetClass();
      maplEunsignedsPintcORPRootDumpTrackInfogR_TClassManip(theClass);
   return theClass;
   }

   static void maplEunsignedsPintcORPRootDumpTrackInfogR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEunsignedsPintcORPRootDumpTrackInfogR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) map<unsigned int,RPRootDumpTrackInfo> : new map<unsigned int,RPRootDumpTrackInfo>;
   }
   static void *newArray_maplEunsignedsPintcORPRootDumpTrackInfogR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) map<unsigned int,RPRootDumpTrackInfo>[nElements] : new map<unsigned int,RPRootDumpTrackInfo>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEunsignedsPintcORPRootDumpTrackInfogR(void *p) {
      delete ((map<unsigned int,RPRootDumpTrackInfo>*)p);
   }
   static void deleteArray_maplEunsignedsPintcORPRootDumpTrackInfogR(void *p) {
      delete [] ((map<unsigned int,RPRootDumpTrackInfo>*)p);
   }
   static void destruct_maplEunsignedsPintcORPRootDumpTrackInfogR(void *p) {
      typedef map<unsigned int,RPRootDumpTrackInfo> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<unsigned int,RPRootDumpTrackInfo>

namespace ROOT {
   static TClass *maplEunsignedsPintcORPRootDumpReconstructedProtongR_Dictionary();
   static void maplEunsignedsPintcORPRootDumpReconstructedProtongR_TClassManip(TClass*);
   static void *new_maplEunsignedsPintcORPRootDumpReconstructedProtongR(void *p = 0);
   static void *newArray_maplEunsignedsPintcORPRootDumpReconstructedProtongR(Long_t size, void *p);
   static void delete_maplEunsignedsPintcORPRootDumpReconstructedProtongR(void *p);
   static void deleteArray_maplEunsignedsPintcORPRootDumpReconstructedProtongR(void *p);
   static void destruct_maplEunsignedsPintcORPRootDumpReconstructedProtongR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<unsigned int,RPRootDumpReconstructedProton>*)
   {
      map<unsigned int,RPRootDumpReconstructedProton> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<unsigned int,RPRootDumpReconstructedProton>));
      static ::ROOT::TGenericClassInfo 
         instance("map<unsigned int,RPRootDumpReconstructedProton>", -2, "map", 96,
                  typeid(map<unsigned int,RPRootDumpReconstructedProton>), DefineBehavior(ptr, ptr),
                  &maplEunsignedsPintcORPRootDumpReconstructedProtongR_Dictionary, isa_proxy, 4,
                  sizeof(map<unsigned int,RPRootDumpReconstructedProton>) );
      instance.SetNew(&new_maplEunsignedsPintcORPRootDumpReconstructedProtongR);
      instance.SetNewArray(&newArray_maplEunsignedsPintcORPRootDumpReconstructedProtongR);
      instance.SetDelete(&delete_maplEunsignedsPintcORPRootDumpReconstructedProtongR);
      instance.SetDeleteArray(&deleteArray_maplEunsignedsPintcORPRootDumpReconstructedProtongR);
      instance.SetDestructor(&destruct_maplEunsignedsPintcORPRootDumpReconstructedProtongR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<unsigned int,RPRootDumpReconstructedProton> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const map<unsigned int,RPRootDumpReconstructedProton>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEunsignedsPintcORPRootDumpReconstructedProtongR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<unsigned int,RPRootDumpReconstructedProton>*)0x0)->GetClass();
      maplEunsignedsPintcORPRootDumpReconstructedProtongR_TClassManip(theClass);
   return theClass;
   }

   static void maplEunsignedsPintcORPRootDumpReconstructedProtongR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEunsignedsPintcORPRootDumpReconstructedProtongR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) map<unsigned int,RPRootDumpReconstructedProton> : new map<unsigned int,RPRootDumpReconstructedProton>;
   }
   static void *newArray_maplEunsignedsPintcORPRootDumpReconstructedProtongR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) map<unsigned int,RPRootDumpReconstructedProton>[nElements] : new map<unsigned int,RPRootDumpReconstructedProton>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEunsignedsPintcORPRootDumpReconstructedProtongR(void *p) {
      delete ((map<unsigned int,RPRootDumpReconstructedProton>*)p);
   }
   static void deleteArray_maplEunsignedsPintcORPRootDumpReconstructedProtongR(void *p) {
      delete [] ((map<unsigned int,RPRootDumpReconstructedProton>*)p);
   }
   static void destruct_maplEunsignedsPintcORPRootDumpReconstructedProtongR(void *p) {
      typedef map<unsigned int,RPRootDumpReconstructedProton> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<unsigned int,RPRootDumpReconstructedProton>

namespace ROOT {
   static TClass *maplEunsignedsPintcORPRootDumpPatternInfogR_Dictionary();
   static void maplEunsignedsPintcORPRootDumpPatternInfogR_TClassManip(TClass*);
   static void *new_maplEunsignedsPintcORPRootDumpPatternInfogR(void *p = 0);
   static void *newArray_maplEunsignedsPintcORPRootDumpPatternInfogR(Long_t size, void *p);
   static void delete_maplEunsignedsPintcORPRootDumpPatternInfogR(void *p);
   static void deleteArray_maplEunsignedsPintcORPRootDumpPatternInfogR(void *p);
   static void destruct_maplEunsignedsPintcORPRootDumpPatternInfogR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<unsigned int,RPRootDumpPatternInfo>*)
   {
      map<unsigned int,RPRootDumpPatternInfo> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<unsigned int,RPRootDumpPatternInfo>));
      static ::ROOT::TGenericClassInfo 
         instance("map<unsigned int,RPRootDumpPatternInfo>", -2, "map", 96,
                  typeid(map<unsigned int,RPRootDumpPatternInfo>), DefineBehavior(ptr, ptr),
                  &maplEunsignedsPintcORPRootDumpPatternInfogR_Dictionary, isa_proxy, 4,
                  sizeof(map<unsigned int,RPRootDumpPatternInfo>) );
      instance.SetNew(&new_maplEunsignedsPintcORPRootDumpPatternInfogR);
      instance.SetNewArray(&newArray_maplEunsignedsPintcORPRootDumpPatternInfogR);
      instance.SetDelete(&delete_maplEunsignedsPintcORPRootDumpPatternInfogR);
      instance.SetDeleteArray(&deleteArray_maplEunsignedsPintcORPRootDumpPatternInfogR);
      instance.SetDestructor(&destruct_maplEunsignedsPintcORPRootDumpPatternInfogR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<unsigned int,RPRootDumpPatternInfo> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const map<unsigned int,RPRootDumpPatternInfo>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEunsignedsPintcORPRootDumpPatternInfogR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<unsigned int,RPRootDumpPatternInfo>*)0x0)->GetClass();
      maplEunsignedsPintcORPRootDumpPatternInfogR_TClassManip(theClass);
   return theClass;
   }

   static void maplEunsignedsPintcORPRootDumpPatternInfogR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEunsignedsPintcORPRootDumpPatternInfogR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) map<unsigned int,RPRootDumpPatternInfo> : new map<unsigned int,RPRootDumpPatternInfo>;
   }
   static void *newArray_maplEunsignedsPintcORPRootDumpPatternInfogR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) map<unsigned int,RPRootDumpPatternInfo>[nElements] : new map<unsigned int,RPRootDumpPatternInfo>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEunsignedsPintcORPRootDumpPatternInfogR(void *p) {
      delete ((map<unsigned int,RPRootDumpPatternInfo>*)p);
   }
   static void deleteArray_maplEunsignedsPintcORPRootDumpPatternInfogR(void *p) {
      delete [] ((map<unsigned int,RPRootDumpPatternInfo>*)p);
   }
   static void destruct_maplEunsignedsPintcORPRootDumpPatternInfogR(void *p) {
      typedef map<unsigned int,RPRootDumpPatternInfo> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<unsigned int,RPRootDumpPatternInfo>

namespace ROOT {
   static TClass *maplEunsignedsPintcORPRootDumpDigiInfogR_Dictionary();
   static void maplEunsignedsPintcORPRootDumpDigiInfogR_TClassManip(TClass*);
   static void *new_maplEunsignedsPintcORPRootDumpDigiInfogR(void *p = 0);
   static void *newArray_maplEunsignedsPintcORPRootDumpDigiInfogR(Long_t size, void *p);
   static void delete_maplEunsignedsPintcORPRootDumpDigiInfogR(void *p);
   static void deleteArray_maplEunsignedsPintcORPRootDumpDigiInfogR(void *p);
   static void destruct_maplEunsignedsPintcORPRootDumpDigiInfogR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<unsigned int,RPRootDumpDigiInfo>*)
   {
      map<unsigned int,RPRootDumpDigiInfo> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<unsigned int,RPRootDumpDigiInfo>));
      static ::ROOT::TGenericClassInfo 
         instance("map<unsigned int,RPRootDumpDigiInfo>", -2, "map", 96,
                  typeid(map<unsigned int,RPRootDumpDigiInfo>), DefineBehavior(ptr, ptr),
                  &maplEunsignedsPintcORPRootDumpDigiInfogR_Dictionary, isa_proxy, 4,
                  sizeof(map<unsigned int,RPRootDumpDigiInfo>) );
      instance.SetNew(&new_maplEunsignedsPintcORPRootDumpDigiInfogR);
      instance.SetNewArray(&newArray_maplEunsignedsPintcORPRootDumpDigiInfogR);
      instance.SetDelete(&delete_maplEunsignedsPintcORPRootDumpDigiInfogR);
      instance.SetDeleteArray(&deleteArray_maplEunsignedsPintcORPRootDumpDigiInfogR);
      instance.SetDestructor(&destruct_maplEunsignedsPintcORPRootDumpDigiInfogR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<unsigned int,RPRootDumpDigiInfo> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const map<unsigned int,RPRootDumpDigiInfo>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEunsignedsPintcORPRootDumpDigiInfogR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<unsigned int,RPRootDumpDigiInfo>*)0x0)->GetClass();
      maplEunsignedsPintcORPRootDumpDigiInfogR_TClassManip(theClass);
   return theClass;
   }

   static void maplEunsignedsPintcORPRootDumpDigiInfogR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEunsignedsPintcORPRootDumpDigiInfogR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) map<unsigned int,RPRootDumpDigiInfo> : new map<unsigned int,RPRootDumpDigiInfo>;
   }
   static void *newArray_maplEunsignedsPintcORPRootDumpDigiInfogR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) map<unsigned int,RPRootDumpDigiInfo>[nElements] : new map<unsigned int,RPRootDumpDigiInfo>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEunsignedsPintcORPRootDumpDigiInfogR(void *p) {
      delete ((map<unsigned int,RPRootDumpDigiInfo>*)p);
   }
   static void deleteArray_maplEunsignedsPintcORPRootDumpDigiInfogR(void *p) {
      delete [] ((map<unsigned int,RPRootDumpDigiInfo>*)p);
   }
   static void destruct_maplEunsignedsPintcORPRootDumpDigiInfogR(void *p) {
      typedef map<unsigned int,RPRootDumpDigiInfo> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<unsigned int,RPRootDumpDigiInfo>

namespace {
  void TriggerDictionaryInitialization_TotemAnalysisTotemAnalysisEvent_xr_Impl() {
    static const char* headers[] = {
0    };
    static const char* includePaths[] = {
"/afs/cern.ch/user/e/eliza/private/TOTEM_JPSI/RPSIM/CMSSW_7_6_3/src",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc493/cms/cmssw/CMSSW_7_6_3/src",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc493/lcg/root/6.02.12-kpegke4/include",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc493/external/boost/1.57.0-kpegke/include",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc493/external/pcre/7.9__8.33/include",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc493/external/bz2lib/1.0.5/include",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc493/external/libuuid/2.22.2/include",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc493/external/python/2.7.6-kpegke/include/python2.7",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc493/external/tbb/43_20150316oss/include",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc493/external/zlib/1.2.8/include",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc493/lcg/root/6.02.12-kpegke4/include",
"/afs/cern.ch/user/e/eliza/private/TOTEM_JPSI/RPSIM/CMSSW_7_6_3/",
0
    };
    static const char* fwdDeclCode = 
R"DICTFWDDCLS(
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
struct __attribute__((annotate("$clingAutoload$TotemAnalysis/TotemAnalysisEvent/interface/TotemRPEvent.h")))  TotemRPEvent;
struct __attribute__((annotate("$clingAutoload$TotemAnalysis/TotemAnalysisEvent/interface/TotemRPEvent.h")))  RPRootDumpTrackInfo;
struct __attribute__((annotate("$clingAutoload$TotemAnalysis/TotemAnalysisEvent/interface/TotemRPEvent.h")))  RPRootDumpDigiInfo;
struct __attribute__((annotate("$clingAutoload$TotemAnalysis/TotemAnalysisEvent/interface/TotemRPEvent.h")))  RPRootDumpReconstructedProton;
struct __attribute__((annotate("$clingAutoload$TotemAnalysis/TotemAnalysisEvent/interface/TotemRPEvent.h")))  RPRootDumpReconstructedProtonPair;
struct __attribute__((annotate("$clingAutoload$TotemAnalysis/TotemAnalysisEvent/interface/TotemRPEvent.h")))  RPRootDumpPattern;
struct __attribute__((annotate("$clingAutoload$TotemAnalysis/TotemAnalysisEvent/interface/TotemRPEvent.h")))  RPRootDumpPatternInfo;
namespace std{template <typename _Tp> class __attribute__((annotate("$clingAutoload$string")))  allocator;
}
namespace std{template <typename _Tp> struct __attribute__((annotate("$clingAutoload$string")))  less;
}
namespace std{template <class _T1, class _T2> struct __attribute__((annotate("$clingAutoload$string")))  pair;
}
namespace edm{template <typename T> class __attribute__((annotate("$clingAutoload$DataFormats/Common/interface/Wrapper.h")))  Wrapper;
}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif
#ifndef CMS_DICT_IMPL
  #define CMS_DICT_IMPL 1
#endif
#ifndef _REENTRANT
  #define _REENTRANT 1
#endif
#ifndef GNUSOURCE
  #define GNUSOURCE 1
#endif
#ifndef __STRICT_ANSI__
  #define __STRICT_ANSI__ 1
#endif
#ifndef GNU_GCC
  #define GNU_GCC 1
#endif
#ifndef _GNU_SOURCE
  #define _GNU_SOURCE 1
#endif
#ifndef CMSSW_GIT_HASH
  #define CMSSW_GIT_HASH "CMSSW_7_6_3"
#endif
#ifndef PROJECT_NAME
  #define PROJECT_NAME "CMSSW"
#endif
#ifndef PROJECT_VERSION
  #define PROJECT_VERSION "CMSSW_7_6_3"
#endif
#ifndef BOOST_SPIRIT_THREADSAFE
  #define BOOST_SPIRIT_THREADSAFE 1
#endif
#ifndef PHOENIX_THREADSAFE
  #define PHOENIX_THREADSAFE 1
#endif
#ifndef CMSSW_REFLEX_DICT
  #define CMSSW_REFLEX_DICT 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H

#include "TotemAnalysis/TotemAnalysisEvent/interface/TotemRPEvent.h"
//#include "TotemAnalysis/TotemAnalysisEvent/interface/RPTrackInfo.h"
#include "TotemAnalysis/TotemAnalysisEvent/interface/RPRootTrackInfo.h"

#include "DataFormats/Common/interface/Wrapper.h"
#include <vector>
#include <map>

namespace {
   struct dictionary {
      TotemRPEvent totemRPEvent;

      RPRootDumpTrackInfo               rpTrackInfo;
      RPRootDumpDigiInfo                rpDigiInfo;
      RPRootDumpReconstructedProton     rpReconstructedProton;
      RPRootDumpReconstructedProtonPair rpReconstructedProtonPair;
      RPRootDumpPattern                 rpPattern;
      RPRootDumpPatternInfo             rpPatternInfo;

      std::vector<RPRootDumpTrackInfo>           vec_rpTrackInfo;
      std::vector<RPRootDumpDigiInfo>            vec_rpDigiInfo;
      std::vector<RPRootDumpPatternInfo>         vec_rpPatternInfo;
      std::vector<RPRootDumpReconstructedProton> vec_rpReconstructedProton;
  
      std::map<unsigned int, RPRootDumpTrackInfo>    track_info_;
      std::map<unsigned int, RPRootDumpDigiInfo>     digi_info_;
      std::map<unsigned int, RPRootDumpPatternInfo>  patterns_info_;

      std::map<unsigned int, std::vector<RPRootDumpTrackInfo> > multi_track_info_;
      std::map<unsigned int, RPRootDumpReconstructedProton>     rec_pr_info_;

      edm::Wrapper<TotemRPEvent>                  totemRPEvent_wr;

      edm::Wrapper<RPRootDumpTrackInfo>               rpTrackInfo_wr;
      edm::Wrapper<RPRootDumpDigiInfo>                rpDigiInfo_wr;
      edm::Wrapper<RPRootDumpReconstructedProton>     rpReconstructedProton_wr;
      edm::Wrapper<RPRootDumpReconstructedProtonPair> rpReconstructedProtonPair_wr;
      edm::Wrapper<RPRootDumpPattern>                 rpPattern_wr;
      edm::Wrapper<RPRootDumpPatternInfo>             rpPatternInfo_wr;

      edm::Wrapper<std::vector<RPRootDumpTrackInfo> >           vec_rpTrackInfo_wr;
      edm::Wrapper<std::vector<RPRootDumpDigiInfo> >            vec_rpDigiInfo_wr;
      edm::Wrapper<std::vector<RPRootDumpPatternInfo> >         vec_rpPatternInfo_wr;
      edm::Wrapper<std::vector<RPRootDumpReconstructedProton> > vec_rpReconstructedProton_wr;

      edm::Wrapper<std::map<unsigned int, RPRootDumpTrackInfo> >               track_info_wr;
      edm::Wrapper<std::map<unsigned int, RPRootDumpDigiInfo> >                digi_info_wr;
      edm::Wrapper<std::map<unsigned int, RPRootDumpPatternInfo> >             patterns_info_wr;
      edm::Wrapper<std::map<unsigned int, std::vector<RPRootDumpTrackInfo> > > multi_track_info_wr;
      edm::Wrapper<std::map<unsigned int, RPRootDumpReconstructedProton> >     rec_pr_info_wr;

   };
} 

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"RPRootDumpDigiInfo", payloadCode, "@",
"RPRootDumpPattern", payloadCode, "@",
"RPRootDumpPatternInfo", payloadCode, "@",
"RPRootDumpReconstructedProton", payloadCode, "@",
"RPRootDumpReconstructedProtonPair", payloadCode, "@",
"RPRootDumpTrackInfo", payloadCode, "@",
"TotemRPEvent", payloadCode, "@",
"edm::Wrapper<RPRootDumpDigiInfo>", payloadCode, "@",
"edm::Wrapper<RPRootDumpPattern>", payloadCode, "@",
"edm::Wrapper<RPRootDumpPatternInfo>", payloadCode, "@",
"edm::Wrapper<RPRootDumpReconstructedProton>", payloadCode, "@",
"edm::Wrapper<RPRootDumpReconstructedProtonPair>", payloadCode, "@",
"edm::Wrapper<RPRootDumpTrackInfo>", payloadCode, "@",
"edm::Wrapper<TotemRPEvent>", payloadCode, "@",
"edm::Wrapper<map<unsigned int,RPRootDumpDigiInfo> >", payloadCode, "@",
"edm::Wrapper<map<unsigned int,RPRootDumpPatternInfo> >", payloadCode, "@",
"edm::Wrapper<map<unsigned int,RPRootDumpReconstructedProton> >", payloadCode, "@",
"edm::Wrapper<map<unsigned int,RPRootDumpTrackInfo> >", payloadCode, "@",
"edm::Wrapper<map<unsigned int,vector<RPRootDumpTrackInfo> > >", payloadCode, "@",
"edm::Wrapper<std::map<unsigned int,RPRootDumpDigiInfo> >", payloadCode, "@",
"edm::Wrapper<std::map<unsigned int,RPRootDumpPatternInfo> >", payloadCode, "@",
"edm::Wrapper<std::map<unsigned int,RPRootDumpReconstructedProton> >", payloadCode, "@",
"edm::Wrapper<std::map<unsigned int,RPRootDumpTrackInfo> >", payloadCode, "@",
"edm::Wrapper<std::map<unsigned int,std::vector<RPRootDumpTrackInfo> > >", payloadCode, "@",
"edm::Wrapper<std::vector<RPRootDumpDigiInfo> >", payloadCode, "@",
"edm::Wrapper<std::vector<RPRootDumpPatternInfo> >", payloadCode, "@",
"edm::Wrapper<std::vector<RPRootDumpReconstructedProton> >", payloadCode, "@",
"edm::Wrapper<std::vector<RPRootDumpTrackInfo> >", payloadCode, "@",
"edm::Wrapper<vector<RPRootDumpDigiInfo> >", payloadCode, "@",
"edm::Wrapper<vector<RPRootDumpPatternInfo> >", payloadCode, "@",
"edm::Wrapper<vector<RPRootDumpReconstructedProton> >", payloadCode, "@",
"edm::Wrapper<vector<RPRootDumpTrackInfo> >", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TotemAnalysisTotemAnalysisEvent_xr",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TotemAnalysisTotemAnalysisEvent_xr_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TotemAnalysisTotemAnalysisEvent_xr_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TotemAnalysisTotemAnalysisEvent_xr() {
  TriggerDictionaryInitialization_TotemAnalysisTotemAnalysisEvent_xr_Impl();
}
