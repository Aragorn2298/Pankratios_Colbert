//
// Created by xblao on 06/02/2018.
//

#include "Pila.h"
Pila::Pila() {
    primero=NULL;
    cantNodos=0;
}
void Pila::apilar(Nodo* tmp) {
    if(tmp->isOp()){
        int n1,n2;

        n1=stoi(primero->getSig()->getVal());
        n2=stoi(primero->getVal());
        int newVal=0;

        if(tmp->getVal()=="+"){
            newVal=n1+n2;
        }else if(tmp->getVal()=="-"){
            newVal=n1-n2;
        }else if(tmp->getVal()=="*"){
            newVal=n1*n2;
        }else if(tmp->getVal()=="/"){
            newVal=n1/n2;
        }

        desapilar();
        desapilar();
        apilar(new Nodo(to_string(newVal)));
    }else{
        tmp->setSig(primero);
        primero = tmp;
    }
}
int Pila::desapilar() {
    int num ;
    Nodo* tmp;

    tmp = primero;
    num = stoi(tmp->getVal());

    primero = tmp->getSig();
    delete(tmp);

    return num;
}

bool Pila::isEmpty() {
    if(cantNodos<1){
        return true;
    }else{
        return false;
    }
}

int Pila::getCantNodos() {
    return cantNodos;
}

void Pila::mostrar() {
    Nodo* tmp;
    tmp = primero;

    while( tmp !=NULL )
    {
        cout<< tmp->getVal()<<", ";
        tmp = tmp->getSig();
    }
}