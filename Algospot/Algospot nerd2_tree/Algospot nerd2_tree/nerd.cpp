#define _CRT_SECURE_NO_WARNINGS
#define FOR(l,size) for(l ; l < size ; ++l)

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

enum ORDER{
	LEFT=1,
	RIGHT=2,
	NONE=3
};

typedef struct REGISTRATION{
	int bowl;
	int problem;
	REGISTRATION* root;
	REGISTRATION* left;
	REGISTRATION* right;
}R;


int nodeCount;

R* removeAll(R* root) {

	if (root->left == nullptr && root->right == nullptr) {

		if (root->root == root) {
			delete root;
			return nullptr;
		}

		R* r = root->root;
		r->right = nullptr;
		r->left = nullptr;
		delete root;
		return r;
	}
		
	while (root != nullptr) {
		if (root->left != nullptr &&  root->left != nullptr) {
			root = removeAll(root->left);
			continue;
		}
		if (root->right != nullptr &&root->right != nullptr) {
			root = removeAll(root->right);
			continue;
		}
		root = removeAll(root);
	}
	
	return root;
}

R* _remove(R* dest, const ORDER o) {

	R* newRoot = nullptr;

	if (dest == nullptr)
		return nullptr;
	
	if (o == LEFT) {
		if (dest->right != nullptr) {
			dest->root->left = dest->right;
			newRoot = dest->right;
		}
		else if (dest->left != nullptr) {
			dest->root->left = dest->left;
			newRoot = dest->left;
		}
		else
			dest->root->left = nullptr;
	}
	else if (o == RIGHT) {
		if (dest->left != nullptr) {
			dest->root->right = dest->left;
			newRoot = dest->left;
		}
		else if (dest->right != nullptr) {
			dest->root->right = dest->right;
			newRoot = dest->right;
		}
		else
			dest->root->right = nullptr;
	}

	nodeCount--;
	delete dest;	
	return newRoot;	
}

R* valid(R* root){

	if (root == nullptr)
		return nullptr;
	bool ok = true;
	if (root->left!=nullptr &&  root->bowl > root->left->bowl && root->problem > root->left->problem) {
		root = _remove(root->left,LEFT);
		ok = false;
	}

	if (root->right != nullptr &&  root->bowl > root->right->problem && root->problem > root->right->problem) {
		root = _remove(root->right,RIGHT);
		ok = false;
	}

	if(!ok)
		root = valid(root);

	return root;
}


R* replace(R* dest, R* src, const ORDER order) {

	if (dest->left != nullptr)
		dest->left->root = src;
	if (dest->right != nullptr)
		dest->right->root = src;

	if (dest->root == dest) {
		
		src->left = dest->left;
		src->right = dest->right;
		src->root = src;
	}
	else if (order == LEFT) {
		dest->root->left = src;
		src->left = dest->left;
		src->right = dest->right;
		src->root = dest->root;
	}
	else if (order == RIGHT) {
		dest->root->right = src;
		src->left = dest->left;
		src->right = dest->right;
		src->root = dest->root;
	}

	delete dest;
	valid(src);

	return src;
}

R* insert(R* root, R* dest, ORDER order) {

	if (root->bowl >= dest->bowl && root->problem >= dest->problem) 
		delete dest;
	
	else if (root->bowl < dest->bowl && root->problem < dest->problem) {
		root = replace(root, dest, order);
	}
	else if (root->bowl > dest->bowl && root->problem < dest->problem) {

		if (root->right == nullptr) {
			root->right = dest;
			dest->root = root;
			nodeCount++;
		}
		else
			insert(root->right, dest, RIGHT);
	}
	else if (root->bowl < dest->bowl && root->problem > dest->problem) {

		if (root->left == nullptr) {
			root->left = dest;
			dest->root = root;
			nodeCount++;
		}
		else
			insert(root->left, dest, LEFT);
	}

	return root;
}


R* getNode(int bowl, int pro) {
	
	R* r = new R;
	r->bowl = bowl;
	r->problem = pro;

	r->root = r;
	r->left = nullptr;
	r->right = nullptr;
	return r;
}

void main2() {

	vector<int> result;

	int caseSize = 0;
	scanf("%d", &caseSize);

	int i = 0;
	FOR(i, caseSize) {

		int registration = 0;
		scanf("%d", &registration);

		int q=0, b=0;
		scanf("%d %d", &q, &b);
		R *root = getNode(b, q);
		
		int res = nodeCount = 1;
		for(int l=0; l < registration-1 ; l++){

			scanf("%d %d", &q, &b);

			R *r = getNode(b, q);

			root = insert(root,r,NONE);
			res += nodeCount;
		}

		//removeAll(root);
		result.push_back(res);
	}

	i = 0;
	FOR(i, result.size()) {
		cout << result[i] << endl;
	}

	//_CrtDumpMemoryLeaks();
}
