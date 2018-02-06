//
// Created by xblao on 05/02/2018.
//

#ifndef LISTAS_ARBOLMANGO_MANGO_H
#define LISTAS_ARBOLMANGO_MANGO_H


class Mango {
public:
    Mango(int peso);
private:
    Mango* sig;
    Mango* ant;
    int peso;
};


#endif //LISTAS_ARBOLMANGO_MANGO_H
