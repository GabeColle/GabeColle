#include "Game2.h"
#include"Game2GabeColle.h"

using namespace game2;

void drawMemory(gc::Memory<CircleObject> const &memory);

// クラスの初期化時に一度だけ呼ばれる（省略可）
void Game2::init()
{
	// ルートを画面中央に
	memory_m.root().center(rootPos);

	time_m = 0;
	count_m = 0;
	garbage_m = 0;
	segmentFault_m = 0;
	process_m = 0;
	state = State::draw;
}

// 毎フレーム updateAndDraw() で呼ばれる
void Game2::update()
{
	if (static_cast<int> (state) < 3 )
	{
		if (System::FrameCount() % 6 == 0)
		{
			bool isOutOfMemory = false;
			double rad = count_m * 360.0/ NUM_OF_MEMORY *Pi /180 ;
			int radius = Random(200, 300);

			switch (state)
			{
			break; case State::draw:
				isOutOfMemory = !allocAndReferenceFromRoot({ rootPos.x + radius * cos(rad), rootPos.y + radius * sin(rad) });				
				
			break; case State::MtoM:
				memory_m.link(count_m, Random(NUM_OF_MEMORY));

			break; case State::erase:
				if (Random(NUM_OF_MEMORY/3)){
					memory_m.unlink(0, count_m);
				}
			break;
			}
			countAndChangeState(isOutOfMemory);
		}
	}
	else if (state == State::input )
	{
		time_m++;
		freeByInput();
		seekSegmentFault();
		if (button_m.leftClicked()){
			garbage_m = Game2GabeColle<game2::CircleObject>::gc(memory_m);
			m_data->error = garbage_m + segmentFault_m;
			m_data->time = time_m;
			m_data->process = process_m;
			m_data->score = 100000 - time_m *2 - garbage_m * 1000 - segmentFault_m * 2000 + process_m * 200;
			state = State::result;
		}
	}
	else if (state == State::result)
	{
		if (Input::MouseL.clicked){
			changeScene(L"Start", 2000);
		}
	}
}

// 毎フレーム update() の次に呼ばれる
void Game2::draw() const
{
	ClearPrint();
	Println(Format(L"TIME ",time_m));
	Println(Format(L"COUNT ", count_m));
	Println(Format(L"Garbage", garbage_m));
	Println(Format(L"SegmentFault", segmentFault_m));
	Println(Format(L"State", static_cast<int>( state )));

	Println(L"----------------------");
	Println(Format(L"TIME ", m_data->time));
	Println(Format(L"Process ", m_data->process));
	Println(Format(L"Error ", m_data->error));
	Println(Format(L"Score ", m_data->score));



	drawMemory(memory_m);
	button_m.draw();
}

//クリックでメモリ解放
void Game2::freeByInput(){
	for (int i(1); i <= NUM_OF_MEMORY; ++i) {
		if (!memory_m.hasExpired(i) && Circle(memory_m.access(i).center(), 40.0).leftClicked) {
			memory_m.free(i);
			process_m++;
		}
	}
}

//セグメントフォルトをカウントし、参照を消す
void Game2::seekSegmentFault(){

	for (int i = 1; i <= NUM_OF_MEMORY; ++i) {
		if (memory_m.hasExpired(i)) {
			for (int j = 0; j <= NUM_OF_MEMORY; ++j) {
				if (memory_m.getRelation().areLinked(j, i)){
					segmentFault_m++;
					memory_m.unlink(j, i);
				}
			}
		}
	}
}

void Game2::countAndChangeState(bool isOutOfMemory){

	if (!isOutOfMemory){
	count_m++;
	}

	if (count_m % NUM_OF_MEMORY == 0){
		count_m = 0;
		state = static_cast<State> (static_cast<int>(state)+1);
	}
}

void drawMemory(gc::Memory<CircleObject> const &memory)
{
	static Font font;
	font.drawCenter(L"Root", Circle(memory.root().center(), 50.0).draw(Palette::Aqua).center);

	//オブジェクトを描く
	auto drawCircle = [&memory](int address)
	{
		double const r = 40.0;
		if (!memory.hasExpired(address)) {
			Circle c = Circle(memory.access(address).center(), r);
			if (c.mouseOver) {
				c.draw(Color(Palette::Pink, 128)).drawFrame(0.0, 3.0, Palette::Red);
			}
			else {
				c.draw(Color(Palette::Red, 128)).drawFrame(0.0, 3.0, Palette::Darkred);
			}
			font.drawCenter(ToString(address), c.center);
		}
	};
	for (int i(1); i < memory.size(); ++i) {
		drawCircle(i);
	}

	//ルートからの参照を描く
	auto rm = memory.getRelation();
	for (int j(1); j < memory.size(); ++j) {
		if (rm.areLinked(0, j)) {
			Line(memory.root().center(), memory.access(j).center()).drawArrow(4, { 20, 50 }, Color(Palette::Yellow, 128));
		}
		else if (rm.areLinked(j, 0))		{
			Line(memory.access(j).center(), memory.root().center()).drawArrow(4, { 20, 50 }, Color(Palette::Yellow, 128));
		}
	}

	//オブジェクト同士の参照を描く
	auto drawArrow = [&memory](int i, int j)
	{
		auto const &relation = memory.getRelation();
		if (relation.areLinked(i, j)) {
			Vec2 const &iCenter = memory.access(i).center();
			Vec2 const &jCenter = memory.access(j).center();
			static Color const clr = Color(Palette::Yellow, 128);
			if (i == j) {
				Circle(Vec2(40.0, -40.0).movedBy(iCenter), 40.0).drawArc(-Math::Pi / 2.0, 3.0 / 2.0 * Math::Pi, 2.0, 2.0, clr);
				Line(Vec2(0.0, -40.0).movedBy(iCenter), iCenter).drawArrow(4, { 20, 50 }, clr);
				Line(Vec2(40.0, 0.0).movedBy(iCenter), iCenter).draw(4, clr);
			}
			else {
				Line(iCenter, jCenter).drawArrow(4, { 20, 50 }, clr);
			}
		}
	};
	for (int i(1); i < memory.size(); ++i) {
		for (int j(1); j < memory.size(); ++j) {
			drawArrow(i, j);
		}
	}
}

int Game2::alloc(Vec2 pos){
	int p = memory_m.alloc();
	if (p != 0) {
		memory_m.access(p).center(pos);
	}
	return p;
}

bool Game2::allocAndReferenceFromRoot(Vec2 pos){
	return allocAndRefetenceMemoryToMemory(0, pos);
}

bool Game2::allocAndRefetenceMemoryToMemory(int address_t, Vec2 pos){
	int m = alloc(pos);
	if (m){
		memory_m.link(address_t, m);
		return true;
	}
	return false;
}

