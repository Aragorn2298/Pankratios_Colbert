//
// Created by xblao on 06/02/2018.
//

#ifndef PILA_NODO_H
#define PILA_NODO_H
#include <iostream>
using namespace std;

class Nodo {
public:
    Nodo(string val);
    void setSig(Nodo *nodo);
    Nodo *getSig();
    string getVal();
    bool isOp();
    inline bool isInteger(const std::string & s);

private:
    string valor;
    Nodo *siguiente;
    int num;
};


#endif //PILA_NODO_H
