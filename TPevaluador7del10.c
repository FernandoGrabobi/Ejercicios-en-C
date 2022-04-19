#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

/*---------------------------*/
/*        Codigo de fer      */
/*                           */
/*                           */
/*   EJERCICIO   evaluador   */
/*                           */
/*---------------------------*/

struct productos{
	char nombre[20];
	int precio;
	int stock;
} producto[10];

struct provedores{
	char nombre[20];
	char direccion[20];
	int telefono[20];
}proveedor[10];

void inicializar(){

    for(int i = 0; i < 10; i++){
        for(int f = 0; f < 20; f++){
        proveedor[i].nombre[f]='\0';
        proveedor[i].direccion[f]='\0';
        proveedor[i].telefono[f]='\0';
        }

    }

}

int main(){
int menu, Nproducto, Nproveedor, op, modificar, cantador;
char nombreprov, nombre[30];
bool bandera;

menu = 0;
Nproducto = 0;
op = 0;
cantador = 0;
Nproveedor = 0;
modificar = 0;
bandera = false;


    while(menu != 7 ){

    printf("\n---Opcion 1 para CARGAR PRODUCTOS, STOCK, PRECIO Y NOMBRE---\n");
    printf("\n---Opcion 2 para BUSCAR UN PRODUCTO segun el nombre---\n");
    printf("\n---Opcion 3 para BUSCAR UN PROVEEDOR segun el nombre y MOSTRAR sus PRODUCTOS ASOCIADOS---\n");
    printf("\n---Opcion 4 para MOSTRAR los productos---\n");
    printf("\n---Opcion 5 para MOSTRAR PORVEEDORES ---\n");
    printf("\n---Opcion 6 para MODIFICAR SU STOCK Y PRECIO de un PRODUCTO---\n");
    printf("\n---Opcion 7 para SALIR del programa---\n");
    scanf("%d",&menu);

    /*Control de errores menu*/

    while((menu > 7)||(menu < 0)){
    printf("\n---Opcion 1 para CARGAR PRODUCTOS, STOCK, PRECIO Y NOMBRE---\n");
    printf("\n---Opcion 2 para BUSCAR UN PRODUCTO segun el nombre---\n");
    printf("\n---Opcion 3 para BUSCAR UN PROVEEDOR segun el nombre y MOSTRAR sus PRODUCTOS ASOCIADOS---\n");
    printf("\n---Opcion 4 para MOSTRAR los productos---\n");
    printf("\n---Opcion 5 para MOSTRAR PORVEEDORES ---\n");
    printf("\n---Opcion 6 para MODIFICAR SU STOCK Y PRECIO de un PRODUCTO---\n");
    printf("\n---Opcion 7 para SALIR del programa---\n");
    scanf("%d",&menu);
    }

    /*fin Control de errores menu*/

        switch(menu){
            case 1:
            inicializar();
            system("cls");
            printf("\n --- A seleccionado la opcion 1 --- \n");
            printf("\n");

                for(int i = 0; i < 10; i++){
                    
                    printf("\n Ingrese nombre del nuevo producto %d (maximo 20 caracteres):  \n",i+1);
                    fflush(stdin);
                    scanf("%s",&producto[i].nombre); 
                    printf("\n Ingrese el precio del producto %d (entre 0 y 1000):  \n",i+1);
                    scanf("%d",&producto[i].precio);
                    /*Control de precio*/
                    while((producto[i].precio < 0)||(producto[i].precio > 1000)){
                        system("cls");
                        printf("\n---ERROR ingrese un valor dentro de los parametros permitidos---\n");
                        printf("Ingrese el precio del producto %d (entre 0 y 1000):  \n",i+1);
                        scanf("%d",&producto[i].precio);
                    }
                    /*Fin Control de precio*/
                    printf("\n Ingrese la cantidad de el producto %d (entre 0 y 1000):  \n",i+1);
                    scanf("%d",&producto[i].stock);
                     /*Control de stock*/
                    while((producto[i].stock < 0)||(producto[i].stock > 1000)){
                        system("cls");
                        printf("\n---ERROR ingrese un valor dentro de los parametros permitidos---\n");
                        printf("Ingrese la cantidad de el producto %d (entre 0 y 1000):  \n",i+1);
                        scanf("%d",&producto[i].stock);
                    }
                    /*Fin Control de stock*/
                    printf("\n ingrese el nombre del proveedor de este producto %d (maximo 20 caracteres): \n",i+1);
                    scanf("%s",&proveedor[i].nombre);
                    printf("\n ingrese la direccion del proveedor de este producto %d (maximo 20 caracteres): \n",i+1);
                    scanf("%s",&proveedor[i].direccion);
                    printf("\n ingrese el nro de TELL del proveedor de este producto %d (maximo 20 caracteres): \n",i+1);
                    scanf("%s",&proveedor[i].telefono);
                    system("pause");
                    system("cls");
                    

                }
            bandera = true;
            break;
            case 2:
            system("cls");
            printf("\n --- A seleccionado la opcion 2 --- \n");
            printf("\n");
             if(bandera == true){

                printf("\n Nombre del producto que desea buscar ?\n");
                fflush(stdin);
                scanf("%s",&nombre);

                for (int i=0;i<10;i++) {
                    if(strcmp(producto[i].nombre,nombre)==0){
                        printf("\n El producto es el siguiente: \n \n \t Nombre: %s \n",producto[i].nombre);
                        printf("\n \t Precio: %d \n",producto[i].precio);
                        printf("\n \t Stock: %d \n",producto[i].stock);
                        i = 100;
                    }
                }

                }else{
                printf("\n Debe ingresar primero la opcion 1 para poder usar esta opcion \n");}
                printf("\n \n");
            break;
            case 3:
            system("cls");
            printf("\n --- A seleccionado la opcion 3 --- \n");
            printf("\n");
             if(bandera == true){

                printf("Ingrese el nombre del proveedor por el que desea buscar:\n");
                scanf("%s",&nombre);
                 for (int i=0;i<10;i++) {
                        if(strcmp(proveedor[i].nombre,nombre)==0){
                            printf("\n El proveedor es el siguiente: \n \n \t Nombre: %s \n",proveedor[i].nombre);
                            printf("\n \t direccion: %s \n",proveedor[i].direccion);
                            printf("\n \t telefono: %s \n",proveedor[i].telefono);
                            cantador = i;
                            i = 100;
                         
                        }
                    }
                    int i = cantador;
                     for (i;i<10;i++) {
                        printf("\n----- PRODUCTO %d ASOCIADO CON EL PROVEEDOR -----\n", i + 1);
                        printf("\n \t NOMBRE del producto: %s \n", producto[i].nombre);
                        printf("\n \t PRECIO: %d \n", producto[i].precio);
                        printf("\n \t STOCK: %d \n", producto[i].stock);
                       i = 100;
                        }

                }else{
                printf("\n Debe ingresar primero la opcion 1 para poder usar esta opcion \n");}
                printf("\n \n");
            break;
            case 4:
            system("cls");
            printf("\n --- A seleccionado la opcion 4 ---\n");
            printf("\n");
             if(bandera == true){

                printf("\n La lista de productos es: \n");
                    for(int i = 0; i < 10; i++){
                        printf("\n----- PRODUCTO N %d -----\n", i + 1);
                        printf("\n \t NOMBRE del producto: %s \n", producto[i].nombre);
                        printf("\n \t PRECIO: %d \n", producto[i].precio);
                        printf("\n \t STOCK: %d \n", producto[i].stock);
                    }

                }else{
                printf("\n Debe ingresar primero la opcion 1 para poder usar esta opcion \n");}
                printf("\n \n");
            break;
            case 5:
            system("cls");
            printf("\n --- A seleccionado la opcion 5 ---\n");
            printf("\n");
            if(bandera == true){

                printf("\n La lista de los proveedores es: \n");

                    for(int i = 0; i < 10; i++){
                        printf("\n----- PROVEEDOR N %d -----\n", i + 1);
                        printf("\n \t NOMBRE del PROVEEDOR: %s \n", proveedor[i].nombre);
                        printf("\n \t DIRECCION: %s \n", proveedor[i].direccion);
                        printf("\n \t TELEFONO: %s \n", proveedor[i].telefono);

                    }

             }else{
                printf("\n Debe ingresar primero la opcion 1 para poder usar esta opcion \n");}
                printf("\n \n");
            break;
            case 6:
            system("cls");
            printf("\n --- A seleccionado la opcion 6 ---\n");
            if(bandera == true){

                printf("\n Desea modificar el precio u stock de algun producto 1 para si, 0 para no?\n");
                fflush(stdin);
                scanf("%d",&op);
                 while((op < 0)||(op > 1)){
                     system("cls");
                     printf("\n---ERROR ingrese un valor dentro de los parametros permitidos---\n");
                     printf("\n Desea modificar el precio u stock de algun producto 1 para si, 0 para no?\n");
                     scanf("%d",&op);
                    }
                if(op == 1){
                    printf("\n Que producto desea modificar del 1 al 10? \n");
                    scanf("%d",&modificar);
                    int i = modificar - 1;
                     for (i;i<10;i++) {
                            system("cls");
                            printf("\n Ingrese el precio del producto %d (entre 0 y 1000):  \n",i+1);
                            scanf("%d",&producto[i].precio);
                            /*Control de precio*/
                            while((producto[i].precio < 0)||(producto[i].precio > 1000)){
                                system("cls");
                                printf("\n---ERROR ingrese un valor dentro de los parametros permitidos---\n");
                                printf("Ingrese el precio del producto %d (entre 0 y 1000):  \n",i+1);
                                scanf("%d",&producto[i].precio);
                            }
                            /*Fin Control de precio*/
                            printf("\n Ingrese la cantidad de el producto %d (entre 0 y 1000):  \n",i+1);
                            scanf("%d",&producto[i].stock);
                             /*Control de stock*/
                            while((producto[i].stock < 0)||(producto[i].stock > 1000)){
                                system("cls");
                                printf("\n---ERROR ingrese un valor dentro de los parametros permitidos---\n");
                                printf("Ingrese la cantidad de el producto %d (entre 0 y 1000):  \n",i+1);
                                scanf("%d",&producto[i].stock);
                            }
                            /*Fin Control de stock*/
                            i = 100;
                    }
                }else{
                    printf("\n Decidio no seguir con la modificacion \n");
                }
          
           }else{ printf("\n Debe ingresar primero la opcion 1 para poder usar esta opcion \n");}
            printf("\n \n");

            break;
            case 7:
            system("cls");

            printf("\n --- (: El Programa finalizo correctamente :) ---\n");
            printf("\n");

            break;
            default:
            printf("\n---Opcion incorrecta---\n");
            break;
        }
    }
return 0;
}
