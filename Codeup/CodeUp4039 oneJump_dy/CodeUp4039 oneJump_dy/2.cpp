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

using namespace std;

stack<pair<int,int>> s;
int **maze;
int **visited;

inline V2INT DIR(int h, int w) {
	
}

bool solve(C_INT height, C_INT width, int h, int w, int exHigh) {

	if (height - 1 == h && width - 1 == w)
	{
		return true;
	}
	else if (h == -1 || w == -1 || h == height || w == width ) {
		return false;
	}
	else if (visited[h][w]) {
		return false;
	}
	
	int high = maze[h][w]-exHigh;
	if (!(high >= -1 && high <= 1)) {
		return false;
	}

	s.push(make_pair(h, w));
	visited[h][w] = true;

	bool res = false;
	res |=solve(height, width, h + 1, w, maze[h][w]);
	res |= solve(height, width, h, w+1, maze[h][w]);
	res |= solve(height, width, h -1, w, maze[h][w]);
	res |= solve(height, width, h, w-1, maze[h][w]);

	if (!res)
		s.pop();

	return res;
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

	if (solve(height, width, 0, 0, maze[0][0]))
		cout << s.size();

	for (int i = 0; i < height; i++) {
		delete maze[i];
	}
	delete [] maze;
}