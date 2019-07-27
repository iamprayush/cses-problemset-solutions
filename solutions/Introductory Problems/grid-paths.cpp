#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
using namespace std;
const lli mod = 1e9 + 7;
const int n = 7;
bool visited[n][n];
int reserved[49];

void move(int r, int c, int &ans, int &steps)
{
    if (r == n - 1 && c == 0)
    {
        ans += (steps == n * n - 1);
        return;
    }

    // if you hit a wall or a path (can only go left or right); return
    if (((r + 1 == n || (visited[r - 1][c] && visited[r + 1][c])) && c - 1 >= 0 && c + 1 < n && !visited[r][c - 1] && !visited[r][c + 1]) ||
        ((c + 1 == n || (visited[r][c - 1] && visited[r][c + 1])) && r - 1 >= 0 && r + 1 < n && !visited[r - 1][c] && !visited[r + 1][c]) ||
        ((r == 0 || (visited[r + 1][c] && visited[r - 1][c])) && c - 1 >= 0 && c + 1 < n && !visited[r][c - 1] && !visited[r][c + 1]) ||
        ((c == 0 || (visited[r][c + 1] && visited[r][c - 1])) && r - 1 >= 0 && r + 1 < n && !visited[r - 1][c] && !visited[r + 1][c]))
        return;

    visited[r][c] = true;

    if (reserved[steps] != -1)
    {
        switch (reserved[steps])
        {
        case 0:
            if (r - 1 >= 0)
            {
                if (!visited[r - 1][c])
                {
                    steps++;
                    move(r - 1, c, ans, steps);
                    steps--;
                }
            }
            break;

        case 1:
            if (c + 1 < n)
            {
                if (!visited[r][c + 1])
                {
                    steps++;
                    move(r, c + 1, ans, steps);
                    steps--;
                }
            }
            break;

        case 2:
            if (r + 1 < n)
            {
                if (!visited[r + 1][c])
                {
                    steps++;
                    move(r + 1, c, ans, steps);
                    steps--;
                }
            }
            break;

        case 3:
            if (c - 1 >= 0)
            {
                if (!visited[r][c - 1])
                {
                    steps++;
                    move(r, c - 1, ans, steps);
                    steps--;
                }
            }
            break;
        }
        visited[r][c] = false;
        return;
    }

    // move down
    if (r + 1 < n)
    {
        if (!visited[r + 1][c])
        {
            steps++;
            move(r + 1, c, ans, steps);
            steps--;
        }
    }

    // move right
    if (c + 1 < n)
    {
        if (!visited[r][c + 1])
        {
            steps++;
            move(r, c + 1, ans, steps);
            steps--;
        }
    }

    // move up
    if (r - 1 >= 0)
    {
        if (!visited[r - 1][c])
        {
            steps++;
            move(r - 1, c, ans, steps);
            steps--;
        }
    }

    // move left
    if (c - 1 >= 0)
    {
        if (!visited[r][c - 1])
        {
            steps++;
            move(r, c - 1, ans, steps);
            steps--;
        }
    }
    visited[r][c] = false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string path;
    cin >> path;
    for (int i = 0; i < path.length(); i++)
    {
        if (path[i] == '?')
            reserved[i] = -1;
        else if (path[i] == 'U')
            reserved[i] = 0;
        else if (path[i] == 'R')
            reserved[i] = 1;
        else if (path[i] == 'D')
            reserved[i] = 2;
        else if (path[i] == 'L')
            reserved[i] = 3;
    }
    int ans = 0, steps = 0;
    move(0, 0, ans, steps);
    cout << ans;
    return 0;
}