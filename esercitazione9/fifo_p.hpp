#pragma once
#include <queue>
#include <vector>
#include <functional>

template<typename T>
class fifo_p {
	std::priority_queue<T,std::vector<T>, std::greater<T>> Q; // così estrae il minimo
public:
	 /* costruttore default */
	 fifo_p() {};
	 
	 void put(const T& nuovo) {
		 Q.push(nuovo);
	 }
	 
	 T get() {
		 T got = Q.top(); // priority_queue usa top
		 Q.pop();
		 return got;
	 }
	 
	 bool empty() {
		 return Q.empty();
	 }
};