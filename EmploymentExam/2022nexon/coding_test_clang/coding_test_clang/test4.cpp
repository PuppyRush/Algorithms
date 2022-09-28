// coding_test_clang.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>

using namespace std;

int maxDifference(vector<int> px) {

    int maxPeriod = numeric_limits<int>::min();
    int startIdx = -1;

    for (int i = 0; i < px.size() - 1; i++)
    {

        if (px[i] > px[i + 1])
        {
            maxPeriod = max(maxPeriod, px[i] - px[startIdx]);
            startIdx = i + 1;
        }
    }

    cout << maxPeriod;

}


int _main4()
{
    _sleep(10000);
}

