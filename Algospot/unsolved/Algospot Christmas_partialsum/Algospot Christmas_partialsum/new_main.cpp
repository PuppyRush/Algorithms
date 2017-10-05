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


int one() {

	int count = 0;
	for (int to = 0; to < boxes; to++) {
		for (int from = 0; from <= to; from++)
			if ( GetPartialSum(from, to) % mans == 0) {
				count++;
				cout << "from:" << from << "to:" << to << endl;
			}
	}
	return count;
}

int two(const int from, const int to, int count) {

	if (from >= boxes || to >= boxes) {
		return count;
	}
	if (from > to)
		return count;

	int val = INFINITY;
	if (memo[from][to] != EMPTY)
		return count;
	else {
		val = memo[from][to] = GetPartialSum(from, to);
	}

	if (val%mans == 0) {
		count++;
		cout << "from:" << from << "to:" << to << endl;
	}

	return max(two(from, to + 1, count), two(from + 1, to, count));
}


int main() {
	int caseSize = 0;
	scanf_s("%d", &caseSize);
	
	for (int i = 0; i < caseSize; i++) {
		
		scanf_s("%d %d", &boxes, &mans);
		vector<int> _dolls(boxes);
		for (int i = 0; i < boxes; i++) {
			scanf_s("%d ", &_dolls[i]);
		}
		memo = V2INT(boxes, VINT(boxes, EMPTY));
		dolls = _dolls;
		sums = GetSum(dolls);

		int a = one();
		cout << "----" << endl;
		int b = two(0, 0, 0);
		cout << "----" << endl;
		cout << a << " " <<b << endl;
	}

}

