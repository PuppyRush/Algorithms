#include <iostream>

using namespace std;
using uint = unsigned int;

typedef struct Node
{
private:
	uint l;
	uint r;
	bool lopen;
	bool ropen;
	uint count;

	Node *left;
	Node *right;
public:
	Node(const uint lhs, const uint rhs)
		:left(nullptr),right(nullptr),l(lhs),r(rhs),lopen(true),ropen(true),count(1)
	{
	}
};

class Tree
{
private:
	Node *root;
public:
	Tree(Node *node) {
		root = new Node(node);
	}

	Node<T>* getRoot() {
		return root;
	}

	void visit(Node<T>* current) {
		cout << current->data << " ";
	}

	// 전위 순회 Current - Left - Right
	void preorder(Node<T>* current) {
		if (current != null) {
			visit(current);
			preorder(current->left);
			preorder(current->right);
		}
	}

	// 중위 순회 Left - Current - Right
	void inorder(Node<T>* current) {
		if (current != null) {
			inorder(current->left);
			visit(current);
			inorder(current->right);
		}
	}

	// 후위 순회 Left - Right - Current
	void postorder(Node<T>* current) {
		if (current != null) {
			postorder(current->left);
			postorder(current->right);
			visit(current);
		}
	}
};

