# Data Structures

> Defination, Advantages, Type - Linear, Non Linear, ADT, Difference between Algorithm & Program

## Asymptotic Analysis:
If f(n) & g(n) are two functions 
1. **Big-Oh:** f(n) = O(g(n)) if there exists c & n<sub>o</sub> such that f(n) ≤ c * g(n) ∀ n ≥ n<sub>o</sub>
2. **Big-Omega:** f(n) = Ω(g(n)) if there exists c & n<sub>o</sub> such that f(n) ≥ c * g(n) ∀ n ≥ n<sub>o</sub>
3. **Big-Theta:** f(n) = θ(g(n)) if there exists c<sub>1</sub>, c<sub>2</sub> & n<sub>o</sub> such that c<sub>1</sub> * g(n) ≤ f(n) ≤ c<sub>2</sub> * g(n) ∀ n ≥ n<sub>o</sub>

## Swap without temp variable:
```c++
x = x^y;
y = x^y;
x = x^y;
```

## Matrix Multiplication:
```c++
int m, n, p, q
cin >> m >> n;
int A[m][n];
for (int i = 0; i < m; ++i)
{
    for (int j = 0; j < n; ++j)
        cin >> A[i][j];
}
cin >> p >> q;
int B[p][q];
for (int i = 0; i < p; ++i)
{
    for (int j = 0; j < q; ++j)
        cin >> B[i][j];
}

if (n != p)
    cout << "Multiplication doesn't exists!" << endl;
else
{
    int C[m][q];
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < q; ++j)
        {
            int sum = 0;
            for (int k = 0; k < p; ++k)
                sum += A[i][k] * B[k][j];
            C[m][q] = sum;
        }
    }
}
```

> Array - Dynamic Array(Insertion, Traversal, Deletion, Searching), 2D Array(Row major or Column major)

Addressing in array<br>
L<sub>i</sub> = UB - LB + 1 [Array Length]<br>
E<sub>i</sub> = K<sub>i</sub> - LB [Effective Address]

m(2:8, 4:1, 6:10) find address of m[5, -1, 8]<br>
L<sub>1</sub> = 8 - 2 + 1 = 7<br>
L<sub>2</sub> = 1 - (-4) + 1 = 6<br>
L<sub>3</sub> = 10 - 6 + 1 = 5<br>
E<sub>1</sub> = 5 - 2 = 3<br>
E<sub>2</sub> = -1 - (-4) = 3<br>
E<sub>3</sub> = 8 - 6 = 2<br>
**In Row Major:**<br>
BA + W[(E<sub>1</sub>L<sub>2</sub> + E<sub>2</sub>)L<sub>3</sub> + E<sub>3</sub>]<br>
**In Column Major:**<br>
BA + W[(E<sub>3</sub>L<sub>2</sub> + E<sub>2</sub>)L<sub>1</sub> + E<sub>1</sub>]

```c++
malloc(bytes of memory)
//returns a pointer of heap memory it is simmilar to new keyword of C++
calloc(elementsCount, sizeOfEachElement)
//Syntax is different in calloc but it also returns a pointer to heap memory however it also initializes it to ZERO

int* temp = (int*) malloc(sizeof(int));
int* temp = new int;
```

> String (Array, Linked List, Dynamic Array representation), Length concatination, substring, indexing (starting index of pattern in string)

## Digit Sum:
```c
int sum = 0;
while(num != 0)
{
    sum += num % 10;
    num /= 10;
}
```

## Stack Using Array:
```c
#define MAX 5

int stackArr[MAX], top = -1;
bool isEmpty() { return (top == -1); }
bool isFull() { return (top == MAX-1); }
void push(int val)
{
    if (isFull())
    {
        cout << "Stack is Full!" << endl;
        return;
    }
    ++top;
    stackArr[top] = val;
}
void pop()
{
    if (isEmpty())
    {
        cout << "Stack is Empty!" << endl;
        return;
    }
    --top;
}
int top()
{
    if (isEmpty())
    {
        cout << "Stack is Empty!" << endl;
        return -1;
    }
    return stackArr[top];
}
```

## Stack Using Linked List:
```c
struct Node { int data; Node* next; } *top = NULL;
bool isEmpty() { return top == NULL; }
void push(int value)
{
    Node* temp = new Node{value, NULL};
    if (top != NULL)
        temp->next = top;
    top = temp;
}
void pop()
{
    if (isEmpty())
    {
        cout << "Stack is Empty!" << endl;
        return;
    }
    temp = top;
    top = top->next;
    delete temp;
}
int top()
{
    if (isEmpty())
    {
        cout << "Stack is Empty!" << endl;
        return;
    }
    return top->data;
}
```

## GCD & LCM:<br>
> GCD (A, B) = GCD (B, A % M) BaseCase: B gets 0

> GCD (A, B) * LCM (A, B) = A * B

## Hanoi Problem:
```c
void solve(int n, char rodFrom, char rodMiddle, char rodTo)
{
    if (n == 1) cout << "Move disk " << n << " from " << rodFrom << " to " << rodTo << endl;
    solve(n-1, rodFrom, rodTo, rodMiddle);
    cout << "Move disk " << n << " from " << rodFrom << " to " << rodTo << endl
    solve(n-1, rodMiddle, rodFrom, rodTo);
}
```

## Arithemetic Expression:
```java
//Infix to postfix
> Push left paranthesis on stack, add right paranthesis to expression.
> Scan left to right and repeat.
> If operand then append in postfix expression otherwise push it on stack.
> If an operator with higher precidence (BODMAS) is already present in stack when pushing above then pop it and append to expression. If paranthesis close then pop and append insides.

//Infix to prefix
> Scan right to left. In the end reverse the expression. The behavior of paranthesis will also change. () will become )( during traversal

//Prefix to infix
> Scan right to left.
> If operand push on stack otherwise s1 = pop s2 = pop push (s1 operator s2) on the stack again.
> Pop the stack to get the output

//Postfix to infix
> Scan left to right.
> If operand push on stack otherwise s1 = pop s2 = pop push (s1 operator s2) on the stack again.
> Pop the stack and reverse it to get output

//Postfix to prefix
> Scan left to right.
> If operand push on stack otherwise s1 = pop s2 = pop push (operator s2 s1) on the stack again.

//Prefix to postfix
> Scan right to left.
> If operand push on stack otherwise s1 = pop s2 = pop push (s1 s2 operator) on the stack again.

//Evaluation of postfix
> Scan left to right
> If operand push on stack otherwise s1 = pop s2 = pop push evaluation of (s2 operator s1) on the stack again.

PRE-X (InPre)       R2L
S2->S1              PostPre & Eval
Reverse             InPre & PostIn
```

## Sparse Matrix:
**A. Store using a 3xN size 2D Array**
<br>![](res/9.png)<br>
**B. Store using a Linked List having row, column, alue & next node**
<br>![](res/5.png)<br>
**C. Store using List of Lists**
<br>![](res/6.png)<br>
```c++
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

struct Node { int i, j, val; Node* next; } *sparseMat2Head = NULL, *sparseMat2Tail = NULL;
struct Node2 { int x, val; Node2* next; };

int main()
{
    int n = 4, m = 5;
    int mat[n][m] = {{0, 0, 3, 0, 4}, {0, 0, 5, 7, 0}, {0, 0, 0, 0}, {0, 2, 6, 0, 0}};

    int sparseMat1[3][MAX];
    int sparseMat1Count = 0;
    Node2* sparseMat3[n];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; i < m; ++j)
        {
            if (mat[i][j] != 0)
            {
                //1-Using 3xN Matrix
                sparseMat1[0][sparseMat1Count] = i;
                sparseMat1[1][sparseMat1Count] = j;
                sparseMat1[2][sparseMat1Count] = mat[i][j];
                ++sparseMat1Count;

                //2-Using Linked list
                Node* cur = new Node{i, j, mat[i][j], NULL};
                if (sparseMat2Head == NULL)
                {
                    sparseMat2Head = cur;
                    sparseMat2Tail = cur;
                }
                else
                {
                    sparseMat2Tail->next = cur;
                    sparseMat2Tail = cur;
                }

                //3-Using list of lists
                Node2* cur2 = new Node2{j, mat[i][j], NULL};
                if (sparseMat3[i] == NULL) sparseMat3[i] = cur2;
                else
                {
                    Node2* temp = sparseMat3[i];
                    while(temp->next != NULL) temp = temp->next;
                    temp->next = cur2;
                }
            }
        }
    }

    return 0;
}
```

## Operations On Sparse Matrix:
Add - Simply traverse both sparse matrix at a time keep two pointers while(pointer1 < end || pointer2 < end) this kind of and simply add. O(N) complexity. Subtract is also same.

Transpose is simplest simplest traverse sparse matrix flipping rows and columns.

Multiply is newA[i][j] = A[i][k]*B[k][j] where k will go from 0...p

## Polynomial Representation:
In the image polynomial: 5x<sup>2</sup> + 4x + 2 & 5x + 5 are added using linked list. Array Of Structures also maybe used.
<br>![](res/7.png)<br>

> Dequeue is a special queue in which insertion & deletion can be performed both at rear or front end.

> Reversing a stack is like reversing a linked list

## Queue using Array:
```c
#define MAX 5
int qArr[MAX], front = -1, rear = -1;
bool isEmpty() { return (front == -1); }
bool isFull() { return (rear == MAX-1); } //In circular queue - (front==0 && rear==MAX-1) || (rear = (front-1)%(MAX-1))
void enqueue(int val)
{
    if (isFull())
    {
        cout << "Queue is Full!" << endl;
        return;
    }
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else ++rear;    //In Circular queue rear = (rear+1) % MAX;
    qArr[rear] = val;
}
void deqeue()
{
    if (isEmpty())
    {
        cout << "Queue is Empty!" << endl;
        return;
    }
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else ++front;   //In Circular queue front = (front+1) % MAX;
}
int front()
{
    if (isEmpty())
    {
        cout << "Queue is Empty!" << endl;
        return -1;
    }
    return qArr[front];
}
```
> Queue using linked list

## Priority Queue using Linked List (Min prior):
```c
struct Node { int data, prio; Node* next; } *root = NULL;
bool isEmpty() { return (root == NULL); }
void push(int val, int _prio)
{
    Node* newNode = new Node{val, _prio, NULL};
    if (root == NULL) root = newNode;
    else if (root->prio > newNode->prio)    //Flip sign for max prio
    {
        newNode->next = root;
        root = newNode;
    }
    else
    {
        Node* temp = root;
        //Flip sign for max prio
        while(temp->next != NULL && temp->next->prio < newNode->prio)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}
void pop()
{
    if (isEmpty())
    {
        cout << "Queue is Empty!" << endl;
        return;
    }
    Node* temp = root;
    root = root->next;
    delete temp;
}
int peek()
{
    if (isEmpty())
    {
        cout << "Queue is Empty!" << endl;
        return -1;
    }
    return root->data;
}
```

## Priority Queue (min prio) using Doubly Linked List:
```c
struct Node { int data, prio; Node *next, *prev; } *front = NULL, *rear = NULL;
bool isEmpty() { return (front == NULL && rear == NULL); }
void push(int val, int _prio)
{
    Node* newNode = new Node{ val, _prio, NULL, NULL };
    if (front == NULL && rear == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else if (newNode->prio <= front->prio)
    {
        //Front Insert
        newNode->next = front;
        front->prev = newNode->next;
        front = newNode;
    }
    else if (newNode->prio > rear->prio)
    {
        //Rear Insert
        newNode->next = NULL;
        rear->next = newNode;
        newNode->prev = rear;
        rear = newNode;
    }
    else
    {
        Node* temp = front;
        while(temp->next != NULL && temp->next->prio < newNode->prio)
            temp = temp->next;
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next = newNode;
        (temp->next)->prev = newNode;
    }
}
void pop()
{
    if (isEmpty())
    {
        cout << "Queue is Empty!" << endl;
        return;
    }
    Node* temp = front;
    front = front->next;
    delete temp;
}
int peek()
{
    if (isEmpty())
    {
        cout << "Queue is Empty!" << endl;
        return -1;
    }
    return front->data;
}
```

> Linked List (Singly, Doubly, Circular, Circular Doubly, Insertion at beggining-specified-end, Traversing, Searching, Deletion at beggining-specified-end, Reversing)

## Linked List reversing
```c
//Singly
void reverse()
{
    Node* cur = root, prev = NULL, next = NULL;
    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    root = prev;
}
//Doubly (Simply reverse all pointers for every node)
void reverse()
{
    Node* cur = front, temp = NULL;
    while(cur != NULL)
    {
        temp = cur->next;
        cur->next = cur->prev;
        cur->prev = temp;
        cur = temp;
    }
    temp = front;
    front = tail;
    tail = temp;
}
```

## Linear Search:
Time: O(n)
```c++
int search(int arr[], int n, int x)
{
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] == x)
            return i;
    }
    return -1;
}
```

## Binary Search:
Applies on sorted array. divides the arr to check which side it can belong then recursively checks that subarray.<br>
Time: O(logn)
```c++
int search(int arr[], int l , int r, int x)
{
    //Binary Search
    if (r >= l)
    {
        int mid = l + (r-l)/2;
        if (arr[mid] == x) return mid;
        else if (arr[mid] > x) return search(arr, l, mid-1, x);
        else return search(arr, mid+1, r, x);
    }
    return -1;

    //Ternary Search 
    if (r >= l)
    {
        int mid1 = l + (r-l)/3;
        int mid2 = mid1 + (r-l)/3;
        if (arr[mid1] == x) return mid1;
        if (arr[mid2] == x) return mid2;
        else if (arr[mid1] > x) return search(arr, l, mid1-1, x);
        else if (arr[mid2] < x) return search(arr, mid2+1, r, x);
        else return search(arr, mid1+1, mid2-1, x);
    }
    return -1;
}
```
Ternary Search is also there which is same as binary search except instead of dividing in 2 parts we divide it in 3 parts.

Binary search is better than ternary search because <br>
T(n) = T(n/2) + 2 [In Binary Search]<br>
T(n) = T(n/3) + 4 [In Ternary Search]<br>
in binary search: 2log<sub>2</sub>n complexity while in ternary search: 4log<sub>3</sub>n calculating mathematically binary search is better.

## Interpolation Search:
An Interpolation Search is an improvement over Binary Search for scenarios where the values in a sorted array are uniformly distributed.

Binary Search goes to the middle element to check. On the other hand, Interpolation Search may go to different locations according to the value of the key being searched.

Time: O(loglogn) however in case of value not in the array the time will be O(n)
```c++
int search(int arr[], int l, int r, int x)
{
    if (l <= r)
    {
        pos = left + (((double)(right - left) / (arr[right] - arr[left])) * (x - arr[left]))
        if (arr[pos] == x) return pos;
        else if (x > arr[pos]) return search(arr, pos + 1, r, x);
        else return search(arr, l, pos - 1, x);
    }

    return -1;
}
```

## Unbounded Binary Search:
Consider that there's a monotonically increasing function f(x) with f(0) some negative value we need to find some value n for which f(n) will be the first non negative number of the function.<br>
Naive approach is linearly searching till we get number greater than 0, it will take O(n)<br>
Other approach is using Unbounded Binary Search. The idea is to proceed with f(0) then f(1) f(2) f(4) f(8) f(16) ... till f(x) every other is  ''''''''''''''''''''''x2 of previous. Now f(x) is first non negative in the above exponentiated series. Now we need to apply binary search from O(x/2) to O(x) x/2 is previous term of the series.
This will give a time complexity of O(logn)

## Selection Sort
Itterate [0..n-1] find minimum element let it be at first then Itterate [1..n-1] find minimum element and so on<br>
Time: O(n<sup>2</sup>)
```c++
void sort(int arr[], int n)
{
    for (int i = 0; i < n-1; ++i)
    {
        int minIndex = i;
        for (int j = i+1; j < n; ++j)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(&arr[minIndex], &arr[i]);
    }
}
```

## Bubble Sort
<br>In bubble sort we make the max element to the right first by swapping the pair of two elements  and itterating throughout.<br>
Time: O(n<sup>2</sup>)
```c++
void sort(int arr[], int n)
{
    for (int i = 0; i < n-1; ++i)
    {
        for (int j = 0; j < n-i-1; ++j)
        {
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
    }
}
```

There's unstable & stable sorting: eg: 5 9 3 9 8 4 here there are duplicate item (9s) if we sort in an unstable sorting the second 9 will not come after the first 9. The relative ordering will change. **Bubble sort is stable.**

## Insertion Sort
In insertion sort we keep a partion of sorted and unsorted parts of array. initially first element is sorted and rest are unsorted. Then we take element from unsorted and insert it on sorted by traversing from right to left.
<br><u>20</u> 35 -15 7 55 1 -22     [key: 35]
<br><u>20 35</u> -15 7 55 1 -22     [key: -15]
<br><u>20 35</u> 35 7 55 1 -22     [key: -15]
<br><u>-15 20 35</u> 7 55 1 -22     [key: 7]
<br><u>-15 20 20</u> 35 55 1 -22     [key: 7]
<br><u>-15 7 20 35</u> 55 1 -22     [key: 7]
<br>...
<br>Time: O(n<sup>2</sup>)

```c++
void sort(int arr[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        int key = arr[i];
        int j = i-1;
        //Iterate in sorted array checking if that element is greater than key
        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
```

## Merge Sort
![](res/mergesort.png)<br>
We use divide and conquer to divide entire array (half to then other half) into individual array. Then we merge while sorting it. Here 27 38 - 3 43 we loop through n of both these merge sets at each iteration check 27 < 3 so 3 comes first then 27 then again check 38 < 43 hence final is 3 27 38 43.
<br>Time: O(nlogn)
<br>Space: O(n)
```c++
void merge(int arr[], int l, int m, int r)
{
    //Setting temp arrays for two merges
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; ++i) L[i] = arr[l + i];
    for (j = 0; j < n2; ++j) R[j] = arr[m + 1+ j];

    int i = 0;  //Initial index of first subarray
    int j = 0;  //Initial index of second subarray
    int k = l;  //Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            ++i;
        }
        else
        {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        ++i;
        ++k;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}
void sort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l+r)>>2;
        sort(arr, l, m);
        sort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
```
## Quick Sort
In quick sort we partition the array and make sure all elements in left subarray is smaller than all elements in right sub array. Then again we will chose a pivot and partition. Unlike merge sort all things are done inplace (constant space complexity) so no need to create temporary variables. So not large memory required.
<br>7 2 1 6 8 5 3 <u>4</u> -> 2 1 3 <u>4</u> 8 5 7 6
<br>Then we will divide and conquer left and right part
<br>Time: O(n<sup>2</sup>) worst case in average case we get O(nlogn) the worst case senerio is avoided usually by a randmised version of quick sort.
<br>![](res/quicksortpartition.jpg)<br>
```c++
void partition(int& arr[], int l, int r)
{
    int pivot = arr[r];
    int x = l - 1;
    for (int i = l; i < r - 1; ++i)
    {
        if (arr[i] <= pivot)
        {
            x++;
            swap(&arr[x], &arr[i]);
        }
    }
    swap(&arr[x + 1], &arr[r]);
    return(x + 1);
}

void sort(int arr[], int l, int r)
{
    if (l < r)
    {
        int partitionIndex = partition(arr, l, r);
        sort(arr, l, partitionIndex - 1);
        sort(arr, partitionIndex + 1, r);
    }
}
```
Quick select algorithm is just like Quick Sort in this we partion based on pivot then we again recursively partition left side of pivot (If we want to select minimum of array) or right side of picot (If we want to select maximum of array).<br>
Worst case senerio for both Quick select and Quick sort can be O(N<sup>2</sup>) if we choose first element as pivot and the list is already sorted.<br>To optimize it upto linear time we need to select a good pivot which should be such that it discards half or more element with each itteration. Sometimes the values are bad that we cannot rely on any pivot approximation technique in that case it will be better if we find the median and then use it as pivot.

## Heap Sort
In heap sort the algorithm idea is to take array and build heap out of it.
<br>![](res/heapsort.png)<br>
Then depending on ascending or descending we make max or min heap this is called heapify.
<br>After heapifying top element will be max or min we swap it with last node and then delete it putting in our sorted array. Then we again do heapify
<br>We keep repeating this until heap is completely deleted.
<br>Time: Heapify takes logn time and then traversing all elements takes n so time complexity will be nlogn. However that's not the case and that is because heapify time will shorten with time as the elements will decrease making it O(n)
https://www.geeksforgeeks.org/time-complexity-of-building-a-heap/

That's fucking complex to understand so XD<br>
Say we want to build a heap of height h then that means it will be having 2^h -1 nodes now we need to call insert that many times along with heapify function. Each heapify shuffles the nodes exactly h times here h is height of that node. So exact operations will be = Sigma(i=1...h) i*2^i this is an AGP series

> Sorting On Different Keys

> Tree (Root, Parent, Children, Internal Node, Siblings, Ansestors, Descendent, GrandParent, Cousin, Depth, Height), Binary Tree (Preorder, Inorder, Postorder), LinkedList Representation Of Binary Tree, Construction from PrePost-PreIn-PostIn

> Full/Strict Binary Tree - All node except leaf nodes are 0 or 2 child here L = I + 1 (L = leaf node, I = Internal node) - Handshaking Lemma

> Complete Binary Tree (All levels except last are full)

> Perfect Binary Tree (All levels are full)

> Skewed Binary Tree - Like a linked list i.e. only one child

> Array Representation Of Complete Binary Tree - Different then heap array representation because in heap we want elements leftmost.
<br>![](res/8.png)<br>

Degree of node is the maximum child it can have so in Binary Tree it's 2

To differentiate between tree and graph also we can do Total Nodes = 2(Leaves-1) for tree - Handshaking lemma<br>

In a k-ary tree where every node has either 0 or k children. L = I*(k-1) + 1<br>
L = Number of leaf node, I = Number of internal nodes i.e. nodes having k childs

## Expression Tree:
![](res/4.png)<br>
Every leaf node has operator

## Binary Search Tree:
> Inorder traversal of BST is always in ascending order
```c
struct Node{ int data; Node *left, *right; } *root = NULL;
Node* searchNode(Node* cur, int x)
{
    if (cur == NULL || cur->data == x) return cur;
    if (cur->data < x) return searchNode(cur->right, x);
    return searchNode(cur->left, x);
}
Node* insertNode(Node* cur, int value)
{
    if (cur == NULL)
    {
        cur->data = value;
        cur->left = NULL;
        cur->right = NULL;
        return cur;
    }
    else if (cur->data > value)
    {
        cur->left = insertNode(cur->left, value);
        return cur;
    }
    else
    {
        cur->right = insertNode(cur->right, value);
        return cur;
    }
}
Node* deleteNode(Node* cur, int value)
{
    if (cur == NULL) return cur;    //If no node with specified value
    else if (cur->data > value)
    {
        cur->left = deleteNode(cur->left, value);
        return cur;
    }
    else if (cur->data < value)
    {
        cur->right = deleteNode(cur->right, value);
        return cur;
    }
    else
    {
        //Case 1 : leaf node
        if (cur->left == NULL && cur->right == NULL)
        {
            delete cur;
            cur = NULL;
            return cur;
        }
        //case 2 : One child
        else if (cur->left == NULL)
        {
            Node *temp = cur;
            cur = cur->right;
            delete temp;
            return cur;
        }
        else if (cur->right == NULL)
        {
            Node *temp = cur;
            cur = cur->left;
            delete temp;
            return cur;
        }
        //Case 3 : Two childrens
        else
        {
            //either find min of right subtree or max of left subtree
            Node* temp = cur->right;
            while(temp->left != NULL) temp = temp->left;
            cur->data = temp->data
            cur->right = deleteNode(cur->right, temp);
            return cur;
        }
    }
}
//O(logN) or in worst case if it's skewed tree then O(N)
```

## Binary Tree to Binary Search tree
Inorder traverse binary tree and store values in an array, now sort the array, and finally again do the inoder traversal this time copy values from sorted array.

## BST can be converted to Greater Sum Tree in which ever node contains sum of all nodes greater than node
![](res/gretre.png)<br>
Inorder traverse: 10, 15, 20, 23, 25, 30, 35, 39<br>
Make Sum array (traverse right2left keep summing): 139, 137, 130, 119, 104, 75, 40, 0

## AVL Tree
https://www.youtube.com/watch?v=GSt_mo60WuE

## Extended Binary Tree or 2-Tree
![](res/extBT.png)<br>
Circles are internal nodes, Squares are external node. Extended binary tree has 0 or 2 child for every node.

> General Tree (each node can have any number of childs)

## Threaded Binary Tree
Instead of wasting unused memory we keep inorder successor or predecessor to make inorder traversal faster.
![](res/threadedtree.png)<br>

## Binary Heap
```c
#define MAXSIZE 50
#define parent(x) (x-1) >> 1
#define child1(x) (x << 1) + 1
#define child2(x) (x << 1) + 2

int heapArr[MAXSIZE];
int size = 0;
void push(int x)
{
    heapArr[size] = x;
    int cur = size;
    while(heapArr[parent(cur)] > heapArr[cur])
    {
        int temp = heapArr[cur];
        heapArr[cur] = heapArr[parent(cur)];
        heapArr[parent(cur)] = temp;
        cur = parent(cur);
    }
    ++size;
}
void pop()
{
    heapArr[0] = heapArr[size-1];
    --size;
    int cur = 0;
    while(min(child1(cur), child2(cur)) < size)
    {
        int temp = heapArr[cur];
        heapArr[cur] = min(heapArr[child1(cur)], heapArr[child2(cur)]);
        heapArr[min(child1(cur), child2(cur))] = temp;
        cur = min(child1(cur), child2(cur));
    }
}
```

## Graph
> Path, ClosedPath, Simple Path, Multi-edge, Loop, Degree, Simple Graph, Connected Graph, Complete Graph, Multigraph, Degree, Simple Graph, Loop, Adjacent Node
> Adjancey Representation, Linked List Representation (Adjancey List)

```c++
#include <bits/stdc++.h>
using namespace std;

void DFS(vector<int> *adj, bool *visited, int node)
{
    if (!visited[node])
    {
        cout << node << " ";
        visited[node] = true;
        for (int i = 0; i < adj[node].size(); ++i)
            DFS(adj, visited, adj[node][i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, e;
    cin >> n >> e;
    vector<int> adj[n];
    bool visited[n];
    fill(visited, visited + n, false);
    for (int i = 0; i < e; ++i)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
            DFS(&adj[0], &visited[0], i);
    }

    return 0;
}
```

```c++
void BFS(vector<int> *adj, bool *visited, queue<int> *nodeVisited, int node)
{
    if (!visited[node])
    {
        cout << node << " ";
        
        visited[node] = true;
        for (int i = 0; i < adj[node].size(); ++i)
        {
            if (!visited[adj[node][i]])
            {
                nodeVisited.push(adj[node][i]);
                cout << adj[node][i] << " ";
            }
        }

        while(!nodeVisited.empty())
        {
            int top = nodeVisited.front();
            nodeVisited.pop();
            BFS(adj, visited, top);
        }
    }
}
```

## Topological Sort:
It is a sorting of graph. In a package manger a package has a dependencie with another so the package manager makes a graph of all the pacakages and perform a topological sort to get linear list of packages to be compiled in order.<br><br>
To implement we take two thing a stack & a visited set. We choose any node which is not visited, put it to visited set. Then check it's child if it's not visited. if a parent is totally visited we put it in our stack. In the end pop all elements from stack and the graph is topologically sorted.

## Spanning Tree:
[Greedy Algorithm]<br>
We first create disjoint sets for all nodes. We store path in a set and sort it in ascending order based on weight. Traverse this new sorted list and apply find set to see if two nodes of path are different then do union. Also print the connection because that is our final minimum spanning tree.
```c++
int e, v;
cin >> e >> v;

DisjointSet<int> ds;

for (int i=0; i<e; ++i)
    ds.makeSet(i);

vector<int> vertex[e];
vector<Path> path(v);
for (int i=0; i<v; ++i)
{
    int a, b, c;
    cin >> a >> b >> c;
    vertex[a].push_back(b);
    vertex[b].push_back(a);
    path[i] = {a, b, c};
}

sort(path.begin(), path.end(), [](Path i, Path j){
    return (i.length < j.length);
}]);

cout << "-------" << endl;

for (int i=0; i<v; ++i)
{
    int a = ds.find(path[i].nodeA);
    int b = ds.find(path[i].nodeB);
    if (a != b)
    {
        ds.makeUnion(a, b);
        cout << path[i].nodeA << " " << path[i].nodeB << " - " << path[i].length << endl;
    }
}
```

## Hashing
