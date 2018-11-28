#include "FrequencyPIRE.h"

QFrequencyTable::QFrequencyTable(QWidget *papi) :
    QTableWidget(papi)
{
    setColumnCount(3);
    setHorizontalHeaderLabels( QStringList() << "PIRE" << "Frec. Inicial" << "Frec. Final" );
}

void QFrequencyTable::fromPIREMap(const QPIREMap &map)
{
    QPIREMapIterator it(map);
    while( it.hasNext() )
    {
        it.next();
        int tmp, min = 0, max = 0; // Frecuencia mínima y máxima.
        foreach( QString fr, it.frequencyList() )
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
        addRow(it.pire(), min, max);
    }
}

int QFrequencyTable::addRow(int pire, int min, int max)
{
    int row = rowCount();
    insertRow(row);
    setCellWidget(row, 0, new QPireWidget(pire) );
    setCellWidget(row, 1, new QFreqWidget(min) );
    setCellWidget(row, 2, new QFreqWidget(max) );
    return row;
}

int QFrequencyTable::pire(int row)
{
    if( (row >= 0) && (row < rowCount()) )
        return static_cast<QPireWidget*>(cellWidget(row, 0))->pire();
    return -1;
}

int QFrequencyTable::freqMin(int row)
{
    if( (row >= 0) && (row < rowCount()) )
        return static_cast<QFreqWidget*>(cellWidget(row, 1))->frequency();
    return -1;
}

int QFrequencyTable::freqMax(int row)
{
    if( (row >= 0) && (row < rowCount()) )
        return static_cast<QFreqWidget*>(cellWidget(row, 2))->frequency();
    return -1;
}

int QFrequencyTable::freqInc(int /*row*/)
{
    return FREQ_INC;
}
