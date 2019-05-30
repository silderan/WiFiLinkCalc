/********************************************************************************
** Form generated from reading UI file 'DlgConfig.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGCONFIG_H
#define UI_DLGCONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>
#include "AntennaGain.h"
#include "FrequencyPIRE.h"

QT_BEGIN_NAMESPACE

class Ui_DlgConfig
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QAntennaGainTable *gainTable;
    QToolButton *addModelGain;
    QGridLayout *gridLayout;
    QLabel *label;
    QToolButton *addPIREButton;
    QFrequencyTable *pireTable;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QSpinBox *sbSteps;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btOk;
    QLabel *label_4;

    void setupUi(QDialog *DlgConfig)
    {
        if (DlgConfig->objectName().isEmpty())
            DlgConfig->setObjectName(QString::fromUtf8("DlgConfig"));
        DlgConfig->resize(575, 391);
        gridLayout_3 = new QGridLayout(DlgConfig);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_2 = new QLabel(DlgConfig);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        gainTable = new QAntennaGainTable(DlgConfig);
        gainTable->setObjectName(QString::fromUtf8("gainTable"));

        gridLayout_2->addWidget(gainTable, 1, 0, 1, 2);

        addModelGain = new QToolButton(DlgConfig);
        addModelGain->setObjectName(QString::fromUtf8("addModelGain"));

        gridLayout_2->addWidget(addModelGain, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(DlgConfig);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        addPIREButton = new QToolButton(DlgConfig);
        addPIREButton->setObjectName(QString::fromUtf8("addPIREButton"));

        gridLayout->addWidget(addPIREButton, 1, 1, 1, 1);

        pireTable = new QFrequencyTable(DlgConfig);
        pireTable->setObjectName(QString::fromUtf8("pireTable"));

        gridLayout->addWidget(pireTable, 2, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(DlgConfig);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_3);

        sbSteps = new QSpinBox(DlgConfig);
        sbSteps->setObjectName(QString::fromUtf8("sbSteps"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sbSteps->sizePolicy().hasHeightForWidth());
        sbSteps->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(sbSteps);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 2);


        gridLayout_3->addLayout(gridLayout, 0, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btOk = new QPushButton(DlgConfig);
        btOk->setObjectName(QString::fromUtf8("btOk"));
        sizePolicy.setHeightForWidth(btOk->sizePolicy().hasHeightForWidth());
        btOk->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(btOk);

        label_4 = new QLabel(DlgConfig);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);


        gridLayout_3->addLayout(horizontalLayout_2, 1, 0, 1, 2);


        retranslateUi(DlgConfig);

        QMetaObject::connectSlotsByName(DlgConfig);
    } // setupUi

    void retranslateUi(QDialog *DlgConfig)
    {
        DlgConfig->setWindowTitle(QApplication::translate("DlgConfig", "Dialog", nullptr));
        label_2->setText(QApplication::translate("DlgConfig", "Ganancia antena seg\303\272n modelo", nullptr));
        addModelGain->setText(QApplication::translate("DlgConfig", "+", nullptr));
        label->setText(QApplication::translate("DlgConfig", "PIRES seg\303\272n frecuencia", nullptr));
        addPIREButton->setText(QApplication::translate("DlgConfig", "+", nullptr));
        label_3->setText(QApplication::translate("DlgConfig", "Pasos frecuencia", nullptr));
        btOk->setText(QApplication::translate("DlgConfig", "Aceptar", nullptr));
        label_4->setText(QApplication::translate("DlgConfig", "Para borrar modelos de antenas y/o PIREs, borrar el modelo y/o poner los PIRE a 0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgConfig: public Ui_DlgConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGCONFIG_H
