#include "GameOver.h"

GameOver::GameOver(String const &message)
{
	auto addButton = [this] (Point p, String name, String sound)
	{
		auto btn = std::make_shared<clickable::Button>(Rect(500, 60).setCenter(p), name, sound);
		btn->show();
		buttons_m.insert(std::make_pair(name, btn));
	};
	addButton(Window::Center().movedBy(0, 140), L"Garbage Collection", L"Asset/SoundEffect/Decision.ogg");
	addButton(Window::Center().movedBy(0, 230), L"Result", L"Asset/SoundEffect/NextScene.ogg");

	static Font font;
	Color outline = Palette::Black;
	Color charColor = Palette::Red;
	font = Font(100, Typeface::Black, FontStyle::Outline);
	title_m.string(L"GAME OVER");
	title_m.font(font);
	title_m.style(TextOutlineStyle(outline, charColor.setAlpha(200), 3.0));
	title_m.center(Window::Center().movedBy(0, -100));

	font = Font(30, Typeface::Medium, FontStyle::Outline);
	message_m.string(message);
	message_m.font(font);
	message_m.style(TextOutlineStyle(outline, charColor, 1.0));
	message_m.center(Window::Center().movedBy(0, 60));

	back_m = HSV(180.0, 0.9, 0.9).toColor(127);
}

void GameOver::update(Game3 &parent)
{
	auto e = parent.memory_m.error();
	e.outOfMemory_m = Clamp(e.outOfMemory_m, 0, 1);
	e.segmentationFault_m = Clamp(e.segmentationFault_m, 0, 1);
	parent.memory_m.error(e);
	buttons_m.at(L"Garbage Collection")->update();
	buttons_m.at(L"Result")->update();

	if (buttons_m.at(L"Garbage Collection")->isClicked()) {
		parent.memory_m.gc();
	}
	if (buttons_m.at(L"Result")->isClicked()) {
		parent.changeScene(nextScene_m);
	}

	static int frameCounter = 0;
	if(frameCounter >= 60 * 90) {
		frameCounter = 0;
		parent.changeScene(L"Result", 1000);
		return;
	} else {
		++frameCounter;
	}
}

void GameOver::draw()const
{
	Window::ClientRect().draw(back_m);
	title_m.draw();
	message_m.draw();
	buttons_m.at(L"Garbage Collection")->draw();
	buttons_m.at(L"Result")->draw();
	clickable::Button::drawEffect();
}
