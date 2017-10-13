//#define _CRT_SECURE_NO_WARNINGS
//
//#define ASCII_BEGIN_ZERO 33
//#define ASCII_COUNT_ALPHABET 26
//#define ASCII_BEGIN_a	 97
//#define ASCII_BEGIN_A	 65
//#define ASCII_CASE_GAP	(ASCII_BEGIN_a - ASCII_BEGIN_A)
//
//
//
//#include <iostream>
//#include <cstring>
//#include <cmath>
//#include <algorithm>
//#include <vector>
//#include <map>
//#include <bitset>
//#include <algorithm>
//#include <functional>   // std::multiplies
//#include <numeric>      // std::partial_sum
//#include <deque>
//#include <queue>
//#include <regex>
//#include <set>
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
//
//typedef vector<pair<char, char>> PAIR;
//
//PAIR GetSet(string str) {
//
//	PAIR v;
//	bool isChar = false;
//	deque<char> q;
//	for each(char c in str) {
//		if (c >= 'a' && c <= 'z'){
//			q.push_back(c);
//		}
//		else if (c >= 'A' && c <= 'Z') {
//			q.push_back(c + ASCII_CASE_GAP);
//		}
//		else {
//			q.clear();
//		}
//		if (q.size() == 2) {
//			v.push_back(make_pair(q[0], q[1]));
//			q.pop_front();
//		}
//	}
//	return v;
//}
//
//int GetZ(PAIR &pair1, PAIR &pair2) {
//
//	std::multiset< pair<char, char>> p1, p2;
//
//	for each(auto p in pair1) {
//		p1.insert(p);
//	}
//	for each(auto p in pair2) {
//		p2.insert(p);
//	}
//	const auto size = p1.size() + p2.size();
//	vector<pair<char, char>> v(size);
//	auto it =set_union(p1.begin(), p1.end(), p2.begin(), p2.end(), v.begin());
//	v.resize(it - v.begin());
//	float sum = v.size();
//
//	v.clear();
//	v.resize(size);
//	it = set_intersection(p1.begin(), p1.end(), p2.begin(), p2.end(), v.begin());
//	v.resize(it - v.begin());
//	float intersection = v.size();
//
//	if (intersection == 0)
//		return 65536;
//	else
//		return 65536 * (intersection/sum);
//}
//
//int main() {
//
//	auto buf1 = new char(1000);
//	auto buf2 = new char(1000);
//
//	scanf("%s %s", buf1, buf2);
//
//	string str1(buf1);
//	string str2(buf2);
//
//	auto set1 = GetSet(str1);
//	auto set2 = GetSet(str2);
//
//	cout << GetZ(set1, set2);
//}