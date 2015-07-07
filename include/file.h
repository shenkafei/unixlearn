/*************************************************************************
	> File Name: ../include/file.h
	> Author: 
	> Mail: 
	> Created Time: 2015年07月05日 星期日 22时46分52秒
 ************************************************************************/

#ifndef _FILE_H
#define _FILE_H

int openFile(const char *pathname);
int createFile(const char *pathname);
void closeFile(int fd);
off_t setFilePos(int fd, off_t offset, int whence);
off_t getFilePos(int fd);
#endif
