#pragma once

#include <d2d1.h>

template<typename T>
class GameObject
{
protected:
	T m_x;
	T m_y;
public:
	virtual void DrawSelf(ID2D1RenderTarget* pRenderTarget, ID2D1SolidColorBrush* pBrush,
		float nCellSize) = 0;
	explicit GameObject(T x = 0, T y = 0) :m_x(x), m_y(y) {}
	virtual ~GameObject() = default;
	T x() const { return m_x; }
	T y() const { return m_y; }
};
