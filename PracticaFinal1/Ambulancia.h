#pragma once

#include"Sprits.h"

class Ambulancia : public Sprits
{
private:
	int ayuda;
	char direccion;
public:

	Ambulancia(int W, int H): Sprits(W,H)
	{
		x = 100;
		y = 100;
		dx = dy = 10;
		ayuda = 0;
		direccion = 'W';
	}

	~Ambulancia(){}

	/*void dibujar(Graphics^ canvas, Bitmap^ bmp) {
		Rectangle Shown = Rectangle(indx * W, indy * H, W, H);
		Rectangle zoom = Rectangle(x, y, W * 1.5, H * 1.5);
		canvas->DrawImage(bmp, Shown, zoom, GraphicsUnit::Pixel);
	}*/

	void mover(Graphics^ canvas, char t)
	{
		switch (t)
		{
		case 'A':
			if (x > 0)
			{
				x -= dx;
				indy = 0;
				direccion = 'A';
			}
			break;

		case 'D':
			if (x + W * 1.0 < canvas->VisibleClipBounds.Width)
			{
				x += dx;
				indy = 1;
				direccion = 'D';
			}
			break;
			

		case 'W':
			if (y > 0)
			{
				y -= dy;
				indy = 3;
				direccion = 'W';
			}
			break;

		case 'S':
			if (y + H * 1.0 < canvas->VisibleClipBounds.Height)
			{
				y += dy;
				indy = 2;
				direccion = 'S';
			}
			

			
		}
		indx++;
		if (indx > 3)indx = 0;

	}

	int getAyuda() { return ayuda; }
	void ayudados() { ayuda++; }
};