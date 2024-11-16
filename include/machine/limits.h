#ifndef _MACHINE_LIMITS_H_
#define _MACHINE_LIMITS_H_

#if defined(__arm__) || defined(__aarch64__)
#include <machine/arm/limits.h>
#elif defined(__i386__) || defined(__x86_64__)
#include <machine/x86/limits.h>
#elif defined(__riscv)
#include <machine/riscv/limits.h>
#elif defined(__powerpc__) || defined(__POWERPC__)
#include <machine/powerpc/limits.h>
#else
#error architecture not supported
#endif

#endif
