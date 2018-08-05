#include <iostream>
#include <random>
#include <bitset>
#include <numeric>
#include <algorithm>

#define GENETIC_TYPE int
#define GENETIC_SIZE 32
#define POOL_SIZE 512
#define COUNT 10000
#define CUT	3
#define SELECTION  12
#define MUTATION 4

int main()
{
	using namespace std;

	std::random_device rd;  
	std::mt19937 gen(rd()); 
	std::uniform_int_distribution<> dis(0,GENETIC_SIZE);
	std::uniform_int_distribution<> dis(SELECTION, POOL_SIZE);
	std::uniform_int_distribution<> random(0, numeric_limits<GENETIC_TYPE>::max());

	//initializing
	vector<GENETIC_TYPE> geneticPool;
	for (int i = 0; i < POOL_SIZE; i++)
	{
		int pos = dis(gen);
		geneticPool.push_back(random(gen));
	}

	int count = 0;
	while (count < COUNT) //loop generation
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
			for (int i = 0; i < MUTATION; i++)
			{
				
			}
		}
	}

}