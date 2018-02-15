#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <QString>
#include <QDebug>
#include <iostream>

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
private slots:
    void on_getTweetsBtn_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
