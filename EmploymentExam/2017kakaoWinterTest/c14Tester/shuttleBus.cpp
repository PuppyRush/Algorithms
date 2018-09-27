//#include <string>
//#include <vector>
//#include <set>
//#include <algorithm>
//#include <deque>
//#include <cassert>
//#include <stdio.h>
//
//using namespace std;
//#undef time
//
//typedef struct time_
//{
//	short h;
//	short m;
//	time_(short _h, short _m)
//		:h(_h), m(_m)
//	{}
//
//	bool operator<(const time_& t) const
//	{
//		if (h == t.h)
//			return m < t.m;
//		else
//			return h < t.h;
//	}
//
//	bool operator>(const time_& t) const
//	{
//		if (h == t.h)
//			return m > t.m;
//		else
//			return h > t.h;
//	}
//
//	bool operator<=(const time_& t) const
//	{
//		if (h == t.h)
//			return m <= t.m;
//		else
//			return h <= t.h;
//	}
//
//	time_ operator+(const time_& t)
//	{
//		this->h += t.h;
//		if (t.m >= 60)
//		{
//			this->h += t.m / 60;
//			this->m += t.m % 60;
//		}
//		else
//			this->m += t.m;
//
//		if (this->m >= 60)
//		{
//			this->h += this->m / 60;
//			this->m -= (this->m % 60);
//		}
//
//		return *this;
//	}
//
//	time_ operator-(const time_& t)
//	{
//		if (this->m < t.m)
//		{
//			this->h -= ((t.m + 60) / 60);
//			this->m = 60 - (t.m % 60);
//		}
//		else
//			this->m -= t.m;
//		assert(this->h >= 0);
//
//		return *this;
//	}
//
//	time_ operator=(const time_& t)
//	{
//		this->m = t.m;
//		this->h = t.h;
//		return *this;
//	}
//
//	string toString()
//	{
//		char buf[6];
//		sprintf_s(buf, "%02d:%02d", this->h, this->m);
//		return string(buf);
//	}
//};
//
//typedef struct bus
//{
//	const short m_max;
//	const short m_round;
//	const short m_count;
//	short thiscount;
//	short thiscrews;
//	time_ time;
//	vector<pair<time_,deque<time_>>> timetables;
//	deque<time_> thiscrewsQ;
//	bus(short _max, short _time, short _count)
//		:m_max(_max), m_round(_time), m_count(_count), time(time_(9, 0)), thiscount(0), thiscrews(0)
//	{}
//
//	void go()
//	{
//		timetables.push_back(make_pair(time,thiscrewsQ));
//		assert(m_count > thiscount);
//		time = time + time_(0, m_round);
//		thiscount++;
//		thiscrews = 0;
//		thiscrewsQ.clear();
//	}
//
//	void take(time_ crew)
//	{
//		thiscrewsQ.push_back(crew);
//		thiscrews++;
//	}
//
//	short count()
//	{
//		return thiscount;
//	}
//
//	short crews()
//	{
//		return thiscrews;
//	}
//
//	bool isFull()
//	{
//		return m_max == thiscrews;
//	}
//
//	bool isEnd()
//	{
//		return m_count == thiscount;
//	}
//};
//
//
//
//string solution(int n, int t, int m, vector<string> timetable) {
//	string answer = "";
//	std::multiset<time_> crewQ;
//
//	for (string s : timetable)
//	{
//		int h = atoi(s.substr(0, 2).c_str());
//		int m = atoi(s.substr(3, 2).c_str());
//		crewQ.insert(time_(h, m));
//	}
//	
//	short fullcount = 0;
//	bus shuttle(m, t, n);
//	while (!shuttle.isEnd())
//	{
//		int i = 0;
//		for(auto it = crewQ.begin() ; it != crewQ.end() && !shuttle.isFull();)
//		{
//			if (*it <= shuttle.time)
//			{
//				shuttle.take(*it);
//				it = crewQ.erase(it);
//			}
//			else if (*it > shuttle.time)
//				break;
//			else
//				it++;
//		}
//
//		if (shuttle.isFull())
//			fullcount++;
//
//		shuttle.go();
//	}
//
//	answer= "09:00";
//	auto timetables = shuttle.timetables;
//
//	if (fullcount == 0)
//	{
//		if (timetables.back().second.empty())
//			return timetables.back().first.toString();
//
//		auto lastcrew = timetables.back().second.back();
//		if (lastcrew < time_(9, 0))
//			return answer;
//		else
//		{
//			auto lasttime = timetables.back().first;
//			return (lasttime + time_(0, t - 1)).toString();
//		}
//
//	}
//	else if (fullcount == n)
//	{
//		return (timetables.front().second.front() - time_(0, 1)).toString();
//	}
//	
//	for (size_t i = timetables.size() - 1; i >= 0; i--)
//	{
//		auto pair = timetables[i];
//		if (pair.second.size() != m)
//		{
//			return (pair.first + time_(0, t) - time_(0, 1)).toString();
//		}
//	}
//
//	return answer;
//}
//
//int main()
//{
//	//[08:00, 08 : 01, 08 : 02, 08 : 03]
//	/*vector<string> times;
//	times.push_back("08:00");
//	times.push_back("08:01");
//	times.push_back("08:02");
//	times.push_back("08:03");*/
//
//	//[09:10, 09:09, 08:00]
//
//	//[09:00, 09:00, 09:00, 09:00]
//
//	//[23:59]
//	vector<string> times;
//	times.push_back("23:59");
//
//	solution(1, 1, 1, times);
//}