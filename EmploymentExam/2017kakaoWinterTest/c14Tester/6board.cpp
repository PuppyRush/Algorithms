//#define _CRT_SECURE_NO_WARNINGS
//
//#define ASCII_BEGIN_ZERO 33
//#define ASCII_COUNT_ALPHABET 26
//#define ASCII_BEGIN_a	 97
//#define ASCII_BEGIN_A	 65
//
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
//#include <queue>
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
//
//
//#define EMPTY '0'
//V2INT board;
//
//template <class T>
//void print(const vector<vector<T>> &ary) {
//	for each(auto v in ary) {
//		for each(auto c in v)
//			cout << c << " ";
//		cout << endl;
//	}
//	cout << "------" << endl;
//}
//
//bool IsBlock(const V2CHAR &ary, C_INT x, C_INT y) {
//
//	C_CHAR c = ary[y][x];
//	if (c == EMPTY)
//		return false;
//
//	if (ary[y + 1][x] == c && ary[y][x + 1] == c && ary[y + 1][x + 1] == c)
//		return true;
//	return false;
//}
//
//void Fill(const V2CHAR &ary, C_INT x, C_INT y) {
//	board[y][x]++;
//	board[y+1][x]++;
//	board[y][x+1]++;
//	board[y+1][x+1]++;
//}
//
//void solver(const V2CHAR &ary, C_INT w, C_INT h, C_INT x, C_INT y) {
//
//	if (w - 1 <= x || h - 1 <= y)
//		return;
//
//	if (IsBlock(ary, x, y))
//		Fill(ary, x, y);
//
//	solver(ary, w, h, x + 1, y);
//	solver(ary, w, h, x, y + 1);
//}
//
//void Destroy(V2CHAR &ary, const V2INT block, C_INT w, C_INT h) {
//	
//	for (int y = 0; y < h; y++) {
//		for (int x = 0; x < w; x++) {
//			if (block[y][x] > 0) {
//				ary[y][x] = EMPTY;
//			}
//		}
//	}
//}
//
//void MoveDown(V2CHAR &ary, C_INT w, C_INT h) {
//
//	for (int x = 0; x < w; x++) {
//		queue<char> q;
//		for (int y = h - 1; y >= 0; y--) {
//			if (ary[y][x] != EMPTY)
//				q.push(ary[y][x]);
//		}
//		if (q.size() != h && q.size() != 0) {
//			int y = h - 1;
//			for (; !q.empty(); y--) {
//				ary[y][x] = q.front();
//				q.pop();
//			}
//			
//			for (; y >= 0; y--)
//				ary[y][x] = EMPTY;
//		}
//	}
//}
//
//int solve(V2CHAR &ary, C_INT w, C_INT h) {
//
//	
//	bool end = false;
//	int c = 0;
//	int count = 0;
//	do {
//		c = 0;
//		print(ary);
//
//		board = V2INT(h, VINT(w, 0));
//		solver(ary, w, h, 0, 0);
//		for each(auto v in board) {
//			c += count_if(v.begin(), v.end(), [&](const auto i) { return (i > 0 ? true : false); });
//		}
//		
//		if (c > 0) {
//			Destroy(ary, board,w,h);
//			print(board);
//			MoveDown(ary,w,h);
//			count += c;
//		}
//		print(ary);
//	} while (c > 0);
//
//	return count;
//}
//
//int main() {
//
//	std::map<char, bool> block;
//	int height=0, width=0;
//	scanf("%d %d ", &height, &width);
//
//	V2CHAR ary;
//
//	for (int i = 0; i < height; i++) {
//		VCHAR v;
//		for (int l = 0; l < width; l++) {
//			char c;
//			scanf("%c", &c);
//			block[c] = true;
//			v.push_back(c);
//
//		}
//		ary.push_back(v);
//	}
//	cout << solve(ary, width, height);
//
//}