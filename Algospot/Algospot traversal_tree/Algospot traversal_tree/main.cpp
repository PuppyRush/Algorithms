#define _CRT_SECURE_NO_WARNINGS
#define FOR(l,size) for(l ; l < size ; ++l)

#include <iostream>
#include <vector>
#include <string.h>
#include <deque>

using namespace std;

void makePostOrder(vector<int> pre, vector<int> in, vector<int> &post);
vector<int> gettingVectorFromValue(vector<int> &v, int begin, int value);


int main() {

	vector<vector<int>> result;

	int caseSize = 0;
	scanf("%d", &caseSize);

	int i = 0;
	FOR(i, caseSize) {

		int nodeSize = 0;
		scanf("%d", &nodeSize);

		vector<int> preOrder;
		int l = 0;
		FOR(l, nodeSize) {
			int temp;
			scanf("%d", &temp);
			preOrder.push_back(temp);
		}

		vector<int> inOrder;
		l = 0;
		FOR(l, nodeSize) {
			int temp;
			scanf("%d", &temp);
			inOrder.push_back(temp);
		}

		vector<int> post;
		makePostOrder(preOrder, inOrder, post);

		result.push_back(post);
	}
	
	i = 0;
	FOR(i, result.size()) {

		auto v = result[i];
		auto it = v.begin();
		while (it != v.end()) {
			cout << *it << " ";
			it++;
		}
		cout << endl;

	}
}

void makePostOrder(vector<int> pre, vector<int> in, vector<int> &post) {

	if (pre.empty())
		return;
	else if (pre.size()==1) {
		post.push_back(pre[0]);
		return;
	}
	
	int root = pre.front();
	pre.erase(pre.begin());
	
	vector<int> in_leftSide = gettingVectorFromValue(in, 0, root);

	vector<int> pre_leftSide;
	pre_leftSide.insert(pre_leftSide.begin(), pre.begin(), pre.begin() + in_leftSide.size());
	pre.erase(pre.begin(), pre.begin() + pre_leftSide.size());

	makePostOrder(pre_leftSide, in_leftSide,post);

	vector<int> pre_rightSide;
	pre_rightSide.insert(pre_rightSide.begin(), pre.begin(), pre.end());

	vector<int> in_rightSide;
	in_rightSide.insert(in_rightSide.begin(), in.begin(), in.end());
	if (pre_rightSide.size()!= in_rightSide.size() &&  in_rightSide.size() > 0)
		in_rightSide.erase(in_rightSide.begin());

	makePostOrder(pre_rightSide, in_rightSide,post);

	post.push_back(root);

}

/*
exclude value
*/
vector<int> gettingVectorFromValue(vector<int> &v, int begin, int value) {
	
	vector<int> newVector;

	int size = 0;
	while (v[begin + size] != value) {
		newVector.push_back(v[begin + size]);
		size++;
	}

	if(size>0)
		v.erase(v.begin() + begin, v.begin() + (begin + size+1));

	return newVector;
}