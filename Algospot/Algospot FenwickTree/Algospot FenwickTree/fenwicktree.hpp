#pragma once

#include "fenwicktree.h"

template <class type>
FenwickTree<type>::FenwickTree(int size) {
	this->tree.resize(size+1);
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
