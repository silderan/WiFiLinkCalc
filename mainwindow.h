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
    QIniData m_cnfgData;

    QFrequencyPireList m_freqPIREList;
    QAntennaDataList m_antDataList;
    quint32 m_freqStep;

    void loadPIREData();
    void savePIREData();

    void loadAntennaData();
    void saveAntennaData();

public:
    explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private slots:
    void loadAll();
    void saveAll();
	void onNewPIRE(int pire);
    void onNewAPGain(quint32 gain);
    void onNewClGain(quint32 gain);
    void onNewDistance(int dist);
    void openCnfgDlg();
    void recalc();
};

#endif // MAINWINDOW_H
