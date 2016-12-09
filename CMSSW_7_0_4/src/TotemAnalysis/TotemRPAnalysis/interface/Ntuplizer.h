/****************************************************************************
*
* This is a part of TOTEM offline software.
* Authors: 
*  Jan Kaspar (jan.kaspar@gmail.com) 
*
****************************************************************************/

#ifndef TotemAnalysis_TotemAnalysisEvent_Ntuplizer
#define TotemAnalysis_TotemAnalysisEvent_Ntuplizer

namespace edm {
  class ParameterSet;
  class EventSetup;
  class Event;
}

class TTree;

/**
 * A template for ntuple-making classes
 **/
class Ntuplizer
{
 public:
  /// constructor
  Ntuplizer();
  Ntuplizer(const edm::ParameterSet&);

  /// book your branches here
  virtual void CreateBranches(const edm::EventSetup&, TTree *) = 0;

  /// fill the event data here
  virtual void FillEvent(const edm::Event&, const edm::EventSetup&) = 0;
};

#endif
