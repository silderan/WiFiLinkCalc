#ifndef QFREQUENCYCOMBOBOX_H
#define QFREQUENCYCOMBOBOX_H

#include <QStringList>
#include <QComboBox>
#include <QMap>

#include "QIniFile.h"

typedef QMap<QString, QString> QFrequencyMap;
typedef QMapIterator<QString, QString> QFrequencyMapIterator;
typedef QMap<QString, QStringList> QPIREMap;
typedef QMapIterator<QString, QStringList> QPIREMapIterator;

class QFrequencyComboBox : public QComboBox
{
	Q_OBJECT
	QFrequencyMap m_frequencyMap;
	QPIREMap m_PIREMap;

public:
	explicit QFrequencyComboBox(QWidget *parent = 0);
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

#endif // QFREQUENCYCOMBOBOX_H
