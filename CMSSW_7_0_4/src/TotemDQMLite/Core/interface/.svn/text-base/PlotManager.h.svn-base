/****************************************************************************
*
* This is a part of TotemDQMLite and TOTEM offline software.
* Authors:
*   Jan Kašpar (jan.kaspar@gmail.com)
*   Rafał Leszko (rafal.leszko@gmail.com)
*
****************************************************************************/

#ifndef _PlotManager_h_
#define _PlotManager_h_


#include <string>
#include <vector>
#include <map>

#include "TNamed.h"

#include "TotemDQMLite/Core/interface/DQMPlot.h"

#include "DataFormats/TotemRPDetId/interface/TotRPDetId.h"

/**
 * \ingroup TotemDQMLite
 * \brief A class responsible for keeping and organizing the plots.
 *
 * Its tasks are to:
 * - register a plot
 * - get a plot by a name
 * - save the plots to ROOT file
 */
class PlotManager
{
  private:
    /// map: path -> plot
	/// TODO: what about unordered_map ??
    typedef std::map<std::string, DQMPlot*> collection;
    collection plots;
    std::vector<std::string> plotsNameOrder;

  public:
    static DQMPlot* Get(const std::string &);

    /// Return directly the plots map (string->plot)
    const collection &GetPlots()
      { return plots; }

    const std::vector<std::string> &GetPlotsNameOrder()
      { return plotsNameOrder; }
    
    /// Registers an DQMPlot by string path and title
    static void Register(const std::string &path, const std::string &title, DQMPlot*);

    /// Overloading of Register function to simplify the registration (automatically using SingleRootPlot) 
    static void Register(const std::string &path, const std::string &title, TNamed*,
        const std::string &opt = "", bool own = true);

    /// Registers a plot which is related to RP detector, simplification of Register function
    static void RegisterRP(TotRPDetId::ElementLevel level, unsigned int id, std::string label,
        const std::string &title, DQMPlot *n);

    /// Overloading of RegisterRP function to simplify the registration (automatically using SingleRootPlot) 
    static void RegisterRP(TotRPDetId::ElementLevel level, unsigned int id, std::string label,
        const std::string &title, TNamed*, const std::string &opt = "", bool own = true);

    /// Clears the registry
    static void Clear();

    /// Saves all registered plots to ROOT file.
    /// \param fileName file to save the ROOT output (*.root)
    static void SaveAs(std::string fileName); 
};

extern PlotManager plotManager;

#endif
