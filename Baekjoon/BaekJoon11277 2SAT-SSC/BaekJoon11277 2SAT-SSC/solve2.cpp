//#define _CRT_SECURE_NO_WARNINGS
//
//
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//const int MAX = 20020;
//
//int N, M;
//vector < int > from[MAX];
//
//inline int neg(int x) {
//	if (x > N) return x - N;
//	else return x + N;
//}
//
//void input() {
//	scanf("%d%d", &N, &M);
//
//	// 그래프 초기화
//	for (int i = 0; i < M; i++) {
//		int f, s;
//		scanf("%d%d", &f, &s);
//
//		// ~X는 N+X로 표현
//		if (f < 0) f = -f + N;
//		if (s < 0) s = -s + N;
//
//		from[neg(f)].push_back(s);
//		from[neg(s)].push_back(f);
//	}
//}
//
//int stack[MAX], top, id[MAX], currentId, groupId[MAX];
//vector < vector < int > > sccGroup;
//
//int traverse(int node) {
//	id[node] = ++currentId;
//	stack[top++] = node;
//
//	// lowlink를 return 값으로 사용
//	int lowlink = id[node];
//	for (auto next : from[node]) {
//		if (id[next] == 0) {
//			// 방문하지 않은 정점
//			lowlink = min(lowlink, traverse(next));
//		}
//		else if (groupId[next] == 0) {
//			// 이미 스택에 들어 있는 정점
//			lowlink = min(lowlink, id[next]);
//		}
//	}
//
//	if (lowlink == id[node]) {
//		// 그룹 추가
//		sccGroup.push_back(vector < int >());
//		while (1) {
//			int now = stack[top - 1];
//			top--;
//
//			// node 하위의 서브트리를 SCC 그룹으로 묶기
//			groupId[now] = sccGroup.size();
//			sccGroup[groupId[now] - 1].push_back(now);
//
//			if (now == node) break;
//		}
//	}
//
//	return lowlink;
//}
//
//void solve() {
//	for (int v = 1; v <= 2 * N; v++) {
//		if (id[v] == 0) {
//			traverse(v);
//		}
//	}
//
//	// x와 ~x가 같은 컴포넌트 안에 속하면 답 없음
//	for (int v = 1; v <= N; v++) {
//		if (groupId[v] == groupId[neg(v)]) {
//			puts("0");
//			return;
//		}
//	}
//
//	// x가 ~x보다 컴포넌트 번호가 작은 경우(그래프 상에서 뒤에 있는 경우) x는 참
//	puts("1");
//	for (int v = 1; v <= N; v++) {
//		printf("%d ", groupId[v] < groupId[neg(v)]);
//	}
//	puts("");
//}
//
//int main() {
//	input();
//
//	solve();
//
//	return 0;
//}