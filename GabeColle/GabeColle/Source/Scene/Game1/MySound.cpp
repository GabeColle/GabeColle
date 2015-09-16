#include "MySound.h"


MySound::MySound(const FilePath BGMPath, const String BGMName)
	: BGM_PATH(BGMPath)
	, BGM_NAME(BGMName)
{
	initialize();
}


MySound& MySound::operator=(const MySound& obj)
{
	obj.BGM_PATH;
	return *this;
}


void MySound::startMusic()
{
	SoundAsset(BGM_NAME).play();
}

void MySound::drawSpectrum() const
{
	const auto fft = FFT::Analyze(SoundAsset(BGM_NAME));

	for(auto i : step(160)) {
		RectF(i * 8, Window::Height(), 8, -Pow(fft.buffer[i], 0.6f) * 2000).draw(HSV(240 - i * 2));
	}
	Rect({0, 0}, Window::Size()).draw(Color(Palette::Black, 230));
}

bool MySound::isEnded()
{
	return !SoundAsset(BGM_NAME).isPlaying;
}


void MySound::initialize()
{
	if(!SoundAsset::IsRegistered(BGM_NAME))  SoundAsset::Register(BGM_NAME, BGM_PATH);
	SoundAsset::Preload(BGM_NAME);
}