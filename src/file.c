/*************************************************************************
	> File Name: file.c
	> Author: 
	> Mail: 
	> Created Time: 2015年07月05日 星期日 21时33分55秒
 ************************************************************************/

#include <fcntl.h>
#include "pub/apue.h"

#define RWRWRW  (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)

/*
 > Function: openFile            
 > Discribe: 打开文件，若文件不存在创建文件
 > Agrement: pathname 文件名字
 > return  : 成功：文件描述符，失败：-1；
*/
int openFile(const char *pathname)
{
    int fd = -1;

    if (NULL == pathname) return -1;

    fd = open(pathname, O_CREAT|O_RDWR|O_APPEND, RWRWRW);
    if (-1 == fd)
    {
        err_ret("open %s failed", pathname);
        return fd;
    }
        
    printf("open %s success\n", pathname);

    return fd;
}

/*
* > Function: createFile
* > Discribe: 创建文件，若文件存在将文件截短为0
* > Agrement: pathname 文件名称
* > return  : 成功：文件描述符，失败：-1
*/
int createFile(const char *pathname)
{
    int fd = -1;

    if (NULL == pathname) return -1;

    fd = open(pathname, O_RDWR|O_CREAT|O_TRUNC, RWRWRW);
    if (-1 == fd)
    {
        err_ret("create %s failed", pathname);
        return fd;
    }

    printf("create %s success.\n", pathname);

    return fd;
}

/*
* > Function: closeFile
* > Describe: 关闭文件
* > Agrement:
* > return  :
*/
void closeFile(int fd)
{
    int ret = -1;

    ret = close(fd);
    if (-1 == ret)
    {
        err_ret("close %d failed", fd);
    }

    printf("close %d success.", fd);

    return;
}

/*
* > Function: setFilePos
* > Describe: 设置文件偏移量
* > Agrement:
* > return  :
*/
off_t setFilePos(int fd, off_t offset, int whence)
{
    off_t curpos = -1;

    curpos = lseek(fd, offset, whence);
    if (-1 == curpos)
    {
        err_ret("set file %d seek failed");
        return -1;
    }

    printf("set file %d seek success，curpos %ld.\n", fd, curpos);

    return curpos;
}

/*
* > Function: getFilePos
* > Describe: 关闭文件
* > Agrement:
* > return  :
*/
off_t getFilePos(int fd)
{
    int curpos = -1;

    curpos = lseek(fd, 0, SEEK_CUR);
    if (-1 == curpos)\
    {
        err_ret("get file cur pos failed");
        return -1;
    }

    printf("file curpos %d.\n", curpos);

    return curpos;
}

