#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

#define FOR_REVERSE(i,SIZE) for( ; i >= SIZE ; i--)
#define FOR(i,SIZE) for(i=0 ; i < SIZE ; i++)

int __main() {

	vector<deque<int>> result;

	int caseSize = 0;
	scanf("%d", &caseSize);

	int i = 0;
	FOR(i, caseSize) {
			
		int size = 0;
		scanf("%d", &size);
		while (getchar() != '\n');

		int l = 0;
		vector<int> seq;
		vector<int> org;
		deque<int> res;
			

		char ch = ' ';
		while ( (ch = _getchar_nolock()) != '\n') {
			if (ch == ' ') continue;

			seq.push_back(ch - 48);
			org.push_back(l + 1);
			l++;
		}

		l = size - 1;
		FOR_REVERSE(l, 0) {
			const int idx = l - seq[l];
			const int val = org[idx];
			res.push_front(val);
			org.erase(org.begin()+idx);
		}

		result.push_back(res);
	}

	i = 0;
	FOR(i, result.size()) {
		
		int l = 0;
		FOR(l, result[i].size() )
			cout << result[i][l] << " ";
		cout << "\n";
	}

	return 0;
}