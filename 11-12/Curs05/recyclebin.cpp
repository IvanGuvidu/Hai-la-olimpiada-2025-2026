#include <fstream>

using namespace std;

ifstream in ("recyclebin.in");
ofstream out ("recyclebin.out");

const int max_size = 1e3 + 1;

int dp[max_size][1025];

int main ()
{
    int n, ans = 0;
    in >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        in >> x;
        for (int j = 0; j < i; j++)
        {
            dp[i][j] = max(dp[i][j], dp[i - 1][j] + x);
            ans = max(ans, dp[i][j]);
        }
        for (int j = 1; j < i; j *= 2)
        {
            for (int k = 0; k <= i - j; k++)
            {
                if ((j & k) == 0)
                {
                    int newconf = (j | k);
                    dp[i][newconf] = max(dp[i][newconf], dp[i - j][k]);
                    ans = max(dp[i][newconf], ans);
                }
            }
        }
    }
    out << ans;
    in.close();
    out.close();
    return 0;
}