## 1. Create tiny URL: https://leetcode.com/problems/encode-and-decode-tinyurl
```c++
class Solution
{
public:
    string convert(int num)
    {
        string res = "";
        do
        {
            // a to z, A to Z, 0 to 9 = 62
            int x = num % 62;
            num /= 62;
            if (x >= 0 && x < 26) res += 'a' + x;
            else if (x >= 26 && x < 52) res += 'A' + (x-26);
            else if (x >= 52) res += '0' + (x-52);
        }
        while (num);
        return res;
    }

    unordered_map<string, string> rec;
    int num = 0;
    string base = "http://tinyurl.com/";
    string encode(string longUrl)
    {
        string key = convert(num);
        rec[key] = longUrl;
        return base + key;
    }

    string decode(string shortUrl)
    {
        return rec[shortUrl.substr(base.size(), shortUrl.size()-base.size())];
    }
};
```

## 2. Longest Absolute File Path: https://leetcode.com/problems/longest-absolute-file-path
```c++
// "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" = "dir\subdir2\file.ext" = 20
class Solution {
public:
    int lengthLongestPath(string input)
    {
        vector<int> dirs(256, 0);
        int res = 0;
        input.push_back('\n');

        int level = 0, len = 0, isFile = 0;
        for (char ch : input)
        {
            if (ch == '\n') level = 0, len = 0, isFile = 0;
            else if (ch == '\t') level++;
            else
            {
                if (ch == '.') isFile = 1;
                len++;
                dirs[level] = len;
                if (isFile)
                    res = max(res, accumulate(dirs.begin(), dirs.begin() + level + 1, 0) + level);
            }
        }
        return res;
    }

};
```

## 3. K Empty Slots: https://zxi.mytechroad.com/blog/simulation/leetcode-683-k-empty-slots/
```c++
// flowers: [1,3,2] k: 1
// In the second day, the first and the third flower have become blooming.
class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k)
    {
        int n = flowers.size();
        if (n == 0 || k >= n) return -1;
        set<int> xs;
        for (int x : flowers)
        {
            auto r = xs.insert(x).first;
            auto l = r;
            if (++r != xs.end() && *r == x+k+1) return i+1;
            if (l != xs.begin() && *(--l) == x-k-1) return i+1;
        }
    }
}
```

## 4. Mutable array Update, Range Problem
```c++
void update(int BIT[], int n, int i, int incr)
{
    while (i <= n)
    {
        BIT[i] += incr;
        i += (i & -i);
    }
}
int query(int BIT[], int n, int i)
{
    int ans = 0;
    while (i > 0)
    {
        ans += BIT[i];
        i -= (i & -i);
    }
    return ans;
}
//2D : https://www.cnblogs.com/grandyang/p/5300458.html
class numMatrix
{
private:
    vector< vector<int> > mat, BIT;
    int n, m;

public:
    int getSum(int row, int column)
    {
        int res = 0;
        for (int i = row; i > 0; i -= i&(-i))
            for (int j = column; j > 0; j -= j&(-j))
                res += BIT[i][j];
        return res;
    }
    void update(int row, int column, int diff)
    {
        for (int i = row; i <= n; i += i&(-i))
            for (int j = column; j <= m; j += j&(-j))
                BIT[i][j] += diff;
    }

    numMatrix(vector< vector<int> > &matrix)
    {
        if (matrix.empty() || matrix[0].empty()) return;
        int n = matrix.size(), m = matrix[0].size();
        mat.resize(n+1, vector<int>(m, 0));
        BIT.resize(n+1, vector<int>(m, 0));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                update(i+1, j+1, matrix[i][j]);
                mat[i][j] = matrix[i][j];
            }
        }
    }
    void updateMatrix(int row, int column, int val)
    {
        int diff = val - mat[row][column];
        mat[row][column] = val;
        update(row+1, column+1, diff);
    }
    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return getSum(row2+1, col2+1) - getSum(row2+1, col1) - getSum(row1, col2+1) + getSum(row1, col1);
    }
};
```

