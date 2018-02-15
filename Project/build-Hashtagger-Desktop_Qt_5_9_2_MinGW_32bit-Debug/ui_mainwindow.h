/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *getTweetsBtn;
    QLineEdit *searchStringLn;
    QListView *foldersView;
    QListView *jsonsView;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(427, 287);
        QFont font;
        font.setFamily(QStringLiteral("System"));
        font.setPointSize(10);
        MainWindow->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        getTweetsBtn = new QPushButton(centralWidget);
        getTweetsBtn->setObjectName(QStringLiteral("getTweetsBtn"));
        getTweetsBtn->setGeometry(QRect(150, 210, 91, 31));
        searchStringLn = new QLineEdit(centralWidget);
        searchStringLn->setObjectName(QStringLiteral("searchStringLn"));
        searchStringLn->setGeometry(QRect(20, 210, 121, 31));
        foldersView = new QListView(centralWidget);
        foldersView->setObjectName(QStringLiteral("foldersView"));
        foldersView->setGeometry(QRect(20, 10, 221, 192));
        jsonsView = new QListView(centralWidget);
        jsonsView->setObjectName(QStringLiteral("jsonsView"));
        jsonsView->setGeometry(QRect(250, 10, 161, 231));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        getTweetsBtn->setText(QApplication::translate("MainWindow", "Get tweets", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
