//#include <iostream>
//// #include <cstdio>  // uncomment to use scanf/printf instead of cin/cout
//#include <sstream>
//#include <string>
//#include <deque>
//#include <algorithm>
//using namespace std;
//
//int main() {
//	string line;
//	getline(cin, line);
//
//	stringstream ss(line);
//	int card;
//	ss >> card;
//
//	getline(cin, line);
//	ss = stringstream(line);
//	int n;
//	ss >> n;
//
//	int totalround = n;
//	deque<int> round;
//	while (n--)
//	{
//		int distance;
//		getline(cin, line);
//		ss = stringstream(line);
//		ss >> distance;
//		round.push_back(distance);
//	}
//	
//	
//	deque<int> q;
//	for (int i = 1; i <= card; i++)
//		q.push_back(i);
//
//	while (totalround-- > 0)
//	{
//		deque<deque<int>> tail;
//		int garbage = round.front();
//		round.pop_front();
//		while (q.size() >= garbage*2 )
//		{
//			if (card < garbage)
//				break;
//
//			deque<int> fr;
//
//			for (int i = 0; i < garbage; i++)
//			{
//				fr.push_back(q.front());
//				q.pop_front();
//			}
//
//			deque<int> bk;
//			for (int i = 0; i < garbage; i++)
//			{
//				bk.push_front(q.back());
//				q.pop_back();
//			}
//
//			for (auto b : bk)
//				fr.push_back(b);
//
//			tail.push_front(fr);
//		}
//
//		for (auto _tail : tail)
//			for (auto t : _tail)
//				q.push_back(t);
//
//	}
//	
//	int count = 5;
//	int ans = -1;
//	while (count > 0)
//	{
//		cout << q.front() << endl;
//		q.pop_front();
//		count--;
//	}
//}