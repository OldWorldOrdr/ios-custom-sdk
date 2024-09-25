#include <errno.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int __putenv(const char *string, int overwrite) {
  __environ_alloc();
  if (!__environ_allocated)
    return -1;
  char *p = strchr(string, '=');
  if (p == NULL) {
    errno = EINVAL;
    return -1;
  }

  int i = __findenv(string);
  if (i != -1) {
    if (overwrite) {
      free(environ[i]);
      environ[i] = strdup(string);
    }
    return 0;
  }

  int environ_len = 0;
  while (environ[environ_len] != NULL)
    environ_len++;
  char **new_environ = realloc(environ, (environ_len + 2) * sizeof(char *));
  if (new_environ == NULL)
    return -1;
  new_environ[environ_len] = strdup(string);
  new_environ[environ_len + 1] = NULL;
  environ = new_environ;
  return 0;
}
