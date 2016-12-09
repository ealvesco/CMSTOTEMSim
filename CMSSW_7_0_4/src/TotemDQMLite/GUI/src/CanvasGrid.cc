/****************************************************************************
*
* This is a part of TotemDQM and TOTEM offline software.
* Authors:
*   Rafał Leszko (rafal.leszko@gmail.com)
*
****************************************************************************/

#include "FWCore/MessageLogger/interface/MessageLogger.h"

#include "TotemDQMLite/GUI/interface/CanvasGrid.h"
#include "TotemDQMLite/Core/interface/PlotManager.h"
#include "TotemDQMLite/GUI/interface/MainWindow.h"

#include <QPushButton>
#include <Q3FileDialog>
#include <Q3Picture>
#include <QMessageBox>

using namespace std;


bool CanvasGrid::loadLayoutMissingPlots;

//----------------------------------------------------------------------------------------------------

CanvasGrid::CanvasGrid(QWidget *parent, Qt::WindowFlags flags) : QGridLayout(parent, 1, 1, 3)
{
    rootCanvasWidgetFactory = new RootCanvasWidgetFactory(this, parent);

    RootCanvasWidget *canvas;
    colNum = 2;
    rowNum = 2;
    for (unsigned int i = 0; i < 2; i++)
    {
        std::vector<RootCanvasWidget*> temp;
        for (unsigned int j = 0; j < 2; j++)
        {
            canvas = rootCanvasWidgetFactory->NewRootCanvasWidget();
            addWidget(canvas, i, j);
            temp.push_back(canvas);
        }
        canvasTab.push_back(temp);
    }
}

//----------------------------------------------------------------------------------------------------

CanvasGrid::CanvasGrid(DQMPlot *mo, std::string ident, QWidget *parent, Qt::WindowFlags flags) : QGridLayout(parent, 1, 1, 3)
{
    rootCanvasWidgetFactory = new RootCanvasWidgetFactory(this, parent);

    colNum = 1;
    rowNum = 1;

    RootCanvasWidget *canvas;
    canvas = rootCanvasWidgetFactory->NewRootCanvasWidget();
    canvas->SetDQMPlot(mo);
    canvas->SetGraphIdent(ident);
    std::vector<RootCanvasWidget*> temp;
    temp.push_back(canvas);
    canvasTab.push_back(temp);
    addWidget(canvas, 1, 1);
}

CanvasGrid::~CanvasGrid() {
    delete rootCanvasWidgetFactory;
}

/**
 * Refreshes all the RootCanvasWidgets, one by one
 */
void CanvasGrid::RefreshCanvas() {
    for (unsigned int i = 0; i < rowNum; i++)
        for (unsigned int j = 0; j < colNum; j++)
            canvasTab[i][j]->Refresh();
}

/**
 * Reloads all the RootCanvasWidgets, one by one
 */
void CanvasGrid::ReloadCanvas() {
    for (unsigned int i = 0; i < rowNum; i++)
        for (unsigned int j = 0; j < colNum; j++)
            canvasTab[i][j]->Reload();
}

/**
 * Clears all the RootCanvasWidgets, one by one
 */
void CanvasGrid::ClearCanvas() {
    for (unsigned int i = 0; i < rowNum; i++)
        for (unsigned int j = 0; j < colNum; j++)
            canvasTab[i][j]->Clear();
}


/**
 * Writes the content of canvases to Layout object (xml)
 */
void CanvasGrid::SaveLayout(QDomDocument &doc, QDomElement &element) {
    QDomElement model = doc.createElement("model");
    unsigned int x = canvasTab.size();
    unsigned int y = canvasTab[0].size();
    model.setAttribute("x", x);
    model.setAttribute("y", y);
    for (unsigned int i = 0; i < x; i++) {
        for (unsigned int j = 0; j < y; j++) {
            model.setAttribute(QString("canvasTab_%1_%2").arg(i).arg(j), QString(canvasTab[i][j]->GraphIdent().c_str()));
        }
    }
    element.appendChild(model);

    QDomElement view = doc.createElement("view");
    view.setAttribute("colNum", colNum);
    view.setAttribute("rowNum", rowNum);
    element.appendChild(view);
}

//----------------------------------------------------------------------------------------------------

bool CanvasGrid::LoadLayout(QDomElement &element)
{
    QDomNode n = element.firstChild();
    unsigned int newColNum=0, newRowNum=0;
    std::vector<std::vector<RootCanvasWidget*> > newCanvasTab;
    while( !n.isNull() ) {
        QDomElement e = n.toElement();

        if (e.tagName() == "model") {
            unsigned int x, y;
            QString temp;
            if ((temp = e.attribute("x", "")) != "") x = temp.toUInt();
            else return false;
            if ((temp = e.attribute("y", "")) != "") y = temp.toUInt();
            else return false;

            for (unsigned int i = 0; i < x; i++) {
                std::vector<RootCanvasWidget*> tempCanvas;
                RootCanvasWidget* canvas;
                DQMPlot *mo;
                tempCanvas.clear();
                for (unsigned int j = 0; j < y; j++) {
                    if ((temp = e.attribute(QString("canvasTab_%1_%2").arg(i).arg(j), "")) != "") {
                        canvas = rootCanvasWidgetFactory->NewRootCanvasWidget();
                        if ((mo = PlotManager::Get(temp.toUtf8().constData()))) {
                            canvas->SetDQMPlot(mo);
                            canvas->SetGraphIdent(temp.toUtf8().constData());
                            tempCanvas.push_back(canvas);
                        } else {
                            cerr << "WARNING in CanvasGrid::LoadLayout > Plot `" << temp.toUtf8().constData() << "' not found in PlotManager.\n";
                            // TODO: use this edm::LogProblem("CanvasGrid")
                            tempCanvas.push_back(canvas);
                            loadLayoutMissingPlots = true;
                        }
                    } else {
                        tempCanvas.push_back(rootCanvasWidgetFactory->NewRootCanvasWidget());
                    }

                }
                newCanvasTab.push_back(tempCanvas);
            }
        }

        if (e.tagName() == "view") {
            QString temp;
            if ((temp = e.attribute("colNum", "")) != "")
                newColNum = temp.toUInt();
            else
                return false;
            if ((temp = e.attribute("rowNum", "")) != "")
                newRowNum = temp.toUInt();
            else
                return false;
        }

        n = n.nextSibling();
    }

    // TODO: why this copying ????
    for (std::vector<std::vector<RootCanvasWidget*> >::iterator iter = canvasTab.begin(); iter != canvasTab.end(); iter++)
        for (std::vector<RootCanvasWidget*>::iterator iter2 = iter->begin(); iter2 != iter->end(); iter2++) {
            removeWidget(*iter2);
            delete *iter2;
        }

    canvasTab.clear();

    colNum = newColNum;
    rowNum = newRowNum;
    canvasTab = newCanvasTab;

    for (unsigned int i = 0; i < canvasTab.size(); i++)
        for (unsigned int j = 0; j < canvasTab[i].size(); j++) {
            addWidget(canvasTab[i][j], i, j);
            canvasTab[i][j]->Refresh();
            if (i < rowNum && j < colNum)
                canvasTab[i][j]->show();
            else
                canvasTab[i][j]->hide();
        }
    return true;
}

//----------------------------------------------------------------------------------------------------

/*********************************************************************************
 * RootCanvasWidgetFactory
 * ******************************************************************************/

CanvasGrid::RootCanvasWidgetFactory::RootCanvasWidgetFactory(CanvasGrid *canvasG, QWidget *parent) {
    canvasGrid = canvasG;
    par = parent;
}

RootCanvasWidget *CanvasGrid::RootCanvasWidgetFactory::NewRootCanvasWidget()
{
    RootCanvasWidget *canvas = new RootCanvasWidget(parent(), Qt::WFlags(0), true);
    connect(canvas, SIGNAL(ChooseDialog(QMouseEvent*)), canvas, SLOT(RunChooseDialog(QMouseEvent*)));
    connect(canvas, SIGNAL(OpenInNewWindow(DQMPlot*, std::string)), GetMainWindow(), SLOT(OpenCanvasInNewWindow(DQMPlot*, std::string)));
    return canvas;
}

MainWindow *CanvasGrid::RootCanvasWidgetFactory::GetMainWindow() {
    return (MainWindow*)parent()->parent()->parent()->parent();
}

/*********************************************************************************
 * SLOTS
 * ******************************************************************************/

void CanvasGrid::AddRow() {
    if (rowNum >= MAX_ROW)
        return;
    if (canvasTab.size() <= rowNum) {
        std::vector<RootCanvasWidget*> temp;
        for (unsigned int i = 0; i < canvasTab[0].size(); i++)
            temp.push_back(rootCanvasWidgetFactory->NewRootCanvasWidget());
        canvasTab.push_back(temp);
        for (unsigned int i = 0; i < colNum; i++)
            addWidget(canvasTab[rowNum][i], rowNum, i);
    }
    else {
        for (unsigned int i = 0; i < colNum; i++) {
            if (canvasTab[rowNum][i]) {   // 'if' just in case of some error, should be always true
                if (!itemAtPosition(rowNum, i))
                    addWidget(canvasTab[rowNum][i], rowNum, i);
                canvasTab[rowNum][i]->show();
            }
            else {
                canvasTab[rowNum][i] = rootCanvasWidgetFactory->NewRootCanvasWidget();
                addWidget(canvasTab[rowNum][i], rowNum, i);
            }
        }
    }
    rowNum++;
}

void CanvasGrid::AddCol() {
    if (colNum >= MAX_COL)
        return;
    if (canvasTab[0].size() <= colNum)  {
        for (std::vector<std::vector<RootCanvasWidget*> >::iterator iter = canvasTab.begin(); iter != canvasTab.end(); iter++)
            iter->push_back(rootCanvasWidgetFactory->NewRootCanvasWidget());
        for (unsigned int i = 0; i < rowNum; i++)
            addWidget(canvasTab[i][colNum], i, colNum);
    }
    else {
        for (unsigned int i = 0; i < rowNum; i++) {
            if (canvasTab[i][colNum])  {  // 'if' just in case of some error, should be always true
                if (!itemAtPosition(i, colNum))
                    addWidget(canvasTab[i][colNum], i, colNum);
                canvasTab[i][colNum]->show();
            }
            else {
                canvasTab[i][colNum] = rootCanvasWidgetFactory->NewRootCanvasWidget();
                addWidget(canvasTab[i][colNum], i, colNum);
            }

        }
    }
    colNum++;
}

void CanvasGrid::DelRow() {
    if (rowNum <= MIN_ROW)
        return;
    rowNum--;
    for (unsigned int i = 0; i < colNum; i++)
        canvasTab[rowNum][i]->hide();
}

void CanvasGrid::DelCol() {
    if (colNum <= MIN_COL)
        return;
    colNum--;
    for (unsigned int i = 0; i < rowNum; i++)
        canvasTab[i][colNum]->hide();
}

/**
 * Creates a screenshot in the selected format
 *
 * Uses system 'convert' to write screenshots in other formats than *.ps
 *
 * Directly from QT does not work (qt bug)
 */
void CanvasGrid::Screenshot() {
    bool psFile = false;
    QString path = Q3FileDialog::getSaveFileName("", "PS (*.ps);;JPG (*.jpg,*.jpeg);;TIFF (*.tiff);; PNG (*.png);; GIF(*.gif);; BMP (*.bmp);; PDF (*.pdf);; all (*)", (QWidget*)parent(), "save file dialog", "Choose a filename to save layout");
    QString path2;
    if (!path.isNull()) {
        // add extension if not given
        int pos = path.lastIndexOf('.');
        if (pos == -1) {
            path += ".ps";
            psFile = true;
        }
        else if (path.mid(pos + 1) == "ps") {
            psFile = true;
        }
        else if (path.mid(pos+1) == "jpg" || path.mid(pos+1) == "jpeg" || path.mid(pos+1) == "tiff" || path.mid(pos+1) == "gif" || path.mid(pos+1) == "bmp" || path.mid(pos+1) == "pdf" || path.mid(pos+1) == "png") {
            path2 = path;
            path = path2.left(pos) + ".ps";
            psFile = false;
        }
        else {
            QMessageBox msgBox(GetMainWindow());
            char buf[300];
            sprintf(buf, "Image format '%s' not supported", path.mid(pos+1).toUtf8().constData());
            msgBox.setText(buf);
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.exec();
            Screenshot();
            return;
        }

        QRootCanvas *tWidget = new QRootCanvas();
        TCanvas *tCanvas = tWidget->GetCanvas();
        tCanvas->Divide(colNum, rowNum);
        for (unsigned int i = 0; i < rowNum; i++)
            for (unsigned int j = 0; j < colNum; j++) {
                tCanvas->cd(i*rowNum + j + 1);
                canvasTab[i][j]->GetDQMPlot()->Draw();
            }
        tCanvas->Update();
        tCanvas->SaveAs(path.toUtf8().constData());
        delete tWidget;

        if (!psFile) {
            /*
             * not working ROOT nor QT3 nor QT4 saving to files other than ps
             * using system program 'convert' by ImageMagick'
            Q3Picture image;
            image.load(path);
            if (!image.isNull() && image.save(path2)) {
              QFile::remove(path);
            }
            */
            char command[200];
            sprintf(command, "convert %s %s", path.toUtf8().constData(), path2.toUtf8().constData());
            if (!system(command))
                QFile::remove(path);
        }
    }
}
