//#include <queue>
//#include <string>
//#include <vector>
//#include <map>
//#include <unordered_set>
//using namespace std;
//
//
//
//int solution(vector<int> stats) {
//
//	std::priority_queue<size_t, vector<size_t>, std::greater<size_t>> pq;
//	pq.push(stats[0]);
//
//	const auto len = stats.size();
//	for (int i = 1; i < len; i++)
//	{
//		if (stats[i] < pq.top())
//		{
//			pq.push(stats[i]);
//		}
//	}
//	
//	return pq.size();
//}
//
//int main()
//{
//	vector<int> s;
//	s.push_back(6);
//	s.push_back(5);
//	s.push_back(4);
//	s.push_back(1);
//	s.push_back(2);
//	s.push_back(3);
//
//	solution(s);
//}