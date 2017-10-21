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
//#include <set>
//#include <queue>
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
///*
//* Complete the function below.
//*/
//int countDuplicates(vector <int> numbers) {
//
//	auto check = vector<int>(1001, 0);
//	auto indexes = set<int>();
//	for (auto it = numbers.begin(); it != numbers.end(); it++) {
//		check[*it]++;
//		indexes.insert(*it);
//	}
//
//	int val = 0;
//	for (auto it = indexes.begin(); it != indexes.end(); it++) {
//		if (check[*it] == 1)
//			val++;
//	}
//	return val;
//}
//
//
//int main() {
//	vector<int> a;
//	a.push_back(8);
//	a.push_back(1);
//	a.push_back(3);
//	a.push_back(1);
//	a.push_back(4);
//	a.push_back(5);
//	a.push_back(6);
//	a.push_back(3);
//	a.push_back(2);
//
//	countDuplicates(a);
//}