## Subarray with given sum
https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0
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
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) cin >> arr[i];

        int curr_sum = arr[0], start = 0;
        bool found = false;
        for (int i = 1; i <= n; ++i)
        {
            while (curr_sum > s && start < i-1)
                curr_sum -= arr[start++];
            if (curr_sum == s)
            {
                cout << start+1 << " " << i << endl;
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

## Count The Triplets
https://practice.geeksforgeeks.org/problems/count-the-triplets/0
```c++
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
```

## Trapping Rain Water
traverse every array element and find the highest bars on left and right sides. Take the smaller of two heights. The difference between smaller height and height of current element is the amount of water that can be stored in this array element.
```c++
#include <bits/stdc++.h>
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

## Kth Smallest Element
```c++
#include <bits/stdc++.h>
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

## Longest Distinct Characters In String
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
        string s;
        cin >> s;
        int n = s.size();

        int curLen = 1, maxLen = 1, prevIndex;
        int visited[256];
        fill(visited, visited+256, -1);
        visited[s[0]] = 0;
        for (int i = 1; i < n; ++i)
        {
            prevIndex = visited[s[i]];
            if (prevIndex == -1 || i - curLen > prevIndex) ++curLen;
            else maxLen = max(maxLen, curLen), curLen = i - prevIndex;
            visited[s[i]] = i;
        }
        maxLen = max(maxLen, curLen);
        cout << maxLen << endl;
    }
    return 0;
}
```

## Remove Loop In Linked List
```c++
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