#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

/*SALE 2 VECES si pongo 1*/

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

void buscar(int arreglo[], int *numeroB, int tamanio){
    int inicio, medio, fin, auxiliar;
    bool band;

    inicio=0;
    fin = 0;
    medio = 0;
    band = false;

    inicio=arreglo[0];
    fin=arreglo[9];
    medio=(inicio+fin)/2;
    auxiliar=fin-inicio;
    

    while(inicio <= fin){

        if(*numeroB == arreglo[medio]){
            band = true;
            break;
        }
            if(*numeroB < arreglo[medio]){
                if(*numeroB == (medio - 1)){
                printf("\n El elemento que se encuentra en la posicion es: %d \n", arreglo[medio-1]);
                }
             fin = medio;
             medio=(inicio+fin)/2;
            }
            if(*numeroB > arreglo[medio]){
                if(*numeroB == (medio + 1)){
                printf("\n El elemento que se encuentra en la posicion es: %d \n", arreglo[medio+1]);       
                }
            inicio = medio;
            medio=(inicio+fin)/2;
            }
    }
    if (band == false){
        printf("\n--- El numero buscado no existe ---\n");
    }else if (band == true){
        printf("\n El elemento se encuentra en la posicion: %d \n", medio+1);
    }
}

int main(){

int menu, numero, elementobuscado;
bool bandera;
int arreglo[9];
menu = 0;
bandera = false;
numero = 0;
elementobuscado = 0;

    while(menu != 4 ){
    /*Menu*/

    printf("\n---Opcion 1 para cargar arreglo---\n");
    printf("\n---Opcion 2 para ordenar y mostrar arreglo ---\n");
    printf("\n---Opcion 3 para buscar un elemento segun su posicion en el arreglo---\n");
    printf("\n---Opcion 4 para salir del programa---\n");
    scanf("%d",&menu);

    /*Control de errores menu*/

    while((menu > 4)||(menu < 0)){
    printf("\n---ERROR---\n");
    printf("\n---Opcion 1 para cargar arreglo---\n");
    printf("\n---Opcion 2 para ordenar y mostrar arreglo---\n");
    printf("\n---Opcion 3 para buscar un elemento segun su posicion en el arreglo---\n");
    printf("\n---Opcion 4 para salir del programa---\n");
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
            printf("\n --- A seleccionado la opcion 3 --- \n");
            printf("\n \n");
                if(bandera == true){
                    printf("\n Ingrese el elemento que desea buscar dentro del arreglo  \n");
                    scanf("%d",&elementobuscado);

                    buscar(arreglo, &elementobuscado, 9);


                }else{
                printf("\n Debe ingresar primero la opcion 1 para poder usar esta opcion \n");}
                printf("\n \n");
            break;
            case 4:
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
