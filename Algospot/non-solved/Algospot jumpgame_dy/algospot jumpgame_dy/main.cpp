#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

bool jump(int [][100],int,int,int);
int memo[100][100];

int main() {

	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//_CrtSetBreakAlloc(177);

	int caseSize;
	scanf("%d", &caseSize);

	bool *result = new bool[caseSize];


	for (size_t i = 0; i < caseSize; i++) {

		
		int board[100][100];
		int boardSize = 0;

		memset(board, -1, 100 * 100 * sizeof(int));
		memset(memo, -1, 100 * 100 * sizeof(int));

		scanf("%d", &boardSize);
		
		char buf[100 * 2 + 1];
		memset(buf, 0, 100*2+1);

		while (getchar() != '\n');
		for (size_t l = 0; l < boardSize; l++) {
			scanf("%[0-9 ]", buf);
			for (size_t t = 0; t < boardSize; t++) {
				board[l][t] = buf[t * 2] - 48;
			}
			while (getchar() != '\n');
		}
	
	

		result[i] = jump( board, boardSize, 0, 0);
		
	}

	for (int i = 0; i < caseSize; i++) {
		string v = result[i] ? "YES" : "NO";
		cout << v << endl;
	}
	delete[] result;
	result = NULL;

	//_CrtDumpMemoryLeaks();

}

bool jump(int board[][100], int size,int x,int y) {

	if (x >= size || y >= size) {
		return 0;
	}
	if (x == size - 1 && y == size - 1) {
		return 1;
	}

	int &res = memo[y][x];

	if (res != -1)
		return res;
	
	int _jump = board[y][x];
	return (res = jump(board, size, x + _jump, y) || jump(board, size, x, y + _jump));

}