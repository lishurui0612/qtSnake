/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actiondsf;
    QAction *action2p;
    QAction *actionstart;
    QAction *actionpause;
    QAction *actionexit;
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menusettings;
    QMenu *menuexit;
    QMenu *menustart;
    QToolBar *mainToolBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        actiondsf = new QAction(MainWindow);
        actiondsf->setObjectName(QStringLiteral("actiondsf"));
        action2p = new QAction(MainWindow);
        action2p->setObjectName(QStringLiteral("action2p"));
        actionstart = new QAction(MainWindow);
        actionstart->setObjectName(QStringLiteral("actionstart"));
        actionpause = new QAction(MainWindow);
        actionpause->setObjectName(QStringLiteral("actionpause"));
        actionexit = new QAction(MainWindow);
        actionexit->setObjectName(QStringLiteral("actionexit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(300, 150, 150, 50));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(300, 250, 150, 50));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(300, 350, 150, 50));
        pushButton_3->setIconSize(QSize(100, 12));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(250, 10, 300, 81));
        label->setMinimumSize(QSize(0, 0));
        label->setPixmap(QPixmap(QString::fromUtf8("Snake.PNG")));
        MainWindow->setCentralWidget(centralWidget);
        pushButton_2->raise();
        pushButton_3->raise();
        pushButton->raise();
        label->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 17));
        menusettings = new QMenu(menuBar);
        menusettings->setObjectName(QStringLiteral("menusettings"));
        menuexit = new QMenu(menuBar);
        menuexit->setObjectName(QStringLiteral("menuexit"));
        menustart = new QMenu(menuBar);
        menustart->setObjectName(QStringLiteral("menustart"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menustart->menuAction());
        menuBar->addAction(menusettings->menuAction());
        menuBar->addAction(menuexit->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\350\264\252\345\220\203\350\233\207", Q_NULLPTR));
        actiondsf->setText(QApplication::translate("MainWindow", "1p", Q_NULLPTR));
        action2p->setText(QApplication::translate("MainWindow", "2p", Q_NULLPTR));
        actionstart->setText(QApplication::translate("MainWindow", "start", Q_NULLPTR));
        actionpause->setText(QApplication::translate("MainWindow", "setting", Q_NULLPTR));
        actionexit->setText(QApplication::translate("MainWindow", "exit", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\345\215\225\346\234\272", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "\351\200\211\351\241\271", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", Q_NULLPTR));
        label->setText(QString());
        menusettings->setTitle(QApplication::translate("MainWindow", "settings", Q_NULLPTR));
        menuexit->setTitle(QApplication::translate("MainWindow", "exit", Q_NULLPTR));
        menustart->setTitle(QApplication::translate("MainWindow", "start", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
