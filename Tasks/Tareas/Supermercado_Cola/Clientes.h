//
// Created by rbara on 05/02/2018.
//

#ifndef SUPERMERCADO_COLA_CLIENTES_H
#define SUPERMERCADO_COLA_CLIENTES_H
#include <iostream>
using namespace std;

class Clientes {
public:
    Clientes(int tot,string nom);
    void imprimir();
    void setSig(Clientes *nodo);
    Clientes *getSig();
    string getNombre();
    int getTotal();

private:
    int total;
    string nombre;
    Clientes *siguiente;
};


#endif //SUPERMERCADO_COLA_CLIENTES_H
