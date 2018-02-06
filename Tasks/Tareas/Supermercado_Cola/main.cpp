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

    cout<<"Cant: "<<LaColonia->getCantNodos()<<endl;

    LaColonia->facturar();
    cout<<"Cant: "<<LaColonia->getCantNodos()<<endl;
    LaColonia->facturar();
    cout<<"Cant: "<<LaColonia->getCantNodos()<<endl;
    LaColonia->facturar();
    cout<<"Cant: "<<LaColonia->getCantNodos()<<endl;
    LaColonia->facturar();
    cout<<"Cant: "<<LaColonia->getCantNodos()<<endl;
    LaColonia->facturar();

    cout<<"Cant: "<<LaColonia->getCantNodos()<<endl;


    std::cout << "Hello, World!" << std::endl;
    return 0;
}