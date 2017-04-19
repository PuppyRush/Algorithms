#define _CRT_SECURE_NO_WARNINGS
#define MIN(a,b) ((a>b)?b:a)
#define MAX(a,b) ((a>b)?b:a)
#define FOR(i,size) for(i ; i < size ; ++i)
#define FOR_IN(i,size) for(i ; i <= size ; ++i)
#define FOR_REV(i) for(i ; i >=0 ; --i)
#define FOR_REV_SIZE(i,size) for(i ; i >=size ; --i)


#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>

using namespace std;

typedef const int C_INT;
typedef unsigned int UINT;
typedef const unsigned int C_UINT;
typedef unsigned char UCHAR;
typedef const unsigned char C_UCHAR;
typedef const char C_CHAR;
typedef const unsigned long long C_ULL;
typedef unsigned long long ULL;

typedef std::pair<int, int> PINT;
typedef std::vector<std::vector<int>> V2INT;
typedef std::vector<int> VINT;
typedef std::vector<string> VSTR;

#define X 'x'
#define O 'o'
#define P '+'
#define EMPTY '.'
#define WALL 'w'

#define m mul[y][x]
#define p plus[y][x]
#define g grid[y][x]

C_INT LINE[][2] = {
	{ 1,0 },{ -1,0 },{0,1},{0,-1}
};

C_INT DIAG[][2] = {
	{ 1,1 },{ -1,-1 },{ -1,1 },{ 1,-1 }
};


using namespace std;

char** copyGrid(char** src,C_INT size,char c) {
	char **grid = new char*[size];
	int i = 0;
	FOR(i, size) {
		grid[i] = new char[size];
		memset(grid[i] + 1, EMPTY, size - 2);
	}

	int y, x;
	y = x = 1;
	FOR(y, size-1) {
		x = 1;
		FOR(x, size-1) {
			if (src[y][x] == c || src[y][x] == O)
				g = c;
		}
	}
	
	return grid;
}

bool diag(char** src, C_INT y, C_INT x) {
	bool empty = true;
	int l = 0;
	int i = 0;
	FOR(i, 4) {
		int _y = y + LINE[i][0];
		int _x = x + LINE[i][1];
		if (src[_y][_x] == X)
			return true;
		else if (src[_y][_x] != EMPTY &&src[_y][_x] != WALL)
			empty = false;
	}
	if (empty)
		true;
	return false;
}

bool line(char** src, C_INT y, C_INT x) {
	
	bool empty = true;
	int l = 0;
	int i = 0;
	FOR(i, 4) {
		int _y = y + DIAG[i][0];
		int _x = x + DIAG[i][1];
		if (src[_y][_x] == P)
			return true;
		else if (src[_y][_x] != EMPTY && src[_y][_x] != WALL)
			empty = false;
	}
	if (empty)
		true;
	return false;
}

void set(char **src, C_INT y, C_INT x, C_INT comp[4][2], char c, map<PINT, char> &s) {
	int i = 0;
	FOR(i, 4) {
		int _y = y + comp[i][0];
		int _x = x + comp[i][1];
		if (src[_y][_x] == c)
			break;
	}
	if (i == 4) {
		//cout << y << " " << x << " " << c << endl;
		src[y][x] = c;
		s[PINT(x, y)] = c;
	}
}

void print(char **grid, C_INT size) {
	int y, x = 0;
	y = x = 1;
	FOR(y, size-1) {
		x = 1;
		FOR(x, size-1 )
			cout << g;
		cout << endl;
	}
	cout << "-------------" << endl;
}

int main() {

	freopen("C:\\Users\\goodd\\Downloads\\D-small-practice.in", "r", stdin);
	//freopen("C:\\Users\\goodd\\Desktop\\D-small.out", "w", stdout);

	int size = 0;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);

	int caseSize = 0;
	scanf("%d", &caseSize);

	for (int t = 0; t < caseSize; ++t) {
		int i = 0;
		int added = 0;
		map<PINT, char> s;
		
		int number, cloths;
		scanf("%d %d", &number, &cloths);


		//init
		char **grid = new char*[number + 2];
		i = 0;
		grid = new char*[number + 2];
		FOR(i, number + 2) {
			grid[i] = new char[number + 2];
			int l = 0;
			FOR(l, number + 2)
				grid[i][l] = EMPTY;
		}
		
		i = 0;
		FOR(i, number + 2) {
			grid[i][0] = WALL;
			grid[i][number + 1] = WALL;
			grid[0][i] = WALL;
			grid[number + 1][i] = WALL;
		}

		i = 0;
		FOR(i, cloths) {
			int x, y;
			char c;
			scanf("%s %d %d", &c, &y, &x);
			grid[y][x] = c;
		}

		//copy
		auto plus = copyGrid(grid, number + 2,P);
		
		auto mul = copyGrid(grid, number + 2,X);
		
		//subtitute
		int x = 1, y = 1;
		FOR(y, number + 1) {
			x = 1;
			FOR(x, number + 1) {
				if ((g != X ) && line(grid, y, x))
					p = P;
				if ((g != P ) &&diag(grid, y, x))
					m = X;
			}
		}
		print(plus, number + 2);
		print(mul, number + 2);

		//fill
		x = 1, y = 1;
		FOR(y, number + 1) {
			x = 1;
			FOR(x, number + 1) {
				if (p == EMPTY && g == EMPTY) {
					set(plus, y, x, DIAG, X, s);
				}
			}
		}
		x = 1, y = 1;
		FOR(y, number + 1) {
			x = 1;
			FOR(x, number + 1) {
				if (m == EMPTY && g == EMPTY)
					set(mul, y, x, LINE, X, s);
			}
		}

		//merge
		int score = 0;
		x = 1, y = 1;
		FOR(y, number + 1) {
			x = 1;
			FOR(x, number + 1) {
				if (p == P && m == X) {
					added++;
					score += 2;
					auto it = s.find(PINT(x, y));
					if (it != s.end())
						s.erase(it);
					if (!(g == O && p == P)) {
						s[PINT(x, y)] = O;
					}
				}
				else if (p == P) {
					score += 1;
				}
				else if (m == X) {
					score += 1;
				}

			}
		}
		cout << "Case #" << (t + 1) << ": " << score << " " << s.size() << endl;
		i = 0;
		auto it = s.begin();
		while (it != s.end()) {
			cout << it->second << " " << it->first.second << " " << it->first.first << endl;
			it++;
		}

	}
	return 0;
}
