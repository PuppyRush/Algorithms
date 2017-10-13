#define _CRT_SECURE_NO_WARNINGS

#define ASCII_BEGIN_ZERO 33
#define ASCII_COUNT_ALPHABET 26
#define ASCII_BEGIN_a	 97
#define ASCII_BEGIN_A	 65
#define ASCII_CASE_GAP	(ASCII_BEGIN_a - ASCII_BEGIN_A)

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <bitset>
#include <algorithm>
#include <functional>   // std::multiplies
#include <numeric>      // std::partial_sum
#include <deque>
#include <queue>
#include <regex>
#include <set>
using namespace std;

typedef const int C_INT;
typedef const unsigned int C_UINT;
typedef const unsigned char C_UCHAR;
typedef const char C_CHAR;
typedef const unsigned long long C_ULL;
typedef unsigned int UINT;
typedef unsigned char UCHAR;
typedef unsigned long long ULL;
typedef unsigned long UL;
typedef std::vector<std::vector<int>> V2INT;
typedef std::vector<int> VINT;
typedef std::vector<std::vector<string>> V2STR;
typedef std::vector<string> VSTR;
typedef std::vector<std::vector<char>> V2CHAR;
typedef std::vector<char> VCHAR;

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