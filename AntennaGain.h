#ifndef ANTENNAGAIN_H
#define ANTENNAGAIN_H

#include <QTableWidget>
#include <QComboBox>
#include <QMap>

#include "QIniFile.h"

class AntennaData
{
    QString m_modelName;
    quint32 m_gain;
public:
    AntennaData() :
        m_gain(0)
    {   }
    AntennaData(const QString modelName, quint32 gain) :
        m_modelName(modelName),
        m_gain(gain)
    {   }

    QString modelName() const                   { return m_modelName;   }
    void setModelName(const QString &modelName) { m_modelName = modelName;  }

    quint32 gain()const                 { return m_gain;    }
    void setGain(const quint32 &gain)   { m_gain = gain;    }
};

class QAntennaDataList : public QList<AntennaData>
{
public:
    void append(const AntennaData &ad)
    {
        QList::append( ad );
    }
    void append(const QString &modelName, quint32 gain)
    {
        QList::append( AntennaData(modelName, gain) );
    }
};

class QAntennaGainCB : public QComboBox
{
    Q_OBJECT

public:
    explicit QAntennaGainCB(QWidget *papi = Q_NULLPTR);
	~QAntennaGainCB();

	QString model(int index) const	{ return itemText(index);	}
	QString currentModelName() const	{ return currentText();	}
	quint32 gain(int index) const	{ return itemData(index).toUInt();	}
	quint32 currentGain() const		{ return itemData(currentIndex()).toUInt();	}

    void setup(const QAntennaDataList &antDataList);

signals:
	void gainChanged(quint32);

public slots:
    void selectAntenaModel(const QString &antennaModel);
private slots:
	void onIndexChanged(int index);
};

class QAntennaGainTable : public QTableWidget
{
	Q_OBJECT

public:
    explicit QAntennaGainTable(QWidget *papi = Q_NULLPTR);
	~QAntennaGainTable();

	quint32 gain(const QString &model) const;
	quint32 gain(int row) const;
	QString model(int row) const;

public slots:
    void addRow(const QString &antenaModel = QString(), quint32 gain = 0);
    void addRow(const AntennaData &antData)
        {   addRow(antData.modelName(), antData.gain());    }
    void load(const QAntennaDataList &antDataList);
    QAntennaDataList save() const;

signals:
    void gainChanged(quint32 gain);
};

#endif // ANTENNAGAIN_H

