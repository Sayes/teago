#ifndef SYZGO_INCLUDE_BASE_H_
#define SYZGO_INCLUDE_BASE_H_

#include <stdint.h>
#include <vector>

enum E_OCC_TYPE {
  BOUND = 0,
  EMPTY = 1,
  BLACK = 2,
  WHITE = 3,
  MIXED = 4,
};

const uint8_t ROW_CNT = 21;
const uint8_t COL_CNT = 21;

typedef struct {
  uint8_t row;
  uint8_t col;
  E_OCC_TYPE ot;
  uint32_t hand;
  uint8_t status;
} Drop;

typedef std::vector<Drop> Record;

typedef struct {
  uint8_t row;
  uint8_t col;
  E_OCC_TYPE ot;
  uint32_t grpid;
} Eye;

typedef struct {
  Eye eyes[ROW_CNT][COL_CNT];
} Field;

#endif
