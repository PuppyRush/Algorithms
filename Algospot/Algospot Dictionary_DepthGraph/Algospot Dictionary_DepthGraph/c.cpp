#define _CRT_SECURE_NO_WARNINGS
#define FOR(i,size) for(i=0; i <size ; i++)


#include <vector>
#include <algorithm>
#include <string.h>
#include <iostream>

#define PAIR vector<pair<char*, int>> 
#define TWO_VEC vector<vector<int>>

using namespace std;

string solve(const PAIR &src) {

	bool isOrdered = true;
	int root = src[0].first[0]-97;
	int prev = src[0].first[0] - 97;
	const int srcSize = src.size();

	int g[26];
	memset(g, -1, sizeof(int) * 26);

	int i = 0;
	FOR(i, srcSize-1) {
		const int len = std::min<int>(src[i].second, src[i + 1].second);
		int l = 0;
		FOR(l, len) {
			const int pre = src[i].first[l] - 97;
			const int post = src[i+1].first[l] - 97;
			if (pre != post) {				
				if (post == root) {
					g[pre] = root;
					root = pre;
				}
				else if (g[post] != -1)
					;
				else {
					g[prev] = post;
					prev = post;
				}				

				if (g[pre] == post && g[post] == pre)
					return string("INVALID HYPOTHESIS");
				else if (isOrdered && pre > post)
					isOrdered = false;

				break;
			}
		}
	}
	
	string res;
	if (isOrdered) {
		return string("abcdefghijklmnopqrstuvwyz");
	}
	else {

		bool alphabet[26];
		memset(alphabet, true, 26);

		int idx = root;
		
		alphabet[root] = false;
		res.push_back(root + 97);
		while (g[idx] != -1) {
			alphabet[g[idx]] = false;
			res.push_back(g[idx] + 97);
			idx = g[idx];
		}

		for (int i = 0; i < 26; i++) {
			if (alphabet[i])
				res.push_back(97 + i);
		}
	}
	return res;
	
}

TWO_VEC* makeGraph(const PAIR &src) {

	auto adj = new TWO_VEC(26,vector<int>(26,0));

	int i = 0;
	FOR(i, src.size()-1) {
		const int len = std::min<int>(src[i].second, src[i + 1].second);
		int l = 0;
		FOR(l, len) {
			if (src[i].first[l] != src[i + 1].first[l]) {
				int y = src[i].first[l] - 'a';
				int x = src[i + 1].first[l] - 'a';
				adj->at(y)[x] = 1;
				break;
			}
		}
	}
	return adj;
}

void dfs(int here, const TWO_VEC &adj, vector<int> &order, vector<int> &seen) {

	seen[here] = 1;
	
	int there = 0;
	FOR(there, adj.size()) {
		if (adj[here][there] && !seen[there])
			dfs(there,adj,order,seen);
	}
	order.push_back(here);

}

vector<int> topologicalSorc(const TWO_VEC &g) {

	const int size = g.size();
	
	auto seen = vector<int>(size, 0);
	auto order = vector<int>();

	int i = 0;
	FOR(i, size) {
		if (!seen[i])
			dfs(i, g, order, seen);
	}

	reverse(order.begin(), order.end());

	i = 0;
	FOR(i, size)
		cout << order[i] << " ";
	cout << "\n";

	i = 0;
	FOR(i, size) {
		int l = 0;
		FOR(l, size) {
			cout << g[i][l] << " ";
		}
		cout << "\n";
	}

	i = 0;
	FOR(i, size) {
		int l = i + 1;
		FOR(l, size) {
			if (g[order[l]][order[i]])
				return vector<int>();
		}
	}
	
	return order;
}



int main() {

	
	TWO_VEC result;

	int caseSize = 0;
	scanf("%d", &caseSize);

	int i = 0;
	FOR(i, caseSize) {

		int size = 0;
		scanf("%d", &size);

		vector<pair<char*,int>> src(size);

		int l = 0;
		FOR(l, size) {

			char *buf = new char[21];
			scanf("%s", buf);
			src[l] = pair<char*, int>(buf, strlen(buf));
		}

		auto g = makeGraph(src);
		auto res = topologicalSorc(*g);

		result.push_back(res);

		//result.push_back(solve(src));

		/*l = 0;
		FOR(l, size) {
			delete src[l].first;
		}*/
	}

	i = 0;
	FOR(i, result.size()) {		
		if (result[i].size() == 0)
			cout << "INVALID HYPOTHESIS";
		else {
			int l = 0;
			FOR(l, result[i].size())
				printf("%c", result[i][l] + 'a');
		}
		cout << "\n";
	}

	return 0;
}