#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

float stock[10], precio[10], Matriz[10][10];
float precio1, iva_21, aumento_del_10;
int producto1, dia, stock1, contador_ventas, ventas_x_dia, ventas_x_prod;

float monto_total_ventas(int dia, int cantidadp){
    printf("\n Seleccione un dia para saber las ventas realizadas \n");
    scanf("%d",&dia);
                while((dia < 0)||(dia > 9)){
                    system("cls");
                    printf("\n ---Error - ingrese un valor entre 0 y 9 ---\n");
                    scanf("%d",&dia);
                 }

    for(int i = 0; i < 10; i++){
            if(Matriz[dia][i] > 0 ){
                ventas_x_dia = ventas_x_dia + 1;
            }

    }
    printf("\n Las ventas realizadas en el dia %d fueron %d \n", dia, ventas_x_dia);
    printf("\n   \n");
    printf("\n Seleccione un producto para saber las ventas realizadas \n");
    scanf("%d",&producto1);
         while((producto1 < 0)||(producto1 > 9)){
                system("cls");
                printf("\n ---Error - ingrese un valor entre 0 y 9 ---\n");
                scanf("%d",&producto1);
             }

        for(int i = 0; i < 10; i++){
            if(Matriz[i][producto1] > 0 ){
                ventas_x_prod = ventas_x_prod + 1;
            }

    }
    printf("\n Las ventas totales realizadas por el producto %d fueron %d \n", producto1, ventas_x_prod);
}

float IVA(int precio1){

if(precio1 > 150){
    iva_21 = (Matriz[dia][producto1] * 0.21);
    Matriz[dia][producto1] = Matriz[dia][producto1] - iva_21;
}
    if(precio1 < 100){
        aumento_del_10 =  Matriz[dia][producto1] * 0.10;
         Matriz[dia][producto1] =  Matriz[dia][producto1] + aumento_del_10;
    }else{
    printf("\n no se aplica el iva ni aumentos \n");
    }
}

int control_stock(int cantidadp){
    if(precio1 > 0){
            if(cantidadp > stock[producto1]){
        printf("\n No hay stock suficiente para realizar la venta \n");
         for(int i = 0; i < 10; i++){
            printf("\n El stock para el producto %d es : %f productos \n", i +1, stock[i]);
        }
    }else{
     printf("\n Hay stock suficiente para realizar la venta \n");

    Matriz[dia][producto1] = stock1 * precio[producto1];
    contador_ventas = contador_ventas + 1;
    }
    }else{
    printf("\n No hay precio para este producto\n");
    }
}

void inicializar(){
    ventas_x_prod = 0;
    ventas_x_dia = 0;
    for(int i = 0; i < 10; i++ ){
        stock[i]=0;
        precio[i]=0;
     }

    for(int i = 0; i < 10; i++ ){
        for(int j = 0; j < 10; j++){
        Matriz[i][j]=0;
        }

    }

}

int main(){
int menu, cantidadp;
menu = 0;

    while(menu != 6){
        printf("\n--- Opcion 1 para inicializar el programa ---\n");
        printf("\n--- Opcion 2 para cargar datos de los productos ---\n");
        printf("\n--- Opcion 3 para registrar ventas de productos ---\n");
        printf("\n--- Opcion 4 para Mostrar datos registrados ---\n");
        printf("\n--- Opcion 5 para Eliminar registro de venta---\n");
        printf("\n--- Opcion 6 Finalizar programa ---\n");
        scanf("%d",&menu);

    /*control errores menu*/
    while((menu< 0)||(menu > 6)){
        system("cls");
        printf("\n--- Error ---\n");
        printf("\n--- Opcion 1 para inicializar el programa  ---\n");
        printf("\n--- Opcion 2 para cargar datos de los productos ---\n");
        printf("\n--- Opcion 3 para registrar ventas de productos ---\n");
        printf("\n--- Opcion 4 para Mostrar datos registrados ---\n");
        printf("\n--- Opcion 5 para Eliminar registro de venta---\n");
        printf("\n--- Opcion 6 Finalizar programa ---\n");
        scanf("%d",&menu);
        }

     switch(menu){
     case 1:
            system("cls");
            stock1 = 0;
            precio1 = 0;
            dia=0;
            producto1 = 0;
            cantidadp = 0;
            inicializar();
            printf("\n--- Se Inicializo el programa correctamente ---\n");

        break;
     case 2:
            system("cls");
             printf("\n Por favor, Ingresa el stock de cada producto, entre 0 y 100 \n");
             for(int i = 0; i < 10; i++ ){
                printf("\n Producto numero %d \n", i + 1);
                scanf("%d",&stock1);

                while((stock1 < 0)||(stock1 > 100)){
                system("cls");
                printf("\n --- Error - Ingresa un valor entre 0 y 100 ---\n");
                printf("\n Producto numero %d \n", i + 1);
                scanf("%d",&stock1);
                }

                stock[i]=stock1;
             }

            printf("\n Por favor, Ingresa el precio de cada producto, entre 0 y 500 dolares \n");
            for(int i = 0; i < 10; i++){
            printf("\n Precio del Producto numero %d \n", i + 1);
            scanf("%f",&precio1);
            while((precio1 < 0)||(precio1 > 500)){
                printf("\n --- Error - Ingresa un valor entre 0 y 500 ---\n");
                printf("\n Producto numero %d \n", i + 1);
                scanf("%f",&precio1);

            }
            precio[i] = precio1;
        }

        break;
     case 3:
             system("cls");
             printf("\n Que dia usted esta realizando la venta ? entre 0 y 9 \n");
             scanf("%d",&dia);
                 while((dia < 0)||(dia > 9)){
                    system("cls");
                    printf("\n ---Error - ingrese un valor entre 0 y 9 ---\n");
                    scanf("%d",&dia);
                 }

                 printf("\n Que Producto desea vender ? entre 0 y 9 \n");
                scanf("%d",&producto1);

                while((producto1 < 0)||(producto1 > 9)){
                system("cls");
                printf("\n ---Error - ingrese un valor entre 0 y 9 ---\n");
                scanf("%d",&producto1);
             }

             printf("\n a seleccionado el Producto : %d \n", producto1);
             printf("\n Que cantidad de este producto desea llevar ? entre 0 y 9 \n");
             scanf("%d",&cantidadp);
             control_stock(cantidadp);
             IVA(precio1);


        break;
     case 4:
             system("cls");
             printf("\n - Seleccione un producto el cual mostrara su precio - \n");
             scanf("%d",&producto1);
                while((producto1 < 0)||(producto1 > 9)){
                system("cls");
                printf("\n ---Error - ingrese un valor entre 0 y 9 ---\n");
                scanf("%d",&producto1);
             }

             printf("\n El precio del producto %d es de : %f dolares \n", producto1, precio[producto1]);
             printf("\n \n");
             printf("\n Las ventas llevadas a cabo hasta el momento fueron: %d \n", contador_ventas);
             printf("\n \n");
             monto_total_ventas(dia,cantidadp);
                for(int i = 0; i < 10; i++){
                    printf("\n El stock para el producto %d es : %f productos \n", i +1, stock[i]);
                }


        break;
     case 5:
             system("cls");
             printf("\n Que dia usted esta eliminando la venta ? entre 0 y 9 \n");
             scanf("%d",&dia);
                while((dia < 0)||(dia > 9)){
                    system("cls");
                    printf("\n ---Error - ingrese un valor entre 0 y 9 ---\n");
                    scanf("%d",&dia);
                 }


             printf("\n - Seleccione un producto para eliminar su venta - \n");
             scanf("%d",&producto1);

            while((producto1 < 0)||(producto1 > 9)){
                system("cls");
                printf("\n ---Error - ingrese un valor entre 0 y 9 ---\n");
                scanf("%d",&producto1);
             }

             printf("\n \n");
             Matriz[dia][producto1] = 0;
             printf("\n \n");


        break;
     case 6:
             system("cls");
             printf("\n--- El programa finalizo correctamente ---\n");



        break;
         }

    }

return 0;}
