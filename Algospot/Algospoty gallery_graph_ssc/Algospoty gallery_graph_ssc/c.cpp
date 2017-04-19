#define _CRT_SECURE_NO_WARNINGS
#define FOR(i,size) for(i=0; i <size ; i++)
#define VECS std::vector<std::vector<int>>
#define INT_PAIR pair<int,int>

#include <vector>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

enum INSTALLATION {
	WATCHED=0,
	INSTALL ,
	UNWATCHED,
};

enum TOUR {
	VISITED=0,
	UNVISTED
};


typedef struct INFO {

private:

	int visitedSequence = 0;
	int installedNumber = 0;
	int galleryNumber = 0;
	vector<TOUR> gallery;
	VECS graph;

public:

	INFO(int gallerySize) : visitedSequence(0), installedNumber(0), galleryNumber(gallerySize)
		, gallery(gallerySize, UNVISTED){
		graph = VECS(gallerySize, std::vector<int>());
	}

	int getSSC_Number() {
		return installedNumber;
	}

	void conntectedGallery(int begin, int end) {
		graph[begin].push_back(end);
		graph[end].push_back(begin);
	}

	void SSC() {
		
		int i = 0;
		FOR(i, gallery.size()) {
			if (gallery[i] == UNVISTED && solve(i) == UNWATCHED) {
				++installedNumber;
			}
		}
	}

private:

	INSTALLATION solve(int here) {
		
		gallery[here] = VISITED;
		int ins[3] = { 0,0,0 };
		for (int i = 0; i < graph[here].size(); i++) {
			int there = graph[here][i];
			if(gallery[there] == UNVISTED)
				ins[solve(there)]++;
		}

		if (ins[UNWATCHED]) {
			++installedNumber;
			return INSTALL;
		}
		if (ins[INSTALL]) {
			return WATCHED;
		}
		return UNWATCHED;
	}


}Info;


int main() {

	int caseSize = 0;
	scanf("%d", &caseSize);

	int i = 0;
	FOR(i, caseSize) {


		int ga, line;
		scanf("%d %d", &ga, &line);
		Info G(ga);

		int l = 0;
		FOR(l, line) {
			int begin, end;
			scanf("%d %d", &begin, &end);
			G.conntectedGallery(begin, end);
		}

		G.SSC();
		cout << G.getSSC_Number() << "\n";

	}

	return 0;
}
