#include <iostream>
 
using namespace std;
 
const int max_aint = 8e5 + 1, max_size = 2e5 + 1;
 
long long aint[max_aint], a[max_size];
 
void init (int nod, int l, int r)
{
    if (l == r)
    {
        aint[nod] = a[l];
        return;
    }
    int m = (l + r) / 2;
    init(2 * nod, l, m);
    init(2 * nod + 1, m + 1, r);
    aint[nod] = aint[2 * nod + 1] + aint[2 * nod];
}
 
void update (int val, int poz, int nod, int l, int r)
{
    if (l == r)
    {
        aint[nod] = val;
        return;
    }
    int m = (l + r) / 2;
    if (poz <= m)
    {
        update(val, poz, 2 * nod, l, m);
    }
    else
    {
        update(val, poz, 2 * nod + 1, m + 1, r);
    }
    aint[nod] = aint[2 * nod + 1] + aint[2 * nod];
}
 
long long query (int nod, int l, int r, int st, int dr)
{
    if (st <= l && r <= dr)
    {
        return aint[nod];
    }
    int m = (l + r) / 2;
    long long p1 = 0, p2 = 0;
    if (st <= m)
    {
        p1 = query(2 * nod, l, m, st, dr);
    }
    if (dr > m)
    {
        p2 = query(2 * nod + 1, m + 1, r, st, dr);
    }
    return p1 + p2;
}
 
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    init(1, 1, n);
    while (q--)
    {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1)
        {
            update(y, x, 1, 1, n);
        }
        else
        {
            cout << query(1, 1, n, x, y) << '\n';
        }
    }
    return 0;
}