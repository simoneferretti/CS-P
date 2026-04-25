#include <iostream>
#include <vector>
#include <algorithm> 
#include "sorts.hpp"
#include "timecounter.h"
#include "randfiller.h"

int main() {
    randfiller rf;
    timecounter tc;
	
	size_t dim_min = 950;
	size_t dim_max = 1000;
	size_t sx = 0;
	std::vector<std::vector<int>> v_lista(dim_max - dim_min +1);
	size_t j = 0;
    for (size_t size = dim_min; size <= dim_max; size++) {
        /* creo vettore */
        std::vector<int> v_originale(size); 
        rf.fill(v_originale, -1000, 1000);
		v_lista[j] = v_originale;
		j++;
	}		
	
	tc.tic();
	for (size_t i = 0; i <= dim_max-dim_min; i++) {
        /* misuro BubbleSort */
        std::vector<int> v_bubble = v_lista[i]; // necessario copiare per avere qualcosa da ordinare
		//tc.tic();
        bubble_sort(v_bubble);
		//double time_bubble = tc.toc();
		//std::cout << "Tempo Bubble Sort con size " << dim_min +i << ":" << time_bubble << " secondi\n";
	}
	double mean_time_bubble = tc.toc()/(dim_max-dim_min+1);
	
	tc.tic();
	for (size_t i = 0; i <= dim_max-dim_min; i++) {
        /* misuro InsertionSort */
        std::vector<int> v_insertion = v_lista[i]; // necessario copiare per avere qualcosa da ordinare
		//tc.tic();
        insertion_sort(v_insertion);
		//double time_insertion = tc.toc();
		//std::cout << "Tempo Inserion Sort con size " << dim_min +i << ":" << time_insertion << " secondi\n";
	}
	double mean_time_insertion = tc.toc()/(dim_max-dim_min+1);
	
	tc.tic();
	for (size_t i = 0; i <= dim_max-dim_min; i++) {
        /* misuro SelectionSort */
        std::vector<int> v_selection = v_lista[i]; // necessario copiare per avere qualcosa da ordinare
		//tc.tic();
        selection_sort(v_selection);
		//double time_selection = tc.toc();
		//std::cout << "Tempo Selection Sort con size " << dim_min +i << ":" << time_selection << " secondi\n";
	}
	double mean_time_selection = tc.toc()/(dim_max-dim_min+1);
	
	tc.tic();
	for (size_t i = 0; i <= dim_max-dim_min; i++) {
		/* misuro MergeSort */
        std::vector<int> v_merge = v_lista[i]; // necessario copiare per avere qualcosa da ordinare
		size_t dx = v_merge.size() -1;
		//tc.tic();
        merge_sort(v_merge,sx,dx);
		//double time_merge = tc.toc();
		//std::cout << "Tempo Merge Sort con size " << dim_min +i << ":" << time_merge << " secondi\n";
	}
	double mean_time_merge = tc.toc()/(dim_max-dim_min+1);
	
	tc.tic();
	for (size_t i = 0; i <= dim_max-dim_min; i++) {
		/* misuro QuickSort */
        std::vector<int> v_quick = v_lista[i]; // necessario copiare per avere qualcosa da ordinare
		size_t dx = v_quick.size() -1;
		//tc.tic();
        quick_sort(v_quick,sx,dx);
		//double time_quick = tc.toc();
		//std::cout << "Tempo Quick Sort con size " << dim_min +i << ":" << time_quick << " secondi\n";
	}
	double mean_time_quick = tc.toc()/(dim_max-dim_min+1);
	
	tc.tic();
	for (size_t i = 0; i <= dim_max-dim_min; i++) {
		/* misuro Optimal QuickSort */
        std::vector<int> v_opt_quick = v_lista[i]; // necessario copiare per avere qualcosa da ordinare
		size_t dx = v_opt_quick.size() -1;
		//tc.tic();
        opt_quick_sort(v_opt_quick,sx,dx);
		//double time_opt_quick = tc.toc();
		//std::cout << "Tempo Opt Quick Sort con size " << dim_min +i << ":" << time_opt_quick << " secondi\n";
	}
	double mean_time_opt_quick = tc.toc()/(dim_max-dim_min+1);

	tc.tic();
	for (size_t i = 0; i <= dim_max-dim_min; i++) {
        /* misuro il sort standard */
        std::vector<int> v_std = v_lista[i];
		//tc.tic();
        std::sort(v_std.begin(), v_std.end());
		//double time_sort = tc.toc();
		//std::cout << "Tempo Standard Sort con size " << dim_min +i << ":" << time_sort << " secondi\n";		
	}
	double mean_time_sort = tc.toc()/(dim_max-dim_min+1);


	std::cout << "Tempo medio Bubble Sort: " << mean_time_bubble << " secondi\n";
	std::cout << "Tempo medio Selection Sort: " << mean_time_selection << " secondi\n";
	std::cout << "Tempo medio Insertion Sort: " << mean_time_insertion << " secondi\n";
	std::cout << "Tempo medio Merge Sort: " << mean_time_merge << " secondi\n";
	std::cout << "Tempo medio Quick Sort: " << mean_time_quick << " secondi\n";
	std::cout << "Tempo medio Optimized Quick Sort: " << mean_time_opt_quick << " secondi\n";
	std::cout << "Tempo medio Sort (std)  : " << mean_time_sort << " secondi\n";
    return 0;
}