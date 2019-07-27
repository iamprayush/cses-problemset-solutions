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
	lli n, total=0, ans=INT_MAX;
	cin >> n;
	li arr[n];
	for(lli i = 0; i < n; i++) {
		cin >> arr[i];
		total += arr[i];
	}
	for(lli i = 0; i < 1<<n; i++) {
		lli s = 0;
		for(lli j = 0; j < n; j++) {
			if(i & 1<<j) s += arr[j];
		}
		lli curr = abs((total-s)-s);
		ans = min(ans, curr);
	}
	cout << ans;
	return 0;
}