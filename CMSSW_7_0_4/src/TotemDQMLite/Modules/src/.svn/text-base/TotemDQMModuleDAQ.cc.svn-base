/****************************************************************************
*
* This is a part of TotemDQMLite and TOTEM offline software.
* Authors:
*   Jan Kašpar (jan.kaspar@gmail.com)
*   Rafał Leszko (rafal.leszko@gmail.com)
*
****************************************************************************/

#include "DataFormats/Common/interface/Handle.h"

#include "TotemDQMLite/Modules/interface/TotemDQMModuleDAQ.h"
#include "TotemDQMLite/Core/interface/PlotManager.h"

#include "TotemRawDataLibrary/DataFormats/interface/RawEvent.h"

#include "TotemDQMLite/Core/interface/PaveTextPlot.h"

#include "TPaveText.h"
#include "TH1D.h"
#include "TProfile.h"

#include <ctime>

using namespace edm;
using namespace Totem;

//----------------------------------------------------------------------------------------------------

TotemDQMModuleDAQ::TotemDQMModuleDAQ(const edm::ParameterSet &ps) : DQMModule(ps),
  tagRawEvent(ps.getParameter<edm::InputTag>("tagRawEvent")),
  text(new TPaveText(0.01, 0.01, 0.99, .99, "NDC"))
{
  // DAQ part
  text->SetOption("b");
  text->SetBorderSize(1);
  text->SetTextSize(0.05);
  text->SetTextAlign(11);
  text->SetTextColor(2);

  PaveTextPlot *p = new PaveTextPlot("event metadata", text, false);
  PlotManager::Register("DAQ/event metadata - actual event", "event metadata", p);
  
  h_dataEventNumber = new TH1D("", "", 100, 0, 0);
  h_dataEventNumber->SetBuffer(100000);
  PlotManager::Register("DAQ/dataEventNumber histogram", "dataEventNumber", h_dataEventNumber);
  
  h_dataConfNumber = new TH1D("", "", 100, 0, 0);
  h_dataConfNumber->SetBuffer(100000);
  PlotManager::Register("DAQ/dataConfNumber histogram", "dataConfNumber", h_dataConfNumber);

  h_timestamp = new TH1D("", "", 100, 0, 0);
  h_timestamp->SetBuffer(100000);
  h_timestamp->GetXaxis()->SetTimeDisplay(1);
  h_timestamp->GetXaxis()->SetTimeFormat("%H:%M%F1970-01-01 00:00:00"); // for date add "%b %d"
  PlotManager::Register("DAQ/timestamp histogram", "timestamp", h_timestamp);

  PlotManager::Register("DAQ/OptoRxID histogram", "OptoRx ID", h_optoRxMetaData_ID = new TH1D("", "", 100, 0, 0));
  PlotManager::Register("DAQ/OptoRxBX histogram", "OptoRx BX", h_optoRxMetaData_BX = new TH1D("", "", 100, 0, 0));
  PlotManager::Register("DAQ/OptoRxLV1 histogram", "OptoRx LV1", h_optoRxMetaData_LV1 = new TH1D("", "", 100, 0, 0));

  // trigger part -- histograms
  PlotManager::Register("Trigger/type histogram", "type", h_trigger_type = new TH1D("", "", 100, 0, 0));
  PlotManager::Register("Trigger/event_num histogram", "event_num", h_trigger_event_num = new TH1D("", "", 100, 0, 0));
  h_trigger_event_num->SetBuffer(100000);
  PlotManager::Register("Trigger/bunch_num histogram", "bunch_num", h_trigger_bunch_num = new TH1D("", "", 100, 0, 0));
  PlotManager::Register("Trigger/src_id histogram", "src_id", h_trigger_src_id = new TH1D("", "", 100, 0, 0));
  PlotManager::Register("Trigger/orbit_num histogram", "orbit_num", h_trigger_orbit_num = new TH1D("", "", 100, 0, 0));
  h_trigger_orbit_num->SetBuffer(100000);
  PlotManager::Register("Trigger/revision_num histogram", "revision_num", h_trigger_revision_num = new TH1D("", "", 100, 0, 0));
  PlotManager::Register("Trigger/run_num histogram", "run_num", h_trigger_run_num = new TH1D("", "", 100, 0, 0));
  PlotManager::Register("Trigger/trigger_num histogram", "trigger_num", h_trigger_trigger_num = new TH1D("", "", 100, 0, 0));
  h_trigger_trigger_num->SetBuffer(100000);
  PlotManager::Register("Trigger/inhibited_triggers_num histogram", "inhibited_triggers_num", h_trigger_inhibited_triggers_num = new TH1D("", "", 100, 0, 0));
  PlotManager::Register("Trigger/input_status_bits histogram", "input_status_bits", h_trigger_input_status_bits = new TH1D("", "", 100, 0, 0));

  // trigger part -- time profiles
  PlotManager::Register("Trigger/event_num time profile", "event_num time profile", p_trigger_event_num = new TProfile("", "", 100, 0., 0.));
  p_trigger_event_num->SetBuffer(100000);
  p_trigger_event_num->GetXaxis()->SetTimeDisplay(1);
  p_trigger_event_num->GetXaxis()->SetTimeFormat("%H:%M%F1970-01-01 00:00:00");

  PlotManager::Register("Trigger/orbit_num time profile", "orbit_num time profile", p_trigger_orbit_num = new TProfile("", "", 100, 0., 0.));
  p_trigger_orbit_num->SetBuffer(100000);
  p_trigger_orbit_num->GetXaxis()->SetTimeDisplay(1);
  p_trigger_orbit_num->GetXaxis()->SetTimeFormat("%H:%M%F1970-01-01 00:00:00");

  PlotManager::Register("Trigger/trigger_num time profile", "trigger_num time profile", p_trigger_trigger_num = new TProfile("", "", 100, 0., 0.));
  p_trigger_trigger_num->SetBuffer(100000);
  p_trigger_trigger_num->GetXaxis()->SetTimeDisplay(1);
  p_trigger_trigger_num->GetXaxis()->SetTimeFormat("%H:%M%F1970-01-01 00:00:00");
}
//----------------------------------------------------------------------------------------------------

void TotemDQMModuleDAQ::beginJob()
{
}

//----------------------------------------------------------------------------------------------------

TotemDQMModuleDAQ::~TotemDQMModuleDAQ()
{
  delete text;
}

//----------------------------------------------------------------------------------------------------

void TotemDQMModuleDAQ::analyze(const edm::EventBase &event)
{
  Handle< RawEvent > re;
  event.getByLabel(tagRawEvent, re);

  // input valid?
  if (!re.isValid())
  {
    printf("ERROR in TotemDQMModuleDAQ::analyze > input handles not valid (%i). Skipping this event.\n",
      re.isValid());
    return;
  }

  if (CumulativeMode())
  {
    h_dataEventNumber->Fill(re->dataEventNumber);
    h_dataConfNumber->Fill(re->dataConfNumber);
    h_timestamp->Fill(re->timestamp);

    for (auto p : re->optoRxMetaData)
    {
      h_optoRxMetaData_ID->Fill(p.first);
      h_optoRxMetaData_BX->Fill(p.second.BX);
      h_optoRxMetaData_LV1->Fill(p.second.LV1);
    }

    h_trigger_type->Fill(re->triggerData.type);
    h_trigger_event_num->Fill(re->triggerData.event_num);
    h_trigger_bunch_num->Fill(re->triggerData.bunch_num);
    h_trigger_src_id->Fill(re->triggerData.src_id);
    h_trigger_orbit_num->Fill(re->triggerData.orbit_num);
    h_trigger_revision_num->Fill(re->triggerData.revision_num);
    h_trigger_run_num->Fill(re->triggerData.run_num);
    h_trigger_trigger_num->Fill(re->triggerData.trigger_num);
    h_trigger_inhibited_triggers_num->Fill(re->triggerData.inhibited_triggers_num);
    h_trigger_input_status_bits->Fill(re->triggerData.input_status_bits);

    p_trigger_event_num->Fill(re->timestamp, re->triggerData.event_num);
    p_trigger_orbit_num->Fill(re->timestamp, re->triggerData.orbit_num);
    p_trigger_trigger_num->Fill(re->timestamp, re->triggerData.trigger_num);
  } else {
    text->Clear();
    char buf[100];
    sprintf(buf, "data event number = %lu", re->dataEventNumber); text->AddText(buf);
    sprintf(buf, "timestamp = %s", ctime(& re->timestamp)); text->AddText(buf);

	// optoRx meta data
	text->AddText("OptoRx:");
	for (auto p : re->optoRxMetaData)
	{
		sprintf(buf, "    ID = 0x04%x, BX = %u, LV1 = %u", p.first, p.second.BX, p.second.LV1);
		text->AddText(buf);
	}

	// trigger data
	text->AddText("trigger:");
    sprintf(buf, "    type = %u", re->triggerData.type); text->AddText(buf);
    sprintf(buf, "    event_num = %u", re->triggerData.event_num); text->AddText(buf);
    sprintf(buf, "    bunch_num = %u", re->triggerData.bunch_num); text->AddText(buf);
    sprintf(buf, "    src_id = %u", re->triggerData.src_id); text->AddText(buf);
    sprintf(buf, "    orbit_num = %u", re->triggerData.orbit_num); text->AddText(buf);
    sprintf(buf, "    revision_num = %u", re->triggerData.revision_num); text->AddText(buf);
    sprintf(buf, "    run_num = %u", re->triggerData.run_num); text->AddText(buf);
    sprintf(buf, "    trigger_num = %u", re->triggerData.trigger_num); text->AddText(buf);
    sprintf(buf, "    inhibited_triggers_num = %u", re->triggerData.inhibited_triggers_num); text->AddText(buf);
    sprintf(buf, "    input_status_bits = %u", re->triggerData.input_status_bits); text->AddText(buf);

  }
}
