// coding_test_clang.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>

using namespace std;

const int g_inv_num = numeric_limits<int>::max();

void getCombiniaton(vector<int> arr, set<pair<int,int>>& combination) {
    
    const int r = 2;
    vector<bool> chk(arr.size(), true);
    for (int i = 0; i < r; i++)
        chk[i] = false;


    auto init_pair = []() {return make_pair(g_inv_num, g_inv_num); };

    do {
        pair<int, int> p = init_pair();
        for (int i = 0; i < arr.size(); ++i) {
            if (chk[i] == false)
            {
                if (p.first == g_inv_num)
                {
                    p.first = arr[i];
                }
                else if (p.second == g_inv_num)
                {
                    p.second = arr[i];
                }

                if(p.first != g_inv_num && p.second != g_inv_num)
                {
                    if (combination.count(make_pair(p.second, p.first) ) == 0)
                    {
                        combination.insert(p);
                    }
                    
                    p = init_pair();
                }
            }
        }
        cout << endl;
    } while (next_permutation(chk.begin(), chk.end()));
}
//
//void _closestNumbers(vector<int> numbers) {
//
//    int min = std::numeric_limits<int>::max();
//    set<pair<int, int>> combination;
//    getCombiniaton(numbers, combination);
//
//    set<int> result;
//    for (auto p : combination)
//    {
//        int maybeMin = abs((abs(p.first) - abs(p.second)));
//        if (min >= maybeMin)
//        {
//            min = maybeMin;
//            result.insert(p.first);
//
//        }
//        else {
//            result.clear();
//        }
//    }
//
//    for (auto p : result) {
//        cout << p.first << " " << p.second << endl;
//    }
//}
//


//
//void closestNumbers(vector<int> numbers) {
//
//    int min = std::numeric_limits<int>::max();
//    sort(numbers.begin(), numbers.end());
//
//    for (int i = 0; i < numbers.size() - 1; i++)
//    {
//        min = std::min(min, abs((abs(numbers[i]) - abs(numbers[i + 1]))));
//    }
//
//    for (int i = 0; i < numbers.size() - 1; i++)
//    {
//        if (abs((abs(numbers[i]) - abs(numbers[i + 1]))) == min)
//        {
//            cout << numbers[i] << " " << numbers[i + 1] << endl;
//        }
//    }

}


void closestNumbers(vector<int> numbers) {

    int minVal = std::numeric_limits<int>::max();
    sort(numbers.begin(), numbers.end());

    minVal = numbers[1] - numbers[0];
    const int size = numbers.size();
    for (int i = 2; i < size ; i++)
    {
        minVal = std::min(minVal, abs((abs(numbers[i]) - abs(numbers[i - 1]))));
    }

    for (int i = 1; i < numbers.size(); i++)
    {
        if (abs((abs(numbers[i]) - abs(numbers[i - 1]))) == minVal)
        {
            cout << numbers[i] << " " << numbers[i - 1] << endl;
        }
    }

}
int _main3()
{
    closestNumbers({ 4, -2, -1, 3 });
    

    _sleep(10000);
}

