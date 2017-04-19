#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

#define FOR_REVERSE(i,SIZE) for( ; i >= SIZE ; i--)
#define FOR(i,SIZE) for(i=0 ; i < SIZE ; i++)

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
	void calSize();

private:

	Treap() {}

};


template <class type>
using TreapPair = pair<Treap<type>*, Treap<type>* >;


template <class type>
TreapPair<type>* Treap<type>::splited(Treap<type> *root, type key) {

	if (root == nullptr)
		return new TreapPair(nullptr, nullptr);
	if (root->key < key) {
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
Treap<type>* Treap<type>::kth(Treap<type> *node, int k) {
	int left = 0;
	if (node->left != nullptr)
		left = node->left->size;
	if (k <= left)
		return kth(node->left, k);
	if (k == left + 1)
		return node;
	return kth(node->right, k - left - 1);
}


deque<int>* solve(const vector<int> &org, const int size) {

	
	int i = 0;
	Treap<int> *trep = new Treap<int>(++i);
	for (i; i < size; i++) {
		trep = trep->insert(trep, new Treap<int>(i+1));
	}

	deque<int> *result = new deque<int>();
	
	i = size - 1;
	FOR_REVERSE(i, 0) {
		int larger = org[i];
 		Treap<int> *p = trep->kth(trep,i + 1 - larger);
		result->push_front(p->key);
		trep = trep->erase(trep, p->key);
	}
	return result;
}

int main() {

	vector<deque<int>*> result;
	int caseSize = 0;
	scanf("%d", &caseSize);

	int i = 0;
	FOR(i, caseSize) {


		int size = 0;
		scanf("%d", &size);
		while (getchar() != '\n');

		int l = 0;
		vector<int> seq(size);

		FOR(l, size) {
			scanf("%d", &seq[l]);
		}

		auto v = solve(seq, size);
		result.push_back(v);
	}

	i = 0;
	FOR(i, result.size()) {

		int l = 0;
		FOR(l, result[i]->size())
			cout << result[i]->at(l) << " ";
		cout << "\n";
	}
}