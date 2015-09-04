#include"CountUpEffect.h"

CountUpEffect::CountUpEffect(int countedVariable, int frame, Vec2 position) : font(30)
{
	countedVariable_m = countedVariable;
	counter_m = 0;
	frame_m = frame; 
	countRange_m = countedVariable_m / frame_m;
	position_m = position;
}


void CountUpEffect::countUp()
{
	if (counter_m < countedVariable_m){
		counter_m += countRange_m;
	}
	else{
		counter_m = countedVariable_m;
	}
	
}

void CountUpEffect::draw()const
{
	font(Format(counter_m)).drawCenter(position_m,Palette::Red);
}


