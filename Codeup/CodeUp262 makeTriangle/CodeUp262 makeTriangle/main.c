#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {

	int size;
	scanf("%d", &size);

	if (size < 3)
		printf("0");

	int count = 0;
	int MAX = size / 2 + 1;

	//for (int a = 1; a < MAX; a++)
	//{
	//	
	//	if (a % 2 == 1)
	//		count += a / 2 + 1;
	//	else
	//		count += a / 2;
	//}

	for (int a = 1; a < MAX; a++)
		for (int b = a; b < (size - a) / 2 + 1; b++) {
			int c = size - a - b;
			if (a + b > c) {
				count++;
				printf("%d %d %d\n", a, b, c);
			}
		}

	printf("%d", count);

}