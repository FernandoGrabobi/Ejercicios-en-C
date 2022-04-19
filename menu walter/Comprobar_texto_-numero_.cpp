#include <iostream>
#include <string>
#include <ctype.h>


using namespace std;

int main(void){


bool program = true;
bool bucle_menu = true;
bool error_op_invalido = false;
char midato;
int x;


do{

    ///bucle del menu
    while (bucle_menu == true){
            //bloque error
            if(error_op_invalido == true){
                system("cls");
                cout << "\n ERROR : OPCION INVALIDA \n";
                error_op_invalido = false;
            }


        ///MENU TEXTO
        cout << "\n ingrese 1 \n";
        cout << "\n ingrese 2 \n";
        cout << "\n --" ; 
        cin >> midato ; cout << "\n"; 


        //comprobamos si es letra
        if(isalpha(midato)){

            /// SI ES LETRA
            error_op_invalido = true;
        }else{

            /// NO ES LETRA
            error_op_invalido = false;
            /// SI NO ES LETRA ENTONCES ES NUMERO...
            /// SE COMPRUEBA SI ES UNA OPCION VALIDA YA QUE ES NUMERO....
            if(midato >=1 || midato <=2){
                bucle_menu = false;
            }else{
                error_op_invalido = true;
            }
            
        }
    }
    

    cout << "\n Lito perro \n" ;

    program = false;




    } while (program == true);

}