//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <vector>
//
//
//using namespace std;
//
//
//int rec(vector<vector<int>>& v, int x, int y, int size, int point) {
//
//	if (x < 0 || x >= size || y < 0 || y >= size)
//		return point;
//
//	if (x > 0 && v[x - 1][y] == 1) {
//		v[x - 1][y] = 0;
//		point += rec(v, x - 1, y, size, point+1);
//	}
//	if (x < size - 2 && v[x + 1][y] == 1) {
//		v[x + 1][y] = 0;
//		point += rec(v, x - 1, y, size, point+1);
//	}
//	if (y > 0 && v[x][y - 1] == 1) {
//		v[x][y - 1] = 0;
//		point += rec(v, x, y - 1, size, point+1);
//	}
//	if (y <size -2 && v[x][y + 1] == 1) {
//		v[x][y + 1] = 0;
//		point += rec(v, x, y + 1, size, point+1);
//	}
//	return point;
//}
//
//
//vector<int> solve(vector<vector<int>>& v, int size) {
//
//	vector<int> s;
//	for (int i = 0; i < size; i++) {
//		for (int l = 0; l < size; l++) {
//			if (v[i][l] == 1) {
//				s.push_back(rec(v, i, l, size, 0));
//			}
//		}
//	}
//	return s;
//}
//
//int main() {
//
//	int size;
//	scanf("%d", &size);
//	vector<vector<int>> vec;
//	for (int i = 0; i < size; i++) {
//		vector<int> v;
//		for (int l = 0; l < size; l++) {
//			int tmp;
//			scanf("%d ", &tmp);
//			v.push_back(tmp);
//		}
//		vec.push_back(v);
//	}
//	auto r = solve(vec, size);
//	return 0;
//}
