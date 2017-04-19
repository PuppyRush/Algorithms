#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>
#include <map>

#define MAX_VALUE 100000000

using namespace std;


int binarySearch(const int*, const int , const int);
int* extractIntegerAryFromChars(const int);

int* tokeninizer(const string fullString, const char token);
int countTokenInString(const string fullString, const char token);

int main() {
	
	map<int, int> map;
	int size;
	scanf("%d", &size);
	while (getchar() != '\n');
	
	for (int i = 0; i < size; i++) {

		int temp;
		scanf("%d", &temp);
		map.insert(pair<int, int>(temp, i));

	}


	int *destValues;
	int destArySize = -1;
	scanf("%d", &destArySize);
	while (getchar() != '\n');
	destValues = extractIntegerAryFromChars(destArySize);

	for (int i = 0; i < destArySize; i++) {

		const int temp = *(destValues + i);
		if (map.count(temp))
			cout << map.find(temp)->second+1 << " ";
		else
			cout << -1 << " ";

	}

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



int binarySearch(const int *array, const int arySize,  const int destValue) {


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


int* tokeninizer(const string fullString, const char token) {

 	const int splitedArySize = countTokenInString(fullString, token);
	int *splitedAry = new int[splitedArySize];
	size_t leftIdx = 0;
	size_t rightIdx = 1;
	int count = 0; 

	while (count < splitedArySize) {

		if ((rightIdx = fullString.find(token, leftIdx)) == string::npos) {
			splitedAry[count] = stoi(fullString.substr(leftIdx, splitedArySize - leftIdx));
			break;
		}
		
		splitedAry[count] = stoi(fullString.substr(leftIdx, rightIdx - leftIdx));
		

		leftIdx = rightIdx + 1;
		count++;
	}

	return splitedAry;

}

int countTokenInString(const string fullString, char token) {

	size_t idx = 0;
	int count = 0;
	const size_t stringLen = fullString.size();

	while (idx < stringLen) {
	
		count++;

		if ( (idx=fullString.find(token, idx + 1)) != string::npos) {
			idx++;
		}
		else
			break;

	}

	return count;
}