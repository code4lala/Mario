#pragma once
#include "GraphicsScene.hpp"
#include "GameElement/Floor.hpp"
#include <vector>
#include <memory>

class GameScene : public GraphicsScene {
    HRESULT CreateDeviceIndependentResources() override;
    void    DiscardDeviceIndependentResources() override;
    HRESULT CreateDeviceDependentResources() override;
    void    DiscardDeviceDependentResources() override;
    void    CalculateLayout() override;
    void    RenderScene() override;

    SafePointer<ID2D1SolidColorBrush> pSolidBrush;
    std::vector<std::shared_ptr<Floor>> m_gameMap;
	
    void DrawMap();

    static float width;
    static float height;
    static float cell;
};
