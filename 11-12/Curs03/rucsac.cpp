#include <fstream>

using namespace std;

ifstream in ("rucsac.in");
ofstream out ("rucsac.out");

const int max_size = 5e3 + 1, max_g = 1e4 + 1;

int w[max_size], p[max_size], sol[max_g];

int main ()
{
    int n, g;
    in >> n >> g;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        in >> w[i] >> p[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = g - w[i]; j >= 0; j--)
        {
            if (sol[j + w[i]] < sol[j] + p[i])
            {
                sol[j + w[i]] = sol[j] + p[i];
                ans = max(ans, sol[j + w[i]]);
            }
        }
    }
    out << ans;
    in.close();
    out.close();
    return 0;
}