#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
typedef std::vector<int> VINT;
int GetBiggerSize(int l, int r) {
	int big, small;
	big = l > r ? l : r;
	small = l > r ? r : l;
	return small * 2 > big ? small * 2 : big;

}
int solve(VINT fence, int size) {
	switch (fence.size()) {
	case 0:
		return size;
	case 1:
		return fence[0];
	case 2:
		return GetBiggerSize(fence[0], fence[1]);
	}
	auto half = fence.size() / 2;
	auto lo = VINT(fence.begin(), fence.begin() + half);
	auto hi = VINT(fence.begin() + half, fence.end());
	int left = solve(lo, size);
	int right = solve(hi, size);
	
	if (lo.back() == 0 || hi.front()==0) {
		return max(lo.back(), hi.front());
	}
	return GetBiggerSize(left, right);
}
int main() {
	int caseSize = 0;
	scanf("%d", &caseSize);
	for (int i = 0; i < caseSize; i++) {
		int fenceSize = 0;
		scanf("%d", &fenceSize);
		VINT fence(fenceSize);
		for (int l = 0; l < fenceSize; l++) {
			scanf("%d", &fence[l]);
		}
		cout << solve(fence, 0) << endl;
	}
}