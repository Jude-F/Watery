//
// Created by Mike Smith on 2017/4/25.
//

#include "camera.h"
#include "../Component/position.h"

namespace watery
{
	Camera::Camera(const Vector &position)
	{
		// Setting up the position component.
		bind_component(new Position(position));
	}
	
	void Camera::move(const Vector &direction)
	{
		Position *position = static_cast<Position *>(component(COMPONENT_POSITION));
		
		if (position != nullptr)
		{
			position->move(direction);
		}
	}
	
	void Camera::move_x(float dx)
	{
		Position *position = static_cast<Position *>(component(COMPONENT_POSITION));
		
		if (position != nullptr)
		{
			position->move_x(dx);
		}
	}
	
	void Camera::move_y(float dy)
	{
		Position *position = static_cast<Position *>(component(COMPONENT_POSITION));
		
		if (position != nullptr)
		{
			position->move_y(dy);
		}
	}
	
	void Camera::move_z(float dz)
	{
		Position *position = static_cast<Position *>(component(COMPONENT_POSITION));
		
		if (position != nullptr)
		{
			position->move_z(dz);
		}
	}
	
	const Vector Camera::position(void) const
	{
		const Position *pos = static_cast<const Position *>(component(COMPONENT_POSITION));
		
		if (pos != nullptr)
		{
			return pos->position();
		}
		else
		{
			return Vector();
		}
	}
	
	Camera::~Camera(void)
	{
		delete component(COMPONENT_POSITION);
	}
	
	float Camera::x(void) const
	{
		return static_cast<const Position *>(component(COMPONENT_POSITION))->x();
	}
	
	float Camera::y(void) const
	{
		return static_cast<const Position *>(component(COMPONENT_POSITION))->y();
	}
	
	float Camera::z(void) const
	{
		return static_cast<const Position *>(component(COMPONENT_POSITION))->z();
	}
}