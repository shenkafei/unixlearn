/*************************************************************************
	> File Name: SqList.c
	> Author:
	> Mail:
	> Created Time: 2015年01月27日 星期二 23时03分28秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"sqlist.h"


Status SqList_Init(SqList *L)
{
    // 构造一个空的顺序表L

    if (NULL == L) return ERROR;

    L->elem = (ElemType *)malloc(sizeof(ElemType) * LIST_INIT_LEN);
    if (NULL == L->elem)
    {
        printf("sqlist init malloc fail");
        exit(OVERFLOW);
    }

    L->length = 0;
    L->listsize = LIST_INIT_LEN;

    return OK;
}

Status SqList_Destroy(SqList *L)
{
    // 销毁线性表L
    if (NULL == L) return ERROR;

    if (NULL != L->elem)
    {
        free(L->elem);
        L->elem = NULL;
    }

    L->length = 0;
    L->listsize = 0;

    return TRUE;
}

Status SqList_Clear(SqList *L)
{
    // 将L重置为空表
    if (NULL == L) return ERROR;

    memset(L->elem, 0, sizeof(ElemType) * L->listsize);

    L->length = 0;

    return OK;
}

Status SqList_IsEmpty(SqList L)
{
    //  表为空，返回TRUE,否则返回FALSE

    if (L.listsize <= 0)
    {
        printf("表不存在\n");
        return ERROR;
    }

    if (0 == L.length)
    {
        return TRUE;
    }

    return FALSE;
}

int SqList_Length(SqList L)
{
    // 表当前元素个数
    if (L.listsize <= 0)
    {
        printf("表不存在\n");
        return ERROR;
    }

    return L.length;
}

Status SqList_GetElem(SqList *L, int i, ElemType *elem)
{
    // 获取L中第i个元素
    if ((NULL == L) || (i < 1) || (i > L->length - 1))
    {
        printf("SqList_GetElem input  error");
        return ERROR;
    }

    *elem = L->elem[i-1];

    return OK;
}


int SqList_LocateEelm(SqList *L, ElemType elem, compare func)
{
    int i = 0;

    //返回L中第1个与e满足关系compare的数据元素的位序，不存在返回0
    if ((NULL == L) || (NULL == func))
    {
        printf("SqList_LocateEelm input error");
        return ERROR;
    }

    for (i = 0; i < L->length-1; i++)
    {
        if (OK == func(L->elem[i], elem))
        {
            return (i + 1);
        }
    }

    return ERROR;
}

Status SqList_PriorElem(SqList *L, ElemType cur_e, ElemType *pre_e)
{
    int i = 0;

    // cur_e为L中元素，且不是第一个，则用pre_e返回其前驱，否则失败
    if ((NULL == L) || (NULL == pre_e))
    {
        return ERROR;
    }

    for (i = 1; i < L->length-1; i++)
    {
        if (0 == memcmp(&(L->elem[i]), &cur_e, sizeof(ElemType)))
        {
            *pre_e = L->elem[i-1];
            return OK;
        }
    }

    return ERROR;
}

Status SqList_NexElem(SqList *L, ElemType cur_e, ElemType *next_e)
{
    int i = 0;
    // cur_e为L中元素，且不是最后一个，则用pre_e返回其后驱，否则失败
    if ((NULL == L) || (NULL == next_e))
    {
        return ERROR;
    }

    for (i = 0; i < (L->length - 2); i++)
    {
        if (0 == memcmp(&(L->elem[i]), &cur_e, sizeof(ElemType)))
        {
            *next_e = L->elem[i+1];
            return OK;
        }
    }

    return ERROR;
}

Status SqList_InsertElem(SqList *L, int i, ElemType elem)
{
    // 在L的i位置插入元素elem，长度增1

    ElemType *newbase;
    ElemType *p = NULL;
    ElemType *q = NULL;

    if ((NULL == L) || (i < 1)|| (i > L->length + 1))
    {
        printf ("sqlist Insert elem input error");
        return ERROR;
    }

    /* 若插入新元素时已超过队列最大长度则在原队列上新分配空间 */
    if (L->length >= L->listsize)
    {
        newbase = (ElemType *)realloc(L->elem,
                                      L->length + sizeof(ElemType)*LISTINCREMENT);
        if (NULL == newbase)
        {
            printf("inscribe sqlist length fail");
            exit(OVERFLOW);
        }

        L->elem = newbase;
        L->length += LISTINCREMENT;
    }

    p = &(L->elem[i-1]);
    if (TRUE != SqList_IsEmpty(*L))
    {
        q = &(L->elem[L->length-1]);
        while (q > p)
        {
            *(q + 1) = *q;
            q--;
        }
    }

    *p = elem;
    L->length++;

    return OK;
}

Status SqList_DeleteElem(SqList *L, int i, ElemType *elem)
{
    // 删除L中第i个元素，并用elem返回其值

    ElemType *p = NULL;
    ElemType *q = NULL;

    if ((NULL == L) || (i < 1) || (i > L->length) || (NULL == elem))
    {
        printf("sqlist delete elem input error");
        return ERROR;
    }

    p = &(L->elem[i-1]);

    *elem = *p;

    q = &(L->elem[L->length-1]);

    while (p < q)
    {
        *p = *(p + 1);
        p++;
    }

    L->length--;
}


Status SqList_Traverse(SqList *L, visit func)
{
    int i = 0;

    // 依次对L中的每个数据调用函数visit。一旦visit()失败，则操作失败

    for (i = 0; i < L->length; i++)
    {
        if (OK != func(L->elem[i]))
        {
            return ERROR;
        }
    }

    return OK;
}
