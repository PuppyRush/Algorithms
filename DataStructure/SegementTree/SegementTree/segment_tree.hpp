#pragma once

#include "segment_tree.h"

template <class type>
SegmentTree<type>::SegmentTree(vector<type> &srcAry, bool isMinimum, ElementComprator comp){
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
SegmentTree<type>::SegmentTree(type *srcAry, int elementSize, bool isMinimum, ElementComprator comp){
	::SegmentTree<type>(new vector<type>(srcAry), isMinimum, comp);
}

template <class type>
int SegmentTree<type>::init(int left, int right, int nodeIdx) {

	if (left == right)
		return resultAry[nodeIdx] = this->src[left];

	int mid = (left + right) / 2;
	return resultAry[nodeIdx] = returnValueComprator(init( left, mid, nodeIdx * 2), init( mid + 1, right, nodeIdx * 2 + 1),this->elementComprator);
}

template <class type>
int SegmentTree<type>::range(const int left,const int right) {
	return range_qurey(left, right, 1, 0, this->elementSize-1);
}

template <class type>
int SegmentTree<type>::range_qurey(const int left,const int right, int nodeIdx, int leftRange, int rightRange) {

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
	return returnValueComprator(_left,_right, this->elementComprator);
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
														update_qurey(mid+1, right, nodeIdx * 2+1, newValue, idx), this->elementComrator);
}