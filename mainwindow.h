#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>

#include "QIniFile.h"
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

	void loadPIREData(const QIniData &cnfgData);
	void savePIREData(QIniData &cnfgData)const;

	void loadAntennaData(const QIniData &cnfgData);
	void saveAntennaData(QIniData &cnfgData) const;

public:
	explicit MainWindow(QWidget *parent = Q_NULLPTR);
	~MainWindow();

private slots:
    void loadAll();
	void saveAll() const;
	void onNewPIRE(int pire);
    void onNewAPGain(quint32 gain);
    void onNewClGain(quint32 gain);
    void onNewDistance(int dist);
    void openCnfgDlg();
    void recalc();
};

#endif // MAINWINDOW_H
