#include <fstream>

using namespace std;

ifstream in ("kfib.in");
ofstream out ("kfib.out");

const int max_size = 3, MOD = 666013;

long long ans[max_size][max_size], inm[max_size][max_size], aux[max_size][max_size], rez[max_size][max_size];

void prod (long long m1[3][3], long long m2[3][3], long long pr[3][3], int n, int m, int p)
{
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            aux[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = 1; k <= p; k++)
            {
                aux[i][j] = (aux[i][j] + m1[i][k] * m2[k][j]) % MOD;
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            pr[i][j] = aux[i][j];
        }
    }
}

void lgput (long long m[3][3], int n, int e)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            rez[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        rez[i][i] = 1; /// il fac I2
    }
    while (e != 0)
    {
        if (e % 2 == 1)
        {
            prod(rez, m, rez, n, n, n);
        }
        prod(m, m, m, n, n, n);
        e /= 2;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            m[i][j] = rez[i][j];
        }
    }
}

int main ()
{
    long long n;
    in >> n;
    inm[1][1] = 1;
    inm[1][2] = 1;
    inm[2][1] = 1;
    lgput(inm, 2, n - 2);
    ans[1][1] = 1;
    ans[1][2] = 1;
    prod(ans, inm, ans, 1, 2, 2);
    out << ans[1][1];
}