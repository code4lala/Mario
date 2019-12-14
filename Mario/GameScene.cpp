#include "GameScene.hpp"
#include "Util.hpp"

HRESULT GameScene::CreateDeviceIndependentResources()
{
    return S_OK;
}

void GameScene::DiscardDeviceIndependentResources()
{
}

HRESULT GameScene::CreateDeviceDependentResources() {
    return S_OK;
}

void GameScene::RenderScene() {
    m_pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::SkyBlue));
}

void GameScene::CalculateLayout() {
    D2D1_SIZE_F fSize = m_pRenderTarget->GetSize();

    const float x = fSize.width / 2.0f;
    const float y = fSize.height / 2.0f;
    const float radius = min(x, y);
}


void GameScene::DiscardDeviceDependentResources() {
}
