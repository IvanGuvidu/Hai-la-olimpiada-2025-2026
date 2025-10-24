#include <fstream>

using namespace std;

ifstream in ("cladire.in");
ofstream out ("cladire.out");

const int mod = 9901, max_size = 1e3 + 1;

int dp[1005][1005];

int main()
{
    int n, m;
    in >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        dp[i][1] = 1;
    }
    for (int j = 1; j <= m; j++)
    {
        dp[1][j] = 1;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= m; j++)
        {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
        }
    }
    out << dp[n][m];
    in.close();
    out.close();
    return 0;
}