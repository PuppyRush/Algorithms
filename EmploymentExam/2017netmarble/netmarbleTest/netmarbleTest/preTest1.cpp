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
//int main() {
//
//	int start=0, end=0;
//	scanf("%d %d", &start, &end);
//
//	VINT v;
//	for (int i = start; i <= end; i++) {
//		if (i / 10 < 0)
//		{
//			v.push_back(i);
//			continue;
//		}
//		auto buf = new char[10];
//		sprintf(buf, "%d", i);
//		auto str = string(buf);
//		auto half = str.size() / 2;
//	
//		int swt = 0;
//		if (half % 2 == 1)
//			swt = 1;
//
//		auto lo = string(str.begin(), str.begin() + half);
//		auto hi = string(str.begin()+half+swt, str.end());
//
//		reverse(hi.begin(), hi.end());
//		if (lo.compare(hi) == 0)
//			v.push_back(i);
//	}
//
//
//
//}