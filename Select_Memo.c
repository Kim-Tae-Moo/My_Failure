#include <stdio.h>

#include <string.h>

#include "Edit_Memo.c"

int Select_Memo();
int Select_Option(FILE *Memo, char *Path);
int Sub_Menu();
int Edit_Memo(FILE *Memo, char *Path);

extern int Select_Memo(void)
{
        char title[100], add_path[200] ="Memos/";
        char *path, list[999999], *memo;
        FILE *Memo_List, *Open_Memo;
        
        printf("input Memo\'s title : ");
        scanf("%s", title);
        
        Memo_List=fopen("Memo_List.txt", "a+t");

        //input to list from Memo_List.txt
        fscanf(Memo_List, "%s", list);

        //save searched data
        memo=strstr(list, title);

        //save full path in 'path'
        path=strcat(add_path, memo);

        //open inputed memo
        Open_Memo=fopen(path, "a+t");

        Select_Option(Open_Memo, path);

        fclose(Memo_List);
        fclose(Open_Memo);
        
        return 0;
}

extern int Select_Option(FILE *Memo, char *Path)
{
        printf("\nTesting...\n");

        int option;

        printf("\nWhat want you do?\n");
        printf("0 -> Exit Program\n");
        printf("1 -> Edit Memo\n");
        printf("X -> Delete Memo\n");
        printf("X -> Rename Memo\'s title\n");
        printf("X -> Show Memo\n");

        printf("Input Option\'s number : ");
        scanf("%d", &option);

        if (option==0) return 0;
        else if (option==1) Edit_Memo(Memo, Path);
        //else if (option==2) Delete_Memo(Memo, Path);
        //else if (option==3) Rename_Memo(Memo, Path);
        else {
                printf("\nProgram has Shutdown\n");
                return 1;
        };

        return Sub_Menu();
}