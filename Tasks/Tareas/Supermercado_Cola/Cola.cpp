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
        cantNodos++;
    }else{
        ultimo->setSig(nuevo);
        nuevo->setSig(0);
        ultimo=nuevo;
        cantNodos++;
    }
}
Clientes * Cola::facturar() {
    Clientes* clienteReturn=primero;
    if(cantNodos>=1){
        Clientes* temp=primero;
        primero=primero->getSig();
        temp=0;
        cantNodos--;

        //clienteReturn->imprimir();
        return clienteReturn;
    }
}

bool Cola::isEmpty() {
    if(cantNodos<1){
        return true;
    }else{
        return false;
    }
}

int Cola::getCantNodos() {
    return cantNodos;
}