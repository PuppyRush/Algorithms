#define _CRT_SECURE_NO_WARNINGS
#define FOR(i,size) for(i=0; i <size ; i++)

#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;



template <class type>
class FenwickTree {


private:

	vector<type> tree;

public:

	FenwickTree(int size);

	int rangeSum(int pos);
	void add(int pos, type newVal);

};


template <class type>
FenwickTree<type>::FenwickTree(int size) {
	this->tree.resize(size + 1);
}

template <class type>
int FenwickTree<type>::rangeSum(int pos) {

	++pos;
	int res = 0;

	while (pos > 0) {
		res += this->tree[pos];
		pos &= (pos - 1);
	}
	return res;
}


template <class type>
void FenwickTree<type>::add(int pos, type newVal) {

	++pos;
	const int size = this->tree.size();
	while (pos < size) {
		this->tree[pos] += newVal;
		pos += (pos & -pos);
	}

}
long long solve(const vector<int> src) {

	FenwickTree<int> tree(1000000);
	long long ret = 0;
	int i = 0;
	FOR(i, src.size()) {
		ret += tree.rangeSum(999999) - tree.rangeSum(src[i]);
		tree.add(src[i], 1);
	}
	return ret;
}
int main() {

	//p758
	vector<long long> result;

	int caseSize = 0;
	scanf("%d", &caseSize);

	int i = 0;
	FOR(i, caseSize) {

		int srcSize;
		
		scanf("%d", &srcSize);
		vector<int> src(srcSize);

		int l = 0;
		FOR(l, srcSize) {
			scanf("%d", &src[l]);
		}
		result.push_back(solve(src));
	}

	i = 0;
	FOR(i, result.size()) {
		cout << result[i] << " ";
	}
	
	return 0;
}

