# Backtracking

## Combination Sum
https://www.interviewbit.com/problems/combination-sum/
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

## Combination Sum II
https://www.interviewbit.com/problems/combination-sum-ii/
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

## Letter Phone
https://www.interviewbit.com/problems/letter-phone/
```c++
string temp = "";
unordered_map<char, string> keypad =
{
    { '1', "1" },
    { '2', "abc" },
    { '3', "def" },
    { '4', "ghi" },
    { '5', "jkl" },
    { '6', "mno" },
    { '7', "pqrs" },
    { '8', "tuv" },
    { '9', "wxyz" },
    { '0', "0" }
};
void backtracking(string digits, int i, vector<string>& res)
{
    if (digits[i] - '0' > -1 && digits[i] - '0' < 10)
    {
        string str = keypad[digits[i]];
        for (auto j = 0; j<str.length(); ++j)
        {
            temp += str[j];
            if (i == digits.length() - 1) res.emplace_back(temp);
            else backtracking(digits, i+1, res);
            temp.pop_back();
        }
    }
}
vector<string> Solution::letterCombinations(string A)
{
    vector<string> res;
    backtracking(A, 0, res);
    return res;
}
```

## Palindrome Partitioning
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

## Generate all parantheses II
https://www.interviewbit.com/problems/generate-all-parentheses-ii/
```c++
vector<string> res;
void solve(int n, int l, int r, string tmp = "(")
{
    if (tmp.size() == 2*n)
    {
        res.push_back(tmp);
        return;
    }
    if (r > 0) solve(n, l, r-1, tmp + ")");
    if (l > 0) solve(n, l-1, r+1, tmp + "(");
}

vector<string> Solution::generateParenthesis(int A)
{
    res.clear();
    solve(A, A-1, 1);
    sort(res.begin(), res.end());
    return res;
}
```

## Kth permutation sequence
https://www.interviewbit.com/problems/kth-permutation-sequence/
```c++
int fact(int n)
{
    if (n > 12) return INT_MAX;
    int f = 1;
    for (auto i = 2; i<=n; ++i) f *= i;
    return f;
}
string backtracking(int k, vector<int>& numlist)
{
    auto n = numlist.size();
    if (n==0 || k > fact(n)) return "";
    int f = fact(n-1);
    int pos = k / f;
    k %= f;
    string ch = to_string(numlist[pos]);
    numlist.erase(numlist.begin() + pos);
    return ch + backtracking(k, numlist);
}
string Solution::getPermutation(int n, int k)
{
    vector<int> numlist;
    for (auto i = 1; i<n+1; ++i) numlist.emplace_back(i);
    return backtracking(k-1, numlist);
}
```

# Hashing