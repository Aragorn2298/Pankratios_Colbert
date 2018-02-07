//
// Created by xblao on 06/02/2018.
//

#ifndef PILA_PILA_H
#define PILA_PILA_H
#include <iostream>
#include "Nodo.h"
using namespace std;

class Pila {
public:
    Pila();
    void apilar(string val);
    int desapilar();
    bool isEmpty();
    int getCantNodos();
    void mostrar();

private:
    Nodo *primero;
    int cantNodos;

};


#endif //PILA_PILA_H
