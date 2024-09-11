#pragma once

#include "defines.h"

// Disable assertions by commenting out the line below
#define LSASSERT_ENABLED

#ifdef LSASSERT_ENABLED
#if _MSC_VER
#include <intrin.h>
#define debugBreak() __debugbreak()
#else
#define debugBreak() __builtin_trap()
#endif

LSAPI void report_assert_failure(const char* expr, const char* msg, const char* filename, int32 line);

#define LSASSERT(expr)                                          \
  {                                                             \
    if (expr) {                                                 \
    } else                                                      \
    {                                                           \
      report_assert_failure(#expr, "", __FILE__, __LINE__);     \
      debugBreak();                                             \
    }                                                           \
  }

#define LSASSERT_MSG(expr, msg)                                 \
  {                                                             \
    if (expr) {                                                 \
    } else {                                                    \
      report_assert_failure(#expr, msg, __FILE__, __LINE__);    \
      debugBreak();                                             \
    }                                                           \
  }

#ifdef _DEBUG
#define LSASSERT_DEBUG(expr)                                    \
  {                                                             \
    if (expr) {                                                 \
    } else {                                                    \
      report_assert_failure(#expr, "", __FILE__, __LINE__);     \
      debugBreak();                                             \
    }                                                           \
  }
#else
#define LSASSERT_DEBUG(expr)
#endif

#else
#define LSASSERT(expr)
#define LSASSERT_MSG(expr, msg)
#define LSASSERT_DEBUG(expr)
#endif