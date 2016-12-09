TotemBase=$(CMSTOTEM_BASE)/TOTEMdataFormat
TotemSrc=$(TotemBase)/src
CMSBase=$(CMSTOTEM_BASE)/CMSdataFormat
CMSSrc=$(CMSBase)/src
TotemLibrary=$(TotemBase)/lib/libTOTEMdataFormat.so
CMSLibrary=$(CMSBase)/lib/libCMSdataFormat.so

CXXFLAGS+=$(shell root-config --cflags) -Wall -I. -I$(TotemSrc) -I$(CMSBase)
LDFLAGS+=$(shell root-config --libs) -lTreePlayer 

all: ../TOTEMdataFormat/utilities/Makefile ../CMSdataFormat/utilities/Makefile
	cd ../TOTEMdataFormat/utilities/; make
	cd ../CMSdataFormat/utilities/; make
	cp $(CMSBase)/lib/eventdict_rdict.pcm ./
	cp $(TotemBase)/lib/eventdictT_rdict.pcm ./
	make all2

#all2: merge12 combine mergeNtuples findOrbitOffset
all2: mergeNtuples findOrbitOffset mergeCMSFiles mergeTOTEMFiles writeTOTEMEventInfo calculateEfficiency mergeNtuplesNew calculateEfficiencyNew

merge12: utilities.h $(CMSLibrary) $(TotemLibrary)

combine: utilities.h $(CMSLibrary) $(TotemLibrary)

mergeNtuples: $(CMSLibrary) $(TotemLibrary)

findOrbitOffset: $(CMSLibrary) $(TotemLibrary)

mergeCMSFiles: $(CMSLibrary)

mergeTOTEMFiles: $(TotemLibrary)

writeTOTEMEventInfo: $(TotemLibrary)

calculateEfficiency: $(CMSLibrary) $(TotemLibrary)

mergeNtuplesNew: $(CMSLibrary) $(TotemLibrary)

calculateEfficiencyNew: $(CMSLibrary) $(TotemLibrary)

clean:
	cd ../TOTEMdataFormat/utilities/; make clean
	cd ../CMSdataFormat/utilities/; make clean
	rm -f merge12 combine mergeNtuples findOrbitOffset mergeCMSFiles mergeTOTEMFiles writeTOTEMEventInfo calculateEfficiency mergeNtuplesNew calculateEfficiencyNew *.o

