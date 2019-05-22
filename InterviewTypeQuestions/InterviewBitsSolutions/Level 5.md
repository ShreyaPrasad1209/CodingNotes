# Backtracking
## Subset
https://www.interviewbit.com/problems/subset/
```c++
void subsetHelper(int i, vector<int> &subset, vector< vector<int> > &ans, vector<int> &A)
{
    if (i == A.size())
    {
        ans.push_back(subset);
        return;
    }
    subsetHelper(i+1, subset, ans, A);
    subset.push_back(A[i]);
    subsetHelper(i+1, subset, ans, A);
    subset.pop_back();
}

vector<vector<int> > Solution::subsets(vector<int> &A)
{
    vector< vector<int> > ans;
    vector<int> subset;
    sort(A.begin(), A.end());
    subsetHelper(0, subset, ans, A);
    sort(ans.begin(), ans.end());
    return ans;
}
```

## Combinations
https://www.interviewbit.com/problems/combinations/
```c++
void combineHelper(int i, int k, vector< vector<int> > &result, vector<int> &A, vector<int> &row)
{
    if (row.size() == k)
    {
        result.push_back(row);
        return;
    }
    if (i >= A.size()) return;
    row.push_back(A[i]);
    combineHelper(i+1, k, result, A, row);
    row.pop_back();
    combineHelper(i+1, k, result, A, row);
}

vector<vector<int> > Solution::combine(int n, int k)
{
    vector< vector<int> > result;
    vector<int> A;
    for (int i = 1; i < n+1; ++i) A.push_back(i);
    vector<int> row;
    combineHelper(0, k, result, A, row);
    return result;
}
```

## Combination Sum
```c++
void backtracking(int start, vector<int>& row, int sum, vector<vector<int> >& res, vector<int>& A, int B)
{
    if (sum >= B)
    {
        if (sum==B) res.emplace_back(row);
        return;
    }

    if (start == A.size()) return;
    row.emplace_back(A[start]);
    sum += A[start];
    backtracking(start, row, sum, res, A, B);
    sum -= row[row.size()-1];
    row.pop_back();
    backtracking(start+1, row, sum, res, A, B);
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B)
{
    vector<vector<int> > res;
    vector<int> row, a;
    sort(A.begin(), A.end());

    a.emplace_back(A[0]);
    for (auto i = 1; i<A.size(); ++i)
        if (A[i-1] != A[i])
            a.emplace_back(A[i]);

    backtracking(0, row, 0, res, a, B);
    return res;
}
```

# Combination Sum II
```c++
void backtracking(int start, vector<int>& row, int sum, vector<vector<int> >& res, vector<int>& A, int B)
{
    if (sum==B)
    {
        res.emplace_back(row);
        return;
    }
    if (sum > B || start == A.size()) return;

    row.emplace_back(A[start]);
    sum += A[start];
    backtracking(start+1, row, sum, res, A, B);
    sum -= row[row.size()-1];
    row.pop_back();

    int endIndex = 0;
    for (endIndex = start+1; endIndex < A.size() && A[endIndex]==A[start]; ++endIndex)
        ++start;

    backtracking(start+1, row, sum, res, A, B);
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B)
{
    vector<vector<int> > res;
    vector<int> row;
    sort(A.begin(), A.end());
    backtracking(0, row, 0, res, A, B);
    return res;
}
```

# Hashing