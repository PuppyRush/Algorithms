//
//#include<algorithm>
//#include<iostream>
//#include<string>
//#include<vector>
//
//using namespace std;
//
//vector<int> getpi(const string& N) 
//{
//	int m = N.size();
//	vector<int> pi(m, 0);
//
//	int begin = 1, matched = 0;
//	while (begin + matched < m) {
//		if (N[begin + matched] == N[matched]) {
//			++matched;
//			pi[begin + matched - 1] = matched;
//		}
//		else {
//			if (matched == 0)
//				++begin;
//			else {
//				begin += matched - pi[matched - 1];
//				matched = pi[matched - 1];
//			}
//		}
//	}
//	return pi;
//}
//
//int pa(const string& s1, const string& s2) 
//{
//	int n = s1.size(), m = s2.size();
//	vector<int> pi = getpi(s2);
//	int begin = 0, cnt = 0;
//	while (begin < n) 
//	{
//		if (cnt < m && s1[begin + cnt] == s2[cnt]) 
//		{
//			cnt++;
//			if (begin + cnt == n)
//				return cnt;
//		}
//		else
//		{
//			if (cnt == 0)
//				++begin;
//			else {
//				begin += cnt - pi[cnt - 1];
//				cnt = pi[cnt - 1];
//			}
//		}
//	}
//	return 0;
//}
//
//int main() {
//
//	string s1("ababc");
//	string s2("abcdab");
//	int a = pa(s1, s2);
//	
//
//}
//
