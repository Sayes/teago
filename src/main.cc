#include "include/drop.h"
#include "include/error.h"
#include "include/field.h"

int main(int argc, char* argv[]) {
  Field f;
  Record r;
  field_init(f);

  CHECK_DROP(drop_at(f, 4, 4, E_OCC_TYPE::BLACK, r));
  CHECK_DROP(drop_at(f, 12, 6, E_OCC_TYPE::WHITE, r));
  CHECK_DROP(drop_at(f, 17, 4, E_OCC_TYPE::BLACK, r));
  CHECK_DROP(drop_at(f, 17, 4, E_OCC_TYPE::BLACK, r));
  CHECK_DROP(drop_at(f, 3, 12, E_OCC_TYPE::WHITE, r));
  CHECK_DROP(drop_at(f, 0, 4, E_OCC_TYPE::BLACK, r));
  CHECK_DROP(drop_at(f, 16, 11, E_OCC_TYPE::BLACK, r));
  CHECK_DROP(drop_at(f, 9, 7, E_OCC_TYPE::WHITE, r));

  field_render(f);
  drop_playback(r);

  return 0;
}
