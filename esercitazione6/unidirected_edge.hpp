#pragma once
#include <string>
#include <iostream>


template<typename T> 
class unidirected_edge {
	T n1_;
	T n2_;

public:
	 /* costruttore user defined */
	 unidirected_edge(T un1, T un2) {//user input
		if (un2 < un1) {
		n1_ = un2;
		n2_ = un1;
		}
		else {
			n1_ = un1;
			n2_ = un2;
		}
	 }
	
	/* metodi di lettura */
	T from() const {return n1_;};
	T to() const {return n2_;};
	
	bool operator==(const unidirected_edge& ue2) const {
		unidirected_edge ue1 = *this;
		if (ue1.from() == ue2.from()) {
			if (ue1.to() == ue2.to()) {
				return true;
			}
		}
		return false;
	}

	
	bool operator<(const unidirected_edge& ue2) const {
		unidirected_edge ue1 = *this;
		if (ue1.from() < ue2.from()) {
			return true;
		}
		else if (ue1.from() == ue2.from()) {
			if (ue1.to() < ue2.to()) {
				return true;
			}
		}
		return false;  // Oss: se sono uguali sia partenza che arrivo restituisco uno qualsiasi
	}
};
			
		
		
template<typename T>
std::ostream&
operator<<(std::ostream& os, const unidirected_edge<T>& a) {
	T n1 = a.from();
	T n2 = a.to();
	os << "\nl'arco va da " << n1 << " a " << n2 << "\n";
	return os;
}
		
		
		
	
	

