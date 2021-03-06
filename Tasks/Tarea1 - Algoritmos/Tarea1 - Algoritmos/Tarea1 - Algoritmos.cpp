// Tarea1 - Algoritmos.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cstdio>

using namespace std;

void toBin(int x){ 
	//Esta funcion, recursivamente, convierte un numero entero a binario
	if (x / 2 != 0) {
		toBin(x / 2);
	}
	printf("%d", x % 2);
}

string palindromo(string pal, int ini, int fin){ 
	//Esta funcion recursivamente comprueba si la palabra ingresada es palindromo o no
	// ini=0; fin=pal.length()-1;
	if (ini < fin) {
		if (pal.at(ini) == pal.at(fin))
		{
			return palindromo(pal, ini + 1, fin - 1);
		}
		return "No es Palindromo";
	}
	return "Palindromo";
}

int checkWord(const string &needle, const string &haystack) {
	/* Algoritmo Knuth-Morris-Pratt */
	
	int count = 0;
	int m = needle.size();
	vector<int> border(m + 1);
	border[0] = -1;
	for (int i = 0; i < m; ++i) {
		border[i + 1] = border[i];
		while (border[i + 1] > -1 and needle[border[i + 1]] != needle[i]) {
			border[i + 1] = border[border[i + 1]];
		}
		border[i + 1]++;
	}

	int n = haystack.size();
	int seen = 0;
	for (int i = 0; i < n; ++i) {
		while (seen > -1 and needle[seen] != haystack[i]) {
			seen = border[seen];
		}
		if (++seen == m) {
			seen = border[m];
			count++;
		}
	}
	return count;

	/*
	if (subPal.length() == 0) return 0;
	int count = 0;
	for (size_t offset = pal.find(subPal); offset != std::string::npos;
		offset = pal.find(subPal, offset + subPal.length()))
	{
		++count;
	}
	return count;
	*/
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

	cout<<"'"<<subPal<<"' se repite "<<checkWord(subPal, pal)<<" veces en '"<<pal<<"'"<<endl;

	system("pause");
	return 0;
}

