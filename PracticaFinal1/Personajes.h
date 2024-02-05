#pragma once
#include"Sprits.h"

//string velocidad = { 10,8,2,4 };

class Personaje : public Sprits
{

public:

	Personaje(int W, int H) : Sprits(W, H)
	{
		x = rand() %700;
		y = rand() % 500;
		dx = 5;//velocidad[rand() % 3];
	}
	~Personaje(){}

	void mover(Graphics^ canvas)
	{
		if (x + W * 1.0 < canvas->VisibleClipBounds.Width )
		{
			x += dx;
			indy = 1;
		}
		else if (x > 0)
		{
			x -= dx;
			indy = 0;
		}

		indx++;
		if (indx > 7)indx = 0;
	}
	//Rectangle getRecangle() { return Rectangle(x, y, W * 1.0, H * 1.0); }

};