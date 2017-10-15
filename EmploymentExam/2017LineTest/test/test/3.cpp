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
//#define PEG_MAX_SIZE 3
//#define DISK_MAX_SIZE 20
//
//using namespace std;
//
///*
//* Description :
//* Time complexity :
//* Space complexity :
//*/
//
//int COUNT;
//int hanoi(S2INT s,int from, int to, int count) {
//
//	bool finish = any_of(s.begin(), s.end(), [](SINT s) {return s.size() == COUNT ? true : false; });
//	if (finish)
//		return count;
//
//	if (from >= 3 || to >= 3 || s[from].empty() || from==to)
//		return INT_MAX;
//
//	if (s[from].top() > s[to].top()) {
//		s[to].push(s[from].top());
//		s[from].pop();
//		count++;
//	}
//
//	int lo = hanoi(s, from + 1, to, count);
//	int hi = hanoi(s, from, to + 1, count);
//	if (lo == INT_MAX && hi == INT_MAX)
//		return count;
//	else if (lo == INT_MAX)
//		return hi;
//	else if (hi == INT_MAX)
//		return lo;
//	else
//		return min(lo, hi);
//}
//
//int main(int argc, const char *argv[]) {
//	
//	S2INT ary;
//	COUNT = 0;
//	for (int i = 0; i < PEG_MAX_SIZE; i++) {
//		
//		string line;
//		getline(cin, line);
//		if (line.length() == 0) {
//			continue;
//		}
//
//		int j = 0;
//		size_t last = 0;
//		size_t next = 0;
//		SINT vec;
//		while ((next = line.find(' ', last)) != string::npos) {
//			int len = next - last;
//			if (len) {
//				vec.push(stoi(line.substr(last, len)));
//				COUNT++;
//			}
//			last = next + 1;
//		}
//
//		string lastNumber = line.substr(last);
//		if (!lastNumber.empty()) {
//			vec.push(stoi(lastNumber));
//			COUNT++;
//		}
//		ary.push_back(vec);
//	}
//
//	int count = 0;
//	for (int i = 0; i < 3; i++)
//		for (int l = 0; l < 3; l++)
//			count = min(hanoi(ary, i, l,count),count);
//
//	cout << count << endl;
//}