#pragma once
#include "GraphicsScene.hpp"

class GameScene : public GraphicsScene {
    HRESULT CreateDeviceIndependentResources() override;
    void    DiscardDeviceIndependentResources() override;
    HRESULT CreateDeviceDependentResources() override;
    void    DiscardDeviceDependentResources() override;
    void    CalculateLayout() override;
    void    RenderScene() override;
};
