#include <stdio.h>
#include <unistd.h>

FILE __stdout = {STDOUT_FILENO, __SWR, NULL, BUFSIZ, 0,     false,
                 false,         0,     read, write,  lseek, close};

FILE *stdout = &__stdout;
