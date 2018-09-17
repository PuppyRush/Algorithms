//#include <queue>
//#include <map>
//#include <set>
//using namespace std;
//
////std::priority_queue<int, std::vector<int>, std::less_equal<int>> q;
//
//std::multiset<int, less<int>> q;
//
//vector<int> solution(int N, vector<int> stages) 
//{
//	vector<int> answer;
//	answer.reserve(N);
//
//	for (int s : stages)
//	{
//		q.insert(s);
//	}
//
//	auto comp = [](const pair<float, int> lhs, const pair<float, int> rhs)
//	{
//		if (lhs.first == rhs.first)
//			return lhs.second < rhs.second;
//		else
//			return lhs.first > rhs.first;
//	};
//
//	set<pair<float, int>, decltype(comp)> failratio(comp);
//	int nomi = 0;
//	for (int i = 1; i <= N ; )
//	{
//		if (q.empty())
//		{
//			float ratio;
//			ratio = nomi == 0 ? 0 : nomi / (static_cast<float>(q.size() + nomi));
//			failratio.insert(make_pair(ratio, i));
//			i++;
//			nomi = 0;
//			continue;
//		}
//
//		const int st = *q.begin();
//		if (st > i)
//		{
//			float ratio;
//			ratio = nomi == 0 ? 0 : nomi / (static_cast<float>(q.size()+nomi));
//			failratio.insert(make_pair(ratio, i));
//			i++;
//			nomi = 0;
//			continue;
//		}
//			
//		nomi++;
//		q.erase(q.begin());
//	}
//
//	for (auto p : failratio)
//		answer.push_back(p.second);
//
//	return answer;
//}
//
//int main()
//{
//	//[2, 1, 2, 6, 2, 4, 3, 3]
//	vector<int> v;
//	v.push_back(4);
//	v.push_back(4);
//	v.push_back(4);
//	v.push_back(4);
//	solution(4,v);
//}