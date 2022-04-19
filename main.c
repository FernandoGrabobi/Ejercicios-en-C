#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h> 

    void validarCadenaNumeros(char num[])
    {
        for (int i = 0; i < strlen(num); i++)
        {
            if(!isdigit(num[i]))
            {
                printf("Ingrese un numero valido \n");
                break;
            }
        }

    }
    int validarCadenaLetras(char cadena[])
    {
        int i = 0;
        while (cadena[i])
        {
            if (
            !isalpha(cadena[i])&& cadena[i] != ' '
            )
            return 0;
            i++;
        }
        return 1;
    }

int main(void)
{
    
     char cadena1[] = "Me gusta programar en C";

    if (validarCadenaLetras(cadena1))
    {
        printf("'%s' tiene unicamente del alfabeto\n",cadena1 );
    }
    else
    {
        printf("'%s' NO tiene unicamente letras del alfabeto\n",cadena1 );
    }

  char letra;
  printf("Escribe un caracter:\n");
  scanf("%c", &letra);
  if(isalpha(letra)) {
    printf("Es una letra");
  } else {
    printf("NO es una letra");
  }

    printf("Ingrese un numero \n");

    int a = getchar();

    if(isdigit(a)){ 
        printf("Es un numero");
    }else{
        puts("ERROR, No es un numero");
    }

    char a[256];
    scanf("%s", a);
    validarCadenaNumeros(a);
    printf("hacer otra cosa...");

    char mensaje_1="/";
    char mensaje_2="----\n";
  
    int max_menu=3;
    int min_menu=1;
  
    int n=2;
    
    float menu_1;
    int menu;

    while(n==2)
    {

        printf("\n:");
        scanf("%f",&menu_1);
        menu=(int)menu_1;
        while(menu<min_menu || menu>max_menu)
        {
            printf("----Valor fuera de rango----\n");
            printf("----El valor debe estar entre %d y %d ---- \n",min_menu ,max_menu);
            printf("----Volve a escribir el numero \n");
            scanf("%f",&menu_1);
            menu=(int)menu_1;

        }
        switch(menu)
        {

        case 1:
            printf("----1----\n");

            break;
        case 2:
            printf("----2----\n");

            break;
        case 3:
            printf("----3----\n");

            break;

        }

    }


    return 0;
}
