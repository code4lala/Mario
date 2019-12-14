#pragma once
#include <d2d1.h>
#include "SafePointer.hpp"
#include "Util.hpp"
#include <cassert>

class GraphicsScene {
protected:

    // D2D Resources
    SafePointer<ID2D1Factory>           m_pFactory;
    SafePointer<ID2D1HwndRenderTarget>  m_pRenderTarget;

    float   m_fScaleX;
    float   m_fScaleY;

protected:

    // Derived class must implement these methods.
    virtual HRESULT CreateDeviceIndependentResources() = 0;
    virtual void    DiscardDeviceIndependentResources() = 0;
    virtual HRESULT CreateDeviceDependentResources() = 0;
    virtual void    DiscardDeviceDependentResources() = 0;
    virtual void    CalculateLayout() = 0;
    virtual void    RenderScene() = 0;

protected:

    HRESULT CreateGraphicsResources(HWND hwnd) {
        if (m_pRenderTarget == nullptr) {
            RECT rc;
            GetClientRect(hwnd, &rc);

            const D2D1_SIZE_U size = D2D1::SizeU(rc.right, rc.bottom);

            Util::hr(m_pFactory->CreateHwndRenderTarget(
                D2D1::RenderTargetProperties(),
                D2D1::HwndRenderTargetProperties(hwnd, size),
                &m_pRenderTarget
            ));

            Util::hr(CreateDeviceDependentResources());
            CalculateLayout();
        }
        return S_OK;
    }

    template <class T>
    T PixelToDipX(T pixels) const {
        return static_cast<T>(pixels / m_fScaleX);
    }

    template <class T>
    T PixelToDipY(T pixels) const {
        return static_cast<T>(pixels / m_fScaleY);
    }

public:
    GraphicsScene() : m_fScaleX(1.0f), m_fScaleY(1.0f) {}
    virtual ~GraphicsScene() = default;

    HRESULT Initialize() {
        Util::hr(D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED,
            &m_pFactory));

        CreateDeviceIndependentResources();
        return S_OK;
    }

    void Render(HWND hwnd) {
	    Util::hr(CreateGraphicsResources(hwnd));

        m_pRenderTarget->BeginDraw();

        RenderScene();

        if (m_pRenderTarget->EndDraw()
            == D2DERR_RECREATE_TARGET) {
            DiscardDeviceDependentResources();
            m_pRenderTarget.SafeRelease();
        }
    }

    HRESULT Resize(int x, int y) {
        if (m_pRenderTarget) {
            Util::hr(m_pRenderTarget->Resize(D2D1::SizeU(x, y)));
            CalculateLayout();
        }
        return S_OK;
    }

    void CleanUp() {
        DiscardDeviceDependentResources();
        DiscardDeviceIndependentResources();
    }
};
