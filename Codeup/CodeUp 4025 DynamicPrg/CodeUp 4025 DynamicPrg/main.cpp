#define _CRT_SECURE_NO_WARNINGS
#define MAX(a,b) (((a)>(b))?(a):(b))
#define FOR(i,begin,end) for(int i = begin ; i < end; i++)

#include <iostream>

using namespace std;

int findHighResolutionOfRecursive(const int *source, const size_t arySize, int leftIdx,int sum);

int main() {

	size_t arySize;
	int *source;

	scanf("%d", &arySize);
	source = new int[arySize];

	int i = 0;
	FOR(i,0,arySize){
		scanf("%d", &source[i]);
	}
	

	cout << findHighResolutionOfRecursive(source, arySize, 0,1);

}

int findHighResolutionOfRecursive(const int *source, const size_t arySize, int curIdx, int sum) {

	if (curIdx == arySize-1) {
		return 1;
	}

	for(int i=curIdx ; i < arySize ; i++){
		if (source[curIdx] >= source[curIdx + i + 1])
			return MAX( sum, findHighResolutionOfRecursive(source, arySize, i+1, sum) )+1;
	}
	
	return sum;
}