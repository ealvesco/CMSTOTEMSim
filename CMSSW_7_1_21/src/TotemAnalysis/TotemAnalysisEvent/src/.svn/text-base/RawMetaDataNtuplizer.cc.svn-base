/****************************************************************************
*
* This is a part of TOTEM offline software.
* Authors: 
*  Jan Kašpar (jan.kaspar@gmail.com) 
*
****************************************************************************/

#include "TotemAnalysis/TotemNtuplizer/interface/RawMetaDataNtuplizer.h"
#include "TotemRawDataLibrary/DataFormats/interface/RawEvent.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/ESHandle.h"

#include "TTree.h"

#include <map>

using namespace std;
using namespace edm;
using namespace Totem;

// TODO: needed?
ClassImp(EventMetaData)

//----------------------------------------------------------------------------------------------------

RawMetaDataNtuplizer::RawMetaDataNtuplizer(const edm::ParameterSet &ps) : Ntuplizer(ps),
  rawEventLabel(ps.getParameter< edm::InputTag >("RawEventLabel"))
{
}

//----------------------------------------------------------------------------------------------------

void RawMetaDataNtuplizer::CreateBranches(const edm::EventSetup&, TTree *tree)
{
  tree->Branch("event_info.", &data);
}

//----------------------------------------------------------------------------------------------------

void RawMetaDataNtuplizer::FillEvent(const edm::Event &event, const edm::EventSetup &es)
{
  data.run_no = event.id().run();
  data.event_no = event.id().event();
  data.timestamp = event.time().unixTime();

  Handle< RawEvent > input;
  event.getByLabel(rawEventLabel, input);

  data.daq_event_number = input->dataEventNumber;

  data.optoRx_Id.clear();
  data.optoRx_BX.clear();
  data.optoRx_LV1.clear();
  for (auto p : input->optoRxMetaData)
  {
    data.optoRx_Id.push_back(p.first);
    data.optoRx_BX.push_back(p.second.BX);
    data.optoRx_LV1.push_back(p.second.LV1);
  }
}
