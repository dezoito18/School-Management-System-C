#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

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

extern int i,newcla,newalu;
extern Clas *clas;
extern FILE *arq;

void hub();
void clascreator();
void cadclas(Clas *clase);
int cad(Clas *clase);
void turm(int turma);
void save();
void load();

#endif // SYSTEM_H_INCLUDED
