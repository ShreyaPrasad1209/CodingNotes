# Algorithms
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

3) Big-Theta Notation (Ω) : Average Case
   <br>
   c<sub>1</sub> * g(n) ≤ f(n) ≤ c<sub>2</sub> * g(n)

```c++
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < n; j++)
        c[i][j] = a[i][j] + b[i][j];
}
```

In this:<br>
The condition i < n & j < n will execute (n + 1)<sup>2</sup> times <br>
Next all c[i][j] operation will execute (n)<sup>2</sup> times<br>
And 2 * 4 bytes for storing int<br>
Which equals to 2n<sup>2</sup> + 2n + 2

## 3. Recursion:
Dividing problem in sub problems and make a function call recursively to solve it. There will be a base case to terminate the infinite recursion. Recursion can be visualized through stack. There are two types of recursion -
```c++
void head(int n)
{
    //Recursion stack: 5, 4, 3, 2, 1, cout 1, cout 2, cout3, cout 4, cout 5
    if (n == 1)
        return;
    head(n-1);
    cout << n << endl;
}
```
```c++
void tail(int n)
{
    //Recursion stack: cout 5, cout 4, cout 3, cout 2, cout 1
    if (n == 1)
        return;
    cout << n << endl;
    tail(n-1);
}
```
Every itteration can be transformed to recursion and vice versa. Recursion is time costlier than itteration.

**Problem #1 (Factorial Problem)**
```c++
int factorial(int n)
{
    //Recursion stack: 5 * fac(4), 4 * fac(3), 3 * fac(2), 2 * fac(1), 1, 2, 6, 24, 120
    if (n==1)
        return 1;
    return n * factorial(n-1);
}
```
```c++
int factorial(int accumulator, int n)
{
    //Recursion stack: fac(5, 4), fac(20, 3), fac(60, 2), fac(120, 1), 120
    if (n==1)
        return accumulator;
    return factorial(accumulator * n, n-1);
}
int calculateFactorial(int n)
{
    factorial(1, n);
}
```

**Problem #2 (GCD Problem)**
```c++
int gcdItter(int a, int b)
{
    while (b != 0)
    {
        int temp = a;
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

**Problem #3 (Hanoi Problem)**
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

## 4. Searching:

**Problem #1 (Linear Search)**
```c++
//Time: O(n)
int search(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
            return i;
    }
    return -1;
}
```

**Problem #2 (Binary Search)**
```c++
//Applies on sorted array. divides the arr to check which side it can belong then recursively checks that subarray.
//Time: O(logn)
int search(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = (l + r)/2;
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

**Problem #3 (Jump Search)**
```c++
//Applies on sorted array. Performs linear search but in a form of group of √n
//Time: O(√n)
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

    for (int i = left; i < right; i++)
    {
        if (arr[i] == x)
            return i;
    }
    return -1;
}
```

**Problem #4 (Interpolation Search)**
```c++
/*
An Interpolation Search is a type of searching algorithm. An Interpolation Search is an improvement over Binary Search for scenarios where the values in a sorted array are uniformly distributed.

Binary Search goes to the middle element to check. On the other hand, Interpolation Search may go to different locations according to the value of the key being searched.

Time: O(loglogn) however in case of value not in the array the time will be O(n)
*/
int search(int arr[], int n, int x)
{
    int left = 0;
    int right = n - 1;

    while (left <= right && x >= arr[left] && x <= arr[right])
    {
        pos = left + (((double)(right - left) / (arr[right] - arr[left])) * (x - arr[left]))
        if (arr[pos] == x)
            return pos;
        else if (x > arr[pos])
            start = pos + 1;
        else
            start = pos - 1;
    }

    return -1;
}
```

**Problem #5 (Exponential Search)**
```c++
//It finds a range within which the number can be found. by performing exponential check. First from 1 to 2 then 2 to 4 then 4 to 8... and then it performs binary search on the range.
//Time: O(logn)
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