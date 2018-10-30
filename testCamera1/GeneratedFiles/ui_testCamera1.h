/********************************************************************************
** Form generated from reading UI file 'testCamera1.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTCAMERA1_H
#define UI_TESTCAMERA1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_testCamera1Class
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLabel *label;
    QTextEdit *textEdit_display;
    QLineEdit *threshEdit;
    QLineEdit *lowLimitEdit;
    QLineEdit *setExpoTimeEdit;
    QLineEdit *totalPxEdit;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *testCamera1Class)
    {
        if (testCamera1Class->objectName().isEmpty())
            testCamera1Class->setObjectName(QStringLiteral("testCamera1Class"));
        testCamera1Class->resize(1320, 839);
        centralWidget = new QWidget(testCamera1Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(31, 21, 93, 28));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(131, 21, 93, 28));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(231, 21, 93, 28));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(331, 21, 93, 28));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(431, 21, 93, 28));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 60, 881, 691));
        label->setFrameShape(QFrame::Panel);
        label->setFrameShadow(QFrame::Sunken);
        textEdit_display = new QTextEdit(centralWidget);
        textEdit_display->setObjectName(QStringLiteral("textEdit_display"));
        textEdit_display->setGeometry(QRect(920, 60, 351, 541));
        threshEdit = new QLineEdit(centralWidget);
        threshEdit->setObjectName(QStringLiteral("threshEdit"));
        threshEdit->setGeometry(QRect(989, 639, 137, 22));
        lowLimitEdit = new QLineEdit(centralWidget);
        lowLimitEdit->setObjectName(QStringLiteral("lowLimitEdit"));
        lowLimitEdit->setGeometry(QRect(989, 668, 137, 22));
        setExpoTimeEdit = new QLineEdit(centralWidget);
        setExpoTimeEdit->setObjectName(QStringLiteral("setExpoTimeEdit"));
        setExpoTimeEdit->setGeometry(QRect(989, 697, 137, 22));
        totalPxEdit = new QLineEdit(centralWidget);
        totalPxEdit->setObjectName(QStringLiteral("totalPxEdit"));
        totalPxEdit->setGeometry(QRect(989, 726, 137, 22));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(1139, 640, 41, 22));
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(1139, 669, 41, 22));
        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(1139, 698, 41, 21));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(937, 644, 41, 20));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(949, 670, 31, 20));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(922, 694, 61, 20));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(940, 724, 41, 20));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(920, 610, 71, 20));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(920, 30, 71, 20));
        testCamera1Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(testCamera1Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1320, 26));
        testCamera1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(testCamera1Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        testCamera1Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(testCamera1Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        testCamera1Class->setStatusBar(statusBar);

        retranslateUi(testCamera1Class);
        QObject::connect(pushButton_5, SIGNAL(clicked()), testCamera1Class, SLOT(close()));
        QObject::connect(pushButton, SIGNAL(clicked()), testCamera1Class, SLOT(slotStart()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), testCamera1Class, SLOT(slotStop()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), testCamera1Class, SLOT(showSrcBtn()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), testCamera1Class, SLOT(showDstBtn()));
        QObject::connect(pushButton_6, SIGNAL(clicked()), testCamera1Class, SLOT(getParaBtn()));
        QObject::connect(pushButton_7, SIGNAL(clicked()), testCamera1Class, SLOT(getParaBtn()));
        QObject::connect(pushButton_8, SIGNAL(clicked()), testCamera1Class, SLOT(getParaBtn()));

        QMetaObject::connectSlotsByName(testCamera1Class);
    } // setupUi

    void retranslateUi(QMainWindow *testCamera1Class)
    {
        testCamera1Class->setWindowTitle(QApplication::translate("testCamera1Class", "testCamera1", Q_NULLPTR));
        pushButton->setText(QApplication::translate("testCamera1Class", "START", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("testCamera1Class", "STOP", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("testCamera1Class", "SHOW SRC", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("testCamera1Class", "SHOW DST", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("testCamera1Class", "EXIT", Q_NULLPTR));
        label->setText(QString());
        threshEdit->setText(QApplication::translate("testCamera1Class", "30", Q_NULLPTR));
        lowLimitEdit->setText(QApplication::translate("testCamera1Class", "50000", Q_NULLPTR));
        setExpoTimeEdit->setText(QApplication::translate("testCamera1Class", "5000", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("testCamera1Class", "ok", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("testCamera1Class", "ok", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("testCamera1Class", "ok", Q_NULLPTR));
        label_2->setText(QApplication::translate("testCamera1Class", "thresh:", Q_NULLPTR));
        label_3->setText(QApplication::translate("testCamera1Class", "total:", Q_NULLPTR));
        label_4->setText(QApplication::translate("testCamera1Class", "Exposure:", Q_NULLPTR));
        label_5->setText(QApplication::translate("testCamera1Class", "return:", Q_NULLPTR));
        label_6->setText(QApplication::translate("testCamera1Class", "Parameter:", Q_NULLPTR));
        label_7->setText(QApplication::translate("testCamera1Class", "Information:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class testCamera1Class: public Ui_testCamera1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTCAMERA1_H
