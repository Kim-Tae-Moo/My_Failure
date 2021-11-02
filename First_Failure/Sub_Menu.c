#include <stdio.h>
#include <string.h>

#include "Select_Memo.c"

int MainMenu();
int Select_Memo();
int Select_Option();

extern int Sub_Menu(void){
        int option;
        printf(" Exit this Program -> 0\n");
        printf("select a memo -> 1\n");
        printf("return Main menu -> 2\n");
        
        printf("input option\'s number : ");
        scanf("%d", &option);

        if (option==0)
        {
            printf("Exit this Program successfully.\n");
        }
        else if (option==1) {
                printf("Test is Start\n");
                Select_Memo();//Error code!!
                printf("Test is End\n");
        }
        else if (option==2) return MainMenu();
        else 
        {
                printf("Program has Shutdown\n");
                return 1;
        };
        return 0;
}
