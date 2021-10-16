#include <stdio.h>
#include <string.h>

int MainMenu();

//will edit
extern int Make_New_Memo(void)
{
        FILE *New_Memo, *Memo_List;

        char title[100];
        char add_path[200]="First_Failure/Memos/";

        printf("\ninput memo\'s name : ");
        scanf("%s", title);

        New_Memo=fopen(strcat(add_path, title), "a+t");

        Memo_List=fopen("Frist_Failure/Memo_List.txt", "a+t");

        fprintf(Memo_List, "%s\n", title);

        fclose(New_Memo);
        fclose(Memo_List);

        return MainMenu();
}
