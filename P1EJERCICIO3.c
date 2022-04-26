#include <stdio.h>

int main (void) {
	int cantExamen,x;
	float promedio,nota, notaMax, notaMin,acumNotas =0;
	
	printf ("Ingrese la cantidad de examenes que realizo durante el semestre\n");
	printf("Cantidad: ");
	scanf ("%d", &cantExamen);
	while (cantExamen<=0){ /* Para que ingrese valores mayores a 0*/
		printf ("La cantidad de examenes debe ser mayor a cero\n");
		printf("Intente ingresar la cantidad nuevamente\n");
		printf("Cantidad:");
		scanf ("%d", &cantExamen);
	}
	
	
	notaMin= 10; /*la nota minima tiene que ser mas vaja que la nota mas alta que se puede colocar, por eso la inicializamos en 10*/
	notaMax=1 ; /*El mismo caso de arriba pero a la inversa*/
	
	for (x=1; x <=cantExamen; x++) {
		printf ("Ingrese la nota de cada examen(una a la vez)\n");
		printf("Nota %d: ",x);/*Muestra el numero de la nota ingresada con el valor de X en el FOR*/
		scanf ("%f", &nota);
		
		while ((nota<1) || (nota>11)){ /*Limitamos el rango de las notas para que solo tome las notas entre 1 y 10*/
			printf ("La nota ingresada es incorrecta, ingrese una nota entre 1 y 10\n");
			printf("Nota %d: ",x);
			scanf ("%f", &nota);
		}
		
		acumNotas= acumNotas+ nota;/*Acumula las notas para luego realizar el promedio*/
		
		if (nota<=notaMin){
			notaMin= nota;/*calcula la nota minima, si es menor que la minima nota guardada la reemplaza*/
		}
		if (nota >notaMax){
			notaMax=nota;/*calcula la nota maxima, si es mayor que la maxima nota guardada la reemplaza*/
		}
	}

	promedio = acumNotas/cantExamen;/*Calculamos el promedio de las notas*/
	
								/*MOSTRAMOS POR PANTALLA LOS RESULTADOS OBTENIDOS*/
								
	printf ("\t El valor del promedio de las notas es: %.2f\n", promedio);
	if(promedio >= 6){
		printf("\t Usted aprobo el semestre, ¡FELICIDADES!\n");
	}else{
		printf("\t Usted no aprobo el semestre, ¡ESFUERZATE MEJOR!\n");
	}
	
	printf ("\t El valor de la nota maxima es: %.2f\n", notaMax);
	printf ("\t El valor de la nota minima es: %.2f\n", notaMin);
	
}
