// coding_test_clang.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void remove_not_exist(string &removed, const string& src)
{
    for (int i = removed.size()-1; i >= 0; i--)
    {
        int idx = src.find(removed[i]);
        if (idx == -1)
        {
            removed = removed.erase(i);
        }
    }
}

string algofn(string lhs, string rhs)
{
    string rtn;
    sort(lhs.begin(), lhs.end()); sort(rhs.begin(), rhs.end());
    set_intersection(lhs.begin(), lhs.end(), rhs.begin(), rhs.end(),
        back_inserter(rtn));
    return rtn;
}

int algofn2(const string& lhs, int rhs, const string& dest, int destStart, string& result)
{
    if (lhs.size() <= rhs)
    {
        //cout << "Res : " << result << endl;
        return result.size();
    }

    int subseq = -1;
    for(int i=rhs ; i < lhs.size() ; i++)
    {
        if ( int founded = dest.find(lhs[i],destStart) ; founded >= 0)
        {
            result += lhs[i];
            int _sub = algofn2(lhs, i+1, dest, founded+1, result);
            result.pop_back();

            if (subseq == -1)
            {
                subseq = _sub;
            }
            else
            {
                subseq = subseq > _sub ? subseq : _sub;
            }
        }
    }

    return subseq;
}

int _mainaa()
{
    string rtn;
    string lhs = "faPkdmElxiyjROOhuFHbaKpmmVAXQcPTiwtCiJC";
    string rhs = "BVObzwbRESpqhpvjiDGmlVJ";

    string result;
   // remove_not_exist(lhs, rhs);
    
    cout << lhs.size() << " " << rhs.size() << endl;

    int idx = algofn2(rhs, 0, lhs, 0, result);
    cout << idx << endl;
    _sleep(10000);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
