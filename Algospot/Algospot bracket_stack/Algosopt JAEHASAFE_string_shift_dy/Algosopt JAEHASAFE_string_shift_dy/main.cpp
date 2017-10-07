#define _CRT_SECURE_NO_WARNINGS
#define FOR(l,size) for(l ; l < size ; ++l)
#define MIN(a,b) (((a)<(b)) ? (a) : (b))
#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <algorithm>


using namespace std;

enum OrderState {

	LEFT=1,
	RIGHT,
	NONE

};

typedef struct charQ{
	char *str;
	int size;
	int head, tail;
};
int locker(const vector<char*> &src, const int thisIdx, bool );
int locker(const vector<char*> &src, const int thisIdx, charQ &thisState, OrderState preOrder);
charQ makeQ(char* str);
bool compareQ(charQ &q1, char* dest);
charQ& shiftLeft(charQ &q);
charQ& shiftRight(charQ &q);
int kmp(string haystack, string needle, vector<int> pi);

int _strcmp(string &s1, string &s2);
vector<int> getPartialMatch(const string& N);
bool _strcmp(char *s1, char *s2);

int memo[100];

int main() {

	vector<int> result;
	int caseSize = 0;
	scanf("%d", &caseSize);

	int i = 0;
	FOR(i, caseSize) {

		memset(memo, -1, sizeof(int) * 100);

		int size;
		scanf("%d", &size);
		vector<char*> states;
		int l = 0;
		FOR(l, size + 1) {
			char *temp = new char[10001];
			scanf("%s", temp);
			char *str = new char[strlen(temp) + 1];
			strcpy(str, temp);
			delete [] temp;
			states.push_back(str);
		}

		charQ q = makeQ(states[0]);

		result.push_back(locker(states, 0,true));
			
		l = 0;
		FOR(l, states.size())
			delete states[l];

	}

	i = 0;
	FOR(i, result.size()) {
		cout << result[i] << endl;
	}

	//_CrtDumpMemoryLeaks();


}

int locker(const vector<char*> &src, const int thisIdx, bool nextOrder) {

	if (thisIdx == src.size()-1)
		return 0;

	string haystack(src[thisIdx + 1]);	
	string needle(src[thisIdx]);
		
	int val = 0;
	if (nextOrder) 
		val = _strcmp(haystack.append(haystack), needle);
	else
		val = _strcmp(needle.append(needle), haystack);
	
	val += locker(src, thisIdx + 1, !nextOrder);

	return val;

}

int locker(const vector<char*> &src ,const int thisIdx, charQ &thisState, OrderState preOrder) {

	//cout << thisIdx << " " << preOrder << endl;

	if (thisIdx == src.size() && compareQ(thisState, src[thisIdx-1]) )
		return 0;
	else if (thisIdx == src.size())
		return 987654321;

	int res = 987654321;

	int &ref = res;
	if (memo[thisIdx] != -1)
		return memo[thisIdx];

	
	if (preOrder!=NONE && compareQ(thisState, src[thisIdx]))
		res = std::min(locker(src, thisIdx + 1, thisState, NONE), res);
	else
		switch (preOrder) {

			case NONE:
				res = std::min(locker(src, thisIdx, shiftLeft(thisState), LEFT) + 1, res);
				res = std::min(locker(src, thisIdx, shiftRight(thisState), RIGHT) + 1, res);
				break;
			case LEFT:
				res = std::min(locker(src, thisIdx, shiftLeft(thisState), LEFT) + 1, res);
				break;
			case RIGHT:
				res = std::min(locker(src, thisIdx, shiftRight(thisState), RIGHT) + 1, res);
				break;
			default:
				return -1;
		}


	return ref = res;
}

charQ makeQ(char* src) {

	charQ q;
	memset(&q, 0, sizeof(q));
	q.str = new char[strlen(src) + 1];
	strcpy(q.str, src);
	q.size = strlen(src);
	q.head = 0;
	q.tail = strlen(src) - 1;
		
	return q;
}

bool compareQ(charQ &q, char* dest) {

	if (q.head == 0)
		return _strcmp(q.str, dest);
	
	char *pre1 = new char[(q.size - q.head)+1];
	char *post1 = new char[q.head + 1];
	
	memcpy(pre1, q.str + q.head, (q.size - q.head)*sizeof(char));
	memcpy(post1, q.str, q.head*sizeof(char));
	
	char *merged1 = new char[q.size + 1];
	memset(merged1, 0, q.size + 1);
	strncat(merged1,pre1, q.size - q.head);
	strncat(merged1, post1, q.head);

	bool res = _strcmp(merged1, dest);

	delete []  pre1;
	delete [] post1;
	delete [] merged1;
	
	return res;

}

charQ& shiftRight(charQ &q){

	if (q.head == 0) {
		q.head = q.size - 1;
		q.tail -= 1;
	}
	else if (q.tail == 0) {
		q.head -= 1;
		q.tail = q.size - 1;
	}
	else {
		q.head -= 1;
		q.tail -= 1;
	}

	return q;
}

charQ& shiftLeft(charQ &q) {

	if (q.head == q.size-1) {
		q.head = 0;
		q.tail += 1;
	}
	else if (q.tail == q.size-1) {
		q.head += 1;
		q.tail = 0;
	}
	else {
		q.head += 1;
		q.tail += 1;
	}

	return q;
}


int _strcmp(string &s1, string &s2) {
	return kmp(s1, s2, getPartialMatch(s2));
}


bool _strcmp(char *s1, char *s2) {

	string needle(s1);
	return kmp(string(s2), needle, getPartialMatch(needle));
		
}

vector<int> getPartialMatch(const string& N) {
	int m = N.size();
	vector<int> pi(m, 0);

	// KMP 로 자기 자신을 찾는다

	// N 을 N 에서 찾는다. begin=0 이면 자기 자신을 찾아버리니까 안됨!
	int begin = 1, matched = 0;
	// 비교할 문자가 N 의 끝에 도달할 때까지 찾으면서 부분 일치를 모두 기록한다.
	while (begin + matched < m) {
		if (N[begin + matched] == N[matched]) {
			++matched;
			pi[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0)
				++begin;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}


int kmp(string haystack, string needle, vector<int> pi) {

	int max = 0;

	const int H_SIZE = haystack.size();
	const int N_SIZE = needle.size();
	int begin = 0;
	int matched = 0;
	while (begin < H_SIZE) {
		if (matched < H_SIZE && haystack[begin + matched] == needle[matched]) {
			++matched;
			if (matched == N_SIZE)
				return begin;
		}
		else {
			// 예외: matched 가 0 인 경우에는 다음 칸에서부터 계속
			if (matched == 0)
				++begin;
			else {
				// begin 를 matched - pi[matched-1] 만큼 옮길 수 있다
				begin += matched - pi[matched - 1];
				// begin 를 옮겼다고 처음부터 다시 비교할 필요가 없다.
				// 옮긴 후에도 pi[matched-1] 만큼은 항상 일치하기 때문이다.
				matched = pi[matched - 1];
			}
		}
	}

	return -1;

}