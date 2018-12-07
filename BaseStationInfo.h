#ifndef BASESTATIONINFO_H
#define BASESTATIONINFO_H

#include <QStringList>
#include <QMap>

struct BaseStation
{
    QString m_id;
    QString m_name;

    BaseStation()
    {    }
    BaseStation(const BaseStation &bs) :
        m_id(bs.m_id),
        m_name(bs.m_name)
    {

    }
    BaseStation(const QString &id, const QString &name) :
        m_id(id),
        m_name(name)
    {

    }
};

class QBaseStationMap : public QMap<QString, BaseStation>
{
public:
    void add(const BaseStation &bs)                     { insert(bs.m_id, bs); }
    void add(const QString &id, const QString &name)    { add(BaseStation(id, name)); }
};
typedef QMapIterator<QString, BaseStation> QBaseStationMapIterator;

struct Panel
{
    QString m_bsID; // Identificador de la estación base.
    QString m_name;
    QString m_ssid;
    QString m_description;
    QString m_degrees;
    QString m_freq;
	QString m_gain;
    QString m_power;

    explicit Panel()
    {   }
    Panel(const Panel &panel) :
        m_bsID(panel.m_bsID),
		m_name(panel.m_name),
        m_ssid(panel.m_ssid),
        m_description(panel.m_description),
        m_degrees(panel.m_degrees),
        m_freq(panel.m_freq),
		m_gain(panel.m_gain),
		m_power(panel.m_power)
    {   }
    Panel(const QString &bsID, const QString &name, const QString &ssid, const QString &description, const QString &degrees, const QString &freq, const QString &gain, const QString &power) :
        m_bsID(bsID),
		m_name(name),
        m_ssid(ssid),
        m_description(description),
        m_degrees(degrees),
		m_freq(freq),
		m_gain(gain),
		m_power(power)
    {   }

    // The ID of the panel is, for now, the degrees and gain.
    QString panelID() const { return QString("%1-%2").arg(m_degrees, m_gain);   }
};

class QPanelMap : public QMap<QString, Panel>
{

public:
    QPanelMap();
    void add(const Panel &panel)    { insert(panel.m_name, panel); }
    void loadPanelsCSV(const QString &fname);
};
typedef QMapIterator<QString, Panel> QPanelMapIterator;

#include <QTableWidget>
class QBaseStationTable : public QTableWidget
{

public:
	QBaseStationTable(QWidget *papi = Q_NULLPTR);
    void addRow(const QString &id = QString(), const QString &name = QString());
    void setup(const QBaseStationMap &bsMap);
    QBaseStationMap save() const;
};


#include <QComboBox>
class QPanelCB : public QComboBox
{
    enum col
    {
        ID = Qt::UserRole,
        Name,
        SSID,
        Description,
        Degrees,
        Frequency,
        Gain,
        Power,
        BaseStationID
    };

    QString currentData(col c) const  { return itemData(currentIndex(), c).toString(); }
public:
    QPanelCB(QWidget *papi = Q_NULLPTR);
    void selectPanel(const QString &panelID);

    QString currentID() const               { return currentData(ID);   }
    QString currentName() const             { return currentData(Name);	}
    QString currentSSID() const             { return currentData(SSID);	}
    QString currentDescription() const      { return currentData(Description);	}
    QString currentDegrees()                { return currentData(Degrees);	}
    QString currentFrequency()              { return currentData(Frequency);	}
    QString currentGain()                   { return currentData(Gain);	}
    QString currentPower()                  { return currentData(Power);	}
    QString currentBaseStationID() const	{ return currentData(BaseStationID);	}
    void setup(const QPanelMap &panelMap, const QBaseStationMap bsMap, const QString &newBSName = QString());

};

#endif // BASESTATIONINFO_H
