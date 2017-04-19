#define _CRT_SECURE_NO_WARNINGS
#define FOR(l,size) for(l ; l < size ; ++l)

#include <iostream>
#include <vector>
#include <string.h>
#include <map>
#include <algorithm>
using namespace std;

bool isDominated(const map<int, int> &nerds ,pair<int, int> newNerd) {

	auto it = nerds.lower_bound(newNerd.first);
	if (it == nerds.end())
		return false;
	else
		return newNerd.second < it->second;

}

void removeDominatedNerds(map<int, int> &nerds, pair<int, int> newNerd) {

	auto it = nerds.lower_bound(newNerd.first);

	if (it == nerds.begin())
		return;
	--it;
	while (true) {
		if (it->second > newNerd.second)
			return;

		if (it == nerds.begin()) {
			nerds.erase(it);
			break;
		}
		else {
			auto prevIt = it;
			prevIt--;
			nerds.erase(it);
			it = prevIt;
		}
	}
	
}

int solve(map<int, int> &nerds, pair<int,int> &newNerd) {
	
	if (isDominated(nerds, newNerd)) return nerds.size();
	
	removeDominatedNerds(nerds, newNerd);
	nerds[newNerd.first] = newNerd.second;

	return nerds.size();
}

int main() {


	vector<int> result;

	int caseSize = 0;
	scanf("%d", &caseSize);

	int i = 0;
	FOR(i, caseSize) {

		int registration = 0;
		scanf("%d", &registration);
		
		int q = 0, b = 0;
		map<int, int> maps;
		


		int res = 0;
		for (int l = 0; l < registration; l++) {
			q = 0, b = 0;
			scanf("%d %d", &q, &b);
			pair<int, int> p(q, b);
			
			res += solve(maps, p);
		}
		result.push_back(res);
	}

	i = 0;
	FOR(i, result.size()) {
		cout << result[i] << endl;
	}

	//_CrtDumpMemoryLeaks();
}
