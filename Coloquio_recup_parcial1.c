#include <stdio.h>
#include <stdlib.h>

int granja[3][4], ingreso_planta, cambio_saplin, cambio_mama, cambio_plant, cambiaso;
float dolar_actual, pvu, monto_total;

void Inicializar(){
    ingreso_planta = 0;
    cambio_saplin = 0;
    cambio_mama = 0;
    cambio_plant = 0;
    dolar_actual = 0;

    for(int f = 0; f < 3; f++){
            for(int c = 0; c < 4; c++){
                granja[f][c]=0;
        }
    }

}

float monto(float PVU){
monto_total = ((PVU * 11.7)*dolar_actual);
return monto_total;
}

int main(){

Inicializar();

int menu, opcion_cambio;
menu = 0;
opcion_cambio = 0;
dolar_actual = 0;

    while(menu != 6 ){

    printf("\n---Opcion 1 para CARGAR PLANTAS SAPLIN ---\n");
    printf("\n");
    printf("\n---Opcion 2 para REALIZAR EL CAMBIO de 4 SAPLIN por 1 MAMA (la mama reemplazara un lugar que ocupaba alguna de las planta saplin y se eliminaran las 3 restantes). \n");
    printf("\n");
    printf("\n---Opcion 3 para REALIZAR EL CAMBIO de 2 MAMA por 1 PLANT (la plant reemplazara un lugar que ocupaba alguna de las plantas mama y se eliminara la restante)---\n");
    printf("\n");
    printf("\n---Opcion 4 SHOW_P, VIZUALIZAR LA GRANJA------\n");
    printf("\n");
    printf("\n---Opcion 5 para CALCULAR EN PESOS LA RECOMPENSA OBTENIDA ---\n");
    printf("\n");
    printf("\n---Opcion 6 para FINALIZAR EL PROGRAMA ---\n");
    scanf("%d",&menu);

    /*Control de errores menu*/
    while((menu > 6)||(menu < 0)){
    system("cls");
    printf("\n");
    printf("---ERROR---\n");
    printf("\n---Opcion 1 para CARGAR (de forma continua) plantas SAPLIN hasta que se ingrese el valor 0---\n");
    printf("\n");
    printf("\n---Opcion 2 para REALIZAR CAMBIO de 4 SAPLIN por 1 MAMA (la mama reemplazara un lugar que ocupaba la planta saplin y se eliminaran las 3 restantes). \n");
    printf("\n");
    printf("\n---Opcion 3 para REALIZAR EL CAMBIO de 2 MAMA por 1 PLANT (la plant reemplazara un lugar que ocupaba alguna de las plantas mama y se eliminara la restante)---\n");
    printf("\n");
    printf("\n---Opcion 4 SHOW_P, VIZUALIZAR LA GRANJA------\n");
    printf("\n");
    printf("\n---Opcion 5 para CALCULAR EN PESOS LA RECOMPENSA OBTENIDA ---\n");
    printf("\n");
    printf("\n---Opcion 6 para FINALIZAR EL PROGRAMA ---\n");
    scanf("%d",&menu);
    }
    /*fin Control de errores menu*/

        switch(menu){
            case 1:
            system("cls");
            printf("\n--- A seleccionado la opcion 1 ---\n");
            printf("\n Debera Ingresar (de forma continua) que planta ocupara cada espacio en la granja(hasta que se ingrese el valor 0). \n");
            printf("\n \n");
            for(int f = 0; f < 3; f++){
                for(int c = 0; c < 4; c++){
                    if(granja[f][c]==0){
                     printf("\n Ingrese 1 para SAPLIN, 0 para ninguna planta y salir de la opcion \n");
                     scanf("%d",&ingreso_planta);
                     while((ingreso_planta< 0)||(ingreso_planta > 1)){
                        system("cls");
                        printf("\n --- ERROR, el valor ingresado no esta dentro de los parametros aceptados ---\n");
                        printf("\n Ingrese 1 para SAPLIN, 0 para ninguna planta y salir de la opcion \n");
                        scanf("%d",&ingreso_planta);
                     }

                     granja[f][c]=ingreso_planta;
                     if(ingreso_planta == 1){
                     cambio_saplin = cambio_saplin + 1;
                     }
                     if(ingreso_planta == 0){
                        f = 10;
                        c = 10;
                        printf("\n ___se finalizo la carga de SAPLIN ___ \n"); }
                      
                     }
                }
            }
            for(int f = 0; f < 3; f++){
                printf("\n");
                for(int c = 0; c < 4; c++){
                    printf(" %d \t", granja[f][c]);
                }
            }
             printf("\n \n");

            break;
            case 2:
            cambiaso = 0;
            system("cls");
            printf("\n ___A seleccionado la opcion 2 ___  \n");
            if(cambio_saplin >= 4){
                 printf("\n ___Desea Realizar el cambio de 4 saplin por 1 mama? 1 para si, 0 para no. ___  \n");
                 scanf("%d",&opcion_cambio);
                  while((opcion_cambio< 0)||(opcion_cambio > 1)){
                        system("cls");
                        printf("\n --- ERROR, el valor ingresado no esta dentro de los parametros aceptados ---\n");
                        printf("\n ___Desea Realizar el cambio de 4 saplin por 1 mama? 1 para si, 0 para no. ___  \n");
                        scanf("%d",&opcion_cambio);
                     }

                if(opcion_cambio == 1){
                    printf("\n Selecciono seguir adelante con el cambio \n");

                    for(int f = 0; f < 3; f++){
                        for(int c = 0; c < 4; c++){
                            if((granja[f][c])== 1){
                                    granja[f][c] = 3;
                                    f = 100;
                                    c = 100;
                            }
                        }
                    }

                        for(int f = 0; f < 3; f++){
                            for(int c= 0; c < 4; c++){
                                if((granja[f][c])== 1){
                                    granja[f][c] = 0;
                                    cambiaso = cambiaso+1;
                                    if(cambiaso >= 3){
                                        f = 100;
                                        c = 100;
                                    }

                                }
                            }
                        }


                    cambio_saplin = cambio_saplin - 4;
                    cambio_mama = cambio_mama + 1;
                    printf("\n ___El cambio se realizo Correctamente, 4 Saplin por 1 MAMA___ \n");

                }else{
                    printf("\n ___Usted no desea realizar el cambio___ \n");
                }

            }else{
                 printf("\n No cumple los requisitos necesarios para cambiar de SAPLIN a MAMA. Necesita como minimo 4 SAPLIN para 1 MAMA. \n");
            }


            break;
            case 3:
            cambiaso = 0;
            system("cls");
            printf("\n ___A seleccionado la opcion 3 ___ \n");
             if(cambio_mama >= 2){
                 printf("\n ___Desea Realizar el cambio de 2 MAMA por 1 PLANT? 1 para si, 0 para no. ___  \n");
                 scanf("%d",&opcion_cambio);
                  while((opcion_cambio< 0)||(opcion_cambio > 1)){
                        system("cls");
                        printf("\n --- ERROR, el valor ingresado no esta dentro de los parametros aceptados ---\n");
                        printf("\n ___Desea Realizar el cambio de 2 MAMA por 1 PLANT? 1 para si, 0 para no. ___  \n");
                        scanf("%d",&opcion_cambio);
                     }

                  if(opcion_cambio == 1){
                    printf("\n Selecciono seguir adelante con el cambio \n");

                    for(int f=0; f < 3; f++){
                        for(int c=0; c < 4; c++){
                            if(granja[f][c]== 3){
                                    granja[f][c] = 7;
                                    f = 100;
                                    c = 100;

                            }
                        }
                    }
                        for(int f=0; f < 3; f++){
                            for(int c=0; c < 4; c++){
                                if(granja[f][c]== 3){
                                    granja[f][c] = 0;
                                    cambiaso = cambiaso+1;
                                    if(cambiaso >= 1){
                                        f = 100;
                                        c = 100;
                                    }
                                }
                            }
                         }



                    cambio_mama = cambio_mama - 2;
                    cambio_plant = cambio_plant + 1;
                    printf("\n ___El cambio se realizo Correctamente, 2 MAMA por 1 PLANT___ \n");

                }else{
                    printf("\n ___Usted no desea realizar el cambio___ \n");
                }


            }else{
                 printf("\n No cumple los requisitos necesarios para cambiar de MAMA a PLANT. Necesita como minimo 2 MAMA para 1 PLANT. \n");
            }



            break;
            case 4:
            system("cls");
            printf("\n___ A Seleccionado la opcion 4 ___\n");
            printf("\n -- Esta opcion permite vizualizar el estado de la granja --\n_ 1 si en el espacio se encuentra una planta SAPLIN \n_ 3 si se encuentra una planta MAMA \n_ 7 si se encuentra una planta PLANT \n_ 0 para un espacio vacio sin plantas ");
            printf("\n \n");

                for(int f = 0; f < 3; f++){
                        printf("\n");
                    for(int c = 0; c < 4; c++){
                       
                        printf(" %d \t", granja[f][c]);
                    }
                }

            if((cambio_mama >= 2)&&(cambio_plant >= 1)){
                printf("\n \n");
                printf("\n____ La granja esta balanceada ____\n");
            }else{
            printf("\n \n");
            printf("\n ___ La granja aun no esta balanceada ___ \n");
            }

            break;
             case 5:
             
            system("cls");
            printf("\n___ A seleccionado la opcion 5 ___ \n");
            printf("\n Ingrese Cuanto vale el Dolar actual en pesos (entre 1 y 1000 pesos): \n");
            scanf("%f",&dolar_actual);
            while((dolar_actual < 1)||(dolar_actual > 1000)){
            printf("\n___ ERROR, valor ingresado fuera de rango ___ \n");
            printf("\n Ingrese Cuanto vale el Dolar actual en pesos (entre 1 y 1000 pesos): \n");
            scanf("%f",&dolar_actual);

            }
            pvu = ((cambio_saplin * 3)+(cambio_mama * 5)+(cambio_plant=(cambio_saplin*3)+(2*cambio_saplin)));
            monto(pvu);
            printf("EL MONTO TOTAL EN PESOS ES: %.2f \n", monto(pvu));

            break;
             case 6:
            system("cls");
            printf("\n ---- (: El programa finalizo correctamente :) ---- \n");
            break;
            default:
            printf("\n ---Opcion incorrecta---\n");
            break;
        }

    }
return 0;
}
