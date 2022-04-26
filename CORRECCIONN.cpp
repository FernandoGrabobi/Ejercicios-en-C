#include <stdio.h>
int main (void){
	int cantidadP=0,producto=0,x=0, acumCantidad=0, cuota;
	float precioP=0,precioTotal=0,precioDesc=0,acumPrecio=0; /*Por si el precio fuera con coma*/
	printf("-------------------------------------------------------------\n");
	printf ("\n\tOpcion 1 - Leche $50.00\n"); /*El menu de productos del supermercado*/
	printf ("\tOpcion 2 - Pan $70.00\n");
	printf ("\tOpcion 3 - Azucar $35.00\n");
	printf ("\tOpcion 4 - Asado que debe el profe $1000.00\n");
	printf ("\tOpcion 5 - Pagar al contado \n");
	printf ("\tOpcion 6 - Pagar en cuotas\n");
	printf ("\tOpcion 7 - Salir\n\n");
	printf("-------------------------------------------------------------\n\n");
	
	printf ("Elija el producto a comprar \n");
	printf("OPCION N: ");
	scanf ("%d", &producto);
	printf("\n");
	
	while(producto<1 || producto>7){ /*Para que se ingrese un valor dentro de las opciones disponibles*/
		printf("-------------------------------------------------------------\n\n");
		printf ("\nIngreso un valor incorrecto, intentalo nuevamente\n");
		printf("\n\n-------------------------------------------------------------\n");
		printf("-------------------------------------------------------------\n");
		printf ("\n\tOpcion 1 - Leche $50.00\n"); /*El menu de productos del supermercado*/
		printf ("\tOpcion 2 - Pan $70.00\n");
		printf ("\tOpcion 3 - Azucar $35.00\n");
		printf ("\tOpcion 4 - Asado que debe el profe $1000.00\n");
		printf ("\tOpcion 5 - Pagar al contado \n");
		printf ("\tOpcion 6 - Pagar en cuotas\n");
		printf ("\tOpcion 7 - Salir\n\n");
		printf("-------------------------------------------------------------\n\n");
		
		printf ("Ingrese una opcion entre 1 a 7\n");
		printf("OPCION N: ");
		scanf ("%d", &producto);
	}
	
	while (producto<=7){
		
		if(producto==7){/*Esta opcion la usamos para salir del bucle si la opcion ingresada es siete*/
				printf("\n-------------------------------------------------------------\n");
				printf("\nUsted ha salido del programa, el total de su cuenta es el siguiente\n");
				printf("\nSe compro un total de %d Productos\n", acumCantidad); /*muestra la cantidad acumulada del producto*/
				printf("El monto total sin descuento es: %.2f\n",acumPrecio); /*muestra el monto acumulado del precio*/
				printf("El descuento total es: %.2f\n",precioDesc); /*muestra el precio de descuento*/
				printf("El precio final con descuento es: %.2f\n\n",acumPrecio-precioDesc);
				printf("\n-------------------------------------------------------------\n");
			break; /*interrucion de la ejecucion del bucle*/
		}
		
		switch (producto){
			case 1:
				while (x==0){
					if (acumCantidad>0){
						/*Muestra por pantalla la cantidad de productos agregados hasta el momento y el total sin descuento*/
						printf("\n-------------------------------------------------------------\n");
						printf ("\n\tSu carrito tiene %d Productos\n", acumCantidad);
						printf ("\tEl total sin descuento es: %.2f\n ", acumPrecio);
						printf("\n-------------------------------------------------------------\n");
					}
					
					precioP= 50;
					printf ("\nIngrese la cantidad del producto a comprar\n");
					printf("CANTIDAD: ");
					scanf ("%d", &cantidadP);
					while(cantidadP<0){
						printf("\n La cantidad no puede ser menor a cero\n");
						printf("Intentalo Nuevamenten");
						printf("CANTIDAD: ");
						scanf ("%d", &cantidadP);
					}
					precioTotal= (precioP*cantidadP);
					acumPrecio=acumPrecio+precioTotal;
					/*Se calcula el descuento del total de productos agregados hasta el momento*/
					if(precioTotal>=200){
						precioDesc= (acumPrecio*0.15);
					}
					
					if((precioTotal>100) && (precioTotal<200)){
						precioDesc=  (acumPrecio*0.12);
					}
					
					if(precioTotal<=100){
						precioDesc=(acumPrecio *0.10);
					}
					acumCantidad = acumCantidad + cantidadP;/*calcula la cantidad total de productos que se van agregando al carrito*/
					
					printf ("\nEl precio real del producto es %.2f x %d Unidades: %.2f \n",precioP, cantidadP,precioP*cantidadP);
					printf("Su carrito tiene %d productos \n",acumCantidad);
					printf("El descuento aplicado para la cantidad actual es %.2f\n",precioDesc);
					printf("El monto actual a pagar es %.2f\n",acumPrecio-precioDesc);
					
					
					if(cantidadP>=0){
						printf("\nOpcion 0 - Continuar agregando mas unidades de este producto\n");
						printf("Opcion 1- Numero distinto de 0 - Comprar otros productos\n");
						printf("OPCION N: ");
						scanf("%d", &x);
					}
				}
			break;
			
		case 2:
			while (x==0){
				if (acumCantidad>0){
					/*Muestra por pantalla la cantidad de productos agregados hasta el momento y el total sin descuento*/
					printf("\n-------------------------------------------------------------\n");
					printf ("\n\tSu carrito tiene %d Productos\n", acumCantidad);
					printf ("\tEl total sin descuento es: %.2f\n ", acumPrecio);
					printf("\n-------------------------------------------------------------\n");
				}
					
				precioP= 70;
				printf ("\nIngrese la cantidad del producto a comprar\n");
				printf("CANTIDAD: ");
				scanf ("%d", &cantidadP);
				while(cantidadP<0){
					printf("\n La cantidad no puede ser menor a cero\n");
					printf("Intentalo Nuevamenten");
					printf("CANTIDAD: ");
					scanf ("%d", &cantidadP);
				}
				precioTotal= (precioP*cantidadP);
				acumPrecio=acumPrecio+precioTotal;
				/*Se calcula el descuento del total de productos agregados hasta el momento*/	
				if(precioTotal>=200){
					precioDesc= (acumPrecio*0.15);
				}
					
				if((precioTotal>100) && (precioTotal<200)){
					precioDesc=  (acumPrecio*0.12);
				}
					
				if(precioTotal<=100){
					precioDesc=(acumPrecio *0.10);
				}
				acumCantidad = acumCantidad + cantidadP;
					
				printf ("\nEl precio real del producto es %.2f x %d Unidades: %.2f \n",precioP, cantidadP,precioP*cantidadP);
				printf("Su carrito tiene %d productos \n",acumCantidad);
				printf("El descuento aplicado para la cantidad actual es %.2f\n",precioDesc);
				printf("El monto actual a pagar es %.2f\n",acumPrecio-precioDesc);	
								
				if(cantidadP>=0){
					printf("\nOpcion 0 - Continuar agregando mas unidades de este producto\n");
					printf("Opcion 1- Numero distinto de 0 - Comprar otros productos\n");
					printf("OPCION N: ");
					scanf("%d", &x);
				}
			}
		break;
		
		case 3:
			while (x==0){
				if (acumCantidad>0){
					/*Muestra por pantalla la cantidad de productos agregados hasta el momento y el total sin descuento*/
					printf("\n-------------------------------------------------------------\n");
					printf ("\n\tSu carrito tiene %d Productos\n", acumCantidad);
					printf ("\tEl total sin descuento es: %.2f\n ", acumPrecio);
					printf("\n-------------------------------------------------------------\n");
				}
					
				precioP= 35;
				printf ("\nIngrese la cantidad del producto a comprar\n");
				printf("CANTIDAD: ");
				scanf ("%d", &cantidadP);
				while(cantidadP<0){
					printf("\n La cantidad no puede ser menor a cero\n");
					printf("Intentalo Nuevamenten");
					printf("CANTIDAD: ");
					scanf ("%d", &cantidadP);
				}
				precioTotal= (precioP*cantidadP);
				acumPrecio=acumPrecio+precioTotal;
				/*Se calcula el descuento del total de productos agregados hasta el momento*/	
				if(precioTotal>=200){
					precioDesc= (acumPrecio*0.15);
				}
					
				if((precioTotal>100) && (precioTotal<200)){
					precioDesc=  (acumPrecio*0.12);
				}
					
				if(precioTotal<=100){
					precioDesc=(acumPrecio *0.10);
				}
				acumCantidad = acumCantidad + cantidadP;
					
				printf ("\nEl precio real del producto es %.2f x %d Unidades: %.2f \n",precioP, cantidadP,precioP*cantidadP);
				printf("Su carrito tiene %d productos \n",acumCantidad);
				printf("El descuento aplicado para la cantidad actual es %.2f\n",precioDesc);
				printf("El monto actual a pagar es %.2f\n",acumPrecio-precioDesc);	
					
				if(cantidadP>=0){
					printf("\nOpcion 0 - Continuar agregando mas unidades de este producto\n");
					printf("Opcion 1- Numero distinto de 0 - Comprar otros productos\n");
					printf("OPCION N: ");
					scanf("%d", &x);
				}
			}
		break;
		
		case 4:
			while (x==0){
				if (acumCantidad>0){
					/*Muestra por pantalla la cantidad de productos agregados hasta el momento y el total sin descuento*/
					printf("\n-------------------------------------------------------------\n");
					printf ("\n\tSu carrito tiene %d Productos\n", acumCantidad);
					printf ("\tEl total sin descuento es: %.2f\n ", acumPrecio);
					printf("\n-------------------------------------------------------------\n");
				}
					
				precioP= 1000;
				printf ("\nIngrese la cantidad del producto a comprar\n");
				printf("CANTIDAD: ");
				scanf ("%d", &cantidadP);
				while(cantidadP<0){
					printf("\n La cantidad no puede ser menor a cero\n");
					printf("Intentalo Nuevamenten");
					printf("CANTIDAD: ");
					scanf ("%d", &cantidadP);
				}
				precioTotal= (precioP*cantidadP);
				acumPrecio=acumPrecio+precioTotal;
				/*Se calcula el descuento del total de productos agregados hasta el momento*/	
				if(precioTotal>=200){
					precioDesc= (acumPrecio*0.15);
				}
					
				if((precioTotal>100) && (precioTotal<200)){
					precioDesc=  (acumPrecio*0.12);
				}
					
				if(precioTotal<=100){
					precioDesc=(acumPrecio *0.10);
				}
				acumCantidad = acumCantidad + cantidadP;
					
				printf ("\nEl precio real del producto es %.2f x %d Unidades: %.2f \n",precioP, cantidadP,precioP*cantidadP);
				printf("Su carrito tiene %d productos \n",acumCantidad);
				printf("El descuento aplicado para la cantidad actual es %.2f\n",precioDesc);
				printf("El monto actual a pagar es %.2f\n",acumPrecio-precioDesc);
					
				if(cantidadP>=0){
					printf("\nOpcion 0 - Continuar agregando mas unidades de este producto\n");
					printf("Opcion 1- Numero distinto de 0 - Comprar otros productos\n");
					printf("OPCION N: ");
					scanf("%d", &x);
				}
			}
		break;
		
		case 5:
			/*Muestra por pantalla los resultados de la compra con todos los productos añadidos al carrito hasta el momento*/
				printf("\n-------------------------------------------------------------\n");
				printf("\nSe compro un total de %d Productos\n", acumCantidad);
				printf("El monto total sin descuento es: %.2f\n",acumPrecio);
				printf("El descuento total es: %.2f\n",precioDesc);
				printf("El precio final con descuento es: %.2f\n",acumPrecio-precioDesc);
				printf("Usted ha pagado, se ha restablecido el carrito de compras\n\n");
				printf("\n-------------------------------------------------------------\n");
				acumCantidad=0;
				precioTotal=0,precioDesc=0,acumPrecio=0;
		break;
			case (6):
			printf("\n-------------------------------------------------------------\n");
			printf("\nIngrese la cantidad de cuotas a pagar\n");
			printf("OPCION 1: 3 Cuotas - Recargo del 10%\n");
			printf("OPCION 2: 6 Cuotas - Recargo del 30%\n");
			printf("OPCION 3: 12 Cuotas - Recargo del 50%\n");
			printf("OPCION: ");
			scanf("%d", &cuota);
			while(cuota<1 || cuota>3){
				printf("Usted ingreso una opcion incorrecta, las opciones disponibles son las siguientes\n");
				printf("OPCION 1: 3 Cuotas - Recargo del 10%\n");
				printf("OPCION 2: 6 Cuotas - Recargo del 30%\n");
				printf("OPCION 3: 12 Cuotas - Recargo del 50%\n");
				printf("OPCION: ");
				scanf("%d", &cuota);
			}
			if(cuota==1){
				printf("\n-------------------------------------------------------------\n\n");
				printf("\nSe compro un total de %d Productos\n", acumCantidad);
				printf("El monto total sin descuento es: %.2f\n",acumPrecio);
				printf("El descuento total es: %.2f\n",precioDesc);
				printf("El precio con descuento es: %.2f\n",acumPrecio-precioDesc);
				printf("La cantidad de cuotas a pagar es 3 x %.2f\n", ((acumPrecio-precioDesc)+((acumPrecio-precioDesc)*0.10))/3); /*cantidad de cuotas a pagar*/
				printf("El precio final con recargo en 3 cuotas es: %.2f\n",(acumPrecio-precioDesc)+((acumPrecio-precioDesc)*0.10)); /*cuotas con recargo al precio con descuentos */
				printf("Usted ha finalizado la compra, se ha restablecido el carrito de compras\n\n");
				printf("\n-------------------------------------------------------------\n");
				acumCantidad=0;
				precioTotal=0,precioDesc=0,acumPrecio=0;
			}
			if(cuota==2){
				printf("\n-------------------------------------------------------------\n\n");
				printf("\nSe compro un total de %d Productos\n", acumCantidad);
				printf("El monto total sin descuento es: %.2f\n",acumPrecio);
				printf("El descuento total es: %.2f\n",precioDesc);
				printf("El precio con descuento es: %.2f\n",acumPrecio-precioDesc);
				printf("La cantidad de cuotas a pagar es 6 x %.2f\n", ((acumPrecio-precioDesc)+((acumPrecio-precioDesc)*0.30))/6);
				printf("El precio final con recargo en 6 cuotas es: %.2f\n",(acumPrecio-precioDesc)+((acumPrecio-precioDesc)*0.30));
				printf("Usted ha finalizado la compra, se ha restablecido el carrito de compras\n\n");
				printf("\n-------------------------------------------------------------\n");
				acumCantidad=0;
				precioTotal=0,precioDesc=0,acumPrecio=0;
			}
			if(cuota==3){
				printf("\n-------------------------------------------------------------\n\n");
				printf("\nSe compro un total de %d Productos\n", acumCantidad);
				printf("El monto total sin descuento es: %.2f\n",acumPrecio);
				printf("El descuento total es: %.2f\n",precioDesc);
				printf("El precio con descuento es: %.2f\n",acumPrecio-precioDesc);
				printf("La cantidad de cuotas a pagar es 12 x %.2f\n", ((acumPrecio-precioDesc)+((acumPrecio-precioDesc)*0.50))/12);
				printf("El precio final con recargo en 12 cuotas es: %.2f\n",(acumPrecio-precioDesc)+((acumPrecio-precioDesc)*0.50));
				printf("Usted ha finalizado la compra, se ha restablecido el carrito de compras\n\n");
				printf("\n-------------------------------------------------------------\n");
				acumCantidad=0;
				precioTotal=0,precioDesc=0,acumPrecio=0;
			}
			printf("\n-------------------------------------------------------------\n");
		
		}
		/*Repite el MENU en caso de que se quiera comprar otro producto distinto*/
		printf("-------------------------------------------------------------\n");
		printf ("\n\tOpcion 1 - Leche $50.00\n"); /*El menu de productos del supermercado*/
		printf ("\tOpcion 2 - Pan $70.00\n");
		printf ("\tOpcion 3 - Azucar $35.00\n");
		printf ("\tOpcion 4 - Asado que debe el profe $1000.00\n");
		printf ("\tOpcion 5 - Pagar al contado\n");
		printf ("\tOpcion 6 - Pagar en cuotas\n");
		printf ("\tOpcion 7 - Salir\n\n");
		printf("-------------------------------------------------------------\n\n");
		
		printf ("Elija el producto a comprar \n");
		printf("OPCION N: ");
		scanf ("%d", &producto);
		printf("\n");
		
		while(producto<1 || producto>6){ /*Para que se ingrese un valor dentro de las opciones disponibles*/
			printf("-------------------------------------------------------------\n\n");
			printf ("\nIngreso un valor incorrecto, intentalo nuevamente\n");
			printf("\n\n-------------------------------------------------------------\n");
			printf("-------------------------------------------------------------\n");
			printf ("\n\tOpcion 1 - Leche $50.00\n"); //El menu de productos del supermercado
			printf ("\tOpcion 2 - Pan $70.00\n");
			printf ("\tOpcion 3 - Azucar $35.00\n");
			printf ("\tOpcion 4 - Asado que debe el profe $1000.00\n");
			printf ("\tOpcion 5 - Pagar al contado \n");
	        printf ("\tOpcion 6 - Pagar en cuotas\n");
	        printf ("\tOpcion 7 - Salir\n\n");
			printf("-------------------------------------------------------------\n\n");
			
			printf ("Ingrese una opcion entre 1 a 7\n");
			printf("OPCION N: ");
			scanf ("%d", &producto);
		}
		x=0;
	}
		

}
