#include "DescendAndCountStringEffect.h"

DescendAndCountStringEffect::DescendAndCountStringEffect(String str, int frame, int delayFrame) : NodeEffect(frame, delayFrame), drawingString_m(30)
{
	stringCountFrame_m = 2;
	startPos_m = 40;
	descendedString_m = inverseCalculationString(str, 60/stringCountFrame_m);
	realString_m = str;
	currentTransparency_m = 0;
	increaseYRange_m = 40 / frame_m;
	increaseTransparencyRange_m = 255 / frame_m;
}

void DescendAndCountStringEffect::update()
{
	if (delayFrame_m == 0){
		if (startPos_m > 0){
			startPos_m -= increaseYRange_m;
		}
		else{
			startPos_m = 0;
		}
		if (currentTransparency_m < 255){
			currentTransparency_m += increaseTransparencyRange_m;
		}
		else{
			currentTransparency_m = 255;
		}
		if (stringCountFrame_m == 0){
			if (realString_m != descendedString_m){
				descendedString_m = incrementString(descendedString_m);
			}
			stringCountFrame_m = 2;
		}
		else{
			stringCountFrame_m--;
		}
		
	}
	else{
		delayFrame_m--;
		
	}

}

void DescendAndCountStringEffect::draw()const
{

}

void DescendAndCountStringEffect::draw(Vec2 realPosition)const
{
	Vec2 drawingPosition(realPosition.x, realPosition.y - startPos_m);
	drawingString_m(descendedString_m).drawCenter(drawingPosition, Color(Palette::Bisque, currentTransparency_m));
}

void DescendAndCountStringEffect::setPosition(Vec2 position)
{
	position_m = position;
}

String DescendAndCountStringEffect::inverseCalculationString(String str,int frame)
{
	for (unsigned int i = 0; i < str.length; ++i){
		if (str.at(i) != '\n' || str.at(i) != '\t'){
			str.at(i) = (wchar)(str.at(i) - frame);
		}	
	}
	
	return str;
}

String DescendAndCountStringEffect::incrementString(String str)
{
	for (unsigned int i = 0; i < str.length; ++i){
		if (str.at(i) != '\n' || str.at(i) != '\t'){
			str.at(i) = (int)str.at(i) + 2;
		}
	}

	return str;
}