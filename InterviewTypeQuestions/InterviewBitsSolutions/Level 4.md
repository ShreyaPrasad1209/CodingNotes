# Linked List
## 30. Linked List Palindrome
```c++
/*
In O(N) time and O(1) space
Simply go to center of linked list then reverse the right half and then compare by iterating.
Reversing a linked list in O(1) space and O(n) time, if it was doubly linked list O(1) time we can just swap next and prev
*/
Node *cur = head, *next = NULL, *prev = NULL;
tail = head;
while (cur != NULL)
{
    next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
}
head = prev;
```

## 31. Reverse Link List II
https://www.interviewbit.com/problems/reverse-link-list-ii/
```c++
ListNode* Solution::reverseBetween(ListNode* A, int B, int C)
{
    ListNode *head = A, *cur = A, *next = NULL, *prev = NULL;
    int i = 0;
    if (B == 1)
    {
        ListNode *temp = A;
        while (cur != NULL && i < C)
        {
            ++i;
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        temp->next = next;
        head = prev;
    }
    else
    {
        while (cur != NULL && i < B-2) ++i, cur = cur->next;
        ListNode *temp = cur;
        cur = cur->next;
        prev = NULL;
        while (cur != NULL && i < C-1)
        {
            ++i;
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        temp->next->next = next;
        temp->next = prev;
    }
    return head;
}
```

## 32. K Reverse Linked List
https://www.interviewbit.com/problems/k-reverse-linked-list/
```c++
ListNode* Solution::reverseList(ListNode* A, int B)
{
    if(A == NULL || B == 1 || B == 0) return A;
    ListNode* head = NULL, *curr = A, *prev = NULL, *tempHead = NULL;
    for(int i = 0; i < B; i++)
    {
        ListNode *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        if(tempHead == NULL) tempHead = prev;
    }
    head = prev;
    prev = NULL;
    while(curr)
    {
        ListNode* t = NULL;
        for(int i = 0; i < B; i++)
        {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            if(t == NULL) t = prev;
        }
        tempHead->next = prev;
        tempHead = t;
    }
    if(tempHead) tempHead->next = NULL;
    return head;
}
```

## 33. Insertion Sort List
```c++
ListNode* Solution::insertionSortList(ListNode* head)
{
    ListNode *sorted = NULL, *list = head;
    while (list)
    {
        ListNode *curr = list;
        list = list->next;

        if (sorted == NULL || sorted->val > curr->val)
        {
            curr->next = sorted;
            sorted = curr;
        }
        else
        {
            ListNode *tmp = sorted;
            while (tmp)
            {
                ListNode *c = tmp;
                tmp = tmp->next;

                if (c->next == NULL || c->next->val > curr->val)
                {
                    c->next = curr;
                    curr->next = tmp;
                    break;
                }
            }
        }
    }
    return sorted;
}
```

## 34. Merge Sort List
```c++
ListNode* merge(ListNode* A, ListNode* B)
{
    ListNode *head = NULL, *cur = head, *itA = A, *itB = B;
    while (itA && itB)
    {
        if (itA->val < itB->val)
        {
            if (!head) head = itA, cur = itA;
            else cur->next = itA, cur = cur->next;
            itA = itA->next;
        }
        else
        {
            if (!head) head = itB, cur = itB;
            else cur->next = itB, cur = cur->next;
            itB = itB->next;
        }
    }
    while (itA)
    {
        if (!head) head = itA, cur = itA;
        else cur->next = itA, cur = cur->next;
        itA = itA->next;
    }
    while (itB)
    {
        if (!head) head = itB, cur = itB;
            else cur->next = itB, cur = cur->next;
            itB = itB->next;
    }
    return head;
}

ListNode* Solution::sortList(ListNode* A)
{
    if (!A || !A->next) return A;
    ListNode *head = A, *start = A, *end = A->next;
    while (start && end && end->next)
    {
        start = start->next;
        end = end->next->next;
    }
    end = start->next;
    start->next = NULL;
    return merge(sortList(head), sortList(end));
}
```

## 35. Reorder List
https://www.interviewbit.com/problems/reorder-list/
```c++
ListNode* Solution::reorderList(ListNode* A)
{
    if (!A || !A->next) return A;
    ListNode *leftHalf = A, *rightHalf;
    ListNode *slow = A, *fast = A, *prev = NULL;
    // Split list from middle to left and right halves
    while (slow && fast && fast->next)
        prev = slow, slow = slow->next, fast = fast->next->next;
    rightHalf = slow;
    if (prev) prev->next = NULL;

    // Reverse right half
    ListNode *cur = rightHalf, *next = NULL;
    prev = NULL;
    while (cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    rightHalf = prev;

    //Simply merge and end this shit
    ListNode *ans = NULL;
    cur = ans;
    while (leftHalf && rightHalf)
    {
        if (!ans) ans = leftHalf, cur = leftHalf;
        else cur->next = leftHalf, cur = cur->next;
        leftHalf = leftHalf->next;
        cur->next = rightHalf, cur = cur->next;
        rightHalf = rightHalf->next;
    }
    return ans;
}
```

## 36. List Cycle
https://www.interviewbit.com/problems/list-cycle/
```c++
// Floyd’s Cycle detection
ListNode* Solution::detectCycle(ListNode* A)
{
    if (A == NULL || A->next == NULL) return A;
    ListNode *slow = A, *fast = A;
    while (slow != NULL && fast != NULL)
    {
        slow = slow->next;
        if (fast->next == NULL) return NULL;
        else fast = (fast->next)->next;
        if (slow == fast) break;
    }
    if (slow == NULL || fast == NULL) return NULL;
    ListNode *cur = A;
    while (cur != slow)
    {
        cur = cur->next;
        slow = slow->next;
    }
    return cur;
}
```

# Stacks & Queues
## 37. Largest Rectangle In Histogram
https://www.interviewbit.com/problems/largest-rectangle-in-histogram/
```c++
int Solution::largestRectangleArea(vector<int> &A)
{
    stack<int> st;
    int ans = 0;
    A.push_back(-1);
    for (int i = 0; i < A.size(); ++i)
    {
        while (!st.empty() && A[i] <= A[st.top()])
        {
            int height = A[st.top()];
            st.pop();
            int width = i - (st.empty() ? -1 : st.top()) - 1;
            ans = max(ans, height * width);
        }
        st.push(i);
    }
    A.pop_back();
    return ans;
}
```

## 38. Sliding Window Maximum
https://www.interviewbit.com/problems/sliding-window-maximum/
```c++
vector<int> Solution::slidingMaximum(const vector<int> &A, int k)
{
    deque <int> q;
    vector <int> res;
    int n = A.size();
    for(int i = 0; i < n; ++i)
    {
        while (!q.empty() && q.front() < i-k+1) q.pop_front();
        while (!q.empty() && A[i] > A[q.back()]) q.pop_back();
        q.push_back(i);
        if(i >= k-1) res.push_back(A[q.front()]);
    }
    return res;
}
```

## 39. Min Stack
https://www.interviewbit.com/problems/min-stack/
```c++
stack<int> st;
stack<int> minSt;

MinStack::MinStack()
{
    while (!st.empty()) st.pop();
    while (!minSt.empty()) minSt.pop();
}

void MinStack::push(int x)
{
    st.push(x);
    if (minSt.size() == 0) minSt.push(x);
    else
    {
        if (x <= minSt.top()) minSt.push(x);
        else minSt.push(minSt.top());
    }
}

void MinStack::pop()
{
    if (!st.empty())
    {
        st.pop();
        minSt.pop();
    }
}

int MinStack::top()
{
    if (st.empty()) return -1;
    return st.top();
}

int MinStack::getMin()
{
    if (minSt.empty()) return -1;
    return minSt.top();
}
```