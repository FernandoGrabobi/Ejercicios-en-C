#include <stdlib.h>
#include <math.h>
#include <stdio.h>

int main(){
	/*variables*/
float acum = 0;
int dia;
int i;
int max=-100;
float media;
float total;
int min=100;
int num1;
int num2;

/*operaciones*/

printf("introduce el numero de dias: \n");

scanf("%i",&dia);

/*ve si la cantidad introducida es menor que 0 entonce muestra un mensaje*/
/*pidiendo que vuelvas a introducirlo*/

while(dia<0)
{

printf("Introduce una cantidad de dias correcta: \n");

scanf("%i",&dia);

}

/*
pide el numero de veces que hallamos escrito anterior en el apartado dias*/

for(i=1;i<=dia;i++){

   printf("introduce la temperatura maxima: \n");
   
   scanf("%i",&num1);

   printf("introduce la temperatura minima: \n");
   
   scanf("%i",&num2);

   if(num1>max){
      max=num1;
   }

   if(num2<min){
      min=num2;
   }

 acum = acum + ((float)(num1+num2)/2);

}

/* La media total será la media parcial entre el número de días*/
total = (float)media/dia;

printf("La temperatura maxima es: %i\n",max);
printf("La temperatura minima es: %i\n",min);
printf("El total es: %.1f\n",total);
}



