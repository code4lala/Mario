#pragma once

#include <d2d1.h>

class GameObject
{
protected:
	int positionX;
	int positionY;
public:
	virtual void DrawSelf(ID2D1RenderTarget* pRenderTarget, ID2D1SolidColorBrush* pBrush,
		float nCellSize) = 0;
	explicit GameObject(int x = 0, int y = 0) :positionX(x), positionY(y) {}
	virtual ~GameObject() = default;
	int x() const { return positionX; }
	int y() const { return positionY; }
};
