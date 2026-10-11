#include "fadec.h"

#include <stdint.h>

uint64_t fd_effects(const FdInstr* instr) {
  static const uint64_t effects[] = {
#define FD_DECODE_TABLE_EFFECTS_TABLE
#include <fadec-decode-private.inc>
#undef FD_DECODE_TABLE_EFFECTS_TABLE
  };
  static const uint16_t indices[] = {
#define FD_DECODE_TABLE_EFFECTS_INDICES
#include <fadec-decode-private.inc>
#undef FD_DECODE_TABLE_EFFECTS_INDICES
  };

  return effects[indices[FD_TYPE(instr)]];
}
