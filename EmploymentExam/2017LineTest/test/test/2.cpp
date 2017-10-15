//#define _CRT_SECURE_NO_WARNINGS
//
//#define ASCII_BEGIN_ZERO 33
//#define ASCII_COUNT_ALPHABET 26
//#define ASCII_BEGIN_a	 97
//#define ASCII_BEGIN_A	 65
//
//#include <iostream>
//#include <cstring>
//#include <cmath>
//#include <algorithm>
//#include <vector>
//#include <map>
//#include <bitset>
//#include <set>
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
//typedef std::vector<std::vector<int>> V2INT;
//typedef std::vector<int> VINT;
//typedef std::vector<std::vector<string>> V2STR;
//typedef std::vector<string> VSTR;
//typedef std::vector<std::vector<char>> V2CHAR;
//typedef std::vector<char> VCHAR;
//typedef long long LL;
//
//set<int> s;
//int solve(const LL size,int count) {
//
//	if (size <= 1)
//		return count;
//	
//	for(int i=1 ; i <= 10 ; i++){
//		auto v = size / i;
//		auto val = size%i;
//		if (val == 0 && (s.count(v)==0 && s.count(i)==0))
//		{
//			s.insert(v);
//			s.insert(i);
//			if (i == v)
//				count += 1;
//			else
//				count += 2;
//			count = solve(size / i, count);
//		}
//	}
//	return count;
//}
//
//int main() {
//	
//
//	LL size = 0;
//	scanf("%lld", &size);
//	
//	if (size == 1)
//		cout << 1;
//	else {
//		int count = 0;
//		cout << solve(size, count);
//		
//	}
//}