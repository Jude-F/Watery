//
// Created by Mike Smith on 2017/5/10.
//

#ifndef WATERY_HEALTH_H
#define WATERY_HEALTH_H

#include "component.h"

namespace watery
{
	class Health : public Component
	{
	private:
		double _health;
	
	public:
		Health(double initial) : Component(COMPONENT_HEALTH), _health(initial) {}
	};
}

#endif  // WATERY_HEALTH_H
