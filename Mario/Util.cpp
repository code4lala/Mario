#include "Util.hpp"

namespace Util {
	HRESULT hr(const HRESULT hr) {
		if (FAILED(hr)) {
			abort();
		}
		return hr;
	}

#if defined(DEBUG) || defined(_DEBUG)
	void logd(const TCHAR* szFormat, ...)
	{
		static TCHAR szBuffer[1024];
		static TCHAR szB2[1024];
		static SYSTEMTIME st;

		va_list pArgList;
		va_start(pArgList, szFormat);
#ifdef UNICODE
		_vsnwprintf_s(szBuffer, sizeof(szBuffer) / sizeof(TCHAR), szFormat, pArgList);
#elif
		_vsnprintf_s(strBuf, sizeof(szBuffer) / sizeof(TCHAR), szFormat, pArgList);
#endif
		va_end(pArgList);

		GetLocalTime(&st);

		wsprintf(szB2, TEXT("[DEBUG] %02d:%02d:%02d.%03d [%d] %s %s\n"),
		         // current time
		         st.wHour, st.wMinute, st.wSecond, st.wMilliseconds,
		         // process id
		         GetCurrentProcessId(),
		         // debug log
		         TEXT("Mario"), szBuffer);
		OutputDebugString(szB2);
	}
#endif

}
