#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
using namespace std;
const lli mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> peeps(n);
    vector<int> apps(m);
    for (int i = 0; i < n; i++)
        cin >> peeps[i];
    for (int i = 0; i < m; i++)
        cin >> apps[i];
    sort(peeps.begin(), peeps.end());
    sort(apps.begin(), apps.end());
    int ans = 0;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (abs(peeps[i] - apps[j]) <= k)
        {
            ans++;
            i++;
            j++;
        }
        else if (peeps[i] < apps[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    cout << ans;
    return 0;
}