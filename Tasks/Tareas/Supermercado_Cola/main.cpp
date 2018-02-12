#include <iostream>
#include "Cola.h"
#include "Clientes.h"

int main() {
    Cola* LaColonia = new Cola();

    LaColonia->hacerFila(12, "Jose");
    LaColonia->hacerFila(524990, "Joa");
    LaColonia->hacerFila(240, "Byron");
    LaColonia->hacerFila(320, "Diego");
    LaColonia->hacerFila(250, "Gerardito");

    cout<<"Cant Clientes: "<<LaColonia->getCantNodos()<<endl;
    cout<<""<<endl;
    LaColonia->facturar()->imprimir();
    cout<<"Cant Clientes: "<<LaColonia->getCantNodos()<<endl;
    cout<<""<<endl;
    LaColonia->facturar()->imprimir();
    cout<<"Cant Clientes: "<<LaColonia->getCantNodos()<<endl;
    cout<<""<<endl;
    LaColonia->facturar()->imprimir();
    cout<<"Cant Clientes: "<<LaColonia->getCantNodos()<<endl;
    cout<<""<<endl;
    LaColonia->facturar()->imprimir();
    cout<<"Cant Clientes: "<<LaColonia->getCantNodos()<<endl;
    cout<<""<<endl;
    LaColonia->facturar()->imprimir();
    cout<<"Cant Clientes: "<<LaColonia->getCantNodos()<<endl;
    cout<<""<<endl;
    return 0;
}