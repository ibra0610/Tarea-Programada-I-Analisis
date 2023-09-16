#include <iostream> 
#include "Ordenador.h" 

int main(){ 

    int tamano = 5; 
    int arreglo[tamano] = {-13, 26, -45, 78, 5}; 

    Ordenador ordenador; 

    ordenador.mergesort(arreglo, tamano); 

    for(int i=0; i<tamano; i++){ 
        std::cout<<arreglo[i]<<std::endl; 
    }
 

    return 0; 
}