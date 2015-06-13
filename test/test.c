#include "pub/apue.h"
#include "phonebook.h"
#include <errno.h>

void console(void);
void PrintAscii(void);

int main(int argc, char *agrv[])
{
//    errno =  EACCES;
//
//    err_ret("%s", "test err_ret");
//
//    err_msg("%s", "test err_msg");
//
//    err_dump("%s", "test err_dump");

    PrintAscii();

    console();

    return 1;
}

void console(void)
{
    int cmd = 0;

    PhoneBook_Init();

    while(1)
    {
        printf("please input:\n");
        getchar();
        printf("1.查看通讯录\n");
        printf("2.添加联系人\n");
        scanf("%d", &cmd);
        
        switch(cmd)
        {
            case 1:
                PhoneBook_ShowList();
                break;
            case 2:
                PhoneBook_AddElem();
                break;
            default:
                break;
        }
    }
}

void PrintAscii(void)
{
    int i;

    for (i = 0; i < 0xFF; i++)
    {
        printf("%c ", i);

        if (i%16 == 0)
        {
            printf("\n");
        }
    }
}
