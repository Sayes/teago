#ifndef TEAGO_INCLUDE_ERROR_H_
#define TEAGO_INCLUDE_ERROR_H_

#include "include/base.h"

enum E_ERR_TYPE {
  DROP,
};

void error(E_ERR_TYPE t, Drop drop);

#define CHECK_DROP(a) error(E_ERR_TYPE::DROP, (a))

#endif
