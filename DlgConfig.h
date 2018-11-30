#ifndef DLGCONFIG_H
#define DLGCONFIG_H

#include <QDialog>
#include <FrequencyPIRE.h>
#include <AntennaGain.h>

namespace Ui
{
	class DlgConfig;
}

class DlgConfig : public QDialog
{
	Q_OBJECT
	Ui::DlgConfig *ui;

public:
	explicit DlgConfig(const QFrequencyPireList &freqPIREList, const QAntennaDataList &antDataList, quint32 freqStep, QWidget *parent = Q_NULLPTR);
	~DlgConfig();

    QFrequencyPireList frequencyPIREList() const;
    quint32 frequencyStep();
    QAntennaDataList antennaDataList() const;

private slots:
	void on_btOk_clicked();
	void on_addPIREButton_clicked();
    void on_addModelGain_clicked();
};

#endif // DLGCONFIG_H
