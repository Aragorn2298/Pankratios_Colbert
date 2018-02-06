//
// Created by rbara on 05/02/2018.
//

#ifndef SUPERMERCADO_COLA_COLA_H
#define SUPERMERCADO_COLA_COLA_H

#include <iostream>
#include "Clientes.h"
using namespace std;

class Cola{
public:
    Cola();
    void hacerFila(int cant, string Nom);
    Clientes *facturar();
    bool isEmpty();
    int getCantNodos();

private:
    Clientes *primero, *ultimo;
    int cantNodos;
};
#endif //SUPERMERCADO_COLA_COLA_H
