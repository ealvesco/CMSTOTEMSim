/****************************************************************************
*
* This is a part of TOTEM offline software.
* Authors:
*   Jan Kašpar (jan.kaspar@gmail.com)
*
****************************************************************************/

#ifndef T2XMLDataDigiProducer_h
#define T2XMLDataDigiProducer_h

#include "FWCore/Framework/interface/EDProducer.h"
#include "DataFormats/T2DetId/interface/T2DetId.h"
#include "TotemRawData/RawToDigi/interface/T2Mapping.h"
#include "DataFormats/T2Digi/interface/T2StripDigi.h"
#include "DataFormats/T2Digi/interface/T2StripDigiCollection.h"
#include "DataFormats/T2Digi/interface/T2PadDigi.h"
#include "DataFormats/T2Digi/interface/T2PadDigiCollection.h"
#include "DataFormats/T2DigiVfat/interface/T2DigiVfat.h"
#include "DataFormats/T2DigiVfat/interface/T2DigiVfatCollection.h"
#include "DataFormats/T2DigiVfat/interface/T2VfatInformation.h"
#include "Geometry/TotemGeometry/interface/T2GeometryUtil.h"

namespace edm {
  class ParameterSet;
  class EventSetup;
  class Event;
  class EventID;
}

namespace Totem {
  class FramePosition;
}


/**
 * \brief Converts raw event data to RP digi information.
**/
class T2XMLDataDigiProducer : public edm::EDProducer
{
  public:

    T2XMLDataDigiProducer(const edm::ParameterSet& conf);
    virtual  ~T2XMLDataDigiProducer();

    virtual void beginJob(const edm::EventSetup&);
    virtual void endJob();
    virtual void produce(edm::Event&, const edm::EventSetup&);
    /*
      std::auto_ptr<TH1F> Padconvertedindex;
      std::auto_ptr<TH1F> PadCOLindex;
      std::auto_ptr<TH1F> PadROWindex;
      std::auto_ptr<TH1F> HistActiveChannel;
    */
  private:
    unsigned char verbosity;
    bool discardHighOccupancyVfat;
    T2Mapping VFATconvertDigichannell;
	
    bool eventError, positionError;   ///< whether error found in event/position

    ///< prints error header
    void PrintErrorHeader(const edm::EventID&, const Totem::FramePosition&, unsigned short, unsigned short);
};

#endif

