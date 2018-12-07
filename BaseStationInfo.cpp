#include "BaseStationInfo.h"

#include "qcsv.h"

QBaseStationInfo::QBaseStationInfo()
{

}

void QBaseStationInfo::loadPanelsCSV(const QString &fname)
{
    CSVData csvData = QCSV::load(fname);
	m_bsPanelMap.clear();

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
			while( isalpha(ll[0][i].toLatin1()) )
				i++;
            while( isdigit(ll[0][i].toLatin1()) )
                i++;
			if( isalpha(ll[0][i].toLatin1()) )
            {
				QString description = panelData[descriptionCol];
				QString bsID = ll[0].left(i);
				QString frequency = panelData[frequencyCol].replace(" MHz", "");
				QString panelID = ll[1];
				QString gain = ll[2];
				QString power = ll[3];

				m_bsPanelMap.addPanel( bsID, panelName, description, panelID, frequency, gain, power );
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

	insertRow(row);
	setItem(row, 0, new QTableWidgetItem(id));
	setItem(row, 1, new QTableWidgetItem(name));
}

void QBaseStationTable::setup(const QBaseStationNameMap &baseStationMap)
{
	QMapIterator<QString, QString> it(baseStationMap);

	setColumnCount(2);
	setHorizontalHeaderLabels( QStringList() << tr("ID") << tr("Nombre") );
	while( it.hasNext() )
	{
		it.next();
		addRow(it.key(), it.value());
	}
}

QBaseStationNameMap QBaseStationTable::save() const
{
	QBaseStationNameMap bsm;

	for( int row = 0; row < rowCount(); row++ )
		bsm.add(item(row, 0)->text(), item(row, 1)->text());

	return bsm;
}

QBaseStationCB::QBaseStationCB(QWidget *papi) :
	QComboBox(papi)
{
	connect( this, SIGNAL(currentIndexChanged(int)), this, SLOT(onNewBaseSelected(int)) );
}

void QBaseStationCB::selectBaseStation(const QString &baseStationID)
{
	for( int i = 0; i < count(); i++ )
		if( itemData(i).toString() == baseStationID )
			setCurrentIndex(i);
}

void QBaseStationCB::setup(const QBaseStationInfo &bsInfo, const QBaseStationNameMap &bsMap, const QString &newBaseStationID)
{
	blockSignals(true);
	clear();
	foreach( QString id, bsInfo.baseStationIDs() )
		addItem( bsMap.contains(id) ? QString("EB%1 - %2").arg(id, bsMap.name(id)) : QString("EB%1").arg(id), id );
	blockSignals(false);
	if( !newBaseStationID.isEmpty() )
		selectBaseStation(newBaseStationID);
	else
		onNewBaseSelected(currentIndex());
}

void QBaseStationCB::onNewBaseSelected(int /*index*/)
{
	emit newBaseStationSelected( currentBaseStationID() );
}

QPanelCB::QPanelCB(QWidget *papi) :
	QComboBox(papi)
{

}

void QPanelCB::selectPanel(const QString &panelName)
{
	int i = findText(panelName);
	if( i != -1 )
		setCurrentIndex( i );
}
