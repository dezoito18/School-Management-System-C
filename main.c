#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct{
    char name[50];
    int age;
    float grade[8];
}Student;

typedef struct{
    Student *alu;
    int Capacidade,Qtd;
    char prof[50];
}Clas;

int i=0,newcla=0,newalu=0;
Clas *clas=NULL;
FILE *arq;

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
