#include <iostream>
#include <vector>
#include <algorithm> 
#include "sorts.hpp"
#include "timecounter.h"
#include "randfiller.h"

int main() {
    randfiller rf;
    timecounter tc;

    std::cout << "Misurazione delle prestazioni:\n";

    for (size_t size = 4; size <= 8192; size *= 2) { // 12 iterazioni
        std::cout << "\n" << "Test per dimensione: " << size << "\n";
        
        /* creo vettore */
        std::vector<int> v_originale(size); 
        rf.fill(v_originale, -1000, 1000); 

        /* misuro BubbleSort */
        std::vector<int> v_bubble = v_originale; // necessario copiare per avere qualcosa da ordinare
        tc.tic();	
        bubble_sort(v_bubble);
        double time_bubble = tc.toc(); 

        /* misuro InsertionSort */
        std::vector<int> v_insertion = v_originale; // necessario copiare per avere qualcosa da ordinare
        tc.tic();	
        insertion_sort(v_insertion);
        double time_insertion = tc.toc(); 
		
        /* misuro SelectionSort */
        std::vector<int> v_selection = v_originale; // necessario copiare per avere qualcosa da ordinare
        tc.tic();	
        selection_sort(v_selection);
        double time_selection = tc.toc(); 
		
        /* misuro il sort standard */
        std::vector<int> v_std = v_originale;
        tc.tic();
        std::sort(v_std.begin(), v_std.end()); 
        double time_sort = tc.toc();

        std::cout << "Bubble Sort: " << time_bubble << " secondi\n";
        std::cout << "Selection Sort: " << time_selection << " secondi\n";
        std::cout << "Insertion Sort: " << time_insertion << " secondi\n";
        std::cout << "Sort (std)  : " << time_sort << " secondi\n";
            }
    return 0;
}