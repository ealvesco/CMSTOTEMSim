/****************************************************************************
*
* This is a part of TOTEM testbeam/monitoring software.
* Authors: 
*  Jan Kaspar (jan.kaspar@gmail.com) 
*
****************************************************************************/

#ifndef _DQMPlot_h_
#define _DQMPlot_h_

#include <string>
#include <vector>

#include "TNamed.h"

/**
 * \ingroup TotemDQMLite
 * \brief An abstract class encapsultaing a generic plot
**/
class DQMPlot
{
  protected:
    /// if isOwner is true, destructor would free pointers to any data (rather for the children of this class)
    bool isOwner;

  public:
    /// full label of the output which is passed to TNamed::SetTitle() etc.
    std::string label;

    /// label to appear in GUI menus (usually label with axes labels stripped off)
    std::string guiLabel;
    
    /// builds guiLabel by removing axis labels from label
    void ProcessLabel();

    DQMPlot(std::string _l = "no label", bool _o = true) : isOwner(_o), label(_l)
      { ProcessLabel(); }
    
    /// empty destructor, this class has nothing to free, see children of this class
    virtual ~DQMPlot() {}

    /// sets Name(s) and title(s) of output's components (see children classes)
    virtual void SetNameTitle(std::string name, std::string title) = 0;

    /// to draw the output
    virtual void Draw() = 0;

    /// to write the output to a ROOT file
    virtual void Write() = 0;

    /// resets (clears) the output
    virtual void Reset() = 0;

    /// prints info
    virtual void Print() = 0;
};

#endif
