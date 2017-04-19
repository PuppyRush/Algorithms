#define _CRT_SECURE_NO_WARNINGS
#define MIN(a,b) (((a)<(b)) ? (a) : (b))

#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using namespace std;
#define ARY_SIZE 100000
#define WRONG -1
#define OK	  -2

typedef struct B {
	int mod;
	int post;
};

const int _mod[5] = { 1,2,4,5,10 };
int *memo;

int pi2(int* src, const int srcSize, int nextIdx, int val);
int pi(int* src, const int srcSize, int nextIdx, int val);
int verify(vector<int> &src);
int verify2(int *src, int size);

int main() {

	int caseSize;
	scanf("%d", &caseSize);

	int *result = new int[caseSize];

	for (size_t i = 0; i < caseSize; i++) {

		int source[ARY_SIZE];
		int boardSize = 0;

		char temp[10001];
		scanf("%s", temp);

		size_t len = strlen(temp);
		for (size_t l = 0; l < len; l++)
			source[l] = temp[l] - 48;

		memo = new int[len];
		memset(memo, -1, sizeof(int)*len);

		result[i] = pi(source,len, 0,0);

		delete[] memo;
		memo = NULL;
	}

	for (size_t i = 0; i < caseSize; i++)
		cout << result[i] << endl;
}


int pi2(int* src, const int srcSize, int nextIdx, int val) {

	if (nextIdx >= srcSize - 2) {
		if (nextIdx == srcSize)
			return -2;
		else
			return -1;
	}

	int &ref = memo[nextIdx];
	if (ref != -1)
		return ref;

	int ac[5];
	memcpy(ac, src + nextIdx, 3);
	
	vector<B> res;
	for (size_t i = 0; i <= 2 && nextIdx <= srcSize; i++) {

		int temp = pi(src, srcSize, nextIdx, val);
		if (temp != -1) {
			const int mod = verify2(ac,3+i);
			B b;
			b.mod = _mod[mod];
			b.post = temp;
			res.push_back(b);
			if (temp == -2)
				break;
		}

		if (nextIdx != srcSize)
			ac[i + 1] = src[nextIdx++];
	}

	int min = INT32_MAX;
	for (size_t i = 0; i < res.size(); i++) {

		if (res[i].post == -2) {
			min = MIN(min, res[i].mod);
			break;
		}
		else
			min = MIN(min, res[i].mod + res[i].post);
	}

	return ref = val + min;
}


int verify2(int *src, int size) {

	int preMod = -1;
	for (int i = 0; i < size - 2; i++) {

		int newMod;
		int n1 = src[i] - src[i + 1];
		int n2 = src[i+1] - src[i + 2];

		if (n1 == 0 && n2 == 0)
			newMod = 0;
		else if (abs(n1) == 1 && n1 == n2)
			newMod = 1;
		else if (n1 == -n2)
			newMod = 2;
		else if (n1 == n2)
			newMod = 3;
		else
			return 4;

		if (preMod == -1)
			preMod = newMod;
		else if (newMod != preMod) {
			preMod = 4;
			break;
		}
		else
			preMod = newMod;
	}

	return preMod;
}


int pi(int* src,const int srcSize, int nextIdx, int val) {

	if (nextIdx >= srcSize-2 ) {
		if (nextIdx == srcSize)
			return -2;
		else
			return WRONG;
	}
	
	int &ref = memo[nextIdx];
	if (ref != -1)
		return ref;

	vector<int> ac;
	for(int i=0 ; i < 3 ; i++)
		ac.push_back(src[nextIdx++]);
	vector<B> res;
	for (size_t i = 0; i <= 2 && nextIdx <= srcSize; i++) {
				
		int temp = pi(src, srcSize, nextIdx, val);
		if (temp != WRONG) {
			const int mod = verify(ac);
			B b;
			b.mod = _mod[mod];
			b.post = temp;
			res.push_back(b);
			if (temp == OK)
				break;
		}
		
		if(nextIdx!=srcSize)
			ac.push_back(src[nextIdx++]);
	}

	int min = INT32_MAX;
	for (size_t i = 0; i < res.size(); i++) {

		if (res[i].post == OK) {
			min = MIN(min, res[i].mod);
			break;
		}
		else
			min = MIN(min, res[i].mod + res[i].post);
	}

	return ref = val + min;
}

int verify(vector<int> &src) {

	if (src.size() < 2)
		return WRONG;
	
	int preMod = -1;
	vector<int>::iterator it = src.begin();
	while (it != src.end() - 2) {

		int newMod;
		int n1 = *(it) - *(it + 1);
		int n2 = *(it + 1) - *(it + 2);

		if (n1 == 0 && n2 == 0)
			newMod = 0;
		else if (abs(n1)==1 && n1 == n2)
			newMod = 1;
		else if (n1 == -n2)
			newMod = 2;
		else if (n1 == n2)
			newMod = 3;
		else
			return 4;

		if (preMod == -1)
			preMod = newMod;
		else if (newMod != preMod) {
			preMod = 4;
			break;
		}
		else
			preMod = newMod;

		it++;
	}

	return preMod;
}