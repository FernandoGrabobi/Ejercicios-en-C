/*Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>


	/*Inicio del programa*/
	int main ()
{
	setlocale(LC_ALL, "spanish");
	
	int i=0, j=0, kms=0, conRuta=0, sinRuta=0, ciudadOrigen=0, ciudadDestino=0, respuesta=1, opcion,info, col0 = 0,col1=0, col2=0, col3=0, col4=0, fil0=0, fil1=0, fil2=0, fil3=0, fil4=0;
	float rutaEntreCiudades[5][5];

	while (respuesta !=0)
	{
	
	for ( i = 0; i <5; i++)
		{
		for ( j=0; j <5; j++)
			{
			rutaEntreCiudades[i][j]=0;
		}
	}
	/*Cartelería de Bienvenida*/
		printf( "                                * * * BIENVENIDO * * * \n " );
		printf( "      |   Este sistema le permite calcular la distancia entre dos ciudades|\n " );
		printf( "      --------------------------------------------------------------------- \n" );
	
	do
		{
	    printf("INGRESE EL NOMBRE DE Origen\n");
        printf("CIUDAD ORIGEN:");
        scanf("%d", &ciudadOrigen);
        printf("INGRESE EL NOMBRE DE CIUDAD destino\n");
        printf("CIUDAD DESTINO:");
        scanf("%d", &ciudadDestino);
        printf("\n");
        printf("INGRESE LOS KMS DE DISTANCIA ENTRE LAS CIUDADES\n");
        printf("KMS:");
        scanf("%d", &kms);
    	rutaEntreCiudades[ciudadOrigen][ciudadDestino]= kms;
        
	for (i=0; i<5; i++)
		{
		for ( j=0; j <5; j++)
	        printf("%.f   ",  rutaEntreCiudades[i][j]);
            printf("\n");	
			
			if (rutaEntreCiudades [i][j] != 0)
				{
				conRuta = conRuta + 1;
			}	
			else
				{
				sinRuta = sinRuta + 1;
			}
		}
		printf("\n");
		printf("                                   ¿Desea cargar una nueva distancia?\n");
		printf("                                         0: NO    |    1: SI \n");
		printf("Opción: ");
		scanf("%d",&respuesta);
		system("cls");
	}
	while (respuesta ==1);	
		
		printf("\n");
		printf("                                ¿Desea consultar la información cargada? \n");
		printf("                                         0: NO    |    1: SI \n");
		printf("Opción: ");
		scanf("%d",&opcion);
	
		
		do
		{
		
		switch (opcion)
		{
			case 1:
				printf("1 - MOSTRAR INFORMACION DE LAS RUTAS CARGADAS\n");
    	      	printf("2 - CANTIDAD DE CIUDADES VINCULADAS POR UNA RUTA\n");
            	printf("3 - CANTIDAD DE CIUDADES SIN RUTA QUE LAS RELACIONE\n");
            	printf("4 - MOSTRAR LA DISTANCIA ENTRE DOS CIUDADES DESEADAS\n");
				scanf("%d",&info);
				system("cls");

				switch (info)
				{
				case 1:
					for (i=0; i<5; i++)
						{
							for ( j=0; j <5; j++)
	    					    printf("%.f   ",  rutaEntreCiudades[i][j]);
          						  printf("\n");	
					}
				break;
			
				case 2:		
				    col0 = 0;col1=0; col2=0; col3=0; col4=0;fil0=0; fil1=0; fil2=0; fil3=0; fil4=0;
                            //cantConRutas++;
                            // for(i=0; i<5; i++)                                 
                                  for(j=0; j <5; j++ )
                                  {
                                        if(rutaEntreCiudades[0][j] != 0)
                                              col0=1;
                                        if(rutaEntreCiudades[1][j] != 0)
                                              col1=1;
                                        if(rutaEntreCiudades[2][j] != 0)
                                              col2=1;
                                        if(rutaEntreCiudades[3][j] != 0)
                                              col3=1;
                                        if(rutaEntreCiudades[4][j] != 0)
                                              col4=1;
                                  }
                                  for(i=0; i <5; i++ )
                                  {
                                        if(rutaEntreCiudades[i][0] != 0)
                                              fil0=1;
                                        if(rutaEntreCiudades[i][1] != 0)
                                              fil1=1;
                                        if(rutaEntreCiudades[i][2] != 0)
                                              fil2=1;
                                        if(rutaEntreCiudades[i][3] != 0)
                                              fil3=1;
                                        if(rutaEntreCiudades[i][4] != 0)
                                              fil4=1;
                                  }
                                  conRuta = col0+col1+col2+col3+col4+fil0+fil1+fil2+fil3+fil4;
								printf("\nCANTIDAD DE CIUDADES CON RUTAS :%d \n", conRuta);			
				break;
			
				case 3:
					       col0 = 0;col1=0; col2=0; col3=0; col4=0;fil0=0; fil1=0; fil2=0; fil3=0; fil4=0;
                            //cantConRutas++;
                            // for(i=0; i<5; i++)                                 
                                  for(j=0; j <5; j++ )
                                  {
                                        if(rutaEntreCiudades[0][j] != 0)
                                              col0=1;
                                        if(rutaEntreCiudades[1][j] != 0)
                                              col1=1;
                                        if(rutaEntreCiudades[2][j] != 0)
                                              col2=1;
                                        if(rutaEntreCiudades[3][j] != 0)
                                              col3=1;
                                        if(rutaEntreCiudades[4][j] != 0)
                                              col4=1;
                                  }
                                  for(i=0; i <5; i++ )
                                  {
                                        if(rutaEntreCiudades[i][0] != 0)
                                              fil0=1;
                                        if(rutaEntreCiudades[i][1] != 0)
                                              fil1=1;
                                        if(rutaEntreCiudades[i][2] != 0)
                                              fil2=1;
                                        if(rutaEntreCiudades[i][3] != 0)
                                              fil3=1;
                                        if(rutaEntreCiudades[i][4] != 0)
                                              fil4=1;
                                  }
                                 	conRuta = col0+col1+col2+col3+col4+fil0+fil1+fil2+fil3+fil4;
									printf("\nCANTIDAD DE CIUDADES SIN RUTAS :%d \n", 10 - conRuta);		                           
				break;

				case 4:
		
					do
						{
							printf( "\n" );
							printf( "\n" );
							printf( "\n" );
							printf ( "Ingrese ciudad de ORIGEN: ");
							scanf("%d", &ciudadOrigen);
					}
					while (ciudadOrigen < 0 || ciudadOrigen > 4);
	
					do
						{
							printf( "\n" );
							printf ( "Ingrese ciudad de DESTINO: ");
							scanf("%d", &ciudadDestino);
					}	
					while ((ciudadDestino < 0 || ciudadDestino > 4) || ciudadDestino == ciudadOrigen);
		
					printf ("\n");
					printf ("\n");
					printf ("La distancia entre ciudad de ORIGEN %d y la ciudad de DESTINO %d es: %.2f km\n", ciudadOrigen, ciudadDestino, rutaEntreCiudades[ciudadOrigen][ciudadDestino]);

				break;

				default:
					{
				}
		 }
			break;

			case 0:
			break;
	}
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("                      ¿Repetir otra consulta?\n");
		printf("                      0: NO    |    1: SI \n");
		printf("\n");
		printf("Opción: ");
		scanf( "%d" , &respuesta );
}
while (respuesta != 0);

/*Opciones del sistema*/
	do
		{
		printf( "\n" );
		printf( "\n" );
		printf("1: Volver al inicio    |    0: Salir del sistema");
		printf("\n");
		printf("Opción: ");
		scanf( "%d" , &respuesta );
		printf( "      ---   EL VALOR INGRESADO NO ES VALIDO   ---\n" );
	}		
	while ( respuesta < 0 || respuesta >1 );	
	system("cls");
	
}
return 0;
}
