#pragma once

namespace Global
{
#if defined(DEBUG) || defined(_DEBUG)
    static const int fps = 30;
#else
    static const int fps = 120;
#endif
    static const int CELL_COUNT = 15;
    // �������ٶ�
    static const float VERTICAL_ACCELERATION
        = 0.000000005f;
    // ˮƽ�������ٶ�
    static const float HORIZONTAL_ACCELERATION
        = 0.000000005f;
    // ��С�ٶ�
    static const float SPEED_MIN = 1e-10f;
}
