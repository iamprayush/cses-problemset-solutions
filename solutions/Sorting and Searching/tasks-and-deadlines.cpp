#include <bits/stdc++.h>
#define pb push_back
#define endl '\n'
#define lli long long int
#define li long int
#define ld long double
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pii pair<int, int>
using namespace std;
const lli mod = 1e9 + 7;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, a, b;
	cin >> n;
	vii arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		arr[i] = make_pair(a, b);
	}
	sort(arr.begin(), arr.end());
	lli total = 0, curr = 0;
	for (auto ele : arr)
	{
		curr += ele.first;
		total += ele.second - curr;
	}
	cout << total;
	return 0;
}
