// Tarea1 - Algoritmos.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>

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

int checkWord(string pal, string subPal) {
	if (subPal.length() == 0) return 0;
	int count = 0;
	for (size_t offset = pal.find(subPal); offset != std::string::npos;
		offset = pal.find(subPal, offset + subPal.length()))
	{
		++count;
	}
	return count;
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
	
	string pal;
	string subPal;
	
	cout << "Ingrese Palabra 1: ";
	cin >> pal;
	cout << "" << endl;
	cout << "Ingrese Palabra a buscar: ";
	cin >> subPal;
	cout << "" << endl;

	cout<<checkWord(pal, subPal)<<endl;

	system("pause");
	return 0;
}

