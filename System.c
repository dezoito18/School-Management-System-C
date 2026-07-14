#include "System.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void hub()
{
    printf("\n\t------------------------");
    printf("\n\t         SCHOOL         ");
    printf("\n\t------------------------\n");
    printf("\n\t[1]Classes\n\t[2]Register Student\n\t[3]Class Registration\n\t[4]Quit\n");
}
void clascreator()
{
    Clas *temp;
    if (newcla==0){
        newcla++;
        temp=malloc(newcla*sizeof(Clas));
        if (temp==NULL){
            printf("Memory Alocation Error");
            return;
        }
        clas=temp;
    }
    else{
        newcla++;
        temp=realloc(clas,newcla*sizeof(Clas));
        if (temp==NULL){
            printf("Memory Alocation Error");
            return;
        }
        clas=temp;
    }
}
void cadclas(Clas *clase)
{
    clas->Qtd=0;
    printf("%d° Ano\nProff. name: ",newcla);
    scanf(" %49[^\n]", clase->prof);
    printf ("how many students?");
    scanf("%d", &clase->Capacidade);
    clase->alu=malloc(clase->Capacidade*sizeof(Student));
    if (clase->alu==NULL)
        printf("Memory Allocation Error.");
}
int cad(Clas *clase)
{
        int f=clase->Qtd;
        Student *temp;
        if (clase->Capacidade<=clase->Qtd){
            temp = realloc(clase->alu, (clase->Capacidade + 1) * sizeof(Student));
            if (temp==NULL){
                printf("Memory Allocation Error");
                return 1;
            }
            clase->alu=temp;
            clase->Capacidade++;
        }
        printf("What's student's name: ");
        scanf(" %49[^\n]",clase->alu[f].name);
        printf("How old are you? ");
        scanf("%d", &clase->alu[f].age);
        printf("What grade of Math? ");
        scanf("%f", &clase->alu[f].grade[0]);
        printf("What grade of Portuguese? ");
        scanf("%f", &clase->alu[f].grade[1]);
        printf("What grade of Cience? ");
        scanf("%f", &clase->alu[f].grade[2]);
        printf("What grade ofe History? ");
        scanf("%f", &clase->alu[f].grade[3]);
        printf("What grade of Geography? ");
        scanf("%f", &clase->alu[f].grade[4]);
        printf("What grade of P.E.? ");
        scanf("%f", &clase->alu[f].grade[5]);
        printf("What grade of Arts? ");
        scanf("%f", &clase->alu[f].grade[6]);
        printf("What grade of English? ");
        scanf("%f", &clase->alu[f].grade[7]);
        clase->Qtd++;
        return 0;
}
void turm(int turma)
{
        int j=0,x;
        char mate[8][20]={"Math","Portuguese","Cience","History","Geography","P.E.","Arts","English"};
        printf("\n%d Ano\n\n",turma+1);
        printf("Teacher: %s\n\n",clas[turma].prof);
        while (j<clas[turma].Capacidade){
            if (clas[turma].Qtd>j){
                printf("\t%s\n", clas[turma].alu[j].name);
                for(x=0;x<8;x++)
                    printf("%-19s\t%.1f\n",mate[x],clas[turma].alu[j].grade[x]);
                printf("\n");
            }
            j++;
        }
}
void save()
{
    fwrite(&newcla, sizeof(int), 1, arq);
    for (i=0;i<newcla;i++){
        fwrite(&clas[i].Capacidade,sizeof(int),1,arq);
        fwrite(&clas[i].Qtd,sizeof(int),1,arq);
        fwrite(&clas[i].prof,sizeof(char),50,arq);
        fwrite(clas[i].alu,sizeof(Student),clas[i].Qtd,arq);
    }
}
void load()
{
    if (fread(&newcla,sizeof(int),1,arq)!=1)
        return;
    clas=malloc(newcla*sizeof(Clas));
    for (i=0;i<newcla;i++){
        fread(&clas [i].Capacidade, sizeof(int),1,arq);
        fread(&clas[i].Qtd,sizeof(int),1,arq);
        fread(&clas[i].prof,sizeof(char),50,arq);
        clas[i].alu=malloc(clas[i].Capacidade*sizeof(Student));
        fread(clas[i].alu,sizeof(Student),clas[i].Qtd,arq);
    }
}
