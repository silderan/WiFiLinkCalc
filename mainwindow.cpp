#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "DlgConfig.h"

#define CONFIG_FNAME	("PIRECalculator.ini")

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow),cnfgAction(this)
{
	ui->setupUi(this);

	QIniFile::load(CONFIG_FNAME, &cnfgData);

	cnfgAction.setShortcut( QKeySequence(Qt::CTRL | Qt::ALT | Qt::Key_C) );
	connect( &cnfgAction, SIGNAL(triggered()), this, SLOT(openCnfgDlg()) );
	this->addAction( &cnfgAction );

	connect( ui->cbFrecuencia, SIGNAL(pireChanged(int)), this, SLOT(onNewPIRE(int)) );
	connect( ui->cbFrecuencia, SIGNAL(frequencyCBError(QString,QString,QString)), this, SLOT(onFrCBError(QString,QString,QString)) );
	ui->cbFrecuencia->loadSaveData(cnfgData);
}

MainWindow::~MainWindow()
{
	ui->cbFrecuencia->getSaveData(cnfgData);
	QIniFile::save(CONFIG_FNAME, cnfgData);
	delete ui;
}

#include <QMessageBox>
void MainWindow::onFrCBError(const QString &fnc, const QString &title, const QString &desc)
{
	QMessageBox::warning( this, title, QString("En la función %1 de la lista de frecuencias:\n%2").arg(fnc, desc) );
}

void MainWindow::onNewPIRE(int pire)
{
	ui->lbPIRE->setText( QString("%1 dBm").arg(pire) );
}

void MainWindow::openCnfgDlg()
{
	DlgConfig cnfgDlg(ui->cbFrecuencia->pireMap(), ui->cbAPModel->antennaGainMap(), this);

	if( cnfgDlg.exec() == QDialog::Accepted )
	{
		ui->cbFrecuencia->setPIREMap( cnfgDlg.pireMAP() );
		ui->cbAPModel->setAntennaGainMap( cnfgDlg.antennaGainMap() );
		ui->cbClModel->setAntennaGainMap( cnfgDlg.antennaGainMap() );
	}
}
