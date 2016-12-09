/****************************************************************************
*
* This is a part of TotemDQM and TOTEM offline software.
* Authors:
*   Jan Kašpar (jan.kaspar@gmail.com)
*
****************************************************************************/

#ifndef _TotemRPGeometryLite_h_
#define _TotemRPGeometryLite_h_

#include "FWCore/Common/interface/EventBase.h"

#include "CLHEP/Vector/ThreeVector.h"

#include <map>

/**
 * \brief Provides TotemRPGeometry in the FWLite framework.
 * At the moment, it contains hardcoded RP_Garage geometry that is used most ofen
 * with DQM. However, the class foresees a method to load the data from event.
 **/
class TotemRPGeometryLite
{
  private:
    struct SensorGeomInfo
    {
        double x, y, z;   // in mm
        double dx, dy;    // read-out direction
    };

    struct RPGeomInfo
    {
      unsigned int n_U, n_V;  // number of U and V planes
      double x, y, z;         // in mm
      double dx_U, dy_U;      // mean read-out U direction
      double dx_V, dy_V;      // mean read-out V direction
    };

    /// mapping: sensor decimal ID --> geometry info
    std::map<unsigned int, SensorGeomInfo> sensorData;

    /// mapping: RP decimal ID --> geometry info
    std::map<unsigned int, RPGeomInfo> rpData;

    void BuildMeanRPData();

  public: 
    TotemRPGeometryLite();

    /// Interface method that keeps possibility to load geometry information from event data.
    void Update(const edm::EventBase &ev);

    /// returns position of the sensor center
    /// output in mm
    CLHEP::Hep3Vector GetSensorPosition(unsigned int id) const;

    /// returns read-out direction of the sensor
    CLHEP::Hep3Vector GetSensorReadoutDirection(unsigned int id) const;

    /// returns position of the RP centre
    /// output in mm
    CLHEP::Hep3Vector GetRPPosition(unsigned int id) const;
    
    /// returns avarage read-out direction of the U sensors in the RP
    CLHEP::Hep3Vector GetRPMeanUDirection(unsigned int id) const;
    
    /// returns avarage read-out direction of the V sensors in the RP
    CLHEP::Hep3Vector GetRPMeanVDirection(unsigned int id) const;
};

#endif
