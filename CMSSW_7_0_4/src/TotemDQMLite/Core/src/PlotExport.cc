/****************************************************************************
*
* This is a part of TotemDQM and TOTEM offline software.
* Authors:
*   Mariusz Wojakovski
*
****************************************************************************/

#include "TotemDQMLite/Core/interface/PlotExport.h"
#include "TotemDQMLite/Core/interface/PlotManager.h"
#include "TotemDQMLite/Core/interface/RootStyle.h"

#include <QString>
#include <QFile>
#include <QDomDocument>
#include <QDomElement>
#include <QDomNode>

using namespace std;

PlotExport::PlotExport(string rootFileName, string plotFilePrefix, string plotFileSuffix, vector<string> layouts) :
    rootFileName(rootFileName),
    plotFilePrefix(plotFilePrefix),
    plotFileSuffix(plotFileSuffix),
    layouts(layouts)
{
}

TCanvas* PlotExport::MakeLayoutCanvas(const std::string &fileName)
{
  QString path(fileName.c_str());
  QFile file(path);
  if ( !file.open(IO_ReadOnly) )
    return NULL;

  QDomDocument doc("layout");
  if ( !doc.setContent(&file) )
  {
    file.close();
    return NULL;
  }

  file.close();

  QDomElement root = doc.documentElement();
  if (root.tagName() != "layout")
    return NULL;

  QDomNode n = root.firstChild();
  QDomElement e = n.toElement();
  if (e.isNull() || e.tagName() != "TabWindow")
    return NULL;

  n = e.firstChild();
  e = n.toElement();
  if (e.isNull() || e.tagName() != "CanvasGrid")
    return NULL;

  n = e.firstChild();
  TCanvas *c = NULL;
  while (!n.isNull())
  {
    e = n.toElement();

    if (e.tagName() == "model") {
      unsigned int x, y;
      QString temp;
      if ((temp = e.attribute("x", "")) != "")
        x = temp.toUInt();
      else
        return NULL;
      if ((temp = e.attribute("y", "")) != "")
        y = temp.toUInt();
      else
        return NULL;

      c = new TCanvas();
      c->Divide(y, x);

      for (unsigned int i = 0; i < x; i++)
      {
        for (unsigned int j = 0; j < y; j++)
        {
          if ((temp = e.attribute(QString("canvasTab_%1_%2").arg(i).arg(j), "")) != "")
          {
            DQMPlot *mo = PlotManager::Get(temp.toUtf8().constData());
            if (mo) {
              c->cd(i*y + j + 1);
              mo->Draw();
            } else
              printf("ERROR: Unknown plot `%s'\n", temp.toUtf8().constData());
          }
        }
      }
    }

    n = n.nextSibling();
  }

  return c;
}

void PlotExport::Save()
{
  // save ROOT file
  SetRootStyle();

  if (!rootFileName.empty())
  {
    printf(" * saving ROOT file\n");
    plotManager.SaveAs(rootFileName);
  }

  // process all layouts
  for (auto l : layouts)
  {
    // erase extension
    string output = l;
    output.erase(output.find_last_of('.'));

    // erase leading path
    size_t pos;
    pos = output.rfind("layouts/");
    if (pos != string::npos)
      output.erase(0, pos+8);

    // replace / with :
    pos = output.find_first_of('/');
    while (pos != string::npos)
    {
      output[pos]='_';
      pos = output.find_first_of('/', pos+1);
    }
    output = plotFilePrefix + output + plotFileSuffix;

    printf(" * saving layout `%s' to %s\n", l.c_str(), output.c_str());

    TCanvas *c = MakeLayoutCanvas(l);
    if (c)
    {
      c->SetWindowSize(3000, 1600);
      c->SetCanvasSize(3000, 1600);
      c->SaveAs(output.c_str(), "Landscape");
    } else {
      printf("ERROR: Layout `%s' cannot be parsed.\n", l.c_str());
    }
  }
}
