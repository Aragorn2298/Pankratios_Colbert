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
    ui->foldersView->setEditTriggers(QListView::NoEditTriggers);
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

    jsonList=dirTweetJson.entryList(QDir::AllEntries | QDir::Files | QDir::NoDotAndDotDot,QDir::Time | QDir::Reversed);

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

void MainWindow::parseJson(const QModelIndex &index){
    QString tweetFileName = index.data(Qt::DisplayRole).toString();
    QString file_path = dirTweetJson.path()+"/"+tweetFileName;

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

    json_map = json_obj.toVariantMap();
    user_map = json_map["user"].toMap();
}

void MainWindow::on_jsonsView_clicked(const QModelIndex &index)
{
    clear();
    clickedTweet=index.data(Qt::DisplayRole).toString();
    parseJson(index);
    clickedTweetText=json_map["text"].toString();
}

void MainWindow::on_jsonsView_doubleClicked(const QModelIndex &index)
{
    QMessageBox msgBox;
    parseJson(index);
    QString name="<font color=\"Black\">"
                    "<b>"+
                        user_map["name"].toString()+
                    "</b>"
                 "</font>";

    QString screen_name="<font color=\"Gray\">"
                            "<small>"
                                "@"+user_map["screen_name"].toString()+
                            "</small>"
                        "</font>";

    QString text="<p>"
                    "<font color=\"Black\">"+
                        json_map["text"].toString()+
                    "</font>"
                 "</p>";

    QString created_at="<p style=""text-align:right;"">"
                           "<font color=\"Black\">"
                               "<small>"+
                                    json_map["created_at"].toString()+
                               "</small>"
                           "</font>"
                       "</p>";

    msgBox.setText(name+"  "+screen_name+
                   text+
                   created_at);
    msgBox.exec();
}

void MainWindow::on_singleTweetBtn_clicked()
{
    /*
    string input=clickedTweet.toStdString();
    istringstream ss(input);
    string token;
    string printString="";

    while(getline(ss,token,'_')){
        printString=token;
        break;
    }
    */
    vector<string> words=separateTweet();
    int posX=0;
    int cont=2;
    for(int i=0; i<words.size();i++){
        if(cont%2==0){
            test.agregarVertice(100, posX, 150, words.at(i));
        }else{
            test.agregarVertice(100, posX, 250, words.at(i));
        }
        cont++;
        posX+=50;
    }
    for(int i=1; i<=words.size();i++){

        test.agregarArista(100, i, i+1);
    }
    test.draw();
    test.show();
}

void MainWindow::on_drawGraphBtn_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Aqui pondria el grafo de los 100 tweets.....SI SUPIERA COMO HACERLO >:v");
    msgBox.exec();
}
vector<string> MainWindow::separateTweet(){
    string s = clickedTweetText.toStdString();
    string str=s;
    string buf;
    stringstream ss(str);

    vector<string> words;

    while(ss >> buf){
        words.push_back(buf);
    }
    return words;
}
void MainWindow::clear(){
    //test.reset();
    clickedTweetText="";
    test.resetCachedContent();
    test.scene->clear();
    test.items().clear();
    test.scene->update();
    test.update();
    test.close();
}
