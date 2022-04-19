#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct
{
    char nombre[31];
    char apellido[31];
    int edad;
    char sexo[2];

}  persona;
persona chicos[4];

void intercambia(int *ptrElemento1, int *ptrElemento2)
{
   int almacena_nombre = *ptrElemento1;
   *ptrElemento1 = *ptrElemento2;
   *ptrElemento2 = almacena_nombre;
}
void ordenamBurbuja(persona chicos[] , int tamanio){
       for (int pasada = 0; pasada < tamanio - 1; pasada++ ){

              for (int j = 0; j < tamanio - 1; j++){

                     if (chicos[j].edad > chicos[j+1].edad){
                        intercambia(&chicos[j].edad, &chicos[j+1].edad);
                     }
                     if (chicos[j].sexo[j] > chicos[j+1].sexo[j]){
                        intercambia(&chicos[j].sexo[j], &chicos[j+1].sexo[j]);
                     }
              }
       }
}




int main(){

int menu, eliminar,cambiar,veramigo;
bool bandera;

menu = 0;
eliminar = 0;
cambiar= 0;
veramigo = 0;
bandera = false;


    while(menu != 6 ){
    /*Menu*/

    printf("\n---Opcion 1: Cargar datos---\n");
    printf("\n---Opcion 2: Eliminar los datos de un amigue (vaciar los campos del amige seleccionado) ---\n");
    printf("\n---Opcion 3: Modificar un dato específico de un amige en particular ---\n");
    printf("\n---Opcion 4: Ver el dato de un amige en particular  ---\n");
    printf("\n---Opcion 5: Ordenar personas de menor a mayor por edad ---\n");
    printf("\n---Opcion 6: salir ---\n");

    scanf("%d",&menu);

    /*Control de errores menu*/

    while((menu > 6)||(menu < 0)){
    printf("\n---ERROR---\n");
    printf("\n---Opcion 1: Cargar datos---\n");
    printf("\n---Opcion 2: Eliminar los datos de un amiguo (vaciar los campos del amigo seleccionado) ---\n");
    printf("\n---Opcion 3: Modificar un dato específico de un amigo en particular ---\n");
    printf("\n---Opcion 4: Ver el dato de un amigo en particular  ---\n");
    printf("\n---Opcion 5: Ordenar personas de menor a mayor por edad ---\n");
    printf("\n---Opcion 6: salir ---\n");
    scanf("%d",&menu);
    }

    /*fin Control de errores menu*/

        switch(menu){
            case 1:
            system("cls");
            printf("\n --- A seleccionado la opcion 1 --- \n");
            printf("\n \n");

            for (int i=0;i<4;i++){
                printf("\n --- Amigo %d --- \n", i + 1);
                printf("\n Cargue los nombres\n");
                scanf("%s",&chicos[i].nombre);
                printf("\n Cargue los apellidos\n");
                scanf("%s",&chicos[i].apellido);
                printf("\n Cargue la edad entre 10 y 45\n");
                scanf("%d",&chicos[i].edad);

                while((chicos[i].edad < 10)||( chicos[i].edad > 45)){
                  printf("\n ___Error valor ingeresado no es valido___ \n");
                  printf("\n Cargue la edad entre 10 y 45\n");
                  scanf("%d",&chicos[i].edad);
                }

                printf("\n Cargue su sexo\n");
                scanf("%s",&chicos[i].sexo);
                printf("\n \n");
            }

            bandera = true;
            break;
            case 2:
            system("cls");
            printf("\n --- A seleccionado la opcion 2 --- \n");
            printf("\n \n");

                 if(bandera == true){

                printf("\n Que amigue vas eliminar entre 0 y 2 \n");
                scanf("%d",&eliminar);
                int i = eliminar;
                for (i;i<4;i++){
                        if(i == eliminar){
                                for(int j = 0; j < 30; j++){
                                     chicos[i].nombre[j]= '\0';
                                     chicos[i].apellido[j]= '\0';
                                     chicos[i].edad= '\0';
                                     chicos[i].sexo[j]='\0';

                                }
                            i = 15;
                        }

                }

                for(int i = 0; i < 4; i++){
                    printf("\n \n");
                    printf("\n --- Amigo %d --- \n", i + 1);
                    printf("\n Nombre: ");
                    puts(chicos[i].nombre);
                    printf("\n Apellido: ");
                    puts(chicos[i].apellido);
                    printf("\n Edad %d \n", chicos[i].edad);
                    printf("\n Sexo: ");
                    puts(chicos[i].sexo);
                    printf("\n \n");
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

                     printf("\n Que amiguo vas cambiar entre 0 y 2 \n");
                scanf("%d",&cambiar);
                int i = cambiar;
                for (i;i<4;i++){
                        if(i == cambiar){
                                   printf("\n --- Amigo %d --- \n", i + 1);
                                   printf("\n Cargue los nombres\n");
                                   scanf("%s",&chicos[i].nombre);
                                   printf("\n Cargue los apellidos\n");
                                   scanf("%s",&chicos[i].apellido);
                                   printf("\n Cargue la edad entre 10 y 45\n");
                                   scanf("%d",&chicos[i].edad);

                                        while((chicos[i].edad < 10)||( chicos[i].edad > 45)){
                                          printf("\n ___Error valor ingeresado no es valido___ \n");
                                          printf("\n Cargue la edad entre 10 y 45\n");
                                          scanf("%d",&chicos[i].edad);
                                        }

                                   printf("\n Cargue su sexo\n");
                                   scanf("%s",&chicos[i].sexo);
                                   printf("\n \n");

                            i = 15;
                        }

                }

                        for(int i = 0; i < 4; i++){
                            printf("\n \n");
                            printf("\n --- Amigo %d --- \n", i + 1);
                            printf("\n Nombre: ");
                            puts(chicos[i].nombre);
                            printf("\n Apellido: ");
                            puts(chicos[i].apellido);
                            printf("\n Edad %d \n", chicos[i].edad);
                            printf("\n Sexo: ");
                            puts(chicos[i].sexo);
                            printf("\n \n");
                }


                }else{
                printf("\n Debe ingresar primero la opcion 1 para poder usar esta opcion \n");}
                printf("\n \n");


            break;
            case 4:
            system("cls");
            printf("\n --- A seleccionado la opcion 4 ---\n");
            printf("\n \n");
                 if(bandera == true){
                    printf("Que amigue quieres ver\n");
                    scanf("%d",&veramigo);
                    int i = veramigo;

                       for(i; i < 4; i++){
                    printf("\n \n");
                    printf("\n --- Amigo %d --- \n", i + 1);
                    printf("\n Nombre: ");
                    puts(chicos[i].nombre);
                    printf("\n Apellido: ");
                    puts(chicos[i].apellido);
                    printf("\n Edad %d \n", chicos[i].edad);
                    printf("\n Sexo: ");
                    puts(chicos[i].sexo);
                    printf("\n \n");
                    i = 10;
                }

                }else{
                printf("\n Debe ingresar primero la opcion 1 para poder usar esta opcion \n");}
                printf("\n \n");

            break;
            case 5:
                 system("cls");
                 printf("\n --- A seleccionado la opcion 5 ---\n");
                 printf("\n \n");
                    if(bandera == true){
                        printf("\n Elementos de datos en el orden original \n" );
                        for(int i = 0; i < 4; i++){
                            printf("\n \n");
                            printf("\n --- Amigo %d --- \n", i + 1);
                            printf("\n Nombre: ");
                            puts(chicos[i].nombre);
                            printf("\n Apellido: ");
                            puts(chicos[i].apellido);
                            printf("\n Edad %d \n", chicos[i].edad);
                            printf("\n Sexo: ");
                            puts(chicos[i].sexo);
                            printf("\n \n");
                            }

                        ordenamBurbuja(chicos, 4);
                        printf("\n Elementos de datos en el orden nuevo \n" );
                         for(int i = 0; i < 4; i++){
                            printf("\n \n");
                            printf("\n --- Amigo %d --- \n", i + 1);
                            printf("\n Nombre: ");
                            puts(chicos[i].nombre);
                            printf("\n Apellido: ");
                            puts(chicos[i].apellido);
                            printf("\n Edad %d \n", chicos[i].edad);
                            printf("\n Sexo: ");
                            puts(chicos[i].sexo);
                            printf("\n \n");
                            }





                    }else{
                printf("\n Debe ingresar primero la opcion 1 para poder usar esta opcion \n");}
                printf("\n \n");


                break;
            case 6:
                system("cls");
                printf("\n --- UwU El programa finalizo correctamente ---\n");

                break;
            default:
            printf("\n---Opcion incorrecta---\n");
            break;
        }

    }
return 0;
}
