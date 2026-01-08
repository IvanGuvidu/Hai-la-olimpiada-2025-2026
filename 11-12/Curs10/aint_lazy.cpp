#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
  
#pragma GCC optimize("O3") 
#pragma GCC optimize("unroll-loops") 
#pragma GCC target("avx2") 
 
using namespace std; 
using namespace __gnu_pbds; 
 
#define ordered_set tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> 
#define lsb(x) (x & (-x))
 
const int INF = 2e9 + 2, max_size = 2e5 + 20, max_seg = 8e5 + 20;
 
long long seg[max_seg], lazy[max_seg], v[max_size];
 
void init (int l, int r, int nod)
{
    if (l == r)
    {
        seg[nod] = v[l];
        return;
    }
    int m = (l + r) / 2;
    init(l, m, 2 * nod);
    init(m + 1, r, 2 * nod + 1);
}
 
void push (int l, int r, int nod)
{
    if (l != r)
    {
        seg[2 * nod] += lazy[nod];
        lazy[2 * nod] += lazy[nod];
        seg[2 * nod + 1] += lazy[nod];
        lazy[2 * nod + 1] += lazy[nod];
    }
    lazy[nod] = 0;
}
 
void upd (int l, int r, int st, int dr, long long val, int nod)
{
    if (st <= l && r <= dr)
    {
        seg[nod] += val;
        lazy[nod] += val;
        return;
    }
    push(l, r, nod);
    int m = (l + r) / 2;
    if (st <= m)
    {
        upd(l, m, st, dr, val, 2 * nod);
    }
    if (dr > m)
    {
        upd(m + 1, r, st, dr, val, 2 * nod + 1);
    }
}
 
long long query (int l, int r, int poz, int nod)
{
    if (l == r)
    {
        return seg[nod];
    }
    push(l, r, nod);
    int m = (l + r) / 2;
    if (poz <= m)
    {
        return query(l, m, poz, 2 * nod);
    }
    else
    {
        return query(m + 1, r, poz, 2 * nod + 1);
    }
}
 
void solve() 
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    init(1, n, 1);
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 2)
        {
            int x;
            cin >> x;
            cout << query(1, n, x, 1) << '\n';
        }
        else
        {
            long long x, y, val;
            cin >> x >> y >> val;
            upd(1, n, x, y, val, 1);
        }
    }
}
  
signed main() 
{ 
#ifdef LOCAL 
    freopen("test.in", "r", stdin); 
    freopen("test.out", "w", stdout); 
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