#define _CRT_SECURE_NO_WARNINGS
#define FOR(l,size) for(l ; l < size ; ++l)
#define FOR_REVERSE(l,min) for (l ; l >=min ; --l)
#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

vector<int> naming(const string& N);
vector<int> result;
vector<int> kmp(string haystack, string needle, vector<int> pi);

int comp(const void* a,const void *b) {
	return (int *)a > (int *)b;
}

int main() {

	string pre, post;

	cin >> pre;
	cin >> post;

	pre.append(post);

	auto pi = naming(pre);	
	
	int i = pre.size();
	vector<int> res;
	while (i > 0) {
		res.push_back(i);
		i = pi[i-1];
	}

	i = res.size() - 1;
	FOR_REVERSE(i, 0)
		cout << res[i] << " ";
/*

	sort(res.begin(), res.end());
	i = 0;
	FOR(i, res.size())
		cout << res[i] << " ";*/
}



vector<int> naming(const string& N) {

	const int STR_LEN = N.size();
	vector<int> pi(STR_LEN, 0);

	int begin = 1, matched = 0;
	
	while (begin + matched < STR_LEN) {
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

