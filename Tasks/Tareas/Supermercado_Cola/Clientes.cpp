//
// Created by rbara on 05/02/2018.
//

#include "Clientes.h"
Clientes::Clientes(int tot, string nom) {
    total=tot;
    nombre=nom;
    siguiente=NULL;
}
void Clientes::imprimir() {
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Total: "<<total<<" Lps."<<endl;
}
void Clientes::setSig(Clientes *nodo) {
    siguiente=nodo;

}
Clientes* Clientes::getSig() {
    return siguiente;
}