#define _CRT_SECURE_NO_WARNINGS
#define MAX(a,b) ( ((a)>(b)) ? (a) : (b))

enum ORDER {

	UP = 0,
	LEFT,
	NOTHING
};

#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

int path(int**, const int, int, int);
int **memo;
int **order;

int main() {


	int caseSize;
	scanf("%d", &caseSize);

	vector<int> result;


	for (size_t i = 0; i < caseSize; i++) {

		int height = 0;
		scanf("%d", &height);

		memo = new int*[height];
		order = new int*[height];
		int **triangle = new int*[height];
		for(int h=0 ; h < height ; h++){
			int temp = 0;
			memo[h] = new int[h + 1];
			order[h] = new int[h + 1];
			triangle[h] = new int[h + 1];
			memset(memo[h], -1, sizeof(int)*(h + 1));
			memset(order[h], -1, sizeof(int)*(h + 1));
			memset(triangle[h], -1, sizeof(int)*(h + 1));

			for (int w = 0; w < h + 1; w++)
				scanf("%d", &triangle[h][w]);
		}

		result.push_back(path(triangle, height, 0, 0 ));

		for (int l = 0; l < height; l++) {
			for (int w = 0; w < l + 1; w++)
				if (order[l][w] == LEFT)
					cout << "в┘" << " ";
				else if (order[l][w] == UP)
					cout << "бщ" << " ";
				else
					cout << " " << " ";
			cout << endl;
		}

	}

	vector<int>::iterator it = result.begin();
	while (it != result.end())
		cout << (*it++) << endl;

}

int path(int **tri, const int height, int x, int y) {

	if (x > y )
		return -1;

	if (y == height - 1)
		return tri[y][x];

	if (memo[y][x] != -1)
		return memo[y][x];

	int btm, right;
	btm = path(tri, height, x, y + 1);
	right = path(tri, height, x + 1, y + 1);
	if (btm > right)
		order[y][x] = UP;
	else
		order[y][x] = LEFT;

	return memo[y][x] = tri[y][x] += MAX(btm,right);

}

//
//char buf[7 * 100 + 1];
//
//for (size_t l = 0, heightIdx = 0; l < height; l++, heightIdx = 0) {
//	memset(buf, 0, 7 * 100 + 1);
//	scanf("%[0-9 ]", buf);
//	const int bufLen = strlen(buf);
//	int numberCount = 0;
//	for (size_t t = 0; t < bufLen; numberCount = 0, t++) {
//		if (buf[t] == ' ')
//			;
//		else {
//			for (; t < bufLen && buf[t] != ' '; t++)
//				numberCount++;
//			char *num = new char[7];
//			memset(num, 0, 7);
//			memcpy(num, buf + t - numberCount, numberCount);
//			sscanf(num, "%d", &triangle[l][heightIdx++]);
//			t--;
//		}
//
//	}
//
//	while (getchar() != '\n');
//}