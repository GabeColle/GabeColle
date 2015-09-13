#pragma once
#include<Siv3D.hpp>
#include<math.h>

class Cir {
public:

	Cir();
	Cir(int,int,int,int);
	int getX();
	int getY();
	int getE();
	void draw();
	void rightmove();
	void leftmove();
	void sinmove();
	void sinmove2();
	void randommove();

private:

	int x;
	int y;
	int r;
	int speed;
	bool exist;
	Circle t;
	void setValue(int,int,int);
	void right(int);
	void up(int);

};