/****************************************************************************
 *
 * This is a part of TOTEM offline software.
 * Authors:
 *	Jan Kašpar (jan.kaspar@gmail.com)
 *
 ****************************************************************************/

#include "TotemAlignment/RPDataFormats/interface/RPAlignmentCorrections.h"

#include "FWCore/Utilities/interface/Exception.h"

#include <map>

using namespace std;

//----------------------------------------------------------------------------------------------------

void PrintUsage()
{
  printf("USAGE: PrintRPAlignmentSummary <alignment file>\n");
}

//----------------------------------------------------------------------------------------------------

int main(int argc, char **argv)
{
  // check command-line paramters
  if (argc != 2)
  {
    PrintUsage();
    return 1;
  }

  // load alignment corrections
  RPAlignmentCorrections ac;

  try
  {
    ac.LoadXMLFile(argv[1]);
  }

  catch (const cms::Exception &e)
  {
    printf("ERROR: Can't load alignment file:\n%s\n", e.what());
  }

  catch (...)
  {
    printf("ERROR: Can't load alignment file `%s'.\n", argv[1]);
  }

  // calculate mean U and V sensor rotations per RP
  struct SensorRotStat
  {
    unsigned int n_U=0, n_V=0;
    double s_U=0., s_V=0.;
  };

  map<unsigned int, SensorRotStat> srs;

  auto senMap = ac.GetSensorMap();
  for (auto p : senMap)
  {
    unsigned int rp = p.first / 10;
    unsigned int detIdx = p.first % 10;
    if ((detIdx % 2) == 0)
    {
      srs[rp].n_V++;
      srs[rp].s_V += p.second.rot_z();
    } else {
      srs[rp].n_U++;
      srs[rp].s_U += p.second.rot_z();
    }
  }

  // print results per RP
  auto rpMap = ac.GetRPMap();
  for (auto p : rpMap)
  {
    // evaluate difference between mean U and V rotations
    const SensorRotStat &st = srs[p.first];
    double mr_U = (st.n_U > 0) ? st.s_U / st.n_U : 0.;
    double mr_V = (st.n_V > 0) ? st.s_V / st.n_V : 0.;

    printf("RP%3i, %+7.1f, %+7.1f, %+6.2f, %+6.2f\n", p.first, p.second.sh_x()*1E3, p.second.sh_y()*1E3,
      p.second.rot_z()*1E3, (mr_U - mr_V) * 1E3);
  }

  return 0;
}
