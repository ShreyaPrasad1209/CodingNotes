# Backtracking

## 40. Combination Sum
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

## 41. Combination Sum II
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

## 42. Letter Phone
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

## 43. Palindrome Partitioning
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

## 44. Generate all parantheses II
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

## 45. Kth permutation sequence
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

## 46. 2 Sum
https://www.interviewbit.com/problems/2-sum/
```c++
vector<int> Solution::twoSum(const vector<int> &A, int B)
{
    int ansI = INT_MAX, ansJ = INT_MAX;
    unordered_map< int, vector<int> > rec;
    for (int i = 0; i < A.size(); ++i)
    {
        for (int j : rec[B - A[i]])
        {
            if (i == j) continue;
            int curI = min(i, j);
            int curJ = max(i, j);
            if (A[curI] + A[curJ] == B && (curJ < ansJ || (curJ == ansJ && curI < ansI)))
            {
                ansJ = curJ;
                ansI = curI;
            }
        }
        rec[A[i]].push_back(i);
    }

    vector<int> res;
    if (ansI != INT_MAX)
    {
        res.push_back(ansI+1);
        res.push_back(ansJ+1);
    }
    return res;
}
```

## 47. Anagrams
https://www.interviewbit.com/problems/anagrams/
```c++
vector<vector<int> > Solution::anagrams(const vector<string> &A)
{
    vector< vector<int> > sol;
    unordered_map< string, vector<int> > myMap;
    string temp;
    for (int i = 0; i < A.size(); ++i)
    {
        temp = A[i];
        sort(temp.begin(), temp.end());
        myMap[temp].push_back(i+1);
    }

    auto it = myMap.begin();
    while (it != myMap.end())
    {
        sol.push_back(it->second);
        it++;
    }

    return sol;
}
```

## 48. Equal
https://www.interviewbit.com/problems/equal/
```c++
vector<int> Solution::equal(vector<int> &A)
{
    unordered_map <int, vector<int> > myMap;
    vector<int> sol;
    vector<int> temp;

    int count = 0;
    for(int i = 0; i < A.size()-1; i++)
    {
        for(int j = i+1; j < A.size(); j++)
        {
            int sum = A[i] + A[j];
            if(myMap.find(sum) == myMap.end())
            {
                myMap[sum].push_back(i);
                myMap[sum].push_back(j);
            }
            else
            {
                temp.push_back(myMap[sum][0]);
                temp.push_back(myMap[sum][1]);
                temp.push_back(i);
                temp.push_back(j);
                for(int a = 0; a < temp.size()-1; a++)
                {
                    for(int b = a+1; b < temp.size(); b++)
                    {
                        if(temp[a] == temp[b])
                            goto COND;
                    }
                }
                count++;
                if(count == 1) sol = temp;
                else
                {
                    for(int z = 0; z < sol.size(); z++)
                    {
                        if(sol[z] > temp[z])
                        {
                           sol = temp;
                           break;
                        }
                        else if(sol[z] < temp[z]) break;
                    }
                }
                COND:temp.erase(temp.begin(), temp.end());
            }
        }
    }
    return sol;
}
```

## 49. Longest Substring Without Repeat
https://www.interviewbit.com/problems/longest-substring-without-repeat/
```c++
int Solution::lengthOfLongestSubstring(string A)
{
    unordered_set<char> myMap;
    int temp = 0, sol = 0, i = 0, j = 0;

    while(j < A.size())
    {
        if(myMap.find(A[j]) == myMap.end())
        {
            myMap.insert(A[j]);
            j++;
            temp++;
        }
        else
        {
            while(A[i] != A[j])
            {
                myMap.erase(A[i]);
                i++;
                temp--;
            }
            if(i != j) i++;
            temp--;
            myMap.erase(A[j]);
        }
        if(temp > sol) sol = temp;
    }
    return sol;
}
```

## 50. Window String
https://www.interviewbit.com/problems/window-string/
```c++
string Solution::minWindow(string S, string T)
{
    if (S.size() < T.size()) return "";
    unordered_map<char, int> counts;
    for (int i = 0; i < T.size(); ++i) counts[T[i]]++;

    int start = 0, length = 0, total = 0;
    for (int i = 0, j = 0; j < S.size(); ++j)
    {
        if (counts.find(S[j]) == counts.end()) continue;
        counts[S[j]]--;
        if (counts[S[j]] >= 0) total++;
        if (total == T.size())
        {
            while (counts.find(S[i]) == counts.end() || counts[S[i]] < 0)
            {
                if (counts.find(S[i]) != counts.end()) counts[S[i]]++;
                i++;
            }
            if (length == 0 || j-i+1 < length)
            {
                start = i;
                length = j-i+1;
            }
        }
    }
    return S.substr(start, length);
}
```

## 51. Points on the Straight Line
https://www.interviewbit.com/problems/points-on-the-straight-line/
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

        for (auto tmp : rec)
            sol = max(sol, tmp.second + duplicate);
        sol = max(vertical + duplicate, sol);
        rec.clear();
    }
    return sol;
}
```

## 52. Substring Concatenation
https://www.interviewbit.com/problems/substring-concatenation/
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