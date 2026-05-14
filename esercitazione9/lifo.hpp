#pragma once
#include <stack>

template<typename T>
class lifo {
	std::stack<T> S;
public:
	 /* costruttore default */
	 lifo() {};
	 
	 void put(const T& nuovo) {
		 S.push(nuovo);
	 }
	 
	 T get() {
		 T got = S.top();
		 S.pop();
		 return got;
	 }
	 
	 bool empty() {
		 return S.empty();
	 }
};