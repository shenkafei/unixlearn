/*************************************************************************
	> File Name: phone_book.c
	> Author:
	> Mail: 通讯录定义模块，完成通讯录的初始化
	> Created Time: 2015年06月06日 星期六 01时24分41秒
 ************************************************************************/

#include "pub/apue.h"
#include "sqlist.h"

int g_IsPhoneBookInitCmp = FALSE;
SqList PBList;

/*创建初始化通讯录*/
int PhoneBook_Init(void)
{
    Status sRet;

    if (TRUE == g_IsPhoneBookInitCmp)
    {
        err_msg("phonebook is already initialed！\n");
        return -1;
    }

    sRet = SqList_Init(&PBList);
    if (OK != sRet)
    {
        err_msg("phonebook init failed!\n");
        return -1;
    }

    printf("phonebook init success.\n");

    SqList_Clear(&PBList);

    g_IsPhoneBookInitCmp = TRUE;

    return 0;
}

/*销毁通讯录*/
int PhoneBook_Destroy(void)
{
    Status sRet;

    if (TRUE != g_IsPhoneBookInitCmp)
    {
        printf("phonebook not init, not need destroy.\n");
        return 0;
    }

    sRet = SqList_Destroy(&PBList);
    if (OK != sRet)
    {
        err_msg("phonebook destroy failed!");
        return -1;
    }

    g_IsPhoneBookInitCmp = FALSE;

    printf("phonebook destroy success.\n");

    return 0;
}


Status PhoneBook_Print(ElemType elem)
{
    printf("===================================\n");
    printf("sex[0:male, 1:female]:%d\n", elem.sex);
    printf("name:%s\n", elem.name);
    printf("ENname:%s\n", elem.ENname);
    printf("code:%s\n", elem.code);

    return OK;
}

/*显示通讯录*/
int PhoneBook_ShowList(void)
{
    Status sRet;

    printf("PhoneBook[total:%d,size:%d]\n", PBList.length,PBList.listsize);

    sRet = SqList_Traverse(&PBList, PhoneBook_Print);
    if (OK != sRet)
    {
        printf("show phonebook error!\n");
        return -1;
    }

    return 0;
}

/*添加新联系人*/
int PhoneBook_AddElem(void)
{
    Status sRet;
    int curPos = 0;
    ElemType newElem;

    memset(&newElem, 0, sizeof(ElemType));

    printf("please input name:\n");
    scanf("%s", newElem.name);
    printf("please input ENname:\n");
    scanf("%s", newElem.ENname);
    printf("please input code:\n");
    scanf("%s", newElem.code);
    printf("select sex:[0:male,1:female]\n");
    scanf("%d", &newElem.sex);

    curPos = SqList_Length(PBList) + 1;
    printf("Insert elem curpos:%d\n", curPos);
    sRet = SqList_InsertElem (&PBList, curPos, newElem);
    if (OK != sRet)
    {
        printf("Insert new elem failed:\n");
        return -1;
    }

    printf("Insert new elem success.\n");

    return 0;
}

