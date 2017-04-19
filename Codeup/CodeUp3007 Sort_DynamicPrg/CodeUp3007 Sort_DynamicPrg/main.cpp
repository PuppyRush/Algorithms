
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <map>

using namespace std;

int* extractIntegerAryFromChars(const int);
int** extractIntegerAryFromMultiChars(const int);
int sumOfAryRecursive(int* ary, int left, int right);

typedef map<int, int> rangeMap;
typedef map<rangeMap, int> Map;
rangeMap range;
Map memo;

int main() {
	

	int valuesSize;
	int rangeSize;
	int *originValues = NULL;

	scanf("%d %d", &valuesSize, &rangeSize);
	while (getchar() != '\n');
	
	
	originValues = extractIntegerAryFromChars(valuesSize);

	int **ranges;
	ranges = extractIntegerAryFromMultiChars(rangeSize);



	int idx = -1;
	int maxValue = -1;
	for (int i = 0; i < rangeSize; i++) {

		int leftIdx = ranges[i][0]-1;
		int rightIdx = ranges[i][1]-1;
		
		if (leftIdx == rightIdx) {
			cout << originValues[leftIdx] << " ";
			continue;
		}
		
		cout << sumOfAryRecursive(originValues, leftIdx, rightIdx) << endl;
		
	}


}

int sumOfAryRecursive(int* ary ,int left, int right) {

	if (left == right)
		return ary[left];

	rangeMap r;
	r.insert(std::make_pair(left, right));

	if (memo.count(r)) {
		return memo.find(r)->second;
	}

	int mid = (left + right) / 2;

	
	int sum = sumOfAryRecursive(ary, left, mid) + sumOfAryRecursive(ary, mid+1, right);
	memo.emplace(r, sum);
	return sum;
}


int** extractIntegerAryFromMultiChars(const int size) {

	int **ranges;
	ranges = new int*[size];
	for (int i = 0; i < size; i++) {
		ranges[i] = new int[2];
		scanf("%d %d", &ranges[i][0], &ranges[i][1]);
		
	}

	return ranges;
}



int* extractIntegerAryFromChars(const int size) {


	int *destAry = new int[size];

	for (int i = 0; i < size; i++) {
		int temp;
		scanf("%d", &temp);
		
		destAry[i] = temp;
	}
	return destAry;
}
