#ifndef MSVC_CLZ_COMPAT_H
#define MSVC_CLZ_COMPAT_H

#ifdef _MSC_VER

#include <intrin.h>
#include <stdint.h>

static inline int __builtin_clzll_impl(unsigned long long x) {
	if (x == 0) return 64; // treat zero as 64 leading zeros to avoid undefined behavior
	unsigned long index = 0;
#if defined(_M_X64) || defined(_M_AMD64)
	_BitScanReverse64(&index, (unsigned long long)x);
	return (int)index;
#else
	if ((unsigned long)(x >> 32)) {
		_BitScanReverse(&index, (unsigned long)(x >> 32));
		return (int)(index + 32);
	} else {
		_BitScanReverse(&index, (unsigned long)x);
		return (int)index;
	}
#endif
}

#define __builtin_clzll(x) ((x) == 0 ? 64 : (63 - __builtin_clzll_impl((unsigned long long)(x))))

#endif // _MSC_VER

#endif // MSVC_CLZ_COMPAT_H
