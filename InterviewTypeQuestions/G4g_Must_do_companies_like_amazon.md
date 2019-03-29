# Must Do Coding Questions for Companies like Amazon, Microsoft, Adobe, …
https://www.geeksforgeeks.org/must-do-coding-questions-for-companies-like-amazon-microsoft-adobe/

## Missing number in array
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
        int sum = 0;
        for (int i = 0; i < n-1; ++i)
        {
            int x;
            cin >> x;
            sum += x;
        }
        int actualSum = ((n * (n+1)) / 2);
        cout << actualSum - sum << endl;
    }
    return 0;
}
```

## Reverse array in groups
O(N) time O(1) space
```c++
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; ++i) cin >> arr[i];

        for (int i = 0; i < n; i += k)
        {
            int left = i;
            int right = min(i + k - 1, n - 1);
            while (left < right) swap(arr[left++], arr[right--]);
        }

        for (int i = 0; i < n; ++i) cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
```

## Sort an array of 0s 1s and 2s
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
        int count_0 = 0, count_1 = 0, count_2 = 0;
        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            if (x == 0) count_0++;
            else if (x == 1) count_1++;
            else if (x == 2) count_2++;
        }

        vector<int> arr;
        while (count_0 > 0)
        {
            arr.push_back(0);
            count_0--;
        }
        while (count_1 > 0)
        {
            arr.push_back(1);
            count_1--;
        }
        while (count_2 > 0)
        {
            arr.push_back(2);
            count_2--;
        }

        for (int i = 0; i < arr.size(); ++i)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
```

## Element with left side smaller and right side greater

## Subarray with given sum: <br>
Find prefix sum of array no we basically need to find l and r value from this which can be easily done using a hasmap.
```c++
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, s;
        scanf("%d %d", &n, &s);
        ll arr[n];
        for (int i = 0; i < n; ++i)
            scanf("%lld", &arr[i]);

        ll prefSum[n];
        ll prev = 0;
        for (int i = 0; i < n; ++i)
        {
            prefSum[i] = prev + arr[i];
            prev = prefSum[i];
        }

        unordered_map<ll, int> rec;
        bool found = false;
        for (int i = 0; i < n; ++i)
        {
            if (prefSum[i] == s)
            {
                printf("%d %d\n", 1, i+1);
                found = true;
                break;
            }
            if (arr[i] == s)
            {
                printf("%d %d\n", i+1, i+1);
                found = true;
                break;
            }
            rec[prefSum[i]] = i+1;
            int reqd = prefSum[i] - s;
            if (reqd <= 0) continue;
            if (rec[reqd] != 0)
            {
                printf("%d %d\n", rec[reqd]+1, i+1);
                found = true;
                break;
            }
        }

        if (!found)
            cout << -1 << endl;
    }
    return 0;
}
```

## Relative Sorting

## Equilibrium Point:<br>
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
        int prefSum[n];
        prefSum[0] = arr[0];
        for (int i = 1; i < n; ++i) prefSum[i] = prefSum[i-1] + arr[i];

        int ans = 0;
        for (ans = 0; ans < n; ++ans)
        {
            //check if this position is in equilibrium
            int left = 0, right = 0;
            if (ans > 0) left = prefSum[ans-1];
            if (ans < n-1) right = prefSum[n-1] - prefSum[ans];
            if (left == right) break;
        }
        if (ans == n) cout << -1 << endl;
        else cout << ans+1 << endl;
    }
    return 0;
}
```

## Kth largest element in a stream
```c++
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> k >> n;
        priority_queue<int, vector<int>, greater<int> > qu;
        for (int i = 0; i < k; ++i) qu.push(-1);
        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            qu.push(x);
            qu.pop();
            cout << qu.top() << " ";
        }
        cout << endl;
    }
    return 0;
}
```

## Largest Number formed from an array
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
        vector<string> arr;
        for (int i = 0; i < n; ++i)
        {
            string str;
            cin >> str;
            arr.push_back(str);
        }

        sort(arr.begin(), arr.end(), [](string X, string Y)
        {
            string XY = X.append(Y);
            string YX = Y.append(X);
            return XY.compare(YX) > 0 ? 1 : 0;
        });

        for (int i = 0; i < arr.size(); i++) cout << arr[i];
        cout << endl;
    }
    return 0;
}
```

## Sorting Elements of an Array by Frequency
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
        vector<int> arr(n), aux(n), freq;
        for (int i = 0; i < n; ++i) cin >> arr[i];
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; ++i) aux[i] = arr[i];
        aux.erase(unique(aux.begin(), aux.end()), aux.end());
        for (int i = 0; i < aux.size(); ++i)
            freq.push_back(count(arr.begin(), arr.end(), aux[i]));

        vector< pair<int, int> > data(aux.size());
        for (int i = 0; i < aux.size(); ++i)
            data[i] = make_pair(freq[i], aux[i]);
        sort(data.begin(), data.end(), greater< pair<int, int> >());
        sort(data.begin(), data.end(), [](pair<int, int> &a, pair<int, int> &b) -> bool
        {
            if (a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        });

        for (int i = 0; i < data.size(); ++i)
        {
            for (int j = 0; j < data[i].first; ++j)
                cout << data[i].second << " ";
        }
        cout << endl;
    }
    return 0;
}
```

## Maximum of all subarrays of size k (Sliding Window)
```c++
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; ++i) cin >> arr[i];

        deque<int> que;
        for (int i = 0; i < k; ++i)
        {
            while (!(que.empty()) && arr[que.back()] <= arr[i]) que.pop_back();
            que.push_back(i);
        }

        for (int i = k; i < n; ++i)
        {
            cout << arr[que.front()] << " ";
            while (!(que.empty()) && que.front() == i-k) que.pop_front();
            while (!(que.empty()) && arr[que.back()] <= arr[i]) que.pop_back();
            que.push_back(i);
        }
        cout << arr[que.front()] << endl;
    }
    return 0;
}
```

## Kaden's Algorithm:<br>
Max subarray problem https://www.youtube.com/watch?v=86CQq3pKSUw
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
        int aux[n];
        aux[0] = arr[0];
        int ans = max(INT_MIN, aux[0]);
        for (int i = 1; i < n; ++i)
        {
            aux[i] = max(aux[i-1] + arr[i], arr[i]);
            ans = max(ans, aux[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
```

## Maximum Sum Increasing Subsequence:<br>
https://www.youtube.com/watch?v=99ssGWhLPUE
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
        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        int ans = 0;
        int aux[n];
        for (int i = 0; i < n; ++i) aux[i] = arr[i];
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (arr[i] > arr[j] && aux[i] < aux[j] + arr[i])
                    aux[i] = aux[j] + arr[i];
            }
        }
        for (int i = 0; i < n; i++) ans = max(aux[i], ans);
        cout << ans << endl;
    }
    return 0;
}
```

## Kth smallest element
Not do complete quick sort but to stop when pivot itself is the kth smallest element O(N) avg O(N square) worst. We can also use a heap
```c++
#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = l-1;
    for (int j = l; j <= r-1; ++j)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[r]);
    return i+1;
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

## Nth lexiographic of a string
https://www.quora.com/How-can-we-find-the-lexicographically-Kth-permutation-of-the-sequence-1-N-efficiently

## Largest subarray with equal number of 0s and 1s
O(N square) and O(N) solution

## LEFT OVERS:
> How to think of O(1) space complexity solution

> Writing C style code