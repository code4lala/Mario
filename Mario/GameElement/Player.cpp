#include "Player.hpp"
#include <ctime>
#include "../Global.hpp"
#include <cmath>

Player::Player(float x, float y, float vx, float vy)
	:MovableGameObject(x, y, vx, vy)
{
}

void Player::DrawSelf(ID2D1RenderTarget* pRenderTarget, ID2D1SolidColorBrush* pBrush, float nCellSize)
{
	const float c = nCellSize;
	const float c2 = c / 2.f;

	// 画自己
	pRenderTarget->FillEllipse(D2D1::Ellipse(D2D1::Point2F(m_x * c + c2, m_y * c + c2), c2, c2),
		pBrush);

	const clock_t currTime = clock();
	if(lastTime==0)
	{
		lastTime = currTime;
		return;
	}
	const clock_t diff = currTime - lastTime;

	// 向下加速
	m_speedY -= Global::VERTICAL_ACCELERATION * diff;

	// 浮点数为0
	if (fabs(m_speedX) < Global::SPEED_MIN) {
	}
	// 向右走减速
	else if(m_speedX>0)
	{
		m_speedX -= Global::HORIZONTAL_ACCELERATION * diff;
		if (m_speedX < 0)m_speedX = 0.f;
	}
	// 向左走减速
	else {
		m_speedX += Global::HORIZONTAL_ACCELERATION * diff;
		if (m_speedX > 0)m_speedX = 0.f;
	}

	// 调整位置
	m_y += m_speedY * diff;
	m_x += m_speedX * diff;
}
