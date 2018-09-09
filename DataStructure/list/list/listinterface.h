#pragma once

#include <stdexcept>

namespace list {

template<class U>
struct node {
public:
	node *next;
	U value;
	node(node<U> *next, const U &v) :
		value(v),
		next(next) {}
};

template <class T>
class listInterface {

private:
	void operator=(const listInterface&) {}
	listInterface(const listInterface &) {}

protected:

	long count;
	node<T> *head;
	node<T> *tail;
	node<T> *now;

public:

	explicit listInterface(const T &value)
		:listInterface(new node<T>(nullptr,value))
	{}

	explicit listInterface(node<T> *n) {
		if (!n)
			throw std::invalid_argument("cant inject a parameter value as nullptr");
		head = n;
		tail = n;
		now = n;
		count = 1;
	}

	long size() { return this->count; }

	T get()
	{
		if (!now)
			throw std::invalid_argument("not initialize yet.");
		return now->value;
	}


public:


	virtual ~listInterface() = 0;

	virtual node<T>* append(node<T>*) = 0;
	virtual node<T>* append(const T&) = 0;
	virtual node<T>* append(const listInterface *_list) = 0;
	//virtual node<T>* remove(node<T>*) = 0;
	//virtual node<T>* remove(const T&) = 0;
	//virtual node<T>* replace(node<T>*) = 0;
	//virtual node<T>* replace(const T*) = 0;
	//virtual node<T>* find(node<T>*) = 0;
	//virtual node<T>* find(const T*) = 0;

};

}