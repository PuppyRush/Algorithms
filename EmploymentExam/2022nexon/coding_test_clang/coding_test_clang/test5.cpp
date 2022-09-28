// coding_test_clang.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>

using namespace std;


vector<string> smallestNegativeBalance(vector<vector<string>> debts) {

    int smallest_negative_balance = 0;
    map<string, int> balance;

    //init
    for (auto& info : debts)
    {
        if (balance.find(info[0]) == balance.end())
        {
            balance.insert(make_pair(info[0], 0));
        }
        if (balance.find(info[1]) == balance.end())
        {
            balance.insert(make_pair(info[1], 0));
        }
    }

    //calc
    for (auto& info : debts)
    {
        balance[info[0]] = balance[info[0]] - stoi(info[2].c_str());
        balance[info[1]] = balance[info[1]] + stoi(info[2].c_str());
    }

    vector<pair<string, int> > sortedBalance;

    for (auto& it : balance) {
        sortedBalance.push_back(it);
    }

    sort(sortedBalance.begin(), sortedBalance.end(), [](pair<string, int>& lhs, pair<string, int>& rhs)
        {
            return lhs.second < rhs.second;
        });
}


int _main5()
{
    _sleep(10000);
}

