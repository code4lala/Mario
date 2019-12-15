#pragma once
#include "GraphicsScene.hpp"
#include "GameElement/Floor.hpp"
#include <vector>
#include <memory>
#include "GameElement/Player.hpp"

class GameScene : public GraphicsScene {
    HRESULT CreateDeviceIndependentResources() override;
    void    DiscardDeviceIndependentResources() override;
    HRESULT CreateDeviceDependentResources() override;
    void    DiscardDeviceDependentResources() override;
    void    CalculateLayout() override;
    void    RenderScene() override;

    SafePointer<ID2D1SolidColorBrush> pSolidBrush;
    std::vector<std::unique_ptr<Floor>> m_gameMap;
    Player player = Player(5.f, 5.f, 0.f, 0.f);
	
    void DrawMap();

    static float width;
    static float height;
    static float cell;
};
