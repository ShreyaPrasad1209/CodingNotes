# Leetcode Questions
## Pascal's Triangle
https://leetcode.com/problems/pascals-triangle/
```c++
class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int> > ans;
        for (int i = 0; i < numRows; ++i)
        {
            vector<int> temp;
            temp.push_back(1);
            if (i != 0)
            {
                if (i > 1)
                {
                    for (int j = 0; j <= i-2; ++j)
                        temp.push_back(ans[ans.size()-1][temp.size()] + ans[ans.size()-1][temp.size()-1]);
                }
                temp.push_back(1);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
```

## Maximum Width of Binary Tree
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