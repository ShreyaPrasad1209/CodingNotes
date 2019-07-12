#include <bits/stdc++.h>
using namespace std;

void printMedians(double arr[], int n)
{
    priority_queue<double> maxHeap;
    priority_queue<double, vector<double>, greater<double> > minHeap;

    double med = arr[0];
    maxHeap.push(arr[0]);
    cout << med << endl;

    for (int i = 1; i < n; ++i)
    {
        double x = arr[i];
        // case1 (left side heap has more elements)
        if (maxHeap.size() > minHeap.size())
        {
            if (x < med) minHeap.push(maxHeap.top()), maxHeap.pop(), maxHeap.push(x);
            else minHeap.push(x);
        }
        // case 2 (both heaps are balanced)
        else if (maxHeap.size() == minHeap.size())
        {
            if (x < med) maxHeap.push(x);
            else minHeap.push(x);
        }
        // case 3 (right side heap has more elements)
        else
        {
            if (x > med) maxHeap.push(minHeap.top()), minHeap.pop(), minHeap.push(x);
            else maxHeap.push(x);
        }
        med = (maxHeap.top() + minHeap.top()) / 2.0;
        cout << med << endl;
    }
}

int main()
{
    double arr[] = {5, 15, 10, 20, 3};
    int n = sizeof(arr)/sizeof(double);
    printMedians(arr, n);
    return 0;
}