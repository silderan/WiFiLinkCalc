#include "BaseStationInfo.h"

#include "qcsv.h"

QPanelMap::QPanelMap()
{

}

void QPanelMap::loadPanelsCSV(const QString &fname)
{
    CSVData csvData = QCSV::load(fname);
    clear();

    if( csvData.count() < 2 )
        return;
    // The first file is (must be) the name of the colums.
    // So, lets search for the names we need.
    int panelNameCol = csvData[0].indexOf("Device Name");
    int frequencyCol = csvData[0].indexOf("Frequency");
    int descriptionCol = csvData[0].indexOf("Description");
    int ssidCol = csvData[0].indexOf("SSID");

    if( panelNameCol == -1 )
        // TODO: warning!
        return;
    if( frequencyCol == -1 )
        // TODO: warning!
        return;
    if( descriptionCol == -1 )
        // TODO: warning!
        return;
    if( ssidCol == -1 )
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
            while( (1 < ll[0].count()) && isalpha(ll[0][i].toLatin1()) )
				i++;
            while( (1 < ll[0].count()) && isdigit(ll[0][i].toLatin1()) )
                i++;
            if( (1 < ll[0].count()) && isalpha(ll[0][i].toLatin1()) )
            {
				QString description = panelData[descriptionCol];
				QString bsID = ll[0].left(i);
				QString frequency = panelData[frequencyCol].replace(" MHz", "");
                QString degrees = ll[1];
				QString gain = ll[2];
				QString power = ll[3];
                QString ssid = panelData[ssidCol];

                add( Panel(bsID, panelName, ssid, description, degrees, frequency, gain, power) );
            }
        }
    }
}

QBaseStationTable::QBaseStationTable(QWidget *papi) :
	QTableWidget(papi)
{

}

void QBaseStationTable::addRow(const QString &id, const QString &name)
{
	int row = rowCount();

    insertRow( row );
    setItem( row, 0, new QTableWidgetItem(id) );
    setItem( row, 1, new QTableWidgetItem(name) );
}

void QBaseStationTable::setup(const QBaseStationMap &bsMap)
{
    QBaseStationMapIterator it(bsMap);

	setColumnCount(2);
	setHorizontalHeaderLabels( QStringList() << tr("ID") << tr("Nombre") );
	while( it.hasNext() )
	{
		it.next();
        addRow(it.value().m_id, it.value().m_name);
	}
}

QBaseStationMap QBaseStationTable::save() const
{
    QBaseStationMap bsm;

	for( int row = 0; row < rowCount(); row++ )
    {
        QString id = item(row, 0)->text();
        QString name = item(row, 1)->text();
        if( id.isEmpty() && !name.isEmpty() )
            bsm.add( id, name );
    }

	return bsm;
}

QPanelCB::QPanelCB(QWidget *papi) :
	QComboBox(papi)
{
}

void QPanelCB::selectPanel(const QString &panelID)
{
	for( int i = 0; i < count(); i++ )
        if( itemData(i, ID).toString() == panelID )
			setCurrentIndex(i);
}

void QPanelCB::setup(const QPanelMap &panelMap, const QBaseStationMap bsMap, const QString &newBaseStationID)
{
	blockSignals(true);
	clear();
    QPanelMapIterator it(panelMap);
    for( int i = 0; it.hasNext(); i++ )
    {
        it.next();
        BaseStation bs = bsMap[it.value().m_bsID];
        QString visibleName = QString("%1\t(%2)").arg(it.value().m_ssid, it.value().m_description);
        addItem( visibleName );
        setItemData( i, it.value().m_bsID, ID );
        setItemData( i, it.value().m_degrees, Degrees );
        setItemData( i, it.value().m_description, Description );
        setItemData( i, it.value().m_freq, Frequency );
        setItemData( i, it.value().m_gain, Gain );
        setItemData( i, it.value().m_name, Name );
        setItemData( i, it.value().m_power, Power );
        setItemData( i, it.value().m_ssid, SSID );
    }
	blockSignals(false);
	if( !newBaseStationID.isEmpty() )
        selectPanel(newBaseStationID);
	else
        emit currentIndexChanged(currentIndex());
}
