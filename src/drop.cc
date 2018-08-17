#include "include/drop.h"
#include <stdio.h>

/*
 * return value: return 0 for success, other value for error code
 * 1: position is occupied
 * 2: out of range
 * 3: death
 * 9: other error
 */

uint8_t is_drop_enabled(Field& f, uint8_t row, uint8_t col, E_OCC_TYPE ot) {
  uint8_t status = 9;
  do {
    if (row == 0 || row >= (ROW_CNT - 2) || col == 0 || col >= (COL_CNT - 2)) {
      status = 1;
      break;
    }
    if (f.eyes[row][col].ot != E_OCC_TYPE::EMPTY) {
      status = 2;
      break;
    }
    E_OCC_TYPE ot_round = field_occtype_round(f, row, col);
    if ((ot == E_OCC_TYPE::BLACK && ot_round == E_OCC_TYPE::WHITE) ||
        (ot == E_OCC_TYPE::WHITE && ot_round == E_OCC_TYPE::BLACK)) {
      status = 3;
      break;
    }
    status = 0;
  } while (0);
  return status;
}

Drop drop_at(Field& f, uint8_t row, uint8_t col, E_OCC_TYPE ot, Record& record) {
  uint8_t status = is_drop_enabled(f, row, col, ot);
  Drop drop = drop_rec(row, col, ot, status, record);
  if (status == 0) {
    f.eyes[row][col].row = row;
    f.eyes[row][col].col = col;
    f.eyes[row][col].ot = ot;
    field_update(f);
  }
  return drop;
}

Drop drop_rec(uint8_t row, uint8_t col, E_OCC_TYPE ot, uint8_t status, Record& record) {
  Drop drop;
  drop.row = row;
  drop.col = col;
  drop.ot = ot;
  drop.status = status;
  std::vector<Drop>::iterator itlast = record.end();
  uint32_t lasthand = -1;
  while (itlast != record.begin()) {
    itlast--;
    if ((*itlast).status == 0) {
      lasthand = (*itlast).hand;
      break;
    }
  }
  drop.hand = lasthand + 1;
  record.push_back(drop);
  return drop;
}

void drop_playback(const Record& record) {
  const char* txtres[] = {"", "", "BLACK", "WHITE", ""};
  for (auto it : record) {
    if (it.status == 0) {
      printf("\thand %d, %s drop at (%d, %d)\n", it.hand,
             it.ot < E_OCC_TYPE::MIXED ? txtres[it.ot] : "", it.row, it.col);
    }
  }
  printf("\n");
}
