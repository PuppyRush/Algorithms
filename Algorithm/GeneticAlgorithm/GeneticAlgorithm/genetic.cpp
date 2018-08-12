#include <iostream>
#include <random>
#include <bitset>
#include <numeric>
#include <algorithm>

#define GENETIC_TYPE int
constexpr auto GENETIC_SIZE = 30ul;
constexpr auto POOL_SIZE = 512ul;
auto INTEGER_MAX = (int)pow(2ul, GENETIC_SIZE);
constexpr auto LOOP_COUNT = 1000ul;
constexpr auto CUT = 3ul;
constexpr auto SELECTION = 12ul;
constexpr auto MUTATION = 4ul;

using namespace std;

void printGraph(vector<int> ary)
{
	sort(ary.begin(), ary.end());

	printf("¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á\n");

	int per = INTEGER_MAX / 10;

	int count[10];
	memset(count, 0, sizeof(int) * 10);

	int sum = 0;
	for (auto val : ary)
	{
		count[val / per]++;
	}

	for (int i = 0; i < 10; i++)
		sum += count[i];

	float ratio[10];
	memset(ratio, 0, sizeof(float) * 10);

	for (int i = 0; i < 10; i++)
		ratio[i] = count[i] / (float)sum;

	for (int i = 0; i < per; i++)
	{
		
	}

	printf("¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á\n");
}

int main()
{
	std::random_device rd;  
	std::mt19937 gen(rd()); 
	std::uniform_int_distribution<> mutationDis(0,GENETIC_SIZE-1);
	std::uniform_int_distribution<> dis(SELECTION, POOL_SIZE);
	std::uniform_int_distribution<> random(0, INTEGER_MAX);

	//initializing
	vector<GENETIC_TYPE> geneticPool;
	for (int i = 0; i < POOL_SIZE; i++)
	{
		geneticPool.push_back(random(gen));
	}

	int count = 0;
	while (count < LOOP_COUNT) //loop generation
	{
		//evaluation
		std::sort(geneticPool.begin(), geneticPool.end(), std::less<GENETIC_TYPE>());
		
		//selection (replace lower rank three with others)
		vector<GENETIC_TYPE> crossoverPool;
		for (int i = 0; i < SELECTION; i++)
			crossoverPool.push_back(geneticPool.at(dis(gen)));

		//crossover
		for (int i = 0; i < SELECTION; i++)
			geneticPool.at(i) = crossoverPool.at(i);

		//mutation
		for (int i = 0; i < SELECTION; i++)
		{
			for (int l = 0; l < MUTATION; l++)
			{
				geneticPool.at(i) ^= (1 << mutationDis(gen));
			}
		}

		printGraph(geneticPool);

		//_sleep(100);
	}

}