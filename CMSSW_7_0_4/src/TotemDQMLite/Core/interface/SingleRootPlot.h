/****************************************************************************
*
* This is a part of TOTEM testbeam/monitoring software.
* Authors: 
*  Jan Kaspar (jan.kaspar@gmail.com) 
*
****************************************************************************/

#ifndef _SingleRootPlot_h_
#define _SingleRootPlot_h_

#include "TotemDQMLite/Core/interface/DQMPlot.h"


/**
 * \ingroup TotemDQMLite
 * \brief A monitor output containing only one ROOT object.
**/
class SingleRootPlot : public DQMPlot
{
  protected:
    /// the ROOT object
    TNamed *obj;

    /// draw option
    std::string opt;

  public:
    SingleRootPlot(std::string _l = "no label", TNamed *_obj = NULL, std::string _opt = "", bool _own = true);

    virtual ~SingleRootPlot();
    virtual void SetNameTitle(std::string name, std::string title);
    static void Reset(TNamed *);
    virtual void Reset() { Reset(obj); }
    virtual void Draw();
    virtual void Write();
    virtual void Print();

    /// determines default draw option based on the class of obj
    static void GetDefaultOption(TNamed *n, std::string &opt);
};

extern SingleRootPlot singleRootOutputEmpty;

#endif
