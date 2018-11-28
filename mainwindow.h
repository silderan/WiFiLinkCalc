#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>

#include "QIniFile.h"

namespace Ui
{
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT
	Ui::MainWindow *ui;
	QIniData cnfgData;

	QAction cnfgAction;

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private slots:
	void onFrCBError(const QString &fnc, const QString &tittle, const QString &desc);
	void onNewPIRE(int pire);
	void openCnfgDlg();
};

#endif // MAINWINDOW_H
