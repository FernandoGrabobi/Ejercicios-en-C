#include<stdio.h>
#include<stdlib.h>
#include <math.h>



int valor(float x){
    int y;
 if(x < 0){
     y = -1;
 }
 if(x > 0){
    y = 1;
 }
 if(x == 0){
    y = 0;
 }

 return y;
}

int main(){
float numeroR;
int z, menu1;
bool menu = true;

do{
printf("\n ingrese un numero real\n");
scanf("%f",&numeroR);
printf("\n");
z = valor(numeroR);
printf("La conversion es: %d \n", z);

printf("\n Desea continuar con el programa? mayor o igual a 0 si, menor a 0 no. \n");
scanf("%d",menu1);
    if(menu1 >= 0 ){
        menu = true;
    }
    if(menu1 <= 0){
        menu = false;
    }

}while(menu == false);

return 0;}
