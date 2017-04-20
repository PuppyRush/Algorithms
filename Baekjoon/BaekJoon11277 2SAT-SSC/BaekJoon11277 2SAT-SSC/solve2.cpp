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
//	// �׷��� �ʱ�ȭ
//	for (int i = 0; i < M; i++) {
//		int f, s;
//		scanf("%d%d", &f, &s);
//
//		// ~X�� N+X�� ǥ��
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
//	// lowlink�� return ������ ���
//	int lowlink = id[node];
//	for (auto next : from[node]) {
//		if (id[next] == 0) {
//			// �湮���� ���� ����
//			lowlink = min(lowlink, traverse(next));
//		}
//		else if (groupId[next] == 0) {
//			// �̹� ���ÿ� ��� �ִ� ����
//			lowlink = min(lowlink, id[next]);
//		}
//	}
//
//	if (lowlink == id[node]) {
//		// �׷� �߰�
//		sccGroup.push_back(vector < int >());
//		while (1) {
//			int now = stack[top - 1];
//			top--;
//
//			// node ������ ����Ʈ���� SCC �׷����� ����
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
//	// x�� ~x�� ���� ������Ʈ �ȿ� ���ϸ� �� ����
//	for (int v = 1; v <= N; v++) {
//		if (groupId[v] == groupId[neg(v)]) {
//			puts("0");
//			return;
//		}
//	}
//
//	// x�� ~x���� ������Ʈ ��ȣ�� ���� ���(�׷��� �󿡼� �ڿ� �ִ� ���) x�� ��
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