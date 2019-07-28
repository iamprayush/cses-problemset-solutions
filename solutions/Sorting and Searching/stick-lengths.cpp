#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
using namespace std;
const lli mod = 1e9 + 7;

lli compute_cost(vector<int> arr, int target)
{
	lli cost = 0;
	for (auto ele : arr)
	{
		cost += abs(target - ele);
	}
	return cost;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	int median = arr[n / 2];
	cout << compute_cost(arr, median);
	return 0;
}
