/****************************************************************************
*
* This is a part of TotemDQM and TOTEM offline software.
* Authors:
*   Rafał Leszko (rafal.leszko@gmail.com)
*
****************************************************************************/

/******************************************************************************************
 * The Dialog shown the new Configuration / Source file should be opened
 * The response on clicking File->Open
 * **************************************************************************************/

#ifndef _OpenDialog_h_
#define _OpenDialog_h_

#include <QDialog>
#include <QPushButton>
#include <QComboBox>
#include <QCheckBox>
#include <QTextEdit>
#include <QLabel>
#include <string>
#include <vector>
#include <QString>
#include <QList>
#include <QRadioButton>
#include <QListWidget>
#include <QShortcut>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>

/**
 * \ingroup TotemDQM
 * \brief A Dialog window responible for opening new configuration file
 *
 * From this window one can open a configuration file with several data files.
 *
 * History both for configuration file and data files is remembered.
 */
class OpenDialog : public QDialog
{
  Q_OBJECT

  public:
    /// Creates the OpenDialog window and reads the history for 'RECO file' and 'configuration file' fields.
    OpenDialog(std::vector<std::string> *recoFileName, std::string *confFileName, std::string *layoutFileName,
        QWidget * parent = 0, Qt::WindowFlags f = 0);

    QString GetConfigFileName() const;

    /// Saves the history for 'RECO file' and 'configuration file' fields.
    /// Uses QT setting to remember history
    void SaveHistory();

    /// Loads the history for 'RECO file' and 'configuration file' fields.
    void LoadHistory();

  private:
    std::vector<std::string> *recoFilenames;
    std::string *confFileName, *layoutFileName;
    std::string recoFilesDirectory;
    QComboBox *confFile, *recoFile, *layoutFile;
    QPushButton *confBrowse, *confEdit, *layoutBrowse, *recoAdd;
    QTextEdit *recoFiles;
    QList<QString> filesList;
    unsigned int dataHistoryPointer, dataHistoryMax;

    QGroupBox* PrepareRecoFilesGroupBox();
    QGroupBox* PrepareConfigurationGroupBox();
    QGroupBox* PrepareLayoutGroupBox();
    QHBoxLayout* PrepareOpenCloseButtonsLayout();

  private slots:
    void AddReco();

    /// Checks the validity of the provided input.
    void ValidateInput();

    void EditConf();
    void HistBackward();
    void HistForward();
    void ClearRecoFiles();

    void BrowseConf();

    void BrowseLayout();
};

#endif
