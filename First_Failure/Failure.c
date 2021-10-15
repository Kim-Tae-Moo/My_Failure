#include <stdio.h>

#define back_space 8
#define esc 27
#define space 32
#define Start 999

char buffer[1000];

int selection=Start;
int Writer0(FILE *Memo);
int Writer1(FILE *Memo);
void Enter_Menu();

int Editor();
char letter=esc;

int Editor(void)
{
    //make three file pointer
    FILE *Default_Memo, *Memo, *Edited_Memo;

    //open Default Memo, "test.txt".
    //dosen't think that default Memo has not there.
    //default memo will use measure "test.txt"'s content.
    
    Default_Memo=fopen("test.txt", "a+t");//check point 1

    int measure=getc(Default_Memo);

    //declare integer variable 'measure'
    //'measure' will measure text are there or not.

    if(measure==EOF) {
        Memo=fopen("test.txt", "w+t");
        printf("Memo has opened!\n");
    }
    else {
        Edited_Memo=fopen("test.txt", "a+t");
        printf("Edited Memo has opened!\n");
        };

    //if text has there are, open Edited_Memo.
    //else if text has there are not, open Memo.

    if (measure==EOF) Writer0(Memo);
    else Writer0(Edited_Memo);







    if (letter=='\n') {
        Enter_Menu();
        
    }

        if (measure==EOF) rewind(Memo);
        else rewind(Edited_Memo);

        if (selection==0) printf("Out Editor\n");
        else if (selection==1&&measure==EOF){rewind(stdin);Writer1(Memo);}
        else if (selection==1&&measure!=EOF)Writer1(Edited_Memo);
        else{
        printf("Program has shutdown!1\n");
        return 0;
        }
    
    //else if (selection==2) {}
    //else if (selection==3) {}
    //else if (selection==4) {}
    //else;

    if (measure==EOF) fclose(Memo);
    else fclose(Edited_Memo);
    fclose(Default_Memo);//close it when it already used.

    return 0;
}

int Writer0(FILE *Memo)//not enter input
{
    printf("(If you put Enter Key,\n");
    printf("you can save this line)\n");

    while (1){
        rewind(stdin);
        letter=getchar();
        if (letter!='\n') fprintf(Memo, "%c", letter);
        else if (letter=='\n') break;
    }
    printf("\nWriter 0 is end!\n");
    return 0;
}

int Writer1(FILE *Memo)//enter input
{
    printf("This is Writer 1.\n");
    while (selection==1&&letter!='\n'){
        rewind(stdin);
        letter=getchar();
        fprintf(Memo, "%c", letter);
        //if (letter=='\n') break;
    }
    if (letter=='\n') Enter_Menu();
    printf("\nWriter 1 is end!\n");
    return 0;
}

void Enter_Menu(){
    printf("\n0-> stay cursor and save and out\n");
    printf("1-> Write next line\n");
    printf("2-> Don\'t save and initializate this line\n");
    printf("3-> Show Memo\'s content\n");
    printf("4-> Enter cursor and Save and Out Editor\n");
    printf("\nSelect Option : ");
    selection=scanf("%d", &selection);
}

int main(void){
    Editor();
}
