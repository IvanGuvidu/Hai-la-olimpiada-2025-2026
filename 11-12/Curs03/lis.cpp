#include <fstream>

using namespace std;

ifstream in ("scmax.in");
ofstream out ("scmax.out");

const int max_size = 1e5 + 1;

int best[max_size], p[max_size], st[max_size], a[max_size], k;

int cb (int x)
{
    int l = 0, r = k, m = (l + r) / 2;
    while (l <= r)
    {
        if (a[st[m]] < x && a[st[m + 1]] >= x)
        {
            return m;
        }
        else
        {
            if (a[st[m + 1]] < x)
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
            m = (l + r) / 2;
        }
    }
    return k;
}

void afis (int poz)
{
    if (p[poz] > 0)
    {
        afis(p[poz]);
    }
    out << a[poz] << " ";
}

int main ()
{
    int n;
    k = 1;
    in >> n;
    for (int i = 1; i <= n; i++)
    {
        in >> a[i];
    }
    st[1] = 1;
    best[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        int poz = cb(a[i]);
        p[i] = st[poz];
        best[i] = poz + 1;
        st[poz + 1] = i;
        if (k < poz + 1)
        {
            k = poz + 1;
        }
    }
    int poz = 0, max1 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (max1 < best[i])
        {
            max1 = best[i];
            poz = i;
        }
    }
    out << max1 << '\n';
    afis(poz);
    in.close();
    out.close();
    return 0;
}