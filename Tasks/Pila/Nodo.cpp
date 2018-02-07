//
// Created by xblao on 06/02/2018.
//

#include "Nodo.h"
Nodo::Nodo(string val) {
    valor=val;
}
void Nodo::setSig(Nodo *nodo) {
    siguiente=nodo;

}
Nodo* Nodo::getSig() {
    return siguiente;
}

string Nodo::getVal() {
    return valor;
}
bool Nodo::isOp() {
    if(valor=="+" || valor=="-" || valor=="*" || valor=="/"){
        return true;
    }else{
        return false;
    }
}