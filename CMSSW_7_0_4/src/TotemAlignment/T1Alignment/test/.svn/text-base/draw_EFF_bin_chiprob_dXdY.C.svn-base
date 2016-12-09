#include <iostream>
#include <fstream>

// Create, Draw and fit a TGraph2DErrors
 void trackeff(){
    gStyle->SetPalette(1);
    const int nd = 480;

// arm, plane, phi, eta -> 2, 5, 120, 4

    ifstream input;
    input.open("EFF_bin_chiprob_dXdY.dat");

    double z_plus[480];
    double z_minus[480];
    double phi[480];
    double eta[480];
    unsigned int index;

    for(unsigned int j=0;j<2;j++){
      for(unsigned int i = 0; i < 120; i++){
	for(unsigned int l=0; l<4;l++){
	  index = 480*j+4*i+l;
	  if(j==0){
	    input >> z_plus[index] ;
	    phi[index] = (double)i /120. *360.;
	    eta[index] = 3.2 + (double)l / 4. *1.6;
      std::cout << index <<  " "<< eta[index] << std::endl;
	  }else{
	    index = 4*i+l;
	    input >> z_minus[index];
	  }

	}
      }
    }

    TGraph2DErrors *dte = new TGraph2DErrors(nd);
    // Fill the 2D graph
    double x, y, z, ex, ey, ez;
    for (Int_t ii=0; ii<nd; ii++) {
 
//      std::cout << ii <<  " "<< eta[ii] << std::endl;
       dte->SetPoint(ii,phi[ii],eta[ii],z_plus[ii]);
       ex = 0.;
       ey = 0.;
       ez = 0.;
       dte->SetPointError(ii,ex,ey,ez);
    }

    // Plot the result
    TCanvas *c1 = new TCanvas();
    dte->SetTitle("Track efficiency");
    dte->Draw("TRI2");
    // Make the x and y projections
/*    TCanvas* c_p= new TCanvas("ProjCan",
                              "The Projections",1000,400);
    c_p->Divide(2,1);
    c_p->cd(1);
    dte->Project("x")->Draw();
    c_p->cd(2);
    dte->Project("y")->Draw();
*/
 }
