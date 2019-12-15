#pragma once
#include "GameObject.hpp"

class Floor final :public GameObject<int>
{
public:
	Floor(int x=0,int y=0):GameObject(x,y)
	{
		
	}
	virtual ~Floor() = default;

	virtual void DrawSelf(ID2D1RenderTarget* pRenderTarget, ID2D1SolidColorBrush* pBrush,
		float nCellSize) override;
};
