#include <fstream>

using namespace std;

ifstream in ("aib.in");
ofstream out ("aib.out");

#define lsb(x)(x & (-x))

const int max_size = 1e5 + 1;

int aib[max_size], n;

void upd (int poz, int val)
{
    for (int i = poz; i <= n; i += lsb(i))
    {
        aib[i] += val;
    }
}

int query (int poz)
{
    int ans = 0;
    for (int i = poz; i > 0; i -= lsb(i))
    {
        ans += aib[i];
    }
    return ans;
}

int cb (int x)
{
    int e = 0;
    while ((1 << (e + 1)) <= n)
    {
        e++;
    }
    int st = 0;
    while (e >= 0)
    {
        if (st + (1 << e) <= n && aib[st + (1 << e)] < x)
        {
            st += (1 << e);
            x -= aib[st];
        }
        e--;
    }
    st++;
    if (st == n + 1 || query(st) - query(st - 1) != x)
    {
        return -1;
    }
    return st;
}

int main ()
{
    int q;
    in >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        int x;
        in >> x;
        upd(i, x);
    }
    while (q--)
    {
        int op;
        in >> op;
        if (op == 0)
        {
            int x, y;
            in >> x >> y;
            upd(x, y);
        }
        if (op == 1)
        {
            int x, y;
            in >> x >> y;
            out << query(y) - query(x - 1) << '\n';
        }
        if (op == 2)
        {
            int x;
            in >> x;
            out << cb(x) << '\n';
        }
    }
    in.close();
    out.close();
    return 0;
}
