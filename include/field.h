#ifndef SYZGO_INCLUDE_RENDER_H_
#define SYZGO_INCLUDE_RENDER_H_

#include "include/base.h"

void field_init(Field& f);
void field_render(const Field& f);
void field_update(Field& f);
E_OCC_TYPE field_occtype_round(const Field& f, uint8_t row, uint8_t col);

#endif
