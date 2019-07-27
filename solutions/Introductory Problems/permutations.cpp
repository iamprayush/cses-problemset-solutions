#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define lli long long int
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << "1";
    }
    else if (n < 4)
    {
        cout << "NO SOLUTION";
    }
    else if (n == 4)
    {
        cout << "3 1 4 2";
    }
    else
    {
        // print odds
        for (int i = 1; i <= n; i += 2)
        {
            cout << i << " ";
        }
        // print evens
        for (int i = 2; i <= n; i += 2)
        {
            cout << i << " ";
        }
    }
    return 0;
}