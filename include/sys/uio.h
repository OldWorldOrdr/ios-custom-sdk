#ifndef _SYS_UIO_H_
#define _SYS_UIO_H_

#include <stddef.h>

struct iovec {
  void *iov_base;
  size_t iov_len;
};

#endif
