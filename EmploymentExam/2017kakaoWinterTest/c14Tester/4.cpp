#define _CRT_SECURE_NO_WARNINGS

#define ASCII_BEGIN_ZERO 33
#define ASCII_COUNT_ALPHABET 26
#define ASCII_BEGIN_a	 97
#define ASCII_BEGIN_A	 65




#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <bitset>
#include <algorithm>
#include <functional>   // std::multiplies
#include <numeric>      // std::partial_sum
#include <deque>
#include <queue>
using namespace std;

typedef const int C_INT;
typedef const unsigned int C_UINT;
typedef const unsigned char C_UCHAR;
typedef const char C_CHAR;
typedef const unsigned long long C_ULL;
typedef unsigned int UINT;
typedef unsigned char UCHAR;
typedef unsigned long long ULL;
typedef unsigned long UL;
typedef std::vector<std::vector<int>> V2INT;
typedef std::vector<int> VINT;
typedef std::vector<std::vector<string>> V2STR;
typedef std::vector<string> VSTR;
typedef std::vector<std::vector<char>> V2CHAR;
typedef std::vector<char> VCHAR;




class TIME {

public:

	bool isOverflow;
	int hour;
	int min;


	TIME() {}

	TIME(int h, int m):isOverflow(false),hour(0), min(0) {

		int _h = m / 60;
		h += _h;
		if (h >= 24) {
			isOverflow = true;
			h /= 24;
		}
		hour = h;

		m %= 60;
		min = m;
	}

	bool TIME::operator!=(const TIME &t) const {
		if (this->hour != t.hour && this->min != t.min)
			return true;
		else
			return false;
	}

	bool TIME::operator==(const TIME &t) const {
		if (this->hour == t.hour && this->min == t.min)
			return true;
		else
			return false;
	}

	int TIME::operator<(const TIME &t) const {
		if(this->hour == t.hour && this->min == t.min)
			return 0;
		if (this->hour > t.hour)
			return 1;
		if (this->hour < t.hour)
			return -1;
		if (this->hour == t.hour) {
			if (this->min > t.min)
				return 1;
			else if (this->min < t.min)
				return -1;
			else
				return 0;

		}
		return 0;
	}

	bool TIME::operator<=(const TIME &t) const {
		if (this->hour == t.hour && this->min == t.min)
			return true;
		if (this->hour > t.hour)
			return false;
		if (this->hour < t.hour)
			return true;
		if (this->hour == t.hour) {
			if (this->min > t.min)
				return false;
			else if (this->min < t.min)
				return true;
			else
				return false;

		}
		return false;
	}

	int TIME::operator>(const TIME &t) const {
		if (this->hour == t.hour && this->min == t.min)
			return 0;
		if (this->hour > t.hour)
			return -1;
		if (this->hour < t.hour)
			return 1;
		if (this->hour == t.hour) {
			if (this->min > t.min)
				return -1;
			else if (this->min < t.min)
				return 1;
			else
				return 0;

		}
		return 0;
	}

	bool TIME::operator>=(const TIME &t) const {
		if (this->hour == t.hour && this->min == t.min)
			return true;
		if (this->hour > t.hour)
			return false;
		if (this->hour < t.hour)
			return true;
		if (this->hour == t.hour) {
			if (this->min > t.min)
				return false;
			else if (this->min < t.min)
				return true;
			else
				return false;

		}
		return false;
	}

	TIME TIME::operator+(const TIME time) {

		int _h = this->hour + time.hour;
		int _m = this->min + time.min;
		
		return TIME(_h, _m);
	}

	TIME TIME::operator-(const TIME time) {

		
		int _h = this->hour - time.hour;
		int _m = this->min - time.min;
		if (_m < 0) {
			_m += 60;
			_h -= 1;
		}
		if (_h < 0)
			_h += 24;

		return TIME(_h, _m);
	}

	TIME TIME::operator*(const int number) {
		int _m = this->min*number;
		return TIME(this->hour, _m);
	}

	friend std::ostream& TIME::operator << (std::ostream &os, const TIME& time);
};

std::ostream& operator << (std::ostream &os, const TIME& time) {
	cout.fill('0');
	cout.width(2);
	os << time.hour << ":";

	cout.fill('0');
	cout.width(2);
	os<< time.min << endl;
	return os;
}

class BUS {

public :

	TIME interval;
	TIME startTime;
	int exceed;
	int number;
	vector<TIME> crews;
	bool isFull;
	bool isEmpty;

	explicit BUS(TIME inte, TIME start, int exc, int number, queue<TIME> &waiters):number(number),isFull(false),isEmpty(true),
	interval(inte), startTime(start), exceed(exc){

		const int count = number - 1;
		while (!waiters.empty() && crews.size() < exceed) {
			if (waiters.front() <= startTime + (interval*count)) {
				isEmpty = false;
				crews.push_back(waiters.front());
				waiters.pop();
			}
			else
				break;
		}
		if(crews.size() == exceed) {
			isFull = true;
		}

	}

	TIME GetStartTime() {
		return startTime + (interval*(number - 1));
	}

};




int main() {
	


	int count = 0;
	int _cycle = 0;
	int quota = 0;

	scanf("%d %d %d", &count, &_cycle, &quota);
	TIME cycle(0, _cycle);
	TIME startTime = TIME(9, 0);

	int number = 0;
	scanf("%d", &number);

	vector<TIME> crews;
	for (int i = 0; i < number; i++) {
		int h = 0;
		int m = 0;
		scanf("%2d:%2d ", &h, &m);
		crews.push_back(TIME(h, m));
	}

	sort(crews.begin(), crews.end(), [](const TIME &l, const TIME &r) { return (l>r) > 0 ? true : false; });

	queue<TIME> orderedCrews;
	for each(TIME t in crews) {
		orderedCrews.push(t);
	}

	deque<BUS> buses;
	for (int i = 0; i < count ; i++)
		buses.push_back(BUS(cycle,startTime,quota, i + 1, orderedCrews));

	//check
	

	const TIME lastCrew = buses.back().crews.back();
	for (int l = buses.size()-1 ; l >= 0; l--) {
		const auto crews = buses[l].crews;
		for (int t = crews.size()-1 ; t >= 0 ; t--){
			if (lastCrew != crews[t]) {
				cout << crews[t];
				l = -1;
				break;
			}
		}
	}
	

}