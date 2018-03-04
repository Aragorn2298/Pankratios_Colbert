//
// Created by xblao on 27/02/2018.
//

#include "LDE.h"
#include <iostream>
using namespace std;
LDE::LDE() {
    centi=new Nodo(-1);
    centi->sig=centi;
    centi->ant= nullptr;
    inicio=centi;
    final=centi;
}

bool LDE::add(Nodo *n) {
    if(inicio==centi){
        inicio=n;
        final=n;
        n->sig=centi;
        centi->ant=n;
        return true;
    }else if(n->valueN > inicio->valueN){
        n->sig=inicio->sig;
        inicio=n;
        return true;
    }else if(n->valueN < final->valueN){
        n->ant=final->ant;
        n->sig=centi;
        final->ant->sig=n;
        final=n;
        return true;
    }else{
        Nodo* tmp=inicio;
        while(tmp != centi){
            if(tmp->valueN < n->valueN){
                n->ant=tmp->ant;
                n->sig=tmp;
                tmp->ant=n;
                return true;
            }else if(tmp->valueN == n->valueN){
                n->ant=tmp->ant;
                n->sig=tmp;
                tmp->ant=n;
                return true;
            }else{
                Nodo* tmp2=tmp;
                while(tmp2->valueN == tmp->valueN){
                    tmp2=tmp2->sig;
                }
                if(n->valueN>=tmp2->valueN){
                    n->ant=tmp2->ant;
                    n->sig=tmp2;
                    tmp2->ant=n;
                    return true;
                }
            }
        }
    }
    return false;
}

bool LDE::deleteInt(int n) {
    if(inicio==centi){
        cout<<"no hay nodos"<<endl;
        return false;
    }else{
        Nodo* tmp=inicio;
        while(tmp->sig!=centi){
            if(tmp->valueN==n && tmp==inicio){
                inicio=tmp->sig;
                tmp->sig->ant=NULL;
                tmp->sig=centi;
                return true;
            }else if(tmp->valueN==n && tmp==final){
                final=tmp->ant;
                tmp->ant=centi;
                centi->ant=final;
                tmp->sig=centi;
                return true;
            }else if(tmp->valueN==n){
                tmp->ant->sig=tmp->sig;
                tmp->sig->ant=tmp->ant;
                tmp->sig=centi;
                return true;
            }else{
                tmp=tmp->sig;
            }
        }
    }
    return false;
}

int LDE::maxRep() {
    Nodo* tmp=inicio;
    int numFinal=0;
    int cantFinal=0;
    while(tmp->sig!=centi){
        int numActual=tmp->valueN;
        int cantActual=1;
        Nodo* tmp2=tmp;
        while(tmp2->valueN == tmp2->sig->valueN){
            tmp2=tmp2->sig;
            cantActual++;
        }

        if(cantActual>cantFinal){
            cantFinal=cantActual;
            numFinal=numActual;
        }
        tmp=tmp2->sig;
    }
    return numFinal;
}

int LDE::maxDif() {
    return inicio->valueN-final->valueN;
}

void LDE::print() {
    Nodo* tmp=inicio;
    while(tmp!=centi){
        cout<<tmp->valueN<<endl;
        tmp=tmp->sig;
    }
}
