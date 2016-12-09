/****************************************************************************
*
* This is a part of TotemDQM and TOTEM offline software.
* Authors:
*   Rafał Leszko (rafal.leszko@gmail.com)
*
****************************************************************************/

#include "FWCore/MessageLogger/interface/MessageLogger.h"

#include "TotemDQMLite/GUI/interface/ChoosePlotDialog.h"
#include "TotemDQMLite/Core/interface/DQMExceptions.h"
#include "TotemDQMLite/Core/interface/DQMPlot.h"
#include "TotemDQMLite/Core/interface/SingleRootPlot.h"

#include "FWCore/Utilities/interface/Exception.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTreeView>
#include <QListView>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QList>
#include <QPushButton>
#include <QLabel>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QMessageBox>

/**
 * Creates the Choose Dialog window
 *
 * Creates the tree structure of elements of the detector with plots related to each element (uses PlotManager)
 */
ChoosePlotDialog::ChoosePlotDialog(QWidget *parent, Qt::WindowFlags f) : QDialog(parent, f) {
    setWindowTitle("TotemDQM: choose plot");
    setMinimumSize(300, 300);

    setGeometry(x(), y(), 550, 550);

    QVBoxLayout *layout = new QVBoxLayout();

    // tree RP / planes BOX
    inTree = CreateInTree();
    inTree->setHeaderLabels(QStringList(QString("element type")) + QStringList(QString("ID")));
    inTree->setColumnCount(1);
    connect(inTree, SIGNAL(itemSelectionChanged()), this, SLOT(UpdateOutView()));
    //

    // graph output BOX
    outView = new QListView();
    outModel = new QStandardItemModel(this);
    outView->setModel(outModel);
    connect(outView, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(Accepted()));
    //

    // views layout
    QHBoxLayout *viewsLayout = new QHBoxLayout();
    QVBoxLayout *inViewLayout = new QVBoxLayout();
    QVBoxLayout *outViewLayout = new QVBoxLayout();
    inViewLayout->addWidget(new QLabel("Choose an element:", this));
    inViewLayout->addWidget(inTree);
    outViewLayout->addWidget(new QLabel("Choose a plot:", this));
    outViewLayout->addWidget(outView);
    viewsLayout->insertLayout(-1, inViewLayout);
    viewsLayout->insertLayout(-1, outViewLayout);
    //

    // OK / CANCEL Buttons
    QHBoxLayout *okCancelLayout = new QHBoxLayout();
    QPushButton *okButton = new QPushButton("OK", this);
    connect(okButton, SIGNAL(clicked()), this, SLOT(Accepted()));
    okButton->setFixedWidth(100);
    QPushButton *emptyButton = new QPushButton("Empty", this);
    connect(emptyButton, SIGNAL(clicked()), this, SLOT(Empty()));
    emptyButton->setFixedWidth(100);
    QPushButton *cancelButton = new QPushButton("Cancel", this);
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
    cancelButton->setFixedWidth(100);
    okCancelLayout->addWidget(okButton);
    okCancelLayout->addWidget(emptyButton);
    okCancelLayout->addWidget(cancelButton);
    okCancelLayout->setSpacing(0);
    //


    layout->insertLayout(-1, viewsLayout);
    layout->insertLayout(-1, okCancelLayout);

    setLayout(layout);
}

/*****************************************************************************************************
 * SLOTS
 * **************************************************************************************************/

/**
 * Updates the right part of the window(plot selection)
 *
 * It is invoked when user selects the element of the detector in the tree structure (left part of the window)
 */
void ChoosePlotDialog::UpdateOutView() {
    try {
        outModel->clear();
        QList<QStandardItem*> list;
        QList<QTreeWidgetItem*> selectedItems = inTree->selectedItems();
        if (selectedItems.isEmpty())
            return;
        QTreeWidgetItem *item = selectedItems.first();
        QVariant data = item->data(0, Qt::UserRole);
        if (!data.isValid())
            return;
        QMap<QString, QVariant> map = data.toList().first().toMap();
        QList<QVariant> vector = data.toList().last().toList();
        for (QList<QVariant>::iterator iter = vector.begin(); iter != vector.end(); iter++) {
            QString name = iter->toString();
            QVariant data = map[name];
            if (!data.isValid())
                continue;
            QStandardItem *item = new QStandardItem(name);
            item->setEditable(false);
            item->setData(data);
            list.push_back(item);
        }
        outModel->insertColumn(0, list);
    }
//    catch (cms::Exception &e) {
    catch (std::exception &e) {
//        edm::LogError("ChoosePlotDialog") << e;
        QMessageBox msgBox;
        msgBox.setText(e.what());
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();
    }
}

/**
 * Accepts the choice, graph chosen
 */
void ChoosePlotDialog::Accepted() {
    try {
        QList<QModelIndex> list = outView->selectionModel()->selectedIndexes();
        if (list.isEmpty()) {
            //reject();
            return;
        }
        QModelIndex modelIndex = list.first();
        QStandardItem *item = outModel->itemFromIndex(modelIndex);
        QVariant data = item->data();
        if (!data.isValid()) {
            throw UnknownMonitorException();
        }
//        std::string ident = data.toString().toStdString();
        std::string ident = data.toString().toUtf8().constData();

        DQMPlot *monitorOutput = PlotManager::Get(ident);
        if (monitorOutput) {
            *mo = monitorOutput;
            *graphIdent = ident;
            accept();
        }
        else {
            throw UnknownMonitorException();
        }
    }
    catch (...) {
//        edm::LogError("ChoosePlotDialog") << "EXCEPTION: in ChoosePlotDialog";
        QMessageBox msgBox;
        msgBox.setText("Error in Choose Graph Dialog. Please try again.");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();
    }
}

/**
 * Sets the Empty Plot (after "Empty" button is clicked)
 */
void ChoosePlotDialog::Empty() {
    *mo = &singleRootOutputEmpty;
    *graphIdent = "";
    accept();
}


/*****************************************************************************************************
 *  auxiliary functions for treeModel (inView) creation
 *  parsing string name and creating tree
*****************************************************************************************************/

QTreeWidget *ChoosePlotDialog::CreateInTree() {
    QTreeWidget *tree = new QTreeWidget(this);
    QTreeWidgetItem *item = new QTreeWidgetItem();

    std::vector<std::string> vector = plotManager.GetPlotsNameOrder();
    for (std::vector<std::string>::iterator iter = vector.begin(); iter != vector.end(); iter++) {
        AddItemToList(item, *iter, *iter);
    }

    tree->addTopLevelItems(item->takeChildren());
    delete item;

    return tree;
}

void ChoosePlotDialog::AddItemToListFinal(QTreeWidgetItem *item, std::string name, std::string ident) {
    QMap<QString, QVariant> map;
    QList<QVariant> vector;
    if (item->data(0,Qt::UserRole).isValid()) {     // no data yet
        map = item->data(0,Qt::UserRole).toList().first().toMap();
        vector = item->data(0,Qt::UserRole).toList().last().toList();
    }
    QVariant val(QString(ident.c_str()));
    QString key(name.c_str());
    map[key] = val;
    vector.push_back(key);
    QList<QVariant> list;
    list.push_back(map);
    list.push_back(vector);
    QVariant data(list);
    item->setData(0,Qt::UserRole,data);

}

void ChoosePlotDialog::AddItemToList2(QTreeWidgetItem *item, std::string hd, std::string tl, std::string ident) {
    std::string name = hd;

    QTreeWidgetItem *itemChild = 0;
    QList<QTreeWidgetItem*> list = item->takeChildren();
    for (QList<QTreeWidgetItem*>::iterator iter = list.begin(); iter != list.end(); iter++) {
        if ((*iter)->text(0) == name.c_str()) {
            itemChild = *iter;
        }
    }
    if (itemChild == 0) {
        itemChild = new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString(name.c_str())) );
        list.push_back(itemChild);
    }
    item->addChildren(list);

    AddItemToList(itemChild, tl, ident);
}

void ChoosePlotDialog::AddItemToList(QTreeWidgetItem *item, std::string name, std::string ident) {
    size_t pos = name.find('/');
    if (pos != std::string::npos) {
        std::string hd = name.substr(0, pos);
        std::string tl = name.substr(pos + 1);
        AddItemToList2(item, hd, tl, ident);
    }
    else
        AddItemToListFinal(item, name, ident);
}
