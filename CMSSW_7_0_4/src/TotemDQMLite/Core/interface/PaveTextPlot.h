/****************************************************************************
*
* This is a part of TOTEM testbeam/monitoring software.
* Authors: 
*  Jan Kaspar (jan.kaspar@gmail.com) 
*
****************************************************************************/

#ifndef _PaveTextPlot_h_
#define _PaveTextPlot_h_

#include "TotemDQMLite/Core/interface/DQMPlot.h"

class TPaveText;

/**
 * \ingroup TotemDQMLite
 * \brief A monitor output containing only one ROOT object.
**/
class PaveTextPlot : public DQMPlot
{
  protected:
    /// the ROOT object
    TPaveText *obj;

  public:
    PaveTextPlot(std::string _l = "no label", TPaveText *_obj = NULL, bool _own = true);
    virtual ~PaveTextPlot();

    virtual void SetNameTitle(std::string name, std::string title);
    virtual void Reset();
    virtual void Draw();
    virtual void Write();
    virtual void Print();
};

#endif
