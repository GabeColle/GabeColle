#include "GameOver.h"


GameOver::GameOver(String const &message)
{
	auto addButton = [this] (Point p, String name, String sound)
	{
		auto btn = std::make_shared<clickable::Button>(Rect(500, 60).setCenter(p), name, sound);
		btn->show();
		buttons_m.insert(std::make_pair(name, btn));
	};
	static String const sound = L"Asset/SoundEffect/Decision.mp3";
	addButton(Window::Center().movedBy(0, 140), L"Garbage Collection", sound);
	addButton(Window::Center().movedBy(0, 230), L"Result", sound);

	static Font font;
	Color outline = Palette::Black;
	Color charColor = Palette::Red;
	font = Font(100, Typeface::Black, FontStyle::Outline);
	font.changeOutlineStyle(TextOutlineStyle(outline, charColor.setAlpha(167), 3.0));
	title_m.string(L"GAME OVER");
	title_m.font(font);
	title_m.center(Window::Center().movedBy(0, -100));
	font = Font(30, Typeface::Medium, FontStyle::Outline);
	font.changeOutlineStyle(TextOutlineStyle(outline, charColor, 1.0));
	message_m.string(message);
	message_m.font(font);
	message_m.center(Window::Center().movedBy(0, 60));

	back_m = HSV(180.0, 0.9, 0.9).toColor(127);
}

void GameOver::update(JumpakuGame &parent)
{
	buttons_m.at(L"Garbage Collection")->update();
	buttons_m.at(L"Result")->update();

	if (buttons_m.at(L"Garbage Collection")->isClicked()) {
		parent.memory_m.gc();
	}
	if (buttons_m.at(L"Result")->isClicked()) {
		parent.changeScene(nextScene_m);
	}
}

void GameOver::draw()const
{
	Window::ClientRect().draw(back_m);
	title_m.draw();
	message_m.draw();
	buttons_m.at(L"Garbage Collection")->draw();
	buttons_m.at(L"Result")->draw();

}
