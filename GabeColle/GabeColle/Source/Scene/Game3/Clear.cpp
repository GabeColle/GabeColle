#include "Clear.h"

Clear::Clear()
{
	auto addButton = [this] (Point p, String name, String sound)
	{
		auto btn = std::make_shared<clickable::Button>(
			Rect(500, 60).setCenter(p), name, sound);
		btn->show();
		buttons_m.insert(std::make_pair(name, btn));
	};
	static String const sound = L"Asset/SoundEffect/Decision.ogg";
	addButton(Window::Center().movedBy(0, 150), L"Result", sound);

	static Font font;
	Color outline = Palette::Black;
	Color charColor = Palette::Yellow;
	font = Font(100, Typeface::Black, FontStyle::Outline);
	font.changeOutlineStyle(TextOutlineStyle(outline, charColor.setAlpha(200), 3.0));
	title_m.string(L"CLEAR");
	title_m.font(font);
	title_m.center(Window::Center().movedBy(0, -100));
	font = Font(30, Typeface::Medium, FontStyle::Outline);
	font.changeOutlineStyle(TextOutlineStyle(outline, charColor, 1.0));
	message_m.string(L"Success");
	message_m.font(font);
	message_m.center(Window::Center().movedBy(0, 60));

	back_m = HSV(240.0, 0.9, 0.9).toColor(127);
}

void Clear::update(Game3 &parent)
{
	auto e = parent.memory_m.error();
	e.outOfMemory_m = Clamp(e.outOfMemory_m, 0, 1);
	e.segmentationFault_m = Clamp(e.segmentationFault_m, 0, 1);
	parent.memory_m.error(e);
	buttons_m.at(L"Result")->update();

	if (buttons_m.at(L"Result")->isClicked()) {
		parent.changeScene(nextScene_m);
	}
}

void Clear::draw()const
{
	Window::ClientRect().draw(back_m);
	title_m.draw();
	message_m.draw();
	buttons_m.at(L"Result")->draw();
	clickable::Button::drawEffect();
}
