# Level 1 (Arrays, String, Binary Search, Two Pointer):

## Theory:
Insertion Sort, Stable sort is the sort which keeps the relative ordering of equal elements bubble insertion are stable selection sort is unstable, Merge Sort, Merge Sort (Inplace), Inversion count using merge sort, duplicate value problems in bit manipulation, Quick Sort, Counting Sort, Radix Sort, Why Kaden Algorithm Work (https://www.youtube.com/watch?v=86CQq3pKSUw)
```c++
//counting set bit n&(n-1) technique, n&(n-1) means closest set bit
while (n)
{
  ++count;
  n = n&(n-1);
}
```

## Questions:
1) Merge Overlap: https://www.interviewbit.com/problems/merge-overlapping-intervals/
2) Hotel Booking Problem: https://www.interviewbit.com/problems/hotel-bookings-possible/
    - Same question but check if consecutive values are equal: https://practice.geeksforgeeks.org/problems/minimum-platforms/0
3) Largest Number: https://www.interviewbit.com/problems/largest-number/
4) Max Distance: https://www.interviewbit.com/problems/max-distance/
5) First Missing Integer: https://www.interviewbit.com/problems/first-missing-integer/
    - (N*(N+1))/2: https://practice.geeksforgeeks.org/problems/missing-number-in-array/0
6) Duplicate in Array: https://www.interviewbit.com/problems/find-duplicate-in-array/
7) Maximum Consecutive Gap: https://www.interviewbit.com/problems/maximum-consecutive-gap/
8) Sum of pairwise hamming distance: https://www.interviewbit.com/problems/sum-of-pairwise-hamming-distance/
9) Array Rotation Problem: https://practice.geeksforgeeks.org/problems/rotate-array-by-n-elements/0
10) Flip: https://www.interviewbit.com/problems/flip/
11) Square root of number: https://www.interviewbit.com/problems/square-root-of-integer/
12) Rotated Sorted array search: https://www.interviewbit.com/problems/rotated-sorted-array-search/
13) Matrix Median OR Sort 100s of sorted array without combining: https://www.interviewbit.com/problems/matrix-median/
14) Median Of Array: https://www.interviewbit.com/problems/median-of-array/
15) Next Permutation: https://www.interviewbit.com/problems/next-permutation/
16) Painter Partition Problem: https://www.interviewbit.com/problems/painters-partition-problem/
    - Allocate Book: https://www.interviewbit.com/problems/allocate-books/
17) Min XOR Value: https://www.interviewbit.com/problems/min-xor-value/
18) Minimize problem: https://www.interviewbit.com/problems/minimize-the-absolute-difference/
    - Count Triplets: https://practice.geeksforgeeks.org/problems/count-the-triplets/0
    - 3 Sum: https://www.interviewbit.com/problems/3-sum/
    - Array 3 Pointers: https://www.interviewbit.com/problems/array-3-pointers/
    - DiffK: https://www.interviewbit.com/problems/diffk/
    - Pythagorean Triplet: https://practice.geeksforgeeks.org/problems/pythagorean-triplet/0
19) Container with most water: https://www.interviewbit.com/problems/container-with-most-water/
20) Equilibruim Point: https://practice.geeksforgeeks.org/problems/equilibrium-point/0
    - Trapping Rain Water: https://practice.geeksforgeeks.org/problems/trapping-rain-water/0
    - Stock buy and sell: https://practice.geeksforgeeks.org/problems/stock-buy-and-sell/0
21) Max continuous 1s: https://www.interviewbit.com/problems/max-continuous-series-of-1s/
    - Subarray with given sum: https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0
22) Voting Algorithm: https://www.interviewbit.com/problems/majority-element/
    - N/3 Repeat Number: https://www.interviewbit.com/problems/n3-repeat-number/

Avoid TLE: Use printf/scanf, use array instead of vectors

# Level 2 (String, Linked List, Stacks, Queues, Heap, Map):
## Theory:
Tries (Node: char data, bool isTerminal, unoredered_map<char, Node*> next;), Why Floyd's Algorithm work (https://www.youtube.com/watch?v=LUm2ABqAs1w), Infix, Prefix, Postfix, Arithematic solver type problems, Delete without a head pointer just a node which has to be deleted will be given [ ans: (*node) = *(node->next); ] also free that node's memory

## Questions:
1) [Trie] Hotel Reviews: https://www.interviewbit.com/problems/hotel-reviews/
2) [Trie] Palindrome Pair in array of word: https://www.geeksforgeeks.org/palindrome-pair-in-an-array-of-words-or-strings
3) Longest Distinct characters in string: https://practice.geeksforgeeks.org/problems/longest-distinct-characters-in-string/0
4) Reverse linked list: https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1
    - K Reverse Linked List: https://www.interviewbit.com/problems/k-reverse-linked-list/
    - Reverse Linked List within a range: https://www.interviewbit.com/problems/reverse-link-list-ii/
    - Palindrome List: https://www.interviewbit.com/problems/palindrome-list/
5) Detect Loop: https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1
    - Loop begining detect: https://www.interviewbit.com/problems/list-cycle/
    - Loop remove: https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1
6) Intersection Point in Y Shapped Linked Lists: https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1
7) Merge Sort Linked List: https://www.interviewbit.com/problems/sort-list/
    - Insertion Sort: https://www.interviewbit.com/problems/insertion-sort-list/
8) Reorder List: https://www.interviewbit.com/problems/reorder-list/
9) Nearest Smallest Element: https://www.interviewbit.com/problems/nearest-smaller-element/
    - Next Larger Number: https://practice.geeksforgeeks.org/problems/next-larger-element/0
10) Largest Rectangle In Histogram: https://www.interviewbit.com/problems/largest-rectangle-in-histogram/
11) Sliding Window: https://www.interviewbit.com/problems/sliding-window-maximum/
12) Min Stack: https://www.interviewbit.com/problems/min-stack/
13) Queue using 2 stacks: https://practice.geeksforgeeks.org/problems/queue-using-two-stacks/1
14) Stack using 2 queues: https://practice.geeksforgeeks.org/problems/stack-using-two-queues/1
15) LRU Cache: https://practice.geeksforgeeks.org/problems/lru-cache/1

# Level 3 (Hashing, Greedy, Trees, Graph):

# Level 4 (Dynamic Programming):