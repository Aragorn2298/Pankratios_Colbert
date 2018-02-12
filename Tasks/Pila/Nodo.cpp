//
// Created by xblao on 06/02/2018.
//

#include "Nodo.h"
#include <stdio.h>
using namespace std;

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
inline bool Nodo::isInteger(const std::string & s) {
    if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false ;

    char * p ;
    strtol(s.c_str(), &p, 10) ;

    return (*p == 0) ;
}