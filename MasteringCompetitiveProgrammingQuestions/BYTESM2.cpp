#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int h, m;
        cin >> h >> m;
        int arr[h+9][m+9];
        for (int i = 0; i < h; i++)
        {
            for (int j = 0 ; j < m ; j++)
                cin >> arr[i][j];
        }

        int ma = -1;
        for (int i = 0; i < m; i++) ma = max(ma, arr[0][i]);
        for (int i = 1; i < h; i++)
        {
            ma = -1;
            for(int j = 0 ; j < m ; j++)
            {
                if (j > 0 && j < m-1)
                    arr[i][j] = max(arr[i-1][j] + arr[i][j], max(arr[i-1][j-1] + arr[i][j] , arr[i-1][j+1] + arr[i][j]));
                else if (j > 0)
                    arr[i][j] = max(arr[i-1][j] + arr[i][j], arr[i-1][j-1] + arr[i][j]);
                else if(j<m-1)
                    arr[i][j] = max(arr[i-1][j] + arr[i][j], arr[i-1][j+1] + arr[i][j]);
                ma = max(arr[i][j], ma);
            }
        }
        cout << ma << endl;
    }
    return 0;
}
