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

    ifstream dict_file("exclude.txt");
    string line;

    while(std::getline(dict_file, line))
    {
        cout<<line;
        excludedWords.push_back(line);
    }

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



    string searchString = "java -jar HashtaggerJava.jar " + ui->searchStringLn->text().toStdString()+" "+to_string(ui->tweetsQuantity->value());
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

    string mystr = clickedTweet.toStdString().substr(0, clickedTweet.toStdString().find("_", 0));
    mainNodo=mystr;
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
    test.resetCachedContent();

    //test.setAttribute(Qt::WA_DeleteOnClose);
    vector<string> words=separateTweet();
    vector<string> wordsFinal=deleteWords(words);

    int posX=0;
    int cont=2;

    int x=300;
    int y=100;

    for(int i=0; i<wordsFinal.size();i++){
        if(wordsFinal.at(i)==mainNodo){
            test.agregarVertice(0,100, 350, wordsFinal.at(i), true);
        }else{
            test.agregarVertice(0, x, y, wordsFinal.at(i),false);
            x+=50;
            y+=50;
        }
        /*if(cont%2==0){
            test.agregarVertice(0,posX, 150, wordsFinal.at(i),false);
        }else{
            test.agregarVertice(0,posX, 250, wordsFinal.at(i),false);
        }
        cont++;
        posX+=50;*/

    }

    vector<string>::iterator it;
    it=std::find(wordsFinal.begin(),wordsFinal.end(),mainNodo);
    //it++;
    int pos = distance(wordsFinal.begin(), it);

    for(int i=1; i<=wordsFinal.size();i++){

        test.agregarArista(100, pos+1, i);
    }
    test.draw();
    test.show();
}

void MainWindow::on_drawGraphBtn_clicked()
{
    /*
    vector<string> words=separateTweet();
    vector<string> wordsFinal=deleteWords(words);

    vector<VerticeClass*> vertVector;
    vector<AristaClass*> ariVector;

    int cant=wordsFinal.size()-1;
    int x=300;
    int y=100;

    for(int i=0; i<wordsFinal.size();i++){
        if(wordsFinal.at(i)==mainNodo){
            vertVector.push_back(new VerticeClass(0, 100, 250, wordsFinal.at(i), true));
        }else{
            vertVector.push_back(new VerticeClass(0, x, y, wordsFinal.at(i), false));
            //x+=50;
            y+=50;
        }
    }

    for(int i=0; i<vertVector.size();i++){
        test.agregarVertice(vertVector.at(i));
    }

    for(int i=0; i<vertVector.size();i++){
        if(vertVector.at(i)->mainNodo){
            for(int j=1; j<=wordsFinal.size();j++){

                test.agregarArista(100, i, j+1);
            }
        }
    }

    for(int i=1; i<=wordsFinal.size();i++){

        test.agregarArista(100, i, i+1);
    }
    test.show();

    cout<<mainNodo<<endl;

    /*
    singleGraph.reset();
    window.resize(280, 270);
    window.setWindowTitle("Full Graph");
    window.show();
    QMessageBox msgBox;
    msgBox.setText("Aqui pondria el grafo de los 100 tweets.....SI SUPIERA COMO HACERLO >:v");
    msgBox.exec();*/
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

vector<string> MainWindow::deleteWords(vector<string> v){
    vector<string> returnVector=v;
    for(int i=0;i<returnVector.size();i++){
        string data =returnVector.at(i);
        transform(data.begin(), data.end(), data.begin(), ::tolower);

        for(int j=0; j<excludedWords.size();j++){
            if(data==excludedWords.at(j)){
                returnVector.erase(returnVector.begin() + i);
            }
        }
    }
    return returnVector;
}

vector<VerticeClass> MainWindow::checkDupes(vector<VerticeClass> v){
    for(int i=0;i<v.size();i++){
        for(int j=v.size()-1;j>=0;j--){
            /*if(v.at(i)==v.at(j)){
                v.erase(v.begin() + j);
                //añadir 1 al nodo
            }*/
        }
    }
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
