//
// Created by rbara on 05/02/2018.
//
#include "Cola.h"

Cola::Cola() {
    primero=NULL;
    ultimo=NULL;
    cantNodos=0;
}
void Cola::hacerFila(int cant, string Nom) {
    Clientes *nuevo = new Clientes(cant, Nom);
    if (cantNodos < 1) {
        primero = nuevo;
        ultimo = nuevo;
        nuevo->setSig(0);
    }else{

    }
}
