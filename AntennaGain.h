#ifndef ANTENNAGAIN_H
#define ANTENNAGAIN_H

#include <QTableWidget>
#include <QComboBox>
#include <QMap>

#include "QIniFile.h"

typedef QMap<QString, quint32> QAntennaGainMap;

class QAntennaGainMapIterator : public QMapIterator<QString, quint32>
{
public:
	QAntennaGainMapIterator(const QAntennaGainMap &map) : QMapIterator(map)
	{	}
	const QString name() const	{ return key();		}
	quint32 gain() const		{ return value();	}
};

class QAntennaGainCB : public QComboBox
{
	Q_OBJECT

public:
	explicit QAntennaGainCB(QWidget *parent = 0);
	~QAntennaGainCB();

	void getSaveData(QIniData &data) const;
	void loadSaveData(const QIniData &data);

	QString model(int index) const	{ return itemText(index);	}
	QString currentModel() const	{ return currentText();	}
	quint32 gain(int index) const	{ return itemData(index).toUInt();	}
	quint32 currentGain() const		{ return itemData(currentIndex()).toUInt();	}

	QAntennaGainMap antennaGainMap()const;
	void setAntennaGainMap(const QAntennaGainMap &antGainMap);
signals:
	void gainChanged(quint32);

private slots:
	void onIndexChanged(int);
};

class QAntennaGainTable : public QTableWidget
{
	Q_OBJECT

public:
	explicit QAntennaGainTable(QWidget *parent = 0);
	~QAntennaGainTable();

	quint32 gain(const QString &model) const;
	quint32 gain(int row) const;
	QString model(int row) const;

public slots:
	void addRow(const QString &model = QString(), quint32 gain = 0);
	void fromMap(const QAntennaGainMap &map);
	bool toMap(QAntennaGainMap &map) const;

signals:
	void error(const QString &context, const QString &desc) const;
};

#endif // ANTENNAGAIN_H
