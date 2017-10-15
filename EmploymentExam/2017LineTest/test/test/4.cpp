#include <iostream>
#include <set>
using namespace std;

#define MAX_N 1000

int graph[MAX_N][MAX_N];
int N;

/*
 * Description :
 * Time complexity :
 * Space complexity :
 */
bool solve(set<int> seat, int man) {
    
	if (seat.size() == N)
		return true;
	if (man == N)
		return false;

	bool res = false;
	for (int l = 0; l < MAX_N; l++) {
		int exist = graph[man][l];
		if (exist==1 &&seat.count(exist)==0) {
			seat.insert(l);
			res |=solve(seat, man + 1);
			seat.erase(l);
		}
	}

    return res;
}

int main() {
    int T, K, P, S;
    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> N;

        // reset
        for (int person = 0; person < N; person++) {
            for (int seat = 0; seat < N; seat++) {
                graph[person][seat] = 0;
            }
        }

        cin >> K;

        for (int i = 0; i < K; i++) {
            cin >> P;
            cin >> S;
            graph[P][S] = 1;
        }

        cout << (solve(set<int>(),0) ? 'O' : 'X') << '\n';
    }
    return 0;
}
