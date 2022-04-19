#include<stdio.h>
#include<stdlib.h>
#include <math.h>

int perimetro(int x){
int y = x + x + x + x;
return y;
}

float superficie(int x){
int y = (x * x);
return y;
}

int main(){
int base_cuadrado, base_rombo, z1, z2;
float p1, p2;

printf("\n ingrese la base del cuadrado\n");
scanf("%d",&base_cuadrado);
printf("\n");
printf("\n ingrese la base del rombo\n");
scanf("%d",&base_rombo);
printf("\n");
z1 = perimetro(base_cuadrado);
z2 = perimetro(base_rombo);
p1 = superficie(base_cuadrado);
p2 = superficie(base_rombo);
printf("El perimetro del cuadrado es: %d \n", z1);
printf("\n");
printf("El perimetro del rombo es: %d \n", z2);
printf("\n");
printf("la superficie del cuadrado es: %f \n", p1);
printf("\n");
printf("la superficie del rombo es: %f \n", p2);
printf("\n");

}
