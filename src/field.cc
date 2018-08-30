#include "include/field.h"
#include <stdio.h>

uint32_t g_max_grpid = 1;
void field_init(Field& f) {
  for (uint8_t i = 0; i < ROW_CNT; ++i) {
    for (uint8_t j = 0; j < COL_CNT; ++j) {
      f.eyes[i][j].row = i;
      f.eyes[i][j].col = j;
      f.eyes[i][j].ot = E_OCC_TYPE::BOUND;
      f.eyes[i][j].grpid = 0;
    }
  }
  for (uint8_t i = 1; i < ROW_CNT - 1; ++i) {
    for (uint8_t j = 1; j < COL_CNT - 1; ++j) {
      f.eyes[i][j].row = i;
      f.eyes[i][j].col = j;
      f.eyes[i][j].ot = E_OCC_TYPE::EMPTY;
      f.eyes[i][j].grpid = 0;
    }
  }
}

void field_render(const Field& f) {
  for (uint8_t i = 0; i < ROW_CNT; ++i) {
    printf("%d\t", i);
    for (uint8_t j = 0; j < COL_CNT; ++j) {
      switch (f.eyes[i][j].ot) {
        case E_OCC_TYPE::EMPTY:
          printf(" +");
          break;
        case E_OCC_TYPE::BLACK:
          printf(" @");
          break;
        case E_OCC_TYPE::WHITE:
          printf(" O");
          break;
        case E_OCC_TYPE::BOUND:
        case E_OCC_TYPE::MIXED:
        default:
          break;
      }
    }
    printf("\n");
  }
}

void field_update(Field& f) {
  for (int i = 1; i < ROW_CNT - 2; ++i) {
    for (int j = 1; j < COL_CNT - 2; ++j) {
      if (f.eyes[i][j].grpid == 1000) {
        if (f.eyes[i - 1][j].grpid != 0 && f.eyes[i - 1][j].ot == f.eyes[i][j].ot) {
          f.eyes[i][j].grpid = f.eyes[i - 1][j].grpid;  // LEFT
        } else if (f.eyes[i + 1][j].grpid != 0 && f.eyes[i + 1][j].ot == f.eyes[i][j].ot) {
          f.eyes[i][j].grpid = f.eyes[i + 1][j].grpid;  // RIGHT
        } else if (f.eyes[i][j - 1].grpid != 0 && f.eyes[i][j - 1].ot == f.eyes[i][j].ot) {
          f.eyes[i][j].grpid = f.eyes[i][j - 1].grpid;  // UP
        } else if (f.eyes[i][j + 1].grpid != 0 && f.eyes[i][j + 1].ot == f.eyes[i][j].ot) {
          f.eyes[i][j].grpid = f.eyes[i][j + 1].grpid;  // DOWN
        } else if (f.eyes[i - 1][j].grpid == 0 && f.eyes[i + 1][j].grpid == 0 &&
                   f.eyes[i][j - 1].grpid == 0 && f.eyes[i][j + 1].grpid == 0) {
          f.eyes[i][j].grpid = g_max_grpid++;
        }
      }
    }
  }
}

E_OCC_TYPE field_occtype_round(const Field& f, uint8_t row, uint8_t col) {
  E_OCC_TYPE result = E_OCC_TYPE::EMPTY;
  return result;
}
