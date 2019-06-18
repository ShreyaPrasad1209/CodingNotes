# Arrays

## 1. Merge Overlap
https://www.interviewbit.com/problems/merge-overlapping-intervals/
```c++
bool mycomp(Interval a, Interval b)
{
    return a.start < b.start;
}
vector<Interval> Solution::merge(vector<Interval> &A)
{
    sort(A.begin(), A.end(), mycomp);
    vector<Interval> res;
    int n = A.size();
    res.push_back(A[0]);
    for(int i = 1; i < n; ++i)
    {
        if(A[i].start <= res[res.size()-1].end)
            res[res.size()-1].end = max(res[res.size()-1].end, A[i].end);
        else
            res.push_back(A[i]);
    }
    return res;
}

```

## 2. Hotel-Booking Possible
https://www.interviewbit.com/problems/hotel-bookings-possible/
```c++
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
https://www.interviewbit.com/problems/largest-number/
```c++
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

## 4. Max Distance
https://www.interviewbit.com/problems/max-distance/
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
This question is easy if it was not in O(1) space. Idea now is to map the presence of an integer to same array by making it negative instead of mapping to other array<br>
https://www.interviewbit.com/problems/first-missing-integer/
```c++
int firstMissingPositive(vector<int> &A)
{
    // [3, 4, -1, 1] Input
    // STL magic baby XD without iterators hume swap karna padta uff
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
    for (int i = 0; i < A.size(); ++i)
    {
        if (A[i] > 0)
            return i+1;
    }
    return A.size() + 1;
}
```

## 6. Find duplicate in Array
https://www.interviewbit.com/problems/find-duplicate-in-array/<br>
https://medium.com/solvingalgo/solving-algorithmic-problems-find-a-duplicate-in-an-array-3d9edad5ad41<br>
https://www.youtube.com/watch?v=LUm2ABqAs1w
```c++
int repeatedNumber(const vector<int> &A)
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
https://www.interviewbit.com/problems/maximum-consecutive-gap/<br>
https://leetcode.com/articles/maximum-gap/
```c++
/*
Say given [1, 10, 5] find min and max i.e. 1 and 10
then find gap which is (max-min)/(n-1) i.e. 4
Now iterate each element finding bucket i.e. (A[i] - min) / gap this will tell the odering
i.e. for 1 it's 0, 10 it's 2 and 5 it's 1
Now finally we are storing them on arrays, seperate because sorting can have multiple elements mapped to onw
So we store minimum of those multiple in one array and max in other
To find difference we need to take forMax of second minus forMin of first
*/
int maximumGap(const vector<int> &A)
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
        cout << A[i] << ": " << bucket << endl;
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

## 8. Flip
https://www.interviewbit.com/problems/flip/
```c++
/*
Logic is to change ever 0 to 1 and 1 to -1 and make that integer array
Now if we apply kaden's algorithm we will get the maximum possible subarray we need to flip that subarry
*/
vector<int> Solution::flip(string A)
{
    vector<int> arr;
    int init_counter = 0;
    for (int i = 0; i < A.size(); ++i)
    {
        if (A[i] == '0') arr.push_back(1);
        else arr.push_back(-1);
    }

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
    for (int maxFlipL = maxFlipR; maxFlipL >= 0; --maxFlipL)
    {
        curVal += arr[maxFlipL];
        if (curVal == maxFlip)
            maxFlipAnsL = min(maxFlipAnsL, maxFlipL);
    }

    sol.push_back(maxFlipAnsL+1);
    sol.push_back(maxFlipR+1);
    return sol;
}
```

## 9. Set Matrix Zero
https://www.interviewbit.com/problems/set-matrix-zeros/
```c++
void Solution::setZeroes(vector<vector<int> > &matrix)
{
    set<int> rows, columns;
    for (int i = 0; i < matrix.size(); ++i)
        for (int j = 0; j < matrix[0].size(); ++j)
            if (!matrix[i][j]) rows.insert(i), columns.insert(j);

    for (int x : rows)
        for (int i = 0; i < matrix[x].size(); ++i)
            matrix[x][i] = 0;

    for (int x : columns)
        for (int i = 0; i < matrix.size(); ++i)
            matrix[i][x] = 0;
}

```

## 10. Next Permutation
https://www.interviewbit.com/problems/next-permutation/<br>
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

## 11. N/3 Repeat Number
Moore's Voting Algorithm [Greedy approach] (This algo seems really weird how does that even works lol remember PMI proof exists for this thing) : https://gregable.com/2013/10/majority-vote-algorithm-find-majority.html
```python
# Say in array we need to find majority element (one with count >= n/2)
answer = 0
count = 0
for value in input:
    if count == 0:
        answer = value
    if answer == value:
        count += 1
    else:
        count -= 1
```
```c++
// Our question is just an extension of voting algorithm instead of one candidate we have to keep track of 2 candidates
// Basically we want candidate1 candidate2 and candidate3 is basically leftover while candidate1 & 2 can be our answer
int repeatedNumber(const vector<int> &A)
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

# Math

## 12. Prime Sum
https://www.interviewbit.com/problems/prime-sum/
```c++
vector<int> Solution::primesum(int n)
{
    vector<bool> isprime(n + 1);
    for (int i = 0; i <= n; i++) isprime[i] = 1;
    isprime[0] = 0;
    isprime[1] = 0;
    for (int i = 2; i*i <= n; i++)
    {
        if (isprime[i])
        {
            for (int j = i*2; j <= n; j+=i)
                isprime[j] = 0;
        }
    }

    vector<int> ans(2);
    for (int i = 2; i <= n/2; i++)
    {
        if (isprime[i] && isprime[n - i])
        {
            ans[0] = i;
            ans[1] = n - i;
            return ans;
        }
    }
}
```

## 13. Sum of pairwise Hamming Distance
https://www.interviewbit.com/problems/sum-of-pairwise-hamming-distance/
```c++
int Solution::hammingDistance(const vector<int> &A)
{
    long long int ans = 0;
    long long int count;
    for (int i = 0; i < 31; ++i)
    {
        count = 0;
        for (int j = 0; j < A.size(); ++j)
        {
            if (A[j] & (1<<i))
                count++;
        }
        ans = (ans + count*(n-count)*2) % 1000000007;
    }
    return ans;
}
```

## 14. Rearrange Array
https://www.interviewbit.com/problems/rearrange-array/
```c++
void Solution::arrange(vector<int> &A)
{
    int N = A.size();
    for(int i = 0; i < N; ++i) A[i] += (A[A[i]]%N) * N;
    for(int i = 0; i < N; ++i) A[i] = A[i] / N;
}
```

## 15. Largest Coprime Divisor
https://www.interviewbit.com/problems/largest-coprime-divisor/
```c++
// A is greatest number dividing A so we keep dividing x by gcd
// until gcd(x, b) is also matched
int x = A
while (gcd(x, B) != 1) x /= gcd(x, B);
return A;
```