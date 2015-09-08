#include "Game2.h"
#include"Game2GabeColle.h"

using namespace game2;

void drawMemory(gc::Memory<CircleObject> const &memory, int num);

// クラスの初期化時に一度だけ呼ばれる（省略可）
void Game2::init()
{
	SoundAsset(L"Game2_BGM").play();
	SoundAsset(L"Game2_BGM").setPosSec(1.8);
	Graphics::SetBackground(Palette::Darkcyan);
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
	SoundAsset(L"Game2_BGM").play();
	if (static_cast<int> (state) < 3 )
	{
		if (System::FrameCount() % (108/NUM_OF_MEMORY) == 0)
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
			m_data->stageName = name;
			m_data->numOfError = garbage_m + segmentFault_m;
			m_data->time = time_m;
			m_data->numOfDeletedObject = process_m;
			m_data->totalScore = 100000 - time_m *2 - garbage_m * 1000 - segmentFault_m * 5000 + process_m * 100;
			state = State::result;
		}
	}
	else if (state == State::result)
	{
		if (Input::MouseL.clicked){
			SoundAsset(L"Game2_BGM").pause(500);
			changeScene(L"Start", 500);
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
	Println(Format(L"Process ", m_data->numOfDeletedObject));
	Println(Format(L"Error ", m_data->numOfError));
	Println(Format(L"Score ", m_data->totalScore));


	double rad = (double)System::FrameCount() / 80;
	Color c(Palette::Darkturquoise);//(HSV(180, 0.5, 0.5));
	Circle(rootPos, 150).drawArc(0.0 + rad*2.3, HalfPi + 0.6, 50, 0, c);
	Circle(rootPos, 211).drawArc(Pi - rad*2.0, HalfPi + 0.1, 60, 0, c);
	Circle(rootPos, 211).drawArc(0.0 - rad*2.0, HalfPi + 0.3, 60, 0, c);
	Circle(rootPos, 282).drawArc(HalfPi + rad*1.7, HalfPi + 0.6, 70, 0, c);
	Circle(rootPos, 363).drawArc(0.0 - rad*1.4, HalfPi + 0.6, 80, 0, c);
	Circle(rootPos, 363).drawArc(Pi - rad*1.4, HalfPi + 0.7, 80, 0, c);
	Circle(rootPos, 454).drawArc(HalfPi + rad*1.1, HalfPi + 0.8, 90, 0, c);
	Circle(rootPos, 555).drawArc(Pi - rad*0.8, HalfPi + 0.6, 100, 0, c);
	Circle(rootPos, 555).drawArc(0.0 - rad*0.8, HalfPi + 0.6, 100, 0, c);
	Circle(rootPos, 666).drawArc(0.0 + rad*0.5, HalfPi*3 + 0.3, 110, 0, c);

	const auto fft = FFT::Analyze(SoundAsset(L"Game2_BGM"));

	for (int i = 0; i < Window::Height() / 30 ; ++i)
	{
		const double size = Pow(fft.buffer[i*30], 0.6f) * 2000;
		RectF(0, i * 30 ,size , 29).draw(HSV(240 - i));
		RectF(Window::Width() - size , i * 30, size, 29).draw(HSV(240 - i));
	}

	drawMemory(memory_m,NUM_OF_MEMORY);
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

void drawMemory(gc::Memory<CircleObject> const &memory,int num)
{
	static Font font;
	font.drawCenter(L"Root", Circle(memory.root().center(), 50.0).draw(HSV(System::FrameCount(),1.0,0.8)/*Palette::Aqua*/).center);

	//オブジェクトを描く
	auto drawCircle = [&memory](int address)
	{
		double const r = 40.0;
		if (!memory.hasExpired(address)) {
			Circle c = Circle(memory.access(address).center(), r);
			if (c.mouseOver) {
				c.draw(Color(Palette::Pink, 245)).drawFrame(0.0, 3.0, Palette::Red);
			}
			else {
				c.draw(Color(Palette::Red, 245)).drawFrame(0.0, 3.0, Palette::Darkred);
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
			Line(memory.root().center(), memory.access(j).center()).drawArrow(4, { 20, 50 }, Color(HSV(47 * j )/*Palette::Yellow*/, 128));
		}
		else if (rm.areLinked(j, 0))		{
			Line(memory.access(j).center(), memory.root().center()).drawArrow(4, { 20, 50 }, Color(HSV(47 * -j), 128));
		}
	}

	//オブジェクト同士の参照を描く
	auto drawArrow = [&memory](int i, int j,Color color)
	{
		auto const &relation = memory.getRelation();
		if (relation.areLinked(i, j)) {
			Vec2 const &iCenter = memory.access(i).center();
			Vec2 const &jCenter = memory.access(j).center();
			//static Color const clr = Color(color , 128);
			if (i == j) {
				Circle(Vec2(40.0, -40.0).movedBy(iCenter), 40.0).drawArc(-Math::Pi / 2.0, 3.0 / 2.0 * Math::Pi, 2.0, 2.0, color);
				Line(Vec2(0.0, -40.0).movedBy(iCenter), iCenter).drawArrow(4, { 20, 50 }, color);
				Line(Vec2(40.0, 0.0).movedBy(iCenter), iCenter).draw(4, color);
			}
			else {
				Line(iCenter, jCenter).drawArrow(4, { 20, 50 }, color);
			}
		}
	};
	for (int i(1); i < memory.size(); ++i) {
		for (int j(1); j < memory.size(); ++j) {
			drawArrow(i, j, Color(HSV(47 * -i ,1.0,1.0),192));
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

