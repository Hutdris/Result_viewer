/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "OpenGLWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLCDNumber *lcdNumber;
    QSlider *horizontalSlider;
    OpenGLWidget *openGLWidget;
    QPushButton *upper_botton;
    QPushButton *lower_botton;
    QPushButton *rt_botton;
    QPushButton *set_first_frame_botton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(755, 576);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(630, 420, 64, 23));
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(120, 480, 571, 16));
        horizontalSlider->setOrientation(Qt::Horizontal);
        openGLWidget = new OpenGLWidget(centralWidget);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));
        openGLWidget->setGeometry(QRect(20, 10, 691, 391));
        upper_botton = new QPushButton(centralWidget);
        upper_botton->setObjectName(QStringLiteral("upper_botton"));
        upper_botton->setGeometry(QRect(30, 420, 75, 23));
        lower_botton = new QPushButton(centralWidget);
        lower_botton->setObjectName(QStringLiteral("lower_botton"));
        lower_botton->setGeometry(QRect(30, 460, 75, 23));
        rt_botton = new QPushButton(centralWidget);
        rt_botton->setObjectName(QStringLiteral("rt_botton"));
        rt_botton->setGeometry(QRect(30, 500, 75, 23));
        set_first_frame_botton = new QPushButton(centralWidget);
        set_first_frame_botton->setObjectName(QStringLiteral("set_first_frame_botton"));
        set_first_frame_botton->setGeometry(QRect(160, 430, 101, 21));
        MainWindow->setCentralWidget(centralWidget);
        lcdNumber->raise();
        horizontalSlider->raise();
        openGLWidget->raise();
        lower_botton->raise();
        rt_botton->raise();
        set_first_frame_botton->raise();
        upper_botton->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 755, 18));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), lcdNumber, SLOT(display(int)));
        QObject::connect(upper_botton, SIGNAL(clicked()), MainWindow, SLOT(upper_click()));
        QObject::connect(lower_botton, SIGNAL(clicked()), MainWindow, SLOT(lower_click()));
        QObject::connect(rt_botton, SIGNAL(clicked()), MainWindow, SLOT(rt_click()));
        QObject::connect(set_first_frame_botton, SIGNAL(clicked()), MainWindow, SLOT(rt_click()));
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), MainWindow, SLOT(sent_rt(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        upper_botton->setText(QApplication::translate("MainWindow", "Upper", 0));
        lower_botton->setText(QApplication::translate("MainWindow", "Lower", 0));
        rt_botton->setText(QApplication::translate("MainWindow", "RT", 0));
        set_first_frame_botton->setText(QApplication::translate("MainWindow", "Set first Frame", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
