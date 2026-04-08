#pragma once
#include <vector>

template<typename T>

bool is_sorted(const std::vector<T>& vec)
{
if (vec.size() == 0) {
return true;
}
for (size_t i = 0; i < (vec.size()-1); i++) {
	if (vec.at(i)>vec.at(i+1)) {
		return false;
		}
}
return true;
}

template<typename T>
void bubble_sort(std::vector<T>& A) {
    size_t n = A.size();

    if (n <= 1) { // se dim<=1 ok
		return;
		} 
    
	// scalo di 1 gli indici
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = n - 1; j > i; j--) {
            if (A[j] < A[j - 1]) {
                T old = A[j]; // swap
                A[j] = A[j - 1];
                A[j - 1] = old;
            }
        }
    }
}

template<typename T>
void insertion_sort(std::vector<T>& A) {
	size_t n = A.size();
    if (n <= 1) {
		return; // come prima
		}
    
    for (size_t j = 1; j < n; j++) {
        T key = A[j];
		/* traslo di uno a destra, altrimenti dovrei mettere while (i>=0 ...) ma i è di tipo size_t */
        size_t i = j; 
        
		// implemento l'algoritmo di conseguenza
        while (i > 0 && A[i - 1] > key) {
            A[i] = A[i - 1];
            i--;
        }
        A[i] = key;
    }
}

template<typename T>
void selection_sort(std::vector<T>& A) {
    size_t n = A.size();
    if (n <= 1) {
		return;
		}
    
    for (size_t i = 0; i < n - 1; i++) {
        size_t min = i; // inizializzo il minimo
        
        for (size_t j = i + 1; j < n; j++) { // non serve traslare j perché è definito in base a i
            if (A[j] < A[min]) {
                min = j;
            }
        }
        /* scambio con l'elemento trovato */
        T vecchio = A[i];
        A[i] = A[min];
        A[min] = vecchio;
    }
}