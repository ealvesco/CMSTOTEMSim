TotemBase=$(CMSTOTEM_BASE)/TOTEMdataFormat
TotemSrc=$(TotemBase)/src
CMSBase=$(CMSTOTEM_BASE)/CMSdataFormat
CMSSrc=$(CMSBase)/src
TotemLibrary=$(TotemBase)/lib/libTOTEMdataFormat.so
CMSLibrary=$(CMSBase)/lib/libCMSdataFormat.so

CXXFLAGS+=$(shell root-config --cflags) -Wall -I. -I$(TotemSrc) -I$(CMSBase)
LDFLAGS+=$(shell root-config --libs) -lTreePlayer 

all: analysis-readTOTEM analysis-readCMS analysis-readTOTEM_MC

analysis-readTOTEM: $(TotemLibrary)

analysis-readCMS: $(CMSLibrary)

analysis-readTOTEM_MC: $(CMSLibrary) $(TotemLibrary)

clean:
	rm -f analysis-readTOTEM analysis-readCMS analysis-readTOTEM_MC

