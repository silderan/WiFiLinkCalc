#include "FrequencyPIRE.h"

void QFrequencyComboBox::setup(const QFrequencyPireList &freqPIREList, quint32 frequencyStep, QString frequencySelected)
{
    if( frequencySelected.isEmpty() )
        frequencySelected = currentText();
    blockSignals(true);
    clear();
    m_freqStep = frequencyStep;
    for( int i = 0; i < freqPIREList.count(); i++ )
    {
        for( quint32 frequency = freqPIREList[i].initialFrequency(); frequency <= freqPIREList[i].endFrequency(); frequency += frequencyStep )
            addItem( QString("%1").arg(frequency), freqPIREList[i].frequencyPIRE() );
    }
    blockSignals(false);
    selectFrequency(frequencySelected);
    if( (currentIndex() == -1) && count() )
        setCurrentIndex(0);
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
