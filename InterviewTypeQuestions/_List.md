# Level 1 (Arrays, String, Binary Search, Two Pointer):

## Theory:
Insertion Sort, Stable sort is the sort which keeps the relative ordering of equal elements bubble insertion are stable selection sort is unstable, Merge Sort, Merge Sort (Inplace), Inversion count using merge sort, duplicate value problems in bit manipulation (one variation: https://www.geeksforgeeks.org/find-the-element-that-appears-once-in-a-sorted-array/)

Given array [1, 2, 4, 2, 1] finding xor 1^2^4^2^1 = xor(1^1)^(2^2)^(4) = 0^0^4 = 4

Given Array [1, 1, 2, 2, 4, 5] we need to find both 4 & 5<br>
If we simply xor all numbers we will get 4^5 which will definitely be non zero. (100)^(101)=(001) Now if we divide the array elements into two one having 1 at unit place other having 0. [1, 1, 5], [2, 2, 4] take xor of both to get the ans<br>
If 100(4) & 110(6) are non repeating numbers we need to divide the array based on tense (check rightmost set bit pos) place set or unset
```c++
int arr[] = {1, 1, 2, 2, 3, 9};
int n = sizeof(arr) / sizeof(int);
int xors = 0;
for (int i = 0; i < n; ++i) xors ^= arr[i];

int temp = 0;
while(xors > 0)
{
    if (xors&1) break;
    ++temp;
    xors >>= 1;
}
int mask = 1<<temp;

int num1 = 0, num2 = 0;
for (int i = 0; i < n; ++i)
{
    if (((arr[i]&mask)>>temp)&1) num1 ^= arr[i];
    else num2 ^= arr[i];
}
cout << num1 << " " << num2 << endl;
```

Given array [7, 7, 3, 4, 2, 4, 3, 3, 4, 7] all numbers except one is occuring thrice we need to find that number.<br>
add binary position values (111 + 111 + 011 + 100 + 010 + 100 + 011 + 011 + 100 + 111) = 676 %3 all digit = 010 = 0.2<sup>0</sup> + 1.2<sup>1</sup> + 0.2<sup>2</sup> = 2
```c++
int arr[] = {7, 11, 3, 4, 9, 4, 3, 3, 4, 7, 9, 9, 7};
    int n = sizeof(arr) / sizeof(int);

    int count[32] {};
    for (int i = 0; i < n; ++i)
    {
        int cur = arr[i], pos = 0;
        while (cur > 0)
        {
            if (cur&1) ++count[pos];
            ++pos;
            cur >>= 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < 32; ++i) ans += pow(2, i) * (count[i] % 3);
    cout << ans << endl;
```

### Calculating number of set bits
```c++
int countBits(int n)
{
    //Time: O(number of bits)
    int count = 0;
    while (n > 0)
    {
        count += (n&1);
        n = n>>1;
    }
    return count;

    //Time: O(number of set bits)
    int count = 0;
    while(n)
    {
        ++count;
        n = n&(n-1);
    }

    // __builtin_popcount(n); or __builtin_popcountl or __builtin_popcountll
}
```

Quick Sort, Counting Sort, Radix Sort, Why Kaden Algorithm Work (https://www.youtube.com/watch?v=86CQq3pKSUw)
```c++
//counting set bit n&(n-1) technique, n&(n-1) means closest set bit
while (n)
{
  ++count;
  n = n&(n-1);
}
```
Find numbers less than 1000 divisible by 2, 3 & 5 [Inclusion Exclusion]
```c++
ll t;
cin >> t;
while (t--)
{
    ll num;
    cin >> num;
    ll arr[] = { 2, 3, 5, 7, 11, 13, 17, 19 };
    ll n = sizeof(arr) / sizeof(ll);
    ll result = 0;
    for (ll i = 1; i < (1<<n); ++i)
    {
        ll mask = i, temp = 1, pos = 0, product = 1ll, bits = __builtin_popcount(mask);
        while (mask > 0)
        {
            ll lastBit = (mask&1);
            if (lastBit) product *= arr[pos];
            mask >>= 1;
            ++pos;
        }
        if (bits&1) result += num/product;
        else result -= num/product;
    }
    cout << result << endl;
}
```
Difference Array

## Questions(39):
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
    - First, Last occurence of a element using binary search
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
23) Kth Smallest Element: https://practice.geeksforgeeks.org/problems/kth-smallest-element/0
    - Kth Largest In a Stream: https://practice.geeksforgeeks.org/problems/kth-largest-element-in-a-stream/0
24) https://www.geeksforgeeks.org/count-number-of-triplets-with-product-equal-to-given-number-with-duplicates-allowed-set-2/
25) Longest subarray having average greater than or equal to x: https://www.geeksforgeeks.org/longest-subarray-having-average-greater-than-or-equal-to-x/

Avoid TLE: Use printf/scanf, use array instead of vectors

# Level 2 (String, Linked List, Stacks, Queues, Heap, Map):
## Theory:
String Builder & String Stream(ostringstream), Tries (Node: char data, bool isTerminal, unoredered_map<char, Node*> next;), Why Floyd's Algorithm work (https://www.youtube.com/watch?v=LUm2ABqAs1w), Infix, Prefix, Postfix, Arithematic solver type problems, Delete without a head pointer just a node which has to be deleted will be given [ ans: (*node) = *(node->next); ] also free that node's memory

Trie, Suffix Tree, Suffix Array (Only basics not in depth) https://www.hackerearth.com/practice/notes/trie-suffix-tree-suffix-array/
```
Implement Google spell-corrector. What data structure will you use and how will it work?
(I suggested the first trie but later on made it more efficient by using suffix array data structure. They asked me to implement all operation of suffix array).(They liked my approach).
```

## Questions(35):
1) [Trie] Hotel Reviews: https://www.interviewbit.com/problems/hotel-reviews/
    - Shortest Unique Prefix: https://www.interviewbit.com/problems/shortest-unique-prefix/
2) [Trie] Palindrome Pair in array of word: https://www.geeksforgeeks.org/palindrome-pair-in-an-array-of-words-or-strings
3) Longest Distinct characters in string: https://practice.geeksforgeeks.org/problems/longest-distinct-characters-in-string/0
    - Longest Substring Without Repeat: https://www.interviewbit.com/problems/longest-substring-without-repeat/
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
    - https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1
9) Nearest Smallest Element: https://www.interviewbit.com/problems/nearest-smaller-element/
    - Next Larger Number: https://practice.geeksforgeeks.org/problems/next-larger-element/0
10) Largest Rectangle In Histogram: https://www.interviewbit.com/problems/largest-rectangle-in-histogram/
11) Sliding Window: https://www.interviewbit.com/problems/sliding-window-maximum/
    - Maximum of all subarrays of size k: https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0
12) Min Stack: https://www.interviewbit.com/problems/min-stack/
13) Queue using 2 stacks: https://www.youtube.com/watch?v=t6XzDmXzSFY
    - Stack using 2 queues: https://www.youtube.com/watch?v=Wn45fJKBTTc
14) LRU Cache: https://www.interviewbit.com/problems/lru-cache/
    - Page faults in LRU: https://practice.geeksforgeeks.org/problems/page-faults-in-lru/0
15) Circular Tour: https://practice.geeksforgeeks.org/problems/circular-tour/1
    - Simmilar: https://www.interviewbit.com/problems/gas-station/
16) First Non Repeating Character In a Stream: https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream/0
17) Median Of Stream Of Running Integers: https://practice.geeksforgeeks.org/problems/find-median-in-a-stream/0
18) Heap Sort:
19) N Max Pair Combinations: https://www.interviewbit.com/problems/n-max-pair-combinations/
20) Merge K Sorted Linked List: https://www.interviewbit.com/problems/merge-k-sorted-lists/
21) Rearrange characters: https://practice.geeksforgeeks.org/problems/rearrange-characters/0

# Level 3 (Hashing, Greedy, Trees, Graph):
## Theory:
Huffman Coding, Fractional Knapsack, Minimum Spanning Tree, Disjoint Sets
```c++
// Iterative code is important because it's faster, recursive code is simpler but slower
void inOrder(Node *root)
{
    stack<Node *> s;
    Node *curr = root;
    while (curr != NULL || !s.empty())
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}
void preOrder(Node *root)
{
    stack<Node *> s;
    s.push(root);
    while (!s.empty())
    {
        Node *curr = s.top();
        cout << curr->data << " ";
        s.pop();

        if (curr->right) s.push(curr->right);
        if (curr->left) s.push(curr->left);
    }
}
void postOrder(Node *root)
{
    stack<Node*> s;
    stack<int> out;
    s.push(root);

    while (!s.empty())
    {
        Node *curr = s.top();
        out.push(curr->data);
        s.pop();

        if (curr->left) s.push(curr->left);
        if (curr->right) s.push(curr->right);
    }

    while (!out.empty())
    {
        cout << out.top() << " ;
        out.pop();
    }
}
void BFS(Node *root)
{
    queue< pair<Node*, int> > q;
    q.push({A, 0});
    while (!q.empty())
    {
        int cur_level = q.front().second;
        while (!q.empty() && q.front().second == cur_level)
        {
            Node *cur = q.front().first;
            q.pop();
            cout << cur->val << " ";
            if (cur->left) q.push({cur->left, cur_level+1});
            if (cur->right) q.push({cur->right, cur_level+1});
        }
        cout << endl;
    }
}
```
Prims Algorithm (https://www.youtube.com/watch?v=4ZlRH0eK-qQ), Kruskal's Algorithm. Prims have complexity of O(N square) while kruskal O(ElogV). Kruskal is implemented through Disjoint Set (https://www.youtube.com/watch?v=fAuF0EuZVCk)
```c++
//Disjoint Set
struct Node
{
    int data;
    Node *parent;
    int rank;
};
class DisjointSet
{
public:
    unordered_map<int, Node*> rec;
    void makeSet(int data)
    {
        Node *node = new Node{data, NULL, 0};
        node->parent = node;
        rec[data] = node;
    }
    Node *findSet(int data)
    {
        if (rec.find(data) == rec.end()) return NULL;
        else return rec[data]->parent;
    }
    void makeUnion(int a, int b)
    {
        if (a == b) return;
        Node *x = findSet(a), *y = findSet(b);
        if (x->rank >= y->rank)
        {
            x->rank = (x->rank == y->rank) ? x->rank + 1 : x->rank;
            y->parent = x;
        }
        else x->parent = y;
    }
};
```
Kosaraju Algorithm for strongly connected graph: Apply DFS to all unvisited nodes. As the node get's exit put it in a stack. Then find transpose of graph, transpose simply means reverse the graph arrows. Apply DFS again to the stack as per new visited set. DFS on nodes from stack.

Shortest Path finding - BFS, Dijikstra (N square). Floyd Warshall Algorithm (https://www.youtube.com/watch?v=oNI0rf2P9gE)

## Questions(42):
1) 2 Sum: https://www.interviewbit.com/problems/2-sum/
2) Relative Sorting (Simmilar to counting sort): https://practice.geeksforgeeks.org/problems/relative-sorting/0
3) Array Pair Sum Divisibility Problem: https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem/0
4) Longest Consecutive Subsequence: https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence/0
5) Anagrams: https://www.interviewbit.com/problems/anagrams/
6) Equal: https://www.interviewbit.com/problems/equal/
7) Window String: https://www.interviewbit.com/problems/window-string/
    - given 2 strings str1 and str2, you have to find the length of the smallest circular substring in str1 containing all characters of str2. For example given strings ‘hackerrank’ and ‘kh’, the answer should be 2 (and not 4 because circular substrings are allowed).
8) Points On The Straight Line: https://www.interviewbit.com/problems/points-on-the-straight-line/
9) Substring Concatenation: https://www.interviewbit.com/problems/substring-concatenation/
10) Activity Selection: https://practice.geeksforgeeks.org/problems/activity-selection/0
    - Same question but specify order: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room/0
11) Largest Number Possible: https://practice.geeksforgeeks.org/problems/largest-number-possible/0
12) Minimize The Heights: https://practice.geeksforgeeks.org/problems/minimize-the-heights/0
13) Bulbs: https://www.interviewbit.com/problems/bulbs/
14) Distributing Candy: https://www.interviewbit.com/problems/distribute-candy/
15) Tushar Birthday Bombs: https://www.interviewbit.com/problems/tushars-birthday-bombs/
16) Identical Binary Tree: https://www.interviewbit.com/problems/identical-binary-trees/
    - Symmetric Binary Tree: https://www.interviewbit.com/problems/symmetric-binary-tree/
17) Inorder Traversal Of Cartesian Tree: https://www.interviewbit.com/problems/inorder-traversal-of-cartesian-tree/
    - Binary Tree from Inorder and Preorder: https://www.interviewbit.com/problems/construct-binary-tree-from-inorder-and-preorder/
    - Binary Tree From Inorder and Postorder: https://www.interviewbit.com/problems/binary-tree-from-inorder-and-postorder/
18) Invert The Binary Tree: https://www.interviewbit.com/problems/invert-the-binary-tree/
19) 2 Sum Binary Tree: https://www.interviewbit.com/problems/2sum-binary-tree/
20) Max Depth of binary tree: https://www.interviewbit.com/problems/max-depth-of-binary-tree
    - Min Depth of binary tree: https://www.interviewbit.com/problems/min-depth-of-binary-tree/
21) Least Common Ancestor: https://www.interviewbit.com/problems/least-common-ancestor/
22) Flatten Binary Tree to Linked List: https://www.interviewbit.com/problems/flatten-binary-tree-to-linked-list/
23) BST Iterator: https://www.interviewbit.com/problems/bst-iterator/
24) Recover Binary Search Tree: https://www.interviewbit.com/problems/recover-binary-search-tree/
25) Populate Next Right Pointers Tree: https://www.interviewbit.com/problems/populate-next-right-pointers-tree/
26) Bottom View: https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
    - Binary Tree in vertical order: https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1
    - Check for balanced tree: https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1
27) Maximum Width of Binary Tree: https://leetcode.com/problems/maximum-width-of-binary-tree/
28) Interesting Number: https://www.spoj.com/problems/INUMBER/
    - Smallest Multiple with 0 and 1: https://www.interviewbit.com/problems/smallest-multiple-with-0-and-1/
29) Commutable Island(Find MST): https://www.interviewbit.com/problems/commutable-islands/
30) Possibility of finishing all courses given pre-requisites: https://www.interviewbit.com/problems/possibility-of-finishing-all-courses-given-prerequisites/
31) Black Shapes: https://www.interviewbit.com/problems/black-shapes/
32) https://www.geeksforgeeks.org/find-maximum-path-sum-in-a-binary-tree/
33) https://www.geeksforgeeks.org/minimum-number-of-given-operations-required-to-make-two-strings-equal/

# Level 4 (Backtracking & Dynamic Programming):
## Theory(DP):
Breaking complex problem it into simpler simmilar sub problems and then solving it. Also memoizing sub problems for faster re-calculation.<br>
Simplest example is calculating fibonaaci series we use F(n) = F(n-1) + F(n-2) this is breaking into simillar sub problems. We can do memoization to optimize it (optimize overlapping sub problems)

DP means - a) Memoization (Top down approach) b) Pure DP (Bottom up approach)

Recursive implementation of Fibonaaci even using memo calls stacks for recursive call 2^n times using itteration to fill a linear DP for fibonacci is O(N)

Using matrix exponentiation fibonacci can be solved in O(k^3 logN) here k is 2. We can even use golden ratio. We can also find it in O(logN) using DP idea is to use other recurence relation such that f(n) is defined in terms of f(n/2)<br>
f(2 * k) = f(k) * f(k) + f(k - 1) * f(k - 1)<br>
f(2 * k + 1) = f(k) * f(k + 1) + f(k - 1) * f(k)

1) **Number Reduce Problem:** <br>
Given a number we can either divide it by 3, 2 or subtract 1. We need to find min operation to make 1 from n.
```c++
int solve(int n)
{
    if (n == 1) return 0;
    int q1 = INF, q2 = INF, q3 = INF;
    if (n%3 == 0) q1 = 1 + solve(n/3);
    if (n%2 == 0) q2 = 1 + solve(n/2);
    q3 = 1 + solve(n-1);
    return min(q1, min(q2, q3));
}
//We can memoize it, or do top down dp
```

2) **Staircase Problem:** <br>
We have N stairs and we can either climb by 1 step or 2 step. Find how many ways possible.
<br>![](res/staircase.png)<br>
W(n) = W(n-1) + W(n-2)
```c++
int memo[30];
int staircaseProblem(int n)
{
    if (memo[n-1] == -1) memo[n-1] = staircaseProblem(n - 1);
    if (memo[n-2] == -1) memo[n-2] = staircaseProblem(n - 2);

    return memo[n - 1] + memo[n - 2];
}
// Simmilar problem SPOJ (ACODE)
```

**Another variation is Minimum Jump To Reach End**<br>
Given array [2, 3, 1, 1, 2, 4, 2, 0, 1, 1] ans is 0->1->4->5->9 (At any step max we can jump is value on that index). Simple dp problem start filling from rightmost end in dp store minimum jumps to reach end from that point, hence dp will be [4, 3, 4, 3, 2, 1, 2, -1, 1, 0] also keep in track which jump is efficient to take at each step so that we can later backtrack our steps.

3) **Minimum Cost Path:** <br>
![](res/minimumcosthome.png)<br>
right side given matrix we need to go from top left to bottom right we can only go bottom and right otherwise this question would have infinite possibilities.<br>
Left side is the dp each cell having minimum cost till that block. min(dp[i-1][j], dp[i][j-1]) + mat[i][j]<br>
**Another varient problem**<br>
![](res/totalways.png)

If we were given condition to move in any 4 direction then there would have been infinite possibilities.

> OPTIMIZATION PROBLEMS: https://medium.com/@pratikone/dynamic-programming-for-the-confused-rod-cutting-problem-588892796840

> https://medium.com/@emailarunkumar/coin-exchange-problem-greedy-or-dynamic-programming-6e5ebe5a30b5

4) **Wine Problem: OPTIMIZATION PROBLEM** We have n wines with their initial prices given. A wine sells at rate of initial price times year it is old. We can sell one wine only per year. What is max profit. We can sell only from two ends<br>
[2, 3, 5, 1, 4]. Approach is find max after selling both end wines. Using greedy and selling cheap first is wrong
```c++
//We will use 2D DP storing l & r
int dp[1000][1000];
int solve(int arr[], int l, int r, int year)
{
    if (l > r) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    int q1 = arr[l]*year + solve(arr, l+1, r, year+1);
    int q2 = arr[r]*year + solve(arr, l, r-1, year+1);
    int ans = max(q1, q2);
    dp[l][r] = ans;
    return ans;
}
//Without memoization it's complexity was O(2^n) with memoization it is O(N^2)

//Bottom up approach
int solve(int arr[], int n)
{
    int dp[1000][1000] {};
    int year = n;
    for (int i = 0; i < n; ++i) dp[i][i] = year*arr[i];
    --year;
    for (int len = 2; len <= n; ++len)
    {
        int l = 0, r = n-len;
        while (l <= r)
        {
            int temp = l+len-1;
            dp[l][temp] = max(arr[l]*year + dp[l+1][temp],
                arr[temp]*year + dp[l][temp-1]);
            ++l;
        }
        -year;
    }
    return dp[0][n-1];
}

/* For [2, 3, 5, 1, 4]
    2       3       5       1       4
2   10      23      43
3   0       15      37      40
5   0       0       25      29
1   0       0       0       5       24
4   0       0       0       0       20
*/

// Quick way to do diagonal filling (excludes diagonal)
for (int i = 1; i < n; ++i)
    for (int j = 0, k = i; k < n; ++k, ++j)

/*
It prints:
i j k
1 0 1
1 1 2
1 2 3
1 3 4
2 0 2
2 1 3
2 2 4
3 0 3
3 1 4
4 0 4
*/
```

5) **Burst Balloon Problem: OPTIMIZATION PROBLEM**<br>
```c++
/*
Given values of balloons: 3 1 5 8
Each bursting means that value * left * right value
We need to burst them such that max val: like in order-5 1 3 8 (1*5*8 + 3*1*8 + 3*8 + 8 = 96)

Diagonals represents first balloon which we burst. 0 1 means balloons within 0 to 1
    0   1   2   3
0   3  30  159  167
1      15  135  159
2          40   48
3               40

For [0, 2] value left [0, 1] denotes what if we choose [0, 1] to burst first then we will burst 2 so for ever cell it's
dp[i][j] = max(dp[i][j-1] + arr[j]*arr[j+1], dp[i+1][j] + arr[0]*arr[j+1])
*/
```

6) **Rod Cutter: OPTIMIZATION PROBLEM** <br>
We are given a rod of some length and we can cut it in any number of pieces. We are given an array that tells us price for rod piece of that size. We need to find rod maximum selling price cuts.<br>
```c++
#include <bits/stdc++.h>
using namespace std;

int rodCutter(int cost[], int n)
{
    int dp[n+1];
    fill(dp, dp + n + 1, -9999);
    dp[0] = 0;
    for (int len = 1; len <= n; ++len)
    {
        for (int cut = 1; cut <= len; ++cut)
            dp[len] = max(dp[len], cost[cut] + dp[len - cut]);
    }

    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    int cost[n + 1];
    for (int i = 0; i <= n; ++i) cin >> cost[i];
    cout << rodCutter(cost, n);
    return 0;
}
```
```
We have rod of length 5 with pieces value: 2, 5, 7, 8 for 1, 2, 3 & 4 respectively.
    1   2   3   4   5
2   2   4   6   8   10
5   2   5   7   10
5
7
```
DP relation will be: Max Cost of rod = (Cost of 1 Rod + Max cost of remaining rod) + (Cost of 2 Rod + Max cost of remaining rod) + ...

7) **Edit Distance: STRING PROBLEM**
Given a string we can perform insertion, deletion, replacement to convert to another string find min operations.
```
              i-->
    ""  S   A   T   U   R   D   A   Y
""  0   1   2   3   4   5   6   7   8
S   1   0   1   2   3   4   5   6   7
U   2
N   3
D   4
A   5
Y   6

We want to make saturday -> sunday
each cell represents min operations reqd. to convert inp. to out.

At any point this DP represents say for i=3, j=1
We want to make S from SAT this means 2 deletion. so 2 min operations.
replacement: 1 + dp[i-1][j-1]
deletion: 1 + dp[i+1][j]
insertion: 1 + dp[i][j-1]
min of all three is ans of that cell
if charactre matches look for i-1, j-1 element since checking that element is redundant
```

8) **Find Longest Increasing subsequence: OPTIMIZATION PROBLEM**
Whenever question says longest, maximum, highest out of subsequences then chances are more of DP
```c++
/*
[3, 10, 2, 1, 20] = [3, 10, 20] = 3
[3, 2] = [3] or [2] = 1
[50, 3, 10, 7, 40, 50] = [3, 7, 40, 50] or [3, 10, 40, 50] = 4
*/
int solve(int arr[], int n)
{
    int dp[1000];
    fill(dp, dp+n, 1);
    int ans = -1;
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (arr[j] < arr[i])
                dp[i] = max(1 + dp[j], dp[i]);
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

/*
If the problem was Find Long Increasing Bitonic subsequence, bitonic means a subsequence which first increases and then decreases. Idea is find LIS from Left 2 Right and Right 2 Left and then add both array then -1.

2 -1  4  3  5 -1  3  2       [Array]
1  1  2  2  3  1  2  2       [L2R LIS]
2  1  3  2  3  1  2  1       [R2L LIS]
2  1  4  3  5  1  3  2       [Longest Increasing bitonic sequence]
*/

/*

Maximum Sum Increasing Subsequence
Like in 4 6 1 3 8 4 6 LIS will be 1 3 4 6 but SIS will be 4 6 8 because it's sum is max
Implementation is same just we will keep track of sum for every array aswell in a different array and to find answer we will see max of that array
https://www.youtube.com/watch?v=99ssGWhLPUE

Application - Box Stacking Problem
Suppose we are given boxes with their l, b & h. we need to stack them as maximum as possible. upper box should be smaller then lower.

Find all 3 orientation of each box and sort them according to their base area i.e. [lbh] [lhb] [bhl] imagine book placing
1 2 4   -   [1 2 4] (2), [4 1 2] (4), [4 2 1] (8)
3 2 5   -   [3 2 5] (6), [2 5 3] (10), [5 3 2] (15)
[5, 3, 2] -> 0
[5, 2, 3] -> 1
[4, 2, 1] -> 2
[3, 2, 5] -> 3
[4, 1, 2] -> 4
[2, 1, 4] -> 5

 j  i
[2, 3, 1, 5, 2, 4]
we will check can i go on top of j if yes then best we can do at i is best we can do at both

 j     i
[2, 3, 1, 5, 2, 4]
yes this is possible so arr[i] = 2 + 1 = 3

Also in a different array maintain every time if it's possible to stack at i the corresponding j

[2, 3, 3, 7, 5, 11]
[0, 1, 0, 0, 1, 3]
11 is max value and we get that by 5<-3<-0
*/
```

9) **Longest Palindromic Subsequence:**<br>
https://www.youtube.com/watch?v=lDYIvtBVmgo<br>
https://www.youtube.com/watch?v=_nCsPn7_OgI

```
https://www.geeksforgeeks.org/minimum-insertions-to-form-a-palindrome-dp-28/

if (l > h) return INT_MAX;
if (l == h) return 0;
if (l == h - 1) return (str[l] == str[h])? 0 : 1;

// Check if the first and last characters are
// same. On the basis of the comparison result,
// decide which subrpoblem(s) to call
return (str[l] == str[h])
        ? findMinInsertions(str, l + 1, h - 1)
        : (min(findMinInsertions(str, l, h - 1), findMinInsertions(str, l + 1, h)) + 1);

find LCS of string and it's reverse's say it's x. n - length(x) is ans;
```

10)   **Maximum Subset Problem:**
Here the return function two operation will give entire possibilities for the recurssion.
```c++
bool isSubsetSum(ull n, ull arr[], ull sum)
{
    if (sum == 0) return true;
    if (n == 0 && sum != 0) return false;
    if (arr[n - 1] > sum) return isSubsetSum(n-1, arr, sum);
    return isSubsetSum(n-1, arr, sum) || isSubsetSum(n-1, arr, sum-arr[n-1]);
}
```
<br>![](res/subsetsum.png)<br>
```c++
bool isSubsetSum(int n, int arr[], int sum)
{
    bool m[n][sum + 1];
    for (int i = 0; i < n; ++i) m[i][0] = true;
    for (int i = 1; i < sum + 1; ++i) m[0][i] = (arr[0] == i) ? true : false;
    for (int j = 1; j < sum + 1; ++j)
    {
        for (int i = 1; i < n; ++i)
        {
            if (j - arr[i] > 0) m[i][j] = m[i-1][j] || m[i-1][j-arr[i]];
            else m[i][j] = m[i-1][j];
        }
    }
    return m[n-1][sum];
}
```

11)  **Longest Common Subsequence:**
```
X = nematode
Y = empty
ans is 3 i.e. emt
This algorithm has application in biological field. If biologist discovers a DNA AGTABAG he wants to find which closest organism does DNA resembles

if (x[i] == y[j]) 1 + LCS(x[i+1], y[j+1])
otherwise max of LCS(x[i], y[j+1]) & LCS(x[i+1], y[j])

basically try matching if current i and j matches with i if not then either other n-i matches with other array or vice versa. We need to find max so max of both

DP Table
              i-->
    ""  A   G   G   T   A   B
""  0   0   0   0   0   0   0
G   0   0   1   1   1   1   1
X   0   0   1   1   1   1   1
T   0   0   1   1   2   2   2
X   0
T   0
A   0
B   0

dp[i][j] = 1+dp[i-1][j-1] or max(dp[i-1][j], dp[i][j-1])
depending upon (x[i] == y[j])

Longest Common Substring is different say in abcdaf & zbcdf. bcd is longest common substring whearas bcdf is longest common subsequence.
Now dp[i][j] = 1 + dp[i-1][j-1] if same otherwise 0

    ""  A   B   C   D   A   F
""  0   0   0   0   0   0   0
Z   0   0   0   0   0   0   0
B   0   0   1   0   0   0   0
C   0   0   0   2   0   0   0
D   0   0   0   0   3   0   0
F   0   0   0   0   0   0   1
In the end see max of entire matrix it's 3 that's ans to find substring go to the element 3 is D then i-1, j-1 it's C then B so BCD is ans
```

12) **Knapsack Problem:**
```c++
/*
Total Weight: 7
Items (weight-val): 1-1, 3-4, 4-5, 5-7

            (total weight capacity of knapsack)
Val (Weight)    0   1   2   3   4   5   6   7
    1 (1)       0   1   1   1   1   1   1   1       [we only have 1 quantity of each item]
    4 (3)       0   1   1   4   5   5   5   5
    5 (4)       0   1   1   4   5  *6*  6   9
    7 (5)       0   1   1   4   5   7   8   9
At any point say [3, 5]: We want to know if we should put object giving val 5 having weight 4.
So max(dp[i-1][j], val[i] + dp[i-1][j-weight[i]])
[i-1, j] is when we do not add that item, other one is if we add that item then we are left with total weight - that item weight left so choose that item.

In the end ans is 9. If we want to find out what all items we picked we need to simply backtrack starting at last ans position of 2d array.

It's same as [i-1, j] means we must have not included this item but the before one. then again at new pos. 9 is not 5 so we included that item then we will subtract 7-4 means next check at [i-1, j-weight[i]]
*/

#include <bits/stdc++.h>
using namespace std;

int s, n, weights[2005], vals[2005], dp[2005][2005];
int main()
{
    scanf("%d %d", &s, &n);
    for (int i = 0; i < n; ++i) scanf("%d %d", &weights[i], &vals[i]);
    for (int i = 0; i < n; ++i) dp[i][0] = 0;
    for (int i = 0; i <= s; ++i) dp[0][i] = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= s; ++j)
        {
            int q1 = dp[i-1][j];
            int q2 = vals[i-1] + dp[i-1][j-weights[i-1]];
            if (weights[i-1] <= j) dp[i][j] = max(q1, q2);
            else dp[i][j] = q1;
        }
    }
    printf("%d\n", dp[n][s]);
    return 0;
}
```

13) **Egg Dropping Puzzle:**<br>
Suppose that we need to find from how tall we can drop an egg from a building. We can reuse an egg if it survives the fall. We need to find worst number of steps it will take us to find that. So for only 1 egg we should start from 1st floor going up it will take n steps in worst.
```
                  (floors)
            0   1   2   3   4   5   6
(eggs)    0
          1     1   2   3   4   5   6
          2     1   2   2   3   3   3

dp[2, 2] means if we try to fall it from 1st floor if it works then 1 is ans otherwise we have 1 egg left and 1 floor to check so 1+dp[1, 1] we need to make max of both so 2. If we try to fall it from 2nd floor if it works then 1 is ans otherwise we have 1 egg left and 1 floor to check like before.

dp[2, 3] means if we drop from 1 then max(1, 3). drop from 2 means max(1+1, 1+1) if it breaks then still we need to check for smaller floor which is 1 if it breaks there. Drop from 3 means max(1+2, 1). Minimum of all three [3, 2, 3] is 2
```

14) **Matrix Chain Multiplication:**<br>
```
Given A (10x30) B (30x5) C (5x60) then we need to find order of multiplication such that operations are minimized

(AB)C = (10×30×5) + (10×5×60) = 4500 operations
A(BC) = (30×5×60) + (10×30×60) = 27000 operations.
```
https://www.youtube.com/watch?v=vgLJZMUfnsU<br>
*SPOJ MIXTURES*
https://www.youtube.com/watch?v=XHjjIJxnAJY

15) **Maximum Size Rectangle/Square Of All 1s**<br>
```
Given a matrix with either 0s or 1s we need to find size of maximum sub matrix which has all 1s in it.

If we need to find squares then we should fill our dp table first row and first column matching to the actual matrix for rest if it's 1 then dp[i, j] = min(dp[i-1, j], dp[i, j-1], dp[i-1, j-1]) + 1 otherwise 0

To find max such rectangle we will create histogram for each column and then keep finding it's area.

   Matrix            Histogram      Max Area
1 0 0 1 1 1         1 0 0 1 1 1         3
1 0 1 1 0 1         2 0 1 2 0 2         2
0 1 1 1 1 1         0 1 2 3 1 3         5
0 0 1 1 1 1         0 0 3 4 2 4         8

So ans is 8
In case of colmns are more then rows then we can sweep in column fashion instead of row so that space complexity reduces
```
![](res/maxsubsqr.png)
```
Maximum Subsquare with sides X in matrix it doesn't matter what's filled inside the square

dp
0, 0    0, 0    0, 0    0, 0    1, 1
1, 1    0, 0    1, 1    1, 2    2, 3
2, 1    0, 0    2, 1    0, 0    3, 1
3, 1    1, 2    3, 3    1, 4    4, 5
0, 0    0, 0    4, 1    2, 2    5, 3

Now we will just traverse entire dp from bottom right or anywhere actually we will see like if it's 5, 3 we will go min of 5 & 3 which is 3 check both up and left if that position is no 0, 0 then again check from that place forming a square
```

16) **Maximum Sum Sub Rectangle:**<br>
```c++
/*
 2    1   -3  -4    5               2   3   0  -4    1
 0    6    3   4    1               0   6   9   13   14
 2   -2   -1   4   -5               2   0  -1   3    -2
-3    3    1   0    3              -3   0   1   1    4
                                Find max subarray of the array
                                Using Kadane's Algorithm in O(N)
                                [Max of all these sub arrays
                                within all itteration is ans]

After this next itteration from 2nd column till last then 3rd column till last and so on it will result in final max

O(N cube) all other questions of list is N square or N this one is only unique XD
*/
```
https://www.youtube.com/watch?v=yCQN096CwWM<br>

17) **Numbers WIthout Consecutive 1s in binary representation:**<br>
https://www.youtube.com/watch?v=a9-NtLIs1Kk

18) **Optimal Game Strategy:**<br>
Given an array two players play optimally and pick from either side to maximize value.
```
[3, 9, 1, 2]
    1           2           3           4
1   (3, 0)      (9, 3)      (4, 9)      (11, 4)
2               (9, 0)      (9, 1)      (10, 1)
3                           (1, 0)      (2, 1)
4                                       (2, 0)

Fill diagonals first
dp[i][j].first = max(dp[i+1][j].second + val[i], dp[i][j-1].second + val[j])
dp[i][j].second = max(dp[i+1][j].first + val[i], dp[i][j-1].first + val[j])
```

19) **Text Justification: OPTIMIZATION PROBLEM**<br>
Given text and width of screen arrange it such that spaces are evenly distributed
```
Given: Tushar Roy likes to code
Width: 10
              spaces
Tushar Roy  ->   0
likes to    ->   2
code        ->   6

              spaces
Tushar      ->   4
Roy likes   ->   1
to code     ->   3

we check badness of arrangement by space left squared sum (we could have even taken cube it's just to make it sensitive to minor errors) so 40 & 26. Greedy approach of fitting as many words will fail.

This dp represents badness of picking i-j elements to display on one line of given width
    0   1   2   3   4
0   16  0   INF INF INF
1       49  1   INF INF
2           25  4   INF
3               64  9
4                   36

Now we will create another dp table that will keep track of minimum badness for each new word we put
[16, 0, 17, 4, 26]
last index has the answer of total badness

https://www.youtube.com/watch?v=RORuwHiblPc
```

20) **Weighted Job Scheduling Problem: OPTIMIZATION PROBLEM**<br>
Given jobs along with their weights we need to choose such that we get max weight out of it. It's different from greedy BUSYMAN because in that no weight was given and we just want to select most jobs possible.
```
first sort on the bases of end time
(1, 3)    (2, 5)    (4, 6)    (6, 7)    (5, 8)     (7, 9)
   5         6        5          4        11          2
weights [5, 6, 5, 4, 11, 2]
dp:
(1, 3)    (2, 5)    (4, 6)    (6, 7)    (5, 8)     (7, 9)
   5         6        10        14        17         16
We get this dp by moving i & j (j<i) if it's possible to do both jobs then do it for example in 3rd job j = 0 i = 2 then it's possible to do both job so 5+5 = 10 update it to 10 likewise keep max value in dp
```

21) **Regex & Wildcard matching: STRING PROBLEM**<br>
```
* means any string of length 0 or more can come in between ?/. means only one character can come
pattern: x?y*z          string to match: xaylmz
```
![](res/Screenshot&#32;from&#32;2019-04-01&#32;22-03-09.png)<br>
https://www.youtube.com/watch?v=3ZDZ-N0EPV0

22) **Travelling Salesman problem:**<br>
Salesman travels over a set of cities, he has to return to source. Minimize total distance travelled by him. Such cycle is also called hamiltonian cycle. We want minimum weight hamiltonian cycle.<br>
we will use bitmask to make it efficient. 000001 means out of all 6 cities 1st is visited<br>
![](res/Screenshot&#32;from&#32;2019-04-02&#32;01-51-36.png)<br>

```c++
#include <bits/stdc++.h>
using namespace std;

int n = 4;
int dist[10][10] =
{
    { 0,  20, 42, 25},
    { 20,  0, 30, 34},
    { 42, 30,  0, 10},
    { 25, 34, 10,  0}
};
int VISITED_ALL = (1<<n) -1;
int dp[16][4];

int tsp (int mask, int pos)
{
    if (mask == VISITED_ALL) return dist[pos][0];
    if (dp[mask][pos] != -1) return dp[mask][pos];

    int ans = INT_MAX;
    for (int city = 0; city < n; ++city)
    {
        if ((mask&(1<<city)) == 0)
            ans = min(dist[pos][city] + tsp(mask|(1<<city), city), ans);
    }

    dp[mask][pos] = ans;
    return ans;
}

int main()
{
    for (int i = 0; i < (1<<n); ++i)
    {
        for (int j = 0; j < n; ++j)
            dp[i][j] = -1;
    }
    cout << tsp(1, 0);
    return 0;
}
```
https://www.youtube.com/watch?v=JE0JE8ce1V0<br>
https://medium.com/basecs/speeding-up-the-traveling-salesman-using-dynamic-programming-b76d7552e8dd<br>
https://www.youtube.com/watch?v=g8bSdXCG-lA&t=86s<br>

## Questions():
1) Combination Sum: https://www.interviewbit.com/problems/combination-sum/
2) Combination Sum II: https://www.interviewbit.com/problems/combination-sum-ii/
3) Letter Phone: https://www.interviewbit.com/problems/letter-phone/
4) Palindrome Partition: https://www.interviewbit.com/problems/palindrome-partitioning/
5) Generate All Paranthesis: https://www.interviewbit.com/problems/generate-all-parentheses-ii/
6) Kth Permutation Sequence: https://www.interviewbit.com/problems/kth-permutation-sequence/
7) Largest Area Of Rectangle With Permutation: https://www.interviewbit.com/problems/largest-area-of-rectangle-with-permutations/
8) Ways to Decode: https://www.interviewbit.com/problems/ways-to-decode/
9) Intersecting Chords In a circle: https://www.interviewbit.com/problems/intersecting-chords-in-a-circle/
10) Max Sum Without Adjacent Elements: https://www.interviewbit.com/problems/max-sum-without-adjacent-elements/
11) Repeating Subsequence: https://www.interviewbit.com/problems/repeating-subsequence/
12) Min Jumps Array: https://www.interviewbit.com/problems/min-jumps-array/
13) Longest Arithemetic Progression: https://www.interviewbit.com/problems/longest-arithmetic-progression/
14) N digit number with digit sum: https://www.interviewbit.com/problems/n-digit-numbers-with-digit-sum-s-/<br>
---[Incomplete]---

# Puzzles:<br>
---[Incomplete]---

# Extras:
- https://www.geeksforgeeks.org/design-a-chess-game/

# Level 5 (God):
1) Ways To Form Max Heap: https://www.interviewbit.com/problems/ways-to-form-max-heap/
2) Order Of People Height: https://amortizedminds.wordpress.com/2016/08/25/order-of-people-height-interviewbit
3) https://www.careercup.com/question?id=5840928073842688
