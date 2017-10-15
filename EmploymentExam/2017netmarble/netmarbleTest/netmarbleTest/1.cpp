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
//int solution(vector<int> s) {
//	int answer = 0;
//
//	int one = 0;
//	int two = 0;
//	int three = 0;
//	for each(int group in s) {
//		switch (group) {
//			case 1:
//				one++;
//				break;
//			case 2:
//				two++;
//				break;
//			case 3:
//				three++;
//				break;
//			case 4:
//				answer++;
//				break;
//		}
//	}
//
//	//
//	
//	if (one>=4) {
//		int temp = one / 4;
//		answer += temp;
//		one -= temp * 4;
//	}
//	if (two>=2) {
//		int temp = two / 2;
//		answer += temp;
//		two -= temp * 2;
//	}
//	if (three && one) {
//		if (three >= one) {
//			three -= one;
//			answer += one;
//			one = 0;
//		}
//		else {
//			if (three > one) {
//				one -= three;
//				answer += three;
//				three = 0;
//			}
//		}
//	}
//
//	if (three && two)
//		answer += 2;
//	else if (two && one)
//		answer += 1;
//
//	return answer;
//}
////[2,3,4,4,2,1,3,1]
//int main() {
//
//	VINT s;
//	s.push_back(2);
//	s.push_back(3);
//	s.push_back(4);
//	s.push_back(4);
//	s.push_back(2);
//	s.push_back(1);
//	s.push_back(3);
//	s.push_back(1);
//	cout << solution(s);
//
//}