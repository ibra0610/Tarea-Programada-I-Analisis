#ifndef Ordenador_h
#define Ordenador_h


class Ordenador{ 

	private:
    // Defina aquí los métodos auxiliares de los algoritmos de ordenamiento solamente.
    // Puede definir cuantos métodos quiera.
	void merge(int *A, int p, int q, int r); 
	void mergesortAUX(int *A, int p, int r); 
	void max_heapify(int *A, int n, int i);  
	void build_max_heap(int *A, int n); 
	void quicksortAUX(int *A, int p, int r); 
	int partition(int *A, int p, int r);  
	int obtenerMaximo(int *A, int n);  
	void countingSort(int *A, int n, int div); 

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

//SELECCION

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

//INSERCION

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

//MERGESORT

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

//II Parte de la Tarea 

//HEAPSORT

void Ordenador::heapsort(int *A, int n){

	build_max_heap(A, n); 

	for(int i = n - 1; i >= 0; i--){
		std::swap(A[0], A[i]); 

		max_heapify(A, i, 0); 
	}
}

void Ordenador::max_heapify(int *A, int n, int i){
	int left = 2 * i + 1; 
	int right = 2 * i + 2; 
	int largest = i; 

	if(left < n && A[left] > A[largest]){
		largest = left; 
	} 

	if(right < n && A[right] > A[largest]){
		largest = right; 
	} 

	if(largest != i){
		std::swap(A[i], A[largest]); 
		max_heapify(A, n, largest); 
	}
}

void Ordenador::build_max_heap(int *A, int n){

	for(int i = n / 2 - 1; i >= 0; i--){
		max_heapify(A, n, i); 
	}
} 

//QUICKSORT 

void Ordenador::quicksort(int *A, int n){
	quicksortAUX(A, 0, n-1); 
}

void Ordenador::quicksortAUX(int *A, int p, int r){ 
	
	if(p < r){
		int q = partition(A, p, r); 
		quicksortAUX(A, p, q-1); 
		quicksortAUX(A, q+1, r); 
	}
} 

int Ordenador::partition(int *A, int p, int r){
	int x = A[r]; 
	int i = p - 1; 

	for(int j = p; j <= r -1; j++){
		if(A[j] <= x){ 
			i++; 
			std::swap(A[i], A[j]); 
		}
	} 

	std::swap(A[i+1], A[r]); 

	return i+1; 
} 

//RADIX-SORT 

void Ordenador::radixsort(int *A, int n){

	int maximo = obtenerMaximo(A, n); 

	for(int div = 1; maximo/div > 0; div*= 10){
		countingSort(A, n, div); 
	} 

} 

void Ordenador::countingSort(int *A, int n, int div){ 
	int salida[n]; 
	int cuenta[10] = {0}; 

	for(int i = 0; i < n; i++){ 
		cuenta[ (A[i] / div) % 10]++; 
	} 

	for(int i = 1; i < 10; i++){ 
		cuenta[i] += cuenta[i - 1]; 
	} 

	for(int i = n - 1; i >= 0; i--){
		salida[cuenta[(A[i]/div)%10] - 1] = A[i]; 
		cuenta[ (A[i]/div) % 10]--; 
	} 

	for(int i = 0; i < n; i++){
		A[i] = salida[i]; 
	}
}

int Ordenador::obtenerMaximo(int *A, int n){

	int max = A[0]; 

	for(int i = 1; i < n; i++){
		if(A[i] > max){
			max = A[i]; 
		}
	}

	return max; 
} 


