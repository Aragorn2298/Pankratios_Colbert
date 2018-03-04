//
// Created by xblao on 27/02/2018.
//

#ifndef EXAMEN1_HT_ABS_H
#define EXAMEN1_HT_ABS_H


#include "cNodoClass.h"

class HT_ABs {
public:
    HT_ABs();

    void add(cNodoClass* n);
    void addCol(cNodoClass* n);
    int hashFunc(string k);
    string search(string k);
    int count;
    int countCol;
    int tableSize;
    cNodoClass* arr[10];
};


#endif //EXAMEN1_HT_ABS_H
