#include "AntennaGain.h"

QAntennaGainCB::QAntennaGainCB(QWidget *papi) : QComboBox(papi)
{
	connect( this, SIGNAL(currentIndexChanged(int)), this, SLOT(onIndexChanged(int)) );
}

QAntennaGainCB::~QAntennaGainCB()
{

}

void QAntennaGainCB::setup(const QAntennaDataList &antDataList)
{
	blockSignals(true);
	QString oldModel = currentModelName();
	clear();

    for( int i = 0; i < antDataList.count(); i++ )
	{
		addItem(antDataList[i].modelName(), antDataList[i].gain());
		setItemData(i, antDataList[i].id(), Qt::UserRole+1);
		setItemData(i, antDataList[i].gain(), Qt::UserRole+2);
	}

    selectAntenaModel(oldModel);
    if( (currentIndex() == -1) && count() )
		setCurrentIndex(0);
	blockSignals(false);
	if( currentIndex() != -1 )
		onIndexChanged(currentIndex());
}

void QAntennaGainCB::selectAntenaModel(const QString &antennaModel)
{
	setCurrentIndex( findText(antennaModel) );
}

void QAntennaGainCB::selectAntenaModel(const QString &modelID, const QString &gain)
{
	for( int i = 0; i < count(); i++ )
		if( (itemData(i, Qt::UserRole+1).toString() == modelID) && (itemData(i, Qt::UserRole+2).toString() == gain) )
			setCurrentIndex(i);
}

void QAntennaGainCB::onIndexChanged(int index)
{
	emit gainChanged( gain(index) );
}
