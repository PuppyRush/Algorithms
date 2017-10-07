#pragma once

#include <iostream>
#include <cstdlib>
using namespace std;

template <class type>
class Treap {

public:

	typedef std::pair<Treap*, Treap* > TreapPair;

	type key;
	int priority, size;
	Treap *left, *right;

	Treap(type _key) :
		key(_key), priority(rand()), size(1), left(nullptr), right(nullptr) {}
	


	void setLeft(Treap* t) { this->left = t; calSize(); }
	void setRight(Treap* t) { this->right = t; calSize(); }

	
	
	TreapPair* splited(Treap<type> *root, type key);
	Treap* insert(Treap<type>* root, Treap<type>* node);
	Treap* merge(Treap *node1, Treap* node2);
	Treap* erase(Treap *node, type key);
	Treap* kth(Treap* node, int k);

	///The function how many the element of treap rather than key of root
	Treap* countLessThan(Treap<type>* root, type key);
	void calSize();

private:

	Treap() {}

};

