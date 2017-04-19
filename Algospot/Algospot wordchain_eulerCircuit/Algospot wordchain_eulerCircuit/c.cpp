#define _CRT_SECURE_NO_WARNINGS
#define FOR(i,size) for(i=0; i <size ; i++)


#include <vector>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <queue>

using namespace std;


typedef struct WORD {
	char *word;
	char front;
	char back;
	
	WORD(char* str, char f, char b) :word(str),front(f),back(b) {}
}W;

typedef struct ROOM {
	std::queue<WORD> words;
}R;

#define TWO_VEC vector<vector<R>>

int in[26];
int out[26];

void solve(int here, vector<int> &circuit, TWO_VEC &adj) {

	int there = 0;
	
	printf("========here : %c===\n", here+'a');

	FOR(there, adj.size()){

		//printf("   -there : %c===\n", there+'a');

		auto &words = adj[here][there].words;
		while ( words.size() > 0) {
			words.pop();
			solve(there, circuit,adj);
		}
	}
	printf("push : %c===\n", here + 'a');
	circuit.push_back(here);
}

TWO_VEC& getEuler(vector<int> &circuit,const TWO_VEC &src, TWO_VEC &adj) {

	int l = 0;
	int i = 0;
	FOR(i, src.size()) {
		if (in[i]>0 && out[i] == in[i] + 1){
			solve(i, circuit, adj);
			return adj;
		}
	}
	
	l = 0;
	FOR(l, adj.size()) {
		if (out[l] > 0) {
			solve(l, circuit, adj);
			return adj;
		}
	}

	solve(0, circuit, adj);
	return adj;
}

void countDoor(const TWO_VEC &adj) {
	int l = 0;
	int i = 0;
	FOR(i, adj.size()) {
		
		FOR(l, adj[i].size()) {
			out[i] += adj[i][l].words.size();
			in[i] += adj[l][i].words.size();
		}
		//printf("%c : %d, %d\n", i+'a', in[i], out[i]);
	}
}

bool check() {

	int plus = 0;
	int i = 0;
	FOR(i, 26) {
		int delta = abs(out[i] - in[i]);
		if (plus>1 || delta < -1 || 1 < delta)
			return false;
		if (delta == 1)
			plus++;
	}
	return true;
}

void makeGraph(TWO_VEC &src, TWO_VEC &adj,const int size) {
	
	int l = 0;
	
	FOR(l, size) {
		char *buf = new char[11];
		scanf("%s", buf);
		int len = strlen(buf);
		char a = buf[0] - 'a';
		char b = buf[len - 1] - 'a';

		W w = W(buf, a, b);
		src[a][b].words.push(w);
		adj[a][b].words.push(w);

	}
}

int main() {

	int caseSize = 0;
	scanf("%d", &caseSize);

	int i = 0;
	FOR(i, caseSize) {
	
		memset(in, 0, sizeof(int) * 26);
		memset(out, 0, sizeof(int) * 26);

		int size = 0;
		scanf("%d", &size);

		auto adj = TWO_VEC(26, vector<R>(26));
		auto src = TWO_VEC(26, vector<R>(26));
		makeGraph(src, adj, size);
		countDoor(src);
	

		TWO_VEC adj_copy = adj;
			
		vector<int> s;
		getEuler(s, src, adj_copy);
		reverse(s.begin(), s.end());

		int l = 0;
		FOR(l, s.size()) {
			printf(" %c\n", s[l] + 'a');
		}

		if (s.size() - 1 != size) {
			cout << "IMPOSSIBLE";
		}
		else{

			int l = 0;
			FOR(l, s.size() - 1) {
				printf("%s ", src[s[l]][s[l + 1]].words.front().word);
				src[s[l]][s[l + 1]].words.pop();
			}
		}
		cout << "\n";
	}

	return 0;
}
