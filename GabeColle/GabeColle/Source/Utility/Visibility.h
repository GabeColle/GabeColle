#pragma once
class Visibility
{
protected:
	bool isVisible_m;
public:
	virtual bool isVisible()const
	{
		return isVisible_m;
	}

	virtual void show()
	{
		isVisible_m = true;
	}

	virtual void hide()
	{
		isVisible_m = false;
	}

	Visibility()
	{}

	virtual ~Visibility()
	{}
};

