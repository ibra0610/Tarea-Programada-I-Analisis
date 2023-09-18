#include <iostream> 
#include "Ordenador.h"  
#include <cstdlib> 
#include <ctime> 
#include <chrono>

int main(){ 

    srand(time(nullptr)); 

    int tamano = 200000; 
    int arreglo[tamano]; 

    for(int i=0; i<tamano; i++){ 
        arreglo[i] = rand() - RAND_MAX /2; 
    }

    Ordenador ordenador; 

    auto start_time = std::chrono::high_resolution_clock::now();

    ordenador.mergesort(arreglo, tamano); 

    auto end_time = std::chrono::high_resolution_clock::now(); 

    auto tiempoEjecucion = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

    std::cout<<tiempoEjecucion.count()<<std::endl; 

    for(int i=1; i<tamano; i++){
        if(arreglo[i] < arreglo[i-1]){
            std::cout<<"Failed!"; 
        }
    }

    return 0; 
}