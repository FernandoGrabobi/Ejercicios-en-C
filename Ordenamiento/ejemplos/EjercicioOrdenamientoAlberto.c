#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>



void intercambia(int *numero1, int *numero2){

    int auxiliar = *numero1;
    *numero1 = *numero2;
    *numero2 = auxiliar;
}

void ordenar(int arreglo[], int tamanio){

    for(int i = 0; i < tamanio-1 ;i++){
        for(int f = 0; f < tamanio - 1; f++){

            if(arreglo[f]>arreglo[f+1]){
                intercambia(&arreglo[f],&arreglo[f+1]);
            }

        }
    }

}


int main(void){


int menu, numero;
bool bandera;
int arreglo[9];
menu = 0;
bandera = false;
numero = 0;


    while(menu != 3 ){
    /*Menu*/

    printf("\n---Opcion 1 para cargar arreglo---\n");
    printf("\n---Opcion 2 para ordenar arreglo---\n");
    printf("\n---Opcion 3 para salir del programa---\n");
    scanf("%d",&menu);

    /*Control de errores menu*/

    while((menu > 3)||(menu < 0)){
    printf("\n---ERROR---\n");
    printf("\n---Opcion 1 para cargar arreglo---\n");
    printf("\n---Opcion 2 para ordenar arreglo---\n");
    printf("\n---Opcion 3 para salir del programa---\n");
    scanf("%d",&menu);
    }

    /*fin Control de errores menu*/

        switch(menu){
            case 1:
            system("cls");
            printf("\n --- A seleccionado la opcion 1 --- \n");
            printf("\n \n");
            for(int i=0;i<9;i++){
                    arreglo[i]=0;
            }
            for(int i=0;i<9;i++){
                printf("\n Ingrese el dato de la posicion %d del arreglo \n", i + 1);
                scanf("%d",&numero);
                arreglo[i]=numero;
            }

            bandera = true;
            break;
            case 2:
            system("cls");
            printf("\n --- A seleccionado la opcion 2 --- \n");
            printf("\n \n");
                 if(bandera == true){

                ordenar(arreglo,9);

                for(int i=0;i<9;i++){
                printf("\t %d ", arreglo[i]);
                }

                }else{
                printf("\n Debe ingresar primero la opcion 1 para poder usar esta opcion \n");}
                printf("\n \n");

            break;
            case 3:
            system("cls");
            printf("\n --- El PROGRAMA FINALIZO CORRECTAMENTE--- \n");
            break;

            default:
            printf("\n---Opcion incorrecta---\n");
            break;
        }

    }
return 0;
}
