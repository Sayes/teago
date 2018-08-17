#include "include/field.h"
#include <stdio.h>

void field_init(Field& f) {
  for (uint8_t i = 0; i < ROW_CNT; ++i) {
    for (uint8_t j = 0; j < COL_CNT; ++j) {
      f.eyes[i][j].row = i;
      f.eyes[i][j].col = j;
      f.eyes[i][j].ot = E_OCC_TYPE::BOUND;
    }
  }
  for (uint8_t i = 1; i < ROW_CNT - 1; ++i) {
    for (uint8_t j = 1; j < COL_CNT - 1; ++j) {
      f.eyes[i][j].row = i;
      f.eyes[i][j].col = j;
      f.eyes[i][j].ot = E_OCC_TYPE::EMPTY;
    }
  }
}

void field_render(const Field& f) {
  printf("\n\n");
  for (uint8_t i = 0; i < ROW_CNT; ++i) {
    printf("%d\t", i);
    for (uint8_t j = 0; j < COL_CNT; ++j) {
      switch (f.eyes[i][j].ot) {
        case E_OCC_TYPE::EMPTY:
          printf(" +");
          continue;
        case E_OCC_TYPE::BLACK:
          printf(" @");
          continue;
        case E_OCC_TYPE::WHITE:
          printf(" O");
          continue;
        case E_OCC_TYPE::BOUND:
        case E_OCC_TYPE::MIXED:
        default:
          continue;
      }
    }
    printf("\n");
  }
  printf("\n");
}

void field_update(Field& f) {}

E_OCC_TYPE field_occtype_round(const Field& f, uint8_t row, uint8_t col) {
  E_OCC_TYPE result = E_OCC_TYPE::EMPTY;
  return result;
}
