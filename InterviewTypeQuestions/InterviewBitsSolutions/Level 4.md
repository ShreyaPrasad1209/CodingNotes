# Linked List
## Linked List Palindrome
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

## Reverse Link List II
https://www.interviewbit.com/problems/reverse-link-list-ii/
```c++
ListNode* Solution::reverseBetween(ListNode* A, int B, int C)
{
    ListNode *cur = A, *start = NULL, *startTemp = NULL, *prev = NULL;
    int length = 0;
    while (length < B)
    {
        length++;
        if (length == B-1) start = cur;
        else if (length == B) startTemp = cur;
        prev = cur;
        cur = cur->next;
    }
    ListNode *end = NULL, *endTemp = NULL, *temp = NULL;
    while (length < C)
    {
        length++;
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
        if (length == C)
        {
            endTemp = prev;
            end = cur;
            startTemp->next = end;
            if (start != NULL) start->next = endTemp;
            else if (start == NULL) A = endTemp;
        }
    }
    return A;
}
```

## K Reverse Linked List
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

## Insertion Sort List
```c++
ListNode* Solution::insertionSortList(ListNode* A)
{
    if (A == NULL) return A;
    ListNode *cur = A->next, *prev = A, *head = A;
    ListNode *temp, *check, *checkPrev;
    while (cur != NULL)
    {
        temp = cur->next;
        if (cur->val < prev->val)
        {
            check = head;
            checkPrev = NULL;
            while (check != cur)
            {
                if (check->val > cur->val) break;
                checkPrev = check;
                check = check->next;
            }
            if (checkPrev == NULL)
            {
                head = cur;
                cur->next = check;
                prev->next = temp;
                cur = temp;
            }
            else
            {
                checkPrev->next = cur;
                cur->next = check;
                prev->next = temp;
                cur = temp;
            }
        }
        else
        {
            prev = cur;
            cur = temp;
        }
    }
    return head;
}
```

## Merge Sort List
```c++
ListNode* merge(ListNode* A, ListNode* B)
{
    if (A == NULL) return B;
    if (B == NULL) return A;
    ListNode *head = NULL;
    if (A->val < B->val)
    {
        head = A;
        A = A->next;
    }
    else
    {
        head = B;
        B = B->next;
    }
    ListNode *temp = head;
    while (A != NULL && B != NULL)
    {
        if (A->val < B->val)
        {
            temp->next = A;
            A = A->next;
        }
        else
        {
            temp->next = B;
            B = B->next;
        }
        temp = temp->next;
    }
    if (A != NULL) temp->next = A;
    else temp->next = B;
    return head;
}

ListNode* Solution::sortList(ListNode* A)
{
    ListNode *head = A;
    if (head == NULL || head->next == NULL) return head;
    ListNode *start = A;
    ListNode *end = A->next;
    while (end != NULL && end->next != NULL)
    {
        start = start->next;
        end = (end->next)->next;
    }
    end = start->next;
    start->next = NULL;
    return merge(sortList(head), sortList(end));
}
```

## Reorder List
https://www.interviewbit.com/problems/reorder-list/
```c++
ListNode* Solution::reorderList(ListNode* A)
{
    if (A == NULL || A->next == NULL) return A;
    ListNode *temp, *prev, *mid = A, *cur = A, *newCur, *newHead, *newTemp, *newPrev;
    while (cur != NULL && cur->next != NULL)
    {
        prev = mid;
        mid = mid->next;
        cur = (cur->next)->next;
    }
    prev->next = NULL;
    newCur = mid;
    while (newCur != NULL)
    {
        newTemp = newCur->next;
        if (newCur == mid)
        {
            newPrev = newCur;
            newCur->next = NULL;
            newCur = newTemp;
        }
        else
        {
            newCur->next = newPrev;
            newPrev = newCur;
            newCur = newTemp;
        }
    }
    newHead = newPrev;
    newCur = newHead;
    cur = A;
    while (newCur != NULL && cur != NULL)
    {
        prev = cur;
        newPrev = newCur;
        temp = cur->next;
        newTemp = newCur->next;
        cur->next = newCur;
        if (temp != NULL) newCur->next = temp;
        cur = temp;
        newCur = newTemp;
    }
    return A;
}
```

## List Cycle
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
