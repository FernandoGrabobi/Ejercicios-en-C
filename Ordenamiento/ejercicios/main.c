#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <stdbool.h>

typedef struct{

int orden;
char titulo[40];
char autor[40];
char editorial[40];
int clase;
int numero;
int publicacion;
} libros;

int buscar(libros lib[],char nombre[],int cant, int *puntero){
int i, n;
char comparar;
for (i=0;i<cant;i++) {
	system("cls");
	if(strcmp(lib[i].titulo,nombre)==0){
		printf("\nEl libro es el siguiente: \nNombre: %s\n",lib[i].titulo);
		printf("AUTOR: ");
		puts(lib[i].autor);
		printf("EDITORIAL: ");
		puts(lib[i].editorial);

		*puntero = i;
		return i;
	}
	else{
        printf("El libro no se encuentra\n");
		*puntero =-1;
		return -1;
	}
}
}




int main()
{

libros lib[10];
int i=0,menu,j;
char nombre[40];

do{

    printf("ingrese 1 si desea cargar un libro o revista\nIngrese 2 si desea buscar un libro o revista\n");
    scanf("%d",&menu);
    fflush(stdin);

    switch(menu)
    {


case 1:
    {


printf("ingrese el numero del libro o revista\n");
scanf("%d",&lib[i].orden);
fflush(stdin);

printf("ingrese el TITULO del libro o revista\n");
gets(lib[i].titulo);

printf("ingrese el NOMBRE DEL AUTOR del libro o revista\n");
gets(lib[i].autor);

printf("ingrese el NOMBRE DE LA EDITORIAL del libro o revista\n");
gets(lib[i].editorial);


i=i+1;

printf("ingrese\n1 si es un LIBRO\n2 si es una REVISTA\n");
scanf("%d",&lib[i].clase);

while (lib[i].clase<1 || lib[i].clase>2)
{
   printf("NUMERO INCORRECTO\n");
    scanf("%d",&lib[i].clase);
}



if (lib[i].clase==1)
{
    printf("ingrese el NUMERO DE EDICION del libro\n");
    scanf("%d",&lib[i].numero);


    printf("ingrese LA FECHA DE PUBLICACION del libro\n");
    scanf("%d",&lib[i].publicacion);
    fflush(stdin);


    printf("LIBRO INGRESADA CORRECTAMENTE\n");

}
else
{
    printf("REVISTA INGRESADA CORRECTAMENTE\n");
}
break;
    }

case 2:
    {
        if (i>0)
        {

            printf("Ingrese el nombre del libro que desea buscar:\n");
            gets(nombre);
            buscar(lib,nombre,i,&j);
        }
        else{
            printf("no hay libros o revistas cargadas\n");

        }
        system("pause");
        system("cls");
        break;
    }


    }






}
while(menu!=0);





    return 0;
}
