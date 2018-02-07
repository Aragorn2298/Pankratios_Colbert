#include <iostream>
#include "Pila.h"
#include "Nodo.h"

using namespace std;

int main() {
    Pila * pilita = new Pila();

    pilita->apilar("5");
    pilita->apilar("1");
    pilita->apilar("2");
    pilita->apilar("+");
    pilita->apilar("4");
    pilita->apilar("*");
    pilita->apilar("+");
    pilita->apilar("3");
    pilita->apilar("-");

    pilita->mostrar();

    return 0;
}