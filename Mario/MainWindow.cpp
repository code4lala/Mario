#include "MainWindow.hpp"
#include "Global.hpp"

LRESULT MainWindow::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) {
    HWND hwnd = m_hwnd;

    switch (uMsg) {
    case WM_CREATE:
        if (FAILED(m_scene.Initialize()) || !InitializeTimer()) {
            return -1;
        }
        SetCursor(LoadCursor(nullptr, IDC_ARROW));
        return 0;

    case WM_DESTROY:
        CloseHandle(m_hTimer);
        m_scene.CleanUp();
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:
    case WM_DISPLAYCHANGE: {
        PAINTSTRUCT ps;
        BeginPaint(m_hwnd, &ps);
        m_scene.Render(m_hwnd);
        EndPaint(m_hwnd, &ps);
    }
    return 0;

    case WM_SIZE: {
        const int x = static_cast<int>(LOWORD(lParam));
	    const int y = static_cast<int>(HIWORD(lParam));
        m_scene.Resize(x, y);
        InvalidateRect(m_hwnd, nullptr, FALSE);
    }
    return 0;

    case WM_ERASEBKGND:
        return 1;

    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}


BOOL MainWindow::InitializeTimer() {
    m_hTimer = CreateWaitableTimer(nullptr, FALSE, nullptr);
    if (m_hTimer == nullptr) {
        return FALSE;
    }

    LARGE_INTEGER li = { 0 };

    if (!SetWaitableTimer(m_hTimer, &li, 1000 / Global::fps,
        nullptr, nullptr, FALSE)) {
        CloseHandle(m_hTimer);
        m_hTimer = nullptr;
        return FALSE;
    }

    return TRUE;
}

void MainWindow::WaitTimer() const
{
    // Wait until the timer expires or any message is posted.
    if (MsgWaitForMultipleObjects(1, &m_hTimer, FALSE, INFINITE, QS_ALLINPUT)
        == WAIT_OBJECT_0) {
        InvalidateRect(m_hwnd, nullptr, FALSE);
    }
}
