#include <iostream>
#include <deque> 

using namespace std;

void printKMax(int arr[], int n, int k) {
    //Write your code here.
    std::deque<int> q;
    int max = -1;

    //init
    for (int i = 0; i < k; i++)
    {
        q.push_back(arr[i]);
        max = std::max(arr[i], max);
    }

    cout << max << " ";

    for (int i = k; i < n ; i++)
    {
        int front = q.front();
        q.pop_front();

        if (front == max)
        {
            max = -1;
            for (int i : q)
            {
                max = std::max(i, max);
            }
        }
         
        int ele = arr[i];
        q.push_back(ele);

        max = std::max(ele, max);

        cout << max << " ";
    }
    cout << endl;
}

int _1main() {

    int t;
    cin >> t;
    while (t > 0) {
        int n, k;
        cin >> n >> k;
        int i;
        int arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        printKMax(arr, n, k);
        t--;
    }
    return 0;
}