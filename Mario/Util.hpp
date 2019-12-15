#pragma once

#include <d2d1.h>
#include <cstdio>

namespace Util {
	HRESULT hr(const HRESULT hr);

#if defined(DEBUG) || defined(_DEBUG)
	void CDECL logd(const TCHAR* szFormat, ...);
#else
	inline void CDECL logd(const TCHAR* szFormat, ...) {}
#endif
}
