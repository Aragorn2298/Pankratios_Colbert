#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H
#include <QPainter>
#include <QWidget>
#include "grafoclass.h"
#include "aristaclass.h"
#include "verticeclass.h"

class GraphWindow : public QWidget
{
    Q_OBJECT
public:
    GraphWindow(QWidget *parent = 0);
    void agregarVertice(int x, int y, string nombre);
    void agregarArista(int p, int from, int to);
    void reset();

    GrafoClass grafito;
    vector<QRectF> vertices;
    vector<QRectF> aristas;
    int cant;
    int cantV;
    int contName;
    vector<bool> verticeCam;
    vector<bool> aristaCam;
protected:
  void paintEvent(QPaintEvent *event);
  void draw(QPainter *qp);
};

#endif // GRAPHWINDOW_H
