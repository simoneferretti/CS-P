#include <iostream>
#include <vector>
#include <string>
#include "sorts.hpp" 
#include "randfiller.h"

int main() {
    randfiller rf; 
	
	/* provo su 100 vettori casuali */
    for (int i = 0; i < 100; i++) {
        size_t size = i + 2; // testo su dimensioni crescenti
        std::vector<int> v(size);
        
        rf.fill(v, -1000, 1000); 
        
        bubble_sort(v);
        
        if (!is_sorted(v)) {
            std::cerr << "Test BubbleSort fallito\n";
            return EXIT_FAILURE; 
        }
    }

    /* provo con stringhe */
    std::vector<std::string> vs = {
        "alberto", "giorgio", "marco", "riccardo", 
        "simone", "davide", "furio", "andrea", 
    };

    bubble_sort(vs);

    if (!is_sorted(vs)) {
        std::cerr << "Test BubbleSort fallito\n";
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}