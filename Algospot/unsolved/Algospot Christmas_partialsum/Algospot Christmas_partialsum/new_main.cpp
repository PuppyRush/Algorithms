#define _CRT_SECURE_NO_WARNINGS

#define ASCII_BEGIN_ZERO 33
#define ASCII_COUNT_ALPHABET 26
#define ASCII_BEGIN_a	 97
#define ASCII_BEGIN_A	 65




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

#undef INFINITY
#define INFINITY INT32_MIN
#define EMPTY INT32_MAX
#define EXIST INT32_MAX-7
int boxes;
int mans;
vector<int> dolls;
V2INT memo;
vector<int> sums;

bool compare(const VINT  &a, const VINT &b){
	return a.size() > b.size();
}

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

int IsValidatedRangedSum(const VINT &range, C_INT mans) {
	int accu = 0;
	int prev = 0, present = 0;
	int val = INFINITY;
	for(int i=0 ; i < range.size() ; i++, prev = present + 1){
		present = prev + (range[i] - 1);
		if (memo[prev][present] == INFINITY)
			continue;
		else if (memo[prev][present] == EXIST)
		{
			accu++;
			continue;
		}
		else if (memo[prev][present] == EMPTY)
			val = GetPartialSum(prev, present);
		
		if (val % mans == 0) {
			accu++;
			memo[prev][present] = EXIST;
		}
		else
			memo[prev][present] = INFINITY;
	}
	return accu;
}

long one(long count, int from, int to) {
	
	if (from >= boxes || to >= boxes)
		return count;
	if (from > to)
		return count;

	int val = INFINITY;
	if (memo[from][to] == EMPTY) {
		if ((val = GetPartialSum(from, to)) % mans == 0) {
			memo[from][to] = EXIST;
			count++;
		}
		else {
			memo[from][to] = INFINITY;
		}
	}

	count = one(count, from + 1, to);
	count = one(count, from, to + 1);
	return count;
}

int two(const V2INT range) {
	int val=INFINITY;
	for (auto it = range.begin(); it != range.end(); it++) {
		val = max(IsValidatedRangedSum(*it, mans), val);
		if (val >= it->size())
			break;
	}
	return val;
}


V2INT GetRange(VINT ary, C_INT boxes, C_INT begin, int sum) {

	if (sum == boxes) {
		return V2INT(1,ary);
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
		dolls = vector<int>(boxes);
		for (int i = 0; i < boxes; i++) {
			scanf("%d ", &dolls[i]);
		}
		memo = V2INT(boxes, VINT(boxes, EMPTY));
		sums = GetSum(dolls);
		auto range = GetRange(VINT(), boxes, 1,0);
		sort(range.begin(), range.end(), compare);

		int a = one(0,0,0)% 20091101L;
		int b = two(range);
		printf("%d %d\n", a, b);
	}

}