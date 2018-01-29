#include <iostream>
using namespace std;
int main() {
    //Declaramos las variables
    int x;
    int y;
    //Declaramos los apuntadores
    int *ptrEntero;
    int *ptr2Entero;
    //Asignamos el espacio de memoria de los apuntadores
    ptrEntero = &x;
    ptr2Entero = &y;
    //Asignamos valores a los apuntadores
    *ptrEntero = 1;
    *ptr2Entero = 5;
    //Se imprime el valor que tiene asignado la direccion del primer apuntador
    cout <<"Ejemplo 1:" << "El valor de x es: " << x << endl;
    //Incrementamos en valor del primer apuntador
    *ptrEntero += 5;
    //Se imprime el valor del primer apuntador despues de se incrementado
    cout <<"Ejemplo 2"<< "El valor de x, luego de incrementar 5 a *ptrEntero, es: " << x << endl;
    //Se imprime el valor que tiene asigado la direccion del
    cout <<"Ejemplo 3"<< "El valor de y es: " << y << endl;
    //Se imprime el espacio en memoria de la variable y
    cout <<"Ejemplo 4"<< "El valor de &y es: " << &y << endl;
    //Aqui estamos imprimiendo solo el espacio en memoria que tiene asignado el ptr2Entero
    cout <<"Ejemplo 5"<< "El valor de ptr2Entero es: " << ptr2Entero << endl;
    //Se imprime el valor que tiene asigando el segundo apuntador
    cout <<"Ejemplo 6"<< "El valor de *ptr2Entero es: " << *ptr2Entero << endl;
    //Se imprime el espacio en memoria del segundo apuntador
    cout <<"Ejemplo 7"<< "El valor de &ptr2Entero es: " << &ptr2Entero << endl;
    //Se imprime el espacio en memoria del *ptrEntero
    cout <<"Ejemplo 8"<< "El valor de &*ptrEntero es: " << &*ptrEntero << " y el valor de *&ptrEntero es: " << *&ptrEntero << endl;
    //Se imprime el espacio en memoria de la variable x
    cout<<"Ejemplo 9:"<<"El valor de &x es: "<<&x<<endl;
    int sum =x+y;
    cout<<"Ejemplo 10: "<<"El valor de la suma es: "<<sum<<endl;
    cout << "FIN DEL PROGRAMA :)" << endl;
    return 0;
}
