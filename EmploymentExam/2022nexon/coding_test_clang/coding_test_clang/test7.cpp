// coding_test_clang.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <deque>

using namespace std;

//long divideGroup(int cur, int prev, const int people, const int groups)
//{
//    //base condition
//    if (cur == groups) 
//    {
//        if (people == 0)
//            return 1;
//        else
//            return 0;
//    }
//
//    if (people == 0) {
//        return 0;
//    }
//
//    long options = 0;
//    for (int i = prev; i <= people; i++) {
//        options += divideGroup(cur + 1, i, people - i, groups);
//    }
//
//    return options;
//}

int getInfectionSequencesCount(int n, vector<int> infectedHouses) {

    vector<int> infectednumberByDay;
    vector<int> lastInfectedHouse;


    for (int i = 0; i < infectedHouses.size(); i++)
    {
        infectedHouses[i] = infectedHouses[i] - 1;
        lastInfectedHouse.push_back(infectedHouses[i]);
    }

    vector<bool> house(n, false);
    for (int inf : infectedHouses)
    {
        house[inf] = true;
    }

    while (lastInfectedHouse.empty() == false)
    {
        deque<int> newInfected;

        for (int houseIdx : lastInfectedHouse)
        {
            if (houseIdx > 0 && !house[houseIdx - 1])
            {
                newInfected.push_back(houseIdx - 1);
                house[houseIdx - 1] = true;
            }
            if (houseIdx < n-1 && !house[houseIdx + 1])
            {
                newInfected.push_back(houseIdx + 1);
                house[houseIdx + 1] = true;
            }
        }

        lastInfectedHouse.clear();

        if (newInfected.size() > 1)
        {
            infectednumberByDay.push_back(newInfected.size());
        }

        lastInfectedHouse = vector<int>(newInfected.begin(), newInfected.end());
    }

    int sum = 0;
    for (int i : infectednumberByDay) {
        sum += tgamma(i+1);
    }

    return sum;
}
int main()
{
    cout << getInfectionSequencesCount(6, {3,5});
    _sleep(10000);
}

