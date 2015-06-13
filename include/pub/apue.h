#ifndef _APUE_H
#define _APUT_H

#define _XOPEN_SOURCE   600 /*Single Unix Specification, Version 3 */

#include <sys/types.h>      /* some system still require this */
#include <sys/stat.h>
#include <sys/termios.h>    /* for wineize */

#ifndef TIOCGWINSZ
#include <sys/ioctl.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

#define MAXLINE 4096

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

#define DIR_MODE (FILE_MODE | S_IXUSR | S_IXGRP | S_IXOTH)

typedef void Sigfunc(int);

#if defined(SIG_IGN) && !defined(SIG_ERR)
#define SIG_ERR ((SigFunc *)-1)
#endif

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

void err_ret(const char *fmt, ...);

void err_sys(const char *fmt, ...);

void err_exit(int error, const char *fmt, ...);

void err_dump(const char *fmt, ...);

void err_msg(const char *fmt, ...);

void err_quit(const char *fmt, ...);

#endif
