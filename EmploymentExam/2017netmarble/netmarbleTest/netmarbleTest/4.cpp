//#define _CRT_SECURE_NO_WARNINGS
//
//
//#include <iostream>
//#include <sstream>
//#include <cstring>
//#include <cmath>
//#include <algorithm>
//#include <vector>
//#include <map>
//#include <stack>
//#include <set>
//#include <queue>
//#include <bitset>
//#include <algorithm>
//#include <functional>   // std::multiplies
//#include <numeric>      // std::partial_sum
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
//using namespace std;
//
//
//int solution(int l, vector<int> v) {
//	int answer = 0;
//
//	int max = 0;
//	sort(v.begin(), v.end());
//	for (int i = 0; i < v.size()-1; i++) {
//
//		int gap = v[i + 1] - v[i];
//		if (max < gap) {
//			max = gap;
//		}
//	}
//
//	return max % 2==0?max/2:max/2-1;
//}
//int main() {
//	VINT v;
//	v.push_back(2);
//	v.push_back(5);
//	solution(5, v);
//}