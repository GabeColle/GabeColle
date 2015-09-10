#include "MySound.h"


const FilePath MySound::BGM_PATH = L"./Asset/BGM/‰Ì•‘Šêƒ_ƒ“ƒVƒ“ƒO_2.ogg";


MySound::MySound()
{
	initialize();
}


void MySound::startMusic()
{
	SoundAsset(L"Stage1BGM").play();
}

void MySound::drawSpectrum() const
{
	const auto fft = FFT::Analyze(SoundAsset(L"Stage1BGM"));

	for(auto i : step(160)) {
		RectF(i * 8, Window::Height(), 8, -Pow(fft.buffer[i], 0.6f) * 2000).draw(HSV(240 - i * 2));
	}
	Rect({0, 0}, Window::Size()).draw(Color(Palette::Black, 230));
}

bool MySound::isEnded()
{
	return !SoundAsset(L"Stage1BGM").isPlaying;
}


void MySound::initialize()
{
	if(!SoundAsset::IsRegistered(L"Stage1BGM"))  SoundAsset::Register(L"Stage1BGM", BGM_PATH, {L"Stage1"});
	SoundAsset::Preload(L"Stage1BGM");
}