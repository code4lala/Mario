#pragma once
#include "BaseWin.hpp"
#include <d2d1.h>
#include "GameScene.hpp"

class MainWindow : public BaseWindow<MainWindow> {
    HANDLE  m_hTimer;
    GameScene m_scene;

    BOOL    InitializeTimer();

public:

    MainWindow() : m_hTimer(nullptr), m_scene()
    {
    }

    void    WaitTimer() const;

    PCWSTR  ClassName() const override { return L"Mario Window Class"; }
    LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) override;
};

