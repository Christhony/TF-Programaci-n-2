#pragma once

#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string>

using namespace std;
using namespace System;

class Dato
{
private:
	ofstream escribir;
	ifstream leer;
	string texto;

	int segundosPersonas;
	int tiempo;
public:

	Dato() {}
	~Dato() {}

	void leerDatos()
	{
		leer.open("configuration.txt", ios::in);

		if (leer.fail())
		{
			leer.close();

			escribir.open("auxiliar.txt", ios::out);
			escribir << "3" << endl;
			escribir << "30" << endl;
			escribir.close();

			leer.open("auxiliar.txt", ios::in);
		}

		getline(leer, texto);
		segundosPersonas = atoi(texto.c_str());

		getline(leer, texto);
		tiempo = atoi(texto.c_str());

		leer.close();
	}

	int getsegundosPersona() { return segundosPersonas; }
	int getTiempo() { return tiempo; }

};