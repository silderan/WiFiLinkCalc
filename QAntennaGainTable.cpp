#include "AntennaGain.h"

#include "AntennaGain.h"
#include <QSpinBox>

class QGainWidget : public QSpinBox
{
public:
	QGainWidget(int gain, QWidget *papi = 0) : QSpinBox(papi)
	{
		setRange(0, 100);
		setGain(gain);
		setSuffix(" dBi");
	}
	int gain() const { return value();	}
	void setGain(int pire)	{ setValue(pire); }
};

QAntennaGainTable::QAntennaGainTable(QWidget *parent) : QTableWidget(parent)
{
	setColumnCount(2);
	setHorizontalHeaderLabels(QStringList()<<"Modelo"<<"Ganancia");
}

QAntennaGainTable::~QAntennaGainTable()
{
}

quint32 QAntennaGainTable::gain(int row) const
{
	if( (row < rowCount()) && (row >=0) )
		return static_cast<QGainWidget*>(cellWidget(row, 1))->gain();
	return 0;
}

QString QAntennaGainTable::model(int row) const
{
	if( (row < rowCount()) && (row >=0) )
		return item(row, 0)->text();
	return QString();
}

quint32 QAntennaGainTable::gain(const QString &modelName) const
{
	for( int i = 0; i < rowCount(); i++ )
		if( modelName == this->model(i) )
			return gain(i);
	return 0;
}

void QAntennaGainTable::addRow(const QString &modelName, quint32 gain)
{
	int row = rowCount();
	insertRow(row);
	setItem(row, 0, new QTableWidgetItem(modelName) );
	setCellWidget(row, 1, new QGainWidget(gain) );
}

void QAntennaGainTable::fromMap(const QAntennaGainMap &map)
{
	QAntennaGainMapIterator it(map);
	clear();
	while( it.hasNext() )
	{
		it.next();
		addRow(it.name(), it.gain());
	}
}

bool QAntennaGainTable::toMap(QAntennaGainMap &map) const
{
	for( int row = 0; row < rowCount(); row++ )
	{
		if( !model(row).isEmpty() )
		{
			if( gain(row) <= 0 )
			{
				emit error( tr("Guardando datos de ganancia de las antenas"), tr("La ganancia de la antena del modelo %1 no es válido").arg(model(row)) );
				return false;
			}
			map[model(row)] = gain(row);
		}
	}
	return true;
}
