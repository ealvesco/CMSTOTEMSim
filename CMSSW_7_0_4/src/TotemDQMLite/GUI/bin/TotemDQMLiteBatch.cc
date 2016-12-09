/****************************************************************************
*
* This is a part of TotemDQM and TOTEM offline software.
* Authors:
*   Jan Kašpar (jan.kaspar@gmail.com)
*   Mariusz Wojakovski
*
****************************************************************************/

#include "TotemDQMLite/GUI/interface/ProcessManager.h"
#include "TotemDQMLite/Core/interface/PlotExport.h"


using namespace std;

//----------------------------------------------------------------------------------------------------

void PrintUsage()
{
  printf("USAGE:\n");
  printf("    TotemDQMLiteBatch [options] <reco file> <reco file> ...\n");
  printf("\n");
  printf("OPTIONS:\n");
  printf("    -cfg <config>    DQM config file\n");
  printf("                     default: %s\n", ProcessManager::GetDefaultConfigFile().c_str());
  printf("    -l <layout>      will use this layout to save PDF after processing\n");
  printf("                     (multiple use allowed)\n");
  printf("    -prefix <arg>    prefix for plot file names; default \"\"\n");
  printf("    -suffix <arg>    suffix for plot file names; default \".pdf\"\n");
}

//----------------------------------------------------------------------------------------------------

int main(int argc, char **argv)
{
  // parse command-line arguments, if supplied
  string confFileName = "";   // empty string will be replaced by default config in ProcessManager
  vector<string> recoFiles;
  vector<string> layoutFiles;
  string plotPrefix = "";
  string plotSuffix = ".pdf";

  for (int i = 1; i < argc; i++)
  {
    if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0)
    {
      PrintUsage();
      return 0;
    }

    if (strcmp(argv[i], "-cfg") == 0)
    {
      if (++i >= argc)
      {
        printf("ERROR: -cfg option needs an argument.\n");
        PrintUsage();
        return 1;
      }

      confFileName = argv[i];
      continue;
    }

    if (strcmp(argv[i], "-l") == 0)
    {
      if (++i >= argc)
      {
        printf("ERROR: -l option needs an argument.\n");
        PrintUsage();
        return 1;
      }

      layoutFiles.push_back(argv[i]);
      continue;
    }

    if (strcmp(argv[i], "-prefix") == 0)
    {
      if (++i >= argc)
      {
        printf("ERROR: -prefix option needs an argument.\n");
        PrintUsage();
        return 1;
      }

      plotPrefix = argv[i];
      continue;
    }

    if (strcmp(argv[i], "-suffix") == 0)
    {
      if (++i >= argc)
      {
        printf("ERROR: -suffix option needs an argument.\n");
        PrintUsage();
        return 1;
      }

      plotSuffix = argv[i];
      continue;
    }

    if (argv[i][0] == '-')
    {
      printf("ERROR: Option '%s' not recognised.\n", argv[i]);
      PrintUsage();
      return 2;
    }

    recoFiles.push_back(argv[i]);
  }

  // check if some reco files actually supplied
  if (recoFiles.empty())
  {
    printf("ERROR: No input file provided.\n");
    PrintUsage();
    return 3;
  }

  // check if some layout files actually supplied
  if (layoutFiles.empty())
  {
    printf("ERROR: No layout file provided.\n");
    PrintUsage();
    return 4;
  }

  ProcessManager& processManager = ProcessManager::GetInstance();

  // initialize modules
  int moduleInitResult = processManager.InitializeModules(confFileName);
  if (moduleInitResult != 0)
  {
    printf("ERROR: Module initialization failed. Most likely there is a problem with the config file.\n");
    return 10;
  }

  // open input files
  int loadInputFileResult = processManager.LoadInputFiles(recoFiles);
  if (loadInputFileResult != 0)
  {
    printf("ERROR: File opening failed.\n");
    return 11;
  }

  // run cumulative processing 
  processManager.RunCumulativeProcessing();

  // save plots
  PlotExport *exp = new PlotExport("", plotPrefix, plotSuffix, layoutFiles);
  exp->Save();

  return 0;
}
