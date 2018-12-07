#ifndef BASESTATIONINFO_H
#define BASESTATIONINFO_H

#include <QStringList>
#include <QMap>

struct Panel
{
    QString m_name;
	QString m_modelName;
	QString m_modelID;
    QString m_freq;
	QString m_gain;
    QString m_power;
    Panel()
    {   }
    Panel(const Panel &panel) :
		m_name(panel.m_name),
		m_modelName(panel.m_modelName),
		m_modelID(panel.m_modelID),
		m_freq(panel.m_freq),
		m_gain(panel.m_gain),
		m_power(panel.m_power)
    {   }
	Panel(const QString &name, const QString &modelName, const QString &modelID, const QString &freq, const QString &gain, const QString &power) :
		m_name(name),
		m_modelName(modelName),
		m_modelID(modelID),
		m_freq(freq),
		m_gain(gain),
		m_power(power)
    {   }
};

class QPanelMap : public QMap<QString, Panel>
{
public:
	Panel panel(const QString &panelName) const		{ return value(panelName);  }

    void addPanel(const Panel &panel)
    {   insert(panel.m_name, panel);    }

	void addPanel(const QString &name, const QString &modelName, const QString &modelID, const QString &frequency, const QString &gain, const QString &outPower)
	{   addPanel( Panel(name, modelName, modelID, frequency, gain, outPower)); }

	QString modelName(const QString &name) const	{ return panel(name).m_modelName;	}
	QString modelID(const QString &name) const		{ return panel(name).m_modelID;		}
	QString frequency(const QString &name) const	{ return panel(name).m_freq;		}
	QString outPower(const QString &name) const		{ return panel(name).m_power;		}
	QString gain(const QString &name) const			{ return panel(name).m_gain;		}

	QStringList panelNames() const				{ return keys();    }
};
typedef QMapIterator<QString, Panel> QPanelMapIterator;

class QBaseStationPanelMap : public QMap<QString, QPanelMap>
{

public:
    void addPanel(const QString &baseStationName, const Panel &panel)
		{ (*this)[baseStationName].addPanel(panel); }
	void addPanel(const QString &baseStationName, const QString &name, const QString &modelName, const QString &modelID, const QString &freq, const QString &gain, const QString power)
		{ addPanel(baseStationName, Panel(name, modelName, modelID, freq, gain, power)); }

	QStringList baseStationNames() const				{ return keys();    }
	QStringList panelNames(const QString &bsName) const	{ return value(bsName).panelNames();   }

	QString frequency(const QString &bsName, const QString &panelName)	{ return (*this)[bsName].frequency(panelName);	}
	QString modelName(const QString &bsName, const QString &panelName)	{ return (*this)[bsName].modelName(panelName);	}
	QString modelID(const QString &bsName, const QString &panelName)	{ return (*this)[bsName].modelID(panelName);	}
	QString gain(const QString &bsName, const QString &panelName)		{ return (*this)[bsName].gain(panelName);	}
};

class QBaseStationNameMap : public QMap<QString, QString>
{

public:
	void add(const QString &id, const QString &name)
	{	insert(id, name);	}
	QString name(const QString &id) const	{ return value(id);	}
	const QList<QString> names() const	{ return values();	}
	const QList<QString> ids() const	{ return keys();	}
};

class QBaseStationInfo
{
	QBaseStationPanelMap m_bsPanelMap;

public:
	QStringList baseStationIDs() const { return m_bsPanelMap.baseStationNames();  }
	QStringList panelNames(const QString &bsName)						{ return m_bsPanelMap.panelNames(bsName);   }
	QString frequency(const QString &bsID, const QString &panelName)	{ return m_bsPanelMap.frequency(bsID, panelName); }
	QString modelName(const QString &bsID, const QString &panelName)	{ return m_bsPanelMap.modelName(bsID, panelName); }
	QString modelID(const QString &bsID, const QString &panelName)		{ return m_bsPanelMap.modelID(bsID, panelName); }
	QString gain(const QString bsID, const QString &panelName)			{ return m_bsPanelMap.gain(bsID, panelName); }
	QBaseStationInfo();
    void loadPanelsCSV(const QString &fname);
};

#include <QTableWidget>
class QBaseStationTable : public QTableWidget
{

public:
	QBaseStationTable(QWidget *papi = Q_NULLPTR);
	void addRow(const QString &id = QString(), const QString &name = QString());
	void setup(const QBaseStationNameMap &baseStationMap);
	QBaseStationNameMap save() const;
};

#include <QComboBox>
class QBaseStationCB : public QComboBox
{
	Q_OBJECT

public:
	explicit QBaseStationCB(QWidget *papi = Q_NULLPTR);
	~QBaseStationCB()
	{	}
	void selectBaseStation(const QString &baseStationID);
	QString currentBaseStationID() const	{ return currentData().toString();	}
	QString currentBaseStationName() const	{ return currentText();	}
	void setup(const QBaseStationInfo &bsInfo, const QBaseStationNameMap &bsMap, const QString &newBSName = QString());

public slots:
	void onNewBaseSelected(int index);

signals:
	void newBaseStationSelected(const QString &id);
};

class QPanelCB : public QComboBox
{

public:
	QPanelCB(QWidget *papi = Q_NULLPTR);
	void selectPanel(const QString &panelName);
	QString currentPanelName() const { return currentText();	}
};

#endif // BASESTATIONINFO_H
