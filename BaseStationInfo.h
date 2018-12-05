#ifndef BASESTATIONINFO_H
#define BASESTATIONINFO_H

#include <QStringList>
#include <QMap>

struct Panel
{
    QString m_name;
    QString m_model;
    QString m_freq;
    QString m_power;
    Panel()
    {   }
    Panel(const Panel &panel) :
        m_name(panel.m_name), m_model(panel.m_model), m_freq(panel.m_freq), m_power(panel.m_power)
    {   }
    Panel(const QString name, const QString model, const QString freq, const QString power) :
        m_name(name), m_model(model), m_freq(freq), m_power(power)
    {   }
};

class QPanelMap : public QMap<QString, Panel>
{
public:
    Panel panel(const QString &panelName)   { return value(panelName);  }

    void addPanel(const Panel &panel)
    {   insert(panel.m_name, panel);    }
    void addPanel(const QString &panelName, const QString &panelModel, const QString &frequency, const QString &outPower)
    {   addPanel( Panel(panelName, panelModel, frequency, outPower)); }
    QString panelModel(const QString &panelName)    { return panel(panelName).m_model;  }
    QString frequency(const QString &panelName)     { return panel(panelName).m_freq;   }
    QString outPower(const QString &panelName)      { return panel(panelName).m_power;  }

    QStringList panelNames() const                  { return keys();    }
};

class QBaseStationMap : public QMap<QString, QPanelMap>
{
public:
    void addPanel(const QString &baseStationName, const Panel &panel)
    {   (*this)[baseStationName].addPanel(panel); }
    void addPanel(const QString &baseStationName, const QString &panelName, const QString &model, const QString &freq, const QString power)
    {   addPanel(baseStationName, Panel(panelName, model, freq, power)); }
    QStringList baseStationNames() const                { return keys();    }
//    const QPanelMap &panelMap(const QString &baseStationName)   { return value(baseStationName);   }
    QStringList panelNames(const QString &baseStationName)      { return value(baseStationName).panelNames();   }
    QString frequency(const QString &baseStationName, const QString &panelName)
    {   return (*this)[baseStationName].frequency(panelName);    }
};

class QBaseStationInfo
{
    QBaseStationMap m_baseStationMap;
public:
    QStringList baseStationNames() const { return m_baseStationMap.baseStationNames();  }
    QStringList panelNames(const QString &baseStationName) { return m_baseStationMap.panelNames(baseStationName);   }
    QString frequency(const QString &baseStationName, const QString &panelName) { return m_baseStationMap.frequency(baseStationName, panelName); }
    QBaseStationInfo();
    void loadPanelsCSV(const QString &fname);
};

#endif // BASESTATIONINFO_H
