#include "Util.hpp"

namespace Util {
	HRESULT hr(const HRESULT hr) {
		if (FAILED(hr)) {
			abort();
		}
		return hr;
	}
}
