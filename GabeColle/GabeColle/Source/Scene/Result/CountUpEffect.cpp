#include"CountUpEffect.h"

CountUpEffect::CountUpEffect(int countedVariable, int frame) : font(30)
{
	countedVariable_m = countedVariable;
	counter_m = 0;
	frame_m = frame; 
	countRange_m = countedVariable_m / frame_m;
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

void CountUpEffect::draw(int x,int y)const
{
	font(Format(counter_m)).drawCenter(Vec2(x,y),Palette::Red);
}


