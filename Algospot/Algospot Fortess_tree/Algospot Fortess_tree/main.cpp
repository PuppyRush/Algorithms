#define _CRT_SECURE_NO_WARNINGS
#define FOR(l,size) for(l ; l < size ; ++l)
#define MIN(a,b) { a>b  ? b : a }
#include <iostream>
#include <vector>
#include <string.h>
#include <deque>
#include <algorithm>

using namespace std;

typedef struct CASTLE{

	int x,y,r;

}C;


typedef struct NODE {
	C* node;
	vector<NODE*> childs;
	NODE* root;
}Node;

int longest;


bool comparator(C* c1, C* c2) {
	return c1->r > c2->r;
}

inline int getInterval(C *r1, C *r2) {
	return (int)sqrt(abs((r1->x - r2->x)*(r1->x - r2->x) + (r1->y - r2->y)*(r1->y - r2->y)));
}

bool isIncluded(C *bigger, C *smaller) {

	int interval = getInterval(bigger, smaller);
	return interval < bigger->r + smaller->r;
}


Node* getTrees(vector<C*> &v, Node* parentNode) {

	vector<C*> childs;

	if (v.empty())
		return new Node;

	auto it = v.begin();
	auto subParent = parentNode;

	while (it != v.end()) {

		if (isIncluded(parentNode->node, *it)) {

			Node *node = new Node;
			node->root = parentNode;
			node->node = *it;
			it = v.erase(it);
			parentNode->childs.push_back(node);
						
			while (it != v.end()) {

				if (isIncluded(node->node, *it)) {

					childs.push_back(*it);
					it = v.erase(it);
					
				}
				else
					it++;
			}

			getTrees(childs, node);
			it = v.begin();	
		}
	}


	return parentNode;
}



int getHeight(const NODE* root) {

	if (root == NULL || root->childs.empty() ) {
		return 1;
	}
	
	int val = -1;
	auto it = root->childs.begin();
	while (it != root->childs.end()) {
		val = std::max(getHeight(*it) + 1, val);
		it++;
	}
	
	return val;
}

const Node* getDeepestNode(const NODE* root,const int height, const int thisHeight) {

	if (height == thisHeight) {
		return root;
	}
	
	const Node* node = NULL;

	int val = -1;
	auto it = root->childs.begin();
	while (it != root->childs.end()) {
		if (node != NULL)
			break;
		node = getDeepestNode(*it, height, thisHeight + 1);
		it++;
	}

	return node;

}
//
//int fortress(const Node* node) {
//
//	/*if (node->root->childs.size() == 0)
//		return -1;
//*/
//	int val = -1;
//	auto it = node->root->childs.begin();
//	
//	while (it != node->root->childs.end()) {
//
//		if (*it != node) {
//			val = std::max<int>(getHeight(*it)+1, val);
//		}
//
//		it++;
//	}
//
//	if (node->root != node->root->root)
//		val = std::max(fortress(node->root) + 1, val);
//	
//
//	return val;
//}
//

int fortress(const Node* root) {

	vector<int> heights;
	int i = 0;
	FOR(i, root->childs.size()) {
		heights.push_back(fortress(root->childs[i]));
	}
	
	if (heights.size() == 0)
		return 0;

	sort(heights.begin(), heights.end());
	if (heights.size() >= 2)
		longest = std::max<int>(longest, 2 + heights[heights.size() - 2] + heights[heights.size() - 1]);


	return heights.back() + 1;
}

void remover(NODE* root) {

	if (root->childs.size() == 0) {
		delete root->node;
	}
	else {

		int i = 0;
		FOR(i, root->childs.size()) {
			remover(root->childs[i]);
			delete root->childs[i];
		}
		delete root->node;
	}
		
}

int main() {

	vector<int> result;

	int caseSize = 0;
	scanf("%d", &caseSize);

	int i = 0;
	FOR(i, caseSize) {

		longest = 0;
		int castleSize = 0;
		scanf("%d", &castleSize);

		vector<C*> castles;

		int l = 0;
		FOR(l, castleSize) {

			C *c = new C;
			scanf("%d %d %d", &c->x, &c->y, &c->r);
			castles.push_back(c);

		}

		sort(castles.begin(), castles.end(), comparator);
		
		Node node;
		node.root = &node;
		node.node = castles.at(0);
		castles.erase(castles.begin());

		Node *tree = getTrees(castles, &node);

		//int height = getHeight(tree);
		//const Node* deepestNode = getDeepestNode(tree, height, 1);

		int val = std::max<int>(fortress(tree), longest);
		result.push_back(val);
	
		//remover(tree);

	}

	i = 0;
	FOR(i, result.size()) {

		cout << result[i] << endl;

	}

	//_CrtDumpMemoryLeaks();

}
