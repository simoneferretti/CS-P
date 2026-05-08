#include "unidirected_edge.hpp"
#include "unidirected_graph.hpp"
#include <iostream>
#include <string>

using namespace std;
int main()
{
    cout << "Test add_edge" << endl;
    unidirected_graph<int> g1;
    g1.add_edge({1, 2});
    g1.add_edge({2, 1});  // è uguale al primo arco
    g1.add_edge({2, 3});
    g1.add_edge({3, 4});
    cout << "Grafo G1 (dovrebbe avere 3 archi): " << g1.all_edges().size() << endl;

    cout << "Test neighbours" << endl;
    cout << "Nodi nel grafo: ";
	
    for(auto n : g1.all_nodes()) {cout << n << " ";}
    cout << endl;

    int nodo_test = 3;
    cout << "neighbours di  " << nodo_test << ": ";
    auto vicini = g1.neighbours(nodo_test);
    for(auto v : vicini) cout << v << " ";
    cout << "\n" << endl;


    cout << "Verifico la numerazione invertendo i nodi" << endl;
    unidirected_edge<int> e_cerca(4, 3);
    size_t it = g1.edge_number(e_cerca);
    
    cout << "Cerco la numerazione corrispondente all'arco (4,3): " << endl;
    if(it != g1.all_edges().size()) {
        cout << "Numerazione arco: " << it << endl;
    } 
	else {
        cout << "Arco non trovato." << endl;
    }
    cout << endl;

    cout << "Test sottrazione" << endl;
    unidirected_graph<int> g2;
    g2.add_edge({2, 3}); 
    
    unidirected_graph<int> g = g1 - g2;
    cout << "Dimensione insieme degli archi del grafo differenza (dovrebbe essere 2): " << g.all_edges().size() << endl;

    return 0;
}