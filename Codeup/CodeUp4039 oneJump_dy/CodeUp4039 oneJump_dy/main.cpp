//#define _CRT_SECURE_NO_WARNINGS
//#define MAX(a,b) ( ((a)>(b)) ? (a) : (b) )
//
//#include <iostream>
//#include <vector>
//#include <string>
//#include <string.h>
//
//enum DIRECTION{
//
//	UP=0,
//	LEFT,
//	RIGHT,
//	DOWN
//
//};
//
//using namespace std;
//
//int jump(int**, int, int,int, int, DIRECTION,int);
//int **memo;
//int minimumOf(int*,int);
//void printSomething(void**, int, int);
//
//int main() {
//
//	int **board;
//	int width = 0, height = 0;
//
//	
//	
//	scanf("%d", &width);
//	scanf("%d", &height);
//
//	board = new int*[height];
//	for (int i = 0; i < height; i++) {
//		board[i] = new int[width];
//		memset(board[i], -1, width * sizeof(int));
//	}
//
//	memo = new int*[height];
//	for (int i = 0; i < height; i++) {
//		memo[i] = new int[width];
//		memset(memo[i], -1, width * sizeof(int));
//	}
//
//	char buf[100 * 2 + 1];
//	memset(buf, 0, 100 * 2 + 1);
//
//	while (getchar() != '\n');
//	for (size_t h = 0; h < height; h++) {
//		scanf("%[0-9 ]", buf);
//		for (size_t w = 0; w < width; w++) {
//			board[h][w] = buf[w * 2] - 48;
//		}
//		while (getchar() != '\n');
//	}
//
//	cout << jump(board, width,height, 0, 0,DOWN, board[0][0]);
//
//}
//
//int jump(int **board, const int width,const int height, int x, int y,DIRECTION dir,int count) {
//	
//	if (x == 1 && y == 1)
//		x = 1;
//
//	if (y < 0 || x < 0 || x >= width || y >= height)
//		return 0;
//
//	int &res = memo[y][x];
//	const int now = board[y][x];
//
//	if (x == width - 1 && y == height - 1) {
//		return res = count + 1;
//	}
//
//	if (res == 0)
//		return res;
//	else if (res == -1) {
//		if (y < height - 1 && dir == UP && abs(board[y + 1][x] - now) > 1 )
//			return 0;
//		else if (y > 0 && dir == DOWN && abs(board[y - 1][x] - now) > 1 )
//			return 0;
//		else if (x < width - 1 && dir == LEFT && abs(board[y][x + 1] - now) > 1 )
//			return 0;
//		else if (x > 0 && dir == RIGHT && abs(board[y][x - 1] - now) > 1 )
//			return 0;
//	}
//	else {
//		if (y < height - 1 && dir == UP && res < memo[y + 1][x]) {
//			return memo[y + 1][x];
//		}
//		else if (y > 0 && dir == DOWN && res < memo[y - 1][x])
//			return memo[y - 1][x];
//		else if (x < width - 1 && dir == LEFT && res < memo[y][x + 1])
//			return memo[y][x + 1];
//		else if (x > 0 && dir == RIGHT && res < memo[y][x - 1])
//			return memo[y][x - 1];
//	}
//
//	res = count + 1;
//	
//	int result;
//	int resultAry[4] = { 0,0,0,0 };
//
//	if(dir!=UP)
//		resultAry[1] = jump(board, width, height, x, y + 1, DOWN, res);
//	if(dir!=LEFT)
//		resultAry[0] = jump(board, width, height, x + 1, y, RIGHT, res);
//	if(dir!=RIGHT)
//		resultAry[2] = jump(board, width, height, x - 1, y, LEFT, res);
//	if(dir!=DOWN)
//		resultAry[3] = jump(board, width, height, x, y - 1, UP, res);
//	
//	res = minimumOf(resultAry, sizeof(resultAry) / sizeof(resultAry[0]));
//
//	//printSomething((void**)memo, width, height);
//
//
//	return res;
//}
//
//int minimumOf(int *ary, int size) {
//
//	size_t min = INT32_MAX;
//	size_t idx = 0;
//	size_t cnt = 0;
//	for (size_t i = 0; i < 4; i++)
//		if (ary[i] > 0) {
//			cnt++;
//			idx = i;
//		}
//
//	if (cnt == 0)
//		return 0;
//	if (cnt == 1)
//		return ary[idx];
//	else if (cnt > 1) {		
//		for (size_t i = 0; i < size; i++) {
//			if (ary[i]>0 && min > ary[i]) {
//				min = ary[i];
//			}
//		}
//	}
//
//	return min;
//}
//
//
//void printSomething(void** ary, int w, int h) {
//
//	cout << endl;
//
//	if (sizeof(ary) == 4) {
//		int **a = (int**)ary;
//		for (int i = 0; i < h; i++) {
//			for (int l = 0; l < w; l++) {
//				printf("%2d ", a[i][l]);
//				
//			}
//			cout << endl;
//		}
//	}
//	else if (sizeof(ary) == 1) {
//		bool **a = (bool**)ary;
//		for (int i = 0; i < h; i++) {
//			for (int l = 0; l < w; l++) {
//				printf("%2d ", a[i][l]);
//			}
//			cout << endl;
//		}
//	}
//
//}