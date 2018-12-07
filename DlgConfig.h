#ifndef DLGCONFIG_H
#define DLGCONFIG_H

#include <QDialog>

#include "FrequencyPIRE.h"
#include "AntennaGain.h"
#include "BaseStationInfo.h"

namespace Ui
{
	class DlgConfig;
}

class DlgConfig : public QDialog
{
	Q_OBJECT
	Ui::DlgConfig *ui;

public:
	explicit DlgConfig(const QFrequencyPireList &freqPIREList, const QAntennaDataList &antDataList, const quint32 freqStep, const QBaseStationMap &baseStationNameMap, QWidget *parent = Q_NULLPTR);
	~DlgConfig();

    QFrequencyPireList frequencyPIREList() const;
	quint32 frequencyStep()const;
    QAntennaDataList antennaDataList() const;
	QBaseStationMap baseStationNameMap() const;

private slots:
	void on_btOk_clicked();
	void on_addPIREButton_clicked();
    void on_addModelGain_clicked();
	void on_pbAddBaseStation_clicked();
};

#endif // DLGCONFIG_H
