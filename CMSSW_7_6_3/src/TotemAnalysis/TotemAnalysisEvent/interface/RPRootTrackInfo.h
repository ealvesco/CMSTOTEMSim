#ifndef _TotemAnalysis_TotemAnalysisEvent_RPRootTrackInfo_h_
#define _TotemAnalysis_TotemAnalysisEvent_RPRootTrackInfo_h_

#include "TNamed.h"
#include <vector>

struct RPRootDumpTrackInfo
{
  bool valid;                       ///< whether track fit is valid
  double x, y, z;                   ///< track fit interpolated to the middle of the RP
  double thx, thy;                  ///< track tilt
  double chi2;                      ///< fit chi square
  double chi2ndf;                   ///< fit chi square divided by the number of degrees of freedom
  unsigned int entries;             ///< the number of contributing hits
  double res_x, res_y;              ///< seem not used
  std::vector<int> u_sect, v_sect;  ///< list of active trigger sectors calculated from (strip) data
  int u_sect_no, v_sect_no;         ///< sizes of u_sect and v_sect vectors
  unsigned int u_id, v_id;          ///<if there are multiple tracks the uv combination id is preserved here
  
  RPRootDumpTrackInfo()
  {
    valid = false;
    chi2=chi2ndf=x=y=z=res_x=res_y=0.0;
    entries = 0;
    u_sect = std::vector<int>();
    v_sect = std::vector<int>();
    u_sect_no = v_sect_no = 0;
    u_id = v_id = 0;
  }

  virtual ~RPRootDumpTrackInfo() {}
  
  //ClassDef(RPRootDumpTrackInfo,1)
};

struct RPRootDumpDigiInfo
{
  std::vector<int> numberOfClusters;  ///< number of clusters in a given plane (indexed from 0 to 9)
  unsigned int numberOfPlanesOn;      ///< number of planes with at least one cluster
  unsigned int uPlanesOn;             ///< number of U planes with at least one cluster
  unsigned int vPlanesOn;             ///< number of V planes with at least one cluster
  std::vector<int> planeId;           ///< plane ID for a given cluster (array index)
  std::vector<int> clusterSize;       ///< cluster size of a given cluster
  std::vector<int> centralStrip;      ///< central strip of a given cluster

  RPRootDumpDigiInfo()
  {
    numberOfPlanesOn = uPlanesOn = vPlanesOn = 0;
    numberOfClusters = std::vector<int>();
    numberOfClusters.reserve(10);
    numberOfClusters.assign(10,0);
    planeId = std::vector<int>();
    clusterSize = std::vector<int>();
    centralStrip = std::vector<int>();
  }

  virtual ~RPRootDumpDigiInfo() {}
  
  //ClassDef(RPRootDumpDigiInfo,1)
};

struct RPRootDumpReconstructedProton
{
  bool valid;
  double thx, thy, phi, t, tx, ty, xi, x0, y0, chi2, chindf;
  
  RPRootDumpReconstructedProton()
  {
    valid = false;
    thx = thy = phi = t = tx = ty = x0 = y0 = chi2 = chindf = 0.0;
    xi = 1;
  } 
  
  virtual ~RPRootDumpReconstructedProton(){

  }

  //ClassDef(RPRootDumpReconstructedProton,1)
};


struct RPRootDumpReconstructedProtonPair
{
  bool valid;
  double thxr, thyr, xir, phir;
  double thxl, thyl, xil, phil;
  double x0, y0, z0, chi2, chindf;
  double tr, txr, tyr;
  double tl, txl, tyl;
  double t;
  
  RPRootDumpReconstructedProtonPair()
  {
    valid = false;
    thxr = thyr = phir = phil = 0.0;
    thxl = thyl = 0.0;
    x0 = y0 = z0 = chi2 = chindf = 0.0;
    tr = txr = tyr = 0.0;
    tl = txl = tyl = 0.0;
    t = 0.0;
    xir = xil = 1.0; 
  } 
  
  virtual ~ RPRootDumpReconstructedProtonPair(){

  }

  //ClassDef(RPRootDumpReconstructedProtonPair,1)
};

/**
 * \brief Describes a recognized linear pattern.
 **/
struct RPRootDumpPattern
{
  double a; ///< slope in rad
  double b; ///< intercept (at the middle of the RP) in mm
  double w; ///< weight

  RPRootDumpPattern(double _a=0., double _b=0., double _w=0.) : a(_a), b(_b), w(_w) {}
  virtual ~RPRootDumpPattern() {}
  
  //ClassDef(RPRootDumpPattern,1)
};


/**
 * \brief Describes a pattern-recognition result.
 **/
struct RPRootDumpPatternInfo
{
  std::vector<RPRootDumpPattern> u, v;  ///< arrays of recognized patterns in u and v projections
  bool fittable;                        ///< whether there is one (and only one) combined u-v pattern worth fitting
  unsigned int u_no, v_no;              ///< number of candidates per projection

  RPRootDumpPatternInfo(bool _f = false) : fittable(_f) {}
  virtual ~RPRootDumpPatternInfo() {}
  void Reset() {
    u.clear();
    v.clear();
    fittable = false;
    u_no = v_no = 0;
  }
  
  //ClassDef(RPRootDumpPatternInfo,1)
};


#endif
