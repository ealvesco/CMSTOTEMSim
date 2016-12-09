/****************************************************************************
*
* This is a part of TotemDQM and TOTEM offline software.
* Authors:
*   Rafał Leszko (rafal.leszko@gmail.com)
*
****************************************************************************/

#include "TotemDQMLite/Modules/interface/CorrelationPlotsSelectorT2.h"
#include <QString>
#include <QStringList>
#include <cstdlib>


// 0-1  arm + 2-3 arm -
CorrelationPlotsSelectorT2::CorrelationPlotsSelectorT2(std::string filter)
{
  // creating Other sorrelation condition, not used at the moment
  for (int i = 0; i < 10; i++) {
    if (i % 2) {
      MatrixHalfPlane[0][i] = MatrixHalfPlane[1][i] = false;
      MatrixHalfPlane[2][i] = MatrixHalfPlane[3][i] = true;
    }
    else {
      MatrixHalfPlane[0][i] = MatrixHalfPlane[1][i] = true;
      MatrixHalfPlane[2][i] = MatrixHalfPlane[3][i] = false;
    }
  }

  //This force or exclude planes correlation from user input
  ReadFilterString(filter); 
}


void CorrelationPlotsSelectorT2::ReadFilterString(std::string correlationPlotsFilter) {

  QString filter(correlationPlotsFilter.c_str());
  filter = filter.simplified();     //whitespace removed
  QStringList filterList = filter.split(';');   //make a list of string according to the ; separator
  QString defaultFilter = filterList.first();
  defaultFilter = defaultFilter.simplified();
  filterList.pop_front();           //remove first element of the list  
  int pos = defaultFilter.indexOf('=');
  if (defaultFilter.left(11) != "ForEachHalf" || pos == -1) {
    printf("!!! The correlation filter string \"%s\" is not correct. Check it and try again.\n", correlationPlotsFilter.c_str());
    printf("!!! The correlation plots are not loaded\n");
    exit(1);
  }
  defaultFilter = defaultFilter.mid(pos+1).simplified();
  //Example: QString x = "Nine pineapples"; QString z = x.mid(5); // z == "pineapples"


  QStringList defaultFilterList = defaultFilter.split(',');
  for (QStringList::iterator iter = defaultFilterList.begin(); iter != defaultFilterList.end(); iter++) {
    if (iter->simplified() == "")
      continue;
    bool ok;
    unsigned int n;
    n = iter->simplified().toUInt(&ok);
    if (!ok) {
      printf("!!! The correlation filter string \"%s\" is not correct. Check it and try again.\n", correlationPlotsFilter.c_str());
      printf("!!! The correlation plots are not loaded\n");
      exit(1);
    }
    defaultPlaneIds.insert(n);
  }

  //Now I look at non default string

  for (QStringList::iterator iter = filterList.begin(); iter != filterList.end(); iter++) {
    QString temp = iter->simplified();
    if (temp == "")
      continue;
    int pos = temp.indexOf('=');
    if (pos == -1) {
      printf("!!! The correlation filter string \"%s\" is not correct. Check it and try again.\n", correlationPlotsFilter.c_str());
      printf("!!! The correlation plots are not loaded\n");
      exit(1);
    }
    QString HalfTeleString = temp.left(pos).simplified();
    QString PlanesString = temp.mid(pos+1).simplified();
    bool ok;
    unsigned int AboluteHalfId = HalfTeleString.toUInt(&ok);
    //---------------------------------------
    //Remember:
    //unsigned int HalfId=AboluteHalfId%2;
    //unsigned int ArmId=AboluteHalfId/2;
    //---------------------------------------
    if (!ok) {
      printf("!!! The correlation filter string \"%s\" is not correct. Check it and try again.\n", correlationPlotsFilter.c_str());
      printf("!!! The correlation plots are not loaded\n");
      exit(1);
    }

    QStringList PlaneInHalfList = PlanesString.split(',');
    bool ifAny = false;
    for (QStringList::iterator i = PlaneInHalfList.begin(); i != PlaneInHalfList.end(); i++) {
      if (i->simplified() == "")
        continue;
      unsigned int PlaneId = i->simplified().toUInt(&ok);
      if (!ok) {
        printf("!!! The correlation filter string \"%s\" is not correct. Check it and try again.\n", correlationPlotsFilter.c_str());
        printf("!!! The correlation plots are not loaded\n");
        exit(1);
      }
      specifiedHalfTelePlaneIds[AboluteHalfId].insert(PlaneId);
      ifAny = true;
    }
    if (!ifAny)
      emptyHalfTeles.insert(AboluteHalfId);
  }
  //Note if you put 3=; in the cfg file you kill any correclation with ht 1 in arm 1.

}


/*

bool CorrelationPlotsSelectorT2::IfCorrelate(unsigned int DetId) {
  //unsigned int RPId = DetId / 10; //means station
  //unsigned int PlaneId = DetId % 10; //means plane
  //return IfCorrelate(RPId, PlaneId);
   unsigned int HalfId = (DetId/10)%2;    //10*ht+20*arm
   unsigned int ArmId = (DetId/20);
   unsigned int PlaneId = (DetId%10);
   unsigned int AboluteHalfId =HalfId+ArmId*2;
   return IfCorrelate(AboluteHalfId, PlaneId); //It is assumed that we wr not interested in correlation from planes in different arms 
}
*/

//It is HERE assumed that Plane1 and Plane2 belongs to the same arm, with index 0..19 according to their ht 
bool CorrelationPlotsSelectorT2::IfCorrelate(unsigned int Plane1, unsigned int Plane2,unsigned int arm) {
  bool flag=false;
  unsigned int HalfId1 =Plane1/10;
  unsigned int Plane1SymbId=Plane1%10;
  unsigned int AbsoluteHalfId1=HalfId1+arm*2;
  unsigned int HalfId2 =Plane2/10;
  unsigned int Plane2SymbId=Plane2%10;
  unsigned int AbsoluteHalfId2=HalfId2+arm*2;
  //Note: emptyHalfTeles are found processing the cfg string in the Non-default part.
  // The nondefault part has biggets priority respect to default part.
  if(emptyHalfTeles.find(AbsoluteHalfId1) == emptyHalfTeles.end())
    if(emptyHalfTeles.find(AbsoluteHalfId2) == emptyHalfTeles.end())
      {
	//Here you han have a default detector in the halfTele or a specified detector

	if((specifiedHalfTelePlaneIds[AbsoluteHalfId1].find(Plane1SymbId) != specifiedHalfTelePlaneIds[AbsoluteHalfId1].end())||(defaultPlaneIds.find(Plane1SymbId) != defaultPlaneIds.end()))
	  if((specifiedHalfTelePlaneIds[AbsoluteHalfId2].find(Plane2SymbId) != specifiedHalfTelePlaneIds[AbsoluteHalfId2].end())||(defaultPlaneIds.find(Plane2SymbId) != defaultPlaneIds.end()))
	    flag=true;
      }


  return flag;
}

/*
bool CorrelationPlotsSelectorT2::IfCorrelate(unsigned int AboluteHalfId, unsigned int PlaneId) {
  bool flag=false;
  if (emptyHalfTeles.find(AboluteHalfId) == emptyHalfTeles.end())
    if(specifiedHalfTelePlaneIds[AboluteHalfId].find(PlaneId) != specifiedHalfTelePlaneIds[AboluteHalfId].end() || (specifiedHalfTelePlaneIds[AboluteHalfId].empty() && defaultPlaneIds.find(PlaneId) != defaultPlaneIds.end()))
      flag=true;

  unsigned int ArmId=AboluteHalfId/2;

return flag;
}
*/
