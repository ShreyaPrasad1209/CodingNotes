# Linked List
## 1. Detect Loop in Linked List - Qualcomm
**Floyd’s Cycle-Finding Algorithm <u>O(N)O(1)</u>:** Use two pointer to traverse list, increment one by 1 other by 2 if they meet then the linked list has loop.

## 2. Check if linked list is palindrome - Microsoft, Amazon, Snapdeal
**Way 1: Using Stack** <u>O(n)O(n)</u><br>
**Way 2: Reversing list** <u>O(n)O(1)</u><br>

## 3. Remove duplicates - Adobe, Myntra, Oracle
**Way 1: From Sorted Linked List** <u>O(n)</u><br>
**Way 2: From UnSorted Linked List Using hashing** <u>O(n)</u><br>

## 4. Pairwise swap elements of a given linked list - Amazon, Microsoft
1->2->3->4->5 becomes 2->1->4->3->5<br>
Simply traverse keep swapping if it's odd number element with next node if it exists.

## 5. Intersection of 2 linked list - Amazon, DE Shaw, Microsoft, Qualcomm, Goldman Sachs, Accolite
**Way 1: If both linked lists are sorted** <u>O(N+M)O(1)</u> simply by traversing at once.<br>
**Way 2: Using Hashing** <u>O(N+M)O(N+M)</u><br>
**Way 3:** Find length of both the lists first after that start traversing longer list and check when second list appears on it.

> Quick sort on linked list is possible. (others also - merge, insertion bubble but quick is mostly used)

## 6. Swap Kth node from the beginning and the end - Morgan Stnaley
Swaping data isn't allowed. There will be 4 cases-
1) Y is next to X
2) X is next to Y
3) X & Y are same
4) X & Y doesn't exist

