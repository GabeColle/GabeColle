#include "MySound.h"

using namespace staffroll;

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
	if (state_m == L"HataG"){
		

		for (auto i : step(160)) {
			RectF(i * 8, Window::Height(), 8, -Pow(fft.buffer[i], 0.6f) * 2000).draw(HSV(240 - i * 2));
		}
		Rect({ 0, 0 }, Window::Size()).draw(Color(Palette::Black, 230));

	}
	else if(state_m == L"Namba"){
		// Ç≠ÇÈÇ≠ÇÈ
		double rad = (double)System::FrameCount() / 80;
		Color c(HSV(180, 0.4, 0.8));//Palette::Darkturquoise);//(HSV(180, 0.5, 0.5));
		Circle(rootPos, 150).drawArc(0.0 + rad*2.3, HalfPi + 0.6, 50, 0, c);
		Circle(rootPos, 211).drawArc(Pi - rad*2.0, HalfPi + 0.1, 60, 0, c);
		Circle(rootPos, 211).drawArc(0.0 - rad*2.0, HalfPi + 0.3, 60, 0, c);
		Circle(rootPos, 282).drawArc(HalfPi + rad*1.7, HalfPi + 0.6, 70, 0, c);
		Circle(rootPos, 363).drawArc(0.0 - rad*1.4, HalfPi + 0.6, 80, 0, c);
		Circle(rootPos, 363).drawArc(Pi - rad*1.4, HalfPi + 0.7, 80, 0, c);
		Circle(rootPos, 454).drawArc(HalfPi + rad*1.1, HalfPi + 0.8, 90, 0, c);
		Circle(rootPos, 555).drawArc(Pi - rad*0.8, HalfPi + 0.6, 100, 0, c);
		Circle(rootPos, 555).drawArc(0.0 - rad*0.8, HalfPi + 0.6, 100, 0, c);
		Circle(rootPos, 666).drawArc(0.0 + rad*0.5, HalfPi * 3 + 0.3, 110, 0, c);

		// ç∂âEÇÃîg
		for (int i = 0; i < Window::Height() / 30; ++i)
		{
			const double size = Pow(fft.buffer[i * 30], 0.6f) * 2000;
			RectF(0, i * 30, size, 29).draw(HSV(240 - i, 0.6, 0.8));
			RectF(Window::Width() - size, i * 30, size, 29).draw(HSV(240 - i, 0.6, 0.8));
		}
	}
	else if (state_m == L"Jumpaku"){

	}
	
	
}

bool MySound::isEnded()
{
	return !SoundAsset(BGM_NAME).isPlaying;
}


void MySound::initialize()
{
	states_m.push(L"HataG");
	states_m.push(L"Namba");
	states_m.push(L"Jumpaku");
	frame_m = 3*160;
	state_m = states_m.front();
	states_m.pop();
	if(!SoundAsset::IsRegistered(BGM_NAME))  SoundAsset::Register(BGM_NAME, BGM_PATH);
	SoundAsset::Preload(BGM_NAME);
}

void MySound::update()
{
	if (!states_m.empty()){
		if (frame_m == 0){
			state_m = states_m.front();
			states_m.pop();
			frame_m = 3 * 160;
			if (state_m == L"Namba"){
				Graphics::SetBackground(Palette::Darkcyan);
			}
			else if (state_m == L"Jumpaku"){
				Graphics::SetBackground(Palette::Whitesmoke);
			}
		}
		else{
			frame_m--;
		}
	}
}