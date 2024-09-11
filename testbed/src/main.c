#include <core/logger.h>
#include <core/asserts.h>

int main(void) {
  LSFATAL("Message: %f", 3.14f);
  LSERROR("Message: %f", 3.14f);
  LSWARN("Message: %f", 3.14f);
  LSINFO("Message: %f", 3.14f);
  LSDEBUG("Message: %f", 3.14f);
  LSTRACE("Message: %f", 3.14f);
 
  LSASSERT(1 == 0);

  return 0;
}