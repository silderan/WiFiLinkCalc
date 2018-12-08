#ifndef BASESTATIONINFO_H
#define BASESTATIONINFO_H

#include <QStringList>
#include <QMap>

struct Panel
{
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
		m_name(panel.m_name),
        m_ssid(panel.m_ssid),
        m_description(panel.m_description),
        m_degrees(panel.m_degrees),
        m_freq(panel.m_freq),
		m_gain(panel.m_gain),
		m_power(panel.m_power)
    {   }
	Panel(const QString &name, const QString &ssid, const QString &description, const QString &degrees, const QString &freq, const QString &gain, const QString &power) :
		m_name(name),
        m_ssid(ssid),
        m_description(description),
        m_degrees(degrees),
		m_freq(freq),
		m_gain(gain),
		m_power(power)
    {   }
};

class QPanelMap : public QMap<QString, Panel>
{

public:
    QPanelMap();
    void add(const Panel &panel)    { insert(panel.m_name, panel); }
    void loadPanelsCSV(const QString &fname);
};
typedef QMapIterator<QString, Panel> QPanelMapIterator;

#include <QComboBox>
class QPanelCB : public QComboBox
{
	enum PanelCustomData
    {
		Name = Qt::UserRole,
        SSID,
        Description,
        Degrees,
        Frequency,
        Gain,
		Power
	};

	QString currentData(PanelCustomData c) const  { return itemData(currentIndex(), c).toString(); }
public:
    QPanelCB(QWidget *papi = Q_NULLPTR);
	void selectPanel(const QString &panelName);

	QString currentName() const				{ return currentData(Name);	}
	QString currentSSID() const				{ return currentData(SSID);	}
	QString currentDescription() const		{ return currentData(Description);	}
	QString currentDegrees() const			{ return currentData(Degrees);	}
	QString currentFrequency() const		{ return currentData(Frequency);}
	QString currentGain() const				{ return currentData(Gain);		}
	QString currentPower() const			{ return currentData(Power);	}
	void setup(const QPanelMap &panelMap, const QString &newPanelName = QString());
};

#endif // BASESTATIONINFO_H
