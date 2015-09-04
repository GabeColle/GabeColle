#include"FeedInAndDescendStringEffect.h"

FeedInAndDescendStringEffect::FeedInAndDescendStringEffect(String str, int frame, Vec2 position) : font_m(50)
{
	descendedString_m = str;
	frame_m = frame;
	currentFrame_m = 0;
	position_m = position;
	currentPosition_m.x = position_m.x;
	currentPosition_m.y = position_m.y - 40;
	currentTransparency_m = 0;
	increaseYRange_m = 40 / frame_m;
	increaseTransparencyRange_m = 255 / frame_m;
	
}

void FeedInAndDescendStringEffect::update()
{
	if (currentTransparency_m < 255 && currentPosition_m.y < position_m.y){
		currentPosition_m.y += increaseYRange_m;
		currentTransparency_m += increaseTransparencyRange_m;
	}
	else{
		currentPosition_m.y = position_m.y;
		currentTransparency_m = 255;
	}
	draw();
}

void FeedInAndDescendStringEffect::draw()
{
	font_m(descendedString_m).drawCenter(currentPosition_m, Color(255,255,255,currentTransparency_m));
	//rect_m.draw(Color(0,0,0,currentTransparency_m));
}