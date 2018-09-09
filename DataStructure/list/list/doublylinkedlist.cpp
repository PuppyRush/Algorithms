#include "doublylinkedlist.h"

using namespace list;

template <class T>
node<T>* doublylinkedlist<T>::append(const T& value) {

	return append<T>(new node<T>(value));
}

template <class T>
node<T>* doublylinkedlist<T>::append(const listInterface *list) {

	return append(new node<T>(value));
}


template <class T>
node<T>* doublylinkedlist<T>::append(node<T>* n) {

	tail->next = n;
	now = n;

	return tail;
}