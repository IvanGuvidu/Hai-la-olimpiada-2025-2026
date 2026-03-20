#include <fstream>
#include <vector>

using namespace std;

ifstream in ("pinex.in");
ofstream out ("pinex.out");

const long long max_size = 1e6 + 1;

int ciur[max_size];
vector <long long> pr;

void ciuru ()
{
    ciur[0] = 1;
    ciur[1] = 1;
    for (long long i = 2; i < max_size; i++)
    {
        if (ciur[i] == 1)
        {
            continue;
        }
        pr.push_back(i);
        for (long long j = 2 * i; j < max_size; j += i)
        {
            ciur[j] = 1;
        }
    }
}

void solve ()
{
    long long a, b;
    in >> a >> b;
    vector <long long> divz;
    for (auto f : pr)
    {
        if (f > b)
        {
            break;
        }
        if (b % f == 0)
        {
            divz.push_back(f);
            while (b % f == 0)
            {
                b /= f;
            }
        }
    }
    if (b > 1)
    {
        divz.push_back(b);
    }
    long long ans = 0, n = divz.size();
    for (long long i = 1; i < (1 << n); i++)
    {
        long long val = -1;
        for (long long j = 0; j < n; j++)
        {
            if ((i & (1 << j)) != 0)
            {
                val *= -divz[j];
            }
        }
        ans += a / val;
    }
    out << a - ans << '\n';
}

signed main ()
{
    ciuru();
    long long t;
    in >> t;
    while (t--)
    {
        solve();
    }
    in.close();
    out.close();
    return 0;
}