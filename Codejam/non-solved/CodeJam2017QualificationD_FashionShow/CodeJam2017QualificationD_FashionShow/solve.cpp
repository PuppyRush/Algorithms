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

using namespace std;

C_INT ROW[2][1][2] = {
	{ 0,1},{0,-1}
};

C_INT COL[2][1][2] = {
	{ 1,0 },{ -1,0}
};

C_INT DIAG[4][1][2] = {
	{ 1,1 },{ -1,-1 },{ -1,1},{ 1,-1}
};


typedef struct GRID {

private:
	

	int change(C_CHAR c) {
		switch (c) {
		case 'o':
			return 2;
		case 'x':
			return 1;
		case '+':
			return 1;
		default:
			return 0;
		}
	}

public:
	int point;
	int add;
	int cloths;
	int number;
	char **g;

	GRID(int n) {
		point = 0;
		number = n;
		cloths = 0;
		add = 0;
		g = new char*[n+2];
		int i = 0;
		FOR(i, n+2) {
			g[i] = new char[n+2];
			int l = 0;
			FOR(l, n + 2)
				g[i][l] = EMPTY;
		}
		//memset(g, EMPTY, (n+2)*(n+2));

		i = 0;
		FOR(i, n + 2) {
			g[i][0] = WALL;
			g[i][n+1] = WALL;
			g[0][i] = WALL;
			g[n+1][i] = WALL;
		}
	}

	~GRID() {
		int i = 0;
		FOR(i, number+2) {
			
			delete g[i];
			
		}
		delete g;
	}

	void init(int x, int y, const char c) {
		cloths++;
		g[y][x] = c;
		point += change(c);
	}

	void set(int x, int y, const char c) {
		cloths++;
		add++;
		g[y][x] = c;
		point += change(c);
	}

	void upgrade(int x, int y) {

		if (g[y][x] == O || g[y][x] == EMPTY)
			return;

		g[y][x] = 'o';
		point += 1;
	}

	bool isFull() {
		return number*number == cloths ? true : false;
	}
	
	bool checkRow(int x, int y, char c) {
		bool isEmpty = true;

		int i = 0;
		i = 0;
		FOR(i, 2) {

			C_CHAR cloths = g[y + ROW[i][0][0]][x + ROW[i][0][1]];
			if (cloths == WALL)
				continue;
			if (cloths != EMPTY)
				isEmpty = false;
		}
		if (isEmpty)
			return true;

		if (c != P) {
			i = 0;
			FOR(i, 2) {

				C_CHAR cloths = g[y + ROW[i][0][0]][x + ROW[i][0][1]];
				if (cloths == P)
					return true;
			}

		}
		else {
			i = 0;
			FOR(i, 2) {

				C_CHAR cloths = g[y + ROW[i][0][0]][x + ROW[i][0][1]];
				if (cloths == WALL)
					continue;
				if (cloths == X || cloths == O || cloths == P)
					return true;
			}

		}
		return false;
	}

	bool checkHeight(int x, int y, char c) {
		bool isEmpty = true;

		int i = 0;
		i = 0;
		FOR(i, 2) {

			C_CHAR cloths = g[y + COL[i][0][0]][x + COL[i][0][1]];
			if (cloths == WALL)
				continue;
			if (cloths != EMPTY)
				isEmpty = false;
		}
		if (isEmpty)
			return true;

		if (c != P) {
			i = 0;
			FOR(i, 2) {

				C_CHAR cloths = g[y + COL[i][0][0]][x + COL[i][0][1]];
				if (cloths == P)
					return true;
			}

		}
		else {
			i = 0;
			FOR(i, 2) {

				C_CHAR cloths = g[y + COL[i][0][0]][x + COL[i][0][1]];
				if (cloths == WALL)
					continue;
				if (cloths == X || cloths == O || cloths == P)
					return true;
			}

		}
		return false;
	}

	bool checkLine(int x, int y, char c) {
		return checkRow(x, y, c) && checkHeight(x, y, c);
	
	}

	bool checkDiagonal(int x, int y, char c) {
				
		bool isEmpty = true;

		int i = 0;
		i = 0;
		FOR(i, 4) {

			C_CHAR cloths = g[y + DIAG[i][0][0]][x + DIAG[i][0][1]];
			if (cloths == WALL)
				continue;
			if (cloths != EMPTY)
				isEmpty = false;
		}
		if (isEmpty)
			return true;

		if (c != X) {
			i = 0;
			FOR(i, 4) {

				C_CHAR cloths = g[y + DIAG[i][0][0]][x + DIAG[i][0][1]];
				if (cloths == X)
					return true;
			}

		}
		else {
			i = 0;
			FOR(i, 4) {

				C_CHAR cloths = g[y + DIAG[i][0][0]][x + DIAG[i][0][1]];
				if (cloths == WALL)
					continue;
				if (cloths == X || cloths == O || cloths == P)
					return true;
			}

		}
		return false;
	}



	bool isCanSet() {

		int y = 0;
		FOR(y, number-1) {
			int x = 0;
			bool beginPlus = true;
			FOR(x, number - 1) {
				if (g[y][x] == '+') {
					;
				}
			}
		}

	}

	void wholeUpgrade() {
		int _x=0, _p=0;

		int y = 1;
		FOR_IN(y, number) {
			int x = 1;
			FOR_IN(x, number) {
				if (g[y][x] == EMPTY || g[y][x] == O)
					continue;

				int i = 0;
				FOR(i, 4) {
					C_CHAR d = g[y + DIAG[i][0][0]][x + DIAG[i][0][1]];
					if (d == X)
						_x++;
				}
				i = 0;
				FOR(i, 2) {
					C_CHAR l = g[y + ROW[i][0][0]][x + ROW[i][0][1]];
					
					if (l == P)
						_p++;
				}
				i = 0;
				FOR(i, 2) {
					C_CHAR l = g[y + COL[i][0][0]][x + COL[i][0][1]];

					if (l == P)
						_p++;
				}

				if (_x>=1&&_p>=1) {
					upgrade(x, y);
				}
				_x = _p = 0;
			}
		}
	}

	int getAddedClothsNumber() { return add; }

	int getWholePoint() {
		return point;
	}

	void printAll() {
		
		int y = 1;
		FOR_IN(y, number) {
			int x = 1;
			FOR_IN(x, number)
				if(g[y][x]!=EMPTY)
					printf("%c %d %d\n", g[y][x],y,x);
			
		}
	}
}Grid;

void solver(Grid &grid) {
	
	if (grid.number*grid.number == grid.cloths)
	{
		grid.wholeUpgrade();
		return;
	}

	int ref = -1;
	int y = 1;
	C_INT size = grid.number;
	FOR_IN(y, size) {
		int x = 1;
		FOR_IN(x, size) {
			if(grid.g[y][x] == EMPTY)

			if (grid.checkDiagonal(x, y,P)  && grid.checkLine(x, y,P)) {
				grid.set(x, y, P);
			}
		}
	}
	y = 1;
	FOR_IN(y, size) {
		int x = 1;
		FOR_IN(x, size) {
			if (grid.g[y][x] != P)
			if (grid.checkDiagonal(x, y,X) && grid.checkLine(x, y,X)) {
				grid.set(x, y, X);
			}
		}
	}
	grid.wholeUpgrade();
}

int _main() {

	//freopen("C:\\Users\\goodd\\Downloads\\C-small-2-attempt0.in", "r", stdin);
	//freopen("C:\\Users\\goodd\\Desktop\\C-small2.out", "w", stdout);

	int size = 0;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);

	int caseSize = 0;
	scanf("%d", &caseSize);

	for (int t = 0; t < caseSize; ++t) {
		int i = 0;
		int number, cloths;
		scanf("%d %d", &number, &cloths);

		Grid grid(number);

		FOR(i, cloths) {
			int x, y;
			char c;
			scanf("%s %d %d", &c, &y, &x);
			grid.init(x, y, c);
		}
		
		solver(grid);
		printf("Case #%d: %d %d\n", (t + 1), grid.getWholePoint(), grid.getAddedClothsNumber());
		if (grid.getAddedClothsNumber() > 0)
			grid.printAll();
		
	}

	return 0;
}
