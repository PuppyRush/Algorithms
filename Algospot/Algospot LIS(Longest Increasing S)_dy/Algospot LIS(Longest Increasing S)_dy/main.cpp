#define _CRT_SECURE_NO_WARNINGS
#define MAX(a,b) ( ((a)>(b)) ? (a) : (b))

#include <iostream>
#include <vector>
#include <string>
#include <string.h>

typedef struct BUCKIT {
	int val;
	size_t idx;
};

using namespace std;

vector<vector<int>>* combination(int *src, int const size, int const pickSize, vector<int> *picked, int toPick);
BUCKIT lis_part(int *src, int size, int left, int right);
//BUCKIT lis(int*, const int, int,int);
int *memo;

int _lis(int* src,int, int beginIdx);

int main() {


	int caseSize;
	scanf("%d", &caseSize);

	vector<int> result;
	
	for (size_t i = 0; i < caseSize; i++) {

		size_t size = 0;
		scanf("%d", &size);

		memo = new int[size+1];
		int *src = new int[size];
		for (size_t l = 0; l < size; l++) {
			scanf("%d", &src[l]);
		}
		memset(memo, -1, sizeof(int)*(size+1));

		result.push_back( _lis(src,size,-1)-1);
		
		delete [] memo;
		memo = NULL;
	}

	vector<int>::iterator it = result.begin();
	while (it != result.end())
		cout << (*it++) << endl;

}


int _lis(int *src, int size, int beginIdx) {

	
	int &ref = memo[beginIdx+1];
	if (ref != -1)
		return ref;

	ref = 1;
	for (int next = beginIdx + 1; next < size; next++)
		if (beginIdx == -1 || src[beginIdx] < src[next])
			ref = MAX(ref , _lis(src,size, next) + 1);	//자기자신(i)를 포함해야 하므로 1을 더한다.
			
	return ref;

}

//
//int _lis(vector<BUCKIT>& src){
//
//	if (src.empty())
//		return 0;
//	
//	const int SIZE = src.size();	
//	int count = 0;
//
//	for (int i = 0; i < SIZE; i++){
//		
//		int &ref = memo[src[i].idx];
//		int val = 0;
//
//		if (ref != -1)
//			count = ref;
//		else {
//			vector<BUCKIT> A;
//			for (int l = i + 1; l < SIZE; l++)
//				if (src[i].val < src[l].val)
//					A.push_back(src[l]);
//
//			val = _lis(A) + 1;	//자기자신(i)를 포함해야 하므로 1을 더한다.
//		}
//
//		count = MAX(count, val);
//		//if (count > ref)
//			ref = count;
//		
//	}
//
//	//for (int i = 0; i < 8; i++)
//	//	cout << memo[i] << " ";
//	//cout << endl;
//
//	return count;
//
//}


vector<vector<int>>* combination(int *src, int const size, int const pickSize, vector<int> *picked, int toPick) {

	if (pickSize == picked->size()) {
		auto *result = new vector<vector<int>>();
		result->push_back(*picked);
		return result;
	}

	auto *result = new vector<vector<int>>();
	auto *saved = new vector<int>();
	saved->insert(saved->end(), picked->begin(), picked->end());

	for (int i = toPick; i < size; i++) {

		saved->push_back(src[i]);

		auto temp = *combination(src, size, pickSize, saved, i + 1);
		result->insert(result->end(), temp.begin(), temp.end());
		
		saved->clear();
		saved->insert(saved->end(), picked->begin() , picked->end());
	}

	return result;
	
}
//
//BUCKIT lis(int* src, const int size, int left,int right) {
//
//	if (left == right) {
//		BUCKIT b;
//		b.left = left;
//		b.right = right;
//		return b;
//	}
//	
//
//	int mid = (left + right) / 2;
//
//	BUCKIT leftAry  = lis(src, size, left, mid);
//	BUCKIT rightAry = lis(src, size, mid+1, right);
//
//	BUCKIT b;
//
//	if (leftAry.right == rightAry.left - 1) {
//
//		b = lis_part(src, size, leftAry.left, rightAry.right);
//
//	}
//	else{
//
//		BUCKIT leftPart = lis_part(src, size, leftAry.left, leftAry.right);
//		BUCKIT rightPart = lis_part(src, size, rightAry.left, rightAry.right);
//
//		b = (leftPart.right - leftPart.left <= rightPart.right - rightPart.left )? rightPart : leftPart;
//
//	}
//
//	return b;
//
//}
//
//BUCKIT lis_part(int *src, int size, int left, int right) {
//
//	BUCKIT b;
//	b.left = left;
//	b.right = right;
//
//	int leftIdx = left;
//	int count = 0;
//	int max = 0;
//
//	for (size_t i = left; i < right - 1; i++) {
//		if (src[i] >= src[i + 1]) {
//			if (count >= max) {
//				b.right = i;
//				max = count;
//			}
//			else {
//				b.left = i;
//				b.right = i;
//			}
//			count = 0;
//		}
//		else {
//			b.right = i;
//			count++;
//		}
//	}
//	
//	return b;
//}