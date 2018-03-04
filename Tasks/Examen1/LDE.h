//
// Created by xblao on 27/02/2018.
//

#ifndef EXAMEN1_LDE_H
#define EXAMEN1_LDE_H

#include "Nodo.h"

class LDE {
public:
    LDE();

    bool add(Nodo* n);
    bool deleteInt(int n);
    int maxRep();
    int maxDif();
    void print();

    Nodo* inicio;
    Nodo* final;
    Nodo* centi;
};


#endif //EXAMEN1_LDE_H
