# Array
## 1. Array Rotation - Amazon, Codenation
[1, 2, 3, 4, 5, 6, 7] -> [3, 4, 5, 6, 7, 1, 2]<br>
**Way 1:** Using temp array <u>O(N) O(D)</u><br>

**Way 2:** Rotate by one till D times so [1, 2, 3, 4, 5, 6, 7] -> [2, 3, 4, 5, 6, 7, 1] -> [3, 4, 5, 6, 7, 1, 2] <u>O(N*D) O(1)</u><br>

**Way 3:** Using juggling algorithm: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12] n=12 d=3 gcd(n, k) = 3 Store temp variable for ith place <u>O(N) O(1)</u><br>
<center>[ <u>1</u>, 2, 3, <u>4</u>, 5, 6, <u>7</u>, 8, 9, <u>10</u>, 11, 12 ]</center>
<center>[ <u>4</u>, 2, 3, <u>7</u>, 5, 6, <u>10</u>, 8, 9, <u>1</u>, 11, 12 ]</center>
<center>[ 4, <u>5</u>, 3, 7, <u>8</u>, 6, 10, <u>11</u>, 9, 1, <u>2</u>, 12 ]</center>
<center>[ 4, 5, <u>6</u>, 7, 8, <u>9</u>, 10, 11, <u>12</u>, 1, 2, <u>3</u> ]</center>

**Way 4:** [2, 1, 3, 4, 5, 6, 7] n=7 d=3 <u>O(N) O(1)</u><br>
<center>[ <u>2, 1, 3</u>, 4, 5, 6, 7 ]</center>
<center>[ <u>3, 1, 2</u>, 7, 6, 5, 4 ]</center>
<center>[ 4, 5, 6, 7, 2, 1, 3 ]</center>

## 2. Binary Search On Rotated Array - Amazon, Adobe, DE Shaw, Microsoft
Apply Binary Search (0+6)/2 = 3 is key. Check left subarray [3, 4, 5] 3 < 5 it's sorted then check other subarray [7, 1, 2] 7 > 2 Not sorted! <br>
[ 3, 4, 5, 6, 7, 1, 2 ] -> [ 3, 4, 5, <u>6</u>, 7, 1, 2 ] <u>O(logN)</u>
```c++
int search(int arr[], int l, int r, int x)
{
    int mid = (l+r) >> 1;
    if (l > r) return -1;
    if (arr[mid] == x) return mid;

    //Left subarray is sorted
    if (arr[l] <= arr[mid])
    {
        if (arr[l] <= x && arr[mid] >= x) return search(arr, l, mid-1, x);
        else return search(arr, mid+1, r, x);
    }
    //Right subarray is sorted
    else if (arr[mid] <= arr[r])
    {
        if (arr[mid] <= x && arr[r] >= x) return search(arr, mid+1, r, x);
        else return return search(arr, l, mid-1, x);
    }
}
```

## 4. Maximum sum of i*arr[i] among all rotations - Amazon
<u>O(N)</u>
```
[8, 3, 1, 2] - 0*8 + 1*3 + 2*1 + 3*2 = 11
[3, 1, 2, 8] - 0*3 + 1*1 + 2*2 + 3*8 = 29 - ANS IS 29
[1, 2, 8, 3] - 0*1 + 1*2 + 2*8 + 3*3 = 27
[2, 8, 3, 1] - 0*2 + 1*8 + 2*3 + 3*1 = 17
```
For every rotation there's a pattern. every element except first got multiplied 1 less then before and the first element get's to front so it's multiplied with (n-1) instead of zero.<br>
So for every next rotation value is: curVal - (sum - arr[0]) + (arr[0] * (n-1))

## 5. Rotation Count in Rotated Sorted Array - Amazon
[ 15, 18, 2, 3, 6, 12 ] ANS: 2 <u>O(logN)</u><br>
Simply apply binary search, go to middle element check arr[l] < arr[mid-1] and arr[mid+1] < arr[r] the subarray which does not fullfil this perform binary search over there now.

## 6. Reverse an array or string - Infosys, VMware
<br>![](res/1.jpg)<br><u>O(N)</u><br>

## 7. Rearrange elements to have alternate +ve -ve elements O(N)O(1) - Amazon, Paytm
We will use partition technique of quick sort and partition the array on the basis of zero. All the elements lesser (-ve) are on left and (+ve) on right side. This is inplace then we can simply swap to make alternate positive series.

## 8. Moving zeroes to end of array O(N)O(1) - Amazon, Bloomberg, Paytm
Simply traverse left to right keep swapping if zero encounters

## 9. Double the first element and move zero to end - Microsoft
Given Array: [2, 2, 0, 4, 0, 8] = [4, 4, 8, 0, 0, 0] Zeros are invalid numbers. We are required to double the number if it's valid and appeared twice in continuation double first and make second zero and after complete traversal move zeroes to the right.

## 10. Reorder an array according to given indexes - O(N)O(1)
Given arr1[10, 11, 12] and arr2[1, 0, 2] we want result[11, 10, 12]
```
Traverse 0...n both array
If index array value doesn't match with loop index then swap incrementing or decrementing the value.
```

## 11. Arrange given numbers to form the biggest number - Amazon, MakeMyTrip, Paytm
[54, 546, 548, 60] ans will be 6054854654.<br>
Solution is simple sort lexiographically simply sorting won't work and then append it.
```c++
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string arr[n];
    for (int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr, arr + n);
    string res = "";
    for (int i = n-1; i >= 0; --i) res += arr[i];
    cout << res << endl;
    return 0;
}
```

## 12. Rearrange an array such that ‘arr[j]’ becomes ‘i’ if ‘arr[i]’ is ‘j’
```
[1, 3, 0, 2]
Since arr[0] is 1, arr[1] is changed to 0
Since arr[1] is 3, arr[3] is changed to 1
Since arr[2] is 0, arr[0] is changed to 2
Since arr[3] is 2, arr[2] is changed to 3
[2, 0, 3, 1]
```
**Way 1:** Using temp array & copying. <u>O(N)O(N)</u><br>
**Way 2:** <u>O(N)O(1)</u> Update value to oldVal + newVal*n. Later if we want oldVal it's /n newVal is%n. Here n is size of array

## 13. Replace every array element by multiplication of previous and next
For first element a[0] * a[1], For last a[n-2] * a[n-1], others a[i-1] * a[i+1]<br>
[2, 3, 4, 5, 6]<br>
[2 * 3, 2 * 4, 3 * 5, 4 * 6, 5 * 6]<br>
[6, 8, 15, 24, 30]<br>
**Way 1:** Using temp array & copying. <u>O(N)O(N)</u><br>
**Way 2:** <u>O(N)O(1)</u> Simply keep track of previous unchanged version of element<br>

## 14. K’th Smallest/Largest Element in Unsorted Array - VMware, Microsoft, Wallmart
[7, 10, 4, 3, 20, 15] k = 3, ans = 7<br>
**Way 1:** Using sorting or min/max heap. <u>O(NlogN)</u><br>
**Way 2:** Improved bubble sort make it run till k times only. <u>O(NK)</u><br>
TODO: https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array-set-3-worst-case-linear-time/

## 15. Kth smallest element in a row-wise and column-wise sorted 2D array - Accolite, Amazon
```
Every element in row & collumn is arranged in non-decreasing order.
        10, 20, 30, 40
        15, 25, 35, 45
        24, 29, 37, 48
        32, 33, 39, 50
```
Idea is to itterate, initially smallest is always topleft. At any point we can go right or bottom which one is smaller.

## 16. Find all elements in array which have at-least two greater elements
[2, 8, 7, 1, 5] ans = [2, 1, 5]<br>
We can sort and pick all numbers excluding maximum 2 this will be O(NlogN) or we can simply find maximum 2 numbers instead in 2 itteration then print all numbers except them it will be O(N)

## 17. Median of Stream of Running Integers - Microsoft, Amazon, Ola, Oracle, Adobe, Google, Facebook, Yahoo, Apple
[5, 10, 15] = [5, 7.5, 10]<br>
Use BST, after every insertion go with inorder traversal it will be sorted find median.<br>
TODO: https://www.geeksforgeeks.org/median-of-stream-of-running-integers-using-stl/

## 18. Counting Inversions - Microsoft, Flipkart, Amazon, Adobe
https://www.geeksforgeeks.org/counting-inversions/

## 19. Rotate Matrix
```
int n;
cin >> n;
vector< vector<int> > mat(n, vector<int>(n));
for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
        cin >> mat[i][j];

for (int i = 0; i < n/2; ++i)
{
    int x = n-i-1;
    for (int j = i; j < x; ++j)
    {
        int offset = j-i;
        int top = mat[i][j];
        mat[i][j] = mat[x-offset][i];
        mat[x-offset][i] = mat[x][x-offset];
        mat[x][x-offset] = mat[j][x];
        mat[j][x] = top;
    }
}

for (int i = 0; i < n; ++i)
{
    for (int j = 0; j < n; ++j)
        cout << setw(3) << mat[i][j];
    cout << endl;
}
```