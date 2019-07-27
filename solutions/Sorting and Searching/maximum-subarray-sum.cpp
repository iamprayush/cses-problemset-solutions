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
    int n;
    cin >> n;
    vector<lli> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    lli curr_best = arr[0], global_best = arr[0];
    for (int i = 1; i < n; i++)
    {
        curr_best = max(curr_best + arr[i], arr[i]);
        global_best = max(global_best, curr_best);
    }
    cout << global_best;
    return 0;
}
