#define _CRT_SECURE_NO_WARNINGS
#define FOR(l,size) for(l ; l < size ; ++l)

#include <iostream>
#include <vector>
#include <string.h>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;


class mycomparison
{
	bool reverse;
public:
	mycomparison(const bool& revparam = false)
	{
		reverse = revparam;
	}
	bool operator() (const int& lhs, const int&rhs) const
	{
		if (reverse) return (lhs>rhs);
		else return (lhs<rhs);
	}
};
typedef std::priority_queue<int, std::vector<int>, mycomparison> pQueue;

struct RNG {

	unsigned seed;
	unsigned a;
	unsigned b;
	RNG(int a,int b) : 
		seed(1983), a(a), b(b){}
	unsigned next() {
		unsigned ret = seed;
		seed = ((seed * (long long)a) + b)%(unsigned)20090711;
		return ret;
	}
};

void push(vector<int> &src, const int val) {
	src.push_back(val);

	int present_idx = src.size() - 1;
	int parent_idx = (src.size() + 1) / 2 - 1;
	while (parent_idx > 0) {

		if (src[present_idx] > src[parent_idx]) {
			std::swap<int, int>(src[present_idx], src[parent_idx]);
			present_idx = parent_idx;
			parent_idx = (parent_idx + 1) / 2 - 1;
		}
		else
			break;
	}

}

int pop(vector<int> &src) {
	
	if (src.empty()) {
		cerr << "empty heap\n";
		return -1;
	}

	int biggest = src[0];
	src[0] = src[src.size() - 1];
	src.pop_back();

	int here = 0;
	int next = -1;
	while (src.size() >= here*2+1) {
		int left = next * 2 + 1;
		int right = next * 2 + 2;

		if (src.size()>=right) {
			if (src[left] < src[right]) {
				next = right;
			}
			else {
				next = left;
			}
		}
		else if (src.size() == left) {
			if (src[left] < src[here])
				next = left;
		}
		std::swap<int, int>(src[here], src[next]);

		here = next;
	}
	return biggest;
}

int solve2(const int size, RNG &rng) {

	vector<int> org;
	int res = 0;
	int i = 0;
	FOR(i, size) {
		org.push_back(rng.next());
		sort(org.begin(), org.end());

		const int size = org.size()/2;
		if (org.size() % 2 == 0) {
			res = (res + std::min<int>(org[size], org[size - 1])) % 20090711;
		}
		else
			res = (res + org[size]) % 20090711;
	}
	return res;
}

int solve(const int size,RNG &rng) {
		
	int res = 0;
	pQueue upperHeap(false);
	pQueue lowerHeap(true);

	int i = 0;
	FOR(i, size) {
		int val = rng.next();
		if (upperHeap.size() == lowerHeap.size())
			upperHeap.push(val);
		else
			lowerHeap.push(val);

		if(!lowerHeap.empty()&&!upperHeap.empty() && lowerHeap.top() < upperHeap.top()){
			int min = lowerHeap.top(), max = upperHeap.top();
			lowerHeap.pop();
			upperHeap.pop();
			upperHeap.push(min);
			lowerHeap.push(max);
		}	
		res = (res + upperHeap.top()) % 20090711;
	}

	return res;
}


int main() { 

	vector<int> result;

	int caseSize = 0;
	scanf("%d", &caseSize);

	int i = 0;
	FOR(i, caseSize) {

		int size, a, b;
		scanf("%d %d %d", &size, &a, &b);

		RNG rng(a, b);
		auto res = solve2(size, rng);
		result.push_back(res);
	}

	i = 0;
	FOR(i, result.size()) {
		cout << result[i] << endl;
	}

	
}
