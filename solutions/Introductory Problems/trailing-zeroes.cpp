#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int total = 0;
    for (int i = 5; n / i >= 1; i *= 5)
    {
        total += n / i;
    }
    cout << total;
    return 0;
}