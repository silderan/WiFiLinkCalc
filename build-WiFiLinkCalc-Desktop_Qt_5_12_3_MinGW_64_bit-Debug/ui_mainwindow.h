/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
#include "AntennaGain.h"
#include "FrequencyPIRE.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QFrequencyComboBox *cbFrecuencia;
    QLabel *label_3;
    QSpinBox *sbPIRE;
    QLabel *label_9;
    QSpinBox *sbDistance;
    QLabel *label_10;
    QLabel *lbLoss;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QLabel *label_8;
    QAntennaGainCB *cbAPModel;
    QLabel *label_2;
    QSpinBox *sbAPGain;
    QLabel *label_6;
    QLabel *lbAPRxPwd;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *label_5;
    QAntennaGainCB *cbClModel;
    QLabel *label_4;
    QSpinBox *sbClGain;
    QLabel *label_7;
    QLabel *lbClRxPwd;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(311, 172);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        cbFrecuencia = new QFrequencyComboBox(centralWidget);
        cbFrecuencia->setObjectName(QString::fromUtf8("cbFrecuencia"));

        gridLayout->addWidget(cbFrecuencia, 0, 1, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        sbPIRE = new QSpinBox(centralWidget);
        sbPIRE->setObjectName(QString::fromUtf8("sbPIRE"));
        sbPIRE->setMinimum(-100);
        sbPIRE->setMaximum(100);

        gridLayout->addWidget(sbPIRE, 0, 3, 1, 1);

        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_9, 1, 0, 1, 1);

        sbDistance = new QSpinBox(centralWidget);
        sbDistance->setObjectName(QString::fromUtf8("sbDistance"));
        sbDistance->setMaximum(999999999);

        gridLayout->addWidget(sbDistance, 1, 1, 1, 1);

        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 1, 2, 1, 1);

        lbLoss = new QLabel(centralWidget);
        lbLoss->setObjectName(QString::fromUtf8("lbLoss"));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font.setPointSize(8);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        lbLoss->setFont(font);

        gridLayout->addWidget(lbLoss, 1, 3, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_3->addWidget(label_8, 0, 0, 1, 1);

        cbAPModel = new QAntennaGainCB(groupBox);
        cbAPModel->setObjectName(QString::fromUtf8("cbAPModel"));

        gridLayout_3->addWidget(cbAPModel, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_3->addWidget(label_2, 1, 0, 1, 1);

        sbAPGain = new QSpinBox(groupBox);
        sbAPGain->setObjectName(QString::fromUtf8("sbAPGain"));

        gridLayout_3->addWidget(sbAPGain, 1, 1, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_3->addWidget(label_6, 2, 0, 1, 1);

        lbAPRxPwd = new QLabel(groupBox);
        lbAPRxPwd->setObjectName(QString::fromUtf8("lbAPRxPwd"));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        lbAPRxPwd->setFont(font1);

        gridLayout_3->addWidget(lbAPRxPwd, 2, 1, 1, 1);


        gridLayout->addWidget(groupBox, 2, 0, 1, 2);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 0, 0, 1, 1);

        cbClModel = new QAntennaGainCB(groupBox_2);
        cbClModel->setObjectName(QString::fromUtf8("cbClModel"));

        gridLayout_2->addWidget(cbClModel, 0, 1, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        sbClGain = new QSpinBox(groupBox_2);
        sbClGain->setObjectName(QString::fromUtf8("sbClGain"));

        gridLayout_2->addWidget(sbClGain, 1, 1, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 2, 0, 1, 1);

        lbClRxPwd = new QLabel(groupBox_2);
        lbClRxPwd->setObjectName(QString::fromUtf8("lbClRxPwd"));
        lbClRxPwd->setFont(font1);

        gridLayout_2->addWidget(lbClRxPwd, 2, 1, 1, 1);


        gridLayout->addWidget(groupBox_2, 2, 2, 1, 2);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Calculadora PIRE", nullptr));
        label->setText(QApplication::translate("MainWindow", "Frecuencia", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "PIRE", nullptr));
        sbPIRE->setSuffix(QApplication::translate("MainWindow", " dBm", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "Distancia", nullptr));
        sbDistance->setSuffix(QApplication::translate("MainWindow", " m", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "Loss", nullptr));
        lbLoss->setText(QString());
        groupBox->setTitle(QApplication::translate("MainWindow", "AP (Panel)", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Modelo", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Ganancia", nullptr));
        sbAPGain->setSuffix(QApplication::translate("MainWindow", " dBi", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Potencia", nullptr));
        lbAPRxPwd->setText(QApplication::translate("MainWindow", "0 dBm", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Cliente", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Modelo", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Ganancia", nullptr));
        sbClGain->setSuffix(QApplication::translate("MainWindow", " dBi", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Potencia", nullptr));
        lbClRxPwd->setText(QApplication::translate("MainWindow", "0 dBm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
