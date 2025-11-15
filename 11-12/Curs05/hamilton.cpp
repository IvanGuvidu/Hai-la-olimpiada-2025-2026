#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 2, max_c = (1 << 18) + 20;

int cost[20][20], dp[max_c][20];

void solve ()
{
    long long n, m;
    cin >> n >> m;
    for (long long i = 0; i < n; i++)
    {
        for (long long j = 0; j < n; j++)
        {
            cost[i][j] = INF;
        }
    }
    for (long long i = 1; i < (1 << n); i++)
    {
        for (long long j = 0; j < n; j++)
        {
            dp[i][j] = INF;
        }
    }
    dp[1][0] = 0;
    while (m--)
    {
        int x, y, c;
        cin >> x >> y >> c;
        cost[x][y] = min(cost[x][y], c);
    }
    for (long long i = 1; i < (1 << n); i++)
    {
        for (long long j = 0; j < n; j++)
        {
            if ((i & (1 << j)) != 0)
            {
                for (long long k = 0; k < n; k++)
                {
                    if ((i & (1 << k)) == 0)
                    {
                        dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j] + cost[j][k]);
                    }
                }
            }
        }
    }
    int ans = INF;
    for (long long j = 0; j < n; j++)
    {
        ans = min(ans, dp[(1 << n) - 1][j] + cost[j][0]);
    }
    if (ans == INF)
    {
        cout << "Nu exista solutie";
    }
    else
    {
        cout << ans;
    }
    cout << '\n';
}

signed main ()
{
#ifdef LOCAL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    freopen("hamilton.in", "r", stdin);
    freopen("hamilton.out", "w", stdout);
#endif // LOCAL
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long tt;
    //cin >> tt;
    tt = 1;
    while (tt--)
    {
        solve();
    }
    return 0;
}