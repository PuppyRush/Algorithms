/*
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <memory>

using namespace std;

typedef struct COORD {
	int x;
	int y;
}COORD;

enum FIGURE {
	FILL = 1,
	EMPTY = 0,
	REMOVE = -1
};

int setRecursive(int**, const int width, const int height);
COORD getBlankBoard(int**, const int, const int);
bool draw(int**, const int, const int, const int, const int, int ,int);
void draws(int **, const int width, const int height);

int figureType[4][3][2] = {

	{
		{0,0},{1,0},{0,1}
	},
	{
		{0,0},{0,1},{1,1}
	},
	{
		{0,0},{1,0},{1,1}
	},
	{
		{ 0,0 },{ 1,0 },{ 1,-1 }
	}
};
const int TYPE_KIND_NUMBER = 4;

int main()
{

	int *result;
	int caseSize = 0;
	int width = 0, height = 0;
	int **board = NULL;

	scanf("%d", &caseSize);

	result = new int[caseSize];

	for (int i = 0; i < caseSize; i++)
	{

		scanf("%d %d", &height, &width);
		while (getchar() != '\n');

		board = new int*[height];
		for (int l = 0; l < height; l++) {
			board[l] = new int[width];
			memset(board[l], 0, sizeof(bool)*width);
		}
		
		int blankCount = 0;
		bool isCorrupt = false;
		for (int h = 0; h < height; h++) {
			for (int w = 0; w < width; w++) {
				char buf;
				scanf("%c", &buf);

				if (buf == '#')
					board[h][w] = FILL;
				else if (buf == '.') {
					board[h][w] = EMPTY;
					blankCount++;
				}
				else {
					isCorrupt = true;
				}


			}
			while (getchar() != '\n');
		}

	
		if (isCorrupt == false && (blankCount % 3 == 0))
			result[i] = setRecursive(board, width, height);
		else
			result[i] = 0;

		for (int l = 0; l < height; l++) {
			delete board[l];
		}
		delete board;
		board = NULL;
	}

	for (int i = 0; i < caseSize ; i++)
		cout << result[i]<<endl;
}


int setRecursive(int** board, const int width, const int height)
{

	int sum = 0;
	
	COORD c = getBlankBoard(board, width, height);
	if (c.x == -1 && c.y == -1)
		return 1;

	for(int type=0 ; type < TYPE_KIND_NUMBER; type++){
		if (draw(board, width, height, c.x, c.y, type, FILL))
			sum += setRecursive(board, width, height);
		
		draw(board, width, height, c.x, c.y, type, REMOVE);
	}

	return sum;

}

COORD getBlankBoard(int** board, const int width, const int height)
{

	COORD c;

	for(int h=0; h < height ; h++)
		for(int w=0; w< width ; w++)
			if (board[h][w] == EMPTY) {
				c.x = w;
				c.y = h;
				return c;
			}
	c.x = -1;
	c.y = -1;
	return c;
}

bool draw(int** board, const int width, const int height, const int x, const int y, int type, int drawKind)
{

	bool isFine = true;

	for (int l = 0; l < 3; l++) {

		int cy = y + figureType[type][l][0];
		int cx = x + figureType[type][l][1];

		if (cx < 0 || cx >= width || cy < 0 || cy >= height) {
			isFine = false;
		}
		else if ((board[cy][cx] += drawKind) > 1)
			isFine = false;
	}

	return isFine;
}

void draws(int **board, const int width, const int height) {

	for (int h = 0; h < height; h++) {
		for (int w = 0; w < width; w++) {
			if (board[h][w]>0)
				cout << "#";
			else
				cout << ".";
			
		}
		cout << endl;
	}
	cout << endl;

}*/
