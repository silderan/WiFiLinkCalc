#ifndef FREQUENCYPIRE
#define FREQUENCYPIRE

#include <QStringList>
#include <QTableWidget>
#include <QComboBox>
#include <QSpinBox>
#include <QMap>

#include "QIniFile.h"

#define FREQ_INC (5)

typedef QMap<QString, QString> QFrequencyMap;
typedef QMapIterator<QString, QString> QFrequencyMapIterator;

typedef QMap<QString, QStringList> QPIREMap;
class  QPIREMapIterator: public QMapIterator<QString, QStringList>
{
public:
    QPIREMapIterator(const QPIREMap &map) : QMapIterator(map)
    {   }
    const QString &pire() const          { return key();   }
    const QStringList &frequencyList() const  { return value(); }
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
    template <class T>
    QFreqWidget(T freq, QWidget *papi = nullptr ) : QSpinBox(papi)
    {
        setRange(0, 6000);
        setFrequency(freq);
        setSuffix(" Mhz");
        setSingleStep( FREQ_INC );
    }
    void setFrequency(int fr)				{ setValue(fr);				}
    void setFrequency(const QString &fr)	{ setFrequency(fr.toInt()); }
    int frequency() const	{ return value();	}
};

class QFrequencyComboBox : public QComboBox
{
	Q_OBJECT
	QFrequencyMap m_frequencyMap;
	QPIREMap m_PIREMap;

public:
    explicit QFrequencyComboBox(QWidget *parent = nullptr);
	~QFrequencyComboBox();

	int getPIRE(const QString &fr) const	{ return m_frequencyMap[fr].toInt();	}
	QString currentFrequency() const		{ return currentText();					}
	int currentPIRE() const					{ return getPIRE(currentFrequency());	}

	const QPIREMap &pireMap() const			{ return m_PIREMap;	}

	void getSaveData(QIniData &data) const;
	void loadSaveData(const QIniData &data);

private slots:
	void onNewFreqSelected(QString freq);

signals:
	void frequencyCBError(const QString &fnc, const QString &titulo, const QString &description);
	void pireChanged(int pire);

public slots:
	void refreshItems();
	void setPIREMap( const QPIREMap &pireMAP );
};

class QFrequencyTable : public QTableWidget
{
public:
    QFrequencyTable(QWidget *papi = nullptr);
    void fromPIREMap(const QPIREMap &map);
    int addRow(int pire, int min, int max);
    int addRow(const QString pire, int min, int max)
    { return addRow(pire.toInt(), min, max);}

    int pire(int row);
    int freqMin(int row);
    int freqMax(int row);
    int freqInc(int);
};

#endif // FREQUENCYPIRE
