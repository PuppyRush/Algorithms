#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef struct truck
{
	int weight;
	int which;
	truck(int we, int wh)
		:weight(we), which(wh)
	{}
};

typedef struct bridge
{
	deque<truck> in;
	queue<truck> wait;
	size_t time;
	size_t now_weight;
	const size_t weight;
	const size_t length;
	bool going;

	bridge(int bridge_length, int weight, vector<int>& truck_weights)
		:length(bridge_length),weight(weight),time(1),now_weight(0),going(false)
	{
		for (auto t : truck_weights)
			wait.push(truck(t, 0));
	}

	bool isFull()
	{
		return in.size() == length;
	}
	
	bool tooWeight()
	{
		return now_weight + wait.front().weight > weight;
	}

	void go()
	{
		if (wait.empty())
			return;

		if (!isFull() && !tooWeight())
		{
			in.push_back(truck(wait.front()));
			now_weight += wait.front().weight;
			wait.pop();
		}
	}

	void ahead()
	{
		for (auto it = in.begin(); it != in.end(); it++)
			it->which++;

		while( !in.empty())
		{
			if (in.front().which == length)
			{
				now_weight -= in.front().weight;
				in.pop_front();
				continue;
			}
			else
				break;
		}
		time++;
	}

	bool finish()
	{
		return wait.empty() && in.empty();
	}
};

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;

	bridge b(bridge_length, weight, truck_weights);

	while (!b.finish())
	{
		b.go();
		b.ahead();
	}

	return answer;
}

int main()
{
	vector<int> a;
	/*a.push_back(7);
	a.push_back(4);
	a.push_back(5);
	a.push_back(6);
	solution(2, 10, a);*/

	a.push_back(10);
	//a.push_back(10);
	//a.push_back(10);
	//a.push_back(10);
	//a.push_back(10);
	//a.push_back(10);
	//a.push_back(10);
	//a.push_back(10);
	//a.push_back(10);
	//a.push_back(10);
	solution(100, 100, a);
}

