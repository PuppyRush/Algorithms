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
//bool IsMatch(string str)
//{
//	SCHAR t;
//	int i, len = str.size();
//
//	for each(char ch in str)
//	{
//		switch (ch)
//		{
//		case '(':
//		case '[':
//		case '{':
//			t.push(ch);
//			break;
//		case ')':
//		case ']':
//		case '}':
//			if(t.empty()) return false;
//			else
//			{
//				char open_ch = t.top();
//				t.pop();
//
//				if ((open_ch == '(' && ch != ')') ||
//					(open_ch == '[' && ch != ']') ||
//					(open_ch == '{' && ch != '}'))
//				{
//					return false;
//				}
//			}
//			break;
//		}
//	}
//
//	if (!t.empty())
//		return false;
//
//	return true;
//}
//
//void Get(string basic, SCHAR left, SCHAR right, vector<string>& complete){
//
//	if (right.empty()) {
//		if (left.empty())
//			return;
//		while (!left.empty()) {
//			basic.push_back(left.top());
//			left.pop();
//		}
//		if(IsMatch(basic))
//			complete.push_back(basic);
//		return;
//	}
//	if (left.empty()) {
//		while (!right.empty()) {
//			basic.push_back(right.top());
//			right.pop();
//		}
//		if (IsMatch(basic))
//			complete.push_back(basic);;
//		return;
//	}
//		
//
//	basic.push_back(right.top());
//	right.pop();
//	Get(basic, left, right, complete);
//	basic.pop_back();
//	right.push(')');
//
//	basic.push_back(left.top());
//	left.pop();
//	Get(basic, left, right, complete);
//	basic.pop_back();
//	left.push('(');
//}
//
//vector<string> solution(int N)
//{
//	vector<string> answer = {};
//
//	for (int i = 1; i <= N; i++) {
//		string str(i, '(');
//		SCHAR left;
//		for (int l = 0; l < N - 1; l++) {
//			left.push('(');
//		}
//		SCHAR right;
//		for (int l = 0; l < N; l++) {
//			right.push(')');
//		}
//		
//		Get(str, left, right, answer);
//	}
//	sort(answer.begin(), answer.end(), [](const string& c1, const string& c2) {return c1.compare(c2) < 0; });
//	return answer;
//}
//
//int main() {
//	solution(3);
//}