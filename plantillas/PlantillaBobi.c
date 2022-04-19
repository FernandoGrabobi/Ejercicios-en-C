#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>

int main(void){
/*Definir Variables*/
int menu;
/*Fin definir variables*/
/*Inicializar variables*/
menu = 0;
/*Fin inicializar variables*/
    while(menu != -1 ){
    /*Menu*/
    printf("\n");
    printf("---Opcion 1---\n");
    printf("\n");
    printf("---Opcion 2---\n");
    printf("\n");
    printf("---Opcion 3---\n");
    printf("\n");
    scanf("%d",&menu);

    /*Control de errores menu*/
    while((menu < 0)||(menu > 0)){
    printf("\n");
    printf("---ERROR---\n");
    printf("\n");
    printf("---Opcion 1---\n");
    printf("\n");
    printf("---Opcion 2---\n");
    printf("\n");
    printf("---Opcion 3---\n");
    printf("\n");
    scanf("%d",&menu);

    }
    /*Control de errores menu*/

        switch(menu){
            case 1:
            system("cls");
            printf("\n");
            printf("\n");

            break;
            case 2:
            system("cls");
            printf("\n");
            printf("\n");


            break;
            case 3:
            system("cls");
            printf("\n");
            printf("\n");


            break;
            case 4:
            system("cls");
            printf("\n");
            printf("\n");


            break;
        }

    }
return 0;
}