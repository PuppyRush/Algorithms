#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <sstream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>   // std::multiplies
#include <numeric>      // std::partial_sum
#include <set>
#include <queue>
#include <deque>
#include <unordered_map>

using namespace std;

typedef const int& C_INT;
typedef const unsigned int& C_UINT;
typedef const unsigned char& C_UCHAR;
typedef const char& C_CHAR;
typedef const unsigned long long& C_ULL;
typedef unsigned int UINT;
typedef unsigned char UCHAR;
typedef unsigned long long ULL;
typedef unsigned long UL;
typedef std::vector<std::stack<int>> S2INT;
typedef std::stack<int> SINT;
typedef std::stack<char> SCHAR;
typedef std::vector<std::vector<int>> V2INT;
typedef std::vector<int> VINT;
typedef std::deque<int> DINT;
typedef std::vector<std::vector<string>> V2STR;
typedef std::vector<string> VSTR;
typedef std::vector<std::vector<char>> V2CHAR;
typedef std::vector<char> VCHAR;
typedef std::pair<int, int> PINT;
typedef long long LL;

#pragma once

#include <vector>
#include <algorithm>

using namespace std;


typedef bool(*ElementComprator)(C_INT a, C_INT b);

template <class type>
class SegmentTree {


	typedef const type& (*ReturnValueComprator)(const type&, const type&, ElementComprator comp);

private:

	ReturnValueComprator returnValueComprator;
	ElementComprator elementComprator;
	vector<type> src;

public:

	bool isMinimum;
	size_t elementSize;
	vector<type> resultAry;

public:

	explicit SegmentTree(vector<type> &srcAry, bool isMinimum, ElementComprator comp);
	explicit SegmentTree(type *srcAry, int elementSize, bool isMinimum, ElementComprator comp);

	int kth(const int k);
	int range(const int left, const int right);
	int update(const int newValue, const int Idx);

private:

	explicit SegmentTree() {};
	//void operator=(const SegmentTree &s) {}
	//explicit SegmentTree(const SegmentTree &s) {}

	int init(int left, int right, int nodeIdx);
	int kth_qurey(const int k, const int count,const int nodeIdx);
	int range_qurey(const int left, const int right, int nodeIdx, int leftRange, int rightRange);
	int update_qurey(int left, int right, int nodeIdx, const int newValue, const int idx);

};

template <class type>
SegmentTree<type>::SegmentTree(vector<type> &srcAry, bool isMinimum, ElementComprator comp) {
	this->elementComprator = comp;
	this->isMinimum = isMinimum;
	if (this->isMinimum)
		returnValueComprator = std::min<int>;
	else
		returnValueComprator = std::max<int>;

	src = srcAry;
	resultAry.resize(srcAry.size() * 4);
	this->elementSize = srcAry.size();
	init(0, srcAry.size() - 1, 1);
}


template <class type>
SegmentTree<type>::SegmentTree(type *srcAry, int elementSize, bool isMinimum, ElementComprator comp) {
	::SegmentTree<type>(new vector<type>(srcAry), isMinimum, comp);
}

template <class type>
int SegmentTree<type>::init(int left, int right, int nodeIdx) {

	if (left == right)
		return resultAry[nodeIdx] = this->src[left];

	int mid = (left + right) / 2;
	return resultAry[nodeIdx] = returnValueComprator(init(left, mid, nodeIdx * 2), init(mid + 1, right, nodeIdx * 2 + 1), this->elementComprator);
}

template <class type>
int SegmentTree<type>::kth(const int kth) {
	return kth_qurey(kth, 1,1);
}

template <class type>
int SegmentTree<type>::kth_qurey(const int kth,const int count, const int nodeIdx) {
	if (kth == count)
		return resultAry[nodeIdx];

	return resultAry[nodeIdx  * 2] > resultAry[nodeIdx * 2 + 1] ? kth_qurey(kth, count + 1, nodeIdx * 2) : kth_qurey(kth, count + 1, nodeIdx * 2 + 1);
}

template <class type>
int SegmentTree<type>::range(const int left, const int right) {
	return range_qurey(left, right, 1, 0, this->elementSize - 1);
}

template <class type>
int SegmentTree<type>::range_qurey(const int left, const int right, int nodeIdx, int leftRange, int rightRange) {

	if (left > rightRange || right < leftRange) {
		if (this->isMinimum)
			return INT32_MAX;
		else
			return -1;
	}
	else if (left <= leftRange && right >= rightRange)
		return this->resultAry[nodeIdx];

	int mid = (leftRange + rightRange) / 2;
	int _left = range_qurey(left, right, nodeIdx * 2, leftRange, mid);
	int _right = range_qurey(left, right, nodeIdx * 2 + 1, mid + 1, rightRange);
	return returnValueComprator(_left, _right, this->elementComprator);
}

template <class type>
int SegmentTree<type>::update(const int newValue, const int idx) {
	update_qurey(0, this->elementSize - 1, 1, newValue, idx);
}

template <class type>
int SegmentTree<type>::update_qurey(int left, int right, int nodeIdx, const int newValue, const int idx) {

	if (nodeIdx < left || nodeIdx > right)
		return this->resultAry[nodeIdx];
	else if (nodeIdx == left && nodeIdx == right) {
		return this->resultAry[nodeIdx] = newValue;
	}

	int mid = (left + right) / 2;
	return this->resultAry[nodeIdx] = returnValueComprator(update_qurey(left, mid, nodeIdx * 2, newValue, idx),
		update_qurey(mid + 1, right, nodeIdx * 2 + 1, newValue, idx), this->elementComrator);
}


DINT solve(DINT v) {

	if (v.size() == 1)
		return v;

	C_INT half = v.size() / 2;
	auto lhs = DINT(v.begin(), v.begin() + half);
	auto rhs = DINT(v.begin() + half , v.end());

	auto sorted_lhs = solve(lhs);
	auto sorted_rhs = solve(rhs);

	int i = 0;
	auto sorted = DINT();
	while (!sorted_lhs.empty() && !sorted_rhs.empty()) {
		if (sorted_lhs.front() < sorted_rhs.front()) {
			sorted.push_back(sorted_lhs.front());
			sorted_lhs.pop_front();
		}
		else {
			sorted.push_back(sorted_rhs.front());
			sorted_rhs.pop_front();
		}
	}
	if (!sorted_lhs.empty()) {
		sorted.insert(sorted.end(), sorted_lhs.begin(), sorted_lhs.end());
	}
	else {
		sorted.insert(sorted.end(), sorted_rhs.begin(), sorted_rhs.end());
	}
	return sorted;
}

int main() {

	int size=0, count=0;
	scanf("%d %d", &size, &count);

	VINT v = VINT(size, 0);
	for (int i = 0; i < size; i++)
		scanf("%d ", &v[i]);

	for (int i = 0; i < count; i++) {
		int begin = 0, end = 0, kth = 0;
		scanf("%d %d %d", &begin, &end, &kth);
		auto st = SegmentTree<int>( v, true, [](C_INT l, C_INT r)->bool{return l > r; });
		cout << st.kth(kth) << endl;
	}

}

