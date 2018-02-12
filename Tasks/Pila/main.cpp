#include <iostream>
#include "Pila.h"
#include "Nodo.h"

using namespace std;

int main() {
    Pila * pilita = new Pila();

    pilita->apilar(new Nodo("5"));
    pilita->apilar(new Nodo("1"));
    pilita->apilar(new Nodo("2"));
    pilita->apilar(new Nodo("+"));
    pilita->apilar(new Nodo("4"));
    pilita->apilar(new Nodo("*"));
    pilita->apilar(new Nodo("+"));
    pilita->apilar(new Nodo("3"));
    pilita->apilar(new Nodo("-"));

    pilita->mostrar();

    return 0;
}