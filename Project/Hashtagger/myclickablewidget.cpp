#include "myclickablewidget.h"
#include <QtWidgets>
#include <QDebug>
#include <iostream>
#include <QLineF>
#include <QRectF>

using namespace std;

MyClickableWidget::MyClickableWidget(QWidget *parent)
    : QGraphicsView(parent)
{
    //scene = new QGraphicsScene();
    setMinimumSize(960, 540);
    setMouseTracking(true);
    setBackgroundBrush(QBrush(Qt::black,Qt::SolidPattern));
    //setSceneRect(10,10,960,540);
    setScene(scene);
    scene->update();
    cant=0;
    cantV=0;
    contName=1;

}
void MyClickableWidget::agregarVertice(int p, int x, int y, string n, bool mn)
{
    VerticeClass* nuevo = new VerticeClass(p,x,y,n,mn);
    grafito.vertices.push_back(nuevo);
    QRectF vertNuevo(x,y, 75.0, 75.0);
    vertices.push_back(vertNuevo);
    for(unsigned int i=0;i<vertices.size();i++)
    {
        verticeCam.push_back(false);
    }
    for(unsigned int i=0;i<aristas.size();i++)
    {
        aristaCam.push_back(false);
    }
    scene->update();
    update();
    draw();
}
void MyClickableWidget::agregarVertice(VerticeClass* nuevo)
{
    agregarVertice(nuevo->peso,nuevo->ex,nuevo->ey,nuevo->name, nuevo->mainNodo);
}
void MyClickableWidget::agregarArista(int p, int from, int to){
    if(grafito.vertices[from-1]!=NULL && grafito.vertices[to-1]!=NULL)
    {
        VerticeClass* fromu = grafito.vertices[from-1];
        VerticeClass* tou = grafito.vertices[to-1];
        AristaClass* nuevaArista = new AristaClass(p,fromu,tou);
        nuevaArista->id=cant;
        grafito.vertices[from-1]->aristas.push_back(nuevaArista);
        QRectF oc(fromu->ex,fromu->ey, tou->ex,tou->ey);
        aristas.push_back(oc);
        cant++;
    }
    for(unsigned int g=0;g<vertices.size();g++)
    {
        verticeCam.push_back(false);
    }
    for(unsigned int gg=0;gg<aristas.size();gg++)
    {
        aristaCam.push_back(false);
    }
    scene->update();
    update();
}
void MyClickableWidget::draw(){
    QPen pen;
    QPen penArista;
    pen.setWidth(3);
    penArista.setWidth(3);
    for(unsigned int p=0;p<aristas.size();p++)
    {
        if(aristaCam[p]==true)
        {
            int xa = aristas[p].x();
            int ya = aristas[p].y();
            int xb = aristas[p].width();
            int yb = aristas[p].height();
            penArista.setColor(Qt::yellow);
            scene->addLine(xa+37,ya+37,xb+37,yb+37, penArista);
        }
        else
        {
            int xa = aristas[p].x();
            int ya = aristas[p].y();
            int xb = aristas[p].width();
            int yb = aristas[p].height();
            penArista.setColor(Qt::lightGray);
            scene->addEllipse(xa+10,ya+10,10,10,pen,QBrush(Qt::lightGray,Qt::SolidPattern));
            scene->addLine(xa+37,ya+37,xb+37,yb+37, penArista);

        }
    }
    for(unsigned int c=0;c<vertices.size();c++)
    {
        if(verticeCam[c]==true)
        {
            pen.setColor(Qt::yellow);
            scene->addEllipse(vertices.at(c),pen,QBrush(Qt::lightGray,Qt::SolidPattern));
        }
        else
        {
            pen.setColor(Qt::black);
            scene->addEllipse(vertices.at(c),pen,QBrush(Qt::lightGray,Qt::SolidPattern));
            QGraphicsTextItem* text;
            QGraphicsTextItem* text2;
            QString qstr = QString::fromStdString(grafito.vertices.at(c)->name);
            QString qstr2 = QString::fromStdString(to_string(grafito.vertices.at(c)->peso));
            text= scene->addText(qstr,QFont("System", 8));
            text->setTextWidth(65);
            text->setPos(vertices.at(c).x()+5, vertices.at(c).y()+10);
            text2= scene->addText(qstr2,QFont("System", 8, 10, true));
            text2->setPos(vertices.at(c).x()+30, vertices.at(c).y()+55);
        }
    }
    scene->update();
}
void MyClickableWidget::reset(){
    vertices.clear();
    aristas.clear();
    cant=0;
    cantV=0;
    contName=0;
    scene->update();
}
