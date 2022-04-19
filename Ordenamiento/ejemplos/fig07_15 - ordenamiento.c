#include <stdio.h>
#define TAMANIO 10

void intercambia( int *ptrElemento1, int *ptrElemento2 )
{
   int almacena = *ptrElemento1;
   *ptrElemento1 = *ptrElemento2;
   *ptrElemento2 = almacena;
} /* fin de la función intercambia */

void ordenamBurbuja( int *arreglo, int tamanio )
{
   //void intercambia( int *ptrElemento1, int *ptrElemento2 ); /* prototipo */
   int pasada; /* contador de pasadas */
   int j;    /* contador de comparaciones */

   /* ciclo para controlar las pasadas */
   for ( pasada = 0; pasada < tamanio - 1; pasada++ ) {

      /* ciclo para controla las comparaciones durante cada pasada */
      for ( j = 0; j < tamanio - 1; j++ ) {

         /* intercambia los elementos adyacentes si no están en orden */
         if ( arreglo[ j ] > arreglo[ j + 1 ] ) {
            intercambia( &arreglo[ j ], &arreglo[ j + 1 ] );
         } /* fin de if */

      } /* fin del for interno */

   } /* fin del for externo */

} /* fin de la función ordenamBurbuja */


int main()
{
   /* inicializa el arreglo a */
   int a[ TAMANIO ] = { 2, 6, 4, 8, 10, 12, 89, 68, 45, 37 };

   int i; /* contador */

   printf( "Elementos de datos en el orden original\n" );

   /* ciclo a través del arreglo a */
   for ( i = 0; i < TAMANIO; i++ ) {
      printf( "%4d", a[ i ] );
   } /* fin de for */

   ordenamBurbuja( a, TAMANIO ); /* ordena el arreglo */

   printf( "\nElementos de datos en orden ascendente\n" );

   /* ciclo a través del arreglo a */
   for ( i = 0; i < TAMANIO; i++ ) {
      printf( "%4d", a[ i ] );
   } /* fin de for */

   printf( "\n" );

   return 0; /* indica terminación exitosa */

} /* fin de main */

/* ordena un arreglo de enteros mediante el uso del algoritmo de la burbuja */

/* intercambia los valores en las ubicaciones de memoria a los cuales apunta ptrElemento1 y
   ptrElemento2 */



/**************************************************************************
 * (C) Copyright 1992-2004 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/

