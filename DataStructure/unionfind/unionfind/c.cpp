#define _CRT_SECURE_NO_WARNINGS
#define FOR(i,size) for(i=0; i <size ; i++)

#include <vector>
#include <algorithm>
#include <map>
#include <string.h>
#include <iostream>

using namespace std;

class UnionFind {

private:

	typedef struct header {
		int user;
		int size;
		int rival;
		header() {};
		header(int u, int s, int r) : user(u), size(s), rival(r) {};
	}hd;

	int size;
	header **headers;
	vector<int> parent;
	vector<int> rank;

public:

	UnionFind(int size) : parent(size), rank(size, 1), size(size) {
		headers = (header **)malloc(sizeof(header*)*size);
		int i = 0;
		FOR(i, size) {
			parent[i] = i;
			headers[i] = new header(i, 1, -1);
		}
	}

	int find(int u) {
		if (u == parent[u])
			return u;
		else
			return (parent[u] = find(parent[u]));
	}

	int merge(int u, int v) {

		u = find(u);
		v = find(v);

		if (u == v)
			return u;

		auto h_u = headers[u];
		auto h_v = headers[v];
		if (h_u->rival != -1 && h_v->rival != -1)
			if (find(h_u->rival) != find(h_v->rival) ) {
				return -1;
			}

		if (rank[u] > rank[v]) {
			swap(h_u, h_v);
			swap(u, v);
		}
		parent[u] = v;

		if (rank[u] == rank[v])
			++rank[v];

		h_v->rival = h_u->rival == -1 ? h_v->rival : h_u->rival;
		h_v->size += h_u->size;
		headers[u] = nullptr;
		return v;
	}

	bool split(int u, int v) {

		int _u = find(u);
		int _v = find(v);

		if (_u == _v)
			return false;

		auto h_u = headers[_u];
		auto h_v = headers[_v];

		h_u->rival = _v;
		h_v->rival = _u;

		int u_rival = find(h_u->rival);
		int v_rival = find(h_v->rival);
		
		merge(v_rival, u);
		merge(u_rival, v);

		return true;
	}

	int solve() {

		vector<int> biggest;
		bool isAllVi = false;

		int t = 0;
		FOR(t, size) {
			if(headers[t]!=nullptr)
				printf("%d %d %d\n", headers[t]->user, headers[t]->rival, headers[t]->size);
		}

		if (size == 2) {
			return std::max<int>(headers[0]->size, headers[1]->size);
		}

		int i = 0;
		FOR(i, size) {

			if (headers[i] != nullptr) {
				if (headers[i]->rival == -1) {
					isAllVi = true;
					return size;
				}
				int u = parent[headers[i]->rival];
				int v = parent[headers[i]->user];
				auto h_u = headers[u];
				auto h_v = headers[v];

				biggest.push_back(std::max<int>(h_u->size, h_v->size));

				headers[u] = nullptr;
				headers[v] = nullptr;

			}

		}

		std::sort(biggest.begin(), biggest.end());
		return biggest.size() == 1 ? biggest[0] : biggest[0] + biggest[1];

	}

private:
	void swap(header *&a, header *&b) {
		auto c = a;
		a = b;
		b = c;
	}

	void swap(int &a, int &b) {
		int c = a;
		a = b;
		b = c;
	}
};

int main() {

	vector<pair<bool, int>> result;

	int caseSize = 0;
	scanf("%d", &caseSize);

	int i = 0;
	FOR(i, caseSize) {

		int manSize, cmtSize;
		scanf("%d %d", &manSize, &cmtSize);

		UnionFind uf(manSize);

		int l = 0;
		FOR(l, cmtSize) {
			char buf[4];
			scanf("%s", buf);

			int a, b;
			scanf("%d %d", &a, &b);

			if (strcmp(buf, "ACK") == 0) {

				if (uf.merge(a, b) == -1) {
					result.push_back(pair<bool, int>(false, l + 1));
					break;
				}
			}
			else {
				if (!uf.split(a, b)) {
					result.push_back(pair<bool, int>(false, l + 1));
					break;
				}
			}
		}
		if (l == cmtSize)
			result.push_back(pair<bool, int>(true, uf.solve()));
	}

	i = 0;
	FOR(i, result.size()) {
		if (result[i].first)
			cout << "MAX PARTY SIZE IS " << result[i].second << "\n";
		else
			cout << "CONTRADICTION AT " << result[i].second << "\n";
	}

	return 0;
}

