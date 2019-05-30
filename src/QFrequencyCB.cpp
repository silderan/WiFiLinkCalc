#include "FrequencyPIRE.h"

void QFrequencyComboBox::setup(const QFrequencyPireList &freqPIREList, quint32 frequencyStep)
{
	QString frequencySelected = currentFrequency();
    blockSignals(true);
    clear();
	Q_ASSERT_X( frequencyStep > 0, __FUNCTION__, "Frequency step must be greater than 0" );
    m_freqStep = frequencyStep;
    for( int i = 0; i < freqPIREList.count(); i++ )
    {
		Q_ASSERT_X( freqPIREList[i].initialFrequency() <= freqPIREList[i].endFrequency(), __FUNCTION__, "initial frequency must be smaller or equal to end frequency" );
        for( quint32 frequency = freqPIREList[i].initialFrequency(); frequency <= freqPIREList[i].endFrequency(); frequency += frequencyStep )
            addItem( QString("%1").arg(frequency), freqPIREList[i].frequencyPIRE() );
    }
    selectFrequency(frequencySelected);
    if( (currentIndex() == -1) && count() )
        setCurrentIndex(0);
	blockSignals(false);
	if( currentIndex() != -1 )
		onNewFreqSelected(currentIndex());
}

void QFrequencyComboBox::onNewFreqSelected(int index)
{
    emit pireChanged(pire(index));
}

void QFrequencyComboBox::selectFrequency(const QString &fr)
{
    setCurrentIndex(findText(fr));
}

QFrequencyComboBox::QFrequencyComboBox(QWidget *parent) : QComboBox(parent)
{
    connect( this, SIGNAL(currentIndexChanged(int)), this, SLOT(onNewFreqSelected(int)) );
}

QFrequencyComboBox::~QFrequencyComboBox()
{
}
