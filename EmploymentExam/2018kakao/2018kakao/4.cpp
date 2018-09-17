//#include <string>
//#include <set>
//#include <vector>
//#include <numeric>
//#include <bitset>
//#include <queue>
//#include <algorithm>
//
//using namespace std;
//
//int solution(vector<int> food_times, long long k) {
//	int answer = 0;
//
//	int size = food_times.size();
//	unsigned long long  sum = 0;
//	sum = accumulate(food_times.begin(), food_times.end(),0);
//
//	if (k > sum)
//		return -1;
//	auto comp = [](const pair<int, int> &l, const pair<int, int>& r)
//	{
//		return l.first < r.first;
//	};
//	//priority_queue<int, vector<int>, decltype(comp)> q(comp);
//	multiset<pair<int,int>> q;
//	for(int i=1 ;i <= size; i++)
//		q.insert(make_pair(food_times.at(i-1),i));
//
//	sum = 0;
//	int criti = 1;
//	int out = 0;
//	while (!q.empty() && k > sum+q.size())
//	{
//		while (!q.empty())
//		{
//			int time = q.begin()->first;
//			if (time <= criti)
//			{
//				q.erase(q.begin());
//				out++;
//			}
//			else
//				break;
//		}
//		sum += q.size()+out;
//		out = 0;
//		criti++;
//	}
//
//	auto comp2 = [](const pair<int, int> &l, const pair<int, int>& r)
//	{
//		return l.second < r.second;
//	};
//
//	vector<pair<int, int>> remains;
//	for (auto p : q)
//	{
//		remains.push_back(make_pair(p.first, p.second));
//	}
//	k -= sum;
//	sort(remains.begin(), remains.end(), comp2);
//	return remains.at(k).second;
//}
//
//int main()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(1);
//	v.push_back(1);
//	v.push_back(1);
//	v.push_back(1);
//	v.push_back(1);
//	v.push_back(1);
//	v.push_back(1);
//	v.push_back(1);
//	v.push_back(1);
//	v.push_back(1);
//	v.push_back(1);
//
//	solution(v, 13);
//}