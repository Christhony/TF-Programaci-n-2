#pragma once
#include"Personajes.h"
#include"Ambulancia.h"
#include<vector>

using namespace std;

class Controlador
{
private:
	Ambulancia* ambu;
	vector<Personaje*>person;
	int tiempo;
	int puntaje;

public:

	Controlador(Bitmap^ bmpAmbulancia,  int tiempo)
	{
		ambu = new Ambulancia(bmpAmbulancia->Width / 4, bmpAmbulancia->Height / 4);
		//person = new Personaje(bmpPersona->Width / 7, bmpPersona->Height / 2);
		this->tiempo = tiempo;
		puntaje = 0;
		
	}

	~Controlador() {}

	void agregarPersona(Personaje* p)
	{
		person.push_back(p);
	}

	void dibujarTodo(Graphics^ canvas, Bitmap^ bmpAmbulancia, Bitmap^ bmpPersona)
	{
		ambu->dibujar(canvas, bmpAmbulancia);
		for (int i = 0; i < person.size(); i++)
		{
			person[i]->dibujar(canvas, bmpPersona);
		}
	}

	void moverTodo(Graphics^ canvas)
	{
		for (int i = 0; i < person.size(); i++)
		{
			person[i]->mover(canvas);
		}
	}

	void colision()
	{
		//verificacion
		for (int i = 0; i < person.size(); i++)
		{
			if (ambu->getRectangle().IntersectsWith(person[i]->getRectangle()))
			{
				person[i]->setVisible(false);
				ambu->ayudados();
				puntaje += 50;
			}
		}

		//Eliminacion
		for (int i = 0; i < person.size(); i++)
		{
			if (!person[i]->getVisible())
			{
				person.erase(person.begin() + i);
			}
		}
	}

	Ambulancia* getAmbulancia() { return ambu; }

	int getTiempo() { return tiempo; };
	int getPuntaje() { return puntaje; }
	void decreceTiempo() { tiempo--; }


};