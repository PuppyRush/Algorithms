#define _CRT_SECURE_NO_WARNINGS

#define ASCII_BEGIN_ZERO 33
#define ASCII_COUNT_ALPHABET 26
#define ASCII_BEGIN_a	 97
#define ASCII_BEGIN_A	 65

#undef INFINITY
#define INFINITY INT32_MIN

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

#define EMPTY -1

int boxes;
int mans;
vector<int> dolls;
V2INT memo;
vector<int> sums;


vector<int> GetSum(vector<int> vec) {

	vector<int> sum(vec.size());
	sum[0] = vec[0];
	for (int i = 1; i < vec.size(); i++) {
		sum[i] = sum[i - 1] + vec[i];
	}
	return sum;

}

int GetPartialSum(int from, int to) {

	if (from == to)
		return dolls[from];
	else if (from == 0)
		return sums[to];

	return sums[to]-sums[from-1];
}


int isValidatedRangedSum(const VINT &range, C_INT mans) {
	int accu = 0;
	int prev = 0, present = 0;
	for(int i=0 ; i < range.size() ; i++){
		present = prev + (range[i] - 1);
		if (GetPartialSum(prev, present) % mans == 0)
			accu++;
		prev = present + 1;
		
	}
	return accu;
}


int one() {

	int count = 0;
	for (int to = 0; to < boxes; to++) {
		for (int from = 0; from <= to; from++)
			if ( GetPartialSum(from, to) % mans == 0) {
				count++;
			}
	}
	return count% 20091101;
}

int two(const V2INT range) {

	int val=INFINITY;
	auto it = range.begin();
	while (it != range.end()) {

		val = max(isValidatedRangedSum(*it, mans), val);

		it++;
	}

	return val;
}

V2INT GetRange(VINT ary, C_INT boxes, C_INT begin, int sum) {

	if (sum == boxes) {
		V2INT v2;
		v2.push_back(ary);
		return v2;
	}
	if (sum>boxes) {
		return V2INT();
	}

	V2INT v2;
	for (int box = 1; begin+box <= boxes+1; box++) {
		ary.push_back(box);
		auto val = GetRange(ary, boxes, begin + 1,sum+box);
		if(!val.empty())
			v2.insert(v2.end(), val.begin(), val.end());
		ary.pop_back();
	}
	return v2;
}

int main() {
	int caseSize = 0;
	scanf("%d", &caseSize);
	
	for (int i = 0; i < caseSize; i++) {
		
		scanf("%d %d", &boxes, &mans);
		vector<int> _dolls(boxes);
		for (int i = 0; i < boxes; i++) {
			scanf("%d ", &_dolls[i]);
		}
		memo = V2INT(boxes, VINT(boxes, EMPTY));
		dolls = _dolls;
		sums = GetSum(dolls);
		auto range = GetRange(VINT(), boxes, 1,0);

		int a = one();
		int b = two(range);
		cout << a << " " <<b << endl;
	}

}

