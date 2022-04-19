#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>

int main(void){

bool bucle_menu = true;
bool bucle_menu_error = false;
bool programa = true;
int menu;

do
{
   /*bucle menu*/
    while (bucle_menu == true)
    {
       if (bucle_menu_error == true)
       {
           printf("\n Error \n");
           bucle_menu_error = false;
       }
            printf("\n");
            printf("---Opcion 1---\n");
            printf("\n");
            printf("---Opcion 2---\n");
            printf("\n");
            printf("---Opcion 3---\n");
            printf("\n");
            scanf("%d",&menu);

        if (isdigit(menu )==0)
        {
            bucle_menu_error = true;

        }else{

            bucle_menu_error = false;

            /*si esta en lo correcto*/
            if ((menu > 0)&&(menu < 4))
            {
                bucle_menu = false;
                bucle_menu_error = false;
            }else{
                bucle_menu_error = true;
            }

        }
        
    }

            switch(menu){
                case 1:
                system("cls");
                printf("1\n");
                printf("\n");

                break;
                case 2:
                system("cls");
                printf("2\n");
                printf("\n");


                break;
                case 3:
                system("cls");
                printf("3\n");
                printf("\n");


                break;
            }


} while (programa == false);

return 0;
}