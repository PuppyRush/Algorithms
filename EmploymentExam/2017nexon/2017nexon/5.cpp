//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <sstream>
//#include <cstring>
//#include <cmath>
//#include <algorithm>
//#include <vector>
//#include <map>
//#include <stack>
//#include <bitset>
//#include <algorithm>
//#include <functional>   // std::multiplies
//#include <numeric>      // std::partial_sum
//#include <set>
//#include <queue>
//
//using namespace std;
//
//typedef const int C_INT;
//typedef const unsigned int C_UINT;
//typedef const unsigned char C_UCHAR;
//typedef const char C_CHAR;
//typedef const unsigned long long C_ULL;
//typedef unsigned int UINT;
//typedef unsigned char UCHAR;
//typedef unsigned long long ULL;
//typedef unsigned long UL;
//typedef std::vector<std::stack<int>> S2INT;
//typedef std::stack<int> SINT;
//typedef std::stack<char> SCHAR;
//typedef std::vector<std::vector<int>> V2INT;
//typedef std::vector<int> VINT;
//typedef std::vector<std::vector<string>> V2STR;
//typedef std::vector<string> VSTR;
//typedef std::vector<std::vector<char>> V2CHAR;
//typedef std::vector<char> VCHAR;
//typedef long long LL;
//
//int solve( V2INT &ary, C_INT arySize) {
//
//	vector<long long> vec(arySize, 0);
//	for (auto it = ary.begin(); it != ary.end(); it++) {
//
//		const auto _ary = *it;
//		const auto sums = _ary[2];
//		for (int i = _ary[0]; i <= _ary[1]; i++) {
//			vec[i] += sums;
//		}
//	}
//	return *max_element(vec.begin(), vec.end());
//}
//
//int main() {
//
//
//	int arySize = 0;
//	int caseSize = 0;
//	scanf("%d %d", &arySize, &caseSize);
//	
//	V2INT v2(caseSize, VINT());
//	for (int i = 0; i < caseSize; i++) {
//
//		int start = 0, end, sums = 0;
//		scanf("%d %d %d", &start, &end, &sums);
//		VINT ary(3);
//		ary[0] = start - 1;
//		ary[1] = end - 1;
//		ary[2] = sums;
//		v2[i] = ary;
//	}
//
//	cout << solve(v2, arySize);
//
//
//	return 0;
//}