#include "verticeclass.h"

VerticeClass::VerticeClass()
{
    peso=0;
    ex=0;
    ey=0;
    name="";
}
VerticeClass::VerticeClass(int p, int x, int y, string n, bool mn){
    peso=1;
    ex=x;
    ey=y;
    ID=0;
    name=n;
}
