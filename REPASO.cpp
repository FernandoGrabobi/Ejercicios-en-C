#include <stdio.h>
#include <stdlib.h>
int main (void){
float tempMin=100, temp=0;
int op=0,continuar=0;
do {
	printf("OPCION 1- INGRESE VALORES DE LA TEMPERATURA BAJO CERO \n");
	printf("OPCION 2- INGRESE VALORES DE LA TEMPERATURA SOBRE DE CERO \n");
	printf("OPCION 3- INGRESE VALORES DE LA SOBRE Y BAJO CERO \n");
	scanf ("%d", &op);
	switch (op) {
			case 1: 
					do {
						printf ("porfavor ingrese los valores de temperatura bajo cero \n");
						scanf ("%f", &temp);
					}
					while (temp>0);	
											
						if (temp< tempMin) {
							tempMin= temp;										
						}
					break;
			case 2: do {
						printf ("porfavor ingrese los valores de temperatura sobre cero \n");
						scanf ("%f", &temp);
						printf ("%.2f\n", temp);
					}
					while (temp<0);	
											
						if (temp< tempMin) {
							tempMin= temp;										
						}			
					break;
			case 3: 
						printf ("porfavor ingrese los valores de temperatura sobre y bajo cero \n");
						scanf ("%f", &temp);
						printf ("%.2f\n", temp);
											
						if (temp< tempMin) {
							tempMin= temp;										
						}			
					break;		
	
	}
	printf ("el valor minimo de la temperatura es %.2f \n", tempMin);	
		
		printf ("para continuar presione 1 \n");
		scanf (" %d", &continuar);
		printf ("%d \n", continuar);
		system ("cls");
}

while (continuar==1);
	return 0;
	
}
