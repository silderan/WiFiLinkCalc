#include <QSpinBox>

#include "AntennaGain.h"

class QGainWidget : public QSpinBox
{
public:
    QGainWidget(quint32 gain, QWidget *papi = Q_NULLPTR) : QSpinBox(papi)
	{
		setRange(0, 100);
		setGain(gain);
		setSuffix(" dBi");
	}
    quint32 gain() const    { return static_cast<quint32>(value()); }
    void setGain(quint32 pire)	{ setValue(static_cast<int>(pire)); }
};

QAntennaGainTable::QAntennaGainTable(QWidget *papi) :
    QTableWidget(papi)
{
	setColumnCount(2);
	setHorizontalHeaderLabels( QStringList() << "Modelo" << "Ganancia" );
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

void QAntennaGainTable::addRow(const QString &antenaModel, quint32 gain)
{
	int row = rowCount();
	setHorizontalHeaderLabels( QStringList() << "Modelo" << "Ganancia" );
	insertRow(row);
    setItem(row, 0, new QTableWidgetItem(antenaModel) );
	setCellWidget(row, 1, new QGainWidget(gain) );
}

void QAntennaGainTable::load(const QAntennaDataList &antDataList)
{
	while( rowCount() )
		removeRow(0);
    for( int i = 0; i < antDataList.count(); i++ )
        addRow(antDataList[i]);
}

QAntennaDataList QAntennaGainTable::save() const
{
    QAntennaDataList antDataList;
	for( int row = 0; row < rowCount(); row++ )
        if( !model(row).isEmpty() && (gain(row) > 0) )
            antDataList.append( model(row), gain(row) );

    return antDataList;
}
