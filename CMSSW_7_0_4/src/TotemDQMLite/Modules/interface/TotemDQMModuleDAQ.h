/****************************************************************************
*
* This is a part of TotemDQMLite and TOTEM offline software.
* Authors:
*   Jan Kašpar (jan.kaspar@gmail.com)
*   Rafał Leszko (rafal.leszko@gmail.com)
*
****************************************************************************/

#ifndef _TotemDQMLite_TotemDQMModuleDAQ_h_
#define _TotemDQMLite_TotemDQMModuleDAQ_h_


#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Common/interface/EventBase.h"

#include "TotemDQMLite/Core/interface/DQMModule.h"

class TPaveText;
class TH1D;
class TProfile;

/**
 * \ingroup TotemDQM
 * \brief A TotemDQM module producing plots related to DAQ.
 **/
class TotemDQMModuleDAQ : public DQMModule
{
  protected:
    edm::InputTag tagRawEvent;

    TPaveText *text;

    TH1D *h_dataEventNumber, *h_dataConfNumber, *h_timestamp;
    TH1D *h_optoRxMetaData_ID, *h_optoRxMetaData_BX, *h_optoRxMetaData_LV1;

    TH1D *h_trigger_type, *h_trigger_event_num, *h_trigger_bunch_num, *h_trigger_src_id;
    TH1D *h_trigger_orbit_num, *h_trigger_revision_num, *h_trigger_run_num;
    TH1D *h_trigger_trigger_num, *h_trigger_inhibited_triggers_num, *h_trigger_input_status_bits;

    TProfile *p_trigger_event_num, *p_trigger_orbit_num, *p_trigger_trigger_num;

  public:
    TotemDQMModuleDAQ(const edm::ParameterSet&);
    ~TotemDQMModuleDAQ();

    virtual void beginJob();
    virtual void analyze(const edm::EventBase &);
    virtual void endJob() {};
};

#endif
