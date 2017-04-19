#define _CRT_SECURE_NO_WARNINGS
#define FOR(l,size) for(l ; l < size ; ++l)

#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;




int kmp(string haystack, string needle, vector<int> pi);
vector<int> getPi(const string& haystack);
string reverseString(const string& str);

int main() {

	vector<int> result;
	int caseSize = 0;
	scanf("%d", &caseSize);

	int i = 0;
	FOR(i, caseSize){

		string haystack;

		cin >> haystack;
		string needle = reverseString(haystack);
		auto pi = getPi(needle);

		result.push_back(kmp(haystack, needle, pi));


	}

	i = 0;
	FOR(i, result.size()) {
		cout << result[i] << endl;
	}
	

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
			if (H_SIZE == begin + matched) {
				return (H_SIZE - matched) * 2 + matched;
			}
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

	return H_SIZE * 2 - 1;

}

vector<int> getPi(const string& haystack) {

	const int STR_LEN = haystack.size();
	vector<int> pi(STR_LEN, 0);

	int begin = 1, matched = 0;

	while(begin + matched < STR_LEN ) {
		if (haystack[begin + matched] == haystack[matched]) {
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

string reverseString(const string& str) {

	const int size = str.size();
	char *reverse = new char[size+1];
	memset(reverse, 0, sizeof(char)*(size+1));
	
	for (int i = 0; i < size; i++)
		reverse[i] = str.at(size - i-1);

	

	return string(reverse);
}