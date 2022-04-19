#include<stdio.h>
#include<stdlib.h>
#include <math.h>

float numero, resultado, n, z;

float cubo(float x, float y){

  float z = pow(x,y);

return z;

}

int main(){

 printf("\n Ingrese un numero: \n");
 scanf("%f",&numero);
 printf("\n Ingrese el exponente: \n");
 scanf("%f",&n);

 z = cubo(numero, n);
 printf("\n");
 printf("El cubo de %f es: %f", numero, z);

return 0;}
