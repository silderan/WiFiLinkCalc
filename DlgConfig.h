#ifndef DLGCONFIG_H
#define DLGCONFIG_H

#include <QDialog>
#include <QFrequencyComboBox.h>
#include <AntennaGain.h>

#define FREQ_INC (5)
namespace Ui
{
	class DlgConfig;
}

class DlgConfig : public QDialog
{
	Q_OBJECT
	Ui::DlgConfig *ui;
	QPIREMap m_PIREMap;
	QAntennaGainMap m_AntennaGainMap;

	void addPIRERow(int pire, int min, int max);
	int pire(int row);
	int freqMin(int row);
	int freqMax(int row);
	int freqInc(int row);

public:
	explicit DlgConfig(const QPIREMap &pireMap, const QAntennaGainMap &antGainMap, QWidget *parent = 0);
	~DlgConfig();

	const QPIREMap &pireMAP() const					{ return m_PIREMap;	}
	const QAntennaGainMap &antennaGainMap() const	{ return m_AntennaGainMap;	}

private slots:
	void on_btOk_clicked();
	void on_addPIREButton_clicked();
};

#endif // DLGCONFIG_H
