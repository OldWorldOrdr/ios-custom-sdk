#ifndef _SYS_DARWIN_STAT_H_
#define _SYS_DARWIN_STAT_H_

#include <sys/types.h>
#include <time.h>

#define S_IWUSR 0000200
#define S_IWGRP 0000020
#define S_IWOTH 0000002

#define S_IFMT 0170000

#define S_IFBLK 0060000
#define S_IFCHR 0020000
#define S_IFDIR 0040000
#define S_IFIFO 0010000
#define S_IFREG 0100000
#define S_IFLNK 0120000
#define S_IFSOCK 0140000
#define S_IXUSR 0000100
#define S_IXGRP 0000010
#define S_IXOTH 0000001

#define S_ISUID 0004000
#define S_ISGID 0002000
#define S_ISVTX 0001000

#define S_ISBLK(m) (((m) & S_IFMT) == S_IFBLK)
#define S_ISCHR(m) (((m) & S_IFMT) == S_IFCHR)
#define S_ISDIR(m) (((m) & S_IFMT) == S_IFDIR)
#define S_ISFIFO(m) (((m) & S_IFMT) == S_IFIFO)
#define S_ISREG(m) (((m) & S_IFMT) == S_IFREG)
#define S_ISLNK(m) (((m) & S_IFMT) == S_IFLNK)
#define S_ISSOCK(m) (((m) & S_IFMT) == S_IFSOCK)

#define DEFFILEMODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

#define _STRUCT_STAT                                                           \
  {                                                                            \
    dev_t st_dev;                                                              \
    mode_t st_mode;                                                            \
    nlink_t st_nlink;                                                          \
    ino_t st_ino;                                                              \
    uid_t st_uid;                                                              \
    gid_t st_gid;                                                              \
    dev_t st_rdev;                                                             \
    long st_atime;                                                           \
    long st_atimensec;                                                         \
    long st_mtime;                                                           \
    long st_mtimensec;                                                         \
    long st_ctime;                                                           \
    long st_ctimensec;                                                         \
    long st_birthtime;                                                       \
    long st_birthtimensec;                                                     \
    off_t st_size;                                                             \
    blkcnt_t st_blocks;                                                        \
    blksize_t st_blksize;                                                      \
    unsigned int st_flags;                                                     \
    unsigned int st_gen;                                                       \
    int st_lspare;                                                             \
    long long st_qspare[2];                                                    \
  }

typedef unsigned long long ino_t;
typedef unsigned short nlink_t;

struct stat _STRUCT_STAT;
struct stat64 _STRUCT_STAT;

#endif
