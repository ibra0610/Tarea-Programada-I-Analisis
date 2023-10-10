#ifndef Ordenador_h
#define Ordenador_h

class Ordenador{
	private:
    // Defina aquí los métodos auxiliares de los algoritmos de ordenamiento solamente.
    // Puede definir cuantos métodos quiera.
	void merge(int *A, int p, int q, int r); 
	void mergesortAUX(int *A, int p, int r); 

	public:
	Ordenador(){};
	~Ordenador(){};
    // Si no implementa algunos de los métodos de ordenamiento no lo borre;
    // déjelo con el cuerpo vacío para evitar errores de compilación, ya
    // que se va a ejecutar el mismo «main» para todas las tareas.
    // Implemente los algoritmos en este archivo, no en un CPP.
	void seleccion(int *A, int n);
	void insercion(int *A, int n);
	void mergesort(int *A, int n);
	void heapsort(int *A, int n);
	void quicksort(int *A, int n);
	void radixsort(int *A, int n);
};
#endif

void Ordenador::seleccion(int *A, int n){ 
	for (int i = 0; i < n; i++){
		int menor = A[i]; 
		int index = i; 

		for(int j = i + 1; j < n; j++){ 
			if(A[j] < menor){
				menor = A[j]; 
				index = j; 
			}
		} 

		if(index != i){
			int auxiliar = A[i]; 
			A[i] = menor;
			A[index] = auxiliar; 
		}
	}
	
} 

void Ordenador::insercion(int *A, int n){ 
	for(int i = 1; i < n; i++){
		int key = A[i]; 
		int j = i - 1;  

		while(j >= 0 && A[j] > key){ 
			A[j + 1] = A[j]; 
			j=j-1; 
		} 

		A[j + 1] = key; 
	}
} 

void Ordenador::mergesort(int *A, int n){ 
	mergesortAUX(A, 0, n-1); 
} 


void Ordenador::merge(int *A, int p, int q, int r){ 
	int nL = q - p + 1; 
	int nR = r - q; 

	int L[nL]; 
	int R[nR]; 

	for(int i = 0; i < nL; i++){
		L[i] = A[p + i]; 
	}  

	for(int j = 0; j < nR; j++){
		R[j] = A[q + j + 1]; 
	} 

	int i = 0, j = 0, k = p;  

	while (i < nL && j < nR){
		if(L[i] <= R[j]){
			A[k] = L[i]; 
			i++;
		}else{
			A[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 

	while (i < nL){
		A[k] = L[i]; 
		i++; 
		k++; 
	} 

	while (j < nR){
		A[k] = R[j]; 
		j++; 
		k++;
	}
} 

void Ordenador::mergesortAUX(int *A, int p, int r){ 
	if(p < r){ 
		int q = (p + r) / 2; 

		mergesortAUX(A, p, q); 

		mergesortAUX(A, q + 1, r); 

		merge(A, p, q, r); 
	}
}



