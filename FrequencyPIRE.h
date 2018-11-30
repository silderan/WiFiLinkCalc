#ifndef FREQUENCYPIRE
#define FREQUENCYPIRE

#include <QStringList>
#include <QTableWidget>
#include <QComboBox>
#include <QSpinBox>
#include <QMap>

#include "QIniFile.h"

#define FREQ_INC (5)

class FrequencyPire
{
    quint32 m_iniFrequency;
    quint32 m_endFrequency;
    qint32 m_pire;

public:
    FrequencyPire()
        : m_iniFrequency(0),
          m_endFrequency(0),
          m_pire(0)
    {   }
    FrequencyPire(quint32 initialFrequency, quint32 endFrequency, qint32 pire)
        : m_iniFrequency(initialFrequency),
          m_endFrequency(endFrequency),
          m_pire(pire)
    {   }
    quint32 initialFrequency() const                            { return m_iniFrequency; }
    void setInitialFrequency(const quint32 &initialFrequency)   { m_iniFrequency = initialFrequency; }

    quint32 endFrequency() const                        { return m_endFrequency; }
    void setEndFrequency(const quint32 &endFrequency)   { m_endFrequency = endFrequency; }

    qint32 frequencyPIRE() const                    { return m_pire; }
    void setFrequencyPire(const qint32 &pire)       { m_pire = pire; }
};

class QFrequencyPireList : public QList<FrequencyPire>
{
public:
    void append(const FrequencyPire &fp)
    {
        QList::append( fp );
    }
    void append(quint32 initialFrequency, quint32 endFrequency, qint32 pire)
    {
        QList::append( FrequencyPire(initialFrequency, endFrequency, pire) );
    }
};

class QPireWidget : public QSpinBox
{
public:
    QPireWidget(int pire, QWidget *papi = nullptr) : QSpinBox(papi)
    {
        setRange(0, 100);
        setPire(pire);
        setSuffix(" dBm");
    }
    int pire() const { return value();	}
    void setPire(int pire)	{ setValue(pire); }
};

class QFreqWidget : public QSpinBox
{
public:
    QFreqWidget(QWidget *papi = nullptr ) : QSpinBox(papi)
    {   }
    template <class T>
    QFreqWidget(T freq, QWidget *papi = nullptr ) : QSpinBox(papi)
    {
        setRange(0, 6000);
        setFrequency(freq);
        setSuffix(" Mhz");
        setSingleStep( FREQ_INC );
    }
    void setFrequency(quint32 fr)				{ setValue(static_cast<int>(fr));}
    void setFrequency(const QString &fr)        { setFrequency(fr.toUInt());    }
    quint32 frequency() const	{ return static_cast<quint32>(value());	}
};

class QFrequencyComboBox : public QComboBox
{
	Q_OBJECT
    quint32 m_freqStep; // The Mhz to create all available selectable frequencies in combo box.

public:
    explicit QFrequencyComboBox(QWidget *parent = nullptr);
	~QFrequencyComboBox();

    int pire(int index) const           { return ((index >= 0) && (index < count())) ? itemData(index).toInt() : 0; }
    int pire(const QString &fr) const	{ return pire(findText(fr));    }
    QString currentFrequency() const	{ return currentText();			}
    int currentPIRE() const				{ return pire(currentIndex());	}
    quint32 frequencyStep() const       { return m_freqStep;            }

    void load(const QFrequencyPireList &freqPIREList, quint32 frequencyStep, QString frequencySelected = QString());


private slots:
    void onNewFreqSelected(int index);

public slots:
    void selectFrequency(const QString &fr);

signals:
	void pireChanged(int pire);
};

class QFrequencyTable : public QTableWidget
{
public:
    QFrequencyTable(QWidget *papi = nullptr);

    void load(const QFrequencyPireList &freqPIREList);
    QFrequencyPireList save() const;

    int addRow(quint32 ini = 0, quint32 end = 0, qint32 pire = 0);
    int addRow(const FrequencyPire &freqPire)
        { return addRow(freqPire.initialFrequency(), freqPire.endFrequency(), freqPire.frequencyPIRE());    }

    int pire(int row) const;
    quint32 iniFrequency(int row) const;
    quint32 endFrequency(int row) const;
};

#endif // FREQUENCYPIRE

