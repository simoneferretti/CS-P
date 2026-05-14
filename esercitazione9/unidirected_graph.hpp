#pragma once
#include <string>
#include <iostream>
#include <set>
#include <iterator>
#include "unidirected_edge.hpp"
#include <stdexcept>
#include <fstream>
#include <map>



template<typename T, typename R = double> 
class unidirected_graph {
	std::set<T> V; // nodi
	std::set<unidirected_edge<T>> E; // archi
	std::map<unidirected_edge<T>, R> W; // pesi
	

public:
	 /* costruttore default */
	 unidirected_graph() {};
	
	/* costruttore di copia */
	 unidirected_graph(const unidirected_graph& ug) {
		 this->V = ug.V;
		 this->E = ug.E;
		 this->W = ug.W;
	 }
	 
	 std::set<T> neighbours(const T& node) const {
		 
		 size_t len = E.size();
		 size_t i = 0;
		 auto it = E.begin(); // provo a farlo manualmente con iteratori
		 std::set<T> neigh; 	
		 while (i<len) {
			 if (it->from() == node) {
				 neigh.insert(it->to());
			 }
			 else if (it->to() == node) {
				 neigh.insert(it->from());
			 }
			 i++;
			 it++;
		 }
		 return neigh;
	 }
	 
	 void add_edge(const unidirected_edge<T>& ue) {
		 E.insert(ue); // se l'arco c'è già non viene inserito
		 V.insert(ue.from()); // inserisco i nodi nel caso in cui non fossero già presenti
		 V.insert(ue.to());
		 W[ue] = 1; // peso unitario di default
	 }
	 
	 void add_edge(const unidirected_edge<T>& ue, const R& w) { //inserire arco e peso contemporaneamente
		 add_edge(ue);
		 W[ue] = w;
	 }
	 
	 void add_weight(const unidirected_edge<T>& ue, const R& w) {
		 if (E.find(ue) == E.end()) {
			 throw std::invalid_argument("add_weight: arco inesistente");
		 }
		 W[ue] = w;
	 }
	 
	 R get_weight(const unidirected_edge<T>& ue) const {
		 return W.at(ue);
	 }
	 
	 std::set<unidirected_edge<T>> all_edges() const {
		 return E;
	 }
	 
	 std::set<T> all_nodes() const {
		 return V;
	 }
	 
	 size_t edge_number(const unidirected_edge<T>& ue) const {
		 size_t i = 0;
		 for (const auto& e: E) {
			 if (e == ue) { // uso l'operator == definito 
				break;
			 }
			 i++;
		 }
		 return i; // se non trovo niente, restituisco la size dell'insieme degli archi
	 }
	 
	 unidirected_edge<T> edge_at(const size_t i) const {
		 auto it = E.begin();
		 if (i >= E.size()) {
			throw std::out_of_range("edge_at: indice non valido"); // gestisco eccezione
		 }
		 std::advance(it,i); // avanza l'iteratore di i posizioni
		 return *it; // ritorno iteratore dereferenziato, ovvero l'arco
	 }
	 
	 unidirected_graph operator-(const unidirected_graph& g2) const {
		 unidirected_graph diff;
		 for (const auto& e : E) {
			 if (g2.E.find(e) == g2.E.end()) {
				 diff.add_edge(e);
			 }
		 }
		 return diff;
	 }	 

	void export_to_dot(const std::string& f) {
    std::ofstream out(f);
    if (out.is_open()) {
        out << "graph G {\n";
        /* itero su tutti gli archi per stamparli */
        for (const auto& edge : all_edges()) {
            out << "  " << edge.from() << " -- " << edge.to() << ";\n";
        }
        out << "}\n";
        out.close();
    }
}
};
	 
		 

	
	