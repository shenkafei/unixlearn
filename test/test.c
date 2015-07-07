#include "pub/apue.h"
#include "phonebook.h"
#include "file.h"
#include <errno.h>

void console(void);
void PrintAscii(void);
int ArryElemMove(int *arry, unsigned int elem_num, unsigned int pos, int *dir);
void PrintArry(int *arry, int elem_num);

int main(int argc, char *agrv[])
{

//    PrintAscii();

//    console();

    int arry[] = {8, 3, -1, 0, -3, 5, -4, 2, 4, 0, -2, -5, 7, 6, -3, 0, 0, 1, 0};
    int i = 0;
    int elem_num = 0;
    int dir = 0;
    int pos = 0;
    int fd = -1;
    off_t curpos = -1;

    elem_num = sizeof(arry) / sizeof(int);

    PrintArry(arry, elem_num);
    
    for (i = 0; i < elem_num; i++)
    {
        ArryElemMove(arry, elem_num, pos, &dir);
        if (0 == dir)
        {
            pos++;
        }
    }
    
    PrintArry(arry, elem_num);
    
    fd = openFile("test.txt");
    if (-1 == fd)
    {
        printf("openFile failed\n");
        return -1;
    }
    
    curpos = getFilePos(fd);


    
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

int ArryElemMove(int *arry, unsigned int elem_num, unsigned int pos, int *dir)
{
    int i = 0;
    int temp = 0;

    if (NULL == arry || elem_num < 1 || pos > elem_num-1)
    {
        err_msg("input error");
        return -1;
    }

    temp = arry[pos];

    *dir = 0;

    if (temp < 0)
    {
        for (i = pos; i > 0; i--)
        {
            arry[i] = arry[i-1];
        }

        arry[i] = temp;
    }
    else if (temp > 0)
    {
        for (i = pos; i < elem_num-1; i++)
        {
            arry[i] = arry[i+1];
        }
        
        arry[i] = temp;

        *dir = 1;
    }

    return 0;
}

void PrintArry(int *arry, int elem_num)
{
    int i = 0;

    if (NULL == arry) return;

    for (i = 0; i < elem_num; i++)
    {
        printf("%d ", arry[i]);
        if ((i+1)%32 == 0)
        {
            printf("\n");
        }
    }

    printf("\n");
}
