// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME tmpdIslc6_amd64_gcc493dIsrcdIUATreedIMitEdmdIsrcdIUATreeMitEdmdIadIUATreeMitEdm_xr

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
#include "src/UATree/MitEdm/src/classes.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static TClass *mitedmcLcLEvtSelData_Dictionary();
   static void mitedmcLcLEvtSelData_TClassManip(TClass*);
   static void *new_mitedmcLcLEvtSelData(void *p = 0);
   static void *newArray_mitedmcLcLEvtSelData(Long_t size, void *p);
   static void delete_mitedmcLcLEvtSelData(void *p);
   static void deleteArray_mitedmcLcLEvtSelData(void *p);
   static void destruct_mitedmcLcLEvtSelData(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::mitedm::EvtSelData*)
   {
      ::mitedm::EvtSelData *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::mitedm::EvtSelData));
      static ::ROOT::TGenericClassInfo 
         instance("mitedm::EvtSelData", "UATree/MitEdm/interface/EvtSelData.h", 16,
                  typeid(::mitedm::EvtSelData), DefineBehavior(ptr, ptr),
                  &mitedmcLcLEvtSelData_Dictionary, isa_proxy, 0,
                  sizeof(::mitedm::EvtSelData) );
      instance.SetNew(&new_mitedmcLcLEvtSelData);
      instance.SetNewArray(&newArray_mitedmcLcLEvtSelData);
      instance.SetDelete(&delete_mitedmcLcLEvtSelData);
      instance.SetDeleteArray(&deleteArray_mitedmcLcLEvtSelData);
      instance.SetDestructor(&destruct_mitedmcLcLEvtSelData);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::mitedm::EvtSelData*)
   {
      return GenerateInitInstanceLocal((::mitedm::EvtSelData*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::mitedm::EvtSelData*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *mitedmcLcLEvtSelData_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::mitedm::EvtSelData*)0x0)->GetClass();
      mitedmcLcLEvtSelData_TClassManip(theClass);
   return theClass;
   }

   static void mitedmcLcLEvtSelData_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *edmcLcLWrapperlEmitedmcLcLEvtSelDatagR_Dictionary();
   static void edmcLcLWrapperlEmitedmcLcLEvtSelDatagR_TClassManip(TClass*);
   static void *new_edmcLcLWrapperlEmitedmcLcLEvtSelDatagR(void *p = 0);
   static void *newArray_edmcLcLWrapperlEmitedmcLcLEvtSelDatagR(Long_t size, void *p);
   static void delete_edmcLcLWrapperlEmitedmcLcLEvtSelDatagR(void *p);
   static void deleteArray_edmcLcLWrapperlEmitedmcLcLEvtSelDatagR(void *p);
   static void destruct_edmcLcLWrapperlEmitedmcLcLEvtSelDatagR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::edm::Wrapper<mitedm::EvtSelData>*)
   {
      ::edm::Wrapper<mitedm::EvtSelData> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::edm::Wrapper<mitedm::EvtSelData>));
      static ::ROOT::TGenericClassInfo 
         instance("edm::Wrapper<mitedm::EvtSelData>", ::edm::Wrapper<mitedm::EvtSelData>::Class_Version(), "DataFormats/Common/interface/Wrapper.h", 25,
                  typeid(::edm::Wrapper<mitedm::EvtSelData>), DefineBehavior(ptr, ptr),
                  &edmcLcLWrapperlEmitedmcLcLEvtSelDatagR_Dictionary, isa_proxy, 0,
                  sizeof(::edm::Wrapper<mitedm::EvtSelData>) );
      instance.SetNew(&new_edmcLcLWrapperlEmitedmcLcLEvtSelDatagR);
      instance.SetNewArray(&newArray_edmcLcLWrapperlEmitedmcLcLEvtSelDatagR);
      instance.SetDelete(&delete_edmcLcLWrapperlEmitedmcLcLEvtSelDatagR);
      instance.SetDeleteArray(&deleteArray_edmcLcLWrapperlEmitedmcLcLEvtSelDatagR);
      instance.SetDestructor(&destruct_edmcLcLWrapperlEmitedmcLcLEvtSelDatagR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::edm::Wrapper<mitedm::EvtSelData>*)
   {
      return GenerateInitInstanceLocal((::edm::Wrapper<mitedm::EvtSelData>*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::edm::Wrapper<mitedm::EvtSelData>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *edmcLcLWrapperlEmitedmcLcLEvtSelDatagR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::edm::Wrapper<mitedm::EvtSelData>*)0x0)->GetClass();
      edmcLcLWrapperlEmitedmcLcLEvtSelDatagR_TClassManip(theClass);
   return theClass;
   }

   static void edmcLcLWrapperlEmitedmcLcLEvtSelDatagR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_mitedmcLcLEvtSelData(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::mitedm::EvtSelData : new ::mitedm::EvtSelData;
   }
   static void *newArray_mitedmcLcLEvtSelData(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::mitedm::EvtSelData[nElements] : new ::mitedm::EvtSelData[nElements];
   }
   // Wrapper around operator delete
   static void delete_mitedmcLcLEvtSelData(void *p) {
      delete ((::mitedm::EvtSelData*)p);
   }
   static void deleteArray_mitedmcLcLEvtSelData(void *p) {
      delete [] ((::mitedm::EvtSelData*)p);
   }
   static void destruct_mitedmcLcLEvtSelData(void *p) {
      typedef ::mitedm::EvtSelData current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::mitedm::EvtSelData

namespace ROOT {
   // Wrappers around operator new
   static void *new_edmcLcLWrapperlEmitedmcLcLEvtSelDatagR(void *p) {
      return  p ? ::new((::ROOT::TOperatorNewHelper*)p) ::edm::Wrapper<mitedm::EvtSelData> : new ::edm::Wrapper<mitedm::EvtSelData>;
   }
   static void *newArray_edmcLcLWrapperlEmitedmcLcLEvtSelDatagR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::TOperatorNewHelper*)p) ::edm::Wrapper<mitedm::EvtSelData>[nElements] : new ::edm::Wrapper<mitedm::EvtSelData>[nElements];
   }
   // Wrapper around operator delete
   static void delete_edmcLcLWrapperlEmitedmcLcLEvtSelDatagR(void *p) {
      delete ((::edm::Wrapper<mitedm::EvtSelData>*)p);
   }
   static void deleteArray_edmcLcLWrapperlEmitedmcLcLEvtSelDatagR(void *p) {
      delete [] ((::edm::Wrapper<mitedm::EvtSelData>*)p);
   }
   static void destruct_edmcLcLWrapperlEmitedmcLcLEvtSelDatagR(void *p) {
      typedef ::edm::Wrapper<mitedm::EvtSelData> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::edm::Wrapper<mitedm::EvtSelData>

namespace {
  void TriggerDictionaryInitialization_UATreeMitEdm_xr_Impl() {
    static const char* headers[] = {
0    };
    static const char* includePaths[] = {
"/afs/cern.ch/user/e/eliza/private/TOTEM_JPSI/RPSIM/CMSSW_7_6_3/src",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc493/cms/cmssw/CMSSW_7_6_3/src",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc493/cms/coral/CORAL_2_3_21-kpegke4/include/LCG",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc493/lcg/root/6.02.12-kpegke4/include",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc493/external/boost/1.57.0-kpegke/include",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc493/external/pcre/7.9__8.33/include",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc493/external/bz2lib/1.0.5/include",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc493/external/clhep/2.2.0.4-kpegke/include",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc493/external/gsl/1.10/include",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc493/external/hepmc/2.06.07/include",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc493/external/libuuid/2.22.2/include",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc493/external/python/2.7.6-kpegke/include/python2.7",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc493/external/sigcpp/2.2.10/include/sigc++-2.0",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc493/external/tbb/43_20150316oss/include",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc493/cms/vdt/v0.3.2-kpegke/include",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc493/external/xerces-c/2.8.0/include",
"/cvmfs/cms.cern.ch/slc6_amd64_gcc493/external/xz/5.2.1/include",
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
namespace mitedm{class __attribute__((annotate("$clingAutoload$UATree/MitEdm/interface/EvtSelData.h")))  EvtSelData;}
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
// $Id: classes.h,v 1.12 2009/12/07 22:50:11 loizides Exp $

#include "DataFormats/Common/interface/Wrapper.h"
#include "UATree/MitEdm/interface/EvtSelData.h"

namespace
{
  namespace
  {
    mitedm::EvtSelData                                 dummy08;
    edm::Wrapper<mitedm::EvtSelData>                   dummy09;
  }
}

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"edm::Wrapper<mitedm::EvtSelData>", payloadCode, "@",
"mitedm::EvtSelData", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("UATreeMitEdm_xr",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_UATreeMitEdm_xr_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_UATreeMitEdm_xr_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_UATreeMitEdm_xr() {
  TriggerDictionaryInitialization_UATreeMitEdm_xr_Impl();
}
