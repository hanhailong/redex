/**
 * Copyright (c) 2016-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#pragma once

#define TMS                                     \
  TM(ANNO)                                      \
  TM(BIND)                                      \
  TM(BRIDGE)                                    \
  TM(CFG)                                       \
  TM(CLASSKILL)                                 \
  TM(DC)                                        \
  TM(DCE)                                       \
  TM(DELINIT)                                   \
  TM(DELMET)                                    \
  TM(DRAC)                                      \
  TM(EMPTY)                                     \
  TM(FINALINLINE)                               \
  TM(IDEX)                                      \
  TM(INL)                                       \
  TM(INTF)                                      \
  TM(LOC)                                       \
  TM(MAIN)                                      \
  TM(MMINL)                                     \
  TM(MTRANS)                                    \
  TM(PEEPHOLE)                                  \
  TM(PM)                                        \
  TM(PGR)                                       \
  TM(REG)                                       \
  TM(RELO)                                      \
  TM(RENAME)                                    \
  TM(SHORTEN)                                   \
  TM(SINK)                                      \
  TM(SINL)                                      \
  TM(SUPER)                                     \
  TM(SYNT)                                      \
  TM(UNTF)

enum TraceModule {
#define TM(x) x,
TMS
#undef TM
  N_TRACE_MODULES,
};

#ifdef NDEBUG
#define TRACE(...)
#else
bool traceEnabled(TraceModule module, int level);
void trace(const char* fmt, ...);
#define TRACE(module, level, fmt, ...) \
  do {                                 \
    if (traceEnabled(module, level)) { \
      trace(fmt, ##__VA_ARGS__);       \
    }                                  \
  } while (0)
#endif // NDEBUG
