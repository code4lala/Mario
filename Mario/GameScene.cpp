#include "GameScene.hpp"
#include "Util.hpp"
#include "Global.hpp"

float GameScene::width;
float GameScene::height;
float GameScene::cell;

HRESULT GameScene::CreateDeviceIndependentResources()
{
	return S_OK;
}

void GameScene::DiscardDeviceIndependentResources()
{
}

HRESULT GameScene::CreateDeviceDependentResources() {
	Util::hr(m_pRenderTarget->CreateSolidColorBrush(
		D2D1::ColorF(D2D1::ColorF::GreenYellow), &pSolidBrush));

	// 初始化游戏地图
	const int MAP_LENGTH = 30;
	const char map[Global::CELL_COUNT][MAP_LENGTH] = {
	"",//14
	"",//13
	"",//12
	"",//11
	"",//10
	"",//9
	"",//8
	"",//7
	"",//6
	"---",//5
	"",//4
	"",//3
	"",//2
	"",//1
	"--------------",//0
	};
	for (int i = 0; i < Global::CELL_COUNT; i++)
	{
		for (int j = 0; j < MAP_LENGTH; j++)
		{
			const int x = j;
			const int y = Global::CELL_COUNT - 1 - i;
			switch (map[i][j])
			{
			case '-':
				m_gameMap.emplace_back(new Floor(x, y));
				break;
			default:
				break;
			}
		}
	}

	return S_OK;
}

void GameScene::DiscardDeviceDependentResources() {
	pSolidBrush.SafeRelease();
}

void GameScene::RenderScene() {
	m_pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::SkyBlue));

	// 设置坐标系为左下角为原点，右方向为x轴正方向，上方向为y轴正方向
	// 先翻转y轴 再向下平移
	m_pRenderTarget->SetTransform(
		D2D1::Matrix3x2F(
			1.f, 0.f,
			0.f, -1.f,
			0.f, 0.f
		) * D2D1::Matrix3x2F::Translation(0.f, height)
	);

	pSolidBrush->SetColor(D2D1::ColorF(D2D1::ColorF::GreenYellow));
	DrawMap();

	pSolidBrush->SetColor(D2D1::ColorF(D2D1::ColorF::DarkCyan));
	player.DrawSelf(m_pRenderTarget, pSolidBrush, cell);

}

void GameScene::DrawMap()
{
	for(auto& i:m_gameMap)
	{
		i->DrawSelf(m_pRenderTarget, pSolidBrush, cell);
	}
}

void GameScene::CalculateLayout() {
	const D2D1_SIZE_F fSize = m_pRenderTarget->GetSize();
	width = fSize.width;
	height = fSize.height;
	cell = height / static_cast<float>(Global::CELL_COUNT);
	Util::logd(L"calculate layout cell = %f height = %f", cell, height);
}
