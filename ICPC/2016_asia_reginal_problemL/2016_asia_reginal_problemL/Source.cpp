#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef struct truck
{
	int weight;
	int which;
};

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;

	queue<truck> q;
	for (auto t : truck_weights)
	{
		truck _t;
		_t.weight = t;
		_t.which = -1;
		q.push(_t);
	}

	deque<truck> b;
	int t_weight = 0;
	for(;; answer++)
	{
		for (auto it = b.begin(); it != b.end(); it++)
			it->which++;

		if (!q.empty() && b.size() < bridge_length && t_weight+q.front().weight <= weight)
		{
			b.push_back(q.front());
			t_weight += q.front().weight;
			q.pop();
			continue;
		}

		if (!b.empty())
		{
			if (b.front().which == bridge_length-1)
			{
				t_weight -= b.front().weight;
				b.pop_front();
			}
		}

		if(b.empty() && q.empty())
			break;
	}

	return answer;
}

int main()
{
	vector<int> a;
	a.push_back(7);
	a.push_back(4);
	a.push_back(5);
	a.push_back(6);
	solution(2, 10, a);

	/*a.push_back(10);
	solution(100, 100, a);*/
}

