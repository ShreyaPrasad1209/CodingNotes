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
        else ans = mid-1;
    }
    return ans;
}
```

## 12. Rotated Sorted Array Search
```c++
/*
It is pretty simple, middle se dekhe toh humeshaa yahi hoga rotated array me yaato left sorted milega ya right It's like shifting the graph with positive slope along x axis.
*/
int search2(const vector<int> &arr, int l, int r, int x)
{
    if (l > r) return -1;
    int mid = l + (r-l)/2;
    if (arr[mid] == x) return mid;
    if (arr[l] <= arr[mid])
    {
        if (arr[l] <= x && arr[mid] >= x) return search2(arr, l, mid-1, x);
        else return search2(arr, mid+1, r, x);
    }
    else if (arr[mid] <= arr[r])
    {
        if (arr[mid] <= x && arr[r] >= x) return search2(arr, mid+1, r, x);
        else return search2(arr, l, mid-1, x);
    }
}
int Solution::search(const vector<int> &A, int B)
{
    int i = search2(A, 0, A.size()-1, B);
    return i;
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
    int n = A.size(), m = A[0].size();
    int count = (n*m + 1)/2;
    int l = INT_MAX, r = INT_MIN;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            l = min(l, A[i][j]), r = max(r, A[i][j]);

    while (l < r)
    {
        int mid = l + (r-l)/2;
        int cur = 0;
        for (int i = 0; i < n; ++i)
            cur += upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();

        if (cur < count) l = mid+1;
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
    double ans = -1;
    while (l <= r)
    {
        int mid = l + (r-l)/2;
        int c = (upper_bound(A.begin(), A.end(), mid) - A.begin()) +
            (upper_bound(B.begin(), B.end(), mid) - B.begin());
        if (c > count) ans = mid, r = mid-1;
        else l = mid+1;
    }
    return ans;
}

double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B)
{
    int n = A.size(), m = B.size(), l, r;
    if (m == 0) l = A[0], r = A[n-1];
    else if (n == 0) l = B[0], r = B[m-1];
    else l = min(A[0], B[0]), r = max(A[n-1], B[m-1]);

    if ((n+m) % 2 == 1) return solve(A, B, l, r, (n+m)/2);
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
void Solution::nextPermutation(vector<int> &A)
{
    int i;
    for (i = A.size()-1; i > 0; --i)
    {
        if (A[i] > A[i-1])
            break;
    }
    if (i == 0)
    {
        sort(A.begin(), A.end());
        return;
    }
    int small = i-1;
    int big = i;
    int temp = big;
    for (i = A.size()-1; i > big; --i)
    {
        if (A[i] > A[small] && A[i] < A[temp])
            temp = i;
    }
    int t = A[temp];
    A[temp] = A[small];
    A[small] = t;
    small++;
    sort(A.begin()+small, A.end());
}
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
bool isPossible(const vector<int> &arr, ll n, ll val)
{
    ll i = 0, sum = val, count = 1;
    while (i < arr.size())
    {
        if (sum - arr[i] < 0) sum = val, count++;
        else sum -= arr[i++];
        if (count > n) return false;
    }
    return true;
}
int Solution::paint(int A, int B, vector<int> &C)
{
    ll l = 0, r = accumulate(C.begin(), C.end(), 0);
    ll ans = INT_MAX;
    while (l <= r)
    {
        ll mid = l + (r-l)/2;
        if (isPossible(C, A, mid)) r = mid - 1, ans = min(ans, mid);
        else l = mid + 1;
    }
    return (l * B) % 10000003;
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
    while(i < A.size() || j < B.size() || k < C.size())
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
    ListNode *cur = A, *next = NULL, *prev = NULL, *tempHead = A;
    for (int i = 0; i < B; ++i)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    ListNode *head = prev;
    prev = NULL;
    while (cur)
    {
        ListNode *temp = cur;
        for (int i = 0; i < B; ++i)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        tempHead->next = prev;
        tempHead = temp;
    }
    if (tempHead) tempHead->next = NULL;
    return head;
}

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
        while (!st.empty() && A[i] < A[st.top()])
        {
            int height = A[st.top()];
            st.pop();
            // i is rightmost smaller element, st.top() is prev top leftmost
            int width = i - (st.empty() ? -1 : st.top()) - 1;
            ans = max(ans, height * width);
        }
        st.push(i);
    }
    A.pop_back();
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