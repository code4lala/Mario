#include "Floor.hpp"
#include "../Util.hpp"

void Floor::DrawSelf(ID2D1RenderTarget* pRenderTarget, ID2D1SolidColorBrush* pBrush, float nCellSize)
{
	const float cell = nCellSize;
	pRenderTarget->FillRectangle(D2D1::RectF(
		cell * x(),
		cell * (y() + 1),
		cell * (x() + 1),
		cell * y()),
		pBrush
	);
}
