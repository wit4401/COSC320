#ifndef DTNODE
#define DTNODE

#include <cstddef>

template <typename T>
class node
{
	public:
		T nodeValue;
		node<T> *left, *center, *right;
		node(){}
		node (const T& item, node<T> *ptr01=NULL, node<T> *ptr02=NULL, node<T> *ptr03=NULL):
			nodeValue(item), left(ptr01), center(ptr02), right(ptr03)
		{}
};
#endif
