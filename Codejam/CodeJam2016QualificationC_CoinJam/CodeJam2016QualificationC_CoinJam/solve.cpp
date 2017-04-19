#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <cmath>
#include <math.h>
#include <algorithm>
#include <vector>


#define MIN(a,b) (a>b?b:a)
#define FOR(i,size) for(i ; i < size ; ++i)
#define FOR_IN(i,size) for(i ; i <= size ; ++i)
#define FOR_REV(i,size) for(i=size ; i >0 ; --i)

using namespace std;

typedef const int CINT;
typedef unsigned int UINT;
typedef const unsigned int C_UINT;
typedef unsigned char UCHAR;
typedef std::vector<std::vector<int>> V2INT;
typedef std::vector<int> VINT;

struct ERATOS {
private:
	int number;
	UCHAR *sieve;

public:
	ERATOS(int n) : number(n) {
		sieve = new UCHAR((n + 7) / 8);
		setEratos();
	}

	~ERATOS() {
		delete sieve;
	}

	inline bool isPrime(CINT k) const{
		return sieve[k >> 3] & (1 << (k & 7));
	}



private:
	inline void setComposite(int k) {
		sieve[k >> 3] &= ~(1 << k & 7);
	}

	void setEratos() {
		memset(sieve, 255, sizeof(sieve));
		setComposite(0);
		setComposite(1);
		int sqrtn = std::sqrt(number);
		int i = 2;
		FOR_IN(i, sqrtn) {
			if (isPrime(i)) {
				for (int j = i*i; j <= number; j += i)
					setComposite(j);
			}
		}
	}

	
};


VINT* getBases(CINT k, CINT len) {

	auto *v = new VINT;
	v->push_back(0);
	v->push_back(0);
	int base = 2;
	FOR(base, 11) {	
		int i = 0;
		int sum = 0;
		FOR(i, len) {
			if ((k & (1 << i)) == (1<<i) ) {
				sum += (int)pow(base, i);
			}
		}
		v->push_back(sum);
	}
	return v;
}

void getDivisors(VINT *src) {

	int base = 2;
	
	FOR(base, 11) {

		int l = 2;
		CINT val = src->at(base);
		CINT end = val % 2 == 0 ? val / 2 : val / 3;
		FOR(l, src->at(base) / 2) {
			if (val%l == 0) {
				src->at(base) = l;
				break;
			}
		}
	}	
}

char *intToBinary(int i) {
	static char s[32 + 1] = { '0', };
	int count = 32;

	do {
		s[--count] = '0' + (char)(i & 1);
		i = i >> 1;
	} while (count);

	return s;
}

vector<pair<char*, VINT*>>* solve(C_UINT number, C_UINT len) {

	auto res = new vector<pair<char*, VINT*>>;
	
	CINT defaultValue = (1 << (len - 1)) + 1;
	CINT end = pow(2, len) - 1;
	
	int value = defaultValue;
	FOR(value, end) {
		auto bases = getBases(value, len);
		int base = 2;
		FOR(base, 11) {
			ERATOS era(bases->at(base));
			if (era.isPrime(bases->at(base)))
				break;
		}
			
		if (11 == base)
			continue;
		
		if (number == res->size())
			return res;

		getDivisors(bases);
		res->push_back(pair<char*, VINT*>(intToBinary(value),bases) );
	}

	return res;
}


int main() {

	freopen("C:\\Users\\goodd\\Downloads\\C-small-practice.in", "r", stdin);
	freopen("C:\\Users\\goodd\\Desktop\\C-small-practice.out", "w", stdout);

	int size = 0;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);

	int caseSize = 0;
	scanf("%d", &caseSize);

	for (int l = 0; l < caseSize; ++l) {

		int len, number;
		scanf("%d %d", &len, &number);
					
		auto res = solve(number, len);

		printf("Case #%d:\n", l + 1);
		for (size_t i = 0; i < res->size(); i++) {
			printf("%s ", res->at(i).first);
			CINT s = res->at(i).second->size();
			for (int t = 0; t < s; t++)
				printf("%d ", res->at(i).second->at(t));
			cout << endl;
		}
		
	}

	return 0;
}

