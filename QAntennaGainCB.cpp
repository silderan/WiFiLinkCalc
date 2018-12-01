#include "AntennaGain.h"

QAntennaGainCB::QAntennaGainCB(QWidget *papi) : QComboBox(papi)
{
	connect( this, SIGNAL(currentIndexChanged(int)), this, SLOT(onIndexChanged(int)) );
}

QAntennaGainCB::~QAntennaGainCB()
{

}

void QAntennaGainCB::setup(const QAntennaDataList &antDataList, const QString newAntenaModel)
{
	blockSignals(true);
    QString oldModel = newAntenaModel.isEmpty() ? currentModelName() : newAntenaModel;
	clear();

    for( int i = 0; i < antDataList.count(); i++ )
        addItem(antDataList[i].modelName(), antDataList[i].gain());

	blockSignals(false);
    selectAntenaModel(oldModel);
    if( (currentIndex() == -1) && count() )
        setCurrentIndex(0);
}

void QAntennaGainCB::selectAntenaModel(const QString &antennaModel)
{
    setCurrentIndex( findText(antennaModel) );
}

void QAntennaGainCB::onIndexChanged(int /*index*/)
{
    static quint32 oldGain = 0;
    if( oldGain != currentGain() )
        emit gainChanged( currentGain() );
}
