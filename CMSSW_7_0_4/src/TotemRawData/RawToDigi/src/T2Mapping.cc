/****************************************************************************
*
* This is a part of TOTEM testbeam/monitoring software.
* Authors: 
*	Erik Brücken, University of Helsinki, email: brucken@cc.helsinki.fi
*	Jan Kaspar (jan.kaspar@gmail.com) 
*
****************************************************************************/


/*   
 *   Program to convert vfatIID and channel to geometrical strips and pads 
 *   numbers (Giuseppe's layout).
 *   Hardware layout and geometrical layout are shown in the documentation 
 *   that can be found in the same directory.
 *
 *   Author: Erik Brücken, University of Helsinki
 *    email: brucken@cc.helsinki.fi
 */

#include "TotemRawData/RawToDigi/interface/T2Mapping.h"
#include "TMath.h"
#include "TotemRawDataLibrary/DataFormats/interface/VFATFrameCollection.h"

#include <iostream>

Bool_t T2Mapping::convertToGeo(Int_t vfatIID, Int_t channelNR, Int_t &elementFlag, Int_t &elementNR)
{

	channelNR++;
  
  Int_t referencePad, columnOfSector, stepInColumn;
  if (vfatIID<0 || vfatIID>16) {
    
    std::cout << " ERROR: VFatID " << vfatIID << " out of limits! " << std::endl;
    return false;
  }
  if (channelNR<1 || channelNR>128) {
    
    std::cout << " ERROR: Channel number " << channelNR << " out of limits! " << std::endl;
    return false;
  }
  if (vfatIID<2) {
    
    elementFlag = fStrip;
    elementNR = (vfatIID + 1) * 128 - (channelNR - 1);
    //std::cout <<" -> flag= "<< elementFlag <<", element= "<< elementNR << std::endl;
  }
  else if (vfatIID>14) {
    
    elementFlag = fStrip;
    elementNR =  128 * (18 - vfatIID) + channelNR; 
    //std::cout <<" -> flag= "<< elementFlag <<", element= "<< elementNR << std::endl;
  }
  else{
    if (channelNR<4 || channelNR>123) {
      // std::cout << " ERROR: Channel (pad) number " << channelNR << " out of limits! " << std::endl;
      return false;
    }
    elementFlag = fPad;
    referencePad = (vfatIID - 2) * 120 + 97;
    columnOfSector = (Int_t)TMath::Floor((channelNR - 4) / 24);
    stepInColumn = (channelNR - 4) % 24;
    elementNR = referencePad - 24 * columnOfSector + stepInColumn;
    //std::cout <<" -> flag= "<< elementFlag <<", element= "<< elementNR << std::endl;
  }

  return true;

} // convertToGeo


int T2Mapping::convertToStripsPads(Totem::VFATFrameCollection *frames, vector<int> IDs, vector<int>& strips, vector<int>& pads)
{
	/// error counter
	int errors = 0;

	/// first reset the output
	strips.clear(); pads.clear();

	/// go through all VFATs in the detector
	for (unsigned int i = 0; i < IDs.size(); i++) {
		vector<unsigned char> channels;
		channels = frames->GetFrameByID(IDs[i])->getActiveChannels();
		/// go through all active channels and convert them to strips and pads
		for (unsigned j = 0; j < channels.size(); j++) {
			int flag, index;
			/// try to do the conversion
			if (!convertToGeo(i, channels[j], flag, index)) {
				errors++;
				continue;
			}
			/// if the conversion was succesful, check the flag
			if (flag == fStrip) strips.push_back(index);
			if (flag == fPad) pads.push_back(index);
		}
	}

	return errors;
}
