#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    dirTweets= QDir::currentPath();
    dirTweets.cd("src");
    dirTweets.cd("Tweets");
    setTweetsPath();

    ui->setupUi(this);
    modelFolders = new QStringListModel(this);
    modelJson = new QStringListModel(this);
    folderList=dirTweets.entryList(QDir::AllEntries | QDir::NoDotAndDotDot);

    modelFolders->setStringList(folderList);
    ui->foldersView->setModel(modelFolders);
    updateViews();
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
    QDir::setCurrent(dirJar.path());
    system(c);
    updateViews();
}
void MainWindow::updateViews()
{
    folderList=dirTweets.entryList(QDir::AllEntries | QDir::NoDotAndDotDot);

    modelFolders->setStringList(folderList);
    ui->foldersView->setModel(modelFolders);
}
void MainWindow::updateJsonView(QString str){
    setTweetsPath();
    dirTweetJson.cd(str);

    jsonList=dirTweetJson.entryList(QDir::AllEntries | QDir::Files | QDir::NoDotAndDotDot);

    parseJson(dirTweetJson.path());

    modelJson->setStringList(jsonList);
    ui->jsonsView->setModel(modelJson);
}
void MainWindow::on_foldersView_clicked(const QModelIndex &index)
{
    updateJsonView(getIndex(index));
}
QString MainWindow::getIndex(const QModelIndex &index){
    setTweetsPath();
    QString itemText = index.data(Qt::DisplayRole).toString()+ "/";
    return itemText;
}
void MainWindow::setTweetsPath(){
    dirTweetJson=QDir::currentPath();
    dirTweetJson.cd("src");
    dirTweetJson.cd("Tweets");
}
void MainWindow::on_foldersView_activated(const QModelIndex &index){}

void MainWindow::parseJson(QString path){
    for (int i = 0; i < jsonList.size(); ++i){
        QString filePath = path + "/" + jsonList.at(i).toLocal8Bit().constData();
        jsonPathList.push_back(filePath);
        //cout << path.toStdString() << "/"<< jsonList.at(i).toLocal8Bit().constData() << endl;
    }
}

void MainWindow::on_jsonsView_clicked(const QModelIndex &index)
{
    QMessageBox msgBox;
    QString tweetFileName = index.data(Qt::DisplayRole).toString();
    QString file_path = dirTweetJson.path()+"/"+tweetFileName;

    //////////////////////////////////
    QFile file_obj(file_path);
    if(!file_obj.open(QIODevice::ReadOnly)){
        qDebug()<<"Failed to open "<<file_path;
        exit(1);
    }

    QTextStream file_text(&file_obj);
    QString json_string;
    json_string = file_text.readAll();
    file_obj.close();
    QByteArray json_bytes = json_string.toLocal8Bit();

    auto json_doc=QJsonDocument::fromJson(json_bytes);

    if(json_doc.isNull()){
        qDebug()<<"Failed to create JSON doc.";
        exit(2);
    }
    if(!json_doc.isObject()){
        qDebug()<<"JSON is not an object.";
        exit(3);
    }

    QJsonObject json_obj=json_doc.object();

    if(json_obj.isEmpty()){
        qDebug()<<"JSON object is empty.";
        exit(4);
    }

    QVariantMap json_map = json_obj.toVariantMap();
    QVariantMap user_map = json_map["user"].toMap();
    ///////////////////////////////
    QJsonDocument jsonDoc = QJsonDocument::fromJson(file_path.toLocal8Bit());
    QJsonObject jsonObj = jsonDoc.object();
    QString tweetStr = jsonObj["id"].toString();


    msgBox.setText("@"+user_map["screen_name"].toString()+": "+json_map["text"].toString());
    msgBox.exec();
}
