//
// Created by xblao on 27/02/2018.
//

#include "HT_ABs.h"

HT_ABs::HT_ABs() {
    count=0;
    countCol=0;
    tableSize=10;
}

void HT_ABs::add(cNodoClass *n) {
    int pos=hashFunc(n->key);
    if(arr[pos]!= nullptr){
        countCol++;
    }
    arr[pos]=n;
}

void HT_ABs::addCol(cNodoClass *n) {
    int pos=hashFunc(n->key);
    if(arr[pos]!= nullptr){
        countCol++;
        cNodoClass* tmp=arr[pos];
        while (tmp->sig != nullptr){
            tmp=tmp->sig;
        }
        tmp->sig=n;
    }else{
        arr[pos]=n;
    }
    count++;
}

int HT_ABs::hashFunc(string k) {
    /*int a= 54059;
    int b= 76963;
    int c= 86969;
    int first= 37;

    while(*k){
        first=(first*a)^(k[0]*b);
        k++;
    }
    return first;
    */
    ////////////////////////
    /*
    int clavee=0, ascii, x=0;
    while(x < (k.length()-1))
    {
        ascii= (int)(k[x]);
        clavee+=ascii;
        x++;
    }
    return clavee%tableSize;
    */
}
/*
string HT_ABs::search(string k) {
    int pos=hashFunc(k);
    if(arr[pos]==NULL)
        return 0;
    return arr[pos]->key;
}
*/