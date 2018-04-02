#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <QString>
#include <QDebug>
#include <iostream>
#include <QStringList>
#include <QStringListModel>
#include <QAbstractItemView>
#include <stdio.h>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include "myclickablewidget.h"
#include <sstream>

using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QDir dirTweets;
    QDir dirTweetJson;
    QStringListModel *modelFolders;
    QStringListModel *modelJson;
    QStringList folderList;
    QStringList jsonList;
    QVariantMap json_map;
    QVariantMap user_map;

    MyClickableWidget test;
    QString clickedTweet;
    QString clickedTweetText;

    void updateViews();
    QString getIndex(const QModelIndex &index);
    void updateJsonView(QString str);
    void setTweetsPath();
    void parseJson(const QModelIndex &index);
    vector<string> separateTweet();
    void clear();

private slots:
    void on_getTweetsBtn_clicked();

    void on_foldersView_clicked(const QModelIndex &index);

    void on_foldersView_activated(const QModelIndex &index);

    void on_jsonsView_clicked(const QModelIndex &index);

    void on_singleTweetBtn_clicked();

    void on_drawGraphBtn_clicked();

    void on_jsonsView_doubleClicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
