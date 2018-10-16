//Gray Simmilar Code - Page 46
//https://www.codechef.com/status/GRAYSC
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long long int ulli;
#define mat(x, y, name) vector< vector<ull> > name (x, vector<ull>(y));
#define printMat(name) for (int i = 0; i < name.size(); i++) {for (int j = 0; j < res[i].size(); j++) cout << res[i][j] << " "; cout << endl;}

int MOD = 1000000000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; 
	unsigned long long a[n];
 
	cin >> n;
	if (n >= 130)
    {
		cout << "Yes";
		return 0;
	}
	for (int i=0;i<n;++i) cin >> a[i];
	for (int i=0;i<n;++i)
    { 
		for (int j=i+1;j<n;++j)
        { 
			for (int k=j+1;k<n;++k)
            { 
				for (int l=k+1;l<n;++l)
                { 
				    if ((a[i]^a[j]^a[k]^a[l])==0)
                    {
					    cout << "Yes";
					    return 0;
				    }
                }
            }
        }
    }
 
	cout << "No";
	return 0;
}