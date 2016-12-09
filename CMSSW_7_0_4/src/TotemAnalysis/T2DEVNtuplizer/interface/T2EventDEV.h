#ifndef ROOTCLASST2EventDEV
#define ROOTCLASST2EventDEV
#include "TObject.h"
#include <vector>
class T2EventDEV : public TObject
{
 public:
  T2EventDEV();
 ~T2EventDEV();
 // double get_var1();
 //int get_var2();
 //void set_var1(double var1);
 //void set_var2(int var2);
 
  std::vector<int> TrkSecondaryRecoIndex;
  std::vector<int> TrkSecondaryPDG;
  std::vector<int> TrkSecondaryMotherPDG;
 std::vector<int> Pad_row;             //strip row   
 std::vector<int> Pad_col;             //strip column   
 std::vector<int> Pad_det;             //symbolic id of the detector containind the pad
 
 std::vector<int> Strip_row;           //strip row
 std::vector<int> Strip_col;           //strip column
 std::vector<int> Strip_det;           //symbolic id of the detector containind the strip

 std::vector<double> TrkEta_XY; 
 std::vector<double> TrkEta2; 

 std::vector<double> TrkZmin_XY;  
 std::vector<double> TrkRmin_XY;  

 std::vector<double> TrkAx;            // slope of the track projection in the XZ plane
 std::vector<double> TrkAy;            // slope of the track projection in the YZ plane
 std::vector<double> TrkX0;            // X at Z=0 for the XZ projected track  
 std::vector<double> TrkY0;            // Y at Z=0 for the XZ projected track
 std::vector<double> TrkPhi;           // Trk Phi (XY fit)

 std::vector<double> TrkChi2XProb;          //Chi2-X probability (goodness of the XZ projection fit)
 std::vector<double> TrkChi2YProb;          //Chi2-Y probability (goodness of the YZ projection fit)
 std::vector<double> TrkClass1HitCounter;   //Number of class1 Hit in the Trk
 std::vector<double> TrkHitCounter;         //Number of class1 + cluster Pad hits in the Trk

 
 std::vector<double> TrkThetaR_RZFit;// Trk Polar angle obtained tracking in the Rz plane
 std::vector<double> TrkEta_RZFit;   // Trk Eta obtained tracking in the Rz plane 
 std::vector<double> TrkPhi_RZFit;   // Trk Phi obtained with a constant fit.
 std::vector<double> TrkZ0_RZFit;    // Crossing Point between Trk and Z Axis obtained tracking in the Rz plane 
 std::vector<double> TrkBX_RZFit;    // X0 @ Z=0 obtained tracking in the Rz plane 
 std::vector<double> TrkBY_RZFit;    // X0 @ Z=0 obtained tracking in the Rz plane 

 std::vector<int> TrkNumHitInH0;  
 std::vector<int> TrkNumHitInH1;  
 std::vector<int> TrkNumHitInH2;  
 std::vector<int> TrkNumHitInH3;  
 std::vector<unsigned int> TrkNature; 
 std::vector<int> Trk_NumHitPrimary;

 std::vector<double> PrimGeantTrkPT;
 std::vector<double> PrimaryGeantTrkEta; 
 std::vector<double> PrimaryGeantTrkQuarter; 
 std::vector<int> PrimaryGeantTrkBarcode;

 std::vector<double> TrkPrimaryGeneratorEta; 
 std::vector<double> TrkPrimaryGeantEta;
 std::vector<double> TrkPrimaryEnergy; 
 std::vector<double> TrkPrimaryPt;
 std::vector<int> TrkPrimaryBarcode; 

 std::vector<double> TrkChiProb;             //Make sense only with T2TrackProducer3
 std::vector<unsigned int> Trknumpadonly;   
 std::vector<unsigned int> Trknumstriponly;   
 std::vector<unsigned int> Trknumhitall;   
 std::vector<unsigned int> Trknumhitacl1;   


 std::vector<double> HitPhi;      // Phi position of all the Hits (deg)
 std::vector<double> HitR;        // R position of all the Hits (mm)
 std::vector<double> HitType;     // 0-> only pad; 1-> only strip 2->Class 1 Hit (superimposition Pad/Strip)
 std::vector<double> HitNumPad;   // Cluster Pad Size 
 std::vector<double> HitNumStrip; // Cluster Strip Size
 

 std::vector<double> TrkEntryX;   //Trk Entry point X
 std::vector<double> TrkEntryY;   //Trk Entry point Y 
 std::vector<double> TrkEntryZ;   //Trk Entry point Z
 std::vector<double> TrkExitX;    //Trk Exit point X
 std::vector<double> TrkExitY;    //Trk Exit point Y  
 std::vector<double> TrkExitZ;    //Trk Exit point Z
 std::vector<double> GeneratorStableCHPartileEta;
 std::vector<double> GeneratorStableCHPartilePhi;
 std::vector<int> GammaVtxSize;    
 std::vector<int> GammaVtxSizeTrkIndex;
 std::vector<double> GammaVtxSizeZImp;

 std::vector<double>GeneratorAllPartileEta; 
 std::vector<double>GeneratorAllPartilePhi;
 std::vector<int> GeneratorAllPartilePDG; 
 std::vector<int> GeneratorAllPartileSTATUS;
 std::vector<int> GeneratorAllPartileBarcode;
 std::vector<double> GeneratorAllPartileE;     
 std::vector<double>  GeneratorAllPartilePt;
 std::vector<int> GeneratorAllPartileCharge1;
 std::vector<int> GeneratorAllPartileCharge2;
 std::vector<int> GeneratorAllPartileCHARGE;

 std::vector<int> GeneratorAllPartileAncestorPID; 

 std::vector<int> GeneratorAllPartileAncestorSize;

 unsigned int NumPadCluH0; //Num pad cluster in the whole H0
 unsigned int NumPadCluH1; 
 unsigned int NumPadCluH2;
 unsigned int NumPadCluH3;


 long int run_no, ev_no;
 unsigned long long timestamp;

 
 //std::vector<double> TrkY0;
 //std::vector<double> TrkY0;

 std::vector<double> Pad_noise;

 private:
 double its_var1;
 int its_var2;
 ClassDef(T2EventDEV,1)
};
#endif
