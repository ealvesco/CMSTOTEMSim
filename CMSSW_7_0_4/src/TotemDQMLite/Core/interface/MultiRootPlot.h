/****************************************************************************
*
* This is a part of TOTEM testbeam/monitoring software.
* Authors: 
*  Jan Kaspar (jan.kaspar@gmail.com) 
*
****************************************************************************/

#ifndef _MultiRootPlot_h_
#define _MultiRootPlot_h_

#include "DQMPlot.h"

class TPaveText;

/**
 * \ingroup TotemDQMLite
 * \brief A plot consisting of several ROOT objects, e.g. stack of graphs etc.
 *
 * Use this class if you want to draw several ROOT objects into the same plot. For example, hits belonging to a
 * track and track fit. Or several tracks, etc. All components of the plot must be added by the Add method, which
 * takes a drawing option as a parameter. At drawing time, the Draw method of each element is called with the given
 * option. The drawing order is the order in which the components are added.
 *
 * See an example in TotemDQMLiteModuleRP::PotPlots::PotPlots constructor.
**/
class MultiRootPlot : public DQMPlot
{
  private:
    TPaveText *emptyGraph;

  public:
    /// collection type (map: object -> draw option)
    typedef std::vector< std::pair<TNamed *, std::string> > collection;

  protected:
    /// collection of ROOT objects and their draw options
    collection objs;

  public:
    MultiRootPlot(std::string _l = "no label", bool _own = true);
    virtual ~MultiRootPlot();

    virtual void Draw();
    virtual void Write();

    virtual void SetNameTitle(std::string name, std::string title);
    virtual void Reset();
    virtual void Print();

    virtual void Add(TNamed *n, std::string opt)
      { objs.push_back(std::pair<TNamed *, std::string>(n, opt)); }

    virtual void Clear()
      { objs.clear(); }

    virtual void Release(unsigned int keepFirstN);
};

#endif
