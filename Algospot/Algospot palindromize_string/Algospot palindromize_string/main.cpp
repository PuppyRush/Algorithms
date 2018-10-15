
#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

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
			if (matched == 0)
				++begin;
			else {
				begin += matched - pi[matched - 1];
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

	while (begin + matched < STR_LEN) {
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


int solution(string s1, string s2) {

	auto pi = getPi(s2);
	return kmp(s1, s2, pi);
	
}

int main() {

	string s1("ababc");
	string s2("abcdab");
	solution(s1,s2);
	

}

