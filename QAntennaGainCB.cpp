#include "AntennaGain.h"

#define KEY_ANTMODL	("ANT-MODLS")
#define KEY_ANTGAIN ("ANT-GAINS")
#define KEY_ANTCURR	("ANT_CURRE")

QAntennaGainCB::QAntennaGainCB(QWidget *parent) : QComboBox(parent)
{
	connect( this, SIGNAL(currentIndexChanged(int)), this, SLOT(onIndexChanged(int)) );
}

QAntennaGainCB::~QAntennaGainCB()
{

}

void QAntennaGainCB::getSaveData(QIniData &data) const
{
	QStringList antModls;
	QStringList antGains;

	for( int i = 0; i < count(); i++ )
	{
		antModls.append(model(i));
		antGains.append(QString("%1").arg(gain(i)));
	}
	data[KEY_ANTCURR] = currentModel();
	data[KEY_ANTGAIN] = antGains.join(',');
	data[KEY_ANTMODL] = antModls.join(',');
}

void QAntennaGainCB::loadSaveData(const QIniData &data)
{
	QAntennaGainMap antGainMap;
	QStringList antModls = data[KEY_ANTMODL].split(',');
	QStringList antGains = data[KEY_ANTGAIN].split(',');

	for( int i = 0; i < antModls.count(); i++ )
		antGainMap[antModls[i]] = antGains[i].toUInt();

	setAntennaGainMap(antGainMap);
}

QAntennaGainMap QAntennaGainCB::antennaGainMap() const
{
	QAntennaGainMap rtn;
	for( int i = 0; i < count(); i++ )
		rtn[itemText(i)] = itemData(i).toInt();
	return rtn;
}

void QAntennaGainCB::setAntennaGainMap(const QAntennaGainMap &antGainMap)
{
	QAntennaGainMapIterator it(antGainMap);
	blockSignals(true);
	QString oldModel = currentModel();
	clear();

	while( it.hasNext() )
	{
		it.next();
		addItem(it.key(), it.value());
	}

	setCurrentIndex(findText(oldModel));
	blockSignals(false);
	onIndexChanged(currentIndex());
}

void QAntennaGainCB::onIndexChanged(int index)
{
	emit gainChanged( itemData(index).toInt() );
}
