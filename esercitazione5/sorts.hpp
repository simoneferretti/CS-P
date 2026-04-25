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


template<typename T>
void merge(std::vector<T>& A, size_t sx, size_t m, size_t dx) {
	size_t n1 = m - sx +1;
	size_t n2 = dx - m;
	std::vector<T> L(n1);
	std::vector<T> R(n2);
	for (size_t i = 0; i < n1; i++) {
		L[i] = A[sx + i];
	}
	for (size_t j = 0; j < n2; j++) {
		R[j] = A[m +1 + j];
	}
	size_t i = 0;
	size_t j = 0;
	for (size_t k =sx; k <= dx; k++) {
		if (i<n1 && j<n2) {
			if (L[i] <= R[j]) {
				A[k] = L[i];
				i++;
			}
			else {
				A[k] = R[j];
				j++;
			}
		}
		else if (i<n1){
			A[k] =L[i];
			i++;
		}
		else {
			A[k] = R[j];
			j++;
		}
	}
}

template<typename T>
void merge_sort(std::vector<T>& A, size_t sx, size_t dx) {
	if (sx<dx) {
		size_t m = sx + (dx-sx)/ 2;
		merge_sort(A, sx, m);
		merge_sort(A, m+1, dx);
		merge(A, sx, m, dx);
	}
}

template<typename T>
size_t part(std::vector<T>& A, size_t sx, size_t p, size_t dx) {
	if (p<dx) {
		T temp = A[dx];
		A[dx] = A[p];
		A[p] = temp;
		p = dx;
	}
	size_t i = sx;
	for (size_t j = sx; j<dx; j++) {
		if (A[j] <= A[dx]) {
			T temp = A[i];
			A[i] = A[j];
			A[j] = temp;
			i++;
		}
	}
	if (i<dx) {
		T temp = A[i];
		A[i] = A[p];
		A[p] = temp;
	}
	return i;
}

template<typename T>
void quick_sort(std::vector<T>& A, size_t sx, size_t dx) {
	if (sx<dx) {
		size_t p =rand() % (dx-sx+1) + sx; // pivot
		size_t q = part(A,sx,p,dx);
		if (q > 0) { // necessario perché ho usato size_t
			quick_sort(A, sx, q-1);
		}
		quick_sort(A,q+1,dx);
	}
}

template<typename T>
void insertion_sort(std::vector<T>& A, size_t sx, size_t dx) {
    if (sx >= dx) {
		return;
	}

    for (size_t j = sx + 1; j <= dx; j++) {
        T key = A[j];
		/* traslo di uno a destra, altrimenti dovrei mettere while (i>=0 ...) ma i è di tipo size_t */
        size_t i = j;
		// implemento l'algoritmo di conseguenza
        while (i > sx && A[i - 1] > key) {
            A[i] = A[i - 1];
            i--;
        }
        A[i] = key;
    }
}

template<typename T>
void opt_quick_sort(std::vector<T>& A, size_t sx, size_t dx) {
	if (dx-sx <= 59) {
		insertion_sort(A,sx,dx);
	}
	else if (sx<dx) {
		size_t p =rand() % (dx-sx+1) + sx; // pivot
		size_t q = part(A,sx,p,dx);
		if (q > 0) { // necessario perché ho usato size_t
			opt_quick_sort(A, sx, q-1);
		}
		opt_quick_sort(A,q+1,dx);
	}
}
