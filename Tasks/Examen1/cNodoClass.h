//
// Created by xblao on 27/02/2018.
//

#ifndef EXAMEN1_CNODOCLASS_H
#define EXAMEN1_CNODOCLASS_H

#include <stdio.h>
#include <iostream>

using namespace std;
class cNodoClass {
public:
    cNodoClass(string k, string v);
    string key;
    string value;
    cNodoClass* sig;
};


#endif //EXAMEN1_CNODOCLASS_H
