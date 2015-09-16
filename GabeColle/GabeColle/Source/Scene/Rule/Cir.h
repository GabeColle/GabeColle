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
	void update();
	void draw()const;
	void rightmove();
	void leftmove();
	void sinmove();
	void sinmove2();
	void randommove();
	static void drawEffect();
private:
	static std::unique_ptr<Effect> effect_m;

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