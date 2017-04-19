#define _CRT_SECURE_NO_WARNINGS
#define FOR(l,size) for(l ; l < size ; ++l)

#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <math.h>
#include <deque>

using namespace std;

int insertOnRuntime(int );
int ites(const int size, const int sum);
void print(const deque<int> &q);
vector<int> result;

struct RNG {

	unsigned seed;
	RNG() : seed(1983) {}
	unsigned next() {
		unsigned ret = seed;
		seed = ((seed * 214013u) + 2531011u);
		return ret % 10000 + 1;
	}

};

int main() {

	size_t caseSize = 0;
	scanf("%d", &caseSize);

	for (size_t i = 0; i < caseSize; i++) {

		int sum, size;
		scanf("%d %d", &sum, &size);

		result.push_back(ites(size, sum));
	}

	size_t i = 0;
	FOR(i, caseSize)
		cout << result[i] << endl;
}

int ites(const int size, const int sum) {

	RNG rng;
	deque<int> q;

	int count = 0;

	auto it = deque<int>::iterator();
	it = q.begin();
	int untilSum = 0;
	int i = 0;
	while( i < size ){

		q.push_back(rng.next());

		while(untilSum > sum) {
			untilSum -= q.front();
			q.pop_front();
		}

		if (untilSum == sum)
			count++;

		untilSum += q.back();
		i++;
	}

	return count;
}

int insertOnRuntime(int ref) {
	
	auto end = ((ref - 1) * 214013u + 2531011u);
	end = (end % 10000u) + 1;
	return (int)end;

}

void print(const deque<int> &q) {

	for (int i = 0; i < q.size(); i++)
		cout << q.at(i) << " ";


}