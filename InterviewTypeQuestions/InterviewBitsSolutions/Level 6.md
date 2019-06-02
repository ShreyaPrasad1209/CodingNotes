# Heaps and Maps
## 53. N Max Pair Combinations
https://www.interviewbit.com/problems/n-max-pair-combinations/
```c++
vector<int> Solution::solve(vector<int> &A, vector<int> &B)
{
    priority_queue<pair<int, pair<int, int> > > hp;
    set<pair<int, int> > S;
    int n = A.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    hp.push(make_pair(A[n-1]+B[n-1], make_pair(n-1, n-1)));
    S.insert(make_pair(n-1, n-1));

    vector<int> ans;
    int k=n;
    while(k--)
    {
        pair<int, pair<int, int> > top = hp.top();
        hp.pop();
        ans.push_back(top.first);
        int L = top.second.first;
        int R = top.second.second;

        if( R>0 && L>=0  && S.find(make_pair(L,R-1)) == S.end() )
        {
            hp.push(make_pair(A[L]+B[R-1], make_pair(L,R-1)));
            S.insert(make_pair(L,R-1));
        }
        if( R>=0  && L>0 && S.find(make_pair(L-1, R))==S.end())
        {
            hp.push(make_pair(A[L-1]+B[R], make_pair(L-1,R)));
            S.insert(make_pair(L-1, R));
        }
    }
    return ans;
}
```

## 54. Ways To Form Max Heap
https://www.interviewbit.com/problems/ways-to-form-max-heap/<br>
https://www.geeksforgeeks.org/number-ways-form-heap-n-distinct-integers/<br>
![](../res/2.jpg)
```c++
#define MAXN 105
int dp[MAXN];

int getLeft(int n)
{
    if (n == 1) return 0;

    int h = log2f(n);
    int numh = (1 << h);
    int last = n - ((1 << h) - 1);
    if (last >= (numh / 2)) return (1 << h) - 1;
    else return (1 << h) - 1 - ((numh / 2) - last);
}
int numberOfHeaps(int n)
{
    if (n <= 1) return 1;
    if (dp[n] != -1) return dp[n];

    int left = getLeft(n);
    int ans = (nCk(n - 1, left) * numberOfHeaps(left)) * (numberOfHeaps(n - 1 - left));
    dp[n] = ans;
    return ans;
}
```

## 55. Merge K Sorted List
https://www.interviewbit.com/problems/merge-k-sorted-lists/
```c++
ListNode* Solution::mergeKLists(vector<ListNode*> &A)
{
    map<int, int> myMap;
    for (int i = 0; i < A.size(); ++i)
    {
        ListNode* cur = A[i];
        while (cur != NULL)
        {
            myMap[cur->val]++;
            cur = cur->next;
        }
    }

    ListNode* head = NULL;
    ListNode* cur = NULL;
    for (auto it = myMap.begin(); it != myMap.end(); ++it)
    {
        while (it->second != 0)
        {
            ListNode* list = new ListNode(it->first);
            if (head == NULL)
                head = list, cur = list;
            else
                cur->next = list, cur = cur->next;
            it->second--;
        }
    }
    return head;
}
```

## 56. LRU Cache
https://www.interviewbit.com/problems/lru-cache/
```c++
/*
LRU = Least Recently Used Cache
say a cache of size 4 we insert 0 then 1 then 2 then 3 i.e our cache becomes 3 2 1 0
if we insert another item size becomes 5 we can only have a capacity of 4 so while insertion least recently used gets deleted i.e. 4 3 2 1 [0 gets deleted]
If we access say 2 then it becomes 2 4 3 1 Now if we insert 5, 1 gets removed i.e. 5 2 4 3

this get & set function should be in O(1)
*/
struct Node { int val; Node *next, *prev; };
unordered_map<int, int> myMap;
int maxI, current;
Node *first, *lru;  //Doubly linked list stores key which needs to lookup from hashmap

LRUCache::LRUCache(int capacity)
{
    myMap.erase(myMap.begin(), myMap.end());
    maxI = capacity;
    current = 0;
    first = NULL;
    lru = NULL;
}
int LRUCache::get(int key)
{
    if (current > 0)
    {
        auto it = myMap.find(key);
        if (it != myMap.end())
        {
            int val = it->first;
            int temp = it->second;
            Node *cur = first;
            while (cur->val != val) cur = cur->next;
            Node *prev = cur->prev;
            Node *next = cur->next;
            if (prev != NULL)
            {
                prev->next = next;
                if (next == NULL) lru = prev;
                else next->prev = prev;
                cur->next = first;
                cur->prev = NULL;
                first->prev = cur;
                first = cur;
            }
            return temp;
        }
    }
    return -1;
}
void LRUCache::set(int key, int value)
{
    if (myMap.find(key) == myMap.end())
    {
        Node *temp = new Node{key, NULL, NULL};
        myMap.insert({key, value});
        if (current != maxI)
        {
            current++;
            if (current == 1)
            {
                lru = temp;
                first = lru;
            }
            else
            {
                temp->next = first;
                first->prev = temp;
                first = temp;
            }
        }
        else
        {
            int t = lru->val;
            myMap.erase(myMap.find(t));
            if (lru->prev != NULL)
            {
                Node *toDelete = lru;
                lru = lru->prev;
                lru->next = NULL;
                temp->next = first;
                first->prev = temp;
                first = temp;
                delete(toDelete);
            }
            else
            {
                lru = temp;
                first = lru;
            }
        }
    }
    else
    {
        myMap[key] = value;
        Node *cur = first;
        while (cur->val != key) cur = cur->next;
        Node *prev = cur->prev;
        Node *next = cur->next;
        if (prev != NULL)
        {
            prev->next = next;
            if (next == NULL) lru = prev;
            else next->prev = prev;
            cur->next = first;
            cur->prev = NULL;
            first->prev = cur;
            first = cur;
        }
    }
}
```
# Tree Data Structure