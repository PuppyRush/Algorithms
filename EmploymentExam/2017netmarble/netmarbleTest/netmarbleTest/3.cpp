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
//vector<int> solution(int MANS, vector<string> words) {
//	vector<int> answer;
//
//	auto game = V2STR();
//	int i = 0;
//	VSTR round;
//	for (auto it = words.begin(); it != words.end(); it++) {
//		round.push_back(*it);
//		i++;
//		if (i == MANS) {
//			game.push_back(round);
//			round.clear();
//			i = 0;
//		}
//
//	}
//
//	string preStr = string(1, game[0][0].back());
//	std::set<string> wordCheck;
//	C_INT ROUND = game.size();
//	for (int l = 0; l < ROUND; l++)
//		for (int i = 0; i < MANS - 1; i++) {
//
//			if (game[l].size() == i) {
//				l = ROUND;
//				break;
//			}
//
//			auto pre = game[l][i];
//			auto next = game[l][i + 1];
//
//			if (l>0 && i==0 && preStr.back() != pre.front()) {
//				answer.push_back(i + 1);
//				answer.push_back(l + 2);
//				l = ROUND;
//				break;
//			}
//			else if (pre.back() != next.front()) {
//
//				answer.push_back(i + 1);
//				answer.push_back(l + 1);
//				l = ROUND;
//				break;
//			}
//			else if (wordCheck.count(pre) > 0) {
//				answer.push_back(i + 1);
//				answer.push_back(l + 1);
//				l = ROUND;
//				break;
//			}
//			else if (wordCheck.count(next) > 0) {
//
//				answer.push_back(i + 2);
//				answer.push_back(l + 1);
//				l = ROUND;
//				break;
//			}
//			else
//				wordCheck.insert(pre);
//
//			if (i == MANS - 2)
//				preStr = next;
//		}
//
//	if (answer.empty()) {
//		answer.push_back(0);
//		answer.push_back(0);
//	}
//
//	return answer;
//}
//
//
//int main() {
//	VSTR v;
//	v.push_back("tk");
//	v.push_back("kk");
//	v.push_back("kw");
//	v.push_back("wl");
//	v.push_back("ld");
//	v.push_back("dm");
//	v.push_back("mr");
//	v.push_back("rt");
//	v.push_back("tk");
//	solution(3, v);
//}