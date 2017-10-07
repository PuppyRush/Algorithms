#pragma once

#include <vector>
#include <algorithm>

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