#include "graphwindow.h"

GraphWindow::GraphWindow(QWidget *parent) : QWidget(parent){
    setMinimumSize(960, 540);
    setStyleSheet("background-color: black");
    cant=0;
}
void GraphWindow::agregarVertice(int x, int y, string n)
{

}
void GraphWindow::agregarArista(int p, int from, int to){
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
    this->update();
    update();
}

void GraphWindow::paintEvent(QPaintEvent *e) {

  Q_UNUSED(e);

  QPainter qp(this);
  draw(&qp);
}
void GraphWindow::draw(QPainter *qp) {
    QPen pen1;
    pen1.setWidth(3);
    pen1.setColor(Qt::lightGray);
    pen1.setBrush(QBrush(Qt::lightGray,Qt::SolidPattern));
    qp->setPen(pen1);
    qp->drawEllipse(100,100,100,100);

    QPen pen;
    QPen penArista;
    pen.setWidth(3);
    penArista.setWidth(3);

    qp->setPen(penArista);

    for(unsigned int p=0;p<aristas.size();p++)
    {
        int xa = aristas[p].x();
        int ya = aristas[p].y();
        int xb = aristas[p].width();
        int yb = aristas[p].height();
        penArista.setColor(Qt::lightGray);
        qp->drawLine(xa+37,ya+37,xb+37,yb+37);
    }

    qp->setPen(pen);

    for(unsigned int c=0;c<vertices.size();c++)
    {
        pen.setColor(Qt::black);
        pen.setBrush(QBrush(Qt::lightGray,Qt::SolidPattern));
        string namem = grafito.vertices.at(c)->name;
        QString qstr = QString::fromStdString(namem);
        qp->setFont(QFont("System", 11));

        qp->drawEllipse(vertices.at(c));
        qp->drawText(vertices.at(c).x(), vertices.at(c).y()+20, qstr);
    }
}
void GraphWindow::reset(){
    vertices.clear();
    aristas.clear();
    cant=0;
    this->update();
    update();
}
