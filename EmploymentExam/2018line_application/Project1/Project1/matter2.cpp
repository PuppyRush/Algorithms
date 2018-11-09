//#include <cassert>
//#include <list>
//#include <map>
//#include <queue>
//#include <set>
//#include <stack>
//#include <unordered_map>
//#include <unordered_set>
//#include <vector>
//#include <algorithm>
//#include <type_traits>
//#include <bitset>
//#include <iterator>
//#include <limits>
//#include <locale>
//#include <memory>
//#include <numeric>
//#include <regex>
//#include <string>
//#include <tuple>
//#include <utility>
//#include <iostream>
//using namespace std;
//#define _CRT_SECURE_NO_WARNINGS
//int main()
//{
//	string _lhs, _rhs;
//	cin >> _lhs;
//	cin >> _rhs;
//
//	if (_lhs.size() != _rhs.size())
//	{
//		assert(0);
//		return 0;
//	}
//
//	vector<char> lhs(_lhs.begin(), _lhs.end());
//	vector<char> rhs(_rhs.begin(), _rhs.end());
//	
//	vector<char> lball;
//	lball.reserve(lhs.size());
//	vector<char> rball;
//	rball.reserve(rhs.size());
//
//	size_t ballcnt = 0;
//	size_t strikecnt =0;
//
//	for (auto lit = lhs.begin(), rit = rhs.begin()
//		; lit != lhs.end() || rit != rhs.end()
//		; lit++, rit++)
//	{
//		if (*lit == *rit)
//		{
//			strikecnt++;
//		}
//		else
//		{
//			lball.push_back(*lit);
//			rball.push_back(*rit);
//		}
//	}
//
//	unordered_set<char> balls(lball.begin(), lball.end());
//	for (const auto ball : rball)
//	{
//		if (balls.count(ball) > 0)
//			ballcnt++;
//	}
//
//
//	string answer;
//	answer.reserve(100);
//	if (strikecnt>0)
//	{
//		char buf[10];
//		std::fill(buf, buf + sizeof(char) * 10, 0);
//		sprintf_s(buf,"%dS",strikecnt);
//		answer.append(buf);
//	}
//	if (ballcnt>0)
//	{
//		char buf[10];
//		std::fill(buf, buf + sizeof(char) * 10, 0);
//		sprintf_s(buf, "%dB", ballcnt);
//		answer.append(buf);
//	}
//	
//	if (strikecnt == 0 || ballcnt ==0)
//		cout << "out";
//	else
//		cout << answer.c_str();
//
//}