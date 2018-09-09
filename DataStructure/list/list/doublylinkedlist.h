#pragma once

#include "listinterface.h"

using namespace list;

template <class T>
struct doublynode : public node<T> {

public:
	doublynode *prev;

	doublynode(const T& value) :
		doublynode(value, nullptr, nullptr) {}

	doublynode(const T& value, node<T>* next, doublynode* prev){
		::node(next, value);
		this->prev = prev;
	}

};

template <class T>
class doublylinkedlist : public listInterface<T> {

private:
	doublylinkedlist(const doublylinkedlist &l) { ; }

public:

	doublylinkedlist(const T &value) :
		listInterface(value) {}

	~doublylinkedlist(){}

	virtual node<T>* append(node<T>*);
	virtual node<T>* append(const T&) ;
	virtual node<T>* append(const listInterface *_list) ;
	//virtual node<T>* remove(node<T>*) ;
	//virtual node<T>* remove(const T&) ;
	//virtual node<T>* replace(node<T>*) ;
	//virtual node<T>* replace(const T*) ;
	//virtual node<T>* find(node<T>*) ;
	//virtual node<T>* find(const T*) ;


};
