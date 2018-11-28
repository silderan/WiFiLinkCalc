#include "DlgConfig.h"
#include "ui_DlgConfig.h"

#include <QSpinBox>

class QPireWidget : public QSpinBox
{
public:
	QPireWidget(int pire, QWidget *papi = 0) : QSpinBox(papi)
	{
		setRange(0, 100);
		setPire(pire);
		setSuffix(" dBm");
	}
	int pire() const { return value();	}
	void setPire(int pire)	{ setValue(pire); }
};

class QFreqWidget : public QSpinBox
{
public:
	template <class T>
	QFreqWidget(T freq, QWidget *papi = 0 ) : QSpinBox(papi)
	{
		setRange(0, 6000);
		setFrequency(freq);
		setSuffix(" Mhz");
		setSingleStep( FREQ_INC );
	}
	void setFrequency(int fr)				{ setValue(fr);				}
	void setFrequency(const QString &fr)	{ setFrequency(fr.toInt()); }
	int frequency() const	{ return value();	}
};

void DlgConfig::addPIRERow(int pire, int min, int max)
{
	int row = ui->pireTable->rowCount();
	ui->pireTable->insertRow(row);
	ui->pireTable->setCellWidget(row, 0, new QPireWidget(pire) );
	ui->pireTable->setCellWidget(row, 1, new QFreqWidget(min) );
	ui->pireTable->setCellWidget(row, 2, new QFreqWidget(max) );
}

int DlgConfig::pire(int row)
{
	if( row < ui->pireTable->rowCount() )
		return static_cast<QPireWidget*>(ui->pireTable->cellWidget(row, 0))->pire();
	return -1;
}

int DlgConfig::freqMin(int row)
{
	if( row < ui->pireTable->rowCount() )
		return static_cast<QFreqWidget*>(ui->pireTable->cellWidget(row, 1))->frequency();
	return -1;
}

int DlgConfig::freqMax(int row)
{
	if( row < ui->pireTable->rowCount() )
		return static_cast<QFreqWidget*>(ui->pireTable->cellWidget(row, 2))->frequency();
	return -1;
}

DlgConfig::DlgConfig(const QPIREMap &pireMap, const QAntennaGainMap &antGainMap, QWidget *parent) :
	QDialog(parent), ui(new Ui::DlgConfig),
	m_PIREMap(pireMap)
{
	ui->setupUi(this);
	ui->pireTable->setColumnCount(3);
	ui->pireTable->setHorizontalHeaderLabels( QStringList() << "PIRE" << "Frec. Inicial" << "Frec. Final" );

	QPIREMapIterator it(m_PIREMap);
	while( it.hasNext() )
	{
		it.next();
		int tmp, min = 0, max = 0; // Frecuencia mínima y máxima.
		foreach( QString fr, it.value() )
		{
			tmp = fr.toInt();
			if( max == 0 )
				max = min = tmp;
			else
			if( tmp > max )
				max = tmp;
			else
			if( tmp < min )
				min = tmp;
		}
		addPIRERow(it.key().toInt(), min, max);
	}
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
		pir = pire(row);
		if( pir > 0 )
		{
			if( (min = freqMin(row)) % FREQ_INC )
			{
				SHOWWARNING( tr("Las frecuencias han de ser múltimplo de %1.\nLa frecuencia mínima %2 para el PIRE %3 no lo es.").arg(FREQ_INC).arg(min).arg(pir));
				return;
			}
			if( (max = freqMax(row)) % FREQ_INC )
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
	addPIRERow(0, 0, 0);
}
