#pragma once
#include <string>
#include<iostream>

using namespace std;
using namespace System::Drawing;

class Sprits
{
protected:

	int x, y;
	int dx, dy;
	int W, H;
	int indx, indy;

	bool visible;


public:

	Sprits(int W, int H)
	{
		this->W = W;
		this->H = H;
		indx = indy = 0;
		

		visible = true;
	}

	~Sprits(){}

	void dibujar(Graphics^ canvas, Bitmap^ bmp)
	{
		Rectangle  Show = Rectangle(indx * W, indy * H, W, H);
		Rectangle zoom = Rectangle(x, y, W * 1.0, H * 1.0);

		canvas->DrawImage(bmp, Show, zoom, GraphicsUnit::Pixel);
	}

	virtual void mover(){}

	Rectangle getRectangle() { return Rectangle(x, y, W * 1.0, H * 1.0); }

	int getX() { return x; }
	int getY() { return y; }

	bool getVisible() { return visible; }
	void setVisible(bool v) { visible = v; }

	void setX(int v) { x = v; }
	void setY(int v) { y = v; }

};