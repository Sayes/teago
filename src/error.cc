#include "include/error.h"
#include <stdio.h>
#include "include/base.h"

void error(E_ERR_TYPE et, Drop drop) {
  const char* ot[] = {"", "", "BLACK", "WHITE", ""};
  switch (et) {
    case E_ERR_TYPE::DROP:
      switch (drop.status) {
        case 1:
          printf("hand %d[%s] can't drop [%d, %d], out of range!\n", drop.hand, ot[drop.ot],
                 drop.row, drop.col);
          break;
        case 2:
          printf("hand %d[%s] can't drop [%d, %d], occupied!\n", drop.hand, ot[drop.ot], drop.row,
                 drop.col);
          break;
      }
      break;
  }
}
