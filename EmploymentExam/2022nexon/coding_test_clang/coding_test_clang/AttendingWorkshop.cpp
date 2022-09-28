#include <iostream>
#include <map>

using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops

typedef struct Workshops
{
    int idx;
    int start_time;
    int duration;
};

typedef struct Available_Workshops
{
    Workshops* workshops;
    int number_of_workshop;
};

std::map<int, Workshops*> m;
using MapIt = std::map<int, Workshops*>::iterator;

bool isConflict(Workshops& lhs, Workshops& rhs)
{
    if (lhs.start_time < rhs.start_time &&
        rhs.start_time < lhs.start_time + lhs.duration)
    {
        return true;
    }
    else if (rhs.start_time < lhs.start_time &&
        lhs.start_time < rhs.start_time + rhs.duration)
    {
        return true;
    }

    return false;
}

Available_Workshops* initialize(int* start_time, int* duration, int n)
{
    Available_Workshops* ptr = new Available_Workshops;
    if (ptr == nullptr)
        return nullptr;

    auto workshops = new Workshops[n];
    for (int i = 0; i < n; i++)
    {
        int st = start_time[i];
        int du = duration[i];
        workshops[i].start_time = st;
        workshops[i].duration = du;
        workshops[i].idx = i;

        if (m.count(st))
        {
            if (m[st]->duration > du)
            {
                m[st]->duration = du;
            }
        }
        else
        {
            m[st] = workshops;
        }
    }
    ptr->workshops = workshops;

    return ptr;
}

int cal(MapIt it,Workshops* prev, int att)
{
    if (it == m.end()) {
        return att;
    }
    
    if (isConflict(*prev, *it->second))
    {
        return -1;
    }

    while (it != m.end())
    {
        int end = it->second->start_time + it->second->duration-1;
        auto upper = m.upper_bound(end);
        if (upper == m.end())
        {
            return att;
        }

        auto prev = it->second;
        att = std::max(cal(++it, prev, att + 1), att);
    }

    return att;
}

int CalculateMaxWorkshops(Available_Workshops* ptr)
{
    if (ptr == nullptr)
        return 0;

    auto it = m.begin();
    auto prev = it->second;
    return cal(++it, prev, 0);
        
}

int main_______(int argc, char* argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> start_time[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> duration[i];
    }

    Available_Workshops* ptr;
    ptr = initialize(start_time, duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
