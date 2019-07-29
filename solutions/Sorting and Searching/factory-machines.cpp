#include <bits/stdc++.h>
#define pb push_back
#define endl '\n'
#define lli long long int
#define li long int
#define ld long double
#define vi vector<int>
#define vii vector<int, int>
#define pii pair<int, int>
using namespace std;
const lli mod = 1e9 + 7;

lli solve(vector<lli> arr, lli max_val, lli target)
{
	lli l = 0, r = target * max_val + 1, mid, curr_output, ans;
	while (l <= r)
	{
		mid = l + (r - l) / 2;
		curr_output = 0;
		for (lli ele : arr)
		{
			curr_output += mid / ele;
		}
		if (curr_output >= target)
		{
			ans = mid;
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n, target, max_val = 0;
	cin >> n >> target;
	vector<lli> arr(n);
	for (lli i = 0; i < n; i++)
	{
		cin >> arr[i];
		max_val = max(max_val, arr[i]);
	}
	cout << solve(arr, max_val, target);
	return 0;
}
