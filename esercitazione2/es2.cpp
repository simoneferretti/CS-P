#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main (void) {
	static const int N = 10;
	double arr[N] = {10,9,8,7,6,5,4,3,2,1};

	double minimo = arr[0];	
	double massimo = arr[0];	
	double somma = 0;
	
	for (int i = 0;i<N;i++) {
		massimo = max(massimo, arr[i]);
		minimo = min(minimo,arr[i]);
		somma += arr[i];
	}
	
	double media = somma/N;
	cout << "Il massimo è " << massimo << "\n";
	cout << "Il minimo è " << minimo << "\n";
	cout << "La media è " << media << "\n";
	
	double somma_scarti = 0;
	for (int j =0;j<N;j++) {
		somma_scarti += (arr[j]-media)*(arr[j]-media);
	}
	double varianza = somma_scarti/N;
	double st_dev = sqrt(varianza);
	cout << "La deviazione standard è " << st_dev << "\n";
	
	// implemento BubbleSort
	bool flag = true;
	while (flag){
		flag = false;
		for (int i = 0;i<N-1;i++) { // salto l'ultima iterazione
			if (arr[i] > arr [i+1]) {
				double vecchia = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] =vecchia;
				flag = true;
			}
		}
	}
	
	cout<< "Array dopo BubbleSort:" ;
	for (int j =0;j<N;j++) {
		cout << arr[j] << " ";
	}
	cout << "\n";
	return 0;
	}