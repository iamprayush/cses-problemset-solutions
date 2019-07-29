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
	int x, n, point, left, right;
	cin >> x >> n;
	set<int> points = {0, x};
	multiset<int> lengths = {x};
	while (n--)
	{
		cin >> point;
		// find the position to insert the current point
		auto it = points.upper_bound(point);

		// [left, right] : the range in which the point is being inserted
		left = *prev(it);
		right = *it;

		// remove that range from lengths
		lengths.erase(lengths.find(right - left));
		// add new lengths
		lengths.insert(point - left);
		lengths.insert(right - point);

		// insert the new point
		points.insert(it, point);

		// output the largest length
		cout << *lengths.rbegin() << " ";
	}
	return 0;
}
