ALL_TOOLS      += llvm
llvm_EX_INCLUDE := /afs/cern.ch/cms/slc6_amd64_gcc481/external/llvm/3.3-cms3/include
llvm_EX_LIB := clang
llvm_EX_FLAGS_LDFLAGS  := -Wl,-undefined -Wl,suppress
llvm_EX_FLAGS_CXXFLAGS  := -D_DEBUG -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS -O3 -fomit-frame-pointer -fPIC -Wno-enum-compare -Wno-strict-aliasing -fno-rtti

