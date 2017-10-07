
#include "trep.h"

template <class type>
using TreapPair = pair<Treap<type>*, Treap<type>* >;


template <class type>
TreapPair<type>* Treap<type>::splited(Treap<type> *root, type key) {

	if (root == nullptr)
		return new TreapPair(nullptr, nullptr);
	if (root->key < key){
		TreapPair *p = root->splited(root->right, key);
		root->setRight(p->first);
		return new TreapPair(root, p->second);
	}
	TreapPair* ls = root->splited(root->left, key);
	root->setLeft(ls->second);
	return new TreapPair(ls->first, root);
}


template <class type>
Treap<type>* Treap<type>::insert(Treap<type> *root, Treap<type> *node) {

	if (root == nullptr)
		return node;

	if (root->priority < node->priority) {
		
		TreapPair *p = root->splited(root, node->key);
		node->setLeft(p->first);
		node->setRight(p->second);
		return node;
	}
	else if (node->key < root->key)
		root->setLeft(root->insert(root->left, node));
	else
		root->setRight(root->insert(root->right, node));
	return root;
}

template <class type>
Treap<type>* Treap<type>::merge(Treap<type> *node1, Treap<type>* node2) {

	if (node1 == nullptr)
		return node2;
	else if (node2 == nullptr)
		return node1;
	else if (node1->priority < node2->priority) {
		node2->setLeft(merge(node1, node2->left));
		return node2;
	}
	
	node1->setRight(merge(node1->right, node2));
	return node1;	
}

template <class type>
Treap<type>* Treap<type>::erase(Treap<type> *node, type key) {

	if (node == nullptr)
		return node;
	if (node->key == key) {
		Treap* ret = merge(node->left, node->right);
		delete node;
		return ret;
	}
	if (key < node->key)
		node->setLeft(erase(node->left, key));
	else
		node->setRight(erase(node->right, key));

	return node;
}

template <class type>
void Treap<type>::calSize() {
	this->size = 1;
	if (this->left)
		this->size += this->left->size;
	if (this->right)
		this->size += this->right->size;
}

template <class type>
Treap<type>* Treap<type>::kth(Treap<type> *node, type k) {
	int left = 0;
	if (node->left != nullptr)
		left = node->left->size;
	if (k <= left)
		return kth(node->left, k);
	if (k == left + 1)
		return node;
	return kth(node->right, k - left - 1);
}

template <class type>
Treap<type>* Treap<type>::countLessThan(Treap<type>* root, type key) {

	if (root == nullptr)
		return 0;
	if (root->key >= key)
		return countLessThan(root->left, key);
	int count = (root->left ? root->left->size() : 0);
	return count + 1 + countLessThan(root->right, key);
}