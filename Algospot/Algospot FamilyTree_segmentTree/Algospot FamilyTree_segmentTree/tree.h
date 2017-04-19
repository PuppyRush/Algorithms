#pragma once

#include <vector>

using namespace std;

class Tree {

private:

	struct node {
		private:
			vector<node> childs;
		public:
			int number;
			int childAllSize;
			node *root;

			node(int n,node *_root) :number(n), childAllSize(1){
				if (_root == nullptr)
					this->root = this;
				else
					this->root = _root;
			}
			void add(node n) {
				childAllSize += n.childAllSize;
				childs.push_back(n);
			}
			int size() { return childs.size(); }
	};

public:

	node *root;

public:

	Tree(vector<int>familys) {
		root = new node(0,nullptr);
		int number = 1;
		init(familys, root,0,number);
	}
	
	node* init(const vector<int>familys,node *root,int idx,int &number) {
	
		node *thisChildNode = nullptr;
				

		for (int i=idx; i < familys.size(); i++) {			
			if (root->number != familys[i]){
				break;
			}
			else {
				if (root->number == familys[i]) {
					thisChildNode = new node(number++, root);
					root->add(*thisChildNode);
				}
			}
		}
		if (thisChildNode != nullptr) {
			node *newRoot = init(familys, thisChildNode, idx + root->sizeZ, number);
			root->add(*newRoot);
		}
		return root;
	}

};