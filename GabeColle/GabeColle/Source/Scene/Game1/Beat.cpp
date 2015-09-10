#include "Beat.h"


Beat::Beat() : soundBeat_m(16000, /*134*/160), nowBeat_m(0), prevBeat_m(0)
{
}


void Beat::update()
{
	const auto b = soundBeat_m(SoundAsset(L"Stage1BGM"), 4, 4);
	prevBeat_m = nowBeat_m;
	nowBeat_m = b.beat;
}

bool Beat::getBeatRising()
{
	return (nowBeat_m != prevBeat_m && (nowBeat_m == 0 || nowBeat_m == 2));
}