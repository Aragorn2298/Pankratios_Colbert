#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    dirTweets= QDir::root();
    dirTweets.cd("src");
    dirTweets.cd("Tweets");

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_getTweetsBtn_clicked()
{
    //cout<<QDir::toStdString()<<endl;
    QDir dirJar = QDir::currentPath();
    dirJar.cd("src");

    string searchString = "java -jar HashtaggerJava.jar " + ui->searchStringLn->text().toStdString();
    const char * c = searchString.c_str();
    //QDir::setCurrent("C:/Users/xblao/Documents/GitHub/Pankratios_Colbert/Project/Hashtagger/src");
    QDir::setCurrent(dirJar.path());
    system(c);
}
