# Binary Search

## Matrix Median
https://www.interviewbit.com/problems/matrix-median/
```c++
//We are basically finding desired value (desired as in which index on sorted array is middle)
int Solution::findMedian(vector<vector<int> > &A)
{
    int n = A.size(), m = A[0].size();
    int _min = INT_MAX, _max = INT_MIN, desired = (n*m+1)/2;
    for (int i = 0; i < n; ++i)
    {
        _min = min(_min, A[i][0]);
        _max = max(_max, A[i][m-1]);
    }
    while (_min < _max)
    {
        int mid = _min + (_max-_min)/2;
        int place = 0;
        for (int i = 0; i < n; ++i)
            place += upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();

        if (place < desired) _min = mid+1;
        else _max = mid;
    }
    return _min;
}
```

## Square Root Of Integer
https://www.interviewbit.com/problems/square-root-of-integer/
```c++
int Solution::sqrt(int A)
{
    if (A == 0 || A == 1) return A;
    int l = 0, r = A, ans;
    while(l <= r)
    {
        int mid = l + (r-l)/2;
        // having mid*mid <= A was giving TLE
        if (mid <= A/mid) l = mid+1, ans = mid;
        else r = mid-1;
    }
    return ans;
}
```

## Rotated Sorted Array Search
https://www.interviewbit.com/problems/rotated-sorted-array-search/
```c++
int search2(const vector<int> &A, int l, int h, int key)
{
    if (l > h) return -1;
    int mid = (l+h)/2;
    if (A[mid] == key) return mid;
    if (A[l] <= A[mid])
    {
        if (key >= A[l] && key <= A[mid]) return search2(A, l, mid-1, key);
        else return search2(A, mid+1, h, key);
    }
    if (key >= A[mid] && key <= A[h])
        return search2(A, mid+1, h, key);
    return search2(A, l, mid-1, key);
}
int Solution::search(const vector<int> &A, int B)
{
    int i = search2(A, 0, A.size()-1, B);
    return i;
}
```

## Median of Array
https://www.interviewbit.com/problems/median-of-array/<br>
```c++
// MEDIAN OF ARRAY OF SAME SIZE
// Median of two sorted array O(N) we are merging both sorted array to get one sorted
// array using merge sort. Media will be middle two element since it has even elements
int findMedian(vector<int> arr1, vector<int> arr2)
{
    int n = arr1.size() + arr2.size();
    vector<int> arr(n);
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] < arr2[j]) arr[k] = arr1[i], ++i;
        else arr[k] = arr2[j], ++j;
        ++k;
    }
    while (i < arr1.size()) arr[k] = arr1[i], ++i;
    while (j < arr2.size()) arr[k] = arr2[j], ++j;

    return (arr[n/2] + arr[n/2 - 1])/2;
}
// O(logN) solution
// calculate medians of arr1 and arr2.
// If m1 == m2 then return it
// If m1 > m2 then repeat looking for in [0...n/2] of arr1 and [n/2...n-1] of arr2
// If m1 < m2 then repeat looking for in [n/2...n-1] of arr1 and [0...n/2] of arr2
// If size of both array is 2 then Median = (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1]))/2
```
![](res/../../../res/IMG_20190409_232712395.jpg)
```c++
int findMedian(vector<int> arr1, vector<int> arr2, int l1, int l2, int n)
{
    if (n == 1)
        return (arr1[l1] + arr2[l2]) / 2;
    else if (n == 2)
        return (max(arr1[l1], arr2[l2]) + min(arr2[l1+1], arr2[l2+1])) / 2;

    int m1 = (n%2 == 0) ? (arr1[l1 + n/2 - 1] + arr1[l1 + n/2]) / 2 : arr1[l1 + n/2];
    int m2 = (n%2 == 0) ? (arr2[l2 + n/2 - 1] + arr2[l2 + n/2]) / 2 : arr2[l2 + n/2];

    if (m1 == m2)
        return m1;
    else if (m1 > m2)
    {
        if (n%2 == 0) return findMedian(arr1, arr2, l1, l2 + n/2 - 1, n/2 + 1);
        else return findMedian(arr1, arr2, l1, l2 + n/2, n/2 + 1);
    }
    else
    {
        if (n%2 == 0) return findMedian(arr1, arr2, l1 + n/2 - 1, l2, n/2 + 1);
        else return findMedian(arr1, arr2, l1 + n/2, l2, n/2 + 1);
    }
}
```
```
FIND MEDIAN OF DIFFERENT SIZE ARRAY: O(N) solution is same using merge sort O(N)
For O(logN) solution it will be same though size is not same so we have to take care of many base cases
N = 0, M : return median of arr2
N = 1, M = 1 : return avg of arr1[0] arr2[0]
N = 1, M = odd : then new cases for ex: {5, 10, 12, 15, 20}
                 if (arr1[0] < 10) return avg 10 12
                 if (arr1[0] is b/w 10 12) return avg arr1[0] and 12
                 if (arr1[0] is b/w 12 15) return avg 12 and arr1[0]
                 if (arr1[0] > 15) return avg 12 15
N = 1, M = even : then new cases for ex: {5, 10, 12, 15}
                 if (arr1[0] < 10) return 10
                 if (arr1[0] is b/w 10 12) return arr1[0]
                 if (arr1[0] > 12) return 12
N = 2, M = 2 : find median of all 4
N = 2, M = odd : then new cases for ex: {5, 10, 12, 15, 20}
                 median of - arr2[M/2], max(arr1[0], B[M/2 - 1]), min(arr1[1], B[M/2 + 1])
N = 2, M = even : then new cases for ex: {5, 10, 12, 15}
                 median of - arr2[M/2], arr2[M/2 - 1], max(arr1[0], B[M/2 - 2]), min(arr1[1], B[M/2 + 1])
Rest do the implementation of same size
```

## Painter Partition Problem
```c++
/*
Given boards and we have 3 painters: 100 200 300 400 500 | 600 700 | 800 900
This way each painter would have to: 1500 | 1300 | 1700 so variance is less

Way like calculating total paint and then dividing by k and trying to match each partition as close to it could not evaluate all possibilities systematically and thus do not always produce the correct solution.
*/

int partition(vector<int> arr, int n, int k)
{
    if (k == 1) return accumulate(arr.begin(), arr.begin() + n, 0);
    if (n == 1) return arr[0];

    int best = INT_MAX;
    for (int i = 1; i <= n; i++)
        best = min(best, max(partition(arr, i, k - 1), accumulate(arr.begin() + i, arr.begin() + n, 0)));

    return best;
}
// using memoziation will reduce complexity to O(k N cube) we can also avoide accumulate by precomputing it reducing complexity to O(K N square)
// Binary Search Approach O(N log(sum of arr))
/*
example - [1, 2, 3, 4, 5, 6, 7, 8, 9]

 9-------45
low     high
low is when there are n painters. high is when there is 1 painter
find mid = 27
find what mid corresponds to
1+2+3+4+5+6 and 7+8+9 this way array partitions such that parts sum is less then mid. (2 parts)

 6------2------1
low    mid   high
apply binary search on low and mid
*/
int no_of_painters(vector<int> arr, int n, int maxLen)
{
    int total = 0, numPainters = 1;
    for (int i = 0; i < n; ++i)
    {
        total += arr[i];
        if (total > maxLen)
        {
            total = arr[i];
            numPainters++;
        }
    }
    return numPainters;
}

int partition(vector<int> arr, int n, int k)
{
    int lo = *max_element(arr.begin(), arr.end());
    int hi = accumulate(arr.begin(), arr.end(), 0);
    while (lo < hi)
    {
        int mid = lo + (hi - lo) / 2;
        int reqd_painters = no_of_painters(arr, n, mid);
        if (reqd_painters <= k) hi = mid;
        else lo = mid+1;
    }
    return lo;
}
```
Simmilar question Allocate Books - https://www.youtube.com/watch?v=Ss9ta1zmiZo

# Bit Manipulation

# Strings

# Two Pointers