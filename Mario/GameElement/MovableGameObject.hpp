#pragma once

#include "GameObject.hpp"

class MovableGameObject:public GameObject
{
public:

	~MovableGameObject() override = default;
	explicit MovableGameObject(float speed = 0.f)
		:m_speed(speed)
	{
		
	}

	virtual void DrawSelf(ID2D1RenderTarget* pRenderTarget, ID2D1SolidColorBrush* pBrush,
		float nCellSize) override = 0;
private:
	float m_speed;
};
