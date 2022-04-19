#include <iostream>
#include <string>
using namespace std;

int total ;

int suma_dos(int xval , int yval){
    return xval + yval;
}

float d ;

float dividir_dos(int x,int y){
    d = x/y;
    return d;
} 


int main(void){
    cout << 10/6 <<  "\n";
    cout << suma_dos(10,20) << "\n";
    cout << dividir_dos(10,6) << "--" ;



}