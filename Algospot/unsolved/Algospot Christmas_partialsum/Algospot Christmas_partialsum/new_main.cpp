#define _CRT_SECURE_NO_WARNINGS
#define MIN(a,b) (a>b?b:a)

#define ASCII_BEGIN_ZERO 33
#define ASCII_COUNT_ALPHABET 26
#define ASCII_BEGIN_a	 97
#define ASCII_BEGIN_A	 65

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
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



int one(int boxes, int mans, vector<int> dolls) {



}

int two(int boxes, int mans, vector<int> dolls) {



}

vector<int> GetSum(vector<int> vec) {

	vector<int> sum(vec.size());
	sum[0] = vec[0];
	for (int i = 1; i < vec.size(); i++) {
		sum[i] = sum[i - 1] + vec[i];
	}
	return sum;

}

int GetPartialSum(int i, int j) {



}

vector<int> sums;

int main() {
	int caseSize = 0;
	scanf_s("%d", &caseSize);
	
	for (int i = 0; i < caseSize; i++) {
		int boxes = 0, mans = 0;
		vector<int> dolls(boxes);
		scanf_s("%d %d", &boxes, &mans);
		for (int i = 0; i < boxes; i++) {
			scanf_s("%d ", &dolls[i]);
		}
		sums = GetSum(dolls);
		int a = one(boxes, mans, dolls);
		int b = two(boxes, mans, dolls);
	}

}

