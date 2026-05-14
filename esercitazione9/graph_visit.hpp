#pragma once
#include "fifo.hpp"
#include "lifo.hpp"
#include "unidirected_graph.hpp"
#include "unidirected_edge.hpp"
#include <set>

template<typename I, typename T>
unidirected_graph<I> graph_visit(const unidirected_graph<I>& g,const I& r, T& container) {
	unidirected_graph<I> tree;	
	std::set<I> reached;
	container.put(r);
	reached.insert(r);
	
	while (!container.empty()) {
		I u = container.get();
		/*if (!(reached.find(u) == reached.end())) {
			continue;
		}
		reached.insert(u);*/
		std::set<I> vic = g.neighbours(u);
		for (const auto v: vic) {
			if (reached.find(v) == reached.end()) {
				reached.insert(v);
				unidirected_edge<I> ue = unidirected_edge<I>(u,v);
				tree.add_edge(ue);
				container.put(v);
			}
		}
	}
	return tree;
}
