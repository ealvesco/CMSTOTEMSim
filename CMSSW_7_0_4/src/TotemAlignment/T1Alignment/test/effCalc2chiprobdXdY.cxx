#include <iostream>
#include <fstream>
#include <assert.h>

using namespace std;



int main(){

  
  float eff[2][5][120][4];
  int dummy;

  ifstream f;
  f.open("eff_plane0_Al_chiprob_dXdY2");
  assert(f.is_open());
  for(unsigned int j=0;j<2;j++)
    for(unsigned int i = 0; i < 120; i++){
      f >> dummy; f >> dummy; f >> dummy; 
      for(unsigned int l=0; l<4; l++){
	f >> eff[j][0][i][l]; 
	
      }
    }
  f.close();
  f.open("eff_plane1_Al_chiprob_dXdY2");
  assert(f.is_open());
  for(unsigned int j=0;j<2;j++)
    for(unsigned int i = 0; i < 120; i++){
      f >> dummy; f >> dummy; f >> dummy; 
      for(unsigned int l=0; l<4; l++){
	f >> eff[j][1][i][l]; 
	  }
    }
 f.close();
  f.open("eff_plane2_Al_chiprob_dXdY2");
  assert(f.is_open());
  for(unsigned int j=0;j<2;j++)
    for(unsigned int i = 0; i < 120; i++){
      f >> dummy; f >> dummy; f >> dummy; 
      for(unsigned int l=0; l<4; l++){
	f >> eff[j][2][i][l]; 
	  }
    }
 f.close();
  f.open("eff_plane3_Al_chiprob_dXdY2");
  assert(f.is_open());
  for(unsigned int j=0;j<2;j++)
    for(unsigned int i = 0; i < 120; i++){
      f >> dummy; f >> dummy; f >> dummy; 
      for(unsigned int l=0; l<4; l++){
	f >> eff[j][3][i][l]; 
	  }
    }
 f.close();
  f.open("eff_plane4_Al_chiprob_dXdY2");
  assert(f.is_open());
  for(unsigned int j=0;j<2;j++)
    for(unsigned int i = 0; i < 120; i++){
      f >> dummy; f >> dummy; f >> dummy; 
      for(unsigned int l=0; l<4; l++){
	f >> eff[j][4][i][l]; 
	  }
    }
  
 f.close();
// efficienza per piano in 100 bins di phi
//360/120=3. 
// 4 bins in eta da 3 a 4.6; bins da 0.4 eta


  float trackEff3[2][120][4];
  float EFF[2][5][120][4];


  for(unsigned int j=0;j<2;j++)
    for(unsigned int k=0;k<5;k++)
      for(unsigned int i = 0; i < 120; i++)
	for(unsigned int l=0; l<4; l++){
	EFF[j][k][i][l]=eff[j][k][i][l]/100.;
//	cout << EFF[j][k][i][l] << endl;

      }



  ofstream oFile("EFF_bin_chiprob_dXdY.dat");
  for(unsigned int j=0;j<2;j++){
	if(j==0)cout << "ARM PLUS" << endl; 
	if(j==1)cout << "ARM MINUS" << endl;
   for(unsigned int i = 0; i < 120; i++){
     for(unsigned int l=0; l<4;l++){
	trackEff3[j][i][l]= 
	  EFF[j][0][i][l]*EFF[j][1][i][l]*EFF[j][2][i][l]*(1-EFF[j][3][i][l])*(1-EFF[j][4][i][l])   +
	  EFF[j][0][i][l]*EFF[j][1][i][l]*EFF[j][3][i][l]*(1-EFF[j][2][i][l])*(1-EFF[j][4][i][l])   +
	  EFF[j][0][i][l]*EFF[j][1][i][l]*EFF[j][4][i][l]*(1-EFF[j][2][i][l])*(1-EFF[j][3][i][l])   +
	  EFF[j][0][i][l]*EFF[j][2][i][l]*EFF[j][3][i][l]*(1-EFF[j][1][i][l])*(1-EFF[j][4][i][l])   +
	  EFF[j][0][i][l]*EFF[j][2][i][l]*EFF[j][4][i][l]*(1-EFF[j][1][i][l])*(1-EFF[j][3][i][l])   +
	  EFF[j][0][i][l]*EFF[j][3][i][l]*EFF[j][4][i][l]*(1-EFF[j][1][i][l])*(1-EFF[j][2][i][l])   +
	  EFF[j][1][i][l]*EFF[j][2][i][l]*EFF[j][3][i][l]*(1-EFF[j][0][i][l])*(1-EFF[j][4][i][l])   +
	  EFF[j][1][i][l]*EFF[j][2][i][l]*EFF[j][4][i][l]*(1-EFF[j][0][i][l])*(1-EFF[j][3][i][l])   +
	  EFF[j][1][i][l]*EFF[j][3][i][l]*EFF[j][4][i][l]*(1-EFF[j][0][i][l])*(1-EFF[j][2][i][l])   +
	  EFF[j][2][i][l]*EFF[j][3][i][l]*EFF[j][4][i][l]*(1-EFF[j][0][i][l])*(1-EFF[j][1][i][l])   +
	  
	  EFF[j][0][i][l]*EFF[j][1][i][l]*EFF[j][2][i][l]*EFF[j][3][i][l]*(1-EFF[j][4][i][l])   +
	  EFF[j][0][i][l]*EFF[j][1][i][l]*EFF[j][2][i][l]*EFF[j][4][i][l]*(1-EFF[j][3][i][l])   +
	  EFF[j][0][i][l]*EFF[j][2][i][l]*EFF[j][3][i][l]*EFF[j][4][i][l]*(1-EFF[j][1][i][l])   +
	  EFF[j][1][i][l]*EFF[j][2][i][l]*EFF[j][3][i][l]*EFF[j][4][i][l]*(1-EFF[j][0][i][l])   +
	  EFF[j][0][i][l]*EFF[j][1][i][l]*EFF[j][3][i][l]*EFF[j][4][i][l]*(1-EFF[j][2][i][l])   +

	  EFF[j][0][i][l]*EFF[j][1][i][l]*EFF[j][2][i][l]*EFF[j][3][i][l]*EFF[j][4][i][l]  ;


	assert(trackEff3[j][i][l]>=0 &&  trackEff3[j][i][l]<=1);

	
	cout << trackEff3[j][i][l] <<","<< endl;
	oFile << trackEff3[j][i][l] <<endl;
     }
    }

}
  oFile.close();
  return 0;
}

