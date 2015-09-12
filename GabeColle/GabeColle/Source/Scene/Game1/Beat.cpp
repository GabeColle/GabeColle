#include "Beat.h"


Beat::Beat(const String BGMName, const int32 tempo)
	: soundBeat_m(16000, tempo)
	, nowBeat_m(0)
	, prevBeat_m(0)
	, BGM_NAME(BGMName)
{
}


void Beat::update()
{
	const auto b = soundBeat_m(SoundAsset(BGM_NAME), 4, 4);
	prevBeat_m = nowBeat_m;
	nowBeat_m = b.beat;
}

bool Beat::getBeatRising(const int beat)
{
	if(beat == 1) {
		return (nowBeat_m != prevBeat_m && nowBeat_m == 0);
	}
	else if(beat == 2) {
		return (nowBeat_m != prevBeat_m && (nowBeat_m == 0 || nowBeat_m == 2));
	}
	return (nowBeat_m != prevBeat_m && (nowBeat_m == 0 || nowBeat_m == 1 || nowBeat_m == 2 || nowBeat_m == 3));
}