#include <stdio.h>

#include <string.h>

#define back_space 8
#define esc 27
#define space 32

int Select_Option();

int Editor(FILE *Memo);

int ESC_Select(void);

extern int Edit_Memo(FILE *Memo, char *Path)
{
        FILE *Edit_Memo;

        Edit_Memo=fopen(Path, "a+t");

        printf("test : %s\n", Path);

        Editor(Edit_Memo);

        printf("test.now!\n");

        fclose(Edit_Memo);

        return 0;
}

int Editor(FILE *Memo)
{
        
    char content;

    int selection=1;

    printf("(If you put Enter Key,\n Editor is shutdown.)\n");
    printf("(If you want write new line,\n Put ESC key And Enter Key\n");
    printf("And then select option.)\n");

    while(selection!=0)
    {
        content=getchar();
        switch(content)
        {
            case (esc):selection=ESC_Select();break;
            case (space):fputc(' ', Memo);break;
            default:break;
            
        }
        if(EOF)
        {
            fprintf(Memo, "%c", back_space);
            fprintf(Memo, "%c", content);
        }
        else 
        {
            fprintf(Memo, "%c", (content));
            fprintf(Memo, "%c", back_space);
        }
        if (selection==0) break;
    }

    printf("\ninput is end!\n");

    return 0;
}

int ESC_Select(void)
{
    int option;

    printf("\n0-> Enter cursor and Save And End Editor\n");
    printf("1-> edit before line\n");
    printf("2-> edit next line\n");
    printf("3-> write next line\n");
    
    printf("\nSelect Option : ");
    scanf("%d", &option);
    if(option==0) return 0;
    else if (option==1) return option;
    else if (option==2) return option;
    else;

    return 0;
}
