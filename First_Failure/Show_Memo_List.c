#include <stdio.h>
#include <string.h>

#include "Sub_Menu.c"

#define Max 999999

int Sub_Menu();

extern int Show_Memo_List(void)
{
        char list[Max];
        int option;

        FILE *List;
        List=fopen("My_Failure/First_Failure/Memo_List.txt", "a+t");

        printf("\nMemo list\n");
        printf("------------\n");
        while(EOF!=fscanf(List, "%s", list))
        {
                printf("%s\n", list);
        }

        fclose(List);
        
        return Sub_Menu();
}
