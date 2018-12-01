#include "FrequencyPIRE.h"

QFrequencyTable::QFrequencyTable(QWidget *papi) :
    QTableWidget(papi)
{
    setColumnCount(3);
    setHorizontalHeaderLabels( QStringList() << "PIRE" << "Frec. Inicial" << "Frec. Final" );
}

void QFrequencyTable::load(const QFrequencyPireList &freqPIREList)
{
	while( rowCount() )
		removeRow(0);
	for( int i = 0; i < freqPIREList.count(); i++ )
        addRow(freqPIREList[i]);
}

QFrequencyPireList QFrequencyTable::save() const
{
    QFrequencyPireList fpl;
    for( int row = 0; row < rowCount(); row++)
        fpl.append(iniFrequency(row), endFrequency(row), pire(row));
    return fpl;
}

int QFrequencyTable::addRow(quint32 ini, quint32 end, qint32 pire)
{
    int row = rowCount();
    insertRow(row);
    QFreqWidget *iniWidget = new QFreqWidget();
    QFreqWidget *endWidget = new QFreqWidget(end);

    connect( iniWidget, SIGNAL(valueChanged(int)), endWidget, SLOT(setMinimum(int)) );
    iniWidget->setFrequency(ini);

    setCellWidget(row, 0, new QPireWidget(pire) );
    setCellWidget(row, 1, new QFreqWidget(ini) );
    setCellWidget(row, 2, new QFreqWidget(end) );
    return row;
}

int QFrequencyTable::pire(int row) const
{
    if( (row >= 0) && (row < rowCount()) )
        return static_cast<QPireWidget*>(cellWidget(row, 0))->pire();
    return -1;
}

quint32 QFrequencyTable::iniFrequency(int row) const
{
    if( (row >= 0) && (row < rowCount()) )
        return static_cast<QFreqWidget*>(cellWidget(row, 1))->frequency();
    return 0;
}

quint32 QFrequencyTable::endFrequency(int row) const
{
    if( (row >= 0) && (row < rowCount()) )
        return static_cast<QFreqWidget*>(cellWidget(row, 2))->frequency();
    return 0;
}
