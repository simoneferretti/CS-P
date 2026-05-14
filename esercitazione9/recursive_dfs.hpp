#pragma once
#include "unidirected_graph.hpp"
#include "unidirected_edge.hpp"
#include <set>
#include <vector>

template<typename I>
void recursive_dfs_aux(const unidirected_graph<I>& g,const I& r, std::set<I>& reached, unidirected_graph<I>& tree) {
	reached.insert(r);
	
	std::set<I> vic = g.neighbours(r);
	std::vector<I> next; // necessario per rispettare l'ordine

	
	for (auto it = vic.rbegin(); it != vic.rend(); ++it) { // itero al contrario
		I v = *it; // nodo dereferenziato

		if (reached.find(v) == reached.end()) {
			reached.insert(v);
			unidirected_edge<I> ue = unidirected_edge<I>(r,v);
			tree.add_edge(ue);
			next.push_back(v);
			// non aggiorno reached perché lo faccio con la chiamata ricorsiva
		}
	}
	for (I v : next) {
		recursive_dfs_aux(g,v,reached, tree);
	}
}


template<typename I>
unidirected_graph<I> recursive_dfs(const unidirected_graph<I>& g,const I& r) {
	unidirected_graph<I> tree;
	std::set<I> reached;
	
	recursive_dfs_aux(g,r, reached,tree);
	
	return tree;
}