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
	QPIREMap m_PIREMap;
	QAntennaGainMap m_AntennaGainMap;

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
