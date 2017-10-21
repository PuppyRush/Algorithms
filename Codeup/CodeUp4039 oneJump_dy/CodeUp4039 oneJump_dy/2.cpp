#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <sstream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>   // std::multiplies
#include <numeric>      // std::partial_sum

using namespace std;

typedef const int C_INT;
typedef const unsigned int C_UINT;
typedef const unsigned char C_UCHAR;
typedef const char C_CHAR;
typedef const unsigned long long C_ULL;
typedef unsigned int UINT;
typedef unsigned char UCHAR;
typedef unsigned long long ULL;
typedef unsigned long UL;
typedef std::vector<bool> VBOOL;
typedef std::vector<std::stack<int>> S2INT;
typedef std::stack<int> SINT;
typedef std::vector<std::vector<int>> V2INT;
typedef std::vector<int> VINT;
typedef std::vector<std::vector<string>> V2STR;
typedef std::vector<string> VSTR;
typedef std::vector<std::vector<char>> V2CHAR;
typedef std::vector<char> VCHAR;
typedef long long LL;
#define INT_MAX 123456789
using namespace std;

stack<pair<int,int>> s;
int **maze;
int **visited;

inline V2INT DIR(int h, int w) {
	
}


bool result;
int solve(C_INT height, C_INT width, int h, int w, int exHigh) {

	if (result) {
		return s.size();
	}
	if (height - 1 == h && width - 1 == w)
	{
		s.push(make_pair(h, w));
		result = true;
		return s.size();
	}
	else if ( !(h==0 && w==0) && s.empty()) {
		result = true;
		return INT_MAX;
	}
	else if (h == -1 || w == -1 || h == height || w == width ){
		return INT_MAX;
	}
	else if (visited[h][w]) {
		return INT_MAX;
	}
	
	int high = maze[h][w]-exHigh;
	if (!(high >= -1 && high <= 1)) {
		return INT_MAX;
	}
	//cout << h << " " << w << endl;
	s.push(make_pair(h, w));
	visited[h][w] = true;

	int val = INT_MAX;
	val = min(solve(height, width, h, w - 1, maze[h][w]), val);
	val = min(solve(height, width, h + 1, w, maze[h][w]), val);
	val = min(solve(height, width, h - 1, w, maze[h][w]), val);
	val = min(solve(height, width, h, w + 1, maze[h][w]), val);

	if (!result)s.pop();

	return val;
}

int main() {

	int height = 0, width = 0;
	scanf("%d %d", &width, &height);
	maze = new int*[height];
	visited = new int*[height];
	for (int i = 0; i < height; i++) {
		visited[i] = new int[width];
		maze[i] = new int[width];
		for (int l = 0; l < width; l++) {
			visited[i][l] = 0;
			scanf("%d ", &maze[i][l]);
		}
	}

	int val = solve(height, width, 0, 0, maze[0][0]);
	if (val == INT_MAX)
		cout << 0;
	else
		cout << val;
	//cout << s.size();

	//while (!s.empty()) {
	//	cout << s.top().first << " " << s.top().second << endl;
	//	s.pop();
	//}

	for (int i = 0; i < height; i++) {
		delete maze[i];
	}
	delete [] maze;
}

//8 8
//5 6 4 4 3 2 3 4
//6 3 3 5 5 2 1 5
//5 4 4 3 3 7 1 4
//6 4 7 7 4 3 2 6
//5 3 7 7 7 3 7 4
//6 7 3 6 6 3 3 7
//5 6 5 6 5 6 4 4
//3 7 5 3 6 6 5 4