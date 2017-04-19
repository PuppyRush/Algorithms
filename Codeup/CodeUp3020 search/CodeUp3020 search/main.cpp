#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

typedef struct BUCKIT {
	int idx;
	int val;
};


BUCKIT* quickSort(BUCKIT *,int ,int);
void swap(BUCKIT*, BUCKIT*);
BUCKIT* extractBuckitrAryFromChars(const int count);
int* extractIntegerAryFromChars(const int);
int binarySearch(const BUCKIT *array, const int arySize, const int destValue);

int compare(const void *a, const void *b) {
	return( (*(BUCKIT*)a).val - (*(BUCKIT*)b).val );
}

int main() {

	int size;
	BUCKIT *originValues = NULL;
	
	scanf("%d", &size);
	while (getchar() != '\n');
	originValues = extractBuckitrAryFromChars(size);

	int *destValues;
	int destArySize = -1;
	scanf("%d", &destArySize);
	while (getchar() != '\n');
	destValues = extractIntegerAryFromChars(destArySize);
	
	qsort(originValues, size, sizeof(BUCKIT), compare);

	int idx = -1;
	for (int i = 0; i < destArySize; i++) {		
		
		int idx = binarySearch(originValues, size, destValues[i]);

		if (idx != -1)
			cout << idx << " ";
		else
			cout << -1 << " ";
		
	}
	
	delete originValues;
	delete destValues;
}


BUCKIT* extractBuckitrAryFromChars(const int size) {


	BUCKIT *destAry = new BUCKIT[size];

	for (int i = 0; i < size; i++) {
		int temp;
		scanf("%d", &temp);
		destAry[i].val = temp;
		destAry[i].idx = i;
	}

	return destAry;
}

int* extractIntegerAryFromChars(const int count) {

	
	int *destAry = new int[count];

	for (int i = 0; i < count; i++) {
		int temp;
		scanf("%d", &temp);
		*(destAry + i) = temp;
	}
	return destAry;
}

int binarySearch(const BUCKIT *array, const int arySize, const int destValue) {

	int right = arySize - 1;
	int left = 0;
	int mid = 0;

	while (left <= right) {

		mid = (left + right) / 2;

		if (array[mid].val == destValue)
			return array[mid].idx + 1;

		if (array[mid].val > destValue)
			right = mid - 1;
		else
			left = mid + 1;



	}

	return -1;
}


BUCKIT* quickSort(BUCKIT *source, int left, int right) {

	//swap(&source[left], &source[ (left + right)/2 ] );
	int pivot = source[left].val;
	int pivotIdx = left;

	int l = left;
	int r = right;

	while (l < r) {

		while (source[r].val > pivot)
			r--;
		while (l<r && source[l].val < pivot)
			l++;


		swap(&source[l], &source[r]);

	}

	swap(&source[pivotIdx], &source[left]);

	/*source[left] = source[l];
	source[l] = source[pivot];
	*/
	if (left<r)
		quickSort(source, left, l - 1);
	if (l < right)
		quickSort(source, l + 1, right);

	return source;
}

void swap(BUCKIT *l, BUCKIT *r) {
	BUCKIT *temp = l;
	l = r;
	r = temp;

}


//
//#define KEY_SIZE 100000
//#define BUCKIT_SIZE	100
//
//using namespace std;
//
//int* extractIntegerAryFromChars(const int);
//
//typedef struct PAIR {
//	int val;
//	int idx;
//};
//
//typedef struct BUCKIT {
//	PAIR ary[BUCKIT_SIZE];
//	int size;
//};
//
//
//int main() {
//
//	int size;
//	BUCKIT *originValues = NULL;
//
//	scanf("%d", &size);
//	while (getchar() != '\n');
//
//	originValues = new BUCKIT[KEY_SIZE];
//	memset(originValues, -1, sizeof(BUCKIT)*KEY_SIZE);
//
//	for (int i = 0; i < size; i++) {
//		int temp;
//		scanf("%d", &temp);
//
//		int key = temp%KEY_SIZE;
//		BUCKIT *thisBuckit = &originValues[key];
//		thisBuckit->size++;
//		thisBuckit->ary[thisBuckit->size].idx = i;
//		thisBuckit->ary[thisBuckit->size].val = temp;
//
//	}
//
//	int *destValues;
//	int destArySize = -1;
//	scanf("%d", &destArySize);
//	while (getchar() != '\n');
//	destValues = extractIntegerAryFromChars(destArySize);
//
//	for (int i = 0; i < destArySize; i++) {
//
//		int idx = -1;
//		int val = destValues[i];
//		int key = val % KEY_SIZE;
//
//		BUCKIT *thisBkt = &originValues[key];
//
//		if (thisBkt->size == 0) {
//			idx = thisBkt->ary[0].idx;
//		}
//		else if (thisBkt->size > 0) {
//			int buckitSize = thisBkt->size;
//			for (int l = 0; l < buckitSize; l++) {
//				if (val == thisBkt->ary[l].val) {
//					idx = thisBkt->ary[l].idx;
//				}
//			}
//		}
//
//		if (idx != -1)
//			cout << idx + 1 << " ";
//		else
//			cout << -1 << " ";
//
//
//	}
//
//	delete originValues;
//	delete destValues;
//}
//
//
//
//

