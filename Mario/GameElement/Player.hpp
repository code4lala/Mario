#pragma once
#include "MovableGameObject.hpp"
#include <ctime>

class Player final :public MovableGameObject
{
	clock_t lastTime = 0;
public:
	explicit Player(float x = 0, float y = 0, float vx = 0.f, float vy = 0.f);
	~Player() override = default;
	virtual void DrawSelf(ID2D1RenderTarget* pRenderTarget, ID2D1SolidColorBrush* pBrush, float nCellSize) override;
};
