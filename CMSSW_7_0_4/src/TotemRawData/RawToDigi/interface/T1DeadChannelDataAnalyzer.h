/*
 * T1DeadChannelDataAnalyzer.h
 *
 *  Created on: Sep 2, 2011
 *      Author: Marcin Borratynski (mborratynski@gmail.com)
 */

#ifndef T1DEADCHANNELDATAANALYZER_H_
#define T1DEADCHANNELDATAANALYZER_H_

#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "DataFormats/Common/interface/DetSetVector.h"

#include "TotemCondFormats/DAQInformation/interface/AnalysisMask.h"
#include "TotemCondFormats/DAQInformation/interface/DAQMapping.h"
#include "TotemRawDataLibrary/DataFormats/interface/VFATFrameCollection.h"
#include "DataFormats/T1DetId/interface/T1DetId.h"
#include "TotemRawData/RawToDigi/interface/T1FisChannel.h"
#include "DataFormats/T1DigiVfat/interface/T1DigiVfat.h"
#include "DataFormats/T1DigiVfat/interface/T1DigiVfatCollection.h"
#include "DataFormats/T1DigiWire/interface/T1DigiWire.h"
#include "DataFormats/T1DigiWire/interface/T1DigiWireCollection.h"

#include "TotemRawDataLibrary/DataFormats/interface/VFATFrame.h"
#include "TotemRawDataLibrary/DataFormats/interface/RawEvent.h"

#include "TotemRawDataLibrary/DataFormats/interface/CommonDef.h"
#include "TotemCondFormats/DAQInformation/interface/DAQInformationT1.h"
#include "TotemCondFormats/DataRecord/interface/TotemDAQMappingRecord.h"
#include "SimTotem/T1Digitizer/interface/T1DeadChannelManager.h"
#include "TotemRawData/RawToDigi/interface/T1Cfecs.h"

#include <math.h>

namespace edm {
class ParameterSet;
class EventSetup;
class Event;
class EventID;
}

namespace Totem {
	class FramePosition;
}


class T1DeadChannelDataAnalyzer : public edm::EDAnalyzer
{
public:

	T1DeadChannelDataAnalyzer(const edm::ParameterSet& conf);
	virtual  ~T1DeadChannelDataAnalyzer();
	 virtual void beginRun(edm::Run const&, edm::EventSetup const&);


//	virtual void beginJob();
	virtual void endJob();
	virtual void analyze(const edm::Event&, const edm::EventSetup&);
  // T1 DATA
  void t1DataBeginJob(const edm::EventSetup &es);
  void t1DataEndJob(edm::Event& e);
  void t1DataProduce(const edm::Event& e, VFATFrameCollection::Iterator &iter, const VFATInfo &info);

private:
	edm::InputTag rawEventLabel;
	unsigned char verbosity;
	unsigned char deadCutValue;
	unsigned char noiseCutValue;
	std::string outputFile;
	ofstream* myFile;
	bool OnlyStrips;

	bool eventError, positionError;   ///< whether error found in event/position
	map<int,T1FisChannel> T1Map;
	map<long long,long long> channelsHitNumber;



 
  T1DeadChannelManager _T1deadChannelManager;

 
	void PrintErrorHeader(const edm::EventID&, const Totem::FramePosition&, unsigned short, unsigned short);
};

#endif /* T1DEADCHANNELDATAANALYZER_H_ */
