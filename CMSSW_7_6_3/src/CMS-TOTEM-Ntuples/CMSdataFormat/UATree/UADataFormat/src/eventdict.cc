// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dIafsdIcerndOchdIuserdIedIelizadIprivatedITOTEM_JPSIdIRPSIMdICMSSW_7_6_3dIsrcdICMSmITOTEMmINtuplesdICMSdataFormatdIUATreedIUADataFormatdIsrcdIeventdict

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
#include "UATree/UADataFormat/interface/MyBeamSpot.h"
#include "UATree/UADataFormat/interface/MyCastorDigi.h"
#include "UATree/UADataFormat/interface/MyCastorJet.h"
#include "UATree/UADataFormat/interface/MyCastorRecHit.h"
#include "UATree/UADataFormat/interface/MyDiJet.h"
#include "UATree/UADataFormat/interface/MyEvtId.h"
#include "UATree/UADataFormat/interface/MyFwdGap.h"
#include "UATree/UADataFormat/interface/MyMet.h"
#include "UATree/UADataFormat/interface/MyGenMet.h"
#include "UATree/UADataFormat/interface/MyGenKin.h"
#include "UATree/UADataFormat/interface/MyGenPart.h"
#include "UATree/UADataFormat/interface/MyGenJet.h"
#include "UATree/UADataFormat/interface/MyPUSumInfo.h"
#include "UATree/UADataFormat/interface/MyHLTrig.h"
#include "UATree/UADataFormat/interface/MyL1Trig.h"
#include "UATree/UADataFormat/interface/MyL1TrigOld.h"
#include "UATree/UADataFormat/interface/MyMITEvtSel.h"
#include "UATree/UADataFormat/interface/MyPart.h"
#include "UATree/UADataFormat/interface/MySimVertex.h"
#include "UATree/UADataFormat/interface/MyVertex.h"
#include "UATree/UADataFormat/interface/MyTracks.h"
#include "UATree/UADataFormat/interface/MyElectron.h"
#include "UATree/UADataFormat/interface/MyMuon.h"
#include "UATree/UADataFormat/interface/MyBaseJet.h"
#include "UATree/UADataFormat/interface/MyJet.h"
#include "UATree/UADataFormat/interface/MyCaloJet.h"
#include "UATree/UADataFormat/interface/MyTrackJet.h"
#include "UATree/UADataFormat/interface/MyPFJet.h"
#include "UATree/UADataFormat/interface/MyPFCand.h"
#include "UATree/UADataFormat/interface/MyCaloTower.h"
#include "UATree/UADataFormat/interface/MyFSCHit.h"
#include "UATree/UADataFormat/interface/MyFSCDigi.h"
#include "UATree/UADataFormat/interface/MyFSCInfo.h"
#include "UATree/UADataFormat/interface/MyKshorts.h"
#include "UATree/UADataFormat/interface/MyLambdas.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static TClass *pairlEstringcOboolgR_Dictionary();
   static void pairlEstringcOboolgR_TClassManip(TClass*);
   static void *new_pairlEstringcOboolgR(void *p = 0);
   static void *newArray_pairlEstringcOboolgR(Long_t size, void *p);
   static void delete_pairlEstringcOboolgR(void *p);
   static void deleteArray_pairlEstringcOboolgR(void *p);
   static void destruct_pairlEstringcOboolgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const pair<string,bool>*)
   {
      pair<string,bool> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(pair<string,bool>));
      static ::ROOT::TGenericClassInfo 
         instance("pair<string,bool>", "string", 96,
                  typeid(pair<string,bool>), DefineBehavior(ptr, ptr),
                  &pairlEstringcOboolgR_Dictionary, isa_proxy, 4,
                  sizeof(pair<string,bool>) );
      instance.SetNew(&new_pairlEstringcOboolgR);
      instance.SetNewArray(&newArray_pairlEstringcOboolgR);
      instance.SetDelete(&delete_pairlEstringcOboolgR);
      instance.SetDeleteArray(&deleteArray_pairlEstringcOboolgR);
      instance.SetDestructor(&destruct_pairlEstringcOboolgR);
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const pair<string,bool>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *pairlEstringcOboolgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const pair<string,bool>*)0x0)->GetClass();
      pairlEstringcOboolgR_TClassManip(theClass);
   return theClass;
   }

   static void pairlEstringcOboolgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static void *new_MyBeamSpot(void *p = 0);
   static void *newArray_MyBeamSpot(Long_t size, void *p);
   static void delete_MyBeamSpot(void *p);
   static void deleteArray_MyBeamSpot(void *p);
   static void destruct_MyBeamSpot(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MyBeamSpot*)
   {
      ::MyBeamSpot *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::MyBeamSpot >(0);
      static ::ROOT::TGenericClassInfo 
         instance("MyBeamSpot", ::MyBeamSpot::Class_Version(), "UATree/UADataFormat/interface/MyBeamSpot.h", 6,
                  typeid(::MyBeamSpot), DefineBehavior(ptr, ptr),
                  &::MyBeamSpot::Dictionary, isa_proxy, 4,
                  sizeof(::MyBeamSpot) );
      instance.SetNew(&new_MyBeamSpot);
      instance.SetNewArray(&newArray_MyBeamSpot);
      instance.SetDelete(&delete_MyBeamSpot);
      instance.SetDeleteArray(&deleteArray_MyBeamSpot);
      instance.SetDestructor(&destruct_MyBeamSpot);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MyBeamSpot*)
   {
      return GenerateInitInstanceLocal((::MyBeamSpot*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::MyBeamSpot*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_MyCastorDigi(void *p = 0);
   static void *newArray_MyCastorDigi(Long_t size, void *p);
   static void delete_MyCastorDigi(void *p);
   static void deleteArray_MyCastorDigi(void *p);
   static void destruct_MyCastorDigi(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MyCastorDigi*)
   {
      ::MyCastorDigi *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::MyCastorDigi >(0);
      static ::ROOT::TGenericClassInfo 
         instance("MyCastorDigi", ::MyCastorDigi::Class_Version(), "UATree/UADataFormat/interface/MyCastorDigi.h", 8,
                  typeid(::MyCastorDigi), DefineBehavior(ptr, ptr),
                  &::MyCastorDigi::Dictionary, isa_proxy, 4,
                  sizeof(::MyCastorDigi) );
      instance.SetNew(&new_MyCastorDigi);
      instance.SetNewArray(&newArray_MyCastorDigi);
      instance.SetDelete(&delete_MyCastorDigi);
      instance.SetDeleteArray(&deleteArray_MyCastorDigi);
      instance.SetDestructor(&destruct_MyCastorDigi);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MyCastorDigi*)
   {
      return GenerateInitInstanceLocal((::MyCastorDigi*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::MyCastorDigi*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_MyCastorJet(void *p = 0);
   static void *newArray_MyCastorJet(Long_t size, void *p);
   static void delete_MyCastorJet(void *p);
   static void deleteArray_MyCastorJet(void *p);
   static void destruct_MyCastorJet(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MyCastorJet*)
   {
      ::MyCastorJet *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::MyCastorJet >(0);
      static ::ROOT::TGenericClassInfo 
         instance("MyCastorJet", ::MyCastorJet::Class_Version(), "UATree/UADataFormat/interface/MyCastorJet.h", 8,
                  typeid(::MyCastorJet), DefineBehavior(ptr, ptr),
                  &::MyCastorJet::Dictionary, isa_proxy, 4,
                  sizeof(::MyCastorJet) );
      instance.SetNew(&new_MyCastorJet);
      instance.SetNewArray(&newArray_MyCastorJet);
      instance.SetDelete(&delete_MyCastorJet);
      instance.SetDeleteArray(&deleteArray_MyCastorJet);
      instance.SetDestructor(&destruct_MyCastorJet);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MyCastorJet*)
   {
      return GenerateInitInstanceLocal((::MyCastorJet*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::MyCastorJet*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_MyCastorRecHit(void *p = 0);
   static void *newArray_MyCastorRecHit(Long_t size, void *p);
   static void delete_MyCastorRecHit(void *p);
   static void deleteArray_MyCastorRecHit(void *p);
   static void destruct_MyCastorRecHit(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MyCastorRecHit*)
   {
      ::MyCastorRecHit *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::MyCastorRecHit >(0);
      static ::ROOT::TGenericClassInfo 
         instance("MyCastorRecHit", ::MyCastorRecHit::Class_Version(), "UATree/UADataFormat/interface/MyCastorRecHit.h", 9,
                  typeid(::MyCastorRecHit), DefineBehavior(ptr, ptr),
                  &::MyCastorRecHit::Dictionary, isa_proxy, 4,
                  sizeof(::MyCastorRecHit) );
      instance.SetNew(&new_MyCastorRecHit);
      instance.SetNewArray(&newArray_MyCastorRecHit);
      instance.SetDelete(&delete_MyCastorRecHit);
      instance.SetDeleteArray(&deleteArray_MyCastorRecHit);
      instance.SetDestructor(&destruct_MyCastorRecHit);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MyCastorRecHit*)
   {
      return GenerateInitInstanceLocal((::MyCastorRecHit*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::MyCastorRecHit*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_MyDiJet(void *p = 0);
   static void *newArray_MyDiJet(Long_t size, void *p);
   static void delete_MyDiJet(void *p);
   static void deleteArray_MyDiJet(void *p);
   static void destruct_MyDiJet(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MyDiJet*)
   {
      ::MyDiJet *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::MyDiJet >(0);
      static ::ROOT::TGenericClassInfo 
         instance("MyDiJet", ::MyDiJet::Class_Version(), "UATree/UADataFormat/interface/MyDiJet.h", 7,
                  typeid(::MyDiJet), DefineBehavior(ptr, ptr),
                  &::MyDiJet::Dictionary, isa_proxy, 4,
                  sizeof(::MyDiJet) );
      instance.SetNew(&new_MyDiJet);
      instance.SetNewArray(&newArray_MyDiJet);
      instance.SetDelete(&delete_MyDiJet);
      instance.SetDeleteArray(&deleteArray_MyDiJet);
      instance.SetDestructor(&destruct_MyDiJet);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MyDiJet*)
   {
      return GenerateInitInstanceLocal((::MyDiJet*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::MyDiJet*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_MyEvtId(void *p = 0);
   static void *newArray_MyEvtId(Long_t size, void *p);
   static void delete_MyEvtId(void *p);
   static void deleteArray_MyEvtId(void *p);
   static void destruct_MyEvtId(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MyEvtId*)
   {
      ::MyEvtId *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::MyEvtId >(0);
      static ::ROOT::TGenericClassInfo 
         instance("MyEvtId", ::MyEvtId::Class_Version(), "UATree/UADataFormat/interface/MyEvtId.h", 9,
                  typeid(::MyEvtId), DefineBehavior(ptr, ptr),
                  &::MyEvtId::Dictionary, isa_proxy, 4,
                  sizeof(::MyEvtId) );
      instance.SetNew(&new_MyEvtId);
      instance.SetNewArray(&newArray_MyEvtId);
      instance.SetDelete(&delete_MyEvtId);
      instance.SetDeleteArray(&deleteArray_MyEvtId);
      instance.SetDestructor(&destruct_MyEvtId);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MyEvtId*)
   {
      return GenerateInitInstanceLocal((::MyEvtId*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::MyEvtId*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_MyFwdGap(void *p = 0);
   static void *newArray_MyFwdGap(Long_t size, void *p);
   static void delete_MyFwdGap(void *p);
   static void deleteArray_MyFwdGap(void *p);
   static void destruct_MyFwdGap(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MyFwdGap*)
   {
      ::MyFwdGap *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::MyFwdGap >(0);
      static ::ROOT::TGenericClassInfo 
         instance("MyFwdGap", ::MyFwdGap::Class_Version(), "UATree/UADataFormat/interface/MyFwdGap.h", 6,
                  typeid(::MyFwdGap), DefineBehavior(ptr, ptr),
                  &::MyFwdGap::Dictionary, isa_proxy, 4,
                  sizeof(::MyFwdGap) );
      instance.SetNew(&new_MyFwdGap);
      instance.SetNewArray(&newArray_MyFwdGap);
      instance.SetDelete(&delete_MyFwdGap);
      instance.SetDeleteArray(&deleteArray_MyFwdGap);
      instance.SetDestructor(&destruct_MyFwdGap);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MyFwdGap*)
   {
      return GenerateInitInstanceLocal((::MyFwdGap*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::MyFwdGap*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_MyGenKin(void *p = 0);
   static void *newArray_MyGenKin(Long_t size, void *p);
   static void delete_MyGenKin(void *p);
   static void deleteArray_MyGenKin(void *p);
   static void destruct_MyGenKin(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MyGenKin*)
   {
      ::MyGenKin *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::MyGenKin >(0);
      static ::ROOT::TGenericClassInfo 
         instance("MyGenKin", ::MyGenKin::Class_Version(), "UATree/UADataFormat/interface/MyGenKin.h", 7,
                  typeid(::MyGenKin), DefineBehavior(ptr, ptr),
                  &::MyGenKin::Dictionary, isa_proxy, 4,
                  sizeof(::MyGenKin) );
      instance.SetNew(&new_MyGenKin);
      instance.SetNewArray(&newArray_MyGenKin);
      instance.SetDelete(&delete_MyGenKin);
      instance.SetDeleteArray(&deleteArray_MyGenKin);
      instance.SetDestructor(&destruct_MyGenKin);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MyGenKin*)
   {
      return GenerateInitInstanceLocal((::MyGenKin*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::MyGenKin*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_MyPUSumInfo(void *p = 0);
   static void *newArray_MyPUSumInfo(Long_t size, void *p);
   static void delete_MyPUSumInfo(void *p);
   static void deleteArray_MyPUSumInfo(void *p);
   static void destruct_MyPUSumInfo(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MyPUSumInfo*)
   {
      ::MyPUSumInfo *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::MyPUSumInfo >(0);
      static ::ROOT::TGenericClassInfo 
         instance("MyPUSumInfo", ::MyPUSumInfo::Class_Version(), "UATree/UADataFormat/interface/MyPUSumInfo.h", 9,
                  typeid(::MyPUSumInfo), DefineBehavior(ptr, ptr),
                  &::MyPUSumInfo::Dictionary, isa_proxy, 4,
                  sizeof(::MyPUSumInfo) );
      instance.SetNew(&new_MyPUSumInfo);
      instance.SetNewArray(&newArray_MyPUSumInfo);
      instance.SetDelete(&delete_MyPUSumInfo);
      instance.SetDeleteArray(&deleteArray_MyPUSumInfo);
      instance.SetDestructor(&destruct_MyPUSumInfo);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MyPUSumInfo*)
   {
      return GenerateInitInstanceLocal((::MyPUSumInfo*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::MyPUSumInfo*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_MyMet(void *p = 0);
   static void *newArray_MyMet(Long_t size, void *p);
   static void delete_MyMet(void *p);
   static void deleteArray_MyMet(void *p);
   static void destruct_MyMet(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MyMet*)
   {
      ::MyMet *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::MyMet >(0);
      static ::ROOT::TGenericClassInfo 
         instance("MyMet", ::MyMet::Class_Version(), "UATree/UADataFormat/interface/MyMet.h", 6,
                  typeid(::MyMet), DefineBehavior(ptr, ptr),
                  &::MyMet::Dictionary, isa_proxy, 4,
                  sizeof(::MyMet) );
      instance.SetNew(&new_MyMet);
      instance.SetNewArray(&newArray_MyMet);
      instance.SetDelete(&delete_MyMet);
      instance.SetDeleteArray(&deleteArray_MyMet);
      instance.SetDestructor(&destruct_MyMet);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MyMet*)
   {
      return GenerateInitInstanceLocal((::MyMet*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::MyMet*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_MyGenMet(void *p = 0);
   static void *newArray_MyGenMet(Long_t size, void *p);
   static void delete_MyGenMet(void *p);
   static void deleteArray_MyGenMet(void *p);
   static void destruct_MyGenMet(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MyGenMet*)
   {
      ::MyGenMet *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::MyGenMet >(0);
      static ::ROOT::TGenericClassInfo 
         instance("MyGenMet", ::MyGenMet::Class_Version(), "UATree/UADataFormat/interface/MyGenMet.h", 7,
                  typeid(::MyGenMet), DefineBehavior(ptr, ptr),
                  &::MyGenMet::Dictionary, isa_proxy, 4,
                  sizeof(::MyGenMet) );
      instance.SetNew(&new_MyGenMet);
      instance.SetNewArray(&newArray_MyGenMet);
      instance.SetDelete(&delete_MyGenMet);
      instance.SetDeleteArray(&deleteArray_MyGenMet);
      instance.SetDestructor(&destruct_MyGenMet);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MyGenMet*)
   {
      return GenerateInitInstanceLocal((::MyGenMet*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::MyGenMet*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_MyGenPart(void *p = 0);
   static void *newArray_MyGenPart(Long_t size, void *p);
   static void delete_MyGenPart(void *p);
   static void deleteArray_MyGenPart(void *p);
   static void destruct_MyGenPart(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MyGenPart*)
   {
      ::MyGenPart *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::MyGenPart >(0);
      static ::ROOT::TGenericClassInfo 
         instance("MyGenPart", ::MyGenPart::Class_Version(), "UATree/UADataFormat/interface/MyGenPart.h", 7,
                  typeid(::MyGenPart), DefineBehavior(ptr, ptr),
                  &::MyGenPart::Dictionary, isa_proxy, 4,
                  sizeof(::MyGenPart) );
      instance.SetNew(&new_MyGenPart);
      instance.SetNewArray(&newArray_MyGenPart);
      instance.SetDelete(&delete_MyGenPart);
      instance.SetDeleteArray(&deleteArray_MyGenPart);
      instance.SetDestructor(&destruct_MyGenPart);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MyGenPart*)
   {
      return GenerateInitInstanceLocal((::MyGenPart*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::MyGenPart*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_MyGenJet(void *p = 0);
   static void *newArray_MyGenJet(Long_t size, void *p);
   static void delete_MyGenJet(void *p);
   static void deleteArray_MyGenJet(void *p);
   static void destruct_MyGenJet(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MyGenJet*)
   {
      ::MyGenJet *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::MyGenJet >(0);
      static ::ROOT::TGenericClassInfo 
         instance("MyGenJet", ::MyGenJet::Class_Version(), "UATree/UADataFormat/interface/MyGenJet.h", 9,
                  typeid(::MyGenJet), DefineBehavior(ptr, ptr),
                  &::MyGenJet::Dictionary, isa_proxy, 4,
                  sizeof(::MyGenJet) );
      instance.SetNew(&new_MyGenJet);
      instance.SetNewArray(&newArray_MyGenJet);
      instance.SetDelete(&delete_MyGenJet);
      instance.SetDeleteArray(&deleteArray_MyGenJet);
      instance.SetDestructor(&destruct_MyGenJet);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MyGenJet*)
   {
      return GenerateInitInstanceLocal((::MyGenJet*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::MyGenJet*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_MyHLTrig(void *p = 0);
   static void *newArray_MyHLTrig(Long_t size, void *p);
   static void delete_MyHLTrig(void *p);
   static void deleteArray_MyHLTrig(void *p);
   static void destruct_MyHLTrig(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MyHLTrig*)
   {
      ::MyHLTrig *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::MyHLTrig >(0);
      static ::ROOT::TGenericClassInfo 
         instance("MyHLTrig", ::MyHLTrig::Class_Version(), "UATree/UADataFormat/interface/MyHLTrig.h", 8,
                  typeid(::MyHLTrig), DefineBehavior(ptr, ptr),
                  &::MyHLTrig::Dictionary, isa_proxy, 4,
                  sizeof(::MyHLTrig) );
      instance.SetNew(&new_MyHLTrig);
      instance.SetNewArray(&newArray_MyHLTrig);
      instance.SetDelete(&delete_MyHLTrig);
      instance.SetDeleteArray(&deleteArray_MyHLTrig);
      instance.SetDestructor(&destruct_MyHLTrig);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MyHLTrig*)
   {
      return GenerateInitInstanceLocal((::MyHLTrig*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::MyHLTrig*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_MyL1Trig(void *p = 0);
   static void *newArray_MyL1Trig(Long_t size, void *p);
   static void delete_MyL1Trig(void *p);
   static void deleteArray_MyL1Trig(void *p);
   static void destruct_MyL1Trig(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MyL1Trig*)
   {
      ::MyL1Trig *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::MyL1Trig >(0);
      static ::ROOT::TGenericClassInfo 
         instance("MyL1Trig", ::MyL1Trig::Class_Version(), "UATree/UADataFormat/interface/MyL1Trig.h", 8,
                  typeid(::MyL1Trig), DefineBehavior(ptr, ptr),
                  &::MyL1Trig::Dictionary, isa_proxy, 4,
                  sizeof(::MyL1Trig) );
      instance.SetNew(&new_MyL1Trig);
      instance.SetNewArray(&newArray_MyL1Trig);
      instance.SetDelete(&delete_MyL1Trig);
      instance.SetDeleteArray(&deleteArray_MyL1Trig);
      instance.SetDestructor(&destruct_MyL1Trig);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MyL1Trig*)
   {
      return GenerateInitInstanceLocal((::MyL1Trig*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::MyL1Trig*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_MyL1TrigOld(void *p = 0);
   static void *newArray_MyL1TrigOld(Long_t size, void *p);
   static void delete_MyL1TrigOld(void *p);
   static void deleteArray_MyL1TrigOld(void *p);
   static void destruct_MyL1TrigOld(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MyL1TrigOld*)
   {
      ::MyL1TrigOld *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::MyL1TrigOld >(0);
      static ::ROOT::TGenericClassInfo 
         instance("MyL1TrigOld", ::MyL1TrigOld::Class_Version(), "UATree/UADataFormat/interface/MyL1TrigOld.h", 7,
                  typeid(::MyL1TrigOld), DefineBehavior(ptr, ptr),
                  &::MyL1TrigOld::Dictionary, isa_proxy, 4,
                  sizeof(::MyL1TrigOld) );
      instance.SetNew(&new_MyL1TrigOld);
      instance.SetNewArray(&newArray_MyL1TrigOld);
      instance.SetDelete(&delete_MyL1TrigOld);
      instance.SetDeleteArray(&deleteArray_MyL1TrigOld);
      instance.SetDestructor(&destruct_MyL1TrigOld);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MyL1TrigOld*)
   {
      return GenerateInitInstanceLocal((::MyL1TrigOld*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::MyL1TrigOld*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_MyMITEvtSel(void *p = 0);
   static void *newArray_MyMITEvtSel(Long_t size, void *p);
   static void delete_MyMITEvtSel(void *p);
   static void deleteArray_MyMITEvtSel(void *p);
   static void destruct_MyMITEvtSel(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MyMITEvtSel*)
   {
      ::MyMITEvtSel *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::MyMITEvtSel >(0);
      static ::ROOT::TGenericClassInfo 
         instance("MyMITEvtSel", ::MyMITEvtSel::Class_Version(), "UATree/UADataFormat/interface/MyMITEvtSel.h", 6,
                  typeid(::MyMITEvtSel), DefineBehavior(ptr, ptr),
                  &::MyMITEvtSel::Dictionary, isa_proxy, 4,
                  sizeof(::MyMITEvtSel) );
      instance.SetNew(&new_MyMITEvtSel);
      instance.SetNewArray(&newArray_MyMITEvtSel);
      instance.SetDelete(&delete_MyMITEvtSel);
      instance.SetDeleteArray(&deleteArray_MyMITEvtSel);
      instance.SetDestructor(&destruct_MyMITEvtSel);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MyMITEvtSel*)
   {
      return GenerateInitInstanceLocal((::MyMITEvtSel*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::MyMITEvtSel*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_MyPart(void *p = 0);
   static void *newArray_MyPart(Long_t size, void *p);
   static void delete_MyPart(void *p);
   static void deleteArray_MyPart(void *p);
   static void destruct_MyPart(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MyPart*)
   {
      ::MyPart *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::MyPart >(0);
      static ::ROOT::TGenericClassInfo 
         instance("MyPart", ::MyPart::Class_Version(), "UATree/UADataFormat/interface/MyPart.h", 8,
                  typeid(::MyPart), DefineBehavior(ptr, ptr),
                  &::MyPart::Dictionary, isa_proxy, 4,
                  sizeof(::MyPart) );
      instance.SetNew(&new_MyPart);
      instance.SetNewArray(&newArray_MyPart);
      instance.SetDelete(&delete_MyPart);
      instance.SetDeleteArray(&deleteArray_MyPart);
      instance.SetDestructor(&destruct_MyPart);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MyPart*)
   {
      return GenerateInitInstanceLocal((::MyPart*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::MyPart*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_MySimVertex(void *p = 0);
   static void *newArray_MySimVertex(Long_t size, void *p);
   static void delete_MySimVertex(void *p);
   static void deleteArray_MySimVertex(void *p);
   static void destruct_MySimVertex(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MySimVertex*)
   {
      ::MySimVertex *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::MySimVertex >(0);
      static ::ROOT::TGenericClassInfo 
         instance("MySimVertex", ::MySimVertex::Class_Version(), "UATree/UADataFormat/interface/MySimVertex.h", 6,
                  typeid(::MySimVertex), DefineBehavior(ptr, ptr),
                  &::MySimVertex::Dictionary, isa_proxy, 4,
                  sizeof(::MySimVertex) );
      instance.SetNew(&new_MySimVertex);
      instance.SetNewArray(&newArray_MySimVertex);
      instance.SetDelete(&delete_MySimVertex);
      instance.SetDeleteArray(&deleteArray_MySimVertex);
      instance.SetDestructor(&destruct_MySimVertex);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MySimVertex*)
   {
      return GenerateInitInstanceLocal((::MySimVertex*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::MySimVertex*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_MyVertex(void *p = 0);
   static void *newArray_MyVertex(Long_t size, void *p);
   static void delete_MyVertex(void *p);
   static void deleteArray_MyVertex(void *p);
   static void destruct_MyVertex(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MyVertex*)
   {
      ::MyVertex *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::MyVertex >(0);
      static ::ROOT::TGenericClassInfo 
         instance("MyVertex", ::MyVertex::Class_Version(), "UATree/UADataFormat/interface/MyVertex.h", 6,
                  typeid(::MyVertex), DefineBehavior(ptr, ptr),
                  &::MyVertex::Dictionary, isa_proxy, 4,
                  sizeof(::MyVertex) );
      instance.SetNew(&new_MyVertex);
      instance.SetNewArray(&newArray_MyVertex);
      instance.SetDelete(&delete_MyVertex);
      instance.SetDeleteArray(&deleteArray_MyVertex);
      instance.SetDestructor(&destruct_MyVertex);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MyVertex*)
   {
      return GenerateInitInstanceLocal((::MyVertex*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::MyVertex*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_MyTracks(void *p = 0);
   static void *newArray_MyTracks(Long_t size, void *p);
   static void delete_MyTracks(void *p);
   static void deleteArray_MyTracks(void *p);
   static void destruct_MyTracks(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MyTracks*)
   {
      ::MyTracks *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::MyTracks >(0);
      static ::ROOT::TGenericClassInfo 
         instance("MyTracks", ::MyTracks::Class_Version(), "UATree/UADataFormat/interface/MyTracks.h", 11,
                  typeid(::MyTracks), DefineBehavior(ptr, ptr),
                  &::MyTracks::Dictionary, isa_proxy, 4,
                  sizeof(::MyTracks) );
      instance.SetNew(&new_MyTracks);
      instance.SetNewArray(&newArray_MyTracks);
      instance.SetDelete(&delete_MyTracks);
      instance.SetDeleteArray(&deleteArray_MyTracks);
      instance.SetDestructor(&destruct_MyTracks);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MyTracks*)
   {
      return GenerateInitInstanceLocal((::MyTracks*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::MyTracks*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_MyElectron(void *p = 0);
   static void *newArray_MyElectron(Long_t size, void *p);
   static void delete_MyElectron(void *p);
   static void deleteArray_MyElectron(void *p);
   static void destruct_MyElectron(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MyElectron*)
   {
      ::MyElectron *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::MyElectron >(0);
      static ::ROOT::TGenericClassInfo 
         instance("MyElectron", ::MyElectron::Class_Version(), "UATree/UADataFormat/interface/MyElectron.h", 8,
                  typeid(::MyElectron), DefineBehavior(ptr, ptr),
                  &::MyElectron::Dictionary, isa_proxy, 4,
                  sizeof(::MyElectron) );
      instance.SetNew(&new_MyElectron);
      instance.SetNewArray(&newArray_MyElectron);
      instance.SetDelete(&delete_MyElectron);
      instance.SetDeleteArray(&deleteArray_MyElectron);
      instance.SetDestructor(&destruct_MyElectron);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MyElectron*)
   {
      return GenerateInitInstanceLocal((::MyElectron*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::MyElectron*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_MyMuon(void *p = 0);
   static void *newArray_MyMuon(Long_t size, void *p);
   static void delete_MyMuon(void *p);
   static void deleteArray_MyMuon(void *p);
   static void destruct_MyMuon(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MyMuon*)
   {
      ::MyMuon *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::MyMuon >(0);
      static ::ROOT::TGenericClassInfo 
         instance("MyMuon", ::MyMuon::Class_Version(), "UATree/UADataFormat/interface/MyMuon.h", 8,
                  typeid(::MyMuon), DefineBehavior(ptr, ptr),
                  &::MyMuon::Dictionary, isa_proxy, 4,
                  sizeof(::MyMuon) );
      instance.SetNew(&new_MyMuon);
      instance.SetNewArray(&newArray_MyMuon);
      instance.SetDelete(&delete_MyMuon);
      instance.SetDeleteArray(&deleteArray_MyMuon);
      instance.SetDestructor(&destruct_MyMuon);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MyMuon*)
   {
      return GenerateInitInstanceLocal((::MyMuon*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::MyMuon*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_MyBaseJet(void *p = 0);
   static void *newArray_MyBaseJet(Long_t size, void *p);
   static void delete_MyBaseJet(void *p);
   static void deleteArray_MyBaseJet(void *p);
   static void destruct_MyBaseJet(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MyBaseJet*)
   {
      ::MyBaseJet *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::MyBaseJet >(0);
      static ::ROOT::TGenericClassInfo 
         instance("MyBaseJet", ::MyBaseJet::Class_Version(), "UATree/UADataFormat/interface/MyBaseJet.h", 6,
                  typeid(::MyBaseJet), DefineBehavior(ptr, ptr),
                  &::MyBaseJet::Dictionary, isa_proxy, 4,
                  sizeof(::MyBaseJet) );
      instance.SetNew(&new_MyBaseJet);
      instance.SetNewArray(&newArray_MyBaseJet);
      instance.SetDelete(&delete_MyBaseJet);
      instance.SetDeleteArray(&deleteArray_MyBaseJet);
      instance.SetDestructor(&destruct_MyBaseJet);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MyBaseJet*)
   {
      return GenerateInitInstanceLocal((::MyBaseJet*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::MyBaseJet*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_MyJet(void *p = 0);
   static void *newArray_MyJet(Long_t size, void *p);
   static void delete_MyJet(void *p);
   static void deleteArray_MyJet(void *p);
   static void destruct_MyJet(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MyJet*)
   {
      ::MyJet *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::MyJet >(0);
      static ::ROOT::TGenericClassInfo 
         instance("MyJet", ::MyJet::Class_Version(), "UATree/UADataFormat/interface/MyJet.h", 13,
                  typeid(::MyJet), DefineBehavior(ptr, ptr),
                  &::MyJet::Dictionary, isa_proxy, 4,
                  sizeof(::MyJet) );
      instance.SetNew(&new_MyJet);
      instance.SetNewArray(&newArray_MyJet);
      instance.SetDelete(&delete_MyJet);
      instance.SetDeleteArray(&deleteArray_MyJet);
      instance.SetDestructor(&destruct_MyJet);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MyJet*)
   {
      return GenerateInitInstanceLocal((::MyJet*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::MyJet*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_MyCaloJet(void *p = 0);
   static void *newArray_MyCaloJet(Long_t size, void *p);
   static void delete_MyCaloJet(void *p);
   static void deleteArray_MyCaloJet(void *p);
   static void destruct_MyCaloJet(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MyCaloJet*)
   {
      ::MyCaloJet *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::MyCaloJet >(0);
      static ::ROOT::TGenericClassInfo 
         instance("MyCaloJet", ::MyCaloJet::Class_Version(), "UATree/UADataFormat/interface/MyCaloJet.h", 6,
                  typeid(::MyCaloJet), DefineBehavior(ptr, ptr),
                  &::MyCaloJet::Dictionary, isa_proxy, 4,
                  sizeof(::MyCaloJet) );
      instance.SetNew(&new_MyCaloJet);
      instance.SetNewArray(&newArray_MyCaloJet);
      instance.SetDelete(&delete_MyCaloJet);
      instance.SetDeleteArray(&deleteArray_MyCaloJet);
      instance.SetDestructor(&destruct_MyCaloJet);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MyCaloJet*)
   {
      return GenerateInitInstanceLocal((::MyCaloJet*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::MyCaloJet*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_MyTrackJet(void *p = 0);
   static void *newArray_MyTrackJet(Long_t size, void *p);
   static void delete_MyTrackJet(void *p);
   static void deleteArray_MyTrackJet(void *p);
   static void destruct_MyTrackJet(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MyTrackJet*)
   {
      ::MyTrackJet *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::MyTrackJet >(0);
      static ::ROOT::TGenericClassInfo 
         instance("MyTrackJet", ::MyTrackJet::Class_Version(), "UATree/UADataFormat/interface/MyTrackJet.h", 10,
                  typeid(::MyTrackJet), DefineBehavior(ptr, ptr),
                  &::MyTrackJet::Dictionary, isa_proxy, 4,
                  sizeof(::MyTrackJet) );
      instance.SetNew(&new_MyTrackJet);
      instance.SetNewArray(&newArray_MyTrackJet);
      instance.SetDelete(&delete_MyTrackJet);
      instance.SetDeleteArray(&deleteArray_MyTrackJet);
      instance.SetDestructor(&destruct_MyTrackJet);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MyTrackJet*)
   {
      return GenerateInitInstanceLocal((::MyTrackJet*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::MyTrackJet*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_MyPFJet(void *p = 0);
   static void *newArray_MyPFJet(Long_t size, void *p);
   static void delete_MyPFJet(void *p);
   static void deleteArray_MyPFJet(void *p);
   static void destruct_MyPFJet(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MyPFJet*)
   {
      ::MyPFJet *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::MyPFJet >(0);
      static ::ROOT::TGenericClassInfo 
         instance("MyPFJet", ::MyPFJet::Class_Version(), "UATree/UADataFormat/interface/MyPFJet.h", 8,
                  typeid(::MyPFJet), DefineBehavior(ptr, ptr),
                  &::MyPFJet::Dictionary, isa_proxy, 4,
                  sizeof(::MyPFJet) );
      instance.SetNew(&new_MyPFJet);
      instance.SetNewArray(&newArray_MyPFJet);
      instance.SetDelete(&delete_MyPFJet);
      instance.SetDeleteArray(&deleteArray_MyPFJet);
      instance.SetDestructor(&destruct_MyPFJet);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MyPFJet*)
   {
      return GenerateInitInstanceLocal((::MyPFJet*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::MyPFJet*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_MyPFCand(void *p = 0);
   static void *newArray_MyPFCand(Long_t size, void *p);
   static void delete_MyPFCand(void *p);
   static void deleteArray_MyPFCand(void *p);
   static void destruct_MyPFCand(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MyPFCand*)
   {
      ::MyPFCand *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::MyPFCand >(0);
      static ::ROOT::TGenericClassInfo 
         instance("MyPFCand", ::MyPFCand::Class_Version(), "UATree/UADataFormat/interface/MyPFCand.h", 6,
                  typeid(::MyPFCand), DefineBehavior(ptr, ptr),
                  &::MyPFCand::Dictionary, isa_proxy, 4,
                  sizeof(::MyPFCand) );
      instance.SetNew(&new_MyPFCand);
      instance.SetNewArray(&newArray_MyPFCand);
      instance.SetDelete(&delete_MyPFCand);
      instance.SetDeleteArray(&deleteArray_MyPFCand);
      instance.SetDestructor(&destruct_MyPFCand);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MyPFCand*)
   {
      return GenerateInitInstanceLocal((::MyPFCand*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::MyPFCand*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_MyCaloTower(void *p = 0);
   static void *newArray_MyCaloTower(Long_t size, void *p);
   static void delete_MyCaloTower(void *p);
   static void deleteArray_MyCaloTower(void *p);
   static void destruct_MyCaloTower(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MyCaloTower*)
   {
      ::MyCaloTower *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::MyCaloTower >(0);
      static ::ROOT::TGenericClassInfo 
         instance("MyCaloTower", ::MyCaloTower::Class_Version(), "UATree/UADataFormat/interface/MyCaloTower.h", 9,
                  typeid(::MyCaloTower), DefineBehavior(ptr, ptr),
                  &::MyCaloTower::Dictionary, isa_proxy, 4,
                  sizeof(::MyCaloTower) );
      instance.SetNew(&new_MyCaloTower);
      instance.SetNewArray(&newArray_MyCaloTower);
      instance.SetDelete(&delete_MyCaloTower);
      instance.SetDeleteArray(&deleteArray_MyCaloTower);
      instance.SetDestructor(&destruct_MyCaloTower);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MyCaloTower*)
   {
      return GenerateInitInstanceLocal((::MyCaloTower*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::MyCaloTower*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_MyKshorts(void *p = 0);
   static void *newArray_MyKshorts(Long_t size, void *p);
   static void delete_MyKshorts(void *p);
   static void deleteArray_MyKshorts(void *p);
   static void destruct_MyKshorts(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MyKshorts*)
   {
      ::MyKshorts *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::MyKshorts >(0);
      static ::ROOT::TGenericClassInfo 
         instance("MyKshorts", ::MyKshorts::Class_Version(), "UATree/UADataFormat/interface/MyKshorts.h", 11,
                  typeid(::MyKshorts), DefineBehavior(ptr, ptr),
                  &::MyKshorts::Dictionary, isa_proxy, 4,
                  sizeof(::MyKshorts) );
      instance.SetNew(&new_MyKshorts);
      instance.SetNewArray(&newArray_MyKshorts);
      instance.SetDelete(&delete_MyKshorts);
      instance.SetDeleteArray(&deleteArray_MyKshorts);
      instance.SetDestructor(&destruct_MyKshorts);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MyKshorts*)
   {
      return GenerateInitInstanceLocal((::MyKshorts*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::MyKshorts*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_MyLambdas(void *p = 0);
   static void *newArray_MyLambdas(Long_t size, void *p);
   static void delete_MyLambdas(void *p);
   static void deleteArray_MyLambdas(void *p);
   static void destruct_MyLambdas(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MyLambdas*)
   {
      ::MyLambdas *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::MyLambdas >(0);
      static ::ROOT::TGenericClassInfo 
         instance("MyLambdas", ::MyLambdas::Class_Version(), "UATree/UADataFormat/interface/MyLambdas.h", 11,
                  typeid(::MyLambdas), DefineBehavior(ptr, ptr),
                  &::MyLambdas::Dictionary, isa_proxy, 4,
                  sizeof(::MyLambdas) );
      instance.SetNew(&new_MyLambdas);
      instance.SetNewArray(&newArray_MyLambdas);
      instance.SetDelete(&delete_MyLambdas);
      instance.SetDeleteArray(&deleteArray_MyLambdas);
      instance.SetDestructor(&destruct_MyLambdas);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MyLambdas*)
   {
      return GenerateInitInstanceLocal((::MyLambdas*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::MyLambdas*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_MyFSCHit(void *p = 0);
   static void *newArray_MyFSCHit(Long_t size, void *p);
   static void delete_MyFSCHit(void *p);
   static void deleteArray_MyFSCHit(void *p);
   static void destruct_MyFSCHit(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MyFSCHit*)
   {
      ::MyFSCHit *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::MyFSCHit >(0);
      static ::ROOT::TGenericClassInfo 
         instance("MyFSCHit", ::MyFSCHit::Class_Version(), "UATree/UADataFormat/interface/MyFSCHit.h", 6,
                  typeid(::MyFSCHit), DefineBehavior(ptr, ptr),
                  &::MyFSCHit::Dictionary, isa_proxy, 4,
                  sizeof(::MyFSCHit) );
      instance.SetNew(&new_MyFSCHit);
      instance.SetNewArray(&newArray_MyFSCHit);
      instance.SetDelete(&delete_MyFSCHit);
      instance.SetDeleteArray(&deleteArray_MyFSCHit);
      instance.SetDestructor(&destruct_MyFSCHit);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MyFSCHit*)
   {
      return GenerateInitInstanceLocal((::MyFSCHit*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::MyFSCHit*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_MyFSCDigi(void *p = 0);
   static void *newArray_MyFSCDigi(Long_t size, void *p);
   static void delete_MyFSCDigi(void *p);
   static void deleteArray_MyFSCDigi(void *p);
   static void destruct_MyFSCDigi(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MyFSCDigi*)
   {
      ::MyFSCDigi *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::MyFSCDigi >(0);
      static ::ROOT::TGenericClassInfo 
         instance("MyFSCDigi", ::MyFSCDigi::Class_Version(), "UATree/UADataFormat/interface/MyFSCDigi.h", 8,
                  typeid(::MyFSCDigi), DefineBehavior(ptr, ptr),
                  &::MyFSCDigi::Dictionary, isa_proxy, 4,
                  sizeof(::MyFSCDigi) );
      instance.SetNew(&new_MyFSCDigi);
      instance.SetNewArray(&newArray_MyFSCDigi);
      instance.SetDelete(&delete_MyFSCDigi);
      instance.SetDeleteArray(&deleteArray_MyFSCDigi);
      instance.SetDestructor(&destruct_MyFSCDigi);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MyFSCDigi*)
   {
      return GenerateInitInstanceLocal((::MyFSCDigi*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::MyFSCDigi*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_MyFSCInfo(void *p = 0);
   static void *newArray_MyFSCInfo(Long_t size, void *p);
   static void delete_MyFSCInfo(void *p);
   static void deleteArray_MyFSCInfo(void *p);
   static void destruct_MyFSCInfo(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MyFSCInfo*)
   {
      ::MyFSCInfo *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::MyFSCInfo >(0);
      static ::ROOT::TGenericClassInfo 
         instance("MyFSCInfo", ::MyFSCInfo::Class_Version(), "UATree/UADataFormat/interface/MyFSCInfo.h", 8,
                  typeid(::MyFSCInfo), DefineBehavior(ptr, ptr),
                  &::MyFSCInfo::Dictionary, isa_proxy, 4,
                  sizeof(::MyFSCInfo) );
      instance.SetNew(&new_MyFSCInfo);
      instance.SetNewArray(&newArray_MyFSCInfo);
      instance.SetDelete(&delete_MyFSCInfo);
      instance.SetDeleteArray(&deleteArray_MyFSCInfo);
      instance.SetDestructor(&destruct_MyFSCInfo);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MyFSCInfo*)
   {
      return GenerateInitInstanceLocal((::MyFSCInfo*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::MyFSCInfo*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr MyBeamSpot::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *MyBeamSpot::Class_Name()
{
   return "MyBeamSpot";
}

//______________________________________________________________________________
const char *MyBeamSpot::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyBeamSpot*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int MyBeamSpot::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyBeamSpot*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *MyBeamSpot::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyBeamSpot*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *MyBeamSpot::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyBeamSpot*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr MyCastorDigi::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *MyCastorDigi::Class_Name()
{
   return "MyCastorDigi";
}

//______________________________________________________________________________
const char *MyCastorDigi::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyCastorDigi*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int MyCastorDigi::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyCastorDigi*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *MyCastorDigi::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyCastorDigi*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *MyCastorDigi::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyCastorDigi*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr MyCastorJet::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *MyCastorJet::Class_Name()
{
   return "MyCastorJet";
}

//______________________________________________________________________________
const char *MyCastorJet::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyCastorJet*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int MyCastorJet::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyCastorJet*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *MyCastorJet::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyCastorJet*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *MyCastorJet::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyCastorJet*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr MyCastorRecHit::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *MyCastorRecHit::Class_Name()
{
   return "MyCastorRecHit";
}

//______________________________________________________________________________
const char *MyCastorRecHit::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyCastorRecHit*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int MyCastorRecHit::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyCastorRecHit*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *MyCastorRecHit::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyCastorRecHit*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *MyCastorRecHit::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyCastorRecHit*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr MyDiJet::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *MyDiJet::Class_Name()
{
   return "MyDiJet";
}

//______________________________________________________________________________
const char *MyDiJet::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyDiJet*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int MyDiJet::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyDiJet*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *MyDiJet::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyDiJet*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *MyDiJet::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyDiJet*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr MyEvtId::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *MyEvtId::Class_Name()
{
   return "MyEvtId";
}

//______________________________________________________________________________
const char *MyEvtId::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyEvtId*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int MyEvtId::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyEvtId*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *MyEvtId::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyEvtId*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *MyEvtId::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyEvtId*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr MyFwdGap::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *MyFwdGap::Class_Name()
{
   return "MyFwdGap";
}

//______________________________________________________________________________
const char *MyFwdGap::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyFwdGap*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int MyFwdGap::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyFwdGap*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *MyFwdGap::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyFwdGap*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *MyFwdGap::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyFwdGap*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr MyGenKin::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *MyGenKin::Class_Name()
{
   return "MyGenKin";
}

//______________________________________________________________________________
const char *MyGenKin::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyGenKin*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int MyGenKin::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyGenKin*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *MyGenKin::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyGenKin*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *MyGenKin::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyGenKin*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr MyPUSumInfo::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *MyPUSumInfo::Class_Name()
{
   return "MyPUSumInfo";
}

//______________________________________________________________________________
const char *MyPUSumInfo::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyPUSumInfo*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int MyPUSumInfo::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyPUSumInfo*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *MyPUSumInfo::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyPUSumInfo*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *MyPUSumInfo::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyPUSumInfo*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr MyMet::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *MyMet::Class_Name()
{
   return "MyMet";
}

//______________________________________________________________________________
const char *MyMet::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyMet*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int MyMet::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyMet*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *MyMet::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyMet*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *MyMet::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyMet*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr MyGenMet::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *MyGenMet::Class_Name()
{
   return "MyGenMet";
}

//______________________________________________________________________________
const char *MyGenMet::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyGenMet*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int MyGenMet::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyGenMet*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *MyGenMet::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyGenMet*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *MyGenMet::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyGenMet*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr MyGenPart::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *MyGenPart::Class_Name()
{
   return "MyGenPart";
}

//______________________________________________________________________________
const char *MyGenPart::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyGenPart*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int MyGenPart::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyGenPart*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *MyGenPart::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyGenPart*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *MyGenPart::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyGenPart*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr MyGenJet::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *MyGenJet::Class_Name()
{
   return "MyGenJet";
}

//______________________________________________________________________________
const char *MyGenJet::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyGenJet*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int MyGenJet::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyGenJet*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *MyGenJet::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyGenJet*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *MyGenJet::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyGenJet*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr MyHLTrig::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *MyHLTrig::Class_Name()
{
   return "MyHLTrig";
}

//______________________________________________________________________________
const char *MyHLTrig::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyHLTrig*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int MyHLTrig::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyHLTrig*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *MyHLTrig::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyHLTrig*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *MyHLTrig::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyHLTrig*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr MyL1Trig::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *MyL1Trig::Class_Name()
{
   return "MyL1Trig";
}

//______________________________________________________________________________
const char *MyL1Trig::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyL1Trig*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int MyL1Trig::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyL1Trig*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *MyL1Trig::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyL1Trig*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *MyL1Trig::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyL1Trig*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr MyL1TrigOld::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *MyL1TrigOld::Class_Name()
{
   return "MyL1TrigOld";
}

//______________________________________________________________________________
const char *MyL1TrigOld::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyL1TrigOld*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int MyL1TrigOld::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyL1TrigOld*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *MyL1TrigOld::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyL1TrigOld*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *MyL1TrigOld::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyL1TrigOld*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr MyMITEvtSel::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *MyMITEvtSel::Class_Name()
{
   return "MyMITEvtSel";
}

//______________________________________________________________________________
const char *MyMITEvtSel::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyMITEvtSel*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int MyMITEvtSel::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyMITEvtSel*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *MyMITEvtSel::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyMITEvtSel*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *MyMITEvtSel::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyMITEvtSel*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr MyPart::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *MyPart::Class_Name()
{
   return "MyPart";
}

//______________________________________________________________________________
const char *MyPart::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyPart*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int MyPart::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyPart*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *MyPart::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyPart*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *MyPart::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyPart*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr MySimVertex::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *MySimVertex::Class_Name()
{
   return "MySimVertex";
}

//______________________________________________________________________________
const char *MySimVertex::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MySimVertex*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int MySimVertex::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MySimVertex*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *MySimVertex::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MySimVertex*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *MySimVertex::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MySimVertex*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr MyVertex::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *MyVertex::Class_Name()
{
   return "MyVertex";
}

//______________________________________________________________________________
const char *MyVertex::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyVertex*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int MyVertex::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyVertex*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *MyVertex::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyVertex*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *MyVertex::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyVertex*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr MyTracks::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *MyTracks::Class_Name()
{
   return "MyTracks";
}

//______________________________________________________________________________
const char *MyTracks::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyTracks*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int MyTracks::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyTracks*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *MyTracks::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyTracks*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *MyTracks::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyTracks*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr MyElectron::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *MyElectron::Class_Name()
{
   return "MyElectron";
}

//______________________________________________________________________________
const char *MyElectron::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyElectron*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int MyElectron::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyElectron*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *MyElectron::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyElectron*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *MyElectron::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyElectron*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr MyMuon::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *MyMuon::Class_Name()
{
   return "MyMuon";
}

//______________________________________________________________________________
const char *MyMuon::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyMuon*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int MyMuon::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyMuon*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *MyMuon::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyMuon*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *MyMuon::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyMuon*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr MyBaseJet::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *MyBaseJet::Class_Name()
{
   return "MyBaseJet";
}

//______________________________________________________________________________
const char *MyBaseJet::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyBaseJet*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int MyBaseJet::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyBaseJet*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *MyBaseJet::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyBaseJet*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *MyBaseJet::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyBaseJet*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr MyJet::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *MyJet::Class_Name()
{
   return "MyJet";
}

//______________________________________________________________________________
const char *MyJet::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyJet*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int MyJet::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyJet*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *MyJet::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyJet*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *MyJet::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyJet*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr MyCaloJet::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *MyCaloJet::Class_Name()
{
   return "MyCaloJet";
}

//______________________________________________________________________________
const char *MyCaloJet::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyCaloJet*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int MyCaloJet::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyCaloJet*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *MyCaloJet::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyCaloJet*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *MyCaloJet::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyCaloJet*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr MyTrackJet::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *MyTrackJet::Class_Name()
{
   return "MyTrackJet";
}

//______________________________________________________________________________
const char *MyTrackJet::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyTrackJet*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int MyTrackJet::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyTrackJet*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *MyTrackJet::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyTrackJet*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *MyTrackJet::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyTrackJet*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr MyPFJet::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *MyPFJet::Class_Name()
{
   return "MyPFJet";
}

//______________________________________________________________________________
const char *MyPFJet::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyPFJet*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int MyPFJet::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyPFJet*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *MyPFJet::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyPFJet*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *MyPFJet::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyPFJet*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr MyPFCand::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *MyPFCand::Class_Name()
{
   return "MyPFCand";
}

//______________________________________________________________________________
const char *MyPFCand::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyPFCand*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int MyPFCand::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyPFCand*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *MyPFCand::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyPFCand*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *MyPFCand::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyPFCand*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr MyCaloTower::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *MyCaloTower::Class_Name()
{
   return "MyCaloTower";
}

//______________________________________________________________________________
const char *MyCaloTower::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyCaloTower*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int MyCaloTower::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyCaloTower*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *MyCaloTower::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyCaloTower*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *MyCaloTower::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyCaloTower*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr MyKshorts::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *MyKshorts::Class_Name()
{
   return "MyKshorts";
}

//______________________________________________________________________________
const char *MyKshorts::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyKshorts*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int MyKshorts::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyKshorts*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *MyKshorts::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyKshorts*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *MyKshorts::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyKshorts*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr MyLambdas::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *MyLambdas::Class_Name()
{
   return "MyLambdas";
}

//______________________________________________________________________________
const char *MyLambdas::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyLambdas*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int MyLambdas::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyLambdas*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *MyLambdas::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyLambdas*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *MyLambdas::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyLambdas*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr MyFSCHit::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *MyFSCHit::Class_Name()
{
   return "MyFSCHit";
}

//______________________________________________________________________________
const char *MyFSCHit::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyFSCHit*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int MyFSCHit::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyFSCHit*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *MyFSCHit::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyFSCHit*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *MyFSCHit::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyFSCHit*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr MyFSCDigi::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *MyFSCDigi::Class_Name()
{
   return "MyFSCDigi";
}

//______________________________________________________________________________
const char *MyFSCDigi::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyFSCDigi*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int MyFSCDigi::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyFSCDigi*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *MyFSCDigi::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyFSCDigi*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *MyFSCDigi::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyFSCDigi*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr MyFSCInfo::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *MyFSCInfo::Class_Name()
{
   return "MyFSCInfo";
}

//______________________________________________________________________________
const char *MyFSCInfo::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyFSCInfo*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int MyFSCInfo::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::MyFSCInfo*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *MyFSCInfo::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyFSCInfo*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *MyFSCInfo::Class()
{
   if (!fgIsA) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::MyFSCInfo*)0x0)->GetClass(); }
   return fgIsA;
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_pairlEstringcOboolgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) pair<string,bool> : new pair<string,bool>;
   }
   static void *newArray_pairlEstringcOboolgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) pair<string,bool>[nElements] : new pair<string,bool>[nElements];
   }
   // Wrapper around operator delete
   static void delete_pairlEstringcOboolgR(void *p) {
      delete ((pair<string,bool>*)p);
   }
   static void deleteArray_pairlEstringcOboolgR(void *p) {
      delete [] ((pair<string,bool>*)p);
   }
   static void destruct_pairlEstringcOboolgR(void *p) {
      typedef pair<string,bool> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class pair<string,bool>

//______________________________________________________________________________
void MyBeamSpot::Streamer(TBuffer &R__b)
{
   // Stream an object of class MyBeamSpot.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(MyBeamSpot::Class(),this);
   } else {
      R__b.WriteClassBuffer(MyBeamSpot::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_MyBeamSpot(void *p) {
      return  p ? new(p) ::MyBeamSpot : new ::MyBeamSpot;
   }
   static void *newArray_MyBeamSpot(Long_t nElements, void *p) {
      return p ? new(p) ::MyBeamSpot[nElements] : new ::MyBeamSpot[nElements];
   }
   // Wrapper around operator delete
   static void delete_MyBeamSpot(void *p) {
      delete ((::MyBeamSpot*)p);
   }
   static void deleteArray_MyBeamSpot(void *p) {
      delete [] ((::MyBeamSpot*)p);
   }
   static void destruct_MyBeamSpot(void *p) {
      typedef ::MyBeamSpot current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MyBeamSpot

//______________________________________________________________________________
void MyCastorDigi::Streamer(TBuffer &R__b)
{
   // Stream an object of class MyCastorDigi.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(MyCastorDigi::Class(),this);
   } else {
      R__b.WriteClassBuffer(MyCastorDigi::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_MyCastorDigi(void *p) {
      return  p ? new(p) ::MyCastorDigi : new ::MyCastorDigi;
   }
   static void *newArray_MyCastorDigi(Long_t nElements, void *p) {
      return p ? new(p) ::MyCastorDigi[nElements] : new ::MyCastorDigi[nElements];
   }
   // Wrapper around operator delete
   static void delete_MyCastorDigi(void *p) {
      delete ((::MyCastorDigi*)p);
   }
   static void deleteArray_MyCastorDigi(void *p) {
      delete [] ((::MyCastorDigi*)p);
   }
   static void destruct_MyCastorDigi(void *p) {
      typedef ::MyCastorDigi current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MyCastorDigi

//______________________________________________________________________________
void MyCastorJet::Streamer(TBuffer &R__b)
{
   // Stream an object of class MyCastorJet.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(MyCastorJet::Class(),this);
   } else {
      R__b.WriteClassBuffer(MyCastorJet::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_MyCastorJet(void *p) {
      return  p ? new(p) ::MyCastorJet : new ::MyCastorJet;
   }
   static void *newArray_MyCastorJet(Long_t nElements, void *p) {
      return p ? new(p) ::MyCastorJet[nElements] : new ::MyCastorJet[nElements];
   }
   // Wrapper around operator delete
   static void delete_MyCastorJet(void *p) {
      delete ((::MyCastorJet*)p);
   }
   static void deleteArray_MyCastorJet(void *p) {
      delete [] ((::MyCastorJet*)p);
   }
   static void destruct_MyCastorJet(void *p) {
      typedef ::MyCastorJet current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MyCastorJet

//______________________________________________________________________________
void MyCastorRecHit::Streamer(TBuffer &R__b)
{
   // Stream an object of class MyCastorRecHit.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(MyCastorRecHit::Class(),this);
   } else {
      R__b.WriteClassBuffer(MyCastorRecHit::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_MyCastorRecHit(void *p) {
      return  p ? new(p) ::MyCastorRecHit : new ::MyCastorRecHit;
   }
   static void *newArray_MyCastorRecHit(Long_t nElements, void *p) {
      return p ? new(p) ::MyCastorRecHit[nElements] : new ::MyCastorRecHit[nElements];
   }
   // Wrapper around operator delete
   static void delete_MyCastorRecHit(void *p) {
      delete ((::MyCastorRecHit*)p);
   }
   static void deleteArray_MyCastorRecHit(void *p) {
      delete [] ((::MyCastorRecHit*)p);
   }
   static void destruct_MyCastorRecHit(void *p) {
      typedef ::MyCastorRecHit current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MyCastorRecHit

//______________________________________________________________________________
void MyDiJet::Streamer(TBuffer &R__b)
{
   // Stream an object of class MyDiJet.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(MyDiJet::Class(),this);
   } else {
      R__b.WriteClassBuffer(MyDiJet::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_MyDiJet(void *p) {
      return  p ? new(p) ::MyDiJet : new ::MyDiJet;
   }
   static void *newArray_MyDiJet(Long_t nElements, void *p) {
      return p ? new(p) ::MyDiJet[nElements] : new ::MyDiJet[nElements];
   }
   // Wrapper around operator delete
   static void delete_MyDiJet(void *p) {
      delete ((::MyDiJet*)p);
   }
   static void deleteArray_MyDiJet(void *p) {
      delete [] ((::MyDiJet*)p);
   }
   static void destruct_MyDiJet(void *p) {
      typedef ::MyDiJet current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MyDiJet

//______________________________________________________________________________
void MyEvtId::Streamer(TBuffer &R__b)
{
   // Stream an object of class MyEvtId.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(MyEvtId::Class(),this);
   } else {
      R__b.WriteClassBuffer(MyEvtId::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_MyEvtId(void *p) {
      return  p ? new(p) ::MyEvtId : new ::MyEvtId;
   }
   static void *newArray_MyEvtId(Long_t nElements, void *p) {
      return p ? new(p) ::MyEvtId[nElements] : new ::MyEvtId[nElements];
   }
   // Wrapper around operator delete
   static void delete_MyEvtId(void *p) {
      delete ((::MyEvtId*)p);
   }
   static void deleteArray_MyEvtId(void *p) {
      delete [] ((::MyEvtId*)p);
   }
   static void destruct_MyEvtId(void *p) {
      typedef ::MyEvtId current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MyEvtId

//______________________________________________________________________________
void MyFwdGap::Streamer(TBuffer &R__b)
{
   // Stream an object of class MyFwdGap.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(MyFwdGap::Class(),this);
   } else {
      R__b.WriteClassBuffer(MyFwdGap::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_MyFwdGap(void *p) {
      return  p ? new(p) ::MyFwdGap : new ::MyFwdGap;
   }
   static void *newArray_MyFwdGap(Long_t nElements, void *p) {
      return p ? new(p) ::MyFwdGap[nElements] : new ::MyFwdGap[nElements];
   }
   // Wrapper around operator delete
   static void delete_MyFwdGap(void *p) {
      delete ((::MyFwdGap*)p);
   }
   static void deleteArray_MyFwdGap(void *p) {
      delete [] ((::MyFwdGap*)p);
   }
   static void destruct_MyFwdGap(void *p) {
      typedef ::MyFwdGap current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MyFwdGap

//______________________________________________________________________________
void MyGenKin::Streamer(TBuffer &R__b)
{
   // Stream an object of class MyGenKin.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(MyGenKin::Class(),this);
   } else {
      R__b.WriteClassBuffer(MyGenKin::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_MyGenKin(void *p) {
      return  p ? new(p) ::MyGenKin : new ::MyGenKin;
   }
   static void *newArray_MyGenKin(Long_t nElements, void *p) {
      return p ? new(p) ::MyGenKin[nElements] : new ::MyGenKin[nElements];
   }
   // Wrapper around operator delete
   static void delete_MyGenKin(void *p) {
      delete ((::MyGenKin*)p);
   }
   static void deleteArray_MyGenKin(void *p) {
      delete [] ((::MyGenKin*)p);
   }
   static void destruct_MyGenKin(void *p) {
      typedef ::MyGenKin current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MyGenKin

//______________________________________________________________________________
void MyPUSumInfo::Streamer(TBuffer &R__b)
{
   // Stream an object of class MyPUSumInfo.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(MyPUSumInfo::Class(),this);
   } else {
      R__b.WriteClassBuffer(MyPUSumInfo::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_MyPUSumInfo(void *p) {
      return  p ? new(p) ::MyPUSumInfo : new ::MyPUSumInfo;
   }
   static void *newArray_MyPUSumInfo(Long_t nElements, void *p) {
      return p ? new(p) ::MyPUSumInfo[nElements] : new ::MyPUSumInfo[nElements];
   }
   // Wrapper around operator delete
   static void delete_MyPUSumInfo(void *p) {
      delete ((::MyPUSumInfo*)p);
   }
   static void deleteArray_MyPUSumInfo(void *p) {
      delete [] ((::MyPUSumInfo*)p);
   }
   static void destruct_MyPUSumInfo(void *p) {
      typedef ::MyPUSumInfo current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MyPUSumInfo

//______________________________________________________________________________
void MyMet::Streamer(TBuffer &R__b)
{
   // Stream an object of class MyMet.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(MyMet::Class(),this);
   } else {
      R__b.WriteClassBuffer(MyMet::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_MyMet(void *p) {
      return  p ? new(p) ::MyMet : new ::MyMet;
   }
   static void *newArray_MyMet(Long_t nElements, void *p) {
      return p ? new(p) ::MyMet[nElements] : new ::MyMet[nElements];
   }
   // Wrapper around operator delete
   static void delete_MyMet(void *p) {
      delete ((::MyMet*)p);
   }
   static void deleteArray_MyMet(void *p) {
      delete [] ((::MyMet*)p);
   }
   static void destruct_MyMet(void *p) {
      typedef ::MyMet current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MyMet

//______________________________________________________________________________
void MyGenMet::Streamer(TBuffer &R__b)
{
   // Stream an object of class MyGenMet.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(MyGenMet::Class(),this);
   } else {
      R__b.WriteClassBuffer(MyGenMet::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_MyGenMet(void *p) {
      return  p ? new(p) ::MyGenMet : new ::MyGenMet;
   }
   static void *newArray_MyGenMet(Long_t nElements, void *p) {
      return p ? new(p) ::MyGenMet[nElements] : new ::MyGenMet[nElements];
   }
   // Wrapper around operator delete
   static void delete_MyGenMet(void *p) {
      delete ((::MyGenMet*)p);
   }
   static void deleteArray_MyGenMet(void *p) {
      delete [] ((::MyGenMet*)p);
   }
   static void destruct_MyGenMet(void *p) {
      typedef ::MyGenMet current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MyGenMet

//______________________________________________________________________________
void MyGenPart::Streamer(TBuffer &R__b)
{
   // Stream an object of class MyGenPart.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(MyGenPart::Class(),this);
   } else {
      R__b.WriteClassBuffer(MyGenPart::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_MyGenPart(void *p) {
      return  p ? new(p) ::MyGenPart : new ::MyGenPart;
   }
   static void *newArray_MyGenPart(Long_t nElements, void *p) {
      return p ? new(p) ::MyGenPart[nElements] : new ::MyGenPart[nElements];
   }
   // Wrapper around operator delete
   static void delete_MyGenPart(void *p) {
      delete ((::MyGenPart*)p);
   }
   static void deleteArray_MyGenPart(void *p) {
      delete [] ((::MyGenPart*)p);
   }
   static void destruct_MyGenPart(void *p) {
      typedef ::MyGenPart current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MyGenPart

//______________________________________________________________________________
void MyGenJet::Streamer(TBuffer &R__b)
{
   // Stream an object of class MyGenJet.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(MyGenJet::Class(),this);
   } else {
      R__b.WriteClassBuffer(MyGenJet::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_MyGenJet(void *p) {
      return  p ? new(p) ::MyGenJet : new ::MyGenJet;
   }
   static void *newArray_MyGenJet(Long_t nElements, void *p) {
      return p ? new(p) ::MyGenJet[nElements] : new ::MyGenJet[nElements];
   }
   // Wrapper around operator delete
   static void delete_MyGenJet(void *p) {
      delete ((::MyGenJet*)p);
   }
   static void deleteArray_MyGenJet(void *p) {
      delete [] ((::MyGenJet*)p);
   }
   static void destruct_MyGenJet(void *p) {
      typedef ::MyGenJet current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MyGenJet

//______________________________________________________________________________
void MyHLTrig::Streamer(TBuffer &R__b)
{
   // Stream an object of class MyHLTrig.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(MyHLTrig::Class(),this);
   } else {
      R__b.WriteClassBuffer(MyHLTrig::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_MyHLTrig(void *p) {
      return  p ? new(p) ::MyHLTrig : new ::MyHLTrig;
   }
   static void *newArray_MyHLTrig(Long_t nElements, void *p) {
      return p ? new(p) ::MyHLTrig[nElements] : new ::MyHLTrig[nElements];
   }
   // Wrapper around operator delete
   static void delete_MyHLTrig(void *p) {
      delete ((::MyHLTrig*)p);
   }
   static void deleteArray_MyHLTrig(void *p) {
      delete [] ((::MyHLTrig*)p);
   }
   static void destruct_MyHLTrig(void *p) {
      typedef ::MyHLTrig current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MyHLTrig

//______________________________________________________________________________
void MyL1Trig::Streamer(TBuffer &R__b)
{
   // Stream an object of class MyL1Trig.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(MyL1Trig::Class(),this);
   } else {
      R__b.WriteClassBuffer(MyL1Trig::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_MyL1Trig(void *p) {
      return  p ? new(p) ::MyL1Trig : new ::MyL1Trig;
   }
   static void *newArray_MyL1Trig(Long_t nElements, void *p) {
      return p ? new(p) ::MyL1Trig[nElements] : new ::MyL1Trig[nElements];
   }
   // Wrapper around operator delete
   static void delete_MyL1Trig(void *p) {
      delete ((::MyL1Trig*)p);
   }
   static void deleteArray_MyL1Trig(void *p) {
      delete [] ((::MyL1Trig*)p);
   }
   static void destruct_MyL1Trig(void *p) {
      typedef ::MyL1Trig current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MyL1Trig

//______________________________________________________________________________
void MyL1TrigOld::Streamer(TBuffer &R__b)
{
   // Stream an object of class MyL1TrigOld.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(MyL1TrigOld::Class(),this);
   } else {
      R__b.WriteClassBuffer(MyL1TrigOld::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_MyL1TrigOld(void *p) {
      return  p ? new(p) ::MyL1TrigOld : new ::MyL1TrigOld;
   }
   static void *newArray_MyL1TrigOld(Long_t nElements, void *p) {
      return p ? new(p) ::MyL1TrigOld[nElements] : new ::MyL1TrigOld[nElements];
   }
   // Wrapper around operator delete
   static void delete_MyL1TrigOld(void *p) {
      delete ((::MyL1TrigOld*)p);
   }
   static void deleteArray_MyL1TrigOld(void *p) {
      delete [] ((::MyL1TrigOld*)p);
   }
   static void destruct_MyL1TrigOld(void *p) {
      typedef ::MyL1TrigOld current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MyL1TrigOld

//______________________________________________________________________________
void MyMITEvtSel::Streamer(TBuffer &R__b)
{
   // Stream an object of class MyMITEvtSel.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(MyMITEvtSel::Class(),this);
   } else {
      R__b.WriteClassBuffer(MyMITEvtSel::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_MyMITEvtSel(void *p) {
      return  p ? new(p) ::MyMITEvtSel : new ::MyMITEvtSel;
   }
   static void *newArray_MyMITEvtSel(Long_t nElements, void *p) {
      return p ? new(p) ::MyMITEvtSel[nElements] : new ::MyMITEvtSel[nElements];
   }
   // Wrapper around operator delete
   static void delete_MyMITEvtSel(void *p) {
      delete ((::MyMITEvtSel*)p);
   }
   static void deleteArray_MyMITEvtSel(void *p) {
      delete [] ((::MyMITEvtSel*)p);
   }
   static void destruct_MyMITEvtSel(void *p) {
      typedef ::MyMITEvtSel current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MyMITEvtSel

//______________________________________________________________________________
void MyPart::Streamer(TBuffer &R__b)
{
   // Stream an object of class MyPart.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(MyPart::Class(),this);
   } else {
      R__b.WriteClassBuffer(MyPart::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_MyPart(void *p) {
      return  p ? new(p) ::MyPart : new ::MyPart;
   }
   static void *newArray_MyPart(Long_t nElements, void *p) {
      return p ? new(p) ::MyPart[nElements] : new ::MyPart[nElements];
   }
   // Wrapper around operator delete
   static void delete_MyPart(void *p) {
      delete ((::MyPart*)p);
   }
   static void deleteArray_MyPart(void *p) {
      delete [] ((::MyPart*)p);
   }
   static void destruct_MyPart(void *p) {
      typedef ::MyPart current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MyPart

//______________________________________________________________________________
void MySimVertex::Streamer(TBuffer &R__b)
{
   // Stream an object of class MySimVertex.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(MySimVertex::Class(),this);
   } else {
      R__b.WriteClassBuffer(MySimVertex::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_MySimVertex(void *p) {
      return  p ? new(p) ::MySimVertex : new ::MySimVertex;
   }
   static void *newArray_MySimVertex(Long_t nElements, void *p) {
      return p ? new(p) ::MySimVertex[nElements] : new ::MySimVertex[nElements];
   }
   // Wrapper around operator delete
   static void delete_MySimVertex(void *p) {
      delete ((::MySimVertex*)p);
   }
   static void deleteArray_MySimVertex(void *p) {
      delete [] ((::MySimVertex*)p);
   }
   static void destruct_MySimVertex(void *p) {
      typedef ::MySimVertex current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MySimVertex

//______________________________________________________________________________
void MyVertex::Streamer(TBuffer &R__b)
{
   // Stream an object of class MyVertex.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(MyVertex::Class(),this);
   } else {
      R__b.WriteClassBuffer(MyVertex::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_MyVertex(void *p) {
      return  p ? new(p) ::MyVertex : new ::MyVertex;
   }
   static void *newArray_MyVertex(Long_t nElements, void *p) {
      return p ? new(p) ::MyVertex[nElements] : new ::MyVertex[nElements];
   }
   // Wrapper around operator delete
   static void delete_MyVertex(void *p) {
      delete ((::MyVertex*)p);
   }
   static void deleteArray_MyVertex(void *p) {
      delete [] ((::MyVertex*)p);
   }
   static void destruct_MyVertex(void *p) {
      typedef ::MyVertex current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MyVertex

//______________________________________________________________________________
void MyTracks::Streamer(TBuffer &R__b)
{
   // Stream an object of class MyTracks.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(MyTracks::Class(),this);
   } else {
      R__b.WriteClassBuffer(MyTracks::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_MyTracks(void *p) {
      return  p ? new(p) ::MyTracks : new ::MyTracks;
   }
   static void *newArray_MyTracks(Long_t nElements, void *p) {
      return p ? new(p) ::MyTracks[nElements] : new ::MyTracks[nElements];
   }
   // Wrapper around operator delete
   static void delete_MyTracks(void *p) {
      delete ((::MyTracks*)p);
   }
   static void deleteArray_MyTracks(void *p) {
      delete [] ((::MyTracks*)p);
   }
   static void destruct_MyTracks(void *p) {
      typedef ::MyTracks current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MyTracks

//______________________________________________________________________________
void MyElectron::Streamer(TBuffer &R__b)
{
   // Stream an object of class MyElectron.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(MyElectron::Class(),this);
   } else {
      R__b.WriteClassBuffer(MyElectron::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_MyElectron(void *p) {
      return  p ? new(p) ::MyElectron : new ::MyElectron;
   }
   static void *newArray_MyElectron(Long_t nElements, void *p) {
      return p ? new(p) ::MyElectron[nElements] : new ::MyElectron[nElements];
   }
   // Wrapper around operator delete
   static void delete_MyElectron(void *p) {
      delete ((::MyElectron*)p);
   }
   static void deleteArray_MyElectron(void *p) {
      delete [] ((::MyElectron*)p);
   }
   static void destruct_MyElectron(void *p) {
      typedef ::MyElectron current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MyElectron

//______________________________________________________________________________
void MyMuon::Streamer(TBuffer &R__b)
{
   // Stream an object of class MyMuon.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(MyMuon::Class(),this);
   } else {
      R__b.WriteClassBuffer(MyMuon::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_MyMuon(void *p) {
      return  p ? new(p) ::MyMuon : new ::MyMuon;
   }
   static void *newArray_MyMuon(Long_t nElements, void *p) {
      return p ? new(p) ::MyMuon[nElements] : new ::MyMuon[nElements];
   }
   // Wrapper around operator delete
   static void delete_MyMuon(void *p) {
      delete ((::MyMuon*)p);
   }
   static void deleteArray_MyMuon(void *p) {
      delete [] ((::MyMuon*)p);
   }
   static void destruct_MyMuon(void *p) {
      typedef ::MyMuon current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MyMuon

//______________________________________________________________________________
void MyBaseJet::Streamer(TBuffer &R__b)
{
   // Stream an object of class MyBaseJet.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(MyBaseJet::Class(),this);
   } else {
      R__b.WriteClassBuffer(MyBaseJet::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_MyBaseJet(void *p) {
      return  p ? new(p) ::MyBaseJet : new ::MyBaseJet;
   }
   static void *newArray_MyBaseJet(Long_t nElements, void *p) {
      return p ? new(p) ::MyBaseJet[nElements] : new ::MyBaseJet[nElements];
   }
   // Wrapper around operator delete
   static void delete_MyBaseJet(void *p) {
      delete ((::MyBaseJet*)p);
   }
   static void deleteArray_MyBaseJet(void *p) {
      delete [] ((::MyBaseJet*)p);
   }
   static void destruct_MyBaseJet(void *p) {
      typedef ::MyBaseJet current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MyBaseJet

//______________________________________________________________________________
void MyJet::Streamer(TBuffer &R__b)
{
   // Stream an object of class MyJet.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(MyJet::Class(),this);
   } else {
      R__b.WriteClassBuffer(MyJet::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_MyJet(void *p) {
      return  p ? new(p) ::MyJet : new ::MyJet;
   }
   static void *newArray_MyJet(Long_t nElements, void *p) {
      return p ? new(p) ::MyJet[nElements] : new ::MyJet[nElements];
   }
   // Wrapper around operator delete
   static void delete_MyJet(void *p) {
      delete ((::MyJet*)p);
   }
   static void deleteArray_MyJet(void *p) {
      delete [] ((::MyJet*)p);
   }
   static void destruct_MyJet(void *p) {
      typedef ::MyJet current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MyJet

//______________________________________________________________________________
void MyCaloJet::Streamer(TBuffer &R__b)
{
   // Stream an object of class MyCaloJet.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(MyCaloJet::Class(),this);
   } else {
      R__b.WriteClassBuffer(MyCaloJet::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_MyCaloJet(void *p) {
      return  p ? new(p) ::MyCaloJet : new ::MyCaloJet;
   }
   static void *newArray_MyCaloJet(Long_t nElements, void *p) {
      return p ? new(p) ::MyCaloJet[nElements] : new ::MyCaloJet[nElements];
   }
   // Wrapper around operator delete
   static void delete_MyCaloJet(void *p) {
      delete ((::MyCaloJet*)p);
   }
   static void deleteArray_MyCaloJet(void *p) {
      delete [] ((::MyCaloJet*)p);
   }
   static void destruct_MyCaloJet(void *p) {
      typedef ::MyCaloJet current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MyCaloJet

//______________________________________________________________________________
void MyTrackJet::Streamer(TBuffer &R__b)
{
   // Stream an object of class MyTrackJet.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(MyTrackJet::Class(),this);
   } else {
      R__b.WriteClassBuffer(MyTrackJet::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_MyTrackJet(void *p) {
      return  p ? new(p) ::MyTrackJet : new ::MyTrackJet;
   }
   static void *newArray_MyTrackJet(Long_t nElements, void *p) {
      return p ? new(p) ::MyTrackJet[nElements] : new ::MyTrackJet[nElements];
   }
   // Wrapper around operator delete
   static void delete_MyTrackJet(void *p) {
      delete ((::MyTrackJet*)p);
   }
   static void deleteArray_MyTrackJet(void *p) {
      delete [] ((::MyTrackJet*)p);
   }
   static void destruct_MyTrackJet(void *p) {
      typedef ::MyTrackJet current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MyTrackJet

//______________________________________________________________________________
void MyPFJet::Streamer(TBuffer &R__b)
{
   // Stream an object of class MyPFJet.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(MyPFJet::Class(),this);
   } else {
      R__b.WriteClassBuffer(MyPFJet::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_MyPFJet(void *p) {
      return  p ? new(p) ::MyPFJet : new ::MyPFJet;
   }
   static void *newArray_MyPFJet(Long_t nElements, void *p) {
      return p ? new(p) ::MyPFJet[nElements] : new ::MyPFJet[nElements];
   }
   // Wrapper around operator delete
   static void delete_MyPFJet(void *p) {
      delete ((::MyPFJet*)p);
   }
   static void deleteArray_MyPFJet(void *p) {
      delete [] ((::MyPFJet*)p);
   }
   static void destruct_MyPFJet(void *p) {
      typedef ::MyPFJet current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MyPFJet

//______________________________________________________________________________
void MyPFCand::Streamer(TBuffer &R__b)
{
   // Stream an object of class MyPFCand.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(MyPFCand::Class(),this);
   } else {
      R__b.WriteClassBuffer(MyPFCand::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_MyPFCand(void *p) {
      return  p ? new(p) ::MyPFCand : new ::MyPFCand;
   }
   static void *newArray_MyPFCand(Long_t nElements, void *p) {
      return p ? new(p) ::MyPFCand[nElements] : new ::MyPFCand[nElements];
   }
   // Wrapper around operator delete
   static void delete_MyPFCand(void *p) {
      delete ((::MyPFCand*)p);
   }
   static void deleteArray_MyPFCand(void *p) {
      delete [] ((::MyPFCand*)p);
   }
   static void destruct_MyPFCand(void *p) {
      typedef ::MyPFCand current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MyPFCand

//______________________________________________________________________________
void MyCaloTower::Streamer(TBuffer &R__b)
{
   // Stream an object of class MyCaloTower.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(MyCaloTower::Class(),this);
   } else {
      R__b.WriteClassBuffer(MyCaloTower::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_MyCaloTower(void *p) {
      return  p ? new(p) ::MyCaloTower : new ::MyCaloTower;
   }
   static void *newArray_MyCaloTower(Long_t nElements, void *p) {
      return p ? new(p) ::MyCaloTower[nElements] : new ::MyCaloTower[nElements];
   }
   // Wrapper around operator delete
   static void delete_MyCaloTower(void *p) {
      delete ((::MyCaloTower*)p);
   }
   static void deleteArray_MyCaloTower(void *p) {
      delete [] ((::MyCaloTower*)p);
   }
   static void destruct_MyCaloTower(void *p) {
      typedef ::MyCaloTower current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MyCaloTower

//______________________________________________________________________________
void MyKshorts::Streamer(TBuffer &R__b)
{
   // Stream an object of class MyKshorts.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(MyKshorts::Class(),this);
   } else {
      R__b.WriteClassBuffer(MyKshorts::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_MyKshorts(void *p) {
      return  p ? new(p) ::MyKshorts : new ::MyKshorts;
   }
   static void *newArray_MyKshorts(Long_t nElements, void *p) {
      return p ? new(p) ::MyKshorts[nElements] : new ::MyKshorts[nElements];
   }
   // Wrapper around operator delete
   static void delete_MyKshorts(void *p) {
      delete ((::MyKshorts*)p);
   }
   static void deleteArray_MyKshorts(void *p) {
      delete [] ((::MyKshorts*)p);
   }
   static void destruct_MyKshorts(void *p) {
      typedef ::MyKshorts current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MyKshorts

//______________________________________________________________________________
void MyLambdas::Streamer(TBuffer &R__b)
{
   // Stream an object of class MyLambdas.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(MyLambdas::Class(),this);
   } else {
      R__b.WriteClassBuffer(MyLambdas::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_MyLambdas(void *p) {
      return  p ? new(p) ::MyLambdas : new ::MyLambdas;
   }
   static void *newArray_MyLambdas(Long_t nElements, void *p) {
      return p ? new(p) ::MyLambdas[nElements] : new ::MyLambdas[nElements];
   }
   // Wrapper around operator delete
   static void delete_MyLambdas(void *p) {
      delete ((::MyLambdas*)p);
   }
   static void deleteArray_MyLambdas(void *p) {
      delete [] ((::MyLambdas*)p);
   }
   static void destruct_MyLambdas(void *p) {
      typedef ::MyLambdas current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MyLambdas

//______________________________________________________________________________
void MyFSCHit::Streamer(TBuffer &R__b)
{
   // Stream an object of class MyFSCHit.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(MyFSCHit::Class(),this);
   } else {
      R__b.WriteClassBuffer(MyFSCHit::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_MyFSCHit(void *p) {
      return  p ? new(p) ::MyFSCHit : new ::MyFSCHit;
   }
   static void *newArray_MyFSCHit(Long_t nElements, void *p) {
      return p ? new(p) ::MyFSCHit[nElements] : new ::MyFSCHit[nElements];
   }
   // Wrapper around operator delete
   static void delete_MyFSCHit(void *p) {
      delete ((::MyFSCHit*)p);
   }
   static void deleteArray_MyFSCHit(void *p) {
      delete [] ((::MyFSCHit*)p);
   }
   static void destruct_MyFSCHit(void *p) {
      typedef ::MyFSCHit current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MyFSCHit

//______________________________________________________________________________
void MyFSCDigi::Streamer(TBuffer &R__b)
{
   // Stream an object of class MyFSCDigi.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(MyFSCDigi::Class(),this);
   } else {
      R__b.WriteClassBuffer(MyFSCDigi::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_MyFSCDigi(void *p) {
      return  p ? new(p) ::MyFSCDigi : new ::MyFSCDigi;
   }
   static void *newArray_MyFSCDigi(Long_t nElements, void *p) {
      return p ? new(p) ::MyFSCDigi[nElements] : new ::MyFSCDigi[nElements];
   }
   // Wrapper around operator delete
   static void delete_MyFSCDigi(void *p) {
      delete ((::MyFSCDigi*)p);
   }
   static void deleteArray_MyFSCDigi(void *p) {
      delete [] ((::MyFSCDigi*)p);
   }
   static void destruct_MyFSCDigi(void *p) {
      typedef ::MyFSCDigi current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MyFSCDigi

//______________________________________________________________________________
void MyFSCInfo::Streamer(TBuffer &R__b)
{
   // Stream an object of class MyFSCInfo.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(MyFSCInfo::Class(),this);
   } else {
      R__b.WriteClassBuffer(MyFSCInfo::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_MyFSCInfo(void *p) {
      return  p ? new(p) ::MyFSCInfo : new ::MyFSCInfo;
   }
   static void *newArray_MyFSCInfo(Long_t nElements, void *p) {
      return p ? new(p) ::MyFSCInfo[nElements] : new ::MyFSCInfo[nElements];
   }
   // Wrapper around operator delete
   static void delete_MyFSCInfo(void *p) {
      delete ((::MyFSCInfo*)p);
   }
   static void deleteArray_MyFSCInfo(void *p) {
      delete [] ((::MyFSCInfo*)p);
   }
   static void destruct_MyFSCInfo(void *p) {
      typedef ::MyFSCInfo current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MyFSCInfo

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
   static TClass *vectorlEfloatgR_Dictionary();
   static void vectorlEfloatgR_TClassManip(TClass*);
   static void *new_vectorlEfloatgR(void *p = 0);
   static void *newArray_vectorlEfloatgR(Long_t size, void *p);
   static void delete_vectorlEfloatgR(void *p);
   static void deleteArray_vectorlEfloatgR(void *p);
   static void destruct_vectorlEfloatgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<float>*)
   {
      vector<float> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<float>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<float>", -2, "vector", 214,
                  typeid(vector<float>), DefineBehavior(ptr, ptr),
                  &vectorlEfloatgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<float>) );
      instance.SetNew(&new_vectorlEfloatgR);
      instance.SetNewArray(&newArray_vectorlEfloatgR);
      instance.SetDelete(&delete_vectorlEfloatgR);
      instance.SetDeleteArray(&deleteArray_vectorlEfloatgR);
      instance.SetDestructor(&destruct_vectorlEfloatgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<float> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<float>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEfloatgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<float>*)0x0)->GetClass();
      vectorlEfloatgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEfloatgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEfloatgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<float> : new vector<float>;
   }
   static void *newArray_vectorlEfloatgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<float>[nElements] : new vector<float>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEfloatgR(void *p) {
      delete ((vector<float>*)p);
   }
   static void deleteArray_vectorlEfloatgR(void *p) {
      delete [] ((vector<float>*)p);
   }
   static void destruct_vectorlEfloatgR(void *p) {
      typedef vector<float> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<float>

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
   static TClass *vectorlEboolgR_Dictionary();
   static void vectorlEboolgR_TClassManip(TClass*);
   static void *new_vectorlEboolgR(void *p = 0);
   static void *newArray_vectorlEboolgR(Long_t size, void *p);
   static void delete_vectorlEboolgR(void *p);
   static void deleteArray_vectorlEboolgR(void *p);
   static void destruct_vectorlEboolgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<bool>*)
   {
      vector<bool> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<bool>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<bool>", -2, "vector", 526,
                  typeid(vector<bool>), DefineBehavior(ptr, ptr),
                  &vectorlEboolgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<bool>) );
      instance.SetNew(&new_vectorlEboolgR);
      instance.SetNewArray(&newArray_vectorlEboolgR);
      instance.SetDelete(&delete_vectorlEboolgR);
      instance.SetDeleteArray(&deleteArray_vectorlEboolgR);
      instance.SetDestructor(&destruct_vectorlEboolgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<bool> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<bool>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEboolgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<bool>*)0x0)->GetClass();
      vectorlEboolgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEboolgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEboolgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<bool> : new vector<bool>;
   }
   static void *newArray_vectorlEboolgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<bool>[nElements] : new vector<bool>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEboolgR(void *p) {
      delete ((vector<bool>*)p);
   }
   static void deleteArray_vectorlEboolgR(void *p) {
      delete [] ((vector<bool>*)p);
   }
   static void destruct_vectorlEboolgR(void *p) {
      typedef vector<bool> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<bool>

namespace ROOT {
   static TClass *vectorlEMyVertexgR_Dictionary();
   static void vectorlEMyVertexgR_TClassManip(TClass*);
   static void *new_vectorlEMyVertexgR(void *p = 0);
   static void *newArray_vectorlEMyVertexgR(Long_t size, void *p);
   static void delete_vectorlEMyVertexgR(void *p);
   static void deleteArray_vectorlEMyVertexgR(void *p);
   static void destruct_vectorlEMyVertexgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<MyVertex>*)
   {
      vector<MyVertex> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<MyVertex>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<MyVertex>", -2, "vector", 214,
                  typeid(vector<MyVertex>), DefineBehavior(ptr, ptr),
                  &vectorlEMyVertexgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<MyVertex>) );
      instance.SetNew(&new_vectorlEMyVertexgR);
      instance.SetNewArray(&newArray_vectorlEMyVertexgR);
      instance.SetDelete(&delete_vectorlEMyVertexgR);
      instance.SetDeleteArray(&deleteArray_vectorlEMyVertexgR);
      instance.SetDestructor(&destruct_vectorlEMyVertexgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<MyVertex> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<MyVertex>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEMyVertexgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<MyVertex>*)0x0)->GetClass();
      vectorlEMyVertexgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEMyVertexgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEMyVertexgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyVertex> : new vector<MyVertex>;
   }
   static void *newArray_vectorlEMyVertexgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyVertex>[nElements] : new vector<MyVertex>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEMyVertexgR(void *p) {
      delete ((vector<MyVertex>*)p);
   }
   static void deleteArray_vectorlEMyVertexgR(void *p) {
      delete [] ((vector<MyVertex>*)p);
   }
   static void destruct_vectorlEMyVertexgR(void *p) {
      typedef vector<MyVertex> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<MyVertex>

namespace ROOT {
   static TClass *vectorlEMyTracksgR_Dictionary();
   static void vectorlEMyTracksgR_TClassManip(TClass*);
   static void *new_vectorlEMyTracksgR(void *p = 0);
   static void *newArray_vectorlEMyTracksgR(Long_t size, void *p);
   static void delete_vectorlEMyTracksgR(void *p);
   static void deleteArray_vectorlEMyTracksgR(void *p);
   static void destruct_vectorlEMyTracksgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<MyTracks>*)
   {
      vector<MyTracks> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<MyTracks>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<MyTracks>", -2, "vector", 214,
                  typeid(vector<MyTracks>), DefineBehavior(ptr, ptr),
                  &vectorlEMyTracksgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<MyTracks>) );
      instance.SetNew(&new_vectorlEMyTracksgR);
      instance.SetNewArray(&newArray_vectorlEMyTracksgR);
      instance.SetDelete(&delete_vectorlEMyTracksgR);
      instance.SetDeleteArray(&deleteArray_vectorlEMyTracksgR);
      instance.SetDestructor(&destruct_vectorlEMyTracksgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<MyTracks> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<MyTracks>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEMyTracksgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<MyTracks>*)0x0)->GetClass();
      vectorlEMyTracksgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEMyTracksgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEMyTracksgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyTracks> : new vector<MyTracks>;
   }
   static void *newArray_vectorlEMyTracksgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyTracks>[nElements] : new vector<MyTracks>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEMyTracksgR(void *p) {
      delete ((vector<MyTracks>*)p);
   }
   static void deleteArray_vectorlEMyTracksgR(void *p) {
      delete [] ((vector<MyTracks>*)p);
   }
   static void destruct_vectorlEMyTracksgR(void *p) {
      typedef vector<MyTracks> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<MyTracks>

namespace ROOT {
   static TClass *vectorlEMyTrackJetgR_Dictionary();
   static void vectorlEMyTrackJetgR_TClassManip(TClass*);
   static void *new_vectorlEMyTrackJetgR(void *p = 0);
   static void *newArray_vectorlEMyTrackJetgR(Long_t size, void *p);
   static void delete_vectorlEMyTrackJetgR(void *p);
   static void deleteArray_vectorlEMyTrackJetgR(void *p);
   static void destruct_vectorlEMyTrackJetgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<MyTrackJet>*)
   {
      vector<MyTrackJet> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<MyTrackJet>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<MyTrackJet>", -2, "vector", 214,
                  typeid(vector<MyTrackJet>), DefineBehavior(ptr, ptr),
                  &vectorlEMyTrackJetgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<MyTrackJet>) );
      instance.SetNew(&new_vectorlEMyTrackJetgR);
      instance.SetNewArray(&newArray_vectorlEMyTrackJetgR);
      instance.SetDelete(&delete_vectorlEMyTrackJetgR);
      instance.SetDeleteArray(&deleteArray_vectorlEMyTrackJetgR);
      instance.SetDestructor(&destruct_vectorlEMyTrackJetgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<MyTrackJet> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<MyTrackJet>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEMyTrackJetgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<MyTrackJet>*)0x0)->GetClass();
      vectorlEMyTrackJetgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEMyTrackJetgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEMyTrackJetgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyTrackJet> : new vector<MyTrackJet>;
   }
   static void *newArray_vectorlEMyTrackJetgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyTrackJet>[nElements] : new vector<MyTrackJet>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEMyTrackJetgR(void *p) {
      delete ((vector<MyTrackJet>*)p);
   }
   static void deleteArray_vectorlEMyTrackJetgR(void *p) {
      delete [] ((vector<MyTrackJet>*)p);
   }
   static void destruct_vectorlEMyTrackJetgR(void *p) {
      typedef vector<MyTrackJet> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<MyTrackJet>

namespace ROOT {
   static TClass *vectorlEMySimVertexgR_Dictionary();
   static void vectorlEMySimVertexgR_TClassManip(TClass*);
   static void *new_vectorlEMySimVertexgR(void *p = 0);
   static void *newArray_vectorlEMySimVertexgR(Long_t size, void *p);
   static void delete_vectorlEMySimVertexgR(void *p);
   static void deleteArray_vectorlEMySimVertexgR(void *p);
   static void destruct_vectorlEMySimVertexgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<MySimVertex>*)
   {
      vector<MySimVertex> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<MySimVertex>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<MySimVertex>", -2, "vector", 214,
                  typeid(vector<MySimVertex>), DefineBehavior(ptr, ptr),
                  &vectorlEMySimVertexgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<MySimVertex>) );
      instance.SetNew(&new_vectorlEMySimVertexgR);
      instance.SetNewArray(&newArray_vectorlEMySimVertexgR);
      instance.SetDelete(&delete_vectorlEMySimVertexgR);
      instance.SetDeleteArray(&deleteArray_vectorlEMySimVertexgR);
      instance.SetDestructor(&destruct_vectorlEMySimVertexgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<MySimVertex> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<MySimVertex>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEMySimVertexgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<MySimVertex>*)0x0)->GetClass();
      vectorlEMySimVertexgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEMySimVertexgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEMySimVertexgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MySimVertex> : new vector<MySimVertex>;
   }
   static void *newArray_vectorlEMySimVertexgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MySimVertex>[nElements] : new vector<MySimVertex>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEMySimVertexgR(void *p) {
      delete ((vector<MySimVertex>*)p);
   }
   static void deleteArray_vectorlEMySimVertexgR(void *p) {
      delete [] ((vector<MySimVertex>*)p);
   }
   static void destruct_vectorlEMySimVertexgR(void *p) {
      typedef vector<MySimVertex> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<MySimVertex>

namespace ROOT {
   static TClass *vectorlEMyPartgR_Dictionary();
   static void vectorlEMyPartgR_TClassManip(TClass*);
   static void *new_vectorlEMyPartgR(void *p = 0);
   static void *newArray_vectorlEMyPartgR(Long_t size, void *p);
   static void delete_vectorlEMyPartgR(void *p);
   static void deleteArray_vectorlEMyPartgR(void *p);
   static void destruct_vectorlEMyPartgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<MyPart>*)
   {
      vector<MyPart> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<MyPart>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<MyPart>", -2, "vector", 214,
                  typeid(vector<MyPart>), DefineBehavior(ptr, ptr),
                  &vectorlEMyPartgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<MyPart>) );
      instance.SetNew(&new_vectorlEMyPartgR);
      instance.SetNewArray(&newArray_vectorlEMyPartgR);
      instance.SetDelete(&delete_vectorlEMyPartgR);
      instance.SetDeleteArray(&deleteArray_vectorlEMyPartgR);
      instance.SetDestructor(&destruct_vectorlEMyPartgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<MyPart> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<MyPart>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEMyPartgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<MyPart>*)0x0)->GetClass();
      vectorlEMyPartgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEMyPartgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEMyPartgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyPart> : new vector<MyPart>;
   }
   static void *newArray_vectorlEMyPartgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyPart>[nElements] : new vector<MyPart>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEMyPartgR(void *p) {
      delete ((vector<MyPart>*)p);
   }
   static void deleteArray_vectorlEMyPartgR(void *p) {
      delete [] ((vector<MyPart>*)p);
   }
   static void destruct_vectorlEMyPartgR(void *p) {
      typedef vector<MyPart> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<MyPart>

namespace ROOT {
   static TClass *vectorlEMyPUSumInfogR_Dictionary();
   static void vectorlEMyPUSumInfogR_TClassManip(TClass*);
   static void *new_vectorlEMyPUSumInfogR(void *p = 0);
   static void *newArray_vectorlEMyPUSumInfogR(Long_t size, void *p);
   static void delete_vectorlEMyPUSumInfogR(void *p);
   static void deleteArray_vectorlEMyPUSumInfogR(void *p);
   static void destruct_vectorlEMyPUSumInfogR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<MyPUSumInfo>*)
   {
      vector<MyPUSumInfo> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<MyPUSumInfo>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<MyPUSumInfo>", -2, "vector", 214,
                  typeid(vector<MyPUSumInfo>), DefineBehavior(ptr, ptr),
                  &vectorlEMyPUSumInfogR_Dictionary, isa_proxy, 4,
                  sizeof(vector<MyPUSumInfo>) );
      instance.SetNew(&new_vectorlEMyPUSumInfogR);
      instance.SetNewArray(&newArray_vectorlEMyPUSumInfogR);
      instance.SetDelete(&delete_vectorlEMyPUSumInfogR);
      instance.SetDeleteArray(&deleteArray_vectorlEMyPUSumInfogR);
      instance.SetDestructor(&destruct_vectorlEMyPUSumInfogR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<MyPUSumInfo> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<MyPUSumInfo>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEMyPUSumInfogR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<MyPUSumInfo>*)0x0)->GetClass();
      vectorlEMyPUSumInfogR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEMyPUSumInfogR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEMyPUSumInfogR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyPUSumInfo> : new vector<MyPUSumInfo>;
   }
   static void *newArray_vectorlEMyPUSumInfogR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyPUSumInfo>[nElements] : new vector<MyPUSumInfo>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEMyPUSumInfogR(void *p) {
      delete ((vector<MyPUSumInfo>*)p);
   }
   static void deleteArray_vectorlEMyPUSumInfogR(void *p) {
      delete [] ((vector<MyPUSumInfo>*)p);
   }
   static void destruct_vectorlEMyPUSumInfogR(void *p) {
      typedef vector<MyPUSumInfo> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<MyPUSumInfo>

namespace ROOT {
   static TClass *vectorlEMyPFJetgR_Dictionary();
   static void vectorlEMyPFJetgR_TClassManip(TClass*);
   static void *new_vectorlEMyPFJetgR(void *p = 0);
   static void *newArray_vectorlEMyPFJetgR(Long_t size, void *p);
   static void delete_vectorlEMyPFJetgR(void *p);
   static void deleteArray_vectorlEMyPFJetgR(void *p);
   static void destruct_vectorlEMyPFJetgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<MyPFJet>*)
   {
      vector<MyPFJet> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<MyPFJet>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<MyPFJet>", -2, "vector", 214,
                  typeid(vector<MyPFJet>), DefineBehavior(ptr, ptr),
                  &vectorlEMyPFJetgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<MyPFJet>) );
      instance.SetNew(&new_vectorlEMyPFJetgR);
      instance.SetNewArray(&newArray_vectorlEMyPFJetgR);
      instance.SetDelete(&delete_vectorlEMyPFJetgR);
      instance.SetDeleteArray(&deleteArray_vectorlEMyPFJetgR);
      instance.SetDestructor(&destruct_vectorlEMyPFJetgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<MyPFJet> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<MyPFJet>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEMyPFJetgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<MyPFJet>*)0x0)->GetClass();
      vectorlEMyPFJetgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEMyPFJetgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEMyPFJetgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyPFJet> : new vector<MyPFJet>;
   }
   static void *newArray_vectorlEMyPFJetgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyPFJet>[nElements] : new vector<MyPFJet>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEMyPFJetgR(void *p) {
      delete ((vector<MyPFJet>*)p);
   }
   static void deleteArray_vectorlEMyPFJetgR(void *p) {
      delete [] ((vector<MyPFJet>*)p);
   }
   static void destruct_vectorlEMyPFJetgR(void *p) {
      typedef vector<MyPFJet> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<MyPFJet>

namespace ROOT {
   static TClass *vectorlEMyPFCandgR_Dictionary();
   static void vectorlEMyPFCandgR_TClassManip(TClass*);
   static void *new_vectorlEMyPFCandgR(void *p = 0);
   static void *newArray_vectorlEMyPFCandgR(Long_t size, void *p);
   static void delete_vectorlEMyPFCandgR(void *p);
   static void deleteArray_vectorlEMyPFCandgR(void *p);
   static void destruct_vectorlEMyPFCandgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<MyPFCand>*)
   {
      vector<MyPFCand> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<MyPFCand>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<MyPFCand>", -2, "vector", 214,
                  typeid(vector<MyPFCand>), DefineBehavior(ptr, ptr),
                  &vectorlEMyPFCandgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<MyPFCand>) );
      instance.SetNew(&new_vectorlEMyPFCandgR);
      instance.SetNewArray(&newArray_vectorlEMyPFCandgR);
      instance.SetDelete(&delete_vectorlEMyPFCandgR);
      instance.SetDeleteArray(&deleteArray_vectorlEMyPFCandgR);
      instance.SetDestructor(&destruct_vectorlEMyPFCandgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<MyPFCand> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<MyPFCand>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEMyPFCandgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<MyPFCand>*)0x0)->GetClass();
      vectorlEMyPFCandgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEMyPFCandgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEMyPFCandgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyPFCand> : new vector<MyPFCand>;
   }
   static void *newArray_vectorlEMyPFCandgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyPFCand>[nElements] : new vector<MyPFCand>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEMyPFCandgR(void *p) {
      delete ((vector<MyPFCand>*)p);
   }
   static void deleteArray_vectorlEMyPFCandgR(void *p) {
      delete [] ((vector<MyPFCand>*)p);
   }
   static void destruct_vectorlEMyPFCandgR(void *p) {
      typedef vector<MyPFCand> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<MyPFCand>

namespace ROOT {
   static TClass *vectorlEMyMuongR_Dictionary();
   static void vectorlEMyMuongR_TClassManip(TClass*);
   static void *new_vectorlEMyMuongR(void *p = 0);
   static void *newArray_vectorlEMyMuongR(Long_t size, void *p);
   static void delete_vectorlEMyMuongR(void *p);
   static void deleteArray_vectorlEMyMuongR(void *p);
   static void destruct_vectorlEMyMuongR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<MyMuon>*)
   {
      vector<MyMuon> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<MyMuon>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<MyMuon>", -2, "vector", 214,
                  typeid(vector<MyMuon>), DefineBehavior(ptr, ptr),
                  &vectorlEMyMuongR_Dictionary, isa_proxy, 4,
                  sizeof(vector<MyMuon>) );
      instance.SetNew(&new_vectorlEMyMuongR);
      instance.SetNewArray(&newArray_vectorlEMyMuongR);
      instance.SetDelete(&delete_vectorlEMyMuongR);
      instance.SetDeleteArray(&deleteArray_vectorlEMyMuongR);
      instance.SetDestructor(&destruct_vectorlEMyMuongR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<MyMuon> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<MyMuon>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEMyMuongR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<MyMuon>*)0x0)->GetClass();
      vectorlEMyMuongR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEMyMuongR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEMyMuongR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyMuon> : new vector<MyMuon>;
   }
   static void *newArray_vectorlEMyMuongR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyMuon>[nElements] : new vector<MyMuon>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEMyMuongR(void *p) {
      delete ((vector<MyMuon>*)p);
   }
   static void deleteArray_vectorlEMyMuongR(void *p) {
      delete [] ((vector<MyMuon>*)p);
   }
   static void destruct_vectorlEMyMuongR(void *p) {
      typedef vector<MyMuon> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<MyMuon>

namespace ROOT {
   static TClass *vectorlEMyMetgR_Dictionary();
   static void vectorlEMyMetgR_TClassManip(TClass*);
   static void *new_vectorlEMyMetgR(void *p = 0);
   static void *newArray_vectorlEMyMetgR(Long_t size, void *p);
   static void delete_vectorlEMyMetgR(void *p);
   static void deleteArray_vectorlEMyMetgR(void *p);
   static void destruct_vectorlEMyMetgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<MyMet>*)
   {
      vector<MyMet> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<MyMet>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<MyMet>", -2, "vector", 214,
                  typeid(vector<MyMet>), DefineBehavior(ptr, ptr),
                  &vectorlEMyMetgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<MyMet>) );
      instance.SetNew(&new_vectorlEMyMetgR);
      instance.SetNewArray(&newArray_vectorlEMyMetgR);
      instance.SetDelete(&delete_vectorlEMyMetgR);
      instance.SetDeleteArray(&deleteArray_vectorlEMyMetgR);
      instance.SetDestructor(&destruct_vectorlEMyMetgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<MyMet> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<MyMet>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEMyMetgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<MyMet>*)0x0)->GetClass();
      vectorlEMyMetgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEMyMetgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEMyMetgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyMet> : new vector<MyMet>;
   }
   static void *newArray_vectorlEMyMetgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyMet>[nElements] : new vector<MyMet>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEMyMetgR(void *p) {
      delete ((vector<MyMet>*)p);
   }
   static void deleteArray_vectorlEMyMetgR(void *p) {
      delete [] ((vector<MyMet>*)p);
   }
   static void destruct_vectorlEMyMetgR(void *p) {
      typedef vector<MyMet> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<MyMet>

namespace ROOT {
   static TClass *vectorlEMyMITEvtSelgR_Dictionary();
   static void vectorlEMyMITEvtSelgR_TClassManip(TClass*);
   static void *new_vectorlEMyMITEvtSelgR(void *p = 0);
   static void *newArray_vectorlEMyMITEvtSelgR(Long_t size, void *p);
   static void delete_vectorlEMyMITEvtSelgR(void *p);
   static void deleteArray_vectorlEMyMITEvtSelgR(void *p);
   static void destruct_vectorlEMyMITEvtSelgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<MyMITEvtSel>*)
   {
      vector<MyMITEvtSel> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<MyMITEvtSel>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<MyMITEvtSel>", -2, "vector", 214,
                  typeid(vector<MyMITEvtSel>), DefineBehavior(ptr, ptr),
                  &vectorlEMyMITEvtSelgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<MyMITEvtSel>) );
      instance.SetNew(&new_vectorlEMyMITEvtSelgR);
      instance.SetNewArray(&newArray_vectorlEMyMITEvtSelgR);
      instance.SetDelete(&delete_vectorlEMyMITEvtSelgR);
      instance.SetDeleteArray(&deleteArray_vectorlEMyMITEvtSelgR);
      instance.SetDestructor(&destruct_vectorlEMyMITEvtSelgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<MyMITEvtSel> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<MyMITEvtSel>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEMyMITEvtSelgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<MyMITEvtSel>*)0x0)->GetClass();
      vectorlEMyMITEvtSelgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEMyMITEvtSelgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEMyMITEvtSelgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyMITEvtSel> : new vector<MyMITEvtSel>;
   }
   static void *newArray_vectorlEMyMITEvtSelgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyMITEvtSel>[nElements] : new vector<MyMITEvtSel>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEMyMITEvtSelgR(void *p) {
      delete ((vector<MyMITEvtSel>*)p);
   }
   static void deleteArray_vectorlEMyMITEvtSelgR(void *p) {
      delete [] ((vector<MyMITEvtSel>*)p);
   }
   static void destruct_vectorlEMyMITEvtSelgR(void *p) {
      typedef vector<MyMITEvtSel> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<MyMITEvtSel>

namespace ROOT {
   static TClass *vectorlEMyLambdasgR_Dictionary();
   static void vectorlEMyLambdasgR_TClassManip(TClass*);
   static void *new_vectorlEMyLambdasgR(void *p = 0);
   static void *newArray_vectorlEMyLambdasgR(Long_t size, void *p);
   static void delete_vectorlEMyLambdasgR(void *p);
   static void deleteArray_vectorlEMyLambdasgR(void *p);
   static void destruct_vectorlEMyLambdasgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<MyLambdas>*)
   {
      vector<MyLambdas> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<MyLambdas>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<MyLambdas>", -2, "vector", 214,
                  typeid(vector<MyLambdas>), DefineBehavior(ptr, ptr),
                  &vectorlEMyLambdasgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<MyLambdas>) );
      instance.SetNew(&new_vectorlEMyLambdasgR);
      instance.SetNewArray(&newArray_vectorlEMyLambdasgR);
      instance.SetDelete(&delete_vectorlEMyLambdasgR);
      instance.SetDeleteArray(&deleteArray_vectorlEMyLambdasgR);
      instance.SetDestructor(&destruct_vectorlEMyLambdasgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<MyLambdas> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<MyLambdas>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEMyLambdasgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<MyLambdas>*)0x0)->GetClass();
      vectorlEMyLambdasgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEMyLambdasgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEMyLambdasgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyLambdas> : new vector<MyLambdas>;
   }
   static void *newArray_vectorlEMyLambdasgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyLambdas>[nElements] : new vector<MyLambdas>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEMyLambdasgR(void *p) {
      delete ((vector<MyLambdas>*)p);
   }
   static void deleteArray_vectorlEMyLambdasgR(void *p) {
      delete [] ((vector<MyLambdas>*)p);
   }
   static void destruct_vectorlEMyLambdasgR(void *p) {
      typedef vector<MyLambdas> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<MyLambdas>

namespace ROOT {
   static TClass *vectorlEMyL1TrigOldgR_Dictionary();
   static void vectorlEMyL1TrigOldgR_TClassManip(TClass*);
   static void *new_vectorlEMyL1TrigOldgR(void *p = 0);
   static void *newArray_vectorlEMyL1TrigOldgR(Long_t size, void *p);
   static void delete_vectorlEMyL1TrigOldgR(void *p);
   static void deleteArray_vectorlEMyL1TrigOldgR(void *p);
   static void destruct_vectorlEMyL1TrigOldgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<MyL1TrigOld>*)
   {
      vector<MyL1TrigOld> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<MyL1TrigOld>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<MyL1TrigOld>", -2, "vector", 214,
                  typeid(vector<MyL1TrigOld>), DefineBehavior(ptr, ptr),
                  &vectorlEMyL1TrigOldgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<MyL1TrigOld>) );
      instance.SetNew(&new_vectorlEMyL1TrigOldgR);
      instance.SetNewArray(&newArray_vectorlEMyL1TrigOldgR);
      instance.SetDelete(&delete_vectorlEMyL1TrigOldgR);
      instance.SetDeleteArray(&deleteArray_vectorlEMyL1TrigOldgR);
      instance.SetDestructor(&destruct_vectorlEMyL1TrigOldgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<MyL1TrigOld> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<MyL1TrigOld>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEMyL1TrigOldgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<MyL1TrigOld>*)0x0)->GetClass();
      vectorlEMyL1TrigOldgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEMyL1TrigOldgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEMyL1TrigOldgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyL1TrigOld> : new vector<MyL1TrigOld>;
   }
   static void *newArray_vectorlEMyL1TrigOldgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyL1TrigOld>[nElements] : new vector<MyL1TrigOld>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEMyL1TrigOldgR(void *p) {
      delete ((vector<MyL1TrigOld>*)p);
   }
   static void deleteArray_vectorlEMyL1TrigOldgR(void *p) {
      delete [] ((vector<MyL1TrigOld>*)p);
   }
   static void destruct_vectorlEMyL1TrigOldgR(void *p) {
      typedef vector<MyL1TrigOld> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<MyL1TrigOld>

namespace ROOT {
   static TClass *vectorlEMyL1TriggR_Dictionary();
   static void vectorlEMyL1TriggR_TClassManip(TClass*);
   static void *new_vectorlEMyL1TriggR(void *p = 0);
   static void *newArray_vectorlEMyL1TriggR(Long_t size, void *p);
   static void delete_vectorlEMyL1TriggR(void *p);
   static void deleteArray_vectorlEMyL1TriggR(void *p);
   static void destruct_vectorlEMyL1TriggR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<MyL1Trig>*)
   {
      vector<MyL1Trig> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<MyL1Trig>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<MyL1Trig>", -2, "vector", 214,
                  typeid(vector<MyL1Trig>), DefineBehavior(ptr, ptr),
                  &vectorlEMyL1TriggR_Dictionary, isa_proxy, 4,
                  sizeof(vector<MyL1Trig>) );
      instance.SetNew(&new_vectorlEMyL1TriggR);
      instance.SetNewArray(&newArray_vectorlEMyL1TriggR);
      instance.SetDelete(&delete_vectorlEMyL1TriggR);
      instance.SetDeleteArray(&deleteArray_vectorlEMyL1TriggR);
      instance.SetDestructor(&destruct_vectorlEMyL1TriggR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<MyL1Trig> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<MyL1Trig>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEMyL1TriggR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<MyL1Trig>*)0x0)->GetClass();
      vectorlEMyL1TriggR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEMyL1TriggR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEMyL1TriggR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyL1Trig> : new vector<MyL1Trig>;
   }
   static void *newArray_vectorlEMyL1TriggR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyL1Trig>[nElements] : new vector<MyL1Trig>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEMyL1TriggR(void *p) {
      delete ((vector<MyL1Trig>*)p);
   }
   static void deleteArray_vectorlEMyL1TriggR(void *p) {
      delete [] ((vector<MyL1Trig>*)p);
   }
   static void destruct_vectorlEMyL1TriggR(void *p) {
      typedef vector<MyL1Trig> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<MyL1Trig>

namespace ROOT {
   static TClass *vectorlEMyKshortsgR_Dictionary();
   static void vectorlEMyKshortsgR_TClassManip(TClass*);
   static void *new_vectorlEMyKshortsgR(void *p = 0);
   static void *newArray_vectorlEMyKshortsgR(Long_t size, void *p);
   static void delete_vectorlEMyKshortsgR(void *p);
   static void deleteArray_vectorlEMyKshortsgR(void *p);
   static void destruct_vectorlEMyKshortsgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<MyKshorts>*)
   {
      vector<MyKshorts> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<MyKshorts>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<MyKshorts>", -2, "vector", 214,
                  typeid(vector<MyKshorts>), DefineBehavior(ptr, ptr),
                  &vectorlEMyKshortsgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<MyKshorts>) );
      instance.SetNew(&new_vectorlEMyKshortsgR);
      instance.SetNewArray(&newArray_vectorlEMyKshortsgR);
      instance.SetDelete(&delete_vectorlEMyKshortsgR);
      instance.SetDeleteArray(&deleteArray_vectorlEMyKshortsgR);
      instance.SetDestructor(&destruct_vectorlEMyKshortsgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<MyKshorts> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<MyKshorts>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEMyKshortsgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<MyKshorts>*)0x0)->GetClass();
      vectorlEMyKshortsgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEMyKshortsgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEMyKshortsgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyKshorts> : new vector<MyKshorts>;
   }
   static void *newArray_vectorlEMyKshortsgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyKshorts>[nElements] : new vector<MyKshorts>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEMyKshortsgR(void *p) {
      delete ((vector<MyKshorts>*)p);
   }
   static void deleteArray_vectorlEMyKshortsgR(void *p) {
      delete [] ((vector<MyKshorts>*)p);
   }
   static void destruct_vectorlEMyKshortsgR(void *p) {
      typedef vector<MyKshorts> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<MyKshorts>

namespace ROOT {
   static TClass *vectorlEMyJetgR_Dictionary();
   static void vectorlEMyJetgR_TClassManip(TClass*);
   static void *new_vectorlEMyJetgR(void *p = 0);
   static void *newArray_vectorlEMyJetgR(Long_t size, void *p);
   static void delete_vectorlEMyJetgR(void *p);
   static void deleteArray_vectorlEMyJetgR(void *p);
   static void destruct_vectorlEMyJetgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<MyJet>*)
   {
      vector<MyJet> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<MyJet>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<MyJet>", -2, "vector", 214,
                  typeid(vector<MyJet>), DefineBehavior(ptr, ptr),
                  &vectorlEMyJetgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<MyJet>) );
      instance.SetNew(&new_vectorlEMyJetgR);
      instance.SetNewArray(&newArray_vectorlEMyJetgR);
      instance.SetDelete(&delete_vectorlEMyJetgR);
      instance.SetDeleteArray(&deleteArray_vectorlEMyJetgR);
      instance.SetDestructor(&destruct_vectorlEMyJetgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<MyJet> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<MyJet>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEMyJetgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<MyJet>*)0x0)->GetClass();
      vectorlEMyJetgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEMyJetgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEMyJetgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyJet> : new vector<MyJet>;
   }
   static void *newArray_vectorlEMyJetgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyJet>[nElements] : new vector<MyJet>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEMyJetgR(void *p) {
      delete ((vector<MyJet>*)p);
   }
   static void deleteArray_vectorlEMyJetgR(void *p) {
      delete [] ((vector<MyJet>*)p);
   }
   static void destruct_vectorlEMyJetgR(void *p) {
      typedef vector<MyJet> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<MyJet>

namespace ROOT {
   static TClass *vectorlEMyHLTriggR_Dictionary();
   static void vectorlEMyHLTriggR_TClassManip(TClass*);
   static void *new_vectorlEMyHLTriggR(void *p = 0);
   static void *newArray_vectorlEMyHLTriggR(Long_t size, void *p);
   static void delete_vectorlEMyHLTriggR(void *p);
   static void deleteArray_vectorlEMyHLTriggR(void *p);
   static void destruct_vectorlEMyHLTriggR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<MyHLTrig>*)
   {
      vector<MyHLTrig> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<MyHLTrig>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<MyHLTrig>", -2, "vector", 214,
                  typeid(vector<MyHLTrig>), DefineBehavior(ptr, ptr),
                  &vectorlEMyHLTriggR_Dictionary, isa_proxy, 4,
                  sizeof(vector<MyHLTrig>) );
      instance.SetNew(&new_vectorlEMyHLTriggR);
      instance.SetNewArray(&newArray_vectorlEMyHLTriggR);
      instance.SetDelete(&delete_vectorlEMyHLTriggR);
      instance.SetDeleteArray(&deleteArray_vectorlEMyHLTriggR);
      instance.SetDestructor(&destruct_vectorlEMyHLTriggR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<MyHLTrig> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<MyHLTrig>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEMyHLTriggR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<MyHLTrig>*)0x0)->GetClass();
      vectorlEMyHLTriggR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEMyHLTriggR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEMyHLTriggR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyHLTrig> : new vector<MyHLTrig>;
   }
   static void *newArray_vectorlEMyHLTriggR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyHLTrig>[nElements] : new vector<MyHLTrig>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEMyHLTriggR(void *p) {
      delete ((vector<MyHLTrig>*)p);
   }
   static void deleteArray_vectorlEMyHLTriggR(void *p) {
      delete [] ((vector<MyHLTrig>*)p);
   }
   static void destruct_vectorlEMyHLTriggR(void *p) {
      typedef vector<MyHLTrig> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<MyHLTrig>

namespace ROOT {
   static TClass *vectorlEMyGenPartgR_Dictionary();
   static void vectorlEMyGenPartgR_TClassManip(TClass*);
   static void *new_vectorlEMyGenPartgR(void *p = 0);
   static void *newArray_vectorlEMyGenPartgR(Long_t size, void *p);
   static void delete_vectorlEMyGenPartgR(void *p);
   static void deleteArray_vectorlEMyGenPartgR(void *p);
   static void destruct_vectorlEMyGenPartgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<MyGenPart>*)
   {
      vector<MyGenPart> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<MyGenPart>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<MyGenPart>", -2, "vector", 214,
                  typeid(vector<MyGenPart>), DefineBehavior(ptr, ptr),
                  &vectorlEMyGenPartgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<MyGenPart>) );
      instance.SetNew(&new_vectorlEMyGenPartgR);
      instance.SetNewArray(&newArray_vectorlEMyGenPartgR);
      instance.SetDelete(&delete_vectorlEMyGenPartgR);
      instance.SetDeleteArray(&deleteArray_vectorlEMyGenPartgR);
      instance.SetDestructor(&destruct_vectorlEMyGenPartgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<MyGenPart> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<MyGenPart>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEMyGenPartgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<MyGenPart>*)0x0)->GetClass();
      vectorlEMyGenPartgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEMyGenPartgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEMyGenPartgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyGenPart> : new vector<MyGenPart>;
   }
   static void *newArray_vectorlEMyGenPartgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyGenPart>[nElements] : new vector<MyGenPart>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEMyGenPartgR(void *p) {
      delete ((vector<MyGenPart>*)p);
   }
   static void deleteArray_vectorlEMyGenPartgR(void *p) {
      delete [] ((vector<MyGenPart>*)p);
   }
   static void destruct_vectorlEMyGenPartgR(void *p) {
      typedef vector<MyGenPart> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<MyGenPart>

namespace ROOT {
   static TClass *vectorlEMyGenMetgR_Dictionary();
   static void vectorlEMyGenMetgR_TClassManip(TClass*);
   static void *new_vectorlEMyGenMetgR(void *p = 0);
   static void *newArray_vectorlEMyGenMetgR(Long_t size, void *p);
   static void delete_vectorlEMyGenMetgR(void *p);
   static void deleteArray_vectorlEMyGenMetgR(void *p);
   static void destruct_vectorlEMyGenMetgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<MyGenMet>*)
   {
      vector<MyGenMet> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<MyGenMet>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<MyGenMet>", -2, "vector", 214,
                  typeid(vector<MyGenMet>), DefineBehavior(ptr, ptr),
                  &vectorlEMyGenMetgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<MyGenMet>) );
      instance.SetNew(&new_vectorlEMyGenMetgR);
      instance.SetNewArray(&newArray_vectorlEMyGenMetgR);
      instance.SetDelete(&delete_vectorlEMyGenMetgR);
      instance.SetDeleteArray(&deleteArray_vectorlEMyGenMetgR);
      instance.SetDestructor(&destruct_vectorlEMyGenMetgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<MyGenMet> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<MyGenMet>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEMyGenMetgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<MyGenMet>*)0x0)->GetClass();
      vectorlEMyGenMetgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEMyGenMetgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEMyGenMetgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyGenMet> : new vector<MyGenMet>;
   }
   static void *newArray_vectorlEMyGenMetgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyGenMet>[nElements] : new vector<MyGenMet>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEMyGenMetgR(void *p) {
      delete ((vector<MyGenMet>*)p);
   }
   static void deleteArray_vectorlEMyGenMetgR(void *p) {
      delete [] ((vector<MyGenMet>*)p);
   }
   static void destruct_vectorlEMyGenMetgR(void *p) {
      typedef vector<MyGenMet> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<MyGenMet>

namespace ROOT {
   static TClass *vectorlEMyGenKingR_Dictionary();
   static void vectorlEMyGenKingR_TClassManip(TClass*);
   static void *new_vectorlEMyGenKingR(void *p = 0);
   static void *newArray_vectorlEMyGenKingR(Long_t size, void *p);
   static void delete_vectorlEMyGenKingR(void *p);
   static void deleteArray_vectorlEMyGenKingR(void *p);
   static void destruct_vectorlEMyGenKingR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<MyGenKin>*)
   {
      vector<MyGenKin> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<MyGenKin>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<MyGenKin>", -2, "vector", 214,
                  typeid(vector<MyGenKin>), DefineBehavior(ptr, ptr),
                  &vectorlEMyGenKingR_Dictionary, isa_proxy, 4,
                  sizeof(vector<MyGenKin>) );
      instance.SetNew(&new_vectorlEMyGenKingR);
      instance.SetNewArray(&newArray_vectorlEMyGenKingR);
      instance.SetDelete(&delete_vectorlEMyGenKingR);
      instance.SetDeleteArray(&deleteArray_vectorlEMyGenKingR);
      instance.SetDestructor(&destruct_vectorlEMyGenKingR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<MyGenKin> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<MyGenKin>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEMyGenKingR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<MyGenKin>*)0x0)->GetClass();
      vectorlEMyGenKingR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEMyGenKingR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEMyGenKingR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyGenKin> : new vector<MyGenKin>;
   }
   static void *newArray_vectorlEMyGenKingR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyGenKin>[nElements] : new vector<MyGenKin>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEMyGenKingR(void *p) {
      delete ((vector<MyGenKin>*)p);
   }
   static void deleteArray_vectorlEMyGenKingR(void *p) {
      delete [] ((vector<MyGenKin>*)p);
   }
   static void destruct_vectorlEMyGenKingR(void *p) {
      typedef vector<MyGenKin> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<MyGenKin>

namespace ROOT {
   static TClass *vectorlEMyGenJetgR_Dictionary();
   static void vectorlEMyGenJetgR_TClassManip(TClass*);
   static void *new_vectorlEMyGenJetgR(void *p = 0);
   static void *newArray_vectorlEMyGenJetgR(Long_t size, void *p);
   static void delete_vectorlEMyGenJetgR(void *p);
   static void deleteArray_vectorlEMyGenJetgR(void *p);
   static void destruct_vectorlEMyGenJetgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<MyGenJet>*)
   {
      vector<MyGenJet> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<MyGenJet>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<MyGenJet>", -2, "vector", 214,
                  typeid(vector<MyGenJet>), DefineBehavior(ptr, ptr),
                  &vectorlEMyGenJetgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<MyGenJet>) );
      instance.SetNew(&new_vectorlEMyGenJetgR);
      instance.SetNewArray(&newArray_vectorlEMyGenJetgR);
      instance.SetDelete(&delete_vectorlEMyGenJetgR);
      instance.SetDeleteArray(&deleteArray_vectorlEMyGenJetgR);
      instance.SetDestructor(&destruct_vectorlEMyGenJetgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<MyGenJet> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<MyGenJet>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEMyGenJetgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<MyGenJet>*)0x0)->GetClass();
      vectorlEMyGenJetgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEMyGenJetgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEMyGenJetgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyGenJet> : new vector<MyGenJet>;
   }
   static void *newArray_vectorlEMyGenJetgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyGenJet>[nElements] : new vector<MyGenJet>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEMyGenJetgR(void *p) {
      delete ((vector<MyGenJet>*)p);
   }
   static void deleteArray_vectorlEMyGenJetgR(void *p) {
      delete [] ((vector<MyGenJet>*)p);
   }
   static void destruct_vectorlEMyGenJetgR(void *p) {
      typedef vector<MyGenJet> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<MyGenJet>

namespace ROOT {
   static TClass *vectorlEMyFwdGapgR_Dictionary();
   static void vectorlEMyFwdGapgR_TClassManip(TClass*);
   static void *new_vectorlEMyFwdGapgR(void *p = 0);
   static void *newArray_vectorlEMyFwdGapgR(Long_t size, void *p);
   static void delete_vectorlEMyFwdGapgR(void *p);
   static void deleteArray_vectorlEMyFwdGapgR(void *p);
   static void destruct_vectorlEMyFwdGapgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<MyFwdGap>*)
   {
      vector<MyFwdGap> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<MyFwdGap>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<MyFwdGap>", -2, "vector", 214,
                  typeid(vector<MyFwdGap>), DefineBehavior(ptr, ptr),
                  &vectorlEMyFwdGapgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<MyFwdGap>) );
      instance.SetNew(&new_vectorlEMyFwdGapgR);
      instance.SetNewArray(&newArray_vectorlEMyFwdGapgR);
      instance.SetDelete(&delete_vectorlEMyFwdGapgR);
      instance.SetDeleteArray(&deleteArray_vectorlEMyFwdGapgR);
      instance.SetDestructor(&destruct_vectorlEMyFwdGapgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<MyFwdGap> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<MyFwdGap>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEMyFwdGapgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<MyFwdGap>*)0x0)->GetClass();
      vectorlEMyFwdGapgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEMyFwdGapgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEMyFwdGapgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyFwdGap> : new vector<MyFwdGap>;
   }
   static void *newArray_vectorlEMyFwdGapgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyFwdGap>[nElements] : new vector<MyFwdGap>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEMyFwdGapgR(void *p) {
      delete ((vector<MyFwdGap>*)p);
   }
   static void deleteArray_vectorlEMyFwdGapgR(void *p) {
      delete [] ((vector<MyFwdGap>*)p);
   }
   static void destruct_vectorlEMyFwdGapgR(void *p) {
      typedef vector<MyFwdGap> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<MyFwdGap>

namespace ROOT {
   static TClass *vectorlEMyFSCInfogR_Dictionary();
   static void vectorlEMyFSCInfogR_TClassManip(TClass*);
   static void *new_vectorlEMyFSCInfogR(void *p = 0);
   static void *newArray_vectorlEMyFSCInfogR(Long_t size, void *p);
   static void delete_vectorlEMyFSCInfogR(void *p);
   static void deleteArray_vectorlEMyFSCInfogR(void *p);
   static void destruct_vectorlEMyFSCInfogR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<MyFSCInfo>*)
   {
      vector<MyFSCInfo> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<MyFSCInfo>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<MyFSCInfo>", -2, "vector", 214,
                  typeid(vector<MyFSCInfo>), DefineBehavior(ptr, ptr),
                  &vectorlEMyFSCInfogR_Dictionary, isa_proxy, 4,
                  sizeof(vector<MyFSCInfo>) );
      instance.SetNew(&new_vectorlEMyFSCInfogR);
      instance.SetNewArray(&newArray_vectorlEMyFSCInfogR);
      instance.SetDelete(&delete_vectorlEMyFSCInfogR);
      instance.SetDeleteArray(&deleteArray_vectorlEMyFSCInfogR);
      instance.SetDestructor(&destruct_vectorlEMyFSCInfogR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<MyFSCInfo> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<MyFSCInfo>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEMyFSCInfogR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<MyFSCInfo>*)0x0)->GetClass();
      vectorlEMyFSCInfogR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEMyFSCInfogR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEMyFSCInfogR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyFSCInfo> : new vector<MyFSCInfo>;
   }
   static void *newArray_vectorlEMyFSCInfogR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyFSCInfo>[nElements] : new vector<MyFSCInfo>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEMyFSCInfogR(void *p) {
      delete ((vector<MyFSCInfo>*)p);
   }
   static void deleteArray_vectorlEMyFSCInfogR(void *p) {
      delete [] ((vector<MyFSCInfo>*)p);
   }
   static void destruct_vectorlEMyFSCInfogR(void *p) {
      typedef vector<MyFSCInfo> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<MyFSCInfo>

namespace ROOT {
   static TClass *vectorlEMyFSCHitgR_Dictionary();
   static void vectorlEMyFSCHitgR_TClassManip(TClass*);
   static void *new_vectorlEMyFSCHitgR(void *p = 0);
   static void *newArray_vectorlEMyFSCHitgR(Long_t size, void *p);
   static void delete_vectorlEMyFSCHitgR(void *p);
   static void deleteArray_vectorlEMyFSCHitgR(void *p);
   static void destruct_vectorlEMyFSCHitgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<MyFSCHit>*)
   {
      vector<MyFSCHit> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<MyFSCHit>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<MyFSCHit>", -2, "vector", 214,
                  typeid(vector<MyFSCHit>), DefineBehavior(ptr, ptr),
                  &vectorlEMyFSCHitgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<MyFSCHit>) );
      instance.SetNew(&new_vectorlEMyFSCHitgR);
      instance.SetNewArray(&newArray_vectorlEMyFSCHitgR);
      instance.SetDelete(&delete_vectorlEMyFSCHitgR);
      instance.SetDeleteArray(&deleteArray_vectorlEMyFSCHitgR);
      instance.SetDestructor(&destruct_vectorlEMyFSCHitgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<MyFSCHit> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<MyFSCHit>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEMyFSCHitgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<MyFSCHit>*)0x0)->GetClass();
      vectorlEMyFSCHitgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEMyFSCHitgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEMyFSCHitgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyFSCHit> : new vector<MyFSCHit>;
   }
   static void *newArray_vectorlEMyFSCHitgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyFSCHit>[nElements] : new vector<MyFSCHit>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEMyFSCHitgR(void *p) {
      delete ((vector<MyFSCHit>*)p);
   }
   static void deleteArray_vectorlEMyFSCHitgR(void *p) {
      delete [] ((vector<MyFSCHit>*)p);
   }
   static void destruct_vectorlEMyFSCHitgR(void *p) {
      typedef vector<MyFSCHit> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<MyFSCHit>

namespace ROOT {
   static TClass *vectorlEMyFSCDigigR_Dictionary();
   static void vectorlEMyFSCDigigR_TClassManip(TClass*);
   static void *new_vectorlEMyFSCDigigR(void *p = 0);
   static void *newArray_vectorlEMyFSCDigigR(Long_t size, void *p);
   static void delete_vectorlEMyFSCDigigR(void *p);
   static void deleteArray_vectorlEMyFSCDigigR(void *p);
   static void destruct_vectorlEMyFSCDigigR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<MyFSCDigi>*)
   {
      vector<MyFSCDigi> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<MyFSCDigi>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<MyFSCDigi>", -2, "vector", 214,
                  typeid(vector<MyFSCDigi>), DefineBehavior(ptr, ptr),
                  &vectorlEMyFSCDigigR_Dictionary, isa_proxy, 4,
                  sizeof(vector<MyFSCDigi>) );
      instance.SetNew(&new_vectorlEMyFSCDigigR);
      instance.SetNewArray(&newArray_vectorlEMyFSCDigigR);
      instance.SetDelete(&delete_vectorlEMyFSCDigigR);
      instance.SetDeleteArray(&deleteArray_vectorlEMyFSCDigigR);
      instance.SetDestructor(&destruct_vectorlEMyFSCDigigR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<MyFSCDigi> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<MyFSCDigi>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEMyFSCDigigR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<MyFSCDigi>*)0x0)->GetClass();
      vectorlEMyFSCDigigR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEMyFSCDigigR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEMyFSCDigigR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyFSCDigi> : new vector<MyFSCDigi>;
   }
   static void *newArray_vectorlEMyFSCDigigR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyFSCDigi>[nElements] : new vector<MyFSCDigi>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEMyFSCDigigR(void *p) {
      delete ((vector<MyFSCDigi>*)p);
   }
   static void deleteArray_vectorlEMyFSCDigigR(void *p) {
      delete [] ((vector<MyFSCDigi>*)p);
   }
   static void destruct_vectorlEMyFSCDigigR(void *p) {
      typedef vector<MyFSCDigi> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<MyFSCDigi>

namespace ROOT {
   static TClass *vectorlEMyEvtIdgR_Dictionary();
   static void vectorlEMyEvtIdgR_TClassManip(TClass*);
   static void *new_vectorlEMyEvtIdgR(void *p = 0);
   static void *newArray_vectorlEMyEvtIdgR(Long_t size, void *p);
   static void delete_vectorlEMyEvtIdgR(void *p);
   static void deleteArray_vectorlEMyEvtIdgR(void *p);
   static void destruct_vectorlEMyEvtIdgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<MyEvtId>*)
   {
      vector<MyEvtId> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<MyEvtId>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<MyEvtId>", -2, "vector", 214,
                  typeid(vector<MyEvtId>), DefineBehavior(ptr, ptr),
                  &vectorlEMyEvtIdgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<MyEvtId>) );
      instance.SetNew(&new_vectorlEMyEvtIdgR);
      instance.SetNewArray(&newArray_vectorlEMyEvtIdgR);
      instance.SetDelete(&delete_vectorlEMyEvtIdgR);
      instance.SetDeleteArray(&deleteArray_vectorlEMyEvtIdgR);
      instance.SetDestructor(&destruct_vectorlEMyEvtIdgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<MyEvtId> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<MyEvtId>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEMyEvtIdgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<MyEvtId>*)0x0)->GetClass();
      vectorlEMyEvtIdgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEMyEvtIdgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEMyEvtIdgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyEvtId> : new vector<MyEvtId>;
   }
   static void *newArray_vectorlEMyEvtIdgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyEvtId>[nElements] : new vector<MyEvtId>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEMyEvtIdgR(void *p) {
      delete ((vector<MyEvtId>*)p);
   }
   static void deleteArray_vectorlEMyEvtIdgR(void *p) {
      delete [] ((vector<MyEvtId>*)p);
   }
   static void destruct_vectorlEMyEvtIdgR(void *p) {
      typedef vector<MyEvtId> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<MyEvtId>

namespace ROOT {
   static TClass *vectorlEMyElectrongR_Dictionary();
   static void vectorlEMyElectrongR_TClassManip(TClass*);
   static void *new_vectorlEMyElectrongR(void *p = 0);
   static void *newArray_vectorlEMyElectrongR(Long_t size, void *p);
   static void delete_vectorlEMyElectrongR(void *p);
   static void deleteArray_vectorlEMyElectrongR(void *p);
   static void destruct_vectorlEMyElectrongR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<MyElectron>*)
   {
      vector<MyElectron> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<MyElectron>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<MyElectron>", -2, "vector", 214,
                  typeid(vector<MyElectron>), DefineBehavior(ptr, ptr),
                  &vectorlEMyElectrongR_Dictionary, isa_proxy, 4,
                  sizeof(vector<MyElectron>) );
      instance.SetNew(&new_vectorlEMyElectrongR);
      instance.SetNewArray(&newArray_vectorlEMyElectrongR);
      instance.SetDelete(&delete_vectorlEMyElectrongR);
      instance.SetDeleteArray(&deleteArray_vectorlEMyElectrongR);
      instance.SetDestructor(&destruct_vectorlEMyElectrongR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<MyElectron> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<MyElectron>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEMyElectrongR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<MyElectron>*)0x0)->GetClass();
      vectorlEMyElectrongR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEMyElectrongR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEMyElectrongR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyElectron> : new vector<MyElectron>;
   }
   static void *newArray_vectorlEMyElectrongR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyElectron>[nElements] : new vector<MyElectron>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEMyElectrongR(void *p) {
      delete ((vector<MyElectron>*)p);
   }
   static void deleteArray_vectorlEMyElectrongR(void *p) {
      delete [] ((vector<MyElectron>*)p);
   }
   static void destruct_vectorlEMyElectrongR(void *p) {
      typedef vector<MyElectron> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<MyElectron>

namespace ROOT {
   static TClass *vectorlEMyDiJetgR_Dictionary();
   static void vectorlEMyDiJetgR_TClassManip(TClass*);
   static void *new_vectorlEMyDiJetgR(void *p = 0);
   static void *newArray_vectorlEMyDiJetgR(Long_t size, void *p);
   static void delete_vectorlEMyDiJetgR(void *p);
   static void deleteArray_vectorlEMyDiJetgR(void *p);
   static void destruct_vectorlEMyDiJetgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<MyDiJet>*)
   {
      vector<MyDiJet> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<MyDiJet>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<MyDiJet>", -2, "vector", 214,
                  typeid(vector<MyDiJet>), DefineBehavior(ptr, ptr),
                  &vectorlEMyDiJetgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<MyDiJet>) );
      instance.SetNew(&new_vectorlEMyDiJetgR);
      instance.SetNewArray(&newArray_vectorlEMyDiJetgR);
      instance.SetDelete(&delete_vectorlEMyDiJetgR);
      instance.SetDeleteArray(&deleteArray_vectorlEMyDiJetgR);
      instance.SetDestructor(&destruct_vectorlEMyDiJetgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<MyDiJet> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<MyDiJet>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEMyDiJetgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<MyDiJet>*)0x0)->GetClass();
      vectorlEMyDiJetgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEMyDiJetgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEMyDiJetgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyDiJet> : new vector<MyDiJet>;
   }
   static void *newArray_vectorlEMyDiJetgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyDiJet>[nElements] : new vector<MyDiJet>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEMyDiJetgR(void *p) {
      delete ((vector<MyDiJet>*)p);
   }
   static void deleteArray_vectorlEMyDiJetgR(void *p) {
      delete [] ((vector<MyDiJet>*)p);
   }
   static void destruct_vectorlEMyDiJetgR(void *p) {
      typedef vector<MyDiJet> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<MyDiJet>

namespace ROOT {
   static TClass *vectorlEMyCastorRecHitgR_Dictionary();
   static void vectorlEMyCastorRecHitgR_TClassManip(TClass*);
   static void *new_vectorlEMyCastorRecHitgR(void *p = 0);
   static void *newArray_vectorlEMyCastorRecHitgR(Long_t size, void *p);
   static void delete_vectorlEMyCastorRecHitgR(void *p);
   static void deleteArray_vectorlEMyCastorRecHitgR(void *p);
   static void destruct_vectorlEMyCastorRecHitgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<MyCastorRecHit>*)
   {
      vector<MyCastorRecHit> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<MyCastorRecHit>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<MyCastorRecHit>", -2, "vector", 214,
                  typeid(vector<MyCastorRecHit>), DefineBehavior(ptr, ptr),
                  &vectorlEMyCastorRecHitgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<MyCastorRecHit>) );
      instance.SetNew(&new_vectorlEMyCastorRecHitgR);
      instance.SetNewArray(&newArray_vectorlEMyCastorRecHitgR);
      instance.SetDelete(&delete_vectorlEMyCastorRecHitgR);
      instance.SetDeleteArray(&deleteArray_vectorlEMyCastorRecHitgR);
      instance.SetDestructor(&destruct_vectorlEMyCastorRecHitgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<MyCastorRecHit> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<MyCastorRecHit>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEMyCastorRecHitgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<MyCastorRecHit>*)0x0)->GetClass();
      vectorlEMyCastorRecHitgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEMyCastorRecHitgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEMyCastorRecHitgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyCastorRecHit> : new vector<MyCastorRecHit>;
   }
   static void *newArray_vectorlEMyCastorRecHitgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyCastorRecHit>[nElements] : new vector<MyCastorRecHit>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEMyCastorRecHitgR(void *p) {
      delete ((vector<MyCastorRecHit>*)p);
   }
   static void deleteArray_vectorlEMyCastorRecHitgR(void *p) {
      delete [] ((vector<MyCastorRecHit>*)p);
   }
   static void destruct_vectorlEMyCastorRecHitgR(void *p) {
      typedef vector<MyCastorRecHit> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<MyCastorRecHit>

namespace ROOT {
   static TClass *vectorlEMyCastorJetgR_Dictionary();
   static void vectorlEMyCastorJetgR_TClassManip(TClass*);
   static void *new_vectorlEMyCastorJetgR(void *p = 0);
   static void *newArray_vectorlEMyCastorJetgR(Long_t size, void *p);
   static void delete_vectorlEMyCastorJetgR(void *p);
   static void deleteArray_vectorlEMyCastorJetgR(void *p);
   static void destruct_vectorlEMyCastorJetgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<MyCastorJet>*)
   {
      vector<MyCastorJet> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<MyCastorJet>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<MyCastorJet>", -2, "vector", 214,
                  typeid(vector<MyCastorJet>), DefineBehavior(ptr, ptr),
                  &vectorlEMyCastorJetgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<MyCastorJet>) );
      instance.SetNew(&new_vectorlEMyCastorJetgR);
      instance.SetNewArray(&newArray_vectorlEMyCastorJetgR);
      instance.SetDelete(&delete_vectorlEMyCastorJetgR);
      instance.SetDeleteArray(&deleteArray_vectorlEMyCastorJetgR);
      instance.SetDestructor(&destruct_vectorlEMyCastorJetgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<MyCastorJet> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<MyCastorJet>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEMyCastorJetgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<MyCastorJet>*)0x0)->GetClass();
      vectorlEMyCastorJetgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEMyCastorJetgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEMyCastorJetgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyCastorJet> : new vector<MyCastorJet>;
   }
   static void *newArray_vectorlEMyCastorJetgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyCastorJet>[nElements] : new vector<MyCastorJet>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEMyCastorJetgR(void *p) {
      delete ((vector<MyCastorJet>*)p);
   }
   static void deleteArray_vectorlEMyCastorJetgR(void *p) {
      delete [] ((vector<MyCastorJet>*)p);
   }
   static void destruct_vectorlEMyCastorJetgR(void *p) {
      typedef vector<MyCastorJet> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<MyCastorJet>

namespace ROOT {
   static TClass *vectorlEMyCastorDigigR_Dictionary();
   static void vectorlEMyCastorDigigR_TClassManip(TClass*);
   static void *new_vectorlEMyCastorDigigR(void *p = 0);
   static void *newArray_vectorlEMyCastorDigigR(Long_t size, void *p);
   static void delete_vectorlEMyCastorDigigR(void *p);
   static void deleteArray_vectorlEMyCastorDigigR(void *p);
   static void destruct_vectorlEMyCastorDigigR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<MyCastorDigi>*)
   {
      vector<MyCastorDigi> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<MyCastorDigi>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<MyCastorDigi>", -2, "vector", 214,
                  typeid(vector<MyCastorDigi>), DefineBehavior(ptr, ptr),
                  &vectorlEMyCastorDigigR_Dictionary, isa_proxy, 4,
                  sizeof(vector<MyCastorDigi>) );
      instance.SetNew(&new_vectorlEMyCastorDigigR);
      instance.SetNewArray(&newArray_vectorlEMyCastorDigigR);
      instance.SetDelete(&delete_vectorlEMyCastorDigigR);
      instance.SetDeleteArray(&deleteArray_vectorlEMyCastorDigigR);
      instance.SetDestructor(&destruct_vectorlEMyCastorDigigR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<MyCastorDigi> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<MyCastorDigi>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEMyCastorDigigR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<MyCastorDigi>*)0x0)->GetClass();
      vectorlEMyCastorDigigR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEMyCastorDigigR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEMyCastorDigigR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyCastorDigi> : new vector<MyCastorDigi>;
   }
   static void *newArray_vectorlEMyCastorDigigR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyCastorDigi>[nElements] : new vector<MyCastorDigi>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEMyCastorDigigR(void *p) {
      delete ((vector<MyCastorDigi>*)p);
   }
   static void deleteArray_vectorlEMyCastorDigigR(void *p) {
      delete [] ((vector<MyCastorDigi>*)p);
   }
   static void destruct_vectorlEMyCastorDigigR(void *p) {
      typedef vector<MyCastorDigi> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<MyCastorDigi>

namespace ROOT {
   static TClass *vectorlEMyCaloTowergR_Dictionary();
   static void vectorlEMyCaloTowergR_TClassManip(TClass*);
   static void *new_vectorlEMyCaloTowergR(void *p = 0);
   static void *newArray_vectorlEMyCaloTowergR(Long_t size, void *p);
   static void delete_vectorlEMyCaloTowergR(void *p);
   static void deleteArray_vectorlEMyCaloTowergR(void *p);
   static void destruct_vectorlEMyCaloTowergR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<MyCaloTower>*)
   {
      vector<MyCaloTower> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<MyCaloTower>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<MyCaloTower>", -2, "vector", 214,
                  typeid(vector<MyCaloTower>), DefineBehavior(ptr, ptr),
                  &vectorlEMyCaloTowergR_Dictionary, isa_proxy, 4,
                  sizeof(vector<MyCaloTower>) );
      instance.SetNew(&new_vectorlEMyCaloTowergR);
      instance.SetNewArray(&newArray_vectorlEMyCaloTowergR);
      instance.SetDelete(&delete_vectorlEMyCaloTowergR);
      instance.SetDeleteArray(&deleteArray_vectorlEMyCaloTowergR);
      instance.SetDestructor(&destruct_vectorlEMyCaloTowergR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<MyCaloTower> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<MyCaloTower>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEMyCaloTowergR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<MyCaloTower>*)0x0)->GetClass();
      vectorlEMyCaloTowergR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEMyCaloTowergR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEMyCaloTowergR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyCaloTower> : new vector<MyCaloTower>;
   }
   static void *newArray_vectorlEMyCaloTowergR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyCaloTower>[nElements] : new vector<MyCaloTower>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEMyCaloTowergR(void *p) {
      delete ((vector<MyCaloTower>*)p);
   }
   static void deleteArray_vectorlEMyCaloTowergR(void *p) {
      delete [] ((vector<MyCaloTower>*)p);
   }
   static void destruct_vectorlEMyCaloTowergR(void *p) {
      typedef vector<MyCaloTower> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<MyCaloTower>

namespace ROOT {
   static TClass *vectorlEMyCaloJetgR_Dictionary();
   static void vectorlEMyCaloJetgR_TClassManip(TClass*);
   static void *new_vectorlEMyCaloJetgR(void *p = 0);
   static void *newArray_vectorlEMyCaloJetgR(Long_t size, void *p);
   static void delete_vectorlEMyCaloJetgR(void *p);
   static void deleteArray_vectorlEMyCaloJetgR(void *p);
   static void destruct_vectorlEMyCaloJetgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<MyCaloJet>*)
   {
      vector<MyCaloJet> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<MyCaloJet>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<MyCaloJet>", -2, "vector", 214,
                  typeid(vector<MyCaloJet>), DefineBehavior(ptr, ptr),
                  &vectorlEMyCaloJetgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<MyCaloJet>) );
      instance.SetNew(&new_vectorlEMyCaloJetgR);
      instance.SetNewArray(&newArray_vectorlEMyCaloJetgR);
      instance.SetDelete(&delete_vectorlEMyCaloJetgR);
      instance.SetDeleteArray(&deleteArray_vectorlEMyCaloJetgR);
      instance.SetDestructor(&destruct_vectorlEMyCaloJetgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<MyCaloJet> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<MyCaloJet>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEMyCaloJetgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<MyCaloJet>*)0x0)->GetClass();
      vectorlEMyCaloJetgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEMyCaloJetgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEMyCaloJetgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyCaloJet> : new vector<MyCaloJet>;
   }
   static void *newArray_vectorlEMyCaloJetgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyCaloJet>[nElements] : new vector<MyCaloJet>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEMyCaloJetgR(void *p) {
      delete ((vector<MyCaloJet>*)p);
   }
   static void deleteArray_vectorlEMyCaloJetgR(void *p) {
      delete [] ((vector<MyCaloJet>*)p);
   }
   static void destruct_vectorlEMyCaloJetgR(void *p) {
      typedef vector<MyCaloJet> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<MyCaloJet>

namespace ROOT {
   static TClass *vectorlEMyBeamSpotgR_Dictionary();
   static void vectorlEMyBeamSpotgR_TClassManip(TClass*);
   static void *new_vectorlEMyBeamSpotgR(void *p = 0);
   static void *newArray_vectorlEMyBeamSpotgR(Long_t size, void *p);
   static void delete_vectorlEMyBeamSpotgR(void *p);
   static void deleteArray_vectorlEMyBeamSpotgR(void *p);
   static void destruct_vectorlEMyBeamSpotgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<MyBeamSpot>*)
   {
      vector<MyBeamSpot> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<MyBeamSpot>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<MyBeamSpot>", -2, "vector", 214,
                  typeid(vector<MyBeamSpot>), DefineBehavior(ptr, ptr),
                  &vectorlEMyBeamSpotgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<MyBeamSpot>) );
      instance.SetNew(&new_vectorlEMyBeamSpotgR);
      instance.SetNewArray(&newArray_vectorlEMyBeamSpotgR);
      instance.SetDelete(&delete_vectorlEMyBeamSpotgR);
      instance.SetDeleteArray(&deleteArray_vectorlEMyBeamSpotgR);
      instance.SetDestructor(&destruct_vectorlEMyBeamSpotgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<MyBeamSpot> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<MyBeamSpot>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEMyBeamSpotgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<MyBeamSpot>*)0x0)->GetClass();
      vectorlEMyBeamSpotgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEMyBeamSpotgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEMyBeamSpotgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyBeamSpot> : new vector<MyBeamSpot>;
   }
   static void *newArray_vectorlEMyBeamSpotgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyBeamSpot>[nElements] : new vector<MyBeamSpot>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEMyBeamSpotgR(void *p) {
      delete ((vector<MyBeamSpot>*)p);
   }
   static void deleteArray_vectorlEMyBeamSpotgR(void *p) {
      delete [] ((vector<MyBeamSpot>*)p);
   }
   static void destruct_vectorlEMyBeamSpotgR(void *p) {
      typedef vector<MyBeamSpot> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<MyBeamSpot>

namespace ROOT {
   static TClass *vectorlEMyBaseJetgR_Dictionary();
   static void vectorlEMyBaseJetgR_TClassManip(TClass*);
   static void *new_vectorlEMyBaseJetgR(void *p = 0);
   static void *newArray_vectorlEMyBaseJetgR(Long_t size, void *p);
   static void delete_vectorlEMyBaseJetgR(void *p);
   static void deleteArray_vectorlEMyBaseJetgR(void *p);
   static void destruct_vectorlEMyBaseJetgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<MyBaseJet>*)
   {
      vector<MyBaseJet> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<MyBaseJet>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<MyBaseJet>", -2, "vector", 214,
                  typeid(vector<MyBaseJet>), DefineBehavior(ptr, ptr),
                  &vectorlEMyBaseJetgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<MyBaseJet>) );
      instance.SetNew(&new_vectorlEMyBaseJetgR);
      instance.SetNewArray(&newArray_vectorlEMyBaseJetgR);
      instance.SetDelete(&delete_vectorlEMyBaseJetgR);
      instance.SetDeleteArray(&deleteArray_vectorlEMyBaseJetgR);
      instance.SetDestructor(&destruct_vectorlEMyBaseJetgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<MyBaseJet> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<MyBaseJet>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEMyBaseJetgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<MyBaseJet>*)0x0)->GetClass();
      vectorlEMyBaseJetgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEMyBaseJetgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEMyBaseJetgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyBaseJet> : new vector<MyBaseJet>;
   }
   static void *newArray_vectorlEMyBaseJetgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) vector<MyBaseJet>[nElements] : new vector<MyBaseJet>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEMyBaseJetgR(void *p) {
      delete ((vector<MyBaseJet>*)p);
   }
   static void deleteArray_vectorlEMyBaseJetgR(void *p) {
      delete [] ((vector<MyBaseJet>*)p);
   }
   static void destruct_vectorlEMyBaseJetgR(void *p) {
      typedef vector<MyBaseJet> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<MyBaseJet>

namespace ROOT {
   static TClass *maplEstringcOunsignedsPintgR_Dictionary();
   static void maplEstringcOunsignedsPintgR_TClassManip(TClass*);
   static void *new_maplEstringcOunsignedsPintgR(void *p = 0);
   static void *newArray_maplEstringcOunsignedsPintgR(Long_t size, void *p);
   static void delete_maplEstringcOunsignedsPintgR(void *p);
   static void deleteArray_maplEstringcOunsignedsPintgR(void *p);
   static void destruct_maplEstringcOunsignedsPintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<string,unsigned int>*)
   {
      map<string,unsigned int> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<string,unsigned int>));
      static ::ROOT::TGenericClassInfo 
         instance("map<string,unsigned int>", -2, "map", 96,
                  typeid(map<string,unsigned int>), DefineBehavior(ptr, ptr),
                  &maplEstringcOunsignedsPintgR_Dictionary, isa_proxy, 0,
                  sizeof(map<string,unsigned int>) );
      instance.SetNew(&new_maplEstringcOunsignedsPintgR);
      instance.SetNewArray(&newArray_maplEstringcOunsignedsPintgR);
      instance.SetDelete(&delete_maplEstringcOunsignedsPintgR);
      instance.SetDeleteArray(&deleteArray_maplEstringcOunsignedsPintgR);
      instance.SetDestructor(&destruct_maplEstringcOunsignedsPintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<string,unsigned int> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const map<string,unsigned int>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEstringcOunsignedsPintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<string,unsigned int>*)0x0)->GetClass();
      maplEstringcOunsignedsPintgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEstringcOunsignedsPintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEstringcOunsignedsPintgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) map<string,unsigned int> : new map<string,unsigned int>;
   }
   static void *newArray_maplEstringcOunsignedsPintgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) map<string,unsigned int>[nElements] : new map<string,unsigned int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEstringcOunsignedsPintgR(void *p) {
      delete ((map<string,unsigned int>*)p);
   }
   static void deleteArray_maplEstringcOunsignedsPintgR(void *p) {
      delete [] ((map<string,unsigned int>*)p);
   }
   static void destruct_maplEstringcOunsignedsPintgR(void *p) {
      typedef map<string,unsigned int> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<string,unsigned int>

namespace ROOT {
   static TClass *maplEstringcOdoublegR_Dictionary();
   static void maplEstringcOdoublegR_TClassManip(TClass*);
   static void *new_maplEstringcOdoublegR(void *p = 0);
   static void *newArray_maplEstringcOdoublegR(Long_t size, void *p);
   static void delete_maplEstringcOdoublegR(void *p);
   static void deleteArray_maplEstringcOdoublegR(void *p);
   static void destruct_maplEstringcOdoublegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<string,double>*)
   {
      map<string,double> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<string,double>));
      static ::ROOT::TGenericClassInfo 
         instance("map<string,double>", -2, "map", 96,
                  typeid(map<string,double>), DefineBehavior(ptr, ptr),
                  &maplEstringcOdoublegR_Dictionary, isa_proxy, 0,
                  sizeof(map<string,double>) );
      instance.SetNew(&new_maplEstringcOdoublegR);
      instance.SetNewArray(&newArray_maplEstringcOdoublegR);
      instance.SetDelete(&delete_maplEstringcOdoublegR);
      instance.SetDeleteArray(&deleteArray_maplEstringcOdoublegR);
      instance.SetDestructor(&destruct_maplEstringcOdoublegR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<string,double> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const map<string,double>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEstringcOdoublegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<string,double>*)0x0)->GetClass();
      maplEstringcOdoublegR_TClassManip(theClass);
   return theClass;
   }

   static void maplEstringcOdoublegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEstringcOdoublegR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) map<string,double> : new map<string,double>;
   }
   static void *newArray_maplEstringcOdoublegR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) map<string,double>[nElements] : new map<string,double>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEstringcOdoublegR(void *p) {
      delete ((map<string,double>*)p);
   }
   static void deleteArray_maplEstringcOdoublegR(void *p) {
      delete [] ((map<string,double>*)p);
   }
   static void destruct_maplEstringcOdoublegR(void *p) {
      typedef map<string,double> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<string,double>

namespace ROOT {
   static TClass *maplEstringcOboolgR_Dictionary();
   static void maplEstringcOboolgR_TClassManip(TClass*);
   static void *new_maplEstringcOboolgR(void *p = 0);
   static void *newArray_maplEstringcOboolgR(Long_t size, void *p);
   static void delete_maplEstringcOboolgR(void *p);
   static void deleteArray_maplEstringcOboolgR(void *p);
   static void destruct_maplEstringcOboolgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<string,bool>*)
   {
      map<string,bool> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<string,bool>));
      static ::ROOT::TGenericClassInfo 
         instance("map<string,bool>", -2, "map", 96,
                  typeid(map<string,bool>), DefineBehavior(ptr, ptr),
                  &maplEstringcOboolgR_Dictionary, isa_proxy, 0,
                  sizeof(map<string,bool>) );
      instance.SetNew(&new_maplEstringcOboolgR);
      instance.SetNewArray(&newArray_maplEstringcOboolgR);
      instance.SetDelete(&delete_maplEstringcOboolgR);
      instance.SetDeleteArray(&deleteArray_maplEstringcOboolgR);
      instance.SetDestructor(&destruct_maplEstringcOboolgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<string,bool> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const map<string,bool>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEstringcOboolgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<string,bool>*)0x0)->GetClass();
      maplEstringcOboolgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEstringcOboolgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEstringcOboolgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) map<string,bool> : new map<string,bool>;
   }
   static void *newArray_maplEstringcOboolgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) map<string,bool>[nElements] : new map<string,bool>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEstringcOboolgR(void *p) {
      delete ((map<string,bool>*)p);
   }
   static void deleteArray_maplEstringcOboolgR(void *p) {
      delete [] ((map<string,bool>*)p);
   }
   static void destruct_maplEstringcOboolgR(void *p) {
      typedef map<string,bool> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<string,bool>

namespace ROOT {
   static TClass *maplEstringcOMyBaseJetgR_Dictionary();
   static void maplEstringcOMyBaseJetgR_TClassManip(TClass*);
   static void *new_maplEstringcOMyBaseJetgR(void *p = 0);
   static void *newArray_maplEstringcOMyBaseJetgR(Long_t size, void *p);
   static void delete_maplEstringcOMyBaseJetgR(void *p);
   static void deleteArray_maplEstringcOMyBaseJetgR(void *p);
   static void destruct_maplEstringcOMyBaseJetgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<string,MyBaseJet>*)
   {
      map<string,MyBaseJet> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<string,MyBaseJet>));
      static ::ROOT::TGenericClassInfo 
         instance("map<string,MyBaseJet>", -2, "map", 96,
                  typeid(map<string,MyBaseJet>), DefineBehavior(ptr, ptr),
                  &maplEstringcOMyBaseJetgR_Dictionary, isa_proxy, 0,
                  sizeof(map<string,MyBaseJet>) );
      instance.SetNew(&new_maplEstringcOMyBaseJetgR);
      instance.SetNewArray(&newArray_maplEstringcOMyBaseJetgR);
      instance.SetDelete(&delete_maplEstringcOMyBaseJetgR);
      instance.SetDeleteArray(&deleteArray_maplEstringcOMyBaseJetgR);
      instance.SetDestructor(&destruct_maplEstringcOMyBaseJetgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<string,MyBaseJet> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const map<string,MyBaseJet>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEstringcOMyBaseJetgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<string,MyBaseJet>*)0x0)->GetClass();
      maplEstringcOMyBaseJetgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEstringcOMyBaseJetgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEstringcOMyBaseJetgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) map<string,MyBaseJet> : new map<string,MyBaseJet>;
   }
   static void *newArray_maplEstringcOMyBaseJetgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) map<string,MyBaseJet>[nElements] : new map<string,MyBaseJet>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEstringcOMyBaseJetgR(void *p) {
      delete ((map<string,MyBaseJet>*)p);
   }
   static void deleteArray_maplEstringcOMyBaseJetgR(void *p) {
      delete [] ((map<string,MyBaseJet>*)p);
   }
   static void destruct_maplEstringcOMyBaseJetgR(void *p) {
      typedef map<string,MyBaseJet> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<string,MyBaseJet>

namespace ROOT {
   static TClass *maplEintcOintgR_Dictionary();
   static void maplEintcOintgR_TClassManip(TClass*);
   static void *new_maplEintcOintgR(void *p = 0);
   static void *newArray_maplEintcOintgR(Long_t size, void *p);
   static void delete_maplEintcOintgR(void *p);
   static void deleteArray_maplEintcOintgR(void *p);
   static void destruct_maplEintcOintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<int,int>*)
   {
      map<int,int> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<int,int>));
      static ::ROOT::TGenericClassInfo 
         instance("map<int,int>", -2, "map", 96,
                  typeid(map<int,int>), DefineBehavior(ptr, ptr),
                  &maplEintcOintgR_Dictionary, isa_proxy, 0,
                  sizeof(map<int,int>) );
      instance.SetNew(&new_maplEintcOintgR);
      instance.SetNewArray(&newArray_maplEintcOintgR);
      instance.SetDelete(&delete_maplEintcOintgR);
      instance.SetDeleteArray(&deleteArray_maplEintcOintgR);
      instance.SetDestructor(&destruct_maplEintcOintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<int,int> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const map<int,int>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEintcOintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<int,int>*)0x0)->GetClass();
      maplEintcOintgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEintcOintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEintcOintgR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) map<int,int> : new map<int,int>;
   }
   static void *newArray_maplEintcOintgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) map<int,int>[nElements] : new map<int,int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEintcOintgR(void *p) {
      delete ((map<int,int>*)p);
   }
   static void deleteArray_maplEintcOintgR(void *p) {
      delete [] ((map<int,int>*)p);
   }
   static void destruct_maplEintcOintgR(void *p) {
      typedef map<int,int> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<int,int>

namespace ROOT {
   static TClass *maplEintcOdoublegR_Dictionary();
   static void maplEintcOdoublegR_TClassManip(TClass*);
   static void *new_maplEintcOdoublegR(void *p = 0);
   static void *newArray_maplEintcOdoublegR(Long_t size, void *p);
   static void delete_maplEintcOdoublegR(void *p);
   static void deleteArray_maplEintcOdoublegR(void *p);
   static void destruct_maplEintcOdoublegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<int,double>*)
   {
      map<int,double> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<int,double>));
      static ::ROOT::TGenericClassInfo 
         instance("map<int,double>", -2, "map", 96,
                  typeid(map<int,double>), DefineBehavior(ptr, ptr),
                  &maplEintcOdoublegR_Dictionary, isa_proxy, 0,
                  sizeof(map<int,double>) );
      instance.SetNew(&new_maplEintcOdoublegR);
      instance.SetNewArray(&newArray_maplEintcOdoublegR);
      instance.SetDelete(&delete_maplEintcOdoublegR);
      instance.SetDeleteArray(&deleteArray_maplEintcOdoublegR);
      instance.SetDestructor(&destruct_maplEintcOdoublegR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<int,double> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const map<int,double>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEintcOdoublegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<int,double>*)0x0)->GetClass();
      maplEintcOdoublegR_TClassManip(theClass);
   return theClass;
   }

   static void maplEintcOdoublegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEintcOdoublegR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) map<int,double> : new map<int,double>;
   }
   static void *newArray_maplEintcOdoublegR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) map<int,double>[nElements] : new map<int,double>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEintcOdoublegR(void *p) {
      delete ((map<int,double>*)p);
   }
   static void deleteArray_maplEintcOdoublegR(void *p) {
      delete [] ((map<int,double>*)p);
   }
   static void destruct_maplEintcOdoublegR(void *p) {
      typedef map<int,double> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<int,double>

namespace {
  void TriggerDictionaryInitialization_eventdict_Impl() {
    static const char* headers[] = {
"UATree/UADataFormat/interface/MyBeamSpot.h",
"UATree/UADataFormat/interface/MyCastorDigi.h",
"UATree/UADataFormat/interface/MyCastorJet.h",
"UATree/UADataFormat/interface/MyCastorRecHit.h",
"UATree/UADataFormat/interface/MyDiJet.h",
"UATree/UADataFormat/interface/MyEvtId.h",
"UATree/UADataFormat/interface/MyFwdGap.h",
"UATree/UADataFormat/interface/MyMet.h",
"UATree/UADataFormat/interface/MyGenMet.h",
"UATree/UADataFormat/interface/MyGenKin.h",
"UATree/UADataFormat/interface/MyGenPart.h",
"UATree/UADataFormat/interface/MyGenJet.h",
"UATree/UADataFormat/interface/MyPUSumInfo.h",
"UATree/UADataFormat/interface/MyHLTrig.h",
"UATree/UADataFormat/interface/MyL1Trig.h",
"UATree/UADataFormat/interface/MyL1TrigOld.h",
"UATree/UADataFormat/interface/MyMITEvtSel.h",
"UATree/UADataFormat/interface/MyPart.h",
"UATree/UADataFormat/interface/MySimVertex.h",
"UATree/UADataFormat/interface/MyVertex.h",
"UATree/UADataFormat/interface/MyTracks.h",
"UATree/UADataFormat/interface/MyElectron.h",
"UATree/UADataFormat/interface/MyMuon.h",
"UATree/UADataFormat/interface/MyBaseJet.h",
"UATree/UADataFormat/interface/MyJet.h",
"UATree/UADataFormat/interface/MyCaloJet.h",
"UATree/UADataFormat/interface/MyTrackJet.h",
"UATree/UADataFormat/interface/MyPFJet.h",
"UATree/UADataFormat/interface/MyPFCand.h",
"UATree/UADataFormat/interface/MyCaloTower.h",
"UATree/UADataFormat/interface/MyFSCHit.h",
"UATree/UADataFormat/interface/MyFSCDigi.h",
"UATree/UADataFormat/interface/MyFSCInfo.h",
"UATree/UADataFormat/interface/MyKshorts.h",
"UATree/UADataFormat/interface/MyLambdas.h",
0
    };
    static const char* includePaths[] = {
"/afs/cern.ch/user/e/eliza/private/TOTEM_JPSI/RPSIM/CMSSW_7_6_3/src/CMS-TOTEM-Ntuples/CMSdataFormat",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc493/lcg/root/6.02.12-kpegke4/include",
"/afs/cern.ch/user/e/eliza/private/TOTEM_JPSI/RPSIM/CMSSW_7_6_3/src/CMS-TOTEM-Ntuples/CMSdataFormat/utilities/",
0
    };
    static const char* fwdDeclCode = 
R"DICTFWDDCLS(
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace std{template <class _CharT> struct __attribute__((annotate("$clingAutoload$string")))  char_traits;
}
namespace std{template <typename > class __attribute__((annotate("$clingAutoload$string")))  allocator;
}
class __attribute__((annotate("$clingAutoload$UATree/UADataFormat/interface/MyBeamSpot.h")))  MyBeamSpot;
class __attribute__((annotate("$clingAutoload$UATree/UADataFormat/interface/MyCastorDigi.h")))  MyCastorDigi;
class __attribute__((annotate("$clingAutoload$UATree/UADataFormat/interface/MyCastorJet.h")))  MyCastorJet;
class __attribute__((annotate("$clingAutoload$UATree/UADataFormat/interface/MyCastorRecHit.h")))  MyCastorRecHit;
class __attribute__((annotate("$clingAutoload$UATree/UADataFormat/interface/MyDiJet.h")))  MyDiJet;
class __attribute__((annotate("$clingAutoload$UATree/UADataFormat/interface/MyEvtId.h")))  MyEvtId;
class __attribute__((annotate("$clingAutoload$UATree/UADataFormat/interface/MyFwdGap.h")))  MyFwdGap;
class __attribute__((annotate("$clingAutoload$UATree/UADataFormat/interface/MyGenKin.h")))  MyGenKin;
class __attribute__((annotate("$clingAutoload$UATree/UADataFormat/interface/MyPUSumInfo.h")))  MyPUSumInfo;
class __attribute__((annotate("$clingAutoload$UATree/UADataFormat/interface/MyMet.h")))  MyMet;
class __attribute__((annotate("$clingAutoload$UATree/UADataFormat/interface/MyGenMet.h")))  MyGenMet;
class __attribute__((annotate("$clingAutoload$UATree/UADataFormat/interface/MyGenPart.h")))  MyGenPart;
class __attribute__((annotate("$clingAutoload$UATree/UADataFormat/interface/MyGenJet.h")))  MyGenJet;
class __attribute__((annotate("$clingAutoload$UATree/UADataFormat/interface/MyHLTrig.h")))  MyHLTrig;
class __attribute__((annotate("$clingAutoload$UATree/UADataFormat/interface/MyL1Trig.h")))  MyL1Trig;
class __attribute__((annotate("$clingAutoload$UATree/UADataFormat/interface/MyL1TrigOld.h")))  MyL1TrigOld;
class __attribute__((annotate("$clingAutoload$UATree/UADataFormat/interface/MyMITEvtSel.h")))  MyMITEvtSel;
class __attribute__((annotate("$clingAutoload$UATree/UADataFormat/interface/MyMet.h")))  MyPart;
class __attribute__((annotate("$clingAutoload$UATree/UADataFormat/interface/MySimVertex.h")))  MySimVertex;
class __attribute__((annotate("$clingAutoload$UATree/UADataFormat/interface/MyVertex.h")))  MyVertex;
class __attribute__((annotate("$clingAutoload$UATree/UADataFormat/interface/MyTracks.h")))  MyTracks;
class __attribute__((annotate("$clingAutoload$UATree/UADataFormat/interface/MyElectron.h")))  MyElectron;
class __attribute__((annotate("$clingAutoload$UATree/UADataFormat/interface/MyMuon.h")))  MyMuon;
class __attribute__((annotate("$clingAutoload$UATree/UADataFormat/interface/MyBaseJet.h")))  MyBaseJet;
class __attribute__((annotate("$clingAutoload$UATree/UADataFormat/interface/MyJet.h")))  MyJet;
class __attribute__((annotate("$clingAutoload$UATree/UADataFormat/interface/MyCaloJet.h")))  MyCaloJet;
class __attribute__((annotate("$clingAutoload$UATree/UADataFormat/interface/MyTrackJet.h")))  MyTrackJet;
class __attribute__((annotate("$clingAutoload$UATree/UADataFormat/interface/MyPFJet.h")))  MyPFJet;
class __attribute__((annotate("$clingAutoload$UATree/UADataFormat/interface/MyPFCand.h")))  MyPFCand;
class __attribute__((annotate("$clingAutoload$UATree/UADataFormat/interface/MyCaloTower.h")))  MyCaloTower;
class __attribute__((annotate("$clingAutoload$UATree/UADataFormat/interface/MyKshorts.h")))  MyKshorts;
class __attribute__((annotate("$clingAutoload$UATree/UADataFormat/interface/MyLambdas.h")))  MyLambdas;
class __attribute__((annotate("$clingAutoload$UATree/UADataFormat/interface/MyFSCHit.h")))  MyFSCHit;
class __attribute__((annotate("$clingAutoload$UATree/UADataFormat/interface/MyFSCDigi.h")))  MyFSCDigi;
class __attribute__((annotate("$clingAutoload$UATree/UADataFormat/interface/MyFSCInfo.h")))  MyFSCInfo;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "UATree/UADataFormat/interface/MyBeamSpot.h"
#include "UATree/UADataFormat/interface/MyCastorDigi.h"
#include "UATree/UADataFormat/interface/MyCastorJet.h"
#include "UATree/UADataFormat/interface/MyCastorRecHit.h"
#include "UATree/UADataFormat/interface/MyDiJet.h"
#include "UATree/UADataFormat/interface/MyEvtId.h"
#include "UATree/UADataFormat/interface/MyFwdGap.h"
#include "UATree/UADataFormat/interface/MyMet.h"
#include "UATree/UADataFormat/interface/MyGenMet.h"
#include "UATree/UADataFormat/interface/MyGenKin.h"
#include "UATree/UADataFormat/interface/MyGenPart.h"
#include "UATree/UADataFormat/interface/MyGenJet.h"
#include "UATree/UADataFormat/interface/MyPUSumInfo.h"
#include "UATree/UADataFormat/interface/MyHLTrig.h"
#include "UATree/UADataFormat/interface/MyL1Trig.h"
#include "UATree/UADataFormat/interface/MyL1TrigOld.h"
#include "UATree/UADataFormat/interface/MyMITEvtSel.h"
#include "UATree/UADataFormat/interface/MyPart.h"
#include "UATree/UADataFormat/interface/MySimVertex.h"
#include "UATree/UADataFormat/interface/MyVertex.h"
#include "UATree/UADataFormat/interface/MyTracks.h"
#include "UATree/UADataFormat/interface/MyElectron.h"
#include "UATree/UADataFormat/interface/MyMuon.h"
#include "UATree/UADataFormat/interface/MyBaseJet.h"
#include "UATree/UADataFormat/interface/MyJet.h"
#include "UATree/UADataFormat/interface/MyCaloJet.h"
#include "UATree/UADataFormat/interface/MyTrackJet.h"
#include "UATree/UADataFormat/interface/MyPFJet.h"
#include "UATree/UADataFormat/interface/MyPFCand.h"
#include "UATree/UADataFormat/interface/MyCaloTower.h"
#include "UATree/UADataFormat/interface/MyFSCHit.h"
#include "UATree/UADataFormat/interface/MyFSCDigi.h"
#include "UATree/UADataFormat/interface/MyFSCInfo.h"
#include "UATree/UADataFormat/interface/MyKshorts.h"
#include "UATree/UADataFormat/interface/MyLambdas.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"MyBaseJet", payloadCode, "@",
"MyBeamSpot", payloadCode, "@",
"MyCaloJet", payloadCode, "@",
"MyCaloTower", payloadCode, "@",
"MyCastorDigi", payloadCode, "@",
"MyCastorJet", payloadCode, "@",
"MyCastorRecHit", payloadCode, "@",
"MyDiJet", payloadCode, "@",
"MyElectron", payloadCode, "@",
"MyEvtId", payloadCode, "@",
"MyFSCDigi", payloadCode, "@",
"MyFSCHit", payloadCode, "@",
"MyFSCInfo", payloadCode, "@",
"MyFwdGap", payloadCode, "@",
"MyGenJet", payloadCode, "@",
"MyGenKin", payloadCode, "@",
"MyGenMet", payloadCode, "@",
"MyGenPart", payloadCode, "@",
"MyHLTrig", payloadCode, "@",
"MyJet", payloadCode, "@",
"MyKshorts", payloadCode, "@",
"MyL1Trig", payloadCode, "@",
"MyL1TrigOld", payloadCode, "@",
"MyLambdas", payloadCode, "@",
"MyMITEvtSel", payloadCode, "@",
"MyMet", payloadCode, "@",
"MyMuon", payloadCode, "@",
"MyPFCand", payloadCode, "@",
"MyPFJet", payloadCode, "@",
"MyPUSumInfo", payloadCode, "@",
"MyPart", payloadCode, "@",
"MySimVertex", payloadCode, "@",
"MyTrackJet", payloadCode, "@",
"MyTracks", payloadCode, "@",
"MyVertex", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("eventdict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_eventdict_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_eventdict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_eventdict() {
  TriggerDictionaryInitialization_eventdict_Impl();
}
