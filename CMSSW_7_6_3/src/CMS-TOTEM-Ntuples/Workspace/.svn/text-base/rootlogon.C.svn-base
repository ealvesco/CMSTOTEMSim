{
   std::cout << "Loading rootlogon.C" << std::endl;
   gROOT->ProcessLine(".L tdrstyle.C");
   setTDRStyle();
   gStyle->SetOptStat(1111111);
   gStyle->SetHistLineWidth(2);
   gStyle->SetMarkerStyle(23);
   gStyle->SetMarkerSize(0.3);
   gStyle->SetErrorX(0.5);
   gStyle->SetPalette(1);

   TString cmstotem_path = gSystem->Getenv("CMSTOTEM_BASE");

   gSystem->Load( cmstotem_path + TString("/TOTEMdataFormat/lib/libTOTEMdataFormat.so") );
   gSystem->Load( cmstotem_path + TString("/CMSdataFormat/lib/libCMSdataFormat.so") );

   gSystem->AddIncludePath( TString("-I") + cmstotem_path + TString("/CMSdataFormat") );
   gSystem->AddIncludePath( TString("-I") + cmstotem_path + TString("/TOTEMdataFormat/src") );

   cout << "\n Available libraries:" << endl
        << gSystem->GetLibraries() << endl;

   cout << "\n INCLUDE PATH:" << endl
        << gSystem->GetIncludePath() << endl;
   cout << endl;

   // Load when using proton transport
   //gSystem->Load("parametrization/libSimG4CMSTotemRPProtTranspPar");
   
   // --------------------------------------
   //gSystem->Load("libFWCoreFWLite");
   //AutoLibraryLoader::enable();
}
