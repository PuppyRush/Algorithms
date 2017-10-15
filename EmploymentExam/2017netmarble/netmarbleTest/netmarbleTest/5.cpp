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
//
//V2INT CHANGE(V2INT matrix, int begin,C_INT size) {
//	
//	V2INT temp = matrix;
//
//	C_INT row = begin, height = begin;
//	int gap = size - begin * 2 - 1;
//	C_INT row_end = row + gap, height_end = height + gap;
//
//	for (int r = row,h=height; r <= row_end, h <= height_end; r++,h++) {
//		matrix[h][row_end] = temp[height][r];
//	}
//
//	for (int r = row_end, h = height; r >= row , h <= height_end; r--, h++) {
//		matrix[height_end][r] = temp[h][row_end];
//	}
//
//	for (int r = row_end, h = height_end; r >= row, h >= height; r--, h--) {
//		matrix[h][row] = temp[height_end][r];
//	}
//
//	for (int r = row, h = height_end; r <= row_end, h >= height; r++, h--) {
//		matrix[height][r] = temp[h][row];
//	}
//	return matrix;
//}
//
//vector<vector<int>> solution(vector<vector<int>> matrix, int r) {
//	
//	r %= 4;
//	auto size = matrix.size();
//	for (int i = 0; i < r; i++)
//		for (int idx = 0; idx < size / 2; idx++)
//			matrix = CHANGE(matrix, idx, size);
//	
//	return matrix;
//	
//}
//int main() {
//	V2INT ary;
//	VINT a;
//	a.push_back(1);
//	a.push_back(2);
//	ary.push_back(a);
//	a.clear();
//	a.push_back(3);
//	a.push_back(4);
//	ary.push_back(a);
//	solution(ary, 1);
//}