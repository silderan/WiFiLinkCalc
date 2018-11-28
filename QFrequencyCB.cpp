#include "FrequencyPIRE.h"

#define KEY_PIRES	("PIRES")
#define KEY_FLIST	("freq-list")
#define KEY_CURFR	("freq-curr")

void QFrequencyComboBox::getSaveData(QIniData &data) const
{
	data[KEY_PIRES] = QStringList(m_frequencyMap.values()).join(',');
	data[KEY_FLIST] = QStringList(m_frequencyMap.keys()).join(',');
	data[KEY_CURFR] = currentFrequency();
}

void QFrequencyComboBox::loadSaveData(const QIniData &data)
{
	QStringList pires = data[KEY_PIRES].split(',');
	QStringList freqs = data[KEY_FLIST].split(',');

	if( pires.count() != freqs.count() )
	{
		emit frequencyCBError( "QFrequencyList::loadSaveData", tr("Formato erroneo en los datos leídos"), tr("La cantidad de PIRES no es la misma que la cantidad de frecuencias."));
		while( pires.count() > freqs.count() )
			freqs.append(QString("%1").arg(freqs.last().toInt()+5));
		while( freqs.count() > pires.count() )
			pires.append( pires.last() );
	}
	m_frequencyMap.clear();
	m_PIREMap.clear();
	bool ok;
	for( int i = 0; i < pires.count(); i++ )
	{
		pires[i].toInt(&ok);
		if( !ok )
			emit frequencyCBError( "QFrequencyList::loadSaveData", tr("Formato erroneo en los datos leídos"), tr("No se puede convertir a número entero el pire %1 de la frecuencia %2").arg(pires[i],freqs[i]));
		else
		{
			m_frequencyMap[freqs[i]] = pires[i];
			m_PIREMap[pires[i]].append(freqs[i]);
		}
	}
	refreshItems();
	setCurrentIndex(findText(data[KEY_CURFR]));
}

void QFrequencyComboBox::onNewFreqSelected(QString freq)
{
	static int oldPIRE = 0;
	int newPIRE = getPIRE(freq);
	if( newPIRE != oldPIRE )
		emit pireChanged(oldPIRE = newPIRE);
}

void QFrequencyComboBox::refreshItems()
{
	blockSignals(true);

	QString oldFrequency = currentText();
	int oldIndex = currentIndex();
	int oldPIRE = currentPIRE();
	clear();
	addItems(m_frequencyMap.keys());
	blockSignals(false);

	int newIndex = findText( oldFrequency );
	if( newIndex != -1 )
		setCurrentIndex( newIndex );
	else
		setCurrentIndex( oldIndex );
	if( oldPIRE != currentPIRE() )
		emit pireChanged(currentPIRE());
}

void QFrequencyComboBox::setPIREMap(const QPIREMap &pireMAP)
{
	m_PIREMap = pireMAP;
	m_frequencyMap.clear();
	QPIREMapIterator it(pireMAP);
	while( it.hasNext() )
	{
		it.next();
		foreach( QString freq, it.value() )
		{
			m_frequencyMap[freq] = it.key();
		}
	}
	refreshItems();
}

QFrequencyComboBox::QFrequencyComboBox(QWidget *parent) : QComboBox(parent)
{
	connect( this, SIGNAL(currentTextChanged(QString)), this, SLOT(onNewFreqSelected(QString)) );
}

QFrequencyComboBox::~QFrequencyComboBox()
{
}

