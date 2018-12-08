#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

#include "QIniFile.h"
#include "qcsv.h"
#include "AntennaGain.h"
#include "DlgConfig.h"

// Save file key definitions.
#define CONFIG_FNAME	("PIRECalculator.ini")
#define PANELCSV_FNAME  ("paneles.csv")
#define KEY_FREQ(_l)    (QString("freq-list_%1").arg(_l))
#define KEY_FSTEP       ("freq-step")
#define KEY_CURFR       ("freq-curr")

#define KEY_ANT(_l)     (QString("antenna_%1").arg(_l)) // Antenna model key
#define KEY_APMODL		("acces-point-model")			// AP antenna model CB current selected.
#define KEY_APGAIN		("acces-point-gain")
#define KEY_CLMODL      ("client-antenna-model")
#define KEY_CLGAIN		("client-gain")

#define KEY_PANELCUR	("panel-current")

#define KEY_DIST        ("link-distance")
#define KEY_PIRE        ("AP-custom-pire")

#define SHOWMESSAGE(_t,_d) (QMessageBox::warning(this, QString("%1 [%2]").arg(this->windowTitle(), __FUNCTION__), QString("%1\n%2").arg(_t, _d)))

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
    ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	QAction *cnfgAction = new QAction(this);
    cnfgAction->setShortcut( QKeySequence(Qt::CTRL | Qt::ALT | Qt::Key_C) );
    connect( cnfgAction, SIGNAL(triggered()), this, SLOT(openCnfgDlg()) );
    this->addAction( cnfgAction );

	cnfgAction = new QAction(this);
    cnfgAction->setShortcut( QKeySequence(Qt::CTRL | Qt::ALT | Qt::Key_L) );
    connect( cnfgAction, SIGNAL(triggered()), this, SLOT(loadAll()) );
    this->addAction( cnfgAction );

	connect( ui->cbFrecuencia, SIGNAL(pireChanged(int)), this, SLOT(onNewPIRE(int)) );
    connect( ui->cbAPModel, SIGNAL(gainChanged(quint32)),this, SLOT(onNewAPGain(quint32)) );
    connect( ui->cbClModel, SIGNAL(gainChanged(quint32)),this, SLOT(onNewClGain(quint32)) );
    connect( ui->sbDistance, SIGNAL(valueChanged(int)), this, SLOT(onNewDistance(int)) );
    connect( ui->sbPIRE, SIGNAL(valueChanged(int)), this, SLOT(onNewPIRE(int)) );
    connect( ui->sbAPGain, SIGNAL(valueChanged(int)), this, SLOT(recalc()) );
    connect( ui->sbClGain, SIGNAL(valueChanged(int)), this, SLOT(recalc()) );

	loadAll();
}

MainWindow::~MainWindow()
{
	saveUserData();
    delete ui;
}

void MainWindow::saveUserData() const
{
	QIniData cnfgData;

	cnfgData[KEY_CURFR] = ui->cbFrecuencia->currentFrequency();
	cnfgData[KEY_PIRE] = QString("%1").arg(ui->sbPIRE->value());
	cnfgData[KEY_DIST] = QString("%1").arg(ui->sbDistance->value());

	cnfgData[KEY_APMODL] = ui->cbAPModel->currentModelName();
	cnfgData[KEY_APGAIN] = QString("%1").arg(ui->sbAPGain->value());

	cnfgData[KEY_CLMODL] = ui->cbClModel->currentModelName();
	cnfgData[KEY_CLGAIN] = QString("%1").arg(ui->sbClGain->value());

	cnfgData[KEY_PANELCUR] = ui->cbPanels->currentName();

	QIniFile::save(CONFIG_FNAME, cnfgData, QIniFile::UserDocuments);
}

void MainWindow::loadAll()
{
	QIniData userData;
	QIniData glblData;
	QIniFile::load(CONFIG_FNAME, &userData, QIniFile::UserDocuments);
	QIniFile::load(CONFIG_FNAME, &glblData, QIniFile::CurrentDir);

	loadPIREData(glblData);
	loadAntennaData(glblData);
	m_freqStep = glblData[KEY_FSTEP].toUInt();

	if( m_freqStep <= 0 )
	{
		do
		{
			SHOWMESSAGE( tr("Datos cargados de fichero"), tr("Los intérvalos de frecuenca cargados son 0. Por favor, configura un valor válido.") );
			openCnfgDlg();
		}
		while( m_freqStep <= 0 );
	}
	else
	{
		ui->cbFrecuencia->setup( m_freqPIREList, m_freqStep );
		ui->cbAPModel->setup( m_antDataList );
		ui->cbClModel->setup( m_antDataList );
	}

    loadPanelCSV();
	ui->cbFrecuencia->setCurrentFrequency( userData[KEY_CURFR] );
	ui->sbAPGain->setValue( userData[KEY_APGAIN].toInt() );
	ui->sbClGain->setValue( userData[KEY_CLGAIN].toInt() );
	ui->sbPIRE->setValue( userData[KEY_PIRE].toInt() );
	ui->sbDistance->setValue( userData[KEY_DIST].toInt() );

	ui->cbPanels->setup( m_panelMap, userData[KEY_PANELCUR] );
}

void MainWindow::loadPIREData(const QIniData &cnfgData)
{
    QString frequencyPIREDataString;

    bool ok;
	m_freqPIREList.clear();
	for( int line = 1; !(frequencyPIREDataString = cnfgData[ KEY_FREQ(line) ]).isEmpty(); line++ )
    {
        QStringList freqPIREDataStringList = frequencyPIREDataString.split(',', QString::SkipEmptyParts);
        FrequencyPire frequencyPIREData;

        if( freqPIREDataStringList.count() != 3 )
            SHOWMESSAGE( tr("Formato erroneo en los datos leídos para el PIRE según frecuencia"),
                         tr("En la configuración de pires %1 no hay 3 datos (frecuencia inicial, frecuencia final y pire)")
                            .arg(frequencyPIREDataString));
        else
        {
            frequencyPIREData.setInitialFrequency(freqPIREDataStringList[0].toUInt(&ok));
            if( !ok )
            {
                SHOWMESSAGE( tr("Formato erroneo en los datos leídos para el PIRE según frecuencia"),
                             tr("En la configuración de pires %1, el primer dato, la frecuencia inicial, no es un número positivo válido ('%2')")
                             .arg(frequencyPIREDataString)
                             .arg(freqPIREDataStringList[0]));
                continue;
            }
            frequencyPIREData.setEndFrequency(freqPIREDataStringList[1].toUInt(&ok));
            if( !ok )
            {
                SHOWMESSAGE( tr("Formato erroneo en los datos leídos para el PIRE según frecuencia"),
                             tr("En la configuración de pires %1, el segundo dato, la frecuencia final, no es un número positivo válido ('%2')")
                             .arg(frequencyPIREDataString)
                             .arg(freqPIREDataStringList[1]));
                continue;
            }
			frequencyPIREData.setFrequencyPIRE(freqPIREDataStringList[2].toInt(&ok));
            if( !ok )
            {
                SHOWMESSAGE( tr("Formato erroneo en los datos leídos para el PIRE según frecuencia"),
                             tr("En la configuración de pires %1, el tercer dato, el PIRE, no es un número válido ('%2')")
                             .arg(frequencyPIREDataString)
                             .arg(freqPIREDataStringList[2]));
                continue;
            }
			m_freqPIREList.append(frequencyPIREData);
        }
    }
}

void MainWindow::loadAntennaData(const QIniData &cnfgData)
{
    QString antennaDataString;

    bool ok;
	m_antDataList.clear();
	for( int line = 1; !(antennaDataString = cnfgData[ KEY_ANT(line) ]).isEmpty(); line++ )
    {
        QStringList antennaDataStringList = antennaDataString.split(',', QString::SkipEmptyParts);
        AntennaData antennaData;

		if( antennaDataStringList.count() < 2 )
            SHOWMESSAGE( tr("Formato erroneo en los datos leídos para la ganancia de las antenas según modelo"),
						 tr("En la configuración de las ganancias según modelo para la linea %1 no hay 2 datos (modelo y ganancia)")
                            .arg(antennaDataString));
        else
        {
            antennaData.setGain(antennaDataStringList[1].toUInt(&ok));
            if( !ok )
            {
                SHOWMESSAGE( tr("Formato erroneo en los datos leídos para la ganancia de las antenas según modelo"),
                             tr("La ganancia de la antena modelo '%1' el valor no es un número positivo válido ('%2')")
                             .arg(antennaDataString)
                             .arg(antennaDataStringList[1]));
                continue;
            }
			if( antennaDataStringList.count() >= 3 )
				antennaData.setID( antennaDataStringList[2] );

			antennaData.setModelName(antennaDataStringList[0]);
			m_antDataList.append(antennaData);
        }
	}
}

void MainWindow::loadPanelCSV()
{
	m_panelMap.loadPanelsCSV(PANELCSV_FNAME);
}

void MainWindow::onNewPIRE(int pire)
{
    ui->sbPIRE->setValue(pire);
    recalc();
}

void MainWindow::onNewAPGain(quint32 gain)
{
    ui->sbAPGain->setValue(static_cast<int>(gain));
    recalc();
}

void MainWindow::onNewClGain(quint32 gain)
{
    ui->sbClGain->setValue(static_cast<int>(gain));
    recalc();
}

void MainWindow::onNewDistance(int /*dist*/)
{
    recalc();
}

void MainWindow::openCnfgDlg()
{
	DlgConfig cnfgDlg(m_freqPIREList, m_antDataList, m_freqStep, this);

    if( cnfgDlg.exec() == QDialog::Accepted )
    {
		int i;
		m_antDataList   = cnfgDlg.antennaDataList();
		m_freqPIREList  = cnfgDlg.frequencyPIREList();
		m_freqStep      = cnfgDlg.frequencyStep();

		ui->cbFrecuencia->setup( m_freqPIREList, m_freqStep );
		ui->cbAPModel->setup( m_antDataList );
		ui->cbClModel->setup( m_antDataList );
		ui->cbPanels->setup( m_panelMap );

		QIniData iniData;
		iniData[KEY_FSTEP] = QString("%1").arg(m_freqStep);
		for( i = 0; i < m_freqPIREList.count(); i++ )
		{
			iniData[KEY_FREQ(i+1)] = QString("%1,%2,%3")
										.arg(m_freqPIREList[i].initialFrequency())
										.arg(m_freqPIREList[i].endFrequency())
										.arg(m_freqPIREList[i].frequencyPIRE());
		}
		for( i = 0; i < m_antDataList.count(); i++ )
			iniData[KEY_ANT(i+1)] = QString("%1,%2,%3")
					.arg(m_antDataList[i].modelName())
					.arg(m_antDataList[i].gain())
					.arg(m_antDataList[i].id());

		QIniFile::save(CONFIG_FNAME, iniData, QIniFile::CurrentDir);
	}
}

#include <math.h>
void MainWindow::recalc()
{
    int powerSISO;
    double freqDelta = 20.0*log10(ui->cbFrecuencia->currentFrequency().toDouble());
    double distDelta = 20.0*log10(ui->sbDistance->value()*0.000621);
    double loss = 36.56 + distDelta + freqDelta;
    ui->lbLoss->setText(QString("%1 dBi").arg(loss));

    // Pout + AntennaGain1 + AntennaGain2 - (36,56+20*LOG10(<Frequency>)+20*LOG10(<Distance>*0,000621))
    powerSISO = ui->sbPIRE->value() - static_cast<int>(loss);

	ui->lbAPRxPwd->setText(QString("de %1 a %2 dBm").arg(powerSISO+3+ui->sbAPGain->value()).arg(powerSISO+ui->sbAPGain->value()));
	ui->lbClRxPwd->setText(QString("de %1 a %2 dBm").arg(powerSISO+3+ui->sbClGain->value()).arg(powerSISO+ui->sbClGain->value()));
}

void MainWindow::on_cbPanels_currentIndexChanged(int /*index*/)
{
	ui->cbFrecuencia->selectFrequency( ui->cbPanels->currentFrequency() );
	ui->cbAPModel->selectAntenaModel( ui->cbPanels->currentDegrees(), ui->cbPanels->currentGain() );
}
