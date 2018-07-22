#pragma once

#include <vector>
#include <algorithm>

using namespace std;


typedef bool(*ElementComprator)(int a, int b);

template <class type>
class SegmentTree{

	
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

	SegmentTree(vector<type> &srcAry, bool isMinimum, ElementComprator comp);
	SegmentTree(type *srcAry,int elementSize, bool isMinimum, ElementComprator comp);

	int range(const int left, const int right);
	int update(const int newValue, const int Idx);

private:

	SegmentTree() {};
	int init(int left, int right, int nodeIdx);
	int range_qurey(const int left,const int right, int nodeIdx, int leftRange, int rightRange);
	int update_qurey(int left, int right, int nodeIdx, const int newValue, const int idx);

};