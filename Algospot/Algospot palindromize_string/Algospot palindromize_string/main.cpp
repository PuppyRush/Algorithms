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
			// ����: matched �� 0 �� ��쿡�� ���� ĭ�������� ���
			if (matched == 0)
				++begin;
			else {
				// begin �� matched - pi[matched-1] ��ŭ �ű� �� �ִ�
				begin += matched - pi[matched - 1];
				// begin �� �Ű�ٰ� ó������ �ٽ� ���� �ʿ䰡 ����.
				// �ű� �Ŀ��� pi[matched-1] ��ŭ�� �׻� ��ġ�ϱ� �����̴�.
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