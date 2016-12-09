/****************************************************************************
*
* This is a part of TotemDQMLite and TOTEM offline software.
* Authors:
*   Jan Kašpar (jan.kaspar@gmail.com)
*
****************************************************************************/


#ifndef _DQMModule_h_
#define _DQMModule_h_

#include "FWCore/Common/interface/EventBase.h"

namespace edm {
  class ParameterSet;
}

/// whether processing is in cumulative mode
extern bool dqmCumulativeMode;

/**
 *\ingroup TotemDQMLite
 *\brief Based class for all the DQM Modules (Plugins)
 **/
class DQMModule
{
  public:
    DQMModule(const edm::ParameterSet&);

    virtual ~DQMModule();

    /// Method called before cumulative processing.
    virtual void beginJob() = 0;

    /// Method called after cumulative processing.
    virtual void endJob() = 0;

    /// Method called for each event.
    virtual void analyze(const edm::EventBase &) = 0;

    /// returns true if data are processed in cumulative mode, false if in single-event mode
    bool CumulativeMode();
};


#endif
