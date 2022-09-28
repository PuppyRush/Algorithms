// coding_test_clang.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>

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

long countWaystoDivide(int people, int group)
{
    //base condition
    if (people < group) {
        return 0;
    }

    vector<vector<long> > ary(people + 1, vector<long>(group + 1));

    for (int i = 1; i <= people; i++) {
        ary[i][1] = 1;
    }

    ary[0][0] = 1;

    for (int i = 1; i <= people; i++) 
    {
        for (int j = 2; j <= group; j++) 
        {
            if (i >= j) {
                ary[i][j] = ary[i-j][j] + ary[i-1][j-1];
            }
            else {
                ary[i][j] = ary[i-1][j-1];
            }
        }
    }

    return ary[people][group]; 
}


int main6()
{
    cout << countWaystoDivide(7, 3);
    _sleep(10000);
}

