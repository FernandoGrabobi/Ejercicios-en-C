#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    ///cadena de texto para el menu
    char mensaje_1="/";
    char mensaje_2="----\n";
    ///
    ///cantidad de opciones del menu
    int max_menu=3;
    int min_menu=1;
    ///
    ///variable para mantener menu
    int n=2;
    ///
    ///parametro del switch
    float menu_1;
    int menu;
    ///
    while(n==2){

        printf("1\n:");
        scanf("%f",&menu_1);
        menu=(int)menu_1;
        /*Controlador*/
        while(menu<min_menu || menu>max_menu){
                printf("----Valor fuera de rango----\n");
                printf("----Introdusca un valor entre el:%d%d\n",min_menu,max_menu);
                scanf("%f",&menu_1);
                menu=(int)menu_1;

        }
        /*/controlador*/
        switch(menu){

            case 1:
                printf("----1----\n");

                break;
            case 2:
                printf("----2----\n");

                break;
            case 3:
                 printf("----3----\n");

                break;

        }

    }


    return 0;
}
