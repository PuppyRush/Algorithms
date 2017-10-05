//#define _CRT_SECURE_NO_WARNINGS
//#define MAX(a,b) (((a)>(b)) ? (a) : (b))
//#define FOR(l,size) for(int l=0 ; l < size ; ++l)
//
//#include <iostream>
//#include <vector>
//#include <string.h>
//
//using namespace std;
//
//int* getPartialSum(const int*, const int);
//int christmas1(int*pSum, const int pSumSize, const int childSize);
//int christmas2(int*gifts, const int giftSize, const int childSize, int beginIdx, int untilSum, int count);
//
//int compare(const void* a, const void *b) {
//	return *(int*)a - *(int*)b;
//}
//
//int *memo;
//
//int main() {
//
//	size_t caseSize = 0;
//	scanf("%d", &caseSize);
//
//	int **result = new int*[caseSize];
//
//	for (size_t i = 0; i < caseSize; i++) {
//
//		result[i] = new int[2];
//
//		int giftSize = 0;
//		int *gifts = NULL;
//		
//		scanf("%d", &giftSize);
//		gifts = new int[giftSize];
//
//		memo = new int[giftSize];
//		memset(memo, -1, sizeof(int)*giftSize);
//
//
//		int childSize = 0;
//		scanf("%d", &childSize);
//
//		for (size_t l = 0; l < giftSize; l++) {
//			scanf("%d", &gifts[l]);
//		}
//
//		int *pSum = getPartialSum(gifts, giftSize);
//
//		result[i][0] = christmas1(pSum, giftSize, childSize) % 20091101;
//		result[i][1] = christmas2(gifts, giftSize, childSize, 0, 0,0);
//
//		delete memo;
//
//	}
//
//	for (size_t i = 0; i < caseSize; i++)
//		cout << result[i][0] << " " << result[i][1] << endl;
//
//}
//
//int christmas1(int*pSum ,const int pSumSize, const int childSize) {
//
//	if (childSize == 1)
//		return (pSumSize* (pSumSize + 1)) / 2;
//
//	int *ary = new int[childSize];
//	memset(ary, -1, sizeof(int)*childSize);
//	ary[0] = 0;
//
//	for (size_t i = 0; i < pSumSize; i++) {
//		int idx = pSum[i] % childSize;
//		ary[idx]++;
//	}
//
//	int result = 0;
//	for (size_t i = 0; i < childSize; i++)
//		if(ary[i] >0)
//			result += ary[i];
//
//	return result;
//}
//
//
//int christmas2(int*gifts, const int giftSize, const int childSize, int beginIdx, int untilSum, int count) {
//
//	if (beginIdx == giftSize)
//		return count;
//
//	untilSum += gifts[beginIdx];
//	if (untilSum%childSize==0)
//		count++;
//
//	//int ref = 0;
//	int &ref = memo[beginIdx];
//
//	ref = MAX(christmas2(gifts, giftSize, childSize, beginIdx + 1, untilSum, count), ref);
//	ref = MAX(christmas2(gifts, giftSize, childSize, beginIdx + 1, 0, 0), ref);
//
//	return ref;	
//}
//
//
//int* getPartialSum(const int* src, const int size) {
//
//	int *pSum = new int[size];
//
//	pSum[0] = src[0];
//	for (int i = 1; i < size; i++) {
//		pSum[i] = pSum[i - 1] + src[i];
//	}
//
//	return pSum;
//
//}
