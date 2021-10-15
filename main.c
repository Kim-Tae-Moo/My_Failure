#include <stdio.h>

#include "Make_New_Memo.c"
#include "Show_Memo_List.c"

extern int Make_New_Memo();
extern int Show_Memo_List();


int MainMenu(void);

int MainMenu(void)
{
        int option;
        printf("\n-----------------\n");
        printf("0.Exit Program\n");
        printf("1.Make New Memo\n");
        printf("2.Show Memo List\n");
        printf("-----------------\n");
        printf("option : ");
        scanf("%d", &option);

        if (option==0) return 0;
        else if (option==1) Make_New_Memo();
        else if (option==2) Show_Memo_List();
        else printf("Program has shutdown.\n");
        return 0;
}

int main(void)
{
        MainMenu();
}