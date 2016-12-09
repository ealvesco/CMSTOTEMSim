/****************************************************************************
*
* This is a part of TotemDQM and TOTEM offline software.
* Authors:
*   Rafał Leszko (rafal.leszko@gmail.com)
*
****************************************************************************/

#ifndef _CanvasGrid_h_
#define _CanvasGrid_h_

#include <QGridLayout>

#include "TotemDQMLite/GUI/interface/RootCanvasWidget.h"

#include <vector>
#include <QDomElement>

class MainWindow;

const unsigned int MIN_COL = 1;
const unsigned int MIN_ROW = 1;
const unsigned int MAX_COL = 8;
const unsigned int MAX_ROW = 8;


/**
 * \ingroup TotemDQM
 * \brief Grid for the ROOT Canvases
 *
 * Keeps ROOT Canvases and show them as a grid
 */
class CanvasGrid : public QGridLayout
{
    Q_OBJECT

private:
    /// Creates RootCanvasWidgets and sets all the parameters for them
    class RootCanvasWidgetFactory {
    private:
        CanvasGrid *canvasGrid;
        QWidget *par;
    public:
        RootCanvasWidgetFactory(CanvasGrid *canvasG, QWidget *parent);

        /// creates a new RootCanvasWidget
        RootCanvasWidget *NewRootCanvasWidget();
        QWidget *parent() { return par;}
        MainWindow *GetMainWindow();
    };

    RootCanvasWidgetFactory *rootCanvasWidgetFactory;

    /// Keeps all the RootCanvasWidgets (ROOT canvases)
    /// model for gridLayout
    std::vector<std::vector<RootCanvasWidget*> > canvasTab;
    unsigned int colNum, rowNum;

    friend class MainWindow;
    friend class TabWindow;

    /// flag used by Main and TabWindow to check whether there have been
    /// some plots not found in PlotManager during layout loading by LoadLayout
    static bool loadLayoutMissingPlots;

public:
    /// Creates CanvasGrid, by default 2x2
    CanvasGrid(QWidget *parent = NULL, Qt::WindowFlags flags = 0);


    /// Creates CanvasGrid for zooming feature, 1x1 (only one plot).
    /// @param mo plot to be zoomed
    /// @param ident string describing the plot which is to be zoomed (related to mo)
    CanvasGrid(DQMPlot *mo, std::string ident, QWidget *parent = NULL, Qt::WindowFlags flags = 0);

    ~CanvasGrid();

    /// refresh all the canvases
    void RefreshCanvas();

    /// reaload the graphs from plotManager
    void ReloadCanvas();

    /// clear all the graphs from all the canvases
    void ClearCanvas();

    MainWindow *GetMainWindow()
    {
        return rootCanvasWidgetFactory->GetMainWindow();
    }

    // saving / loading layout
    void SaveLayout(QDomDocument&, QDomElement&);

    /// processes a <CanvasGrid> block
    bool LoadLayout(QDomElement&);

public slots:
    void AddCol();
    void AddRow();
    void DelCol();
    void DelRow();

    void Screenshot();
};

#endif
