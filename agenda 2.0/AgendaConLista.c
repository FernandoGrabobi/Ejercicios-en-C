#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

struct nodoLista{
    char Nombre[15];
    char Apellido[35];
    char Sobrenombre[10];
    long DNI;
    struct nodoLista *ptrSiguiente;
};

typedef struct nodoLista NodoLista;
typedef NodoLista *ptrNodoLista;

void MENU(){

    printf("\n---Opcion 1 Para AGREGAR DATOS de la AGENDA---\n");
    printf("\n---Opcion 2 Para ELIMINAR UNA PERSONA de la AGENDA---\n");
    printf("\n---Opcion 3 Para BUSCAR a alguien en la AGENDA por el DNI---\n");
    printf("\n---Opcion 4 Para MOSTRAR el listado de todas las personas de acuerdo a un atributo de la estructura (Nombre, Apellido, Sobrenombre y Telefono)---\n");
    printf("\n---Opcion 5 Para Salir del programa---\n");  

}

void insertar( ptrNodoLista *ptrS, NodoLista *agenda ){
   ptrNodoLista ptrNuevo;
   ptrNodoLista ptrAnterior;
   ptrNodoLista ptrActual;

    ptrNuevo = malloc(sizeof(NodoLista));

   if (ptrNuevo != NULL ){
      strcpy(ptrNuevo->Nombre,agenda->Nombre);
      strcpy(ptrNuevo->Apellido,agenda->Apellido);
      strcpy(ptrNuevo->Sobrenombre,agenda->Sobrenombre);
      ptrNuevo->DNI=agenda->DNI;
      ptrNuevo->ptrSiguiente = NULL;

      ptrAnterior = NULL;
      ptrActual = *ptrS;

      while(ptrActual != NULL && agenda->DNI > ptrActual->DNI){
         ptrAnterior = ptrActual;
         ptrActual = ptrActual->ptrSiguiente;
      }
      if(ptrAnterior == NULL){
         ptrNuevo->ptrSiguiente = *ptrS;
         *ptrS = ptrNuevo;
      }else{
         ptrAnterior->ptrSiguiente = ptrNuevo;
         ptrNuevo->ptrSiguiente = ptrActual;
      }
   }else{
      printf( "No se inserto, No hay memoria disponible.\n");
   }

}

void imprimeLista( ptrNodoLista ptrActual){

  system("cls");
   if(ptrActual == NULL){
      printf("\n \n");
      printf("\n La lista esta vacia. \n" );
   }else{
      printf( "La lista es:\n" );
      while(ptrActual != NULL){
         printf("\n -------------- \n");
         puts(ptrActual->Nombre);
         puts(ptrActual->Apellido);
         puts(ptrActual->Sobrenombre);
         printf("%ld ",ptrActual->DNI);
         ptrActual = ptrActual->ptrSiguiente;
         printf("\n -------------- \n");
      }
      printf( "\n final de lista \n" );
   }

}

int estaVacia( ptrNodoLista ptrS ){
   return ptrS == NULL;
}

char eliminar( ptrNodoLista *ptrS, long DNI ){
   ptrNodoLista ptrAnterior;
   ptrNodoLista ptrActual;
   ptrNodoLista tempPtr;


   if ( DNI == ( *ptrS )->DNI ) {
      tempPtr = *ptrS;
      *ptrS = ( *ptrS )->ptrSiguiente;
      free( tempPtr );
      return DNI;
   }else{
      ptrAnterior = *ptrS;
      ptrActual = ( *ptrS )->ptrSiguiente;

      while ( ptrActual != NULL && ptrActual->DNI != DNI ) {
         ptrAnterior = ptrActual;
         ptrActual = ptrActual->ptrSiguiente;
      }

      if ( ptrActual != NULL ) {
         tempPtr = ptrActual;
         ptrAnterior->ptrSiguiente = ptrActual->ptrSiguiente;
         free( tempPtr );
         return DNI;
      }

   }
   return '\0';
}

void Buscar(ptrNodoLista *ptrS, long DNI){
    ptrNodoLista ptrAnterior;
    ptrNodoLista ptrActual;
   if (DNI == ((*ptrS)->DNI)){

      *ptrS = (*ptrS)->ptrSiguiente;
       printf("\n -------------- \n");
       puts(ptrActual->Nombre);
       puts(ptrActual->Apellido);
       puts(ptrActual->Sobrenombre);
       printf("%ld ",ptrActual->DNI);
       printf("\n -------------- \n"); 

   }else{
      ptrAnterior = (*ptrS);
      ptrActual = (*ptrS)->ptrSiguiente;

      while ( ptrActual != NULL && DNI > ptrActual->DNI ) {
               ptrAnterior = ptrActual;
               ptrActual = ptrActual->ptrSiguiente;

            }
            if(DNI == ptrActual->DNI){
                  printf("\n -------------- \n");
                  puts(ptrActual->Nombre);
                  puts(ptrActual->Apellido);
                  puts(ptrActual->Sobrenombre);
                  printf("%ld ",ptrActual->DNI);
                  printf("\n -------------- \n"); 
               }
   }
   
         

}

void MostrarListaSegun(NodoLista *agenda,int *eleccion,ptrNodoLista ptrActual){

   switch(*eleccion){
   case 1:

     system("cls");
      if(ptrActual == NULL){
         printf("\n \n");
         printf("\n La lista esta vacia. \n" );
      }else{
         printf( "La lista por nombres es:\n" );
         while(ptrActual != NULL){
            printf("\n -------------- \n");
            puts(ptrActual->Nombre);
            ptrActual = ptrActual->ptrSiguiente;
         }
          printf( "\n final de lista \n" );
       }

   break;
   case 2:
     system("cls");
      if(ptrActual == NULL){
         printf("\n \n");
         printf("\n La lista esta vacia. \n" );
      }else{
         printf( "La lista por Apellido es:\n" );
         while(ptrActual != NULL){
            printf("\n -------------- \n");
            puts(ptrActual->Apellido);
            ptrActual = ptrActual->ptrSiguiente;
         }
          printf( "\n final de lista \n" );
       }

   break;
   case 3:
     system("cls");
      if(ptrActual == NULL){
         printf("\n \n");
         printf("\n La lista esta vacia. \n" );
      }else{
         printf( "La lista por SobreNombre es:\n" );
         while(ptrActual != NULL){
            printf("\n -------------- \n");
            puts(ptrActual->Sobrenombre);
            ptrActual = ptrActual->ptrSiguiente;
         }
          printf( "\n final de lista \n" );
       }
   break;
   }
}

int main(){

int menu,eleccion;
NodoLista agenda;
bool bandera;
char nombre[15], apellido[35], sobrenombreb[10];
ptrNodoLista ptrInicial = NULL;
long DNI;

DNI = 0;
menu = 0;
eleccion = 0;
bandera = false;

    while(menu != 5 ){
    /*Menu*/
    MENU();
    scanf("%d",&menu);
    /*Control de errores menu*/
    while((menu >5)||(menu < 0)){
         system("cls");
         printf("\n---ERROR valor ingresado fuera de los parametros permitidos---\n");
         MENU();
         scanf("%d",&menu);
    }
    /*fin Control de errores menu*/
        switch(menu){
            case 1:
            system("cls");
            printf("\n --- A seleccionado la opcion 1 --- \n");
            printf("\n \n");

            fflush(stdin);
            system("cls");
            printf("\n___Ingrese el NOMBRE: (Maximo 15 caracteres)___\n");
            gets(agenda.Nombre);
            printf("\n___Ingrese el Apellido: (Maximo 35 caracteres)___\n");
            gets(agenda.Apellido);
            printf("\n___Ingrese el SobreNombre: (Maximo 10 caracteres)___\n");
            gets(agenda.Sobrenombre);
            printf("\n___Ingrese el DNI: ___\n");
            scanf("%ld",&agenda.DNI);
            insertar(&ptrInicial, &agenda);
            imprimeLista(ptrInicial);

            bandera = true;
            break;
            case 2:
            system("cls");
            printf("\n --- A seleccionado la opcion 2 --- \n");
            printf("\n \n");
                 if(bandera == true){
                     printf("\n Ingrese el DNI de la persona que quiera Eliminar:  \n");
                     scanf("%ld",&DNI);
                     eliminar(&ptrInicial,DNI);
                     imprimeLista( ptrInicial );
                  }else{
                     printf("\n Debe ingresar primero la opcion 1 para poder usar esta opcion \n");
                  }
                  printf("\n \n");
            break;
            case 3:
            system("cls");
            printf("\n --- A seleccionado la opcion 3 --- \n");
            printf("\n \n");
                 if(bandera == true){

                     printf("\n Ingrese el DNI de la persona que quiera Mostrar: \n");
                     scanf("%ld",&DNI);
                     Buscar(&ptrInicial,DNI);


                }else{
                printf("\n Debe ingresar primero la opcion 1 para poder usar esta opcion \n");}
                printf("\n \n");
            break;
            case 4:
            system("cls");
            printf("\n --- A seleccionado la opcion 4 ---\n");
            printf("\n \n");
                 if(bandera == true){
                    printf("\n Ingresar un numero para Ver listado de las personas segun:\n");
                    printf("\t 1) Nombre \n");
                    printf("\t 2) Apellido \n");
                    printf("\t 3) Sobrenombre \n");
                    scanf("%d",&eleccion);
                    /*Control de eleccion*/
                    while ((eleccion < 0)||(eleccion > 3)){
                     printf("\n ERROR valor ingresado fuera de los parametros permitidos\n");
                     printf("\n Ingresar un numero para Ver listado de las personas segun:\n");
                     printf("\t 1) Nombre \n");
                     printf("\t 2) Apellido \n");
                     printf("\t 3) Sobrenombre \n");
                     scanf("%d",&eleccion);
                    }
                    /*Fin control de eleccion*/
                    MostrarListaSegun(&agenda,&eleccion,ptrInicial);


                }else{
                printf("\n Debe ingresar primero la opcion 1 para poder usar esta opcion \n");}
                printf("\n \n");
            break;
            case 5:
             system("cls");
             printf("\n --- El programa finalizo correctamente ---\n");
            break;
        }
    }
return 0;
}
