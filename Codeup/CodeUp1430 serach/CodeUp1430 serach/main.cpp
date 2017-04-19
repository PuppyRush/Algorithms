#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>
#include <map>

#define MAX_VALUE 100000000

using namespace std;

int binarySearch(const int*, const int, const int);
int* extractIntegerAryFromChars(const int);

int main() {

	int size;
	map<int, bool> map;
	std::map<int, bool>::iterator it;
	int *originValues;
	int *scracityIdx;


	scanf("%d", &size);
	while (getchar() != '\n');
	originValues = new int[size];
	memset(originValues, false, size);

	for (int i = 0; i < size; i++) {
		int temp;
		scanf("%d", &temp);
		map.insert(pair<int,bool>(temp, true));
	}
	
	//int i = 0;
	//for (i=0 , it = map.begin(); it != map.end(); it++, i++) {
	//	originValues[i] = it->first;
	//}


	int *destValues;
	int destArySize = -1;
	scanf("%d", &destArySize);
	while (getchar() != '\n');
	destValues = extractIntegerAryFromChars(destArySize);

	for (int i = 0; i < destArySize; i++) {
	
		if(map.find(destValues[i])->second)
			cout << 1 << " ";
		else
			cout << 0 << " "; 
	/*	int idx = binarySearch(originValues, size, destValues[i]);

		if (idx!=-1)
			cout << 1 << " ";
		else
			cout << 0 << " ";*/

	}

	delete originValues;
	delete destValues;
}


int* extractIntegerAryFromChars(const int count) {

	char *bufs;
	int *destAry = new int[count];

	for (int i = 0; i < count; i++) {
		int temp;
		scanf("%d", &temp);
		*(destAry + i) = temp;
	}
	return destAry;
}



int binarySearch(const int *array, const int arySize, const int destValue) {


	int right = arySize - 1;
	int left = 0;
	int mid = 0;

	while (left <= right) {

		mid = (left + right) / 2;

		if (array[mid] == destValue)
			return mid + 1;

		if (array[mid] > destValue)
			right = mid - 1;
		else
			left = mid + 1;



	}

	return -1;

}

