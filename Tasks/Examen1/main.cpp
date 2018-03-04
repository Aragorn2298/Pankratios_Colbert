#include <iostream>
#include "HT_ABs.h"
#include "LDE.h"
#include "Nodo.h"
#include "cNodoClass.h"
using namespace std;
int main() {
    LDE* listita = new LDE();

    listita->add(new Nodo(1));
    listita->add(new Nodo(2));
    listita->add(new Nodo(3));
    listita->add(new Nodo(3));
    listita->add(new Nodo(3));
    listita->add(new Nodo(5));

    cout<<listita->maxDif()<<endl;

    cout<<listita->maxRep()<<endl;

    listita->print();

    return 0;
}