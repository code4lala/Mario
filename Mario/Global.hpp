#pragma once

namespace Global
{
#if defined(DEBUG) || defined(_DEBUG)
    static const int fps = 30;
#else
    static const int fps = 120;
#endif
    static const int CELL_COUNT = 15;
    static const float GRAVITY = 10;

}
