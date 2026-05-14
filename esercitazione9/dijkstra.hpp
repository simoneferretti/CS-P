#pragma once
#include "unidirected_graph.hpp"
#include "unidirected_edge.hpp"
#include "fifo_p.hpp"
#include <set>
#include <map>
#include <vector>
#include <limits>
#include <stdexcept>

template<typename I, typename R>
unidirected_graph<I, R> dijkstra(const unidirected_graph<I,R>& g,const I& r) {
	unidirected_graph<I,R> tree;
	std::map<I,I> pred;
	std::map<I, R> dist;
	fifo_p<std::pair<R,I>> pq; //ordina prima per distanza, poi nodo
	
	R inf =std::numeric_limits<R>::infinity();
	
	for (const auto& v: g.all_nodes()) {
		dist[v] = inf;
	}
	
	if (dist.find(r) == dist.end()) {
        throw std::invalid_argument("dijkstra: sorgente non presente nel grafo");
    }
	
	pred[r] = r;
	dist[r] = 0;
	pq.put({0,r});
	
	while (!pq.empty()) {
		std::pair<R,I> now = pq.get();
		R dist_u = now.first;
		I u = now.second;
		
		if (dist_u > dist[u]) {
			continue;
		}
		
		for (const auto&v : g.neighbours(u)) {
			unidirected_edge<I> e = unidirected_edge<I>(u,v);
			R w = g.get_weight(e);
			
			if (w<0) {
				throw std::invalid_argument("dijkstra: c'è un peso negativo");
			}
			
			if (dist[u] != inf  && dist[v] > dist[u] +w) {
				dist[v] = dist[u] + w;
				pred[v] =u;
				pq.put({dist[v],v});
			}
		}
	}
	
	for (const auto& p: pred) {
		I v = p.first;
		I padre = p.second;
		
		if (v != r) {
			unidirected_edge<I> e = unidirected_edge<I>(padre,v);
			R w = g.get_weight(e);
			tree.add_edge(e, w);
		}
	}
	
	return tree;
}