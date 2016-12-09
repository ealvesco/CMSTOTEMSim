/****************************************************************************
*
* This is a part of TotemDQM and TOTEM offline software.
* Authors:
*   Jan Kašpar (jan.kaspar@gmail.com)
*   Mariusz Wojakovski
*
****************************************************************************/

#include "TotemDQMLite/GUI/interface/MainWindow.h"
#include "TotemDQMLite/GUI/interface/ProcessManager.h"
#include "TotemDQMLite/GUI/interface/QRootEventHandler.h"

#include <QApplication>

#include "TApplication.h"

#include <iostream>

using namespace std;

//----------------------------------------------------------------------------------------------------

void PrintUsage()
{
  printf("USAGE:\n");
  printf("    start GUI:\n");
  printf("        TotemDQMLite\n");
  printf("    load input and start GUI:\n");
  printf("        TotemDQMLite [options] <reco file> <reco file> ...\n");
  printf("\n");
  printf("OPTIONS:\n");
  printf("    -cfg <config>    DQM config file\n");
  printf("                     default: %s\n", ProcessManager::GetDefaultConfigFile().c_str());
  printf("    -l <layout>      start-up layout, default: none\n");
}

//----------------------------------------------------------------------------------------------------

int main(int argc, char **argv)
{
  // parse command-line arguments, if supplied
  string confFilename = "";   // empty string will be replaced by default config in ProcessManager
  vector<string> recoFiles;
  string layoutFile;

  if (argc > 1)
  {
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

        confFilename = argv[i];
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

        layoutFile = argv[i];
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
  }

  // init ROOT application
  TApplication rootApp("TotemDQMLite", &argc, argv);

  // init Qt application and its main window
  QApplication app(argc, argv);
  MainWindow mainWindow(NULL);
  mainWindow.show();

  // if input supplied, process it now
  if (!recoFiles.empty())
    mainWindow.OpenSource(recoFiles, confFilename, layoutFile);

  // start ROOT-event handler
  QRootEventHandler *reh = new QRootEventHandler();

  // run application
  app.exec();

  delete reh;

  return 0;
}
