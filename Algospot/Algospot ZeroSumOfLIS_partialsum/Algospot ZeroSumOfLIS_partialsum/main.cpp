#define _CRT_SECURE_NO_WARNINGS
#define MIN(a,b) (((a)<(b)) ? (a) : (b))

#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int* getPartialSum(const int* ,const int);
void zeroSequence(const int* , const int*, const int);


int compare(const void* a,const void *b) {
	return *(int*)a - *(int*)b;
}


int main() {

	size_t caseSize = 0;
	scanf("%d", &caseSize);

	int *result = new int[caseSize];

	for (size_t i = 0; i < caseSize; i++) {

		int srcSize = 0;
		int *src = NULL;
		
		scanf("%d", &srcSize);
		src = new int[srcSize];
		
		for (size_t l = 0; l < srcSize; l++) {
			scanf("%d", &src[l]);
		}
		
		qsort(src, srcSize, sizeof(int),compare);

		int *pSum = getPartialSum(src,srcSize);
	
	}

}


int* getPartialSum(const int* src, const int size) {

	int *pSum = new int[size];

	pSum[0] = src[0];
	for (int i = 1; i < size; i++) {
		pSum[i] = pSum[i - 1] + src[i];
	}

	return pSum;

}

void zeroSequence(const int* src, const int* pSum, const int size) {



}