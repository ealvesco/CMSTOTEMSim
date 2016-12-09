BASE=$(CMSTOTEM_BASE)/CMSdataFormat
SRC=$(BASE)/UATree/UADataFormat/src
INC=$(BASE)/UATree/UADataFormat/interface
OBJ=$(BASE)/lib
UATREEPATH=UATree/UADataFormat/interface

#CXX=/cvmfs/cms.cern.ch/slc6_amd64_gcc491/external/gcc/4.9.1-cms/bin/c++
CXXFLAGS+=$(shell root-config --cflags) -Wall -I$(BASE) -ggdb3 -fPIC
LDFLAGS+=$(shell root-config --glibs) -lGenVector -ggdb3 

#HEAD=$(wildcard $(INC)/My*.h)
#HEAD = $(UATREEPATH)/MassParticles.h $(UATREEPATH)/MyFSCInfo.h
HEAD=$(UATREEPATH)/MyBeamSpot.h \
   $(UATREEPATH)/MyCastorDigi.h \
   $(UATREEPATH)/MyCastorJet.h \
   $(UATREEPATH)/MyCastorRecHit.h \
   $(UATREEPATH)/MyDiJet.h \
   $(UATREEPATH)/MyEvtId.h \
   $(UATREEPATH)/MyFwdGap.h \
   $(UATREEPATH)/MyMet.h \
   $(UATREEPATH)/MyGenMet.h \
   $(UATREEPATH)/MyGenKin.h \
   $(UATREEPATH)/MyGenPart.h \
   $(UATREEPATH)/MyGenJet.h \
   $(UATREEPATH)/MyPUSumInfo.h \
   $(UATREEPATH)/MyHLTrig.h \
   $(UATREEPATH)/MyL1Trig.h \
   $(UATREEPATH)/MyL1TrigOld.h \
   $(UATREEPATH)/MyMITEvtSel.h \
   $(UATREEPATH)/MyPart.h \
   $(UATREEPATH)/MySimVertex.h \
   $(UATREEPATH)/MyVertex.h \
   $(UATREEPATH)/MyTracks.h \
   $(UATREEPATH)/MyElectron.h \
   $(UATREEPATH)/MyMuon.h \
   $(UATREEPATH)/MyBaseJet.h \
   $(UATREEPATH)/MyJet.h \
   $(UATREEPATH)/MyCaloJet.h \
   $(UATREEPATH)/MyTrackJet.h \
   $(UATREEPATH)/MyPFJet.h \
   $(UATREEPATH)/MyPFCand.h \
   $(UATREEPATH)/MyCaloTower.h \
   $(UATREEPATH)/MyFSCHit.h \
   $(UATREEPATH)/MyFSCDigi.h \
   $(UATREEPATH)/MyFSCInfo.h \
   $(UATREEPATH)/MyKshorts.h \
   $(UATREEPATH)/MyLambdas.h
HEADINC=$(subst $(UATREEPATH),$(INC),$(HEAD))
OBJS1=$(HEAD:.h=.o)
OBJS=$(subst $(UATREEPATH),$(OBJ),$(OBJS1))

LINKD=LinkDef

all: $(OBJ) $(OBJ)/libCMSdataFormat.so

$(OBJ)/libCMSdataFormat.so: $(OBJS) $(OBJ)/eventdict.o 
	$(CXX) $(LDFLAGS) -shared -o $@ $^	
	@echo ""
	#to load the library to CINT one needs X connection
	@echo ""

$(OBJ)/%.o: $(SRC)/%.cc
	$(CXX) $(CXXFLAGS) -I$(BASE) -c $< -o $@
	@echo ""

$(SRC)/eventdict.cc: $(HEADINC) $(INC)/$(LINKD).h
	rootcint -f $@ -c -p -I$(BASE) $(HEAD) $(UATREEPATH)/$(LINKD).h
	cp $(SRC)/eventdict_rdict.pcm $(OBJ)/
	@echo ""

$(INC)/$(LINKD).h:
	#compatibility with cmssw
	if [ ! -f $(INC)/$(LINKD).h ]; then mv $(INC)/$(LINKD)h $(INC)/$(LINKD).h; fi;
	@echo ""

$(OBJ):
	mkdir -p $(OBJ)

clean:
	rm -rf $(OBJ)
	rm $(SRC)/eventdict.cc
	rm $(SRC)/eventdict_rdict.pcm

