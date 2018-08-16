//A heap is a complete tree except last level. This property makes it suitable to store in an array

//A heap is used for heap sort to sort an array we create a heap of elements from array.
//In max heap first element is taken out from top (it is max) then put in an array then heap is managed
//Then again top is taken out which is second max this way it is sorted in O(nlogn) complexity

//Heaps can be used to create priority Queue. Priority Queue are queue in which there is priority assosiated
//with every push at the time of pop most priority will be popped first for that max heap is made with pop
//operation top most is poped and heap is recreated
//Priority queues or Binary Heap are used in graph algorithms like Dijikstra

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Heap
{
    #define getParent(n) floor((n-1)/2)
    #define getChild1(n) (2*n + 1)
    #define getChild2(n) (2*n + 2)

private:
    void SwapWithParent(int &pos, int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
        pos = getParent(pos);
    }

    vector<int> heapList;
    bool isMinHeap = true;

public:
    Heap(bool _isMinHeap)
    {
        isMinHeap = _isMinHeap;
    }

    void Insert(int value)
    {
        heapList.push_back(value);
        int pos = heapList.size() - 1;

        if (isMinHeap)
        {
            while (heapList[getParent(pos)] > heapList[pos])
                SwapWithParent(pos, heapList[getParent(pos)], heapList[pos]);
        }
        else
        {
            while (heapList[getParent(pos)] < heapList[pos])
                SwapWithParent(pos, heapList[getParent(pos)], heapList[pos]);
        }   
    }
    
    void Print()
    {
        for (int t : heapList)
            cout << t << " ";
        cout << endl;
    }
};

int main()
{
    Heap heap(false);
    heap.Insert(9);
    heap.Insert(5);
    heap.Insert(13);
    heap.Insert(7);
    heap.Insert(8);
    heap.Insert(20);
    heap.Insert(3);
    heap.Insert(1);
    heap.Insert(6);
    heap.Insert(2);
    heap.Print();
    
    return 0;
}