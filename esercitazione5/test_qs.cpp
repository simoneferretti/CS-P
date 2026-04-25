#include <iostream>
#include <vector>
#include <string>
#include "sorts.hpp" 
#include "randfiller.h"

int main() {
    randfiller rf; 
	size_t sx = 0;
	
	/* provo su 100 vettori casuali */
    for (int i = 0; i < 100; i++) {
        size_t size = i + 2; // testo su dimensioni crescenti
        std::vector<int> v(size);
        
        rf.fill(v, -1000, 1000); 
		size_t dx = size-1;
        
        quick_sort(v,sx,dx);
        
        if (!is_sorted(v)) {
            std::cerr << "Test QuickSort fallito\n";
            return EXIT_FAILURE; 
        }
    }

    /* provo con stringhe */
    std::vector<std::string> vs = {
        "alberto", "giorgio", "marco", "riccardo", 
        "simone", "davide", "furio", "andrea", "roby", "lou" 
    };

    quick_sort(vs,sx, vs.size()-1);

    if (!is_sorted(vs)) {
        std::cerr << "Test QuickSort fallito\n";
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}