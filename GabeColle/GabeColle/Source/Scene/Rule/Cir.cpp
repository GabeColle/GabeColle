#include "Cir.h"


//コンストラクタ
Cir::Cir(){
	this->x = 0;
	this->y = 0;
	this->r = 0;
	this->exist = true;
}
Cir::Cir(int x,int y,int r,int sp){
	this->speed = sp;
	setValue(x, y, r);
}


//移動パターン1(右に動くだけ)
void Cir::rightmove(){
	this->right(this->speed);
}
//移動パターン2(左に動くだけ)
void Cir::leftmove(){
	this->right(-this->speed);
}


//描画
void Cir::draw(){
	if (t.leftClicked)this->exist = false;
	if(this->exist)this->t.draw(HSV(System::FrameCount()));
}

//値を入れる
void Cir::setValue(int x,int y,int r){
	this->x = x;
	this->y = y;
	this->r = r;
	this->t = Circle(x,y,r);
}


//移動
void Cir::right(int sp){
	this->x += sp;
	if (this->x < 0)this->x = Window::Width();
	if (this->x > Window::Width())this->x = 0;
	this->setValue(this->x, this->y,this->r);
}
void Cir::up(int sp){
	this->y += sp;
	if (this->y < 0)this->x = Window::Height();
	if (this->y > Window::Height())this->x = 0;
	this->setValue(this->x,this->y,this->r);
}
