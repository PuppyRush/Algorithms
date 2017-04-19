#define _CRT_SECURE_NO_WARNINGS
#define FOR(i,size) for(i=0; i <size ; i++)

#include <iostream>
#include "segment_tree.h"
#include "tree.h"

using namespace std;

bool comparator(int a, int b) {
	return a < b;
}

int main() {

	//p743

	vector<int> result;

	int caseSize = 0;
	scanf("%d", &caseSize);

	int i = 0;
	FOR(i, caseSize) {

		int mans = 0;
		int size = 0;
		
		scanf("%d %d", &mans, &size);
		vector<int> src(mans);
		int l = 0;
		FOR(l, mans) {
			scanf("%d", &src[l]);
		}

		Tree tree(src);

		/*
		SegmentTree<int> minTree(src, true, comparator);
		SegmentTree<int> maxTree(src, false, comparator);*/

	}

	i = 0;
	FOR(i, result.size()) {
		cout << result[i] << " ";
	}


	return -1;
}