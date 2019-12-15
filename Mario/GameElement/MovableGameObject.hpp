#pragma once

#include "GameObject.hpp"

class MovableGameObject:public GameObject<float>
{
public:

	~MovableGameObject() override = default;
	explicit MovableGameObject(float x, float y, float speedX = 0.f, float speedY = 0.f)
		:GameObject(x, y), m_speedX(speedX), m_speedY(speedY)
	{
		
	}

	virtual void DrawSelf(ID2D1RenderTarget* pRenderTarget, ID2D1SolidColorBrush* pBrush,
		float nCellSize) override = 0;
protected:
	float m_speedX;
	float m_speedY;
};
