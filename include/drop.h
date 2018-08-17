#ifndef SYZGO_INCLUDE_DROP_H_
#define SYZGO_INCLUDE_DROP_H_

#include "include/base.h"
#include "include/field.h"

uint8_t is_drop_enabled(Field& f, uint8_t row, uint8_t col, E_OCC_TYPE ot);
Drop drop_at(Field& f, uint8_t row, uint8_t col, E_OCC_TYPE ot, Record& record);
Drop drop_rec(uint8_t row, uint8_t col, E_OCC_TYPE ot, uint8_t status, Record& record);
void drop_playback(const Record& record);

#endif
