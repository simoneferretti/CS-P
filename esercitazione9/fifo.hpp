#pragma once
#include <queue>

template<typename T>
class fifo {
	std::queue<T> Q;
public:
	 /* costruttore default */
	 fifo() {};
	 
	 void put(const T& nuovo) {
		 Q.push(nuovo);
	 }
	 
	 T get() {
		 T got = Q.front();
		 Q.pop();
		 return got;
	 }
	 
	 bool empty() {
		 return Q.empty();
	 }
};