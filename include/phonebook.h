/*************************************************************************
	> File Name: phonebook.h
	> Author: 
	> Mail: 定义通讯录元素结构 
	> Created Time: 2015年02月01日 星期日 23时22分17秒
 ************************************************************************/

#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_NAME_LEN      32
#define MAX_EN_NAME_LEN   32 
#define MAX_CODE_LEN      20

typedef enum _sex
{
    male_e,
    female_e,

} Sex;

struct _phone_book
{
    Sex   sex;
    char  name[MAX_NAME_LEN];
    char  ENname[MAX_EN_NAME_LEN];
    char  code[MAX_CODE_LEN];

};

int PhoneBook_ShowList(void);

int PhoneBook_AddElem(void);
#endif
