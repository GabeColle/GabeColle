#include "Cir.h"

std::unique_ptr<Effect> Cir::effect_m;

void Cir::drawEffect()
{
	if (effect_m != nullptr){
		effect_m->update();
	}
}

struct Snow : IEffect
{
	struct Particle
	{
		Vec2 pos, v0;
	};

	Array<Particle> m_particles;

	Snow(const Point& pos, int count)
		: m_particles(count)
	{
		for (auto& particle : m_particles)
		{
			const Vec2 v = Circular(Random(10.0, 80.0), Random(TwoPi));
			particle.pos = pos + v;
			particle.v0 = v * 2.0;
		}
	}

	bool update(double t) override
	{
		for (const auto& particle : m_particles)
		{
			const Vec2 pos = particle.pos + particle.v0 * t + 0.5* t*t * Vec2(0, 320);

			Circle(pos, 3).draw(HSV(pos.y / 4.0, 1.0, 1.0).toColorF(1.0 - t));
		}

		return t < 1.0;
	}
};

//コンストラクタ
Cir::Cir()
	:Cir(0,0,0,0)
{
	this->exist = true;
}
Cir::Cir(int x,int y,int r,int sp){
	this->speed = sp;
	setValue(x, y, r);
	if (effect_m == nullptr){
		effect_m = std::make_unique<Effect>();
	}
}


int Cir::getX(){
	return this->x;
}
int Cir::getY(){
	return this->y;
}
int Cir::getE(){
	return this->exist;
}

//1(右に動くだけ)
void Cir::rightmove(){
	this->right(this->speed);
}
//2(左に動くだけ)
void Cir::leftmove(){
	this->right(-this->speed);
}
//3(分からん動き)
void Cir::sinmove(){
	this->right(Random(0,10));
	this->up(-speed);
}
//4(分からん動き)
void Cir::sinmove2(){
	this->right(Random(0, 10));
	this->up(speed);
}

void Cir::update(){
	if (t.leftClicked){
		this->exist = false;
		effect_m->add<Snow>(Point({ x, y }), 50);
	}
}
//描画
void Cir::draw()const{
	
	if(this->exist)this->t.draw(HSV(2*System::FrameCount(), 0.8, 0.5).toColor(63));
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
	this->y -= sp;
	if (this->y < 0)this->y = Window::Height();
	if (this->y > Window::Height())this->y = 0;
	this->setValue(this->x,this->y,this->r);
}
