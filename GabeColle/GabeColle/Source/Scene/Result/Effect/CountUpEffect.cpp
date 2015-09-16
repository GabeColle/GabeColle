#include"CountUpEffect.h"

CountUpEffect::CountUpEffect(int countedVariable, int frame, int delayFrame, Vec2 position) : NodeEffect(frame, delayFrame, position), drawingVariable_m(60)
{
	countedVariable_m = countedVariable;
	counter_m = 0;
	countRange_m = (countedVariable_m / frame_m == 0) ? 1 : countedVariable_m / frame_m;
}


void CountUpEffect::update()
{
	if (delayFrame_m == 0){
		if (counter_m < countedVariable_m){
			counter_m += countRange_m;
		}
		else{
			counter_m = countedVariable_m;
		}
	}
	else{
		delayFrame_m--;
	}
	
	
}

void CountUpEffect::draw()const
{
	drawingVariable_m(Format(counter_m)).drawCenter(position_m,Palette::White);
}


