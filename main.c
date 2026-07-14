#include "System.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


int i=0,newcla=0,newalu=0;
Clas *clas=NULL;
FILE *arq;

int main()
{
    setlocale(LC_ALL, "");
    int start,saida=0,chose;
    arq=fopen("save","rb+");
    if (arq==NULL)
        arq=fopen("save","wb+");
    load();
do{
        chose=0;
        hub();
        scanf("%d",&start);
        system("cls");
        switch (start){
    case 1:
        int Chose=0;
        if (clas==NULL){
            printf("No records foud.");
            break;
        }
        printf("Which class do you want to see?\n");
        for (i=0;i<newcla;i++)
            printf("Class %d°\n", i+1);
        scanf("%d",&Chose);
        turm(Chose-1);
        break;
    case 2:
        if (clas==NULL){
            printf("Class no found.");
            break;
        }
        do{
        getchar();
        printf("Which Class?");
        for (i=0;i<newcla;i++)
            printf("Class %d°\n", i+1);
        scanf(" %d",&chose);
        }while(chose>newcla||chose<1);
        cad(&clas[chose-1]);
        break;
    case 3:
        clascreator();
        cadclas(&clas[newcla-1]);
        break;
    case 4:
    rewind(arq);
    save();
    fclose(arq);
    printf("\n\tQuitting...\n");
    saida=1;
    }
}while(saida!=1);
}
