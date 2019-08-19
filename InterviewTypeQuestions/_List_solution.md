# Level 1
## 1. Merge Overlap
```c++
/*
Compare functions are like this: a pehle aayega b se kya ye sahi he yaa nahi, you need to return a bool
if a.start < b.start means haan a aana chahiye b se pehle agar a chota he b se (Ascending order)
*/
bool mycmp(Interval a, Interval b)
{
    return a.start < b.start;
}
vector<Interval> Solution::merge(vector<Interval> &A)
{
    vector<Interval> ans;
    sort(A.begin(), A.end(), mycmp);
    for (int i = 0; i < A.size(); ++i)
    {
        if (ans.size() > 0 && A[i].start <= ans[ans.size()-1].end)
            ans[ans.size()-1].end = max(A[i].end, ans[ans.size()-1].end);
        else ans.push_back(A[i]);
    }
    return ans;
}
```

## 2. Hotel Booking Problem
```c++
/*
Consider it like a timeline, 1 means arrival -1 means departure tabhi sort kara
In interviewbit question there was no such case ki arrival and departure same hosake in geeksforgeek variation it can be same as well. Same ho sakte he toh we have to check and remove that pair otherwise answer galat aayega using this approach.
*/
bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K)
{
    vector<pair<int, int> >v;
    int n = arrive.size();
    for(int i = 0; i < n; ++i)
    {
        v.push_back(make_pair(arrive[i],1));
        v.push_back(make_pair(depart[i],-1));
    }
    sort(v.begin(), v.end());
    int count = 0;
    for(int i = 0; i < 2*n; ++i)
    {
        count += v[i].second;
        if(count > K) return false;
    }
    return true;
}
```

## 3. Largest Number
```c++
/*
Simply sorting won't do it because 548 is greater than 60 par wo smaller aayega sort karke string ko
toh we use this compare function 548 ko 60 se compare kare toh compare 54860 and 60548 XY.compare(YX) > 0 means XY bada he kya YX se (it will check lexiographically)
*/
string Solution::largestNumber(const vector<int> &A)
{
    vector<string> b;
    for(int i = 0; i < A.size(); ++i)
        b.push_back(to_string(A[i]));
    sort(b.begin(), b.end(), [](string x, string y)
    {
        string xy = x.append(y);
        string yx = y.append(x);
        return xy.compare(yx) > 0 ? 1 : 0;
    });
    string ans = "";
    for(int i=0;i<b.size();i++) ans += b[i];
    bool allzero = true;
    for (char i : ans)
    {
        if (i != '0')
        {
            allzero = false;
            break;
        }
    }
    if (allzero) return "0";
    return ans;
}
```

# 4. Max Distance
```c++
int Solution::maximumGap(const vector<int> &A)
{
    int n = A.size();
    if (n == 0) return -1;
    vector< pair<int, int> > arr;
    for (int i = 0; i < n; ++i)
        arr.push_back(make_pair(A[i], i));
    sort(arr.begin(), arr.end());
    int ans = 0;
    int rmax = arr[n-1].second;
    for (int i = n-2; i >= 0; --i)
    {
        ans = max(ans, rmax - arr[i].second);
        rmax = max(rmax, arr[i].second);
    }
    return ans;
}
```

## 5. First Missing Integer
```c++
/*
It must be given that array have some confined range n elements he toh positive numbers 0 to n-1 hi ho type
Other variation is using N*(N+1)/2
*/
int Solution::firstMissingPositive(vector<int> &A)
{
    // [3, 4, -1, 1] Input
    // STD magic baby XD without iterators hume swap karna padta uff
    for (auto it = A.begin(); it != A.end(); )
    {
        if (*it <= 0) A.erase(it);
        else ++it;
    }
    // [3, 4, 1]
    for (int i = 0; i < A.size(); ++i)
    {
        int cur = abs(A[i]) - 1;
        if (cur >= 0 && cur < A.size())
            A[cur] = -A[cur];
    }
    // [-3, 4, -1]
    for(int i=0;i<A.size();i++)
    {
        if(A[i]>0)
            return i+1;
    }
    return A.size()+1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n-1);
        for (int i = 0; i < n-1; ++i) cin >> arr[i];
        ll sum = accumulate(arr.begin(), arr.end(), 0);
        ll ans = ((n * (n+1)) / 2) - sum;
        cout << ans << endl;
    }
    return 0;
}
```

## 6. Duplicate In Array
https://medium.com/solvingalgo/solving-algorithmic-problems-find-a-duplicate-in-an-array-3d9edad5ad41
```c++
int Solution::repeatedNumber(const vector<int> &A)
{
    int slow = A[0];
    int fast = A[A[0]];
    while (slow != fast)
    {
        slow = A[slow];
        fast = A[A[fast]];
    }

    fast = 0;
    while (slow != fast)
    {
        slow = A[slow];
        fast = A[fast];
    }

    if (slow == 0) return -1;
    return slow;
}
```

## 7. Maximum Consecutive Gap
```c++
/*
Loved the strategy, basically agar sort karsakte toh kitna sahi hota but we have to do in O(N) so we have to reduce our comparisons
Consider uniform gap he toh: min, min + gap, min + 2*gap, ... min + (n-1)*gap
min + (n-1)*gap = max
gap = (max - min) / (n-1)
Now we place every number in these n-1 buckets: bucket = num - min / gap
we prepare max and min for each bucket and subtract to find our answer

Or spoiler alert just use counting sort here in this question it works but counting sort is not good over varying range
*/
int Solution::maximumGap(const vector<int> &A)
{
    if (A.size() < 2) return 0;
    vector<int> forMin(A.size(), -1);
    vector<int> forMax(A.size(), -1);
    int maxDist = 0, mini = INT_MAX, maxi = INT_MIN, gap = 0, bucket = 0, ind = 0;
    for (int i = 0; i < A.size(); ++i)
    {
        mini = min(A[i], mini);
        maxi = max(A[i], maxi);
    }
    gap = (maxi - mini) / (A.size() - 1);
    if (gap == 0) return (maxi - mini);
    for (int i = 0; i < A.size(); ++i)
    {
        bucket = (int)((A[i] - mini)/gap);
        if (forMin[bucket] < 0)
        {
            forMin[bucket] = A[i];
            forMax[bucket] = A[i];
        }
        else
        {
            forMin[bucket] = min(A[i], forMin[bucket]);
            forMax[bucket] = max(A[i], forMax[bucket]);
        }
    }
    int maxDiff = 0;
    for(int i = 0; i < forMin.size(); i++)
    {
        if(forMin[i] >= 0)
        {
            maxDiff = max(maxDiff, forMin[i] - forMax[ind]);
            ind = i;
        }
    }
    return maxDiff;
}
```

## 8. Sum Of Pairwise Hamming Distance
```c++
/*
Formula is for each binary place sum up 2 * set bits * non set bits
It is pretty obvious because we need to find
A=[2, 4, 6]

We return,
f(2, 2) + f(2, 4) + f(2, 6) +
f(4, 2) + f(4, 4) + f(4, 6) +
f(6, 2) + f(6, 4) + f(6, 6) =

so every set bit times unset 2 times because it resembles a symmetric square matrix
*/
int Solution::hammingDistance(const vector<int> &A)
{
    long long int ans=0;
    long long int count;
    n = A.size();
    for (int i = 0; i < 31; ++i)
    {
        count = 0;
        for (int j = 0; j < n; ++j)
            if (A[j] & (1<<i))
                count++;
        ans = (ans + count*(n-count)*2) % 1000000007;
    }
    return ans;
}
```

## 10. Flip
/*
Break the problem into a fammilliar problem. If we conver '0' to 1 and '1' to -1 (we are basically flipping the entire string and then choose a substring from it) Using kaden's algorithm we can find maximum subarray. maxR is the index which ends up as max it is rightmost values of range. we go to the left till we get sum specified on it again we choose smallest number because L & R must be smallest.
We used -1 instead of 0 because we are basically having one place loss with it so we must have some negative value for it otherwise it will give wrong answer.
*/
```c++
vector<int> Solution::flip(string A)
{
    vector<int> arr;
    for (char s : A) arr.push_back(s == '0' ? 1 : -1);
    vector<int> kaden(arr.size());
    kaden[0] = arr[0];
    int maxFlip = arr[0];
    int maxFlipR = 0;
    for (int i = 1; i < arr.size(); ++i)
    {
        kaden[i] = max(arr[i], arr[i] + kaden[i-1]);
        if (kaden[i] > maxFlip)
        {
            maxFlip = kaden[i];
            maxFlipR = i;
        }
    }

    vector<int> sol;
    if (maxFlip <= 0) return sol;
    int maxFlipAnsL = INT_MAX;
    int curVal = 0;
    for (int i = maxFlipR; i >= 0; --i)
    {
        curVal += arr[i];
        if (curVal == maxFlip) maxFlipAnsL = min(maxFlipAnsL, i);
    }
    sol.push_back(maxFlipAnsL+1);
    sol.push_back(maxFlipR+1);
    return sol;
}
```

## 11. Square Root Of Integer
```c++
/*
Some binary search solution have l <= r this one have just < It is a simple hack actually if we don't have inner stopping condition like binary search me if arr[mid] == key then return aesa nahi he and hume humesha minimize kar rahe he toh don't put <= because then it will lead to TLE because think like this ki if l and r are equal mid is also equal will that cause TLE? if it will cause then don't put <=

other thing is people use l + (r-l)/2 instead of (l+r)/2 because say l+r is a very big number exceeding integer range although l and r are integers their sum can exceed. So we write it this way this is slightly more efficient.

Other efficiency trick is instead of mid*mid < A i wrote A <= A/mid because again A*A might exceed integer limit
*/
int Solution::sqrt(int A)
{
    if (A == 0) return 0;
    if (A == 1 || A == 2 || A == 3) return 1;
    int l = 0, r = A, ans = -1;

    while (l < r)
    {
        int mid = l + (r-l)/2;
        if (mid <= A/mid) l = mid+1, ans = mid;
        else r = mid;
    }
    return ans;
}
```

## 12. Rotated Sorted Array Search
```c++
/*
It is pretty simple, middle se dekhe toh humeshaa yahi hoga rotated array me yaato left sorted milega ya right It's like shifting the graph with positive slope along x axis.
*/
int Solution::search(const vector<int> &A, int B)
{
    int l = 0, r = A.size()-1;
    while (l <= r)
    {
        int mid = l + (r-l)/2;
        if (A[mid] == B) return mid;
        if (A[l] <= A[mid])
        {
            if(A[l] <= B && A[mid] >= B) r = mid-1;
            else l = mid+1;
        }
        else if (A[mid] <= A[r])
        {
            if (A[mid] <= B && A[r] >= B) l = mid+1;
            else r = mid-1;
        }
    }
    return -1;
}
```

## 13. Matrix Median
```c++
/*
Binary search from min to max element of the matrix
upper bound works on sorted array only it tells how many elements are lesser then or equal to specified
Toh we check mid se kam kitne elements he humeshaa
[1, 3, 5]
[2, 6, 9]
[3, 6, 9]

l = 1   r = 9   mid = 5
cur = 3 + 1 + 1 = 5

l = 1   r = 5   mid = 3
cur = 2 + 1 + 1 = 1

l = 4   r = 5   mid = 4
cur = 2 + 1 + 1 = 4

l = 5, r = 5    = ans 5

(n*m+1)/2 is 5 which signifies upperbound must be 5 for median but if matrix is like [[1, 1, 3, 3, 3, 3]] our check for upperbound of 3 will not be (m*n+1)/2 although it is clearly the median. But it clear if cur is greater then count then our answer must be from l to mid and reverse in vice versa.
*/
int Solution::findMedian(vector<vector<int> > &A)
{
    int l = INT_MAX, r = INT_MIN;
    for (auto x : A)
        for (int i : x)
            l = min(l, i), r = max(r, i);
    while (l < r)
    {
        int mid = l + (r-l)/2;
        int places = 0;
        for (auto x : A) places += upper_bound(x.begin(), x.end(), mid) - x.begin();
        if (places < ((A.size()*A[0].size())+1)/2) l = mid+1;
        else r = mid;
    }
    return l;
}

/*
Suppose there's a very big array which cannot be stored as one but only as 100 different arrays in sorted order each. find the median of it as one collective array. The answer is to treat it like a matrix and then simply do it.
*/
```
## 14. Median Of an Array
```c++
double solve(const vector<int> &A, const vector<int> &B, int l, int r, int count)
{
    while (l < r)
    {
        int mid = l + (r-l)/2;
        int c = (upper_bound(A.begin(), A.end(), mid) - A.begin()) +
            (upper_bound(B.begin(), B.end(), mid) - B.begin());
        if (c > count) r = mid;
        else l = mid+1;
    }
    return l;
}

double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B)
{
    int n = A.size(), m = B.size(), l, r;
    if (m == 0) l = A[0], r = A[n-1];
    else if (n == 0) l = B[0], r = B[m-1];
    else l = min(A[0], B[0]), r = max(A[n-1], B[m-1]);

    if ((n+m)&1) return solve(A, B, l, r, (n+m)/2);
    else return (solve(A, B, l, r, (n+m)/2 - 1) + solve(A, B, l, r, (n+m)/2))/(double)2;
}
```

## 15. Next Permutation
https://www.nayuki.io/page/next-lexicographical-permutation-algorithm<br>

......... [swap pivot with next value in range]<br>
1 <b>2</b> <u>3</u>     ->      1 3 2<br>
1 <b>3</b> <u>2</u>     ->      2 3 1   -> after sorting range: 2 1 3<br>
2 <b>1</b> <u>3</u>     ->      2 3 1<br>
2 <b>3</b> <u>1</u><br>
3 <b>1</b> <u>2</u><br>
3 <b>2</b> <u>1</u><br>
```c++
class Solution {
public:
    void nextPermutation(vector<int>& nums)
    {
        int i = nums.size()-1;
        while (i > 0 && nums[i-1] >= nums[i]) i--;
        if (i > 0)
        {
            int j = nums.size()-1;
            while (nums[j] <= nums[i-1]) j--;
            int temp = nums[i-1];
            nums[i-1] = nums[j];
            nums[j] = temp;
        }
        reverse(nums.begin() + i, nums.end());
    }
};
```

## 16. Painter's Partition Problem
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
#define ll long long
bool isPossible(int painters, vector<int> &boards, int val)
{
    ll count = 1, sum = val, i = 0;
    while (i < boards.size())
    {
        if (sum - boards[i] < 0) sum = val, count++;
        else sum -= boards[i++];
        if (count > painters) return false;
    }
    return true;
}

int Solution::paint(int A, int B, vector<int> &C)
{
    ll l = 0, r = accumulate(C.begin(), C.end(), 0);
    while (l < r)
    {
        int mid = l + (r-l)/2;
        if (isPossible(A, C, mid)) r = mid;
        else l = mid+1;
    }
    return (l * B) % 10000003;
}

// Book Allocation
bool isPossible(vector<int> &A, int B, int mid)
{
    int i = 0, sum = mid, count = 1;
    while (i < A.size())
    {
        if (sum - A[i] < 0) sum = mid, count++;
        else sum -= A[i++];
        if (count > B) return false;
    }
    return true;
}

int Solution::books(vector<int> &A, int B)
{
    if (A.size() < B) return -1;
    int l = 0, r = accumulate(A.begin(), A.end(), 0);
    while (l < r)
    {
        int mid = l + (r-l)/2;
        if (isPossible(A, B, mid)) r = mid;
        else l = mid+1;
    }
    return l;
}
```

## 17. Min XOR Value
```c++
/*
If we sort and then check xor of consecutive pair it will give min no need to check pair which are not consecutive.
*/
int Solution::findMinXor(vector<int> &A)
{
    sort(A.begin(), A.end());
    int ans = INT_MAX;
    for (int i = 0; i < A.size()-1; ++i)
        ans = min(ans, A[i]^A[i+1]);
    return ans;
}
```

## 18. Minimize the absolute difference
```c++
// minimize this | max(a,b,c) - min(a,b,c) |
int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C)
{
    int i = A.size()-1, j = B.size()-1, k = C.size()-1;
    int ans = INT_MAX;
    while (i >= 0 && j >= 0 && k >= 0)
    {
        int x = max(A[i], max(B[j], C[k]));
        int y = min(A[i], min(B[j], C[k]));
        ans = min(ans, abs(x - y));
        if (A[i] == x) --i;
        else if (B[i] == x) --j;
        else --k;
    }
    if (ans == INT_MAX) return -1;
    else return ans;
}

// Count the triplets such that A[i] + A[j] = A[k]
using namespace std;
#define ll long long

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
        sort(arr.begin(), arr.end(), greater<int>());
        int ans = 0;
        for (int i = 0; i < n-2; ++i)
        {
            int j = i+1, k = n-1;
            while (j < k)
            {
                int sum = arr[j] + arr[k];
                if (sum == arr[i]) ++ans;
                if (sum < arr[i]) --k;
                else ++j;
            }
        }
        if (ans == 0) cout << -1 << endl;
        else cout << ans << endl;
    }
    return 0;
}

// Same technique - 3 Sum
int Solution::threeSumClosest(vector<int> &A, int B)
{
    sort(A.begin(), A.end());
    int diff = INT_MAX, ansA, ansB, ansC;
    for (int i = 0; i < A.size()-2; ++i)
    {
        int j = i+1, k = A.size()-1;
        while (j < k)
        {
            int sum = A[i] + A[j] + A[k];
            if (abs(sum - B) < diff) ansA = A[i], ansB = A[j], ansC = A[k];
            if (sum > B) k--;
            else j++;
        }
    }
    return (diff == INT_MAX) ? -1 : ansA + ansB + ansC;
}

// Array 3 pointers - max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])) is minimized
int getMax(int a, int b, int c) { return max(a, max(b,c)); }
int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C)
{
    int i = 0, j = 0, k = 0;
    int sol = INT_MAX;
    int temp, temp1, temp2, temp3;
    while(i < A.size() && j < B.size() && k < C.size())
    {
        sol = min(sol, getMax(abs(A[i]-B[j]), abs(B[j]-C[k]), abs(C[k]-A[i])));
        temp1 = (i+1 < A.size()) ?
            getMax(abs(A[i+1]-B[j]), abs(B[j]-C[k]), abs(C[k]-A[i+1])) : INT_MAX;
        temp2 = (j+1 < B.size()) ?
            getMax(abs(A[i]-B[j+1]), abs(B[j+1]-C[k]), abs(C[k]-A[i])) : INT_MAX;
        temp3 = (k+1 < C.size()) ?
            getMax(abs(A[i]-B[j]), abs(B[j]-C[k+1]), abs(C[k+1]-A[i])) : INT_MAX;
        temp = min(temp1, min(temp2, temp3));

        if(temp == INT_MAX) return sol;
        else if(temp == temp1) i++;
        else if(temp == temp2) j++;
        else k++;
    }
    return sol;
}

// Diffk - A[i] - A[j] = k, i != j
int Solution::diffPossible(vector<int> &A, int B)
{
    int i = 0, j = 0;
    while (i < A.size() && j < A.size())
    {
        if (i == j) i++;
        int cur = A[i] - A[j];
        if (cur == B) return 1;
        else if (cur > B) j++;
        else i++;
    }
    return 0;
}

// Pythagorean Triplet - a^2 + b^2 = c^2 satisfy this
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; ++i) cin >> arr[i];
        for (int i = 0; i < n; ++i) arr[i] *= arr[i];
        sort(arr, arr + n, greater<int>());
        bool found = false;
        for (int i = 0; i < n-2; ++i)
        {
            int j = i+1, k = n-1;
            while (j < k)
            {
                int b = arr[j] + arr[k];
                if (arr[i] == b)
                {
                    cout << "Yes" << endl;
                    found = true;
                    break;
                }
                else if (arr[i] > b) --k;
                else ++j;
            }
            if (found) break;
        }
        if (!found) cout << "No" << endl;
    }
    return 0;
}

/*
Analysis:
for (int i = 0; i < n-2; ++i)
    int j = i+1, k = n-1;
    while (j < k)
This technique works for Count the triplets such that A[i] + A[j] = A[k], sum a b c closest to given number and Pythagorean Triplet - a^2 + b^2 = c^2 satisfy this.
In these three it worked because this technique is basically for summation problems. In pythagorean triplet however for optimization in array every number squared is stored instead to avoid recalculating square.
We do both side pointer technique only if there's an addition problem

minimize this | max(a,b,c) - min(a,b,c) | we start by pointing all i, j, k to n-1. If max value is contributed by say a then we do i-- if b then j-- else k--

max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])) is minimized, this questions starts by pointing i, j, k to 0. It doesn't matter we can point it to end also. what we are basically checking if we increment i, j and k which one gives best benefit then we increment that only.

Lastly DiffK we again do linear pointer thing
*/
```

## 19. Container With Most Water
```c++
int Solution::maxArea(vector<int> &A)
{
    int i = 0, j = A.size()-1;
    int cur, ans = INT_MIN;
    while (i < A.size())
    {
        if (A[i] < A[j]) cur = (j-i) * A[i++];
        else cur = (j-i) * A[j--];
        ans = max(cur, ans);
        if (i == j) break;
    }
    return ans;
}
```

## 20. Equilibruim Point
```c++
using namespace std;
#define ll long long

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
        for (int i = 1; i < n; ++i) arr[i] += arr[i-1];
        bool solved = false;
        for (int i = 0; i < n; ++i)
        {
            int left = (i > 0) ? arr[i-1] : 0;
            int right = (i < n-1) ? arr[n-1] - arr[i] : 0;
            if (left == right)
            {
                cout << i+1 << endl;
                solved = true;
                break;
            }
        }
        if (!solved) cout << -1 << endl;
    }
    return 0;
}

// Trapping Rain Water
// Make two arrays one storing all maxLeft and one maxRight. min for each index excpet first and last sum gives final ans
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; ++i) cin >> arr[i];

        int maxLeft[n], maxRight[n];
        int curMax = 0;
        for (int i = 0; i < n; ++i)
        {
            maxLeft[i] = curMax;
            curMax = max(curMax, arr[i]);
        }
        curMax = 0;
        for (int i = n-1; i >= 0; --i)
        {
            maxRight[i] = curMax;
            curMax = max(curMax, arr[i]);
        }
        maxLeft[0] = -1, maxRight[n-1] = -1;

        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (maxLeft[i] != -1 && maxRight[i] != -1)
            {
                int val = min(maxLeft[i], maxRight[i]) - arr[i];
                if (val > 0) ans += val;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

// O(1) space solution using 2 pointer
class Solution {
public:
    int trap(vector<int>& height)
    {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        int left_max = 0, right_max = 0;
        while (left < right)
        {
            if (height[left] < height[right])
            {
                if (height[left] >= left_max) left_max = height[left];
                else ans += (left_max - height[left]);
                ++left;
            }
            else
            {
                if (height[right] >= right_max) right_max = height[right];
                else ans += (right_max - height[right]);
                --right;
            }
        }
        return ans;
    }
};
```

## 21. Max Continuous 1s
```c++
vector<int> Solution::maxone(vector<int> &A, int B)
{
    int i = 0, j = 0, count = 0, bestTillNow = INT_MIN, ansI, ansJ;
    while (i < A.size())
    {
        if (count <= B)
        {
            if (A[i] == 0) ++count;
            ++i;
        }
        if (count > B)
        {
            if (A[j] == 0) --count;
            ++j;
        }
        if (i-j+1 > bestTillNow) bestTillNow = i-j+1, ansI = i, ansJ = j;
    }
    vector<int> res;
    if (bestTillNow == INT_MIN) return res;
    for (int i = ansJ; i < ansI; ++i) res.push_back(i);
    return res;
}

// Subarray with given sum
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, s;
        cin >> n >> s;
        int arr[n];
        for (int i = 0; i < n; ++i) cin >> arr[i];

        int curr_sum = arr[0], j = 0;
        bool found = false;
        for (int i = 1; i <= n; ++i)
        {
            while (curr_sum > s) curr_sum -= arr[j++];
            if (curr_sum == s)
            {
                cout << j+1 << " " << i << endl;
                found = true;
                break;
            }
            if (i < n) curr_sum += arr[i];
        }
        if (!found) cout << -1 << endl;
    }
    return 0;
}
```

## 22. Majority Element
```c++
int Solution::majorityElement(const vector<int> &A)
{
    int ans = 0, x = 0;
    for (int i : A)
    {
        if (x == 0) ans = i;
        if (ans == i) x++;
        else x--;
    }
    return ans;
}

// N/3 Repeat Number
int Solution::repeatedNumber(const vector<int> &A)
{
    int len = A.size();
    if (A.size() == 0) return -1;
    if (A.size() == 1) return A[0];

    int c1 = A[0];
    int c2 = A[1];
    int c1count = 0;
    int c2count = 0;

    for (int num : A)
    {
        if (c1 == num) c1count++;
        else if (c2 == num) c2count++;
        else if (c1count == 0)
        {
            c1 = num;
            c1count = 1;
        }
        else if (c2count == 0)
        {
            c2 = num;
            c2count = 1;
        }
        else
        {
            c1count--;
            c2count--;
        }
    }

    // Need to properly find count once again
    c1count = 0;
    c2count = 0;
    for (int num : A)
    {
        if (c1 == num) c1count++;
        else if (num == c2) c2count++;
    }

    if (c1count > len / 3) return c1;
    else if (c2count > len / 3) return c2;
    else return -1;
}
```

## 23. Kth Smallest Element
```c++
// Simple quick sort question
using namespace std;

int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int j = l-1;
    for (int i = l; i <= r-1; ++i)
        if (arr[i] <= pivot)
            swap(arr[++j], arr[i]);

    swap(arr[++j], arr[r]);
    return j;
}

int k_th_smallest(int arr[], int l, int r, int k)
{
    if (k > 0 && k <= r-l+1)
    {
        int pos = partition(arr, l, r);
        if (pos-l == k-1) return arr[pos];
        if (pos-l > k-1) return k_th_smallest(arr, l, pos-1, k);
        return k_th_smallest(arr, pos+1, r, k-pos+l-1);
    }
    return INT_MAX;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; ++i) cin >> arr[i];
        cin >> k;
        cout << k_th_smallest(arr, 0, n-1, k) << endl;
    }
    return 0;
}
```

## 26. Fraction to Recurring Decimal
https://leetcode.com/problems/fraction-to-recurring-decimal/
```c++
class Solution {
public:
    string fractionToDecimal(int n, int d) {
        if (n == 0) return "0";
        if (d == 0) return "";

        long long num = n, den = d;

        string res = "";
        if ((num < 0) ^ (den < 0)) res += "-";
        num = abs(num), den = abs(den);
        long long quo = num/den;
        res += to_string(quo);
        long long rem = (num % den) * 10;
        if (rem == 0) return res;
        res += ".";

        // Calculate decimal values
        unordered_map<long long, int> rec;
        while (rem != 0)
        {
            if (rec.find(rem) != rec.end())
            {
                int beg = rec[rem];
                string part1 = res.substr(0, beg);
                string part2 = res.substr(beg, res.size());
                res = part1 + "(" + part2 + ")";
                return res;
            }
            rec[rem] = res.size();
            long long temp = rem/den;
            rem = (rem % den) * 10;
            res += to_string(temp);
        }
        return res;
    }
};
```

# Level 2
## 1. Hotel Review
```c++
struct node
{
    char data;
    unordered_map<char, node*> next;
    bool isTerminal;
    node(char d)
    {
        data = d;
        isTerminal = false;
    }
};
class Trie
{
    node* root;
public:
    Trie()
    {
        root = new node('\0');
    }
    void addWord(string word)
    {
        node* temp = root;
        for (int i = 0; word[i] != '\0'; ++i)
        {
            char ch = word[i];
            if (temp -> next.count(ch) == 0)
            {
                node* child = new node(ch);
                temp -> next[ch] = child;
                temp = child;
            }
            else
                temp = temp -> next[ch];
        }
        temp->isTerminal = true;
    }
    bool search(string word)
    {
        node* temp = root;
        for (int i = 0; word[i] != '\0'; ++i)
        {
            char ch = word[i];
            if (temp -> next.count(ch))
                temp = temp -> next[ch];
            else
                return false;
        }
        return temp -> isTerminal;
    }
};
vector<string> tokenize(string x)
{
    vector<string> res;
    string temp = "";
    for (int i = 0; i < x.size(); ++i)
    {
        if (x[i] == '_')
        {
            res.push_back(temp);
            temp = "";
        }
        else temp += x[i];
    }
    res.push_back(temp);
    return res;
}
vector<int> Solution::solve(string A, vector<string> &B)
{
    Trie trie;
    vector<string> goodWords = tokenize(A);
    for (string x : goodWords) trie.addWord(x);
    vector< pair<int, int> > ans;
    for (string x : B)
    {
        vector<string> words = tokenize(x);
        int score = 0;
        for (string y : words) score += (trie.search(y)) ? 1 : 0;
        ans.push_back(make_pair(score, ans.size()));
    }
    sort(ans.begin(), ans.end(), [](const pair<int, int> &a, const pair<int, int> &b)
    {
        if (a.first == b.first) return a.second < b.second;
        else return a.first > b.first;
    });
    vector<int> out;
    for (auto x : ans) out.push_back(x.second);
    return out;
}
```

## 3. Longest Distinct Characters in string
```c++
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int visited[256];
        fill(visited, visited+256, -1);
        visited[s[0]] = 0;
        int maxLen = 1, curLen = 1;
        for (int i = 1; i < s.size(); ++i)
        {
            int prevIndex = visited[s[i]];
            if (prevIndex == -1 || i-curLen > prevIndex) ++curLen;
            else maxLen = max(maxLen, curLen), curLen = i-prevIndex;
            visited[s[i]] = i;
        }
        maxLen = max(maxLen, curLen);
        cout << maxLen << endl;
    }
    return 0;
}
```

## 4. Reverse a linked list
```c++
Node *cur = head, *next = NULL, *prev = NULL;
while (cur != NULL)
{
    next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
}

// K reverse linked list
// If reverse is clear, K reverse isn't difficult just one thing to mug up. Always create first k element reverse then rest in while loop because the first will give new head
ListNode* Solution::reverseList(ListNode* A, int B)
{
    if (!head || !(head->next)) return head;
    ListNode *cur = head, *next = NULL, *prev = NULL, *tempHead = head;
    for (int i = 0; i < 2; ++i)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    ListNode *newHead = prev;
    prev = NULL;
    while (cur)
    {
        ListNode *temp = cur;
        for (int i = 0; i < 2; ++i)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            if (!cur) break;
        }
        tempHead->next = prev;
        tempHead = temp;
    }
    if (tempHead) tempHead->next = NULL;
    return newHead;
}

https://leetcode.com/problems/reverse-nodes-in-k-group
class Solution
{
public:
    ListNode* reverse(ListNode* first, ListNode* last)
    {
        ListNode* prev = last;
        while (first != last)
        {
            auto tmp = first->next;
            first->next = prev;
            prev = first;
            first = tmp;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        auto node = head;
        for (int i = 0; i < k; ++i)
        {
            if (!node) return head; //nothing to do list too sort
            node = node->next;
        }
        auto new_head = reverse(head, node);
        head->next = reverseKGroup(node, k);
        return new_head;
    }
};


// Reverse within a range
ListNode* Solution::reverseBetween(ListNode* A, int B, int C)
{
    ListNode *head = A, *cur = A, *next = NULL, *prev = NULL;
    int i = 0;
    if (B == 1)
    {
        ListNode *temp = A;
        while (cur != NULL && i < C)
        {
            ++i;
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        temp->next = next;
        head = prev;
    }
    else
    {
        while (cur != NULL && i < B-2) ++i, cur = cur->next;
        ListNode *temp = cur;
        cur = cur->next;
        prev = NULL;
        while (cur != NULL && i < C-1)
        {
            ++i;
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        temp->next->next = next;
        temp->next = prev;
    }
    return head;
}

// Palindrome List
// Go to the middle of linked list and reverse from middle to the end and break it into two half. Now just iterate both halves for equality.
// To go to middle, slow and fast pointer can be used when fast will become NULL (reach end) it will cover 2x distance while x distance will be covered by slow pointer which will be then the middle.
int Solution::lPalin(ListNode* A)
{
    int n = 0;
    ListNode *temp = A;
    while (temp != NULL)
    {
        n++;
        temp = temp->next;
    }
    ListNode *mid = A, *prev = NULL;
    int half = (n&1) ? n/2 + 1 : n/2;
    for (int i = 0; i < half; ++i)
    {
        prev = mid;
        mid = mid->next;
    }
    prev->next = NULL;
    prev = NULL;
    ListNode *cur = mid, *next = NULL;
    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    ListNode *t1 = A;
    ListNode *t2
}
```

## 5. Detect Loop
```c++
int detectloop(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return 1;
    }
    return 0;
}

ListNode* Solution::detectCycle(ListNode* A)
{
    if (A == NULL || A->next == NULL) return A;
    ListNode *slow = A, *fast = A;
    while (slow && fast)
    {
        slow = slow->next;
        if (!fast || !slow || !fast->next) return NULL;
        fast = fast->next->next;
        if (!fast || !slow || !fast->next) return NULL;
        if (slow == fast) break;
    }
    if (!fast || !slow || !fast->next) return NULL;
    fast = A;
    while (slow !=fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return fast;
}

void removeTheLoop(Node *A)
{
    Node *slow = A, *fast = A;
    while (slow && fast)
    {
        slow = slow->next;
        if (!fast || !slow || !fast->next) return;
        fast = fast->next->next;
        if (!fast || !slow || !fast->next) return;
        if (slow == fast) break;
    }
    if (!fast || !slow || !fast->next) return;
    fast = A;
    Node* prev = NULL;
    while (slow !=fast)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next;
    }
    prev->next = NULL;
}
```

## 6. Intersection Point in y shaped linked list
Pretty simple, just find which one is the bigger list. x = abs(n-m) where n and m are size of both list. If we go x steps next from longer list it will be intersection point.

## 7. Merge Sort Linked List
```c++
ListNode* merge(ListNode* A, ListNode* B)
{
    ListNode *head = NULL, *cur = head, *itA = A, *itB = B;
    while (itA && itB)
    {
        if (itA->val < itB->val)
        {
            if (!head) head = itA, cur = itA;
            else cur->next = itA, cur = cur->next;
            itA = itA->next;
        }
        else
        {
            if (!head) head = itB, cur = itB;
            else cur->next = itB, cur = cur->next;
            itB = itB->next;
        }
    }
    while (itA)
    {
        if (!head) head = itA, cur = itA;
        else cur->next = itA, cur = cur->next;
        itA = itA->next;
    }
    while (itB)
    {
        if (!head) head = itB, cur = itB;
            else cur->next = itB, cur = cur->next;
            itB = itB->next;
    }
    return head;
}

ListNode* Solution::sortList(ListNode* A)
{
    if (!A || !A->next) return A;
    ListNode *head = A, *start = A, *end = A->next;
    while (start && end && end->next)
    {
        start = start->next;
        end = end->next->next;
    }
    end = start->next;
    start->next = NULL;
    return merge(sortList(head), sortList(end));
}

// Insertion Sort
ListNode* Solution::insertionSortList(ListNode* head)
{
    ListNode *sorted = NULL;
    ListNode *list = head;
    while (list)
    {
        ListNode *curr = list;
        list = list->next;
        if (sorted == NULL || sorted->val > curr->val)
        {
            curr->next = sorted;
            sorted = curr;
        }
        else
        {
            ListNode *tmp = sorted;
            while (tmp)
            {
                ListNode *c = tmp;
                tmp = tmp->next;
                if (c->next == NULL || c->next->val > curr->val)
                {
                    c->next = curr;
                    curr->next = tmp;
                    break;
                }
            }
        }
    }
    return sorted;
}
```

## 8. Reorder List
```c++
ListNode* Solution::reorderList(ListNode* A)
{
    if (!A || !A->next) return A;
    ListNode *leftHalf = A, *rightHalf;
    ListNode *slow = A, *fast = A, *prev = NULL;
    // Split list from middle to left and right halves
    while (slow && fast && fast->next)
        prev = slow, slow = slow->next, fast = fast->next->next;
    rightHalf = slow;
    if (prev) prev->next = NULL;

    // Reverse right half
    ListNode *cur = rightHalf, *next = NULL;
    prev = NULL;
    while (cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    rightHalf = prev;

    //Simply merge and end this shit
    ListNode *ans = NULL;
    while (leftHalf && rightHalf)
    {
        if (!ans) ans = leftHalf, cur = ans;
        else cur->next = leftHalf, cur = cur->next;
        leftHalf = leftHalf->next;
        cur->next = rightHalf;
        cur = cur->next;
        rightHalf = rightHalf->next;
    }
    return ans;
}

// Second ques Linked List Random Pointer
Node *copyList(Node *start)
{
    Node* curr = start, *temp;
    while (curr)
    {
        temp = curr->next;
        curr->next = new Node(curr->data);
        curr->next->next = temp;
        curr = temp;
    }

    curr = start;
    while (curr)
    {
        if(curr->arb) curr->next->arb = curr->arb;
        curr = curr->next ? curr->next->next : curr->next;
    }

    Node* original = start, *copy = start->next;
    temp = copy;
    while (original && copy)
    {
        if (original->next) original->next = original->next->next;
        if (copy->next) copy->next = copy->next->next;
        original = original->next;
        copy = copy->next;
    }
    return temp;
}
```

## 9. Nearest Smallest Element
```c++
// Coming up with brute force O(N^2) solution (taking inner loop from i-1 to 0) then optimizing it here by using smallestIndex helps a lot
vector<int> Solution::prevSmaller(vector<int> &A)
{
    int n = A.size(), smallestIndex = 0, smallestVal = A[0];
    vector<int> res(n);
    res[0] = -1;
    for (int i = 1; i < n; ++i)
    {
        int minSmallest = -1;
        for (int j = i-1; j >= smallestIndex; --j)
        {
            if (A[j] < A[i])
            {
                minSmallest = A[j];
                break;
            }
        }
        res[i] = minSmallest;
        if (A[i] < smallestVal) smallestVal = A[i], smallestIndex = i;
    }
    return res;
}

// OR Other approach
vector<int> Solution::prevSmaller(vector<int> &A)
{
    stack<int> st;
    vector<int> ans(A.size());
    for (int i = 0; i < A.size(); ++i)
    {
        while (!st.empty() && st.top() >= A[i]) st.pop();
        ans[i] = st.empty() ? -1 : st.top();
        st.push(A[i]);
    }
    return ans;
}

// Next Larger Number
#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
	int t, n;
	cin >> t;
	while(t--)
	{
	    cin >> n;
	    ll arr[n], ans[n];
	    for (int i = 0; i < n; ++i) cin >> arr[i];
	    stack<ll> st;
	    for (int i = n-1; i >= 0; --i)
	    {
	        while (!st.empty() && arr[i] >= st.top()) st.pop();
	        ans[i] = st.empty() ? -1 : st.top();
	        st.push(arr[i]);
	    }

	    for (ll i : ans) cout << i << " ";
	    cout << endl;
	}
	return 0;
}
```

## 10. Largest Area In Histogram
https://www.youtube.com/watch?v=MhQPpAoZbMc
```c++
/*
Basically har st.top() jiske liye while loop chal raha he we are finding an area which can be maximum area rectangle for it.
*/
int Solution::largestRectangleArea(vector<int> &A)
{
    stack<int> st;
    int ans = 0;
    A.push_back(-1);
    for (int i = 0; i < A.size(); ++i)
    {
        while (!st.empty() && A[i] <= A[st.top()])
        {
            int height = A[st.top()];
            st.pop();
            // i is rightmost smaller element, st.top() is prev top leftmost
            int width = i - (st.empty() ? -1 : st.top()) - 1;
            ans = max(ans, height * width);
        }
        st.push(i);
    }
    return ans;
}
```

## 11. Sliding Window Maximum
```c++
/*
Deque will have a capacity of k and at an instance it's front will store maximum and back will store minimum
*/
vector<int> Solution::slidingMaximum(const vector<int> &A, int k)
{
    deque <int> q;
    vector <int> res;
    int n = A.size();
    for(int i = 0; i < n; ++i)
    {
        while (!q.empty() && q.front() < i-k+1) q.pop_front();
        while (!q.empty() && A[i] > A[q.back()]) q.pop_back();
        q.push_back(i);
        if(i >= k-1) res.push_back(A[q.front()]);
    }
    return res;
}
```

## 12. Min Stack
```c++
stack<int> st, minSt;
MinStack::MinStack()
{
    while (!st.empty()) st.pop();
    while (!minSt.empty()) minSt.pop();
}
void MinStack::push(int x)
{
    st.push(x);
    if (minSt.size() == 0) minSt.push(x);
    else
    {
        if (x <= minSt.top()) minSt.push(x);
        else minSt.push(minSt.top());
    }
}
void MinStack::pop()
{
    if (!st.empty())
    {
        st.pop();
        minSt.pop();
    }
}
int MinStack::top()
{
    return (st.empty() ? -1 : st.top();
}
int MinStack::getMin()
{
    return (minSt.empty() ? -1 : minSt.top();
}
```

## 14. LRU Cache
```c++
/*
LRU = Least Recently Used Cache
say a cache of size 4 we insert 0 then 1 then 2 then 3 i.e our cache becomes 3 2 1 0
if we insert another item size becomes 5 we can only have a capacity of 4 so while insertion least recently used gets deleted i.e. 4 3 2 1 [0 gets deleted]
If we access say 2 then it becomes 2 4 3 1 Now if we insert 5, 1 gets removed i.e. 5 2 4 3

this get & set function should be in O(1)
*/
struct Node { int val; Node *next, *prev; };
unordered_map<int, int> rec;
int maxI, current;
Node *first, *lru;

LRUCache::LRUCache(int capacity)
{
    rec.erase(rec.begin(), rec.end());
    maxI = capacity;
    current = 0;
    first = NULL;
    lru = NULL;
}
int LRUCache::get(int key)
{
    if (current > 0)
    {
        auto it = rec.find(key);
        if (it != rec.end())
        {
            int val = it->second;
            Node *cur = first;
            while (cur && cur->val != key) cur = cur->next;
            Node *next = cur->next;
            Node *prev = cur->prev;
            if (prev)
            {
                prev->next = next;
                if (next) next->prev = prev;
                else lru = prev;
                cur->next = first;
                cur->prev = NULL;
                first->prev = cur;
                first = cur;
            }
            return val;
        }
    }
    return -1;
}
void LRUCache::set(int key, int value)
{
    if (rec.find(key) != rec.end())
    {
        rec[key] = value;
        Node *cur = first;
        while (cur && cur->val != key) cur = cur->next;
        Node *next = cur->next;
        Node *prev = cur->prev;
        if (prev)
        {
            prev->next = next;
            if (next) next->prev = prev;
            else lru = prev;
            cur->next = first;
            cur->prev = NULL;
            first->prev = cur;
            first = cur;
        }
    }
    else
    {
        Node *temp = new Node{key, NULL, NULL};
        rec[key] = value;
        if (current != maxI)
        {
            current++;
            if (current == 1) lru = temp, first = temp;
            else temp->next = first, first->prev = temp, first = temp;
        }
        else
        {
            int lru_key = lru->val;
            rec.erase(rec.find(lru_key));
            if (lru->prev)
            {
                Node *toDelete = lru;
                lru = lru->prev;
                lru->next = NULL;
                temp->next = first;
                first->prev = temp;
                first = temp;
                delete(toDelete);
            }
            else
            {
                lru = temp;
                first = lru;
            }
        }
    }
}
```

## 15. Circular Tour
```c++
// Find out how many petrol additionally is required to finish tour from last index
// Then fill rest of dp simply
int tour(petrolPump p[], int n)
{
    int dp[n];
    int lastStationReqd = 0;
    int lastStationVal = p[n-1].petrol;
    if (p[n-1].distance > lastStationVal)
    {
        int incr = p[n-1].distance - lastStationVal;
        lastStationReqd += incr;
        lastStationVal += incr;
    }
    lastStationVal -= p[n-1].distance;
    for (int i = 0; i < n-1; ++i)
    {
        lastStationVal += p[i].petrol;
        if (p[i].distance > lastStationVal)
        {
            int incr = p[i].distance - lastStationVal;
            lastStationReqd += incr;
            lastStationVal += incr;
        }
        lastStationVal -= p[i].distance;
    }
    dp[n-1] = lastStationReqd;

    for (int i = n-2; i >= 0; --i)
    {
        dp[i] = dp[i+1] - (p[i].petrol - p[i].distance);
        if (dp[i] < 0) dp[i] = 0;
    }

    for (int i = 0; i < n; ++i)
        if (dp[i] == 0) return i;
    return -1;
}
// Above solution basically works but there's even simpler approach
// This is greedy approach
int Solution::canCompleteCircuit(const vector<int> &gas, const vector<int> &cost)
{
    int fuel = 0, start_i = 0, sum = 0;
    for (int i = 0; i < gas.size(); ++i)
    {
        sum += (gas[i] - cost[i]);
        fuel += (gas[i] - cost[i]);
        if (fuel < 0) fuel = 0, start_i = i+1;
    }
    return (sum >= 0) ? start_i : -1;
}
```

## 16. First Non Repeating character in a stream
```c++
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        char arr[n];
        for (int i = 0; i < n; ++i) cin >> arr[i];
        unordered_map<char, int> freq;

        queue<char> q;
        for (int i = 0; i < n; ++i)
        {
            freq[arr[i]]++;
            q.push(arr[i]);
            while (!q.empty())
            {
                if (freq[q.front()] > 1) q.pop();
                else
                {
                    cout << q.front() << " ";
                    break;
                }
            }
            if (q.empty()) cout << -1 << " ";
        }
        cout << endl;
    }
    return 0;
}
```

## 17. Median Of Stream Of Running Integers
```c++
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n < 1) continue;

        priority_queue<double> maxHeap; //maintains lower half
        priority_queue<double, vector<double>, greater<double> > minHeap;   //maintains upper half
        double med;
        cin >> med;
        cout << floor(med) << endl;
        maxHeap.push(med);
        for (int i = 1; i < n; ++i)
        {
            double x;
            cin >> x;
            //case1 (left side heap has more elements)
            if (maxHeap.size() > minHeap.size())
            {
                if (x < med) minHeap.push(maxHeap.top()), maxHeap.pop(), maxHeap.push(x);
                else minHeap.push(x);
            }
            //case2 (both heaps are balanced)
            else if (maxHeap.size() == minHeap.size())
            {
                if (x < med) maxHeap.push(x);
                else minHeap.push(x);
            }
            //case3 (right side heap has more elements)
            else
            {
                if (x > med) maxHeap.push(minHeap.top()), minHeap.pop(), minHeap.push(x);
                else maxHeap.push(x);
            }
            med = (maxHeap.top() + minHeap.top()) / 2.0;
            cout << floor(med) << endl;
        }
    }
    return 0;
}
```

## 19. N Max Pair Combinations
```c++
vector<int> Solution::solve(vector<int> &A, vector<int> &B)
{
    priority_queue<pair<int, pair<int, int> > > hp;
    set<pair<int, int> > S;
    int n = A.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    hp.push(make_pair(A[n-1]+B[n-1], make_pair(n-1, n-1)));
    S.insert(make_pair(n-1, n-1));

    vector<int> ans;
    int k=n;
    while(k--)
    {
        pair<int, pair<int, int> > top = hp.top();
        hp.pop();
        ans.push_back(top.first);
        int L = top.second.first;
        int R = top.second.second;

        if( R>0 && L>=0  && S.find(make_pair(L,R-1)) == S.end() )
        {
            hp.push(make_pair(A[L]+B[R-1], make_pair(L,R-1)));
            S.insert(make_pair(L,R-1));
        }
        if( R>=0  && L>0 && S.find(make_pair(L-1, R))==S.end())
        {
            hp.push(make_pair(A[L-1]+B[R], make_pair(L-1,R)));
            S.insert(make_pair(L-1, R));
        }
    }
    return ans;
}
```

## 20. Merge K sorted linked list
```c++
/*
Interviebit question is bullshit gives correct answer even for high time, in reality this question has tighter constraints and is asked by Google

Way #1: Brute Force - Array me yaa map me saare element daalo sort kardo then linked list banado Time: O(KNlogKN) Space: O(KN)

Way #2: Create K pointers, initially pointing to head of each linked list choose smallest increment it's pointer. Keep doing it. Time: O(KN) Space: O(K). Interview bit variation passes this. One optimization in this is use priority queue to avoid comparisons then time will become: O(NlogK)

Way #3: merge two sorted linked list at a time till (k-1) times. Time: O(KN) Space: O(1)
*/

//Way 1: Using maps insertion will be logN so total time will be: log1 + log2 + .... + log(KN) for insertion this is integration from 1 to n logx = nlogn + n i.e. KNlogKN then inside for loop of map theres KN iteration so overall O(KNLogKN) but in case of duplicacy it stores count so it can perform better in that case
ListNode* Solution::mergeKLists(vector<ListNode*> &A)
{
    map<int, int> myMap;
    for (auto x : A)
        while(x)
            myMap[x->val]++, x = x->next;

    ListNode *head = NULL, *cur = NULL;
    for (auto it = myMap.begin(); it != myMap.end(); ++it)
    {
        while (it->second != 0)
        {
            ListNode *list = new ListNode(it->first);
            if (!head) head = list, cur = list;
            else cur->next = list, cur = cur->next;
            it->second--;
        }
    }
    return head;
}

//Way 2: Just O(K) space, O(KNK) time
ListNode* mergeKLists(vector<ListNode*>& A)
{
    vector<ListNode*> ptrs;
    for (auto x : A) ptrs.push_back(x);
    ListNode *head = NULL, *cur = NULL;
    while (true)
    {
        int minVal = INT_MAX, minIndex = 0;
        for (int i = 0; i < ptrs.size(); ++i)
            if (ptrs[i] && ptrs[i]->val < minVal)
                minVal = ptrs[i]->val, minIndex = i;

        if (minVal == INT_MAX) break;
        ListNode *temp = new ListNode(minVal);
        if (!head) head = temp, cur = head;
        else cur->next = temp, cur = cur->next;
        ptrs[minIndex] = ptrs[minIndex]->next;
    }
    return head;
}

// O(KNlogK) time, O(K) space
typedef pair<int, ListNode*> pilist;
ListNode* Solution::mergeKLists(vector<ListNode*> &A)
{
    priority_queue<pilist, vector<pilist>, greater<pilist> > ptrs;
    for (auto x : A)
        ptrs.push({x->val, x});
    ListNode *head = NULL, *cur = NULL;
    while (!ptrs.empty())
    {
        pilist front = ptrs.top();
        ptrs.pop();
        ListNode *temp = new ListNode(front.first);
        if (!head) head = temp, cur = head;
        else cur->next = temp, cur = cur->next;
        if ((front.second)->next)
        {
            front.second = (front.second)->next;
            front.first = (front.second)->val;
            ptrs.push(front);
        }
    }
    return head;
}
// Conclusion: this one is better but if there are many duplicacy present 1st one is better
```

## 21. Rearrange Characters:
Very simple heap question. Count each letters of given string. Like in geeksforgeeks there are g-2, e-4, k-2, s-2, f-1, o-1, r-1. Put it on a max heap. pick e then again pick max one since top element is same as previous we will pick second top.

## 22. Longest Consecutive Sequence:
```c++
int longestConsecutive(vector<int>& nums)
{
    unordered_set<int> rec;
    for (int i : nums) rec.insert(i);
    int ans = 0;
    for (int i : nums)
    {
        // if current element is begining
        if (rec.find(i-1) == rec.end())
        {
            int j = i+1;
            while (rec.find(j) != rec.end())
                j++;
            ans = max(ans, j - i);
        }
    }
    return ans;
}
```

# Level 3
## 6. Equal:
```c++
struct fourpair{ int a, b, c, d; };
bool mycmp(fourpair S1, fourpair S2)
{
    return (S1.a < S2.a || (S1.a == S2.a && S1.b < S2.b) || (S1.a == S2.a && S1.b == S2.b && S1.c < S2.c) ||
        (S1.a == S2.a && S1.b == S2.b && S1.c == S2.c && S1.d < S2.d));
}
vector<int> Solution::equal(vector<int> &A)
{
    unordered_map<int, vector< pair<int, int> > > rec;
    vector<fourpair> temp;
    vector<int> ans;
    for (int i = 0; i < A.size(); ++i)
    {
        for (int j = i+1; j < A.size(); ++j)
        {
            int sum = A[i] + A[j];
            if (rec.find(sum) == rec.end()) rec[sum].push_back(make_pair(i, j));
            else
            {
                for (int x = 0; x < rec[sum].size(); ++x)
                {
                    int A1 = rec[sum][x].first, B1 = rec[sum][x].second, C1 = i, D1 = j;
                    if (A1 < B1 && C1 < D1 && A1 < C1 && B1 != D1 && B1 != C1)
                    {
                        temp.push_back({A1, B1, C1, D1});
                        rec[sum].erase(rec[sum].begin(), rec[sum].end());
                    }
                }
            }
        }
    }

    if (temp.size() > 0)
    {
        fourpair cur = *min_element(temp.begin(), temp.end(), mycmp);
        ans.push_back(cur.a);
        ans.push_back(cur.b);
        ans.push_back(cur.c);
        ans.push_back(cur.d);
    }
    return ans;
}
```

## 7. Window String
```c++
string Solution::minWindow(string S, string T)
{
    unordered_map<char, int> rec;
    for (char ch : T) rec[ch]++;

    int i = 0, j = 0, len = T.size(), minSize = INT_MAX, lastI;
    while(j < S.size())
    {
        if (rec[S[j++]]-- > 0) len--;
        while (len == 0)
        {
            if (j-i < minSize) minSize = j-i, lastI = i;
            if (rec[S[i++]]++ == 0) len++;
        }
    }
    if (minSize == INT_MAX) return "";
    return S.substr(lastI, minSize);
}
```

## 8. Points On The Straight Line
```c++
int Solution::maxPoints(vector<int> &A, vector<int> &B)
{
    if (A.size() == 0 || B.size() == 0) return 0;
    unordered_map<double, int> rec;
    int sol = 1;
    for (int i = 0; i < A.size(); ++i)
    {
        int duplicate = 1;
        int vertical = 0;
        for (int j = i+1; j < A.size(); ++j)
        {
            if (A[i] == A[j])
            {
                if (B[i] == B[j]) duplicate++;
                else vertical++;
            }
            else
            {
                double slope = 0.0;
                double x = A[j] - A[i];
                double y = B[j] - B[i];
                if (x != 0) slope = y/x;
                rec[slope]++;
            }
        }

        for (auto tmp : rec) sol = max(sol, tmp.second + duplicate);
        sol = max(vertical + duplicate, sol);
        rec.clear();
    }
    return sol;
}
```

## 9. Substring Concatenation
```c++
vector<int> Solution::findSubstring(string A, const vector<string> &B)
{
    vector<int> sol;
    int wsize = B[0].size();
    int lsize = B.size();
    if (A.size() == 0 || B.size() == 0) return sol;
    unordered_map<string, int> rec;
    for (int i = 0; i < B.size(); ++i) rec[B[i]]++;

    int i = 0;
    while ((i + (wsize*lsize) - 1) < A.size())
    {
        unordered_map<string, int> tmp;
        int j = 0;
        while (j < A.size())
        {
            string t = A.substr(i + (j*wsize), wsize);
            if (rec.find(t) == rec.end()) break;
            else
            {
                tmp[t]++;
                if (tmp[t] > rec[t]) break;
                j++;
            }
            if (j == lsize) sol.push_back(i);
        }
        ++i;
    }
    return sol;
}
```

## 10. Activity Selection
```c++
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        pair<int, int> arr[n];
        for (int i = 0; i < n; ++i) cin >> arr[i].second;
        for (int i = 0; i < n; ++i) cin >> arr[i].first;
        sort(arr, arr+n);
        int count = 1, timer = arr[0].first;
        for (int i = 1; i < n; ++i)
            if (arr[i].second >= timer)
                count++, timer = arr[i].first;
        cout << count << endl;
    }
    return 0;
}
```

## 11. Largest Number Possible
```c++
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, s;
        cin >> n >> s;
        if (s == 0 || s > 9*n)
        {
            cout << -1 << endl;
            continue;
        }
        string num = "";
        while (n--)
        {
            num += to_string(min(9, s));
            s -= min(9, s);
        }
        if (s < 0) cout << -1 << endl;
        else cout << num << endl;
    }
    return 0;
}
```

## 12. Minimize The Heights
```c++
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> k >> n;
        int arr[n];
        for (int i = 0; i < n; ++i) cin >> arr[i];
        int maxV = *max_element(arr, arr+n), minV = *min_element(arr, arr+n);
        int x = (maxV + minV)/2, ans = maxV - minV;
        for (int i = 0; i < n; ++i) arr[i] += (arr[i] < x) ? k : (-k);
        maxV = *max_element(arr, arr+n), minV = *min_element(arr, arr+n);
        ans = min(ans, maxV - minV);
        cout << ans << endl;
    }
    return 0;
}
```

## 13. Bulbs
```c++
int Solution::bulbs(vector<int> &A)
{
    int ans = 0;
    bool isFlipped = false;
    for (int i : A)
    {
        if ((i && isFlipped) || (!i && !isFlipped))
        {
            isFlipped = !isFlipped;
            ans++;
        }
    }
    return ans;
}
```

## 14. Distributing Candies
```c++
int Solution::candy(vector<int> &ratings)
{
    vector<int> val(ratings.size(), 1);
    for (int i = 0; i < ratings.size(); ++i)
    {
        if (i == 0)
        {
            if (ratings[i] > ratings[i+1])
                val[i] = val[i+1] + 1;
        }
        else if (i == ratings.size()-1)
        {
            if (ratings[i] > ratings[i-1])
                val[i] = val[i-1] + 1;
        }
        else
        {
            if (ratings[i] > ratings[i+1] && ratings[i] > ratings[i-1])
                val[i] = max(val[i+1], val[i-1]) + 1;
            else if (ratings[i] > ratings[i+1])
                val[i] = val[i+1] + 1;
            else if (ratings[i] > ratings[i-1])
                val[i] = val[i-1] + 1;
        }
    }
    for (int i = ratings.size()-1; i >= 0; --i)
    {
        if (i == 0)
        {
            if (ratings[i] > ratings[i+1])
                val[i] = val[i+1] + 1;
        }
        else if (i == ratings.size()-1)
        {
            if (ratings[i] > ratings[i-1])
                val[i] = val[i-1] + 1;
        }
        else
        {
            if (ratings[i] > ratings[i+1] && ratings[i] > ratings[i-1])
                val[i] = max(val[i+1], val[i-1]) + 1;
            else if (ratings[i] > ratings[i+1])
                val[i] = val[i+1] + 1;
            else if (ratings[i] > ratings[i-1])
                val[i] = val[i-1] + 1;
        }
    }
    int ans = 0;
    for (int i : val) ans += i;
    return ans;
}
```

## 15. Tushar Birthday Bombs
```c++
vector<int> Solution::solve(int A, vector<int> &B)
{
    auto minV = min_element(B.begin(), B.end());
    int maxKicks = A/(*minV);
    vector<int> ans;
    for (int i = 0; i < maxKicks; ++i) ans.push_back(minV - B.begin());
    int rem = A - ((*minV) * maxKicks);
    int i = 0, j;
    while (i < maxKicks)
    {
        int pos = ans[i];
        int index = -1;
        for (j = 0; j < B.size(); ++j)
        {
            if (rem - (B[j] - B[pos]) >= 0)
            {
                index = j;
                rem -= B[j] - B[pos];
                break;
            }
        }
        ans[i] = j;
        ++i;
    }
    return ans;
}
// DP+BFS solution also exists
```

## 16. Identical Binary Tree
```c++
bool check (TreeNode* A, TreeNode* B)
{
    if (A == NULL && B == NULL) return true;
    else if ((A == NULL && B != NULL) || (A != NULL && B == NULL)) return false;
    else if (A->val == B->val) return check(A->left, B->left) & check(A->right, B->right);
    //Change above line to
    //else if (A->val == B->val) return check(A->left, B->right) & check(A->right, B->left);
    //for symmetric binary tree
    return false;
}
int Solution::isSameTree(TreeNode* A, TreeNode* B)
{
    return check(A, B);
}
```

## 17. Inorder Traversal Of Cartesian Tree
```c++
TreeNode* makeTree(vector<int> &A, int start, int end)
{
    if (start > end) return NULL;
    int maxIndex = max_element(A.begin()+start, A.begin()+end+1) - A.begin();
    TreeNode* root = new TreeNode(A[maxIndex]);
    root->left = makeTree(A, start, maxIndex-1);
    root->right = makeTree(A, maxIndex+1, end);
    return root;
}
TreeNode* Solution::buildTree(vector<int> &A)
{
    return makeTree(A, 0, A.size()-1);
}

// Construct using Inorder and Preorder
unordered_map<int, int> indexes;
TreeNode* makeTree(vector<int> &A, vector<int> &B, int start, int end)
{
    if (start > end) return NULL;
    int indexA = INT_MAX, indexB;
    for (int i = start; i <= end; ++i)
        if (indexes[B[i]] < indexA)
            indexA = indexes[B[i]], indexB = i;

    TreeNode* parent = new TreeNode(A[indexA]);
    parent->left = makeTree(A, B, start, indexB-1);
    parent->right = makeTree(A, B, indexB+1, end);
    return parent;
}

TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B)
{
    for (int i = 0; i < A.size(); ++i) indexes[A[i]] = i;
    return makeTree(A, B, 0, A.size()-1);
}
```

## 18. Invert The Binary Tree
```
void invert(TreeNode* root)
{
    if (root == NULL) return;
    invert(root->left);
    invert(root->right);

    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
}

TreeNode* Solution::invertTree(TreeNode* root)
{
    invert(root);
    return root;
}
```

## 19. 2 Sum Binary Tree
```c++
int Solution::t2Sum(TreeNode* A, int B)
{
    if (!A) return 0;
    stack<TreeNode *> st1, st2;
    TreeNode *cur1 = A, *cur2 = A;
    while(cur1) st1.push(cur1), cur1 = cur1->left;
    while(cur2) st2.push(cur2), cur2 = cur2->right;
    cur1 = st1.top(), cur2 = st2.top();
    while(cur1 && cur2 && cur1->val < cur2->val)
    {
        if (cur1->val + cur2->val == B) return 1;
        if (cur1->val + cur2->val < B)
        {
            st1.pop();
            cur1 = cur1->right;
            while (cur1) st1.push(cur1), cur1 = cur1->left;
            cur1 = st1.top();
        }
        else
        {
            st2.pop();
            cur2 = cur2->left;
            while (cur2) st2.push(cur2), cur2 = cur2->right;
            cur2 = st2.top();
        }
    }
    return 0;
}
```

## 21. Least Common Ancestor (LCA)
```c++
bool find(TreeNode* root, int val)
{
    if (!root) return false;
    if (root->val == val) return true;
    if ((root->left && find(root->left, val)) || (root->right && find(root->right, val))) return true;
    return false;
}
TreeNode* LCA(TreeNode* root, int val1, int val2)
{
    if (!root || root->val == val1 || root->val == val2) return root;
    auto L = LCA(root->left, val1, val2);
    auto R = LCA(root->right, val1, val2);
    if (L && R) return root;
    return L ? L : R;
}
int Solution::lca(TreeNode* A, int B, int C)
{
    if (!find(A, B) || !find(A, C)) return -1;
    auto ancesstor = LCA(A, B, C);
    if (ancesstor) return ancesstor->val;
    return -1;
}
```

## 22. Flatten BST
```c++
TreeNode* Solution::flatten(TreeNode* A)
{
    TreeNode *root = A;
    while (A)
    {
        if (A->left)
        {
            TreeNode *temp = A->left;
            while (temp->right) temp = temp->right;
            temp->right = A->right;
            A->right = A->left;
            A->left = NULL;
        }
        A = A->right;
    }
    return root;
}
```

## 23. BST Iterator
```c++
stack<TreeNode*> path;
void pushAll(TreeNode *root)
{
    while (root)
    {
        path.push(root);
        root = root->left;
    }
}
BSTIterator::BSTIterator(TreeNode *root) { pushAll(root); }
bool BSTIterator::hasNext() { return !path.empty(); }
int BSTIterator::next()
{
    TreeNode *temp = path.top();
    path.pop();
    pushAll(temp->right);
    return temp->val;
}
```

## 24. Recover Binary Tree
```c++
// Inorder traversal me previous value zyada nahi honi chahiye he toh matlab gadbad hui
vector<int> Solution::recoverTree(TreeNode* A)
{
    stack<TreeNode*> st;
    TreeNode *cur = A, *prev = NULL, *first = NULL, *last = NULL;
    while(!st.empty() || cur)
    {
        while (cur) st.push(cur), cur = cur->left;
        cur = st.top();
        st.pop();
        if (prev)
        {
            if (prev->val > cur->val)
            {
                //This part is tricky we could have just written first = prev, last = cur and then break BUT
                //agar non immediate child se swap hua he tab uss case me ek toh humesha fixed rahega dusra badalta rahega
                if (!first) last = prev;
                first = cur;
            }
        }
        prev = cur;
        cur = cur->right;
    }
    vector<int> sol;
    if (first && last)
    {
        sol.push_back(first->val);
        sol.push_back(last->val);
    }
    sort(sol.begin(), sol.end());
    return sol;
}
```

## 25. Populate Next Right Pointers Tree
```c++
void Solution::connect(TreeLinkNode* A)
{
    queue< pair<int, TreeLinkNode*> > q;
    q.push({0, A});
    while (!q.empty())
    {
        auto temp = q.front();
        int level = temp.first;
        q.pop();
        while (!q.empty() && q.front().first == level)
        {
            if (temp.second->left) q.push({level+1, temp.second->left});
            if (temp.second->right) q.push({level+1, temp.second->right});
            temp.second->next = q.front().second;
            temp = q.front();
            q.pop();
        }
        temp.second->next = NULL;
        if (temp.second->left) q.push({level+1, temp.second->left});
        if (temp.second->right) q.push({level+1, temp.second->right});
    }
}
```

## 27. Maximum Width Of Binary Tree
```c++
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root)
    {
        if (!root) return 0;
        queue< pair<TreeNode*, int> > q;
        q.push({root, 1});
        int ans = 0;
        while (!q.empty())
        {
            int n = q.size();
            int a = q.front().second, b = a;
            for (int i = 0; i < n; ++i)
            {
                auto node = q.front();
                b = node.second;
                q.pop();
                if (b == INT_MAX) continue;
                if (node.first->left) q.push({node.first->left, node.second * 2});
                if (node.first->right) q.push({node.first->right, node.second * 2 + 1});
            }
            ans = max(ans, b - a + 1);
        }
        return ans;
    }
};
```

## 28. Intresting Numbers
```c++
#include <bits/stdc++.h>
using namespace std;

int dp_ds[1011][1011], dp_lst_no[1011][1011], dp_lst_mo[1011][1011];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(dp_ds, -1, sizeof(dp_ds));
        memset(dp_lst_mo, 0, sizeof(dp_lst_mo));

        int n;
        cin >> n;
        queue< pair<int, int> > q;
        for (int i = 1; i <= 9; ++i)
        {
            q.push({i%n, i});
            dp_ds[i%n][i] = i;
            dp_lst_no[i%n][i] = i;
        }

        while (!q.empty())
        {
            auto temp = q.front();
            q.pop();
            int rem = temp.first, ds = temp.second;
            if (rem == 0 && ds == n) break;
            for (int i = 0; i <= 9; ++i)
            {
                temp.first = ((rem * 10) + i) % n;
                temp.second = ds + i;
                // Check if we have already covered this state or if it's impossible then skip
                if (dp_ds[temp.first][temp.second] != -1 || temp.second > n) continue;
                q.push(temp);
                dp_ds[temp.first][temp.second] = ds + i;
                dp_lst_no[temp.first][temp.second] = i;
                dp_lst_mo[temp.first][temp.second] = rem;
            }
        }

        stack<int> ans;
        int m = 0, s = n;
        while (m != 0 || s != 0)
        {
            ans.push(dp_lst_no[m][s]);
            int m1 = dp_lst_mo[m][s], s1 = dp_ds[m][s] - dp_lst_no[m][s];
            m = m1, s = s1;
        }

        while (!ans.empty())
        {
            cout << ans.top();
            ans.pop();
        }
        cout << endl;
    }
    return 0;
}

//Interviewbit problem is like the easiest version of above question. try solving it yourself if you can understand above
char dp[50506][16];
int dp_last[50506][16];
string Solution::multiple(int n)
{
    queue< pair<int, int> > q;
    q.push({1%n, 0});
    dp[1%n][0] = '1';
    int y;
    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();
        if (temp.first == 0)
        {
            y = temp.second;
            break;
        }
        q.push({(temp.first * 10) % n, temp.second + 1});
        dp[(temp.first * 10) % n][temp.second + 1] = '0';
        dp_last[(temp.first * 10) % n][temp.second + 1] = temp.first;
        q.push({(temp.first * 10 + 1) % n, temp.second + 1});
        dp[(temp.first * 10 + 1) % n][temp.second + 1] = '1';
        dp_last[(temp.first * 10 + 1) % n][temp.second + 1] = temp.first;
    }

    int x = 0;
    string ans= "";
    while (x != 1%n || y != 0)
    {
        ans = dp[x][y] + ans;
        int x0 = dp_last[x][y];
        x = x0, y = y-1;
    }
    ans = dp[x][y] + ans;
    return ans;
}
//Or a quick hack XD
string Solution::multiple(int n)
{
    queue< pair<int, string> > q;
    q.push({1%n, "1"});
    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();
        if (temp.first == 0) return temp.second;
        q.push({(temp.first * 10) % n, temp.second + "0"});
        q.push({(temp.first * 10 + 1) % n, temp.second + "1"});
    }
    return "";
}
```

## 30. Cycle detection:
[Directed Graph] Apply DFS and maintain a visited set. If during traversing DFS we encounter an already visited node then it means the graph has cycle. [Undirected Graph] We also need to maintain a complete visited set and for cycle the node should be in visited but not in completely visited set.<br><br>
Another way is with the help of Disjoint Sets. We make disjoint sets for all nodes and then for each connections we make union. If we found that before making union both edges already belong in same disjoint set means there is a cycle.
```c++
// O(N)
int main()
{
    int n, e;
    cin >> n >> e;
    DisjointSet<int> ds;
    for (int i = 0; i < n; ++i)
        ds.makeSet(i);

    for (int i = 0; i < e; ++i)
    {
        int a, b;
        cin >> a >> b;
        if (ds.find(a) == ds.find(b))
        {
            cout << "CYCLE FOUND"
            return;
        }
        ds.makeUnion(a, b);
    }

    cout << "CYCLE NOT FOUND";
    return;
}
```
Using BFS to detect cycle in directed graph we use Kahn's Algorithm for Topological Sorting
```c++
bool Graph::isCyclic()
{
    vector<int> inDegree(V, 0);
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < adj[i].size(); ++j)
            ++inDegree[adj[i][j]];
    }

    queue<int> q;
    for (int i = 0; i < V; ++i)
    {
        if (inDegree[i] == 0)
            q.push(i);
    }

    vector<int> topOrder;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        topOrder.push_back(front);
        for (int i = 0; i < adj[front].size(); ++i)
        {
            --inDegree[adj[front][i]];
            if (inDegree[adj[front][i]] == 0)
                q.push(adj[front][i]);
        }
    }

    return (topOrder.size() != V);
}
/*
O(V+E)
Above code is basically for topological sort using Kahn's algorithm
- Compute indegree for all nodes and add those with 0 to the queue
- Visit queue until its empty. Remove visited element from queue add it to topological Order
- Visit neighbous and reduce their indegree since that path is now chosen and if indegree reduces down to 0 we add it to queu
- This makes sense because we are only going to neighbour if it's last path we haven't discovered
- If in the end topological sort cannot visit every node means there was a cycle in the path
*/

# Level 4
## 1. Combination Sum
https://leetcode.com/problems/combination-sum/
```c++
class Solution {
public:
    void solve(vector< vector<int> > &res, vector<int> &temp, vector<int> &candidates, int target, int cur = 0)
    {
        if (target == 0)
        {
            res.push_back(temp);
            return;
        }
        if (cur == candidates.size() || target - candidates[cur] < 0) return;
        temp.push_back(candidates[cur]);
        solve(res, temp, candidates, target - candidates[cur], cur);
        temp.pop_back();
        solve(res, temp, candidates, target, cur+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector< vector<int> > res;
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        solve(res, temp, candidates, target);
        return res;
    }
};
```

## 2. Combination Sum II
https://leetcode.com/problems/combination-sum-ii/
```c++
class Solution {
public:
    void solve(vector< vector<int> > &res, vector<int> &temp, vector<int> &candidates, int target, int cur = 0)
    {
        if (target == 0)
        {
            res.push_back(temp);
            return;
        }
        if (cur == candidates.size() || target - candidates[cur] < 0) return;
        temp.push_back(candidates[cur]);
        solve(res, temp, candidates, target - candidates[cur], cur+1);
        temp.pop_back();
        solve(res, temp, candidates, target, cur+1);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        vector< vector<int> > res;
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        solve(res, temp, candidates, target);
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};
```

## 3. Letter Phone
https://www.interviewbit.com/problems/letter-phone/
```c++
string keypad[] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void backtrack(string A, vector<string> &res, string temp = "", int cur = 0)
{
    if (cur == A.size())
    {
        res.push_back(temp);
        return;
    }
    int index = A[cur] - '0';
    for (char ch : keypad[index])
        backtrack(A, res, temp + ch, cur + 1);
}

vector<string> Solution::letterCombinations(string A)
{
    vector<string> res;
    backtrack(A, res);
    return res;
}
```

```c++
//BFS Approach
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string keypad[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        queue< tuple<char, int, string> > q;
        vector<string> res;
        if (digits.size() == 0) return res;
        for (char ch : keypad[digits[0] - '0'])
            q.push({ch, 0, string(1, ch)});
        while (!q.empty())
        {
            int cur_level = get<1>(q.front());
            while (get<1>(q.front()) == cur_level)
            {
                auto cur = q.front();
                q.pop();
                if (cur_level+1 == digits.size())
                {
                    res.push_back(get<2>(cur));
                    continue;
                }
                for (char ch : keypad[digits[cur_level+1] - '0'])
                    q.push({ch, cur_level+1, get<2>(cur) + ch});
            }
        }
        return res;
    }
};
```

## 4. Palindrome Partitioning
https://www.interviewbit.com/problems/palindrome-partitioning/
```c++
bool isPalindrome(const string s, int i, int j)
{
    while (i<j)
    {
        if (s[i] == s[j])
        {
            ++i;
            --j;
        }
        else
            return false;
    }
    return true;
}

void backtracking(const string& s, int i, vector<string>& row, vector<vector<string> >& res)
{
    if (i == s.length())
    {
        res.emplace_back(row);
        return;
    }

    for (auto x = i; x < s.length(); ++x)
    {
        if (isPalindrome(s, i, x))
        {
            row.emplace_back(s.substr(i, x-i+1));
            backtracking(s, x+1, row, res);
            row.pop_back();
        }
    }
}

vector<vector<string> > Solution::partition(string A)
{
    vector<string> row;
    vector<vector<string> > res;
    backtracking(A, 0, row, res);
    return res;
}
```

## 5. Generate all parantheses II
https://www.interviewbit.com/problems/generate-all-parentheses-ii/<br>
https://leetcode.com/problems/generate-parentheses/
```c++
void solve(vector<string> &res, int A, string val = "", int cur = 0)
{
    if (val.size() == 2*A)
    {
        if (cur == 0) res.push_back(val);
        return;
    }
    if (cur > 0) solve(res, A, val + ")", cur-1);
    solve(res, A, val + "(", cur+1);
}

vector<string> Solution::generateParenthesis(int A)
{
    vector<string> res;
    solve(res, A);
    reverse(res.begin(), res.end());
    return res;
}

// Other solution
class Solution {
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        if (n == 0) res.push_back("");
        else
        {
            for (int i = 0; i < n; ++i)
            {
                for (string left : generateParenthesis(i))
                {
                    for (string right : generateParenthesis(n-i-1))
                        res.push_back("(" + left + ")" + right);
                }
            }
        }
        return res;
    }
};
```

## 6. Kth permutation sequence (FUCKING LOVED THIS QUESTION)
https://www.interviewbit.com/problems/kth-permutation-sequence/
```c++
int fact(int n)
{
    if (n > 12) return INT_MAX;
    int f = 1;
    for (auto i = 2; i<=n; ++i) f *= i;
    return f;
}

string Solution::getPermutation(int n, int k)
{
    vector<int> nums;
    for (int i = 1; i <= n; ++i) nums.push_back(i);
    string res = "";
    k--;
    while (n--)
    {
        int f = fact(nums.size()-1);
        int pos = k / f;
        k %= f;
        res += to_string(nums[pos]);
        nums.erase(nums.begin() + pos);
    }
    return res;
}
// Memoize factorial to save time in recalculating
```

## 7. Word Break
https://leetcode.com/problems/word-break/
```c++
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> rec;
        for (string s : wordDict) rec.insert(s);
        string cur = "";
        for (int i = 0; i < s.size(); ++i)
        {
            cur += s[i];
            if (i == s.size()-1)
                return (rec.find(cur) != rec.end());
            if (rec.find(cur) != rec.end())
                cur = "";
        }
        return false;
    }
};
// Above greedy solution won't work for this testcase "aaaaaaa" ["aaaa","aaa"], DP solution is needed
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> rec;
        for (string s : wordDict) rec.insert(s);
        bool dp[s.size()+1];
        memset(dp, false, sizeof(dp));
        dp[0] = true;
        for (int i = 0; i < s.size(); ++i)
        {
            for (int j = i; j >= 0; --j)
            {
                if (dp[j] && rec.find(s.substr(j, i-j+1)) != rec.end())
                {
                    dp[i+1] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
// The HARD variation is amazing
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> rec;
        for (string s : wordDict) rec.insert(s);
        vector<int> dp[s.size()];
        for (int i = 0; i < s.size(); ++i)
        {
            for (int j = i; j >= 0; --j)
            {
                string cur = s.substr(j, i - j + 1);
                if ((j == 0 || (j > 0 && dp[j-1].size() > 0)) &&
                    rec.find(cur) != rec.end())
                    dp[i].push_back(i-j+1);
            }
        }

        // Backtrack dp using BFS
        vector<string> res;
        queue< pair<int, string> > q;
        q.push({s.size()-1, ""});
        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();
            if (cur.first < 0)
            {
                res.push_back(cur.second);
                continue;
            }
            for (auto i : dp[cur.first])
            {
                int start = cur.first - i;
                if (cur.second == "") q.push({start, s.substr(start + 1, i)});
                else q.push({start, s.substr(start + 1, i) + " " + cur.second});
            }
        }
        return res;
    }
};
```

## 8. Divisor Game
https://leetcode.com/problems/divisor-game/
```c++
class Solution {
public:
    bool divisorGame(int N) {
        vector<int> dp(N + 1, false);
        for(int i = 2; i <= N; ++i)
        {
            for(int j = 1; j < i; ++j)
            {
                if(i % j == 0 && !dp[i - j])
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[N];
    }
};
```

## 10. Best Time to Buy and Sell Stock
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        int maxArr[n], minArr[n], ans = INT_MIN;
        minArr[0] = prices[0], maxArr[n-1] = prices[n-1];
        for (int i = 1; i < n; ++i) minArr[i] = min(minArr[i-1], prices[i]);
        for (int i = n-2; i >= 0; --i) maxArr[i] = max(maxArr[i+1], prices[i]);
        for (int i = 0; i < n; ++i) ans = max(ans, maxArr[i] - minArr[i]);
        return ans;
    }
};
// O(1) space solution: Basically draw a graph out of the given tescase you will deduce problem to finding valley followed by a peak then just subtract them.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX, maxProfit = 0;
        for (int i = 0; i < prices.size(); ++i)
        {
            minPrice = min(prices[i], minPrice);
            maxProfit = max(prices[i] - minPrice, maxProfit);
        }
        return maxProfit;
    }
};
// Variation II: This time also draw a graph. We must buy on valley and sell on immediate peak
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int i = 0, valley = prices[0], peak = prices[0], maxProfit = 0;
        while (i < prices.size()-1)
        {
            while (i < prices.size()-1 && prices[i] >= prices[i+1]) i++;
            valley = prices[i];
            while (i < prices.size()-1 && prices[i] <= prices[i+1]) i++;
            peak = prices[i];
            maxProfit += peak - valley;
        }
        return maxProfit;
    }
};
// Variation III
class Solution {
public:
    int maxProfit(vector<int>& A) {
        if (A.size() == 0) return 0;
        int dp[A.size()], maxV = INT_MIN, minV = INT_MAX;
        for (int i = A.size()-1; i >= 0; --i)
        {
            maxV = max(maxV, A[i]);
            dp[i] = (i == A.size()-1) ? 0 : max(dp[i+1], maxV - A[i]);
        }
        for (int i = 0; i < A.size(); ++i)
        {
            minV = min(minV, A[i]);
            dp[i] = (i == 0) ? 0 : max(dp[i-1], dp[i] + (A[i] - minV));
        }
        return dp[A.size()-1];
    }
};
```

## 11. House Robber
```c++
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int dp[nums.size()];
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i)
            dp[i] = (i == 1) ? max(nums[i], dp[i-1]) : max(nums[i] + dp[i-2], dp[i-1]);
        return dp[nums.size()-1];
    }
};
// Variation II: Now houses are in circle
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        int dp1[nums.size()], dp2[nums.size()];
        dp1[0] = nums[0], dp2[nums.size()-1] = nums[nums.size()-1];
        for (int i = 1; i < nums.size(); ++i)
            dp1[i] = (i == 1) ? max(nums[i], dp1[i-1]) : max(nums[i] + dp1[i-2], dp1[i-1]);
        for (int i = nums.size()-2; i >= 0; --i)
            dp2[i] = (i == nums.size()-2) ? max(nums[i], dp2[i+1]) : max(nums[i] + dp2[i+2], dp2[i+1]);
        return max(dp2[1], dp1[nums.size()-2]);
    }
};
```

## 12. Martian
```c++
#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<ll, ll> p[501][501];
ll dp[504][504];

ll martian(ll i, ll j)
{
    if (dp[i][j] != -1) return dp[i][j];
    if ((i == 0 && j != 0) || (i != 0 && j == 0)) return 0;
    if (i == 1 && j == 1) return max(p[i-1][j-1].first, p[i-1][j-1].second);
    ll sum1 = 0, sum2 = 0;
    for (ll x = j-1; x >= 0; --x) sum1 += p[i-1][x].first;
    for (ll x = i-1; x >= 0; --x) sum2 += p[x][j-1].second;
    return dp[i][j] = max(martian(i-1, j) + sum1, martian(i, j-1) + sum2);
}

int main()
{
    ll n, m;
    cin >> n >> m;
    while (n != 0 && m != 0)
    {
        memset(dp, -1, sizeof(dp));
        for (ll i = 0; i < n; ++i)
        {
            for (ll j = 0; j < m; ++j)
            {
                ll x;
                cin >> x;
                p[i][j].first = x;
            }
        }
        for (ll i = 0; i < n; ++i)
        {
            for (ll j = 0; j < m; ++j)
            {
                ll x;
                cin >> x;
                p[i][j].second = x;
            }
        }
        cout << martian(n, m) << endl;
        cin >> n >> m;
    }
    return 0;
}
```

## 13. Longest Valid Paranthesis
```c++
// O(N) with O(N) space
class Solution {
public:
    int longestValidParentheses(string s)
    {
        int n = s.size();
        vector<int> dp(n, 0);
        int ans = 0;
        for (int i = 1; i < n; ++i)
        {
            if (s[i] == ')')
            {
                // ()
                if (s[i-1] == '(')
                    dp[i] = (i >= 2) ? dp[i-2] + 2 : 2;
                // ()(())   =   020026
                else if (i-dp[i-1]-1 >= 0 && s[i-dp[i-1]-1] == '(')
                    dp[i] = (i-dp[i-1] >= 2) ? dp[i-1] + dp[i-dp[i-1]-2] + 2 : dp[i-1] + 2;
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
```