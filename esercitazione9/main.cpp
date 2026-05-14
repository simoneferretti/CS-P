#include <iostream>
#include "unidirected_graph.hpp"
#include "unidirected_edge.hpp"
#include "fifo.hpp"
#include "lifo.hpp"
#include "graph_visit.hpp" 
#include "recursive_dfs.hpp" 
#include "dijkstra.hpp" 


int main() {
    unidirected_graph<int> G;
    
    G.add_edge(unidirected_edge<int>(1, 2));
    G.add_edge(unidirected_edge<int>(1, 4));
    G.add_edge(unidirected_edge<int>(1, 3), 0.9);
	G.add_edge(unidirected_edge<int>(1, 6));

    
    G.add_edge(unidirected_edge<int>(2, 4));
    G.add_edge(unidirected_edge<int>(2, 5));
    G.add_edge(unidirected_edge<int>(2, 7)); 
    
    G.add_edge(unidirected_edge<int>(3, 6));
    
    G.add_edge(unidirected_edge<int>(4, 6));
    G.add_edge(unidirected_edge<int>(4, 7));
    
    G.add_edge(unidirected_edge<int>(5, 7));
    
    G.add_edge(unidirected_edge<int>(6, 7));
    G.add_edge(unidirected_edge<int>(6, 8));
    
    G.add_edge(unidirected_edge<int>(7, 9));
    
    G.add_edge(unidirected_edge<int>(8, 9), 0.1); // ho modificato questo arco e uno dei precedenti per vedere se dijkstra funziona
    
    /* DFS */
    lifo<int> s;
    unidirected_graph<int> dfsG = graph_visit(G, 1, s);
    dfsG.export_to_dot("dfs.dot");
    std::cout << "Albero DFS esportato in dfs.dot\n";

    /* BFS */
    fifo<int> q;
    unidirected_graph<int> bfsG = graph_visit(G, 1, q);
    bfsG.export_to_dot("bfs.dot");
    std::cout << "Albero BFS esportato in bfs.dot\n";
	
	/* Recursive DFS */ 
	unidirected_graph<int> rDfsG = recursive_dfs(G,1);
	rDfsG.export_to_dot("rdfs.dot");
    std::cout << "Albero recursive DFS esportato in rdfs.dot\n";
	
	/* Dijkstra */ 
	unidirected_graph<int> dijG = dijkstra(G, 1);
	dijG.export_to_dot("dij.dot");
	std::cout << "Dijkstra esportato in dij.dot\n";

    return 0;
}