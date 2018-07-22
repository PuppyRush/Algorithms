//
//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <deque>
//
//using namespace std;
//using uint = unsigned int;
//using Range = pair<uint, uint>;
//
//typedef struct Node
//{
//public:
//	Range range;
//	bool lopen;
//	bool ropen;
//	uint count;
//
//	Node *left;
//	Node *right;
//public:
//	Node(Range range)
//		:left(nullptr),right(nullptr),range(range),lopen(false),ropen(false),count(1)
//	{
//	}
//};
//
//class Tree
//{
//public:
//	explicit Tree(Range Range)
//	{
//		root = new Node(Range);
//	}
//
//	Node* getRoot()  const
//	{
//		return root;
//	}
//
//	void insert(Range range)
//	{
//		_insert(root,root, range);
//	}
//
//	void visit() const
//	{
//		deque<Range> q;
//		_preorder(q,root);
//	}
//
//	
//private:
//	Node *root;
//
//private:
//	void _insert(Node *parent, Node *current, Range range)
//	{
//		if (current == nullptr)
//		{
//			current = new Node(range);
//			return;
//		}
//
//		if (range.first == range.second)
//		{
//			if (current->range.first == range.first)
//				current->lopen != current->lopen;
//			else if (current->range.second == range.second)
//				current->ropen != current->ropen;
//			else
//			{
//				if (parent->range.first < current->range.second)
//					_insert(current, current->left, range);
//				else
//					_insert(current, current->right, range);
//			}
//		}
//
//		if (current->range.second < range.first)
//		{
//
//		}
//	}
//
//	void _preorder(deque<Range> &q, Node *current) const
//	{
//		if (current != nullptr)
//		{
//			_preorder(q,current->left);
//			_preorder(q,current->right);
//		}
//	}
//};
//
//int main()
//{
//	int size = 0;
//	scanf("%d", &size);
//
//	int l = 0, r = 0;
//	scanf("%d %d", &l, &r);
//	auto range = make_pair(l, r);
//	Tree tree(range);
//
//	for (int i = 1; i < size; i++)
//	{
//		l = 0, r = 0;
//		scanf("%d %d", &l, &r);
//		range = make_pair(l, r);
//		tree.insert(range);
//	}
//
//	tree.visit();
//}