#include "DlgConfig.h"
#include "ui_DlgConfig.h"

DlgConfig::DlgConfig(const QFrequencyPireList &freqPIREList,
                     const QAntennaDataList &antDataList,
					 const quint32 freqStep,
					 const QBaseStationNameMap &baseStationNameMap,
                     QWidget *parent) :
    QDialog(parent), ui(new Ui::DlgConfig)
{
	ui->setupUi(this);

    ui->sbSteps->setValue(static_cast<int>(freqStep));
    ui->sbSteps->setMinimum(1);
    ui->pireTable->load(freqPIREList);
    ui->gainTable->load(antDataList);
	ui->baseStationTable->setup(baseStationNameMap);
}

DlgConfig::~DlgConfig()
{
    delete ui;
}

QFrequencyPireList DlgConfig::frequencyPIREList() const
{
    return ui->pireTable->save();
}

quint32 DlgConfig::frequencyStep() const
{
    return static_cast<quint32>(ui->sbSteps->value());
}

QAntennaDataList DlgConfig::antennaDataList() const
{
	return ui->gainTable->save();
}

QBaseStationNameMap DlgConfig::baseStationNameMap() const
{
	return ui->baseStationTable->save();
}

#include <QMessageBox>
#define SHOWWARNING(_t) QMessageBox::warning(this, QString("%1 [%2]").arg(this->windowTitle(), __FUNCTION__), _t)

void DlgConfig::on_btOk_clicked()
{
    bool bAllOk = true;

    // Lets check if all data is fine.
    for( int row = 0; row < ui->pireTable->rowCount(); row++ )
	{
        if( ui->pireTable->pire(row) > 0 )
		{
            if( (ui->pireTable->iniFrequency(row)) % static_cast<quint32>(ui->sbSteps->value()) )
			{
                SHOWWARNING( tr("Las frecuencias han de ser múltiplo de %1.\nLa frecuencia mínima %2 para el PIRE %3 no lo es.")
                             .arg(ui->sbSteps->value())
                             .arg(ui->pireTable->iniFrequency(row))
                             .arg(ui->pireTable->pire(row)));
                bAllOk = false;
                continue;
			}
            if( (ui->pireTable->endFrequency(row)) % static_cast<quint32>(ui->sbSteps->value()) )
			{
                SHOWWARNING( tr("Las frecuencias han de ser múltiplo de %1.\nLa frecuencia máxima %2 para el PIRE %3 no lo es.")
                             .arg(ui->sbSteps->value())
                             .arg(ui->pireTable->iniFrequency(row))
                             .arg(ui->pireTable->pire(row)));
                bAllOk = false;
                continue;
            }
            if( ui->pireTable->endFrequency(row) < ui->pireTable->iniFrequency(row) )
			{
                SHOWWARNING( tr("En el PIRE %1, la frecuencia máxima es menor que la mínima.").arg(ui->pireTable->pire(row)) );
                bAllOk = false;
                continue;
            }
		}
	}
    if( bAllOk )
        accept();
}

void DlgConfig::on_addPIREButton_clicked()
{
    ui->pireTable->addRow();
}

void DlgConfig::on_addModelGain_clicked()
{
    ui->gainTable->addRow();
}

void DlgConfig::on_pbAddBaseStation_clicked()
{
	ui->baseStationTable->addRow();
}
