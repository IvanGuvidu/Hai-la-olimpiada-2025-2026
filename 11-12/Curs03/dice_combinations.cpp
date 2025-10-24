#include <iostream>
 
using namespace std;
 
const int max_dp = 1e6 + 10, mod = 1e9 + 7;
 
long long dp[max_dp];
 
int main ()
{
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 1;
    dp[5] = 1;
    dp[6] = 1;
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        for (int k = 1; k <= 6; k++)
        {
            dp[i + k] = (dp[i + k] + dp[i]) % mod;
        }
    }
    cout << dp[n];
    return 0;
}