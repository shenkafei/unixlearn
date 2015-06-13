/*************************************************************************
	> File Name: SqList.h
	> Author: 
	> Mail: 顺序表
	> Created Time: 2015年01月27日 星期二 22时41分11秒
 ************************************************************************/

#ifndef _SQLIST_H
#define _SQLIST_H

#include "phonebook.h"

/* 函数结果状态代码 */
#define TRUE     1
#define FALSE    0
#define OK       1
#define ERROR    0
#define INFEASIBLE  -1
#define OVERFLOW    -2

/*Status是函数的类型，其值是函数结果状态代码*/
typedef int Status;

#define LIST_INIT_LEN   100  // 表初始长度
#define LISTINCREMENT   10   // 分配增量


typedef struct _phone_book ElemType;

typedef struct _sqlist   SqList;

typedef Status (* compare)(ElemType e1, ElemType e2);

typedef Status (* visit)(ElemType e);

/* 表元素 */
struct _elemtype
{
    int  socre;
    char name[MAX_NAME_LEN];

};

// 顺序表
struct _sqlist
{
    ElemType *elem;   // 存储空间基地址
    int length;       // 当前长度
    int listsize;    // 当前分配的存储容量

};


Status SqList_Init(SqList *L);

Status SqList_Destroy(SqList *L);

Status SqList_Clear(SqList *L);

int SqList_Length(SqList L);

Status SqList_InsertElem(SqList *L, int i, ElemType elem);

Status SqList_DeleteElem(SqList *L, int i, ElemType *elem);


Status SqList_Traverse(SqList *L, visit func);

#endif
