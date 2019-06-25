# Greedy Algorithm
## 70. Bulbs
https://www.interviewbit.com/problems/bulbs/
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

## 71. Distribute Candy
https://www.interviewbit.com/problems/distribute-candy/
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

## 72. Gas Station
https://www.interviewbit.com/problems/gas-station/
```c++
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

## 73. Tushar Birthday Bombs
https://www.interviewbit.com/problems/tushars-birthday-bombs/
```c++
vector<int> Solution::solve(int A, vector<int> &B)
{
    int mn = INT_MAX;
    int n = B.size(), pos;
    for (int i = 0; i < n; ++i)
        if (B[i] < mn) mn = B[i], pos = i;
    int maxKick = A/mn;
    vector<int> order;
    for (int i = 0; i < maxKick; ++i) order.push_back(pos);
    int rem = A - (maxKick*mn);
    int i = 0, j;
    while (i < maxKick)
    {
        pos = order[i];
        int index = -1;
        for (j = 0; j < n; ++j)
        {
            if (rem - B[j] + B[pos] >= 0)
            {
                index = j;
                rem = rem - B[j] + B[pos];
                break;
            }
        }
        if (j == n) break;
        order[i] = j;
        ++i;
    }
    return order;
}
```

# Dynamic Programming
## 74. Largest Area Of Rectangle With Permutation
https://www.interviewbit.com/problems/largest-area-of-rectangle-with-permutations/
```c++
int Solution::solve(vector<vector<int> > &A)
{
    vector< vector<int> > dp(A.size(), vector<int>(A[0].size()));
    for (int i = 0; i < dp.size(); ++i)
        for (int j = 0; j < dp[0].size(); ++j)
            dp[i][j] = (i <= 0) ? A[i][j] : ((A[i][j] == 0) ? 0 : dp[i-1][j]+1);

    for (int i = 0; i < A.size(); ++i)
        sort(dp[i].begin(), dp[i].end(), greater<int>());

    int cur_area, max_area = 0;
    for (int i = 0; i < dp.size(); ++i)
    {
        for (int j = 0; j < dp[0].size(); ++j)
        {
            cur_area = (j + 1) * dp[i][j];
            max_area = max(cur_area, max_area);
        }
    }
    return max_area;
}
/*
A:
    0   1   0   1   0
    0   1   0   1   1
    1   1   0   1   0
dp:
    0   1   0   1   0
    0   2   0   2   1
    1   3   0   3   0
sort:
    1   1   0   0   0
    2   2   1   0   0
    3   3   1   0   0
find area :p
*/
```

## 75. Ways To Decode
https://www.interviewbit.com/problems/ways-to-decode/
```c++
int Solution::numDecodings(string A)
{
    int n = A.size();
    if (A.size() == 0 || A[0] == '0') return 0;
    if (A.size() == 1) return 1;

    vector<int> dp(A.size()+1);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        dp[i] = 0;
        if (A[i-1] - '0' > 0) dp[i] = dp[i-1];
        if (A[i-1] == '0' && A[i-2] > '2') return 0;
        if ((A[i-2] - '0' < 2 && A[i-2] - '0' > 0) || (A[i-2] - '0' == 2 && A[i-1] - '0' <= 6))
            dp[i] += dp[i-2];
    }
    return dp[dp.size()-1];
}
```

## 76. Intersecting Chords In a Circle
https://www.interviewbit.com/problems/intersecting-chords-in-a-circle/
```c++
int Solution::chordCnt(int A)
{
    ll n = 2*A;
    ll dp[n+1] {};
    dp[0] = dp[2] = 1;
    for (int i = 4; i <= n; i+=2)
        for (int j = 0; j < i-1; j+=2)
            dp[i] = (dp[i] + dp[j]*dp[i-2-j]) % M;
    return dp[n] % M;
}
```

## 77. Max Sum Without Adjacent Elements
https://www.interviewbit.com/problems/max-sum-without-adjacent-elements/
```c++
int Solution::adjacent(vector<vector<int> > &A)
{
    if (A.size() == 0) return 0;
    int a = 0, b = 0;
    for (int i = 0; i < A[0].size(); ++i)
    {
        int num = max(A[0][i], A[1][i]);
        int temp = max(a, b);
        a = b + num;
        b = temp;
    }
    return max(a, b);
}
```

## 78. Repeating Subsequence
https://www.interviewbit.com/problems/repeating-subsequence/
```c++
int Solution::anytwo(string A)
{
    int n = A.size();
    unordered_map<char, int> rec;
    for (char c : A)
    {
        rec[c]++;
        if (rec[c] > 2) return true;
    }
    // Remove non repeating
    int k = 0;
    for (int i = 0; i < n; ++i)
        if (rec[A[i]] > 1)
            A[k++] = A[i];
    if (isPalindrome(A, 0, k-1))
    {
        // Special case like "AAA" palindrome but repeated sequence exists
        if (k&1) return (A[k/2] == A[k/2 - 1]);
        return false;
    }
    return true;
}
```

## 79. Min Jumps Array
https://www.interviewbit.com/problems/min-jumps-array/
```c++
// DP O(N square) will fail this is modified DP
int Solution::jump(vector<int> &A)
{
    vector<int> dp(A.size(), 0);
    int i = -1, j = 1;
    int val = 0;
    while (j < A.size())
    {
        if (val == 0)
        {
            i++;
            val = A[i];
            dp[j] = dp[i]+1;
        }
        else
        {
            if (A[i]+i >= j)
            {
                dp[j] = max(dp[j-1], dp[j]);
                val--;
                j++;
            }
            else val = 0;
        }
        if (i == j) return -1;
    }
    return dp[A.size()-1];
}
```

## 80. Longest Arithmetic Progression
https://www.interviewbit.com/problems/longest-arithmetic-progression/
```c++
int Solution::solve(const vector<int> &A)
{
    int n = A.size();
    if (n <= 2) return n;
    vector<int> arr = A;
    sort(arr.begin(), arr.end());
    int dp[n][n];
    int llap = 2;
    for (int i = 0; i < n; ++i) dp[i][n-1] = 2;
    for (int j = n-2; j >= 1; --j)
    {
        int i = j-1, k = j+1;
        while (i >= 0 && k <= n-1)
        {
            if (arr[i] + arr[k] < 2*arr[j]) ++k;
            else if (arr[i]+arr[k] > 2*arr[j]) dp[i][j] = 2, --i;
            else
            {
                dp[i][j] = dp[j][k] + 1;
                llap = max(llap, dp[i][j]);
                --i, ++k;
            }
        }
        while (i >= 0) dp[i][j] = 2, --i;
    }
    return llap;
}
```

## 81. N Digit Number With Digit Sum
https://www.interviewbit.com/problems/n-digit-numbers-with-digit-sum-s-/
```c++
#define ll long long
int Solution::solve(int A, int B)
{
    ll dp[A][B];
    if (B < 1 || B > 9*A) return 0;
    for (int i = 0; i < B; ++i)
    {
        if (i+1 <= 9) dp[0][i] = 1;
        else dp[0][i] = 0;
    }
    for (int j = 0; j < A; ++j) dp[j][0] = 1;
    for (int i = 1; i < A; ++i)
    {
        for (int j = 1; j < B; ++j)
        {
            dp[i][j] = 0;
            int k = 0;
            if (j >= 9) k = j-9;
            for (; k <= j; ++k) dp[i][j] = (dp[i][j] + dp[i-1][k]) % 1000000007;
        }
    }
    return dp[A-1][B-1];
}
```

[IN COMPLETE]