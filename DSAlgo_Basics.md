# DS Algorithms - Basics
## 1. Introduction:
Algorithm is a set of steps to complete a task. 

**An algorithm should** - take input, give output, Definiteness (each instruction clear), Finiteness (algorithm terminates after finite operations), Effectiveness(Good result shows).

Effectiveness & Efficiency are different. Effectiveness is the ability to produce desired result. Efficiency means how fast.

**Expectations from an algorithm** - Correctness, Approximation Algorithm if exact solution is not found then use approximation for optimization, less resource usage.

Running program on test cases to check it's correctness in called testing. Debugging is fixing any issue including compiler or even logical issues. There are two methods - Black box and white box testing. In black box testing the tester has no knowledge of the internal implementation of the program he may not even have the programming knowledge whereas in white box testing it's carried out by the developer who has knowledge of implementations.

## 2. Asymptotic Analysis:
To analyse a program's performance we have to measure it somehow. A naive way is to implement algorithm then calculate the duration of time taken in execution but the execution time will vary so it won't give clear result. That's where Asymptotic Analysis comes in role.

It talks about the time and space complexity. However in this we ignore constant so it may not be the best way to compute performance.

1) Big-Oh Notation (O) : Worst Case : Upper Bound
   <br>
   f(n) ≤ c * g(n)

2) Big-Omega Notation (Ω) : Best Case : Lower Bound
   <br>
   f(n) ≥ c * g(n)

3) Big-Theta Notation (θ) : Average Case
   <br>
   c<sub>1</sub> * g(n) ≤ f(n) ≤ c<sub>2</sub> * g(n)

```c++
for (int i = 0; i < n; ++i)
{
    for (int j = 0; j < n; ++j)
        c[i][j] = a[i][j] + b[i][j];
}
```

In this:<br>
The condition i < n & j < n will execute (n + 1)<sup>2</sup> times <br>
Next all c[i][j] operation will execute (n)<sup>2</sup> times<br>
And 2 * 4 bytes for storing int<br>
Which equals to 2n<sup>2</sup> + 2n + 2

> Asymptotic notations are for rationalization. It's a tool for saying which algorithms scale better, not which ones are absolutely faster. so θ(2n) becomes O(n) because, roughly speaking, for large enough inputs, doubling the input size will no more than double the number of steps taken.<br>
To conclude Big O only measures relative performance not absolute.

```c++
//Matrix multiplication example
#include<iostream>
 
using namespace std;
 
int main()
{
    int a[5][5],b[5][5],c[5][5],m,n,p,q,i,j,k;
    cout<<"Enter rows and columns of first matrix:";
    cin>>m>>n;
    cout<<"Enter rows and columns of second matrix:";
    cin>>p>>q;
 
    if(n==p)
    {
        cout<<"\nEnter first matrix:\n";
        for(i=0;i<m;++i)
            for(j=0;j<n;++j)
                cin>>a[i][j];
 
        cout<<"\nEnter second matrix:\n";
        for(i=0;i<p;++i)
            for(j=0;j<q;++j)
                cin>>b[i][j];
 
        cout<<"\nThe new matrix is:\n";
        for(i=0;i<m;++i)
        {
            for(j=0;j<q;++j)
            {
                c[i][j]=0;
                for(k=0;k<n;++k)
                    c[i][j]=c[i][j]+(a[i][k]*b[k][j]);
                cout<<c[i][j]<<" ";
        }
            cout<<"\n";
        }
    }
    else
        cout<<"\nSorry!!!! Matrix multiplication can't be done";
 
    return 0;
}
```

## 3. Recursion:
Dividing problem in sub problems and make a function call recursively to solve it. There will be a base case to terminate the infinite recursion. Recursion can be visualized through stack. There are two types of recursion -
```c++
void head(int n)
{
    //Recursion stack: 5, 4, 3, 2, 1, cout 2, cout3, cout 4, cout 5
    if (n == 1)
        return;
    head(n-1);
    cout << n << endl;
}
```
```c++
void tail(int n)
{
    //Recursion stack: cout 5, cout 4, cout 3, cout 2
    if (n == 1)
        return;
    cout << n << endl;
    tail(n-1);
}
```
Every itteration can be transformed to recursion and vice versa. Recursion is time costlier than itteration.

**Problem #1 (GCD Problem)**
```c++
int gcdItter(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int gcdRecur(int a, b)
{
    if (b == 0)
        return a;
    return gcdRecur(b, a % b);
}
```

**Problem #2 (Hanoi Problem)**
```c++
void solveHanoi(int n, char rodFrom, char rodMiddle, char rodTo)
{
    if (n == 1)
    {
        cout << "Plate: " << n << " from " << rodFrom << " to " << rodTo << endl;
        return;
    }
    solveHanoi(n-1, rodFrom, rodTo, rodMiddle);
    cout << "Plate: " << n << " from " << rodFrom << " to " << rodTo << endl;
    solveHanoi(n-1, rodMiddle, rodFrom, rodTo);
}

//solveHanoi(3, 'A', 'B', 'C');
```

**<u>Solving Linear Recurrences:</u>**<br>
1) Determing K:<br>
f(i-1) + f(i-2) **K = 2**<br>
2f(i-2) + f(i-4) = 0f(i-1) + 2f(i-2) + 0f(i-3) + 1f(i-4) **K = 4**<br>
K is on how many terms relation depends on
2) Determine initial values:<br>
First K terms should be initialized in a Kx1 matrix F<sub>i</sub>
3) Determing transformation matrix<br>
A matrix with last row as reverse of matrix initialized above. Rest diagonals above element are 1 rest are 0.
<br>![](res/transformationmat.png)<br>
4) Now finally:<br>
F<sub>2</sub> = TF<sub>1</sub><br>
F<sub>3</sub> = TF<sub>2</sub> = T<sup>2</sup>F<sub>1</sub><br>
F<sub>n</sub> = T<sup>n-1</sup>F<sub>1</sub><br>
Use fast exponention algorithm to calculate power in O(logn) instead of brute force O(n) multiplying.
```c++
//pow(a, b) of math library uses fast exponention
int expo(int a, int b)
{
    if (b==1) return a;
    if (b==2) return a*a;

    if (b%2==0)
        return expo(expo(a,b/2),2);
    else
        return a*expo(expo(a,(b-1)/2),2);
}
```
Fibonacci Series Solve
<br>![](res/linrec1.png)<br>
https://www.spoj.com/problems/SEQ/
<br>![](res/linrec2.png)<br>
In case of some constant in relation
<br>![](res/linrec3.png)<br>
For generalized (better) approach:
<br>![](res/recurRel.png)<br>

### Common Problems:
**1 ) LCM & GCD:**<br>
a x b = LCM(a, b) * GCD(a, b)<br>
LCM(a, b) = (a x b) / GCD(a, b)

```c++
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}
```
LCM(a, b, c) ≠ (a x b x c) / GCD(a, b, c)<br>
GCD(a, b, c) = GCD(a, gcd(b, c))
```c++
long long findlcm(int arr[], int n)
{
    long long ans = arr[0];
 
    for (int i = 1; i < n; ++i)
        ans = (((arr[i] * ans)) / (gcd(arr[i], ans)));
 
    return ans;
}
```

## 4. Searching:

**Problem #1 (Linear Search)**
<br>Time: O(n)
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

**Problem #2 (Binary Search)**
<br>Applies on sorted array. divides the arr to check which side it can belong then recursively checks that subarray.<br>
Time: O(logn)
```c++
int search(int arr[], int l , int r, int x)
{
    // l = 0 & r = n-1
    if (r >= l)
    {
        int mid = (l + r) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] > x)
            return search(arr, l, mid - 1, x);
        else
            return search(arr, mid + 1, r, x);
    }
    return -1;
}
```
Ternary Search is also there which is same as binary search except instead of dividing in 2 parts we divide it in 3 parts.

Binary search is better than ternary search because <br>
T(n) = T(n/2) + 2 [In Binary Search]<br>
T(n) = T(n/3) + 4 [In Ternary Search]<br>
in binary search: 2log<sub>2</sub>n complexity while in ternary search: 4log<sub>3</sub>n calculating mathematically binary search is better.

**Problem #3 (Jump Search)**
<br>Applies on sorted array. Performs linear search but in a form of group of √n
<br>Time: O(√n)
```c++
int search(int arr[], int n, int x)
{
    int left = 0;
    int right = sqrt(n);

    while (arr[right] <= x && right < n)
    {
        left = right;
        right += sqrt(n);

        if (right > length - 1)
            right = length;
    }

    for (int i = left; i < right; ++i)
    {
        if (arr[i] == x)
            return i;
    }
    return -1;
}
```

**Problem #4 (Interpolation Search)**
<br>An Interpolation Search is an improvement over Binary Search for scenarios where the values in a sorted array are uniformly distributed.

Binary Search goes to the middle element to check. On the other hand, Interpolation Search may go to different locations according to the value of the key being searched.

Time: O(loglogn) however in case of value not in the array the time will be O(n)
```c++
int search(int arr[], int l, int r, int x)
{
    if (l <= r)
    {
        pos = left + (((double)(right - left) / (arr[right] - arr[left])) * (x - arr[left]))
        if (arr[pos] == x)
            return pos;
        else if (x > arr[pos])
            return search(arr, pos + 1, r, x);
        else
            return search(arr, l, pos - 1, x);
    }

    return -1;
}
```

**Problem #5 (Exponential Search)**
<br>It finds a range within which the number can be found. by performing exponential check. First from 1 to 2 then 2 to 4 then 4 to 8... and then it performs binary search on the range.<br>
Time: O(logn)
```c++
int search(int arr[], int n, int x)
{
    if (arr[0] == x)
        return 0;
    
    int i = 1;
    while (i < n && arr[i] <= x)
        i *= 2;
    
    return binarySearch(arr, i/2, min(i, n), x);
}
```

**Other important things from std namespace**<br>
std::rotate (in algorithm): 1 2 3 4 5 6 7 8 9 -> 4 5 6 7 8 9 1 2 3 <br>
std::rotate(vec.begin(), vec.begin() + 3, vec.end());<br>
1 2 3 4 5 6 7 8 9 -> 6 7 8 9 1 2 3 4 5 <br>
std::rotate(vec.begin(), vec.begin() + vec.size() - 4, vec.end());<br>
std::reverse(vecA.begin(), vecA.end()); //reverses vector
std::lower_bound(vec.begin(), vec.end(), 5) will return an itterator to the first occurence of 5 in vector like wise there is std::upper_bound<br>
auto low = lowerbound(vec.begin(), vec.end(), 5);<br>
cout << low - vec.begin() << endl;

Lexiographic order is alphabetical order: 0, 1, 10, 2, 21, 3

To round of int - lower int, upper int or even nearest round off<br>
https://www.geeksforgeeks.org/lrint-llrint-c/

```c++
//compare function: Descending order. By default sort function will sort in ascending order.
sort(ar.begin(), ar.end(), [](const class& a, const class& b) -> bool
{
    return a.x > b.x;
});

//We also need a compare function for senerios like sorting a class on the bases of it's some member variable
```

### Unbounded Binary Search:
Consider that there's a monotonically increasing function f(x) with f(0) some negative value we need to find some value n for which f(n) will be the first non negative number of the function.<br>
Naive approach is linearly searching till we get number greater than 0, it will take O(n)<br>
Other approach is using Unbounded Binary Search. The idea is to proceed with f(0) then f(1) f(2) f(4) f(8) f(16) ... till f(x) every other is x2 of previous. Now f(x) is first non negative in the above exponentiated series. Now we need to apply binary search from O(x/2) to O(x) x/2 is previous term of the series.
This will give a time complexity of O(logn)

### Two pointers Technique:
Consider we are given an array and we need to find what all pairs with given sum exists in it.<br>
Naive approach is by using two itterations and checking sum. This is brute force and has complexity O(N<sup>2</sup>)<br>
The array should be sorted. Two pointers approach is by having two pointers in the itteration one at head other at tail of the array and matching pairs. Time: O(n)

```c++
bool isPairSum(A[], N, X)
{
    int i = 0;
    int j = N - 1;
 
    while (i < j)
    {
        if (A[i] + A[j] == X) return true;
        else if (A[i] + A[j] < X) ++i;
        else j--;
    }
    return false;
}
```

## 5. Sorting:
**Problem #1 (Selection Sort)**
<br>Itterate [0..n-1] find minimum element let it be at first then Itterate [1..n-1] find minimum element and so on<br>
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

**Problem #2 (Bubble Sort)**
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

**Problem #3 (Insertion Sort)** STABLE
<br>In insertion sort we keep a partion of sorted and unsorted parts of array. initially first element is sorted and rest are unsorted. Then we take element from unsorted and insert it on sorted by traversing from right to left.
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

**Problem #4 (Shell Sort)**
<br>Shell sort is an extension to Insertion sort. In insertion sort if the array is sorted then it will take O(n) to shift elements to sorted partition while this can be optimized using shell sort.
<br>gap is size / 2 means 7 / 2 = 3 then 3 / 2 = 1 There can be more gap variety (see wikipedia) they will change complexity.
<br><u>20</u> 35 -15 7 55 1 -22     [key: 7]
<br><u>20</u> 35 -15 20 55 1 -22    [key: 7]
<br><u>7 35</u> -15 20 55 1 -22     [key: 7]
<br><u>7 35</u> -15 20 55 1 -22     [key: 55]
<br><u>7 35 -15</u> 20 55 1 -22     [key: 1]
<br><u>7 35 -15</u> 20 55 1 -22     [key: 1]
<br><u>7 35 -15 20</u> 55 1 -22     [key: -22]
<br><u>7 35 -15 20</u> 55 1 20      [key: -22]
<br>-22 35 -15 7 55 1 20            [key: -22]
<br>Then gap 1 will be pure insertion sort
<br>...
<br>Time: O(n<sup>2</sup>)
```c++
void sort(int arr[], int n)
{
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; ++i)
        {
            int temp = arr[i];
            for (int j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            arr[j] = temp;
        }
    }
}
```

**Problem #5 (Merge Sort)**
<br>![](res/mergesort.png)<br>
We use divide and conquer to divide entire array (half to then other half) into individual array. Then we merge while sorting it. Here 27 38 - 3 43 we loop through n of both these merge sets at each iteration check 27 < 3 so 3 comes first then 27 then again check 38 < 43 hence final is 3 27 38 43.
<br>Time: O(nlogn)
<br>Space: O(n)

```c++
//Counting inversion merge sort
int invCount(vector<int> &arr)
{
    int inv_count = 0;
    for (int i = 0; i < arr.size(); ++i)
    {
        for (int j = i+1; j < arr.size(); ++j)
            if (arr[i] > arr[j]) inv_count++;
    }
    return inv_count;
}

int merge(vector<int> &arr, int l, int m, int r)
{
    vector<int> temp = arr;
    int i = l, j = m+1, k = l, inv_count = 0;
    while (i <= m && j <= r)
    {
        if (temp[i] > temp[j]) arr[k++] = temp[j++], inv_count += m-i+1;
        else arr[k++] = temp[i++];
    }
    while (i <= m) arr[k++] = temp[i++];
    while (j <= r) arr[k++] = temp[j++];
    return inv_count;
}

int mergeSort(vector<int> &arr, int l, int r)
{
    int inv_count = 0, m = (l+r)/2;
    if (l < r)
    {
        inv_count += mergeSort(arr, 0, m);
        inv_count += mergeSort(arr, m+1, r);
        inv_count += merge(arr, 0, m, r);
    }
    return inv_count;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) cin >> arr[i];
        int ans = invCount(arr);
        int found = mergeSort(arr, 0, n-1);
        if (ans != found)
        {
            cout << ans << " " << found << endl;
            for (int i : arr) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}
```
```c++
// Inplace merge sort
void merge(vector<int> &arr, int l, int m, int r)
{
    int i = l, j = m+1;
    while (i <= m && j <= r)
    {
        if (arr[i] > arr[j])
        {
            arr.insert(arr.begin()+i, arr[j]);
            arr.erase(arr.begin()+j+1);
            ++i, ++j;
        }
        else ++i;
    }
}

void sort(vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        sort(arr, l, mid);
        sort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
}
```

**Problem #6 (Quick Sort)**
<br>In quick sort we partition the array and make sure all elements in left subarray is smaller than all elements in right sub array. Then again we will chose a pivot and partition. Unlike merge sort all things are done inplace (constant space complexity) so no need to create temporary variables. So not large memory required.
<br>7 2 1 6 8 5 3 <u>4</u> -> 2 1 3 <u>4</u> 8 5 7 6
<br>Then we will divide and conquer left and right part
<br>Time: O(n<sup>2</sup>) worst case in average case we get O(nlogn) the worst case senerio is avoided usually by a randmised version of quick sort.
<br>![](res/quicksortpartition.jpg)<br>
```c++
int partition(vector<int> &arr, int l, int r)
{
    int pivot = arr[r];
    int j = l-1;
    for (int i = l; i <= r-1; ++i)
    {
        if (arr[i] <= pivot)
            swap(arr[++j], arr[i]);
    }
    swap(arr[j+1], arr[r]);
    return j+1;
}

void sort(vector<int> &arr, int l, int r)
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

**Problem #7 (Heap Sort)**
In heap sort the algorithm idea is to take array and build heap out of it.
<br>![](res/heapsort.png)<br>
Then depending on ascending or descending we make max or min heap this is called heapify.
<br>After heapifying top element will be max or min we swap it with last node and then delete it putting in our sorted array. Then we again do heapify
<br>We keep repeating this until heap is completely deleted.
<br>Time: Heapify takes logn time and then traversing all elements takes n so time complexity will be nlogn. However that's not the case and that is because heapify time will shorten with time as the elements will decrease making it O(n)<br>
https://www.youtube.com/watch?v=HqPJF2L5h9U<br>
https://www.geeksforgeeks.org/time-complexity-of-building-a-heap/

**Problem #8 (Counting Sort)**
<br>Counting sort work within a specific range. Range should be reasonable not huge like 1 to million. In this we don't do any comparison instead we count.
<br>9 4 10 8 2 4
<br>We find min and max element of array and then prepare an array holding the range.
<br>2 3 4 5 6 7 8 9 10
<br>1 0 2 0 0 0 1 1 1       [count of elements]
<br>2 4 4 8 9 10
<br>Time: O(n + k) n+k is total range here m
<br>Space: O(n + k)
```c++
void sort(int arr[], int n)
{
    int min = arr[0];
    int max = arr[0];
    for (int i = 1; i < n; ++i)
    {
        if (max < arr[i])
            max = arr[i];
        if (min > arr[i])
            min = arr[i];
    }

    int m = max - min + 1;
    int count[m];
    fill(count, count + m, 0);
    for (int i = 0; i < n; ++i)
        count[arr[i] - min]++;

    int counter = 0;
    for (int i = 0; i < m; ++i)
    {
        while (count[i] > 0)
        {
            arr[counter] = min + i;
            counter++;
            count[i]--;
        }
    }
}
```

**Problem #9 (Radix Sort)**
<br>In Radix sort we count sort (or any other stable sort) each digit. It is applied when data is within big range directly applying counting sort will be worse.
<br>17<u>0</u> 4<u>5</u> 7<u>5</u> 9<u>0</u> 80<u>2</u> 2<u>4</u> <u>2</u> 6<u>6</u>
<br>1<u>7</u>0 <u>9</u>0 8<u>0</u>2 <u>0</u>2 <u>2</u>4 <u>4</u>5 <u>7</u>5 <u>6</u>6
<br><u>8</u>02 <u>0</u>02 <u>0</u>24 <u>0</u>45 <u>0</u>66 <u>1</u>70 <u>0</u>75 <u>0</u>90
<br>2 24 45 66 75 90 170 802

![](res/sortTime.png)

## 6. Data Structures:
ADT (Abstract Data Type) It tells about the behaviour (interface)

1) List:
<br>
Dynamic list will create an array reserved with some initial blocks if we add an element and the array is full another array of double block will be created.
<br>
> In java both ArrayList and Vector provide this functionality however vector is thread safe. Means that it is safe (no conflicts) to access or modify a vector from different threads at same time. Vectors came first though but arraylist kind of implementation is still required. ArrayList is hence faster as well.

2) Linked List
<br>It's a dynamic list in which each entity is stored in nodes connected to one another. There are two types of linked list - Singly Linked List (value + head) or Doubly Linked List (value + head + tail)
```c++
#include <iostream>

using namespace std;

template<typename T>
class LinkedList
{
private:
    struct Node
    {
        T data;
        Node* next = NULL;
    };
    void PrintElementsRecurssion(Node* curHead) const
    {
        if(curHead == NULL)
            return;
        
        cout << curHead -> data << " ";
        PrintElementsRecurssion(curHead -> next);
    }
    void PrintElementsReverseRecurssion(Node* curHead) const
    {
        if(curHead == NULL)
            return;
        
        PrintElementsReverseRecurssion(curHead -> next);
        cout << curHead -> data << " ";        
    }
    void ReverseListRecurssion(Node* curHead, Node* prevHead)
    {
        if(curHead -> next == NULL)
        {
            prevHead -> next = NULL;
            curHead -> next = prevHead;
            head = curHead;
            return;
        }
        
        ReverseListRecurssion(curHead -> next, curHead);
        if(prevHead == NULL)
            return;
        prevHead -> next = NULL;
        curHead -> next = prevHead;
    }
    Node* head;
    Node* tail;
    int size;
    
public:
    LinkedList() : head(NULL), size(0) { };

    void Insert(T value, int index)
    {
        Node* node = new Node;
        node -> data = value;

        if(head == NULL && index == 0)
        {
            head = node;
            tail = node;
            return;
        }

        Node* curHead = head;
        Node* changedHead = head;
        int i = 0;
        while(curHead != NULL)
        {
            if(i == index - 1)
            {
                changedHead = curHead -> next;
                curHead -> next = node;                
            }
            else if(i == index)
            {
                if(index == 0)
                    head = node;
                
                if(node -> next == NULL)
                    tail = changedHead;
                node -> next = changedHead;
                size++;
                break;
            }

            ++i;
            curHead = curHead -> next;
        }
    }

    void PushFront(T value)
    {
        Node* node = new Node;
        node -> data = value;
        node -> next = head;

        if(head == NULL)
        {
            head = node;
            tail = node;
            return;
        }

        head = node;
    }

    T TopFront()
    {
        return head -> data;
    }

    void PopFront()
    {
        Node* delNode = head;
        head = head -> next;
        delNode -> next = NULL;
        delete delNode;
    }

    void PushBack(T value)
    {
        //For pop back we must implement doubly linked list
        //A doubly linked list will have reference of next and previous node
        //This will help in certain operations like push back, reverse, etc.
        //Here it will help in keeping track of tail once pop is performed
        Node* node = new Node;
        node -> data = value;
        node -> next = NULL;

        if(head == NULL)
        {
            head = node;
            tail = node;
            return;
        }

        tail -> next = node;
        tail = tail -> next;
        size++;
    }

    void Remove(int index)
    {
        Node* curHead = head;
        int i = 0;

        if(index == 0)
        {
            head = head -> next;
            curHead -> next = NULL;
            delete curHead;
            return;
        }

        while(curHead != NULL)
        {
            if (i == index - 1)
            {
                head = head -> next;
                curHead -> next = NULL;
                delete curHead;
                break;
            }
            ++i;
            curHead = curHead -> next;
        }
    }

    void PrintElementsUsingItteration() const
    {
        Node* curHead = head;
        while(curHead != NULL)
        {
            cout << curHead -> data << " ";
            curHead = curHead -> next;
        }
        cout << endl;
    }

    void PrintElementsUsingRecurssion() const
    {
        PrintElementsRecurssion(head);
        cout << endl;
    }

    void PrintElementsReverseUsingRecurssion() const
    {
        PrintElementsReverseRecurssion(head);
        cout << endl;
    }

    void ReverseListUsingItteration()
    {
        Node* curNode = head;
        Node* nextNode = NULL;
        Node* prevNode = NULL;
        tail = head;

        while(curNode != NULL)
        {
            nextNode = curNode -> next;
            curNode -> next = prevNode;
            prevNode = curNode;
            curNode = nextNode;
        }
        head = prevNode;
    }

    void ReverseListUsingRecurssion()
    {
        tail = head;
        ReverseListRecurssion(head, NULL);
    }

    ~LinkedList()
    {
        Node* curHead = head;
        while(curHead != NULL)
        {
            Node* tempNext = curHead -> next;
            curHead -> next = NULL;
            delete curHead;
            curHead = tempNext;
        }
    }
};

int main()
{
    {
        LinkedList<int> linkedList;
        linkedList.PushBack(5);
        linkedList.PushBack(9);
        linkedList.PushBack(7);
        linkedList.Insert(1, 2);
        linkedList.PrintElementsUsingRecurssion();
        linkedList.Remove(0);
        linkedList.PrintElementsUsingItteration();
        linkedList.PushBack(1);
        linkedList.PushBack(2);
        linkedList.PushBack(3);
        linkedList.PrintElementsUsingRecurssion();
        linkedList.Insert(4, 4);
        linkedList.PrintElementsUsingItteration();
        linkedList.ReverseListUsingItteration();        
        linkedList.PrintElementsUsingRecurssion();
        linkedList.PrintElementsReverseUsingRecurssion();
        cout << "--------" << endl;
        linkedList.PrintElementsUsingRecurssion();
        linkedList.ReverseListUsingRecurssion();
        linkedList.PrintElementsUsingRecurssion();
        cout << "--------" << endl;
        linkedList.PushFront(0);
        linkedList.PrintElementsUsingRecurssion();
        linkedList.PopFront();
        linkedList.PopFront();
        linkedList.PushFront(8);
        linkedList.PrintElementsUsingRecurssion();
        cout << linkedList.TopFront() << endl;
    }

    return 0;
}
```

3) Stacks
<br>
(LIFO) Last In First Out<br>
Push (Insert at the entry of stack), Pop (Remove from entery) & Top (Gets entry element)<br>
All stack operations are performed in constant time<br>
Applications: Undo operation, paranthesis are balanced by compiler using stack, Recurssion stack.
```c++
#include <iostream>
using namespace std;
#define SIZE 10

//Stack can be created using array as well as linked list
template<typename T>
class stack
{
    T* arr;
    int top;
    int capacity;

public:
    stack(int size = SIZE)
    {
        arr = new T[size];
        capacity = size;
        top = -1;
    }
    bool isEmpty() const
    {
        return (top == -1);
    }
    bool isFull() const
    {
        return (top == capacity - 1);
    }
    void push(T x)
    {
        if (isFull())
        {
            cout << "overflow termination" << endl;
            return;
        }
        arr[++top] = x;
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "underflow termination" << endl;
            return;
        }
        top--;
    }
    T peek() const
    {
        if (!isEmpty()) return arr[top];
        else cout << "underflow termination" << endl;
    }
    int size() const
    {
        return top+1;
    }
};

int main()
{
    stack<char> st;
    st.push('A');
    st.push('N');
    st.push('K');
    st.push('I');
    st.push('T');
    while(st.size() > 0)
    {
        cout << st.peek();
        st.pop();
    }

    return 0;
}
```
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
```
```c++
#include <iostream>
#include <stack>
#include <algorithm>        //For reverse
#include <math.h>           //For pow
using namespace std;

int getOperatorRank(char oper)
{
    switch(oper)
    {
        case '^' : return 5;
        case '/' : return 4;
        case '*' : return 3;
        case '+' : return 2;
        case '-' : return 1;
    }
    return -1;
}

double evaluate(double a, double b, char oper)
{
    switch(oper)
    {
        // Everything in reverse b/a b^a b-a because it's postfix
        case '^' : return pow(b, a);
        case '/' : return b/a;
        case '*' : return b*a;
        case '+' : return b+a;
        case '-' : return b-a;
    }
    return 0;
}

int main()
{
    //Infix
    string expression = "5+(6*7-(7/8-9)*4)*3";
    expression = "(" + expression + ")";

    //INFIX TO POSTFIX
    stack<char> postfixStack;
    string postfix = "";
    for (int i = 0; i < expression.size(); ++i)
    {
        char cur = expression[i];
        if (cur == '+' || cur == '-' || cur == '*' || cur == '/' || cur == '^')
        {
            while (getOperatorRank(postfixStack.top()) > getOperatorRank(cur))
            {
                postfix += postfixStack.top();
                postfixStack.pop();
            }
            postfixStack.push(cur);
        }
        else if (cur == ')')
        {
            while (postfixStack.top() != '(')
            {
                postfix += postfixStack.top();
                postfixStack.pop();
            }
            postfixStack.pop();
        }
        else if (cur == '(') postfixStack.push(cur);
        else if (cur != ' ') postfix += cur;
    }
    cout << "postfix: " << postfix << endl;

    //INFIX TO PREFIX
    stack<char> prefixStack;
    string prefix = "";
    for (int i = expression.size()-1; i >= 0; i--)
    {
        char cur = expression[i];
        if (cur == '+' || cur == '-' || cur == '*' || cur == '/' || cur == '^')
        {
            while (getOperatorRank(prefixStack.top()) > getOperatorRank(cur))
            {
                prefix += prefixStack.top();
                prefixStack.pop();
            }
            prefixStack.push(cur);
        }
        else if (cur == '(')
        {
            while (prefixStack.top() != ')')
            {
                prefix += prefixStack.top();
                prefixStack.pop();
            }
            prefixStack.pop();
        }
        else if (cur == ')') prefixStack.push(cur);
        else if (cur != ' ') prefix += cur;
    }
    reverse(prefix.begin(), prefix.end());
    cout << "prefix: " << prefix << endl;

    //PREFIX TO INFIX
    stack<string> pre2inStack;
    string pre2in = "";
    for (int i = prefix.size()-1; i >= 0; i--)
    {
        char cur = prefix[i];
        if (cur == '+' || cur == '-' || cur == '*' || cur == '/' || cur == '^')
        {
            string a = pre2inStack.top();
            pre2inStack.pop();
            string b = pre2inStack.top();
            pre2inStack.pop();
            pre2inStack.push(a + string(1, cur) + b);
        }
        else if (cur != ' ') pre2inStack.push(string(1, cur));
    }
    pre2in = pre2inStack.top();
    cout << "prefix to infix: " << pre2in << endl;

    //POSTFIX TO INFIX
    stack<string> post2inStack;
    string post2in = "";
    for (int i = 0; i < postfix.size(); ++i)
    {
        char cur = postfix[i];
        if (cur == '+' || cur == '-' || cur == '*' || cur == '/' || cur == '^')
        {
            string a = post2inStack.top();
            post2inStack.pop();
            string b = post2inStack.top();
            post2inStack.pop();
            post2inStack.push(a + string(1, cur) + b);
        }
        else if (cur != ' ') post2inStack.push(string(1, cur));
    }
    post2in = post2inStack.top();
    reverse(post2in.begin(), post2in.end());
    cout << "postfix to infix: " << post2in << endl;

    //POSTFIX TO PREFIX
    stack<string> post2preStack;
    string post2pre = "";
    for (int i = 0; i < postfix.size(); ++i)
    {
        char cur = postfix[i];
        if (cur == '+' || cur == '-' || cur == '*' || cur == '/' || cur == '^')
        {
            string a = post2preStack.top();
            post2preStack.pop();
            string b = post2preStack.top();
            post2preStack.pop();
            post2preStack.push(string(1, cur) + b + a);
        }
        else if (cur != ' ') post2preStack.push(string(1, cur));
    }
    post2pre = post2preStack.top();
    cout << "postfix to prefix: " << post2pre << endl;

    //PREFIX TO POSTFIX
    stack<string> pre2postStack;
    string pre2post = "";
    for (int i = prefix.size()-1; i >= 0; i--)
    {
        char cur = prefix[i];
        if (cur == '+' || cur == '-' || cur == '*' || cur == '/' || cur == '^')
        {
            string a = pre2postStack.top();
            pre2postStack.pop();
            string b = pre2postStack.top();
            pre2postStack.pop();
            pre2postStack.push(a + b + string(1, cur));
        }
        else if (cur != ' ') pre2postStack.push(string(1, cur));
    }
    pre2post = pre2postStack.top();
    cout << "prefix to postfix: " << pre2post << endl;

    //EVALUATION OF POSTFIX
    stack<double> evaluateStack;
    double solution = 0;
    for (int i = 0; i < postfix.size(); ++i)
    {
        char cur = postfix[i];
        if (cur == '+' || cur == '-' || cur == '*' || cur == '/' || cur == '^')
        {
            double a = evaluateStack.top();
            evaluateStack.pop();
            double b = evaluateStack.top();
            evaluateStack.pop();
            evaluateStack.push(evaluate(a, b, cur));
        }
        else if (cur != ' ') evaluateStack.push(cur - '0');
    }
    solution = evaluateStack.top();
    cout << "Solution: " << solution << endl;
    return 0;
}
```

4) Queues
<br>
(FIFO) First In First Out<br>
Used in case where requests are sent like to a printer for print requests.<br><br>
Priority Queue is in which there is a priority assosiated with every value. It can be implemented through Binary Heap.<br>
Applications of Priority Queue - CPU Scheduling, Graph Algorithms like Dijikstra, Prim's Minimum Spanning Tree.<br><br>
Naive Implementation Of Priority Queue can be done using an array storing priority integer for every node. Everytime dequeing will look through the entire queue and dequeue the smallest (min priority queue) or larget (max priority queue)<br><br>
In a queue there's one disadvantage that if we do deletion it will happen in front shifting all elements taking O(n). This can be avoided by using circular queue.<br><br>
STL priority queue by default is a max heap pass greater<int> comparator to make it min heap
```c++
priority_queue <int> max_heap;
priority_queue <int, vector<int>, greater<int> > min_heap;
```
<br>![](res/circularqueue.png)<br>

```c++
//Queue can be created using array as well as linked list

template<typename T>
class queue
{
    T* arr;
    int rear, front;
    int capacity;

public:
    queue(int size = SIZE)
    {
        arr = new T[size];
        capacity = size;
        rear = -1;
        front = -1;
    }
    bool isEmpty() const
    {
        return (rear == -1 && front == -1);
    }
    bool isFull() const
    {
        return (rear == capacity - 1);
    }
    void push(T x)
    {
        if (isFull())
        {
            cout << "overflow termination" << endl;
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = x;
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "underflow termination" << endl;
            return;
        }
        front++;
    }
    T peek() const
    {
        if (!isEmpty()) return arr[front];
        else cout << "underflow termination" << endl;
    }
    int size() const
    {
        if (!isEmpty()) return 0;
        return rear-front+1;
    }
};

//In case of circular queue at pop instead of ++rear add this line before that rear = (rear + 1) % capacity.

//In priority queue just assign a struct and dynamiccally allocate it's object created as array of struct. every pop time just traverse entire array and select minimum priority or max priority at traversal. set that struct node to null.
```

5) Double Ended Queue (Deque): It is a generalized form of Queue in which we can insert and delete at both front and back - insertFront, insertBack, deleteFront, deleteBack

6) Sets
<br>
Stores values in sorted order. Stores only unique. Elements can be only inserted and removed (not modified). Sets are implemented as Binary Search Tree. A multiset allows storage of multiple elements. <u>**More in Graph Theory.**</u> While inserting it checks for if the value is unique and it returns an iterator
```c++
// This loop will continue inserting until a duplicate value is reached
while (true)
{
    auto check = s.insert(n);
    if (!check.second) break;
}
```

7) Maps
<br>
Map, Multimap, Unordered map, Unordered multimap<br>
In a hashmap or unordered_map the data input (key) is hashed to convert in some hash value which modulo is then taken<br>
To make that big hash number fit into a list. It is a linked list so if any other data gets the same modulo it gets appended to the linked list.<br><br>
In ordered map data gets stored in sorted manner<br>
In map one value for a key wheras multimap can have many values for a key<br>
Unordered map are stored as hash map whearas map are balanced binary tree. A multimap can store multiple values for a key.<br>
Hash tables suffer from O(n) worst time complexity due to two reasons:<br>
If too many elements were hashed into the same key: looking inside this key may take O(n) time.
Once a hash table has passed its load balance - it has to rehash [create a new bigger table, and re-insert each element to the table].<br>
A hashmap maps giving direct access by hashing the key to a value now two keys may have same hash in that case collision happens. In that case a linked list will be maintain and then ittiration through linked list will be done.<br>
There is also Load Factor which tells how full is our array which stores hashtable. Now we don't want it too low because that will mean our space getting waste and also we don't want it too hight because that will mean that collision will happen more. 
<center>

| Task           |                     Map                      |                     Unordered_Map |
| -------------- | :------------------------------------------: | --------------------------------: |
| Ordering       |       Increasing order <br> by default       |                       No ordering |
| Implementation | Self balancing tree <br> like Red Black Tree |                        Hash Table |
| Search Time    |                    log(n)                    | O(1) -> Average <br>O(n) -> Worst |
| Insertion Time |              log(n) + Rebalance              |                    Same as search |
| Deletion Time  |              log(n) + Rebalance              |                    Same as search |

</center>

8) Trees - <u>**Graph Theory.**</u>
9) Graphs - <u>**Graph Theory.**</u>
10)  Heaps - <u>**Graph Theory.**</u>
11)   Disjoint Sets<br>
Disjoint sets are seperate sets which are represented by 1 identity. Example - 1, 2, 3, 4 initially all 4 are dijoint sets. If we apply make union to 1 & 2 we get (1 2), 3, 4 in (1 2) the identity of both 1 & 2 on calling findSet will be same. RANK AND PATH COMPRESSION

https://www.youtube.com/watch?v=ID00PMy0-vE
```c++
template<typename T>
class DisjointSet
{
private:
    struct Node
    {
        T data;
        Node* parent;
        int rank;
    };
    unordered_map<T, Node*> rec;

public:
    void makeSet(T _data)
    {
        Node* node = new Node{_data, node, 0};
        rec[_data] = node;
    }
    Node* findSet(T _data)
    {
        if (rec.find(_data) == rec.end()) return NULL;
        else return rec[_data]->parent;
    }
    void makeUnion(T data1, T data2)
    {
        Node* parent1 = findSet(data1);
        Node* parent2 = findSet(data2);
        if (parent1->rank >= parent2->rank)
        {
            parent1->rank = (parent1->rank == parent2->rank) ? parent1->rank + 1 : parent1->rank;
            parent2->parent = parent1;
        }
        else
            parent1->parent = parent2;
    }
};
```

1)  Tries<br>
It's an information retrieval data structure also known as radix/prefix tree.
<br>![](res/trie.jpg)<br>
```c++
class Trie
{
private:
    struct Node
    {
        char data;
        bool isTerminal;
        unordered_map<char, Node*> next;
        Node(char d) : data(d), isTerminal(false) { }
    };
    Node* root = new Node('\0');

public:
    void addWord(string word)
    {
        Node* temp = root;
        for (char ch : word)
        {
            if (temp->next.find(ch) == temp->next.end())
            {
                Node* child = new Node(ch);
                temp->next[ch] = child;
                temp = child;
            }
            else
                temp = temp->next[ch];
        }
        temp->isTerminal = true;
    }
    bool search(string word)
    {
        Node* temp = root;
        for (char ch : word)
        {
            if (temp->next.find(ch) != temp->next.end())
                temp = temp->next[ch];
            else
                return false;
        }
        return temp->isTerminal;
    }
};
```
https://www.geeksforgeeks.org/palindrome-pair-in-an-array-of-words-or-strings/<br>
![](res/hVkzy.png)
```
[bat, tab, cat] these will make battab or tabbat so we will get palindrome when
- size[i] = size[j] and j is rev of i
- size[i] > size[j] and i must end with rev of j and remaining letters of i is palindrome

This Trie makes it pretty efficient to search for prefixes. For instance searching for cba (reverse of  abc) gives the node starting cbaaa
1) Create an empty Trie.
2) Do following for every word:-
    a) Insert reverse of current word.
    b) Also store up to which index it is
       a palindrome.
3) Traverse list of words again and do following
   for every word.
    a) If it is available in Trie then return true
    b) If it is partially available
         Check the remaining word is palindrome or not
         If yes then return true that means a pair
         forms a palindrome.
         Note: Position upto which the word is palindrome
               is stored because of these type of cases.
```

13) Segment Tree<br>
Say given array we want to calculate sum (or anyother query like max from L to R) from L to R. we can do it in O(N) time or in O(1) if we calculate prefix sum of the array. With Segment Tree we take O(logN) however we can also update our array updating then summing over range is fastest through segment tree if no updating then better use prefix sum.<br>
![](res/segmentTree.png)<br>
**Every node represents the answer to a query**<br>
![](res/QUERYST.png)
```c++
#include <bits/stdc++.h>
using namespace std;

int tree[900000];
void buildTree(int arr[], int start, int end, int node = 1)
{
    if (start == end)
    {
        tree[node] = arr[end];
        return;
    }
    int mid = (start + end) >> 1;
    buildTree(arr, start, mid, node*2);
    buildTree(arr, mid+1, end, node*2 + 1);
    tree[node] = tree[node*2] + tree[node*2 + 1];
}
int queryTree(int start, int end, int l, int r, int node = 1)
{
    if (start > end || start > r || end < l) return 0; //No Overlap
    if (start >= l && end <= r) return tree[node]; //Complete Overlap
    //Partial Overlap
    int mid = (start + end) >> 1;
    int q1 = queryTree(start, mid, l, r, node*2);
    int q2 = queryTree(mid+1, end, l, r, node*2 + 1);
    return q1 + q2;
}
void updateTree(int start, int end, int i, int val, int node = 1)
{
    if (start > end || start > i || end < i) return; //No Overlap
    if (start == end) //Complete Overlap
    {
        tree[node] = val;
        return;
    }
    //Partial Overlap
    int mid = (start + end) >> 1;
    updateTree(start, mid, i, val, node*2);
    updateTree(mid+1, end, i, val, node*2 + 1);
    tree[node] = tree[node*2] + tree[node*2 + 1];
}
int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr) / sizeof(int);
    buildTree(arr, 0, n-1);
    cout << queryTree(0, n-1, 2, 4) << endl;    //21
    updateTree(0, n-1, 3, 19);
    for (int i = 1; i < 14; ++i) cout << tree[i] << " ";
    cout << endl;
    cout << queryTree(0, n-1, 2, 4) << endl;    //33
    return 0;
}
```
**BUILD O(N), QUERY O(logN), UPDATE O(logN)**<br>
Updating a single values takes O(logN) say we want to range update values naively calling will be O(NlogN) it can be O(N) since entire tree may need to be updated in the worst case and it will be of order N. Most optimized is using lazy propagation in O(logN)<br>
```c++
void updateRange(int start, int end, int l, int r, int increment, int node = 1)
{
    if (start > end || start > r || end < l) return;
    if (start == end)
    {
        tree[node] += increment;
        return;
    }
    int mid = (start + end) >> 1;
    updateRange(start, mid, l, r, increment, node*2);
    updateRange(mid+1, end, l, r, increment, node*2+1);
    tree[node] = tree[node*2] + tree[node*2 + 1];
}
```
Lazy Propagation simply assigns a lazy value for all node in a tree. Say we update a range if it's a complete overlap then that range node will get a lazy value assosiated otherwise the conjection of partials will be. Then later on if a query is passed to any node we start from parent root node always going deep, if we found any non zero lazy then we will resolve that node means we will increment that node to it's value and also pass it on to it's children.
```c++
int lazy[900000];
void lazyUpdate(int start, int end, int l, int r, int val, int node = 1)
{
    if (lazy[node] != 0)
    {
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end)
        {
            lazy[node*2] += lazy[node];
            lazy[node*2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (start > end || start > r || end < l) return;
    if (start >= l && end <= r)
    {
        tree[node] += (end - start + 1) * val;
        if (start != end)
        {
            lazy[node*2] += lazy[node];
            lazy[node*2 + 1] += lazy[node];
        }
        return;
    }
    int mid = (start + end) >> 1;
    lazyUpdate(start, mid, l, r, val, node*2);
    lazyUpdate(mid+1, end, l, r, val, node*2 + 1);
    tree[node] = tree[node*2] + tree[node*2 + 1];
}
int lazyQuery(int start, int end, int l, int r, int node = 1)
{
    if (start > end || start > r || end < l) return 0;
    if (lazy[node] != 0)
    {
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end)
        {
            lazy[node*2] += lazy[node];
            lazy[node*2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (start >= l && end <= r) return tree[node];
    int mid = (start + end) >> 1;
    int q1 = lazyQuery(start, mid, l, r, node*2);
    int q2 = lazyQuery(mid+1, end, l, r, node*2 + 1);
    return q1 + q2;
}
```
DIVMAC.cpp<br>

14. Fenwick Or Binary Index Tree<br>
It is used to calculate prefix sum of an array. It's not as powerful as Segment Tree but it's simpler to implement.<br>
In the image, BIT will be stored in array of n+1 length. (indexing starts with 1 because binary operation used later onn will be anomoly for 0) for each say 3 find 3 & -3 this will flip right most set bit giving the parent from tree.<br>
Now to fill all value say 4 we find 4 = 0 + 2^2 means we go from 0th index to next 4 elements or for 11 = 2^3 + 2^1 + 2^0 from 10-10
![](res/BIT.png)<br>
If we need to find sum from 0 to 5 we first go to value 6 take it here it's 9 then we go to it's parent it's 10 so ans is 19
```c++
void update(int BIT[], int n, int i, int incr)
{
    while (i <= n)
    {
        BIT[i] += incr;
        i += (i & -i);
    }
}
int query(int BIT[], int n, int i)
{
    int ans = 0;
    while (i > 0)
    {
        ans += BIT[i];
        i -= (i & -i);
    }
    return ans;
}
```
BIT array stores values like: left = i - 2<sup>r</sup> + 1. right = i. Here r is rightmost set bit position. example-<br>
BIT(1) = 1 - 2<sup>0</sup> + 1 = [1, 1]<br>
BIT(2) = 2 - 2<sup>1</sup> + 1 = [1, 2]<br>
Observation: ans is [i, i] for all odd no. ans is [1, i] for 2 power no.

When to use BIT - When inverse exists like addition has subtraction or multiplication have division, max min, but not with gcd.

https://www.geeksforgeeks.org/count-inversions-array-set-3-using-bit/

## 7. Greedy Algorithm
Count out certain amount of money, using fewest possible notes or coins.<br>
39 = 10 + 10 + 10 + 5 + 2 + 2<br>
We are going for greedy approach chosing local optimum (max value we can take) to achieve global optimum. **This may not be true for some other currencies** Like in above case leaf node represents single segment all parent to it gives sum within range query.

Greedy is more efficient then DP. O(NLogN) of Greedy can also be optimized by using counting sort if and only if our total elements are less variant. Or even radix sort can be used.