#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>

#include "QIniFile.h"
#include "BaseStationInfo.h"
#include "FrequencyPIRE.h"
#include "AntennaGain.h"

namespace Ui
{
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT
	Ui::MainWindow *ui;

	QFrequencyPireList m_freqPIREList;
	QAntennaDataList m_antDataList;
	quint32 m_freqStep;
	QPanelMap m_panelMap;

	void loadPIREData(const QIniData &cnfgData);
	void loadAntennaData(const QIniData &cnfgData);
    void loadPanelCSV();

public:
	explicit MainWindow(QWidget *parent = Q_NULLPTR);
	~MainWindow();

private slots:
    void loadAll();
	void saveUserData() const;
	void onNewPIRE(int pire);
    void onNewAPGain(quint32 gain);
    void onNewClGain(quint32 gain);
    void onNewDistance(int dist);
    void openCnfgDlg();
    void recalc();
	void on_cbPanels_currentIndexChanged(int index);
};

#endif // MAINWINDOW_H
