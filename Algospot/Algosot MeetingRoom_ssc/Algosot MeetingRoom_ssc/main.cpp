#define _CRT_SECURE_NO_WARNINGS
#define MIN(a,b) ((a>b)?b:a)
#define MAX(a,b) ((a>b)?b:a)
#define FOR(i,size) for(i ; i < size ; ++i)
#define FOR_IN(i,size) for(i ; i <= size ; ++i)
#define FOR_REV(i) for(i ; i >=0 ; --i)
#define FOR_REV_SIZE(i,size) for(i ; i >=size ; --i)
#define FOR_EACH(it,c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>

using namespace std;

typedef const int* C_INT_P;
typedef const int C_INT;
typedef unsigned int UINT;
typedef const unsigned int C_UINT;
typedef unsigned char UCHAR;
typedef const unsigned char C_UCHAR;
typedef const char C_CHAR;
typedef const unsigned long long C_ULL;
typedef unsigned long long ULL;

typedef std::pair<int, int> PINT;
typedef std::vector<std::vector<int>> V2INT;
typedef const std::vector<std::vector<int>> C_V2INT;
typedef std::vector<int> VINT;
typedef std::vector<string> VSTR;

using namespace std;

typedef struct ROOM {
	
private:

	typedef struct INFO {
		vector<int> times;
		int number;
		int graph[43200];
		bool isAccessible;
		INFO() {}
		INFO(const int size, int n):number(n) {
			memset(graph, -1, sizeof(int) * 43200);
			isAccessible = true;
		}
	};
	
	INFO info[2];
	int groupSize;

	bool insert(INFO &info, PINT &time) {

		if (info.times.size()==0) {
			info.times.push_back(time.first);
			info.graph[time.first] = time.second;
			return true;
		}

		int i = 0;
		FOR(i, info.times.size()) {
			const int begin = info.times[i];
			PINT ex = PINT(begin,info.graph[begin]);
			if(!( ex.first <= time.first || ex.second >=time.second) || !( ex.second > time.first ) || !(time.second < ex.first) && !(ex.first == time.first && ex.second == time.second))
				if ( (ex.second <= time.first  && time.second > ex.first ) || (  time.first < ex.second && time.second <= ex.first) ) {
					info.graph[time.first] = time.second;
					info.times.push_back(time.first);
					break;
				}	
		}
		if (i == info.times.size())
			return false;
		return true;
	}

public:
	ROOM(const int size){
		info[0] = INFO(size,0);
		info[1] = INFO(size,1);
		groupSize = sizeof(info) / sizeof(info[0]);
	}

	bool addTimetable(PINT &a, PINT &b) {
		
		bool using_a = true, using_b = true;

		if (info[0].isAccessible && !info[1].isAccessible) {
			if (insert(info[0], a))
				return true;
			else if (insert(info[0], b))
				return true;
			else
				return false;
			
		}
		if (info[1].isAccessible && !info[0].isAccessible) {
			if (insert(info[1], a))
				return true;
			else if (insert(info[1], b))
				return true;
			else
				return false;
		}
		
		if (insert(info[0], a)) {
			if (insert(info[1], b))
				return true;
			else {
				info[1].isAccessible = false;
			}
			return true;
		}
		else if (insert(info[0], b)) {
			if (insert(info[1], a))
				return true;
			else {
				info[1].isAccessible = false;
			}
			return true;
		}
		else if (insert(info[1], a)) {
			return true;
		}
		else if(insert(info[1], b)) {
			return true;
		}
		
		return false;
	
	}

	void getSolve() {
		cout << "POSSIBLE\n";
		int i = 0;
		FOR(i, groupSize) {
			if (info[i].isAccessible) {
				int l = 0;
				INFO &in = info[i];
				sort(in.times.begin(), in.times.end());
				FOR(l, in.times.size()) {
					printf("%d %d\n", in.times[l], in.graph[in.times[l]]);
				}
				break;
			}
		}

	}

}R;

int main() {

	int caseSize = 0;
	scanf("%d", &caseSize);

	int i = 0;
	FOR(i, caseSize) {

		int teams = 0;
		scanf("%d", &teams);

		R r(teams);
		int l = 0;

		FOR(l, teams) {
			PINT a, b;
			scanf("%d %d %d %d", &a.first, &a.second, &b.first, &b.second);

			if (r.addTimetable(a, b) == false) {
				cout << "IMPOSSIBLE" << "\n";
				break;
			}
		}
		if (l == teams) {
			r.getSolve();
		}
	}

	return 0;
}
