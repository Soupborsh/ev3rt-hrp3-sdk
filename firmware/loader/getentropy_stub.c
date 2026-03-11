#include <errno.h>
#include <sys/types.h>

int _getentropy(void *buffer, size_t length) {
  errno = ENOSYS; // Function not implemented
  return -1;      // Always fail
}
