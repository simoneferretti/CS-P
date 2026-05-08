#include "unidirected_edge.hpp" 
#include "unidirected_graph.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

bool test_addedge() {
    unidirected_graph<int> g;
    unidirected_edge<int> e(-1, 1);
    g.add_edge(e);

    if (g.all_edges().size() == 1 && 
        g.all_nodes().size() == 2 && 
        g.all_nodes().contains(-1) && 
        g.all_nodes().contains(1)) 
    {
        return true;
    } else {
        cout << "Test add_edge: FALLITO!" << endl;
        return false;
    }
}

bool test_numerazione() {
    unidirected_graph<string> g;
    unidirected_edge<string> e1("Jakarta", "Bali");
    g.add_edge(e1);

    size_t id = g.edge_number(e1); 
    unidirected_edge<string> e2 = g.edge_at(id);

    if (id == 0 && (e2.to() == "Jakarta" && e2.from() == "Bali")) {
        return true;
    } else {
        cout << "Test Mapping ID: FALLITO!" << endl;
        return false;
    }
}

bool test_neighbours() {
    unidirected_graph<int> g;
    g.add_edge(unidirected_edge<int>(1, 2)); 
    g.add_edge(unidirected_edge<int>(1, 3));

    std::set<int> v = g.neighbours(1); 

    if (v.size() == 2 && v.contains(2) && v.contains(3)) {
        return true;
    } else {
        cout << "Test Vicini: FALLITO!" << endl;
        return false;
    }
}

bool test_sottr() {
    unidirected_graph<int> g1, g2;
    g1.add_edge(unidirected_edge<int>(1, 2));
    g1.add_edge(unidirected_edge<int>(2, 3));
    g2.add_edge(unidirected_edge<int>(2, 3)); 

    unidirected_graph<int> diff = g1 - g2;
    size_t diff_size = diff.all_edges().size();

    if (diff_size == 1 && 
        diff.edge_number(unidirected_edge<int>(1, 2)) != diff_size && 
        diff.edge_number(unidirected_edge<int>(2, 3)) == diff_size) // edge_number ritorna la size se non trova l'arco
    {
        return true;
    } else {
        cout << "Test sottrazione: FALLITO!" << endl;
        return false;
    }
}

int main() {
    bool ok = true;
    if(!test_addedge() || !test_numerazione() || !test_neighbours() || !test_sottr()) {
        ok = false; 
    }
    
    if(ok){
        return EXIT_SUCCESS;
    }
    else
    {
        cout << "Almeno un test è FALLITO" << endl;
        return EXIT_FAILURE;
    }
} 