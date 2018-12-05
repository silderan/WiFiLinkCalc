#include "BaseStationInfo.h"

#include "qcsv.h"

QBaseStationInfo::QBaseStationInfo()
{

}

void QBaseStationInfo::loadPanelsCSV(const QString &fname)
{
    CSVData csvData = QCSV::load(fname);
    m_baseStationMap.clear();

    if( csvData.count() < 2 )
        return;
    // The first file is (must be) the name of the colums.
    // So, lets search for the names we need.
    int panelNameCol = csvData[0].indexOf("Device Name");
    int frequencyCol = csvData[0].indexOf("Frequency");
    int descriptionCol = csvData[0].indexOf("Description");

    if( panelNameCol == -1 )
        // TODO: warning!
        return;
    if( frequencyCol == -1 )
        // TODO: warning!
        return;
    if( descriptionCol == -1 )
        // TODO: warning!
        return;
    foreach( QStringList panelData, csvData )
    {
        // Let's find out the data in the name.
        // It's encoded like <EBNumber><Orientation>-<Degrees>-<AntennaGain>-<txPower>
        QString panelName = panelData[panelNameCol];
        QStringList ll = panelData[panelNameCol].split('-');
        if( ll.count() == 4 )
        {
            int i = 0;
            while( isdigit(ll[0][i].toLatin1()) )
                i++;
            if( i != 0 )
            {
                QString baseName = ll[0].left(i);
                QString panelDir = ll[0].right(ll[0].length()-i);
                QString frequency = panelData[frequencyCol];
                frequency = frequency.replace(" MHz", "");
                m_baseStationMap.addPanel( baseName, panelName, panelData[descriptionCol], frequency, ll[2] );
            }
        }
    }
}
