#include "DlgConfig.h"
#include "ui_DlgConfig.h"

#include <QSpinBox>

DlgConfig::DlgConfig(const QPIREMap &pireMap, const QAntennaGainMap &antGainMap, QWidget *parent) :
	QDialog(parent), ui(new Ui::DlgConfig),
	m_PIREMap(pireMap)
{
	ui->setupUi(this);

    ui->pireTable->fromPIREMap(pireMap);
	ui->gainTable->fromMap(antGainMap);
}

DlgConfig::~DlgConfig()
{
	delete ui;
}

#include <QMessageBox>
#define SHOWWARNING(_t) QMessageBox::warning(this, this->windowTitle(), _t)

void DlgConfig::on_btOk_clicked()
{
	int row;
	int min, max;
	int pir;

	m_PIREMap.clear();
	for( row = 0; row < ui->pireTable->rowCount(); row++ )
	{
        pir = ui->pireTable->pire(row);
		if( pir > 0 )
		{
            if( (min = ui->pireTable->freqMin(row)) % FREQ_INC )
			{
				SHOWWARNING( tr("Las frecuencias han de ser múltimplo de %1.\nLa frecuencia mínima %2 para el PIRE %3 no lo es.").arg(FREQ_INC).arg(min).arg(pir));
				return;
			}
            if( (max = ui->pireTable->freqMax(row)) % FREQ_INC )
			{
				SHOWWARNING( tr("Las frecuencias han de ser múltimplo de %1.\nLa frecuencia máxima %2 para el PIRE %3 no lo es.").arg(FREQ_INC).arg(max).arg(pir));
				return;
			}
			if( max < min )
			{
				SHOWWARNING( tr("En el PIRE %1, la frecuencia máxima es menor que la mínima.").arg(pir) );
				return;
			}
			while( min <= max )
			{
				m_PIREMap[QString("%1").arg(pir)].append(QString("%1").arg(min));
				min += FREQ_INC;
			}
		}
	}
	m_AntennaGainMap.clear();
	if( ui->gainTable->toMap(m_AntennaGainMap) )
		accept();
}

void DlgConfig::on_addPIREButton_clicked()
{
    ui->pireTable->addRow(0, 0, 0);
}
