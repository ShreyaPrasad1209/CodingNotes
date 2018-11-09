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
        else return return search(arr, mid+1, r, x);
    }
    //Right subarray is sorted
    else if (arr[mid] <= arr[r])
    {
        if (arr[mid] <= x && arr[r] >= x) return search(arr, mid+1, r, x);
        else return return search(arr, l, mid-1, x);
    }
}
```

## 3. Maximum sum of i*arr[i] among all rotations - Amazon
<u>O(N)</u>
```
[8, 3, 1, 2] - 0*8 + 1*3 + 2*1 + 3*2 = 11
[3, 1, 2, 8] - 0*3 + 1*1 + 2*2 + 3*8 = 29 - ANS IS 29
[1, 2, 8, 3] - 0*1 + 1*2 + 2*8 + 3*3 = 27
[2, 8, 3, 1] - 0*2 + 1*8 + 2*3 + 3*1 = 17
```
For every rotation there's a pattern. every element except first got multiplied 1 less then before and the first element get's to front so it's multiplied with (n-1) instead of zero.<br>
So for every next rotation value is: curVal - (sum - arr[0]) + (arr[0] * (n-1))

## 4. Rotation Count in Rotated Sorted Array - Amazon
[ 15, 18, 2, 3, 6, 12 ] ANS: 2 <u>O(logN)</u><br>
Simply apply binary search, go to middle element check arr[l] < arr[mid-1] and arr[mid+1] < arr[r] the subarray which does not fullfil this perform binary search over there now.

## 5. Reverse an array or string - Infosys, VMware
<br>![](res/1.jpg)<br><u>O(logN)</u><br>

## 6. Rearrange elements to have alternate +ve -ve elements O(N)O(1) - Amazon, Paytm
Seperate +ve and -ve numbers using quick sort partition technique and then simply do rearrangment by swapping elements.

## 7. Moving zeroes to end of array O(N)O(1) - Amazon, Bloomberg, Paytm
Simply traverse left to right keep swapping if zero encounters
