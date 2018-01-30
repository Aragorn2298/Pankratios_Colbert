// Tarea1 - Algoritmos.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

void toBin(int x){
	if (x / 2 != 0) {
		toBin(x / 2);
	}
	printf("%d", x % 2);
}

string palindromo(string pal, int ini, int fin)
{
	if (ini < fin) {
		if (pal.at(ini) == pal.at(fin))
		{
			return palindromo(pal, ini + 1, fin - 1);
		}
		return "No es Palindromo";
	}
	return "Palindromo";
}


int main()
{
	string p;
	cout << "Ingrese una palabra: ";
	cin >> p;
	cout << "" << endl;

	cout<<palindromo(p, 0, p.length() - 1)<<endl;
	
	int x;
	cout << "Ingrese un numero: ";
	cin >> x;
	cout << "" << endl;

	toBin(x);
	
	cout << "" << endl;
	system("pause");
	return 0;
}

