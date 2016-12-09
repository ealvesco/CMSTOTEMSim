/****************************************************************************
*
* This is a part of TotemDQM and TOTEM offline software.
* Authors:
*   Mariusz Wojakowski
*
****************************************************************************/

#include "TotemDQMLite/GUI/interface/RunEventNavigationBox.h"

RunEventNavigationBox::RunEventNavigationBox(std::string title, MainWindow *mainWindow, QWidget *parent) :
        QGroupBox(title.c_str(), parent),
        mainWindow(mainWindow)
{
    CreateAndCustomizeRunNrBox(parent);
    connect(runNrBox, SIGNAL(currentIndexChanged(int)), this, SLOT(RunNrEditted()));

    CreateAndCustomizeEventNrBox(parent);
    connect(eventNrBox, SIGNAL(valueChanged(int)), this, SLOT(EventNrEditted()));

    QHBoxLayout *eventLayout = new QHBoxLayout(this);
    eventLayout->insertLayout(-1, CreateRunLayout());
    eventLayout->insertLayout(-1, CreateEventLayout());
}

void RunEventNavigationBox::EventLimitChanged(int minEventNr, int maxEventNr)
{
    eventNrBox->setMinimum(minEventNr);
    eventNrBox->setMaximum(maxEventNr);
    eventsRangeLabel->setText(QString(" [%1, %2]").arg(minEventNr).arg(maxEventNr));
}

void RunEventNavigationBox::RunsChanged()
{
    runNrBox->clear();
    const std::map<unsigned int, ProcessManager::RunInfo>& runInfo = ProcessManager::GetInstance().GetRunInfo();
    for (auto item : runInfo)
    {
        TotemRunNumber totemRunNumber(item.first);
        runNrBox->addItem(totemRunNumber.ToLongString().c_str(), QVariant(item.first));
    }
}

void RunEventNavigationBox::RunChanged(int runNr)
{
    int index = runNrBox->findData(QVariant(runNr));
    runNrBox->setCurrentIndex(index);
}

void RunEventNavigationBox::EventChanged(int eventNr)
{
    if (eventNrBox->value() != eventNr)
        eventNrBox->setValue(eventNr);
}

void RunEventNavigationBox::RunAndEventNumbersChanged(int runNr, int eventNr)
{
    BlockSignals(true);
    RunChanged(runNr);
    EventChanged(eventNr);
    mainWindow->RunAndEventNumbersChanged(runNr, eventNr);
    BlockSignals(false);
}

//----------------SLOTS----------------

void RunEventNavigationBox::RunNrEditted()
{
    try {
        std::string data = runNrBox->itemData(runNrBox->currentIndex()).toString().toUtf8().constData();
        mainWindow->RunNumberChanged(std::stoi(data));
    }
    catch (std::invalid_argument e) {
        #ifdef DEBUG
            std::cout << "Run number is not valid integer" << std::endl;
        #endif
    }
}

void RunEventNavigationBox::EventNrEditted()
{
    mainWindow->EventNrChanged(eventNrBox->value());
}

//----------------PRIVATE METHODS----------------

void RunEventNavigationBox::CreateAndCustomizeEventNrBox(QWidget *parent)
{
    eventNrBox = new EventAwareSpinBox(this, parent);
    eventNrBox->setFixedWidth(100);
    eventNrBox->setMinimum(1);
    eventNrBox->setKeyboardTracking(false);
}

void RunEventNavigationBox::CreateAndCustomizeRunNrBox(QWidget *parent)
{
    runNrBox = new QComboBox(parent);
    runNrBox->setFixedWidth(300);
    runNrBox->setEditable(false);
}

QLayout* RunEventNavigationBox::CreateRunLayout()
{
    QVBoxLayout *eventLayoutRunNr = new QVBoxLayout();
    eventLayoutRunNr->addWidget(CreateRunNumberLabel());
    eventLayoutRunNr->addWidget(runNrBox);

    return eventLayoutRunNr;
}

QLayout* RunEventNavigationBox::CreateEventLayout()
{
    QVBoxLayout *eventLayoutEventNr = new QVBoxLayout();
    eventLayoutEventNr->addWidget(CreateEventNumberLabel());
    eventLayoutEventNr->insertLayout(-1, CreateEventNrLayout());

    return eventLayoutEventNr;
}

QLayout *RunEventNavigationBox::CreateEventNrLayout()
{
    QHBoxLayout *eventNrLayout = new QHBoxLayout();
    eventsRangeLabel = new QLabel("eventsRangeLabel", this);
    eventNrLayout->addWidget(eventNrBox);
    eventNrLayout->addWidget(eventsRangeLabel);

    return eventNrLayout;
}

QLabel* RunEventNavigationBox::CreateEventNumberLabel()
{
    QLabel *eventNumberLabel = new QLabel("event", this);
    eventNumberLabel->setAlignment(Qt::AlignHCenter);

    return eventNumberLabel;
}

QLabel *RunEventNavigationBox::CreateRunNumberLabel()
{
    QLabel *runNumberLabel = new QLabel("run/file", this);
    runNumberLabel->setAlignment(Qt::AlignHCenter);

    return runNumberLabel;
}

void RunEventNavigationBox::BlockSignals(bool block)
{
    runNrBox->blockSignals(block);
    eventNrBox->blockSignals(block);
}
