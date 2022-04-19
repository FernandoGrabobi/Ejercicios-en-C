#include<stdio.h>
#include<stdlib.h>
#include <math.h>

int num1_par1, num2_par1, num1_par2, num2_par2, num1_par3, num2_par3, min1, min2, min3;

int menor(int x, int y){
    int min = x;

    if (y < min){
        y = min;
    }
    return min;
}

int main(){
printf("\n Ingrese un numero para comparar: \n");
scanf("%d",&num1_par1);
printf("\n Ingrese un numero para comparar: \n");
scanf("%d",&num2_par1);
printf("\n");
min1 = menor(num1_par1, num2_par1);
printf("El menor de estos numeros es: %d \n", min1);

printf("\n Ingrese un numero para comparar: \n");
scanf("%d",&num1_par2);
printf("\n Ingrese un numero para comparar: \n");
scanf("%d",&num2_par2);
printf("\n");
min2 = menor(num1_par2, num2_par2);
printf("El menor de estos numeros es: %d \n", min2);


printf("\n Ingrese un numero para comparar: \n");
scanf("%d",&num1_par3);
printf("\n Ingrese un numero para comparar: \n");
scanf("%d",&num2_par3);
printf("\n");
min3 = menor(num1_par3, num2_par3);
printf("El menor de estos numeros es: %d \n", min3);


return 0;}
