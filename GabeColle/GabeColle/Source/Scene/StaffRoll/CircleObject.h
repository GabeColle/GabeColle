#pragma once

#include <Siv3D.hpp>
#include "../../GC/Object.h"

namespace staffroll{
	class CircleObject :
		public gc::Object
	{
	private:
		double x_m;
		double y_m;
	public:
		Vec2 getCenter() const;
		void setCenter(Vec2 v);
		void setX(double x);
		void setY(double y);
	};
}
