//#define _CRT_SECURE_NO_WARNINGS
//#define MIN(a,b) ((a>b)?b:a)
//#define MAX(a,b) ((a>b)?b:a)
//#define FOR(i,size) for(i ; i < size ; ++i)
//#define FOR_IN(i,size) for(i ; i <= size ; ++i)
//#define FOR_REV(i) for(i ; i >=0 ; --i)
//#define FOR_REV_SIZE(i,size) for(i ; i >=size ; --i)
//
//
//#include <iostream>
//#include <cstring>
//#include <string>
//#include <cmath>
//#include <algorithm>
//#include <vector>
//#include <stack>
//#include <queue>
//#include <map>
//
//using namespace std;
//
//typedef const int C_INT;
//typedef unsigned int UINT;
//typedef const unsigned int C_UINT;
//typedef unsigned char UCHAR;
//typedef const unsigned char C_UCHAR;
//typedef const char C_CHAR;
//typedef const unsigned long long C_ULL;
//typedef unsigned long long ULL;
//
//typedef std::pair<int, int> PINT;
//typedef std::vector<std::vector<int>> V2INT;
//typedef std::vector<int> VINT;
//typedef std::vector<string> VSTR;
//
//using namespace std;
//
//#define MAX 2000
//#define LETTERS 'Z'-'A'+1
//
//V2INT graph;
//const char *numbers[] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
//char root[] = { 'Z','O','T','F','S','E','N' };
//
//int isContain(const string word) {
//	int i = 0;
//	FOR(i, 10) {
//		if (strcmp(word.c_str(), numbers[i]) == 0)
//			return i;
//	}
//	return -1;
//}
//
//VINT solver(VINT letters, int remain, vector<int> solve, string word, bool begin) {
//	
//	int num = isContain(word);
//	if (word.size() > 5)
//		return VINT();
//	else if (num != -1) {
//		solve.push_back(num);
//		begin = true;
//		word = "";
//	}
//	
//	if (remain == 0) {
//		if (begin)
//			return solve;
//		else
//			VINT();
//	}
//	if (begin) {
//		int i = 0;
//		FOR(i, 7) {
//			C_CHAR rt = root[i];
//			if (letters[rt] != 0) {
//				letters[rt]--;
//				auto s = solver(letters, remain - 1, solve, word+(char)(root[i]), false);
//				letters[rt]++;
//				if (s.size() > 0)
//					return s;
//			}
//		}
//		if (i == 7)
//			return VINT();
//	}
//	else {	
//		auto v = graph[*prev(word.end())];
//		if (v.size() == 0)
//			return VINT();
//		int i = 0;
//		FOR(i, v.size()) {
//			if (letters[v[i]] > 0) {
//				letters[v[i]]--;
//				auto s = solver(letters, remain - 1, solve, word + (char)(v[i]), false);
//				letters[v[i]]++;
//				if (s.size() > 0)
//					return s;
//			}
//		}
//	}
//
//	return VINT();
//}
//
//void makeGraph() {
//	
//	
//	graph = V2INT('Z'+1, VINT());
//	int i = 0;
//	FOR(i, 10) {
//		int len = strlen(numbers[i]);
//		int l = 0;
//		FOR(l, len-1) {
//			graph[numbers[i][l]].push_back(numbers[i][l+1]);
//		}
//	}
//	
//}
//
//int _main() {
//
//	freopen("C:\\Users\\goodd\\Downloads\\A-large-practice.in", "r", stdin);
//	//freopen("C:\\Users\\goodd\\Desktop\\A-large.out", "w", stdout);
//	
//	int size = 0;
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.precision(10);
//
//	int caseSize = 0;
//	scanf("%d", &caseSize);
//
//	makeGraph();
//	for (int t = 0; t < caseSize; ++t) {
//
//		VINT letters = VINT('Z'+1);
//		
//		char buf[MAX + 1];
//		scanf("%s", buf);
//		int i = 0;
//		C_INT len = strlen(buf);
//		FOR(i, len) {
//			letters[buf[i]]++;
//		}
//
//		i = 0;
//		auto s = solver(letters, len, VINT(), "", true);
//		sort(s.begin(), s.end());
//
//		cout << "Case #" << (t + 1)<<": ";
//		FOR(i, s.size())
//			cout << s[i];
//		cout << endl;
//	}
//
//	return 0;
//}
