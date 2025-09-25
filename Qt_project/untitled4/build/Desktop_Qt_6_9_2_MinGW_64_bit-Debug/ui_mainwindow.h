/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actNew;
    QAction *actiondakai;
    QAction *actiontuichu;
    QAction *actionjianqie;
    QAction *actionfuzhi;
    QAction *actionzhantie;
    QAction *actioncuti;
    QAction *actionxieti;
    QAction *actionxiahuaxian;
    QAction *actAbout;
    QWidget *centralwidget;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(771, 600);
        actNew = new QAction(MainWindow);
        actNew->setObjectName("actNew");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/new2.bmp"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actNew->setIcon(icon);
        actiondakai = new QAction(MainWindow);
        actiondakai->setObjectName("actiondakai");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/open3.bmp"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actiondakai->setIcon(icon1);
        actiontuichu = new QAction(MainWindow);
        actiontuichu->setObjectName("actiontuichu");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/images/exit.bmp"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actiontuichu->setIcon(icon2);
        actionjianqie = new QAction(MainWindow);
        actionjianqie->setObjectName("actionjianqie");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/images/cut.bmp"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionjianqie->setIcon(icon3);
        actionfuzhi = new QAction(MainWindow);
        actionfuzhi->setObjectName("actionfuzhi");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/images/120.bmp"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionfuzhi->setIcon(icon4);
        actionzhantie = new QAction(MainWindow);
        actionzhantie->setObjectName("actionzhantie");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/images/paste.bmp"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionzhantie->setIcon(icon5);
        actioncuti = new QAction(MainWindow);
        actioncuti->setObjectName("actioncuti");
        actioncuti->setCheckable(true);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/images/BLD.BMP"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actioncuti->setIcon(icon6);
        actionxieti = new QAction(MainWindow);
        actionxieti->setObjectName("actionxieti");
        actionxieti->setCheckable(true);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/images/ITL.BMP"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionxieti->setIcon(icon7);
        actionxiahuaxian = new QAction(MainWindow);
        actionxiahuaxian->setObjectName("actionxiahuaxian");
        actionxiahuaxian->setCheckable(true);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/images/WORDUNDR.BMP"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionxiahuaxian->setIcon(icon8);
        actAbout = new QAction(MainWindow);
        actAbout->setObjectName("actAbout");
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/images/20.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actAbout->setIcon(icon9);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(310, 40, 104, 75));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 771, 25));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName("menu_2");
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName("menu_3");
        menu_4 = new QMenu(menubar);
        menu_4->setObjectName("menu_4");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        toolBar->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menubar->addAction(menu_4->menuAction());
        menu->addAction(actNew);
        menu->addAction(actiondakai);
        menu->addAction(actiontuichu);
        menu_2->addAction(actionjianqie);
        menu_2->addAction(actionfuzhi);
        menu_2->addAction(actionzhantie);
        menu_3->addAction(actioncuti);
        menu_3->addAction(actionxieti);
        menu_3->addAction(actionxiahuaxian);
        menu_4->addAction(actAbout);
        toolBar->addAction(actNew);
        toolBar->addAction(actiondakai);
        toolBar->addAction(actiontuichu);
        toolBar->addAction(actionjianqie);
        toolBar->addAction(actionfuzhi);
        toolBar->addAction(actionzhantie);
        toolBar->addAction(actioncuti);
        toolBar->addAction(actionxieti);
        toolBar->addAction(actionxiahuaxian);
        toolBar->addAction(actAbout);

        retranslateUi(MainWindow);
        QObject::connect(actiontuichu, &QAction::triggered, MainWindow, qOverload<>(&QMainWindow::close));
        QObject::connect(actionjianqie, &QAction::triggered, textEdit, qOverload<>(&QTextEdit::cut));
        QObject::connect(actionfuzhi, &QAction::triggered, textEdit, qOverload<>(&QTextEdit::copy));
        QObject::connect(actionzhantie, &QAction::triggered, textEdit, qOverload<>(&QTextEdit::paste));
        QObject::connect(actionjianqie, &QAction::triggered, textEdit, qOverload<>(&QTextEdit::clear));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actNew->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272", nullptr));
#if QT_CONFIG(tooltip)
        actNew->setToolTip(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
        actiondakai->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
#if QT_CONFIG(tooltip)
        actiondakai->setToolTip(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
        actiontuichu->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#if QT_CONFIG(tooltip)
        actiontuichu->setToolTip(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
        actionjianqie->setText(QCoreApplication::translate("MainWindow", "\345\211\252\345\210\207", nullptr));
#if QT_CONFIG(tooltip)
        actionjianqie->setToolTip(QCoreApplication::translate("MainWindow", "\345\211\252\345\210\207", nullptr));
#endif // QT_CONFIG(tooltip)
        actionfuzhi->setText(QCoreApplication::translate("MainWindow", "\345\244\215\345\210\266", nullptr));
#if QT_CONFIG(tooltip)
        actionfuzhi->setToolTip(QCoreApplication::translate("MainWindow", "\345\244\215\345\210\266", nullptr));
#endif // QT_CONFIG(tooltip)
        actionzhantie->setText(QCoreApplication::translate("MainWindow", "\347\262\230\350\264\264", nullptr));
#if QT_CONFIG(tooltip)
        actionzhantie->setToolTip(QCoreApplication::translate("MainWindow", "\347\262\230\350\264\264", nullptr));
#endif // QT_CONFIG(tooltip)
        actioncuti->setText(QCoreApplication::translate("MainWindow", "\347\262\227\344\275\223", nullptr));
#if QT_CONFIG(tooltip)
        actioncuti->setToolTip(QCoreApplication::translate("MainWindow", "\347\262\227\344\275\223", nullptr));
#endif // QT_CONFIG(tooltip)
        actionxieti->setText(QCoreApplication::translate("MainWindow", "\346\226\234\344\275\223", nullptr));
#if QT_CONFIG(tooltip)
        actionxieti->setToolTip(QCoreApplication::translate("MainWindow", "\346\226\234\344\275\223", nullptr));
#endif // QT_CONFIG(tooltip)
        actionxiahuaxian->setText(QCoreApplication::translate("MainWindow", "\344\270\213\345\210\222\347\272\277", nullptr));
#if QT_CONFIG(tooltip)
        actionxiahuaxian->setToolTip(QCoreApplication::translate("MainWindow", "\344\270\213\345\210\222\347\272\277", nullptr));
#endif // QT_CONFIG(tooltip)
        actAbout->setText(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
#if QT_CONFIG(tooltip)
        actAbout->setToolTip(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
#endif // QT_CONFIG(tooltip)
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\346\240\274\345\274\217", nullptr));
        menu_4->setTitle(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
