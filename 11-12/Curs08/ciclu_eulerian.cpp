#include <bits/stdc++.h>

using namespace std;

const int max_size = 1e5 + 20, max_mc = 5e5 + 20;

int uz[max_mc];
vector <pair <int, int>> mc[max_size];
stack <int> stk;
vector <int> ans;

void solve ()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        mc[x].push_back({y, i});
        mc[y].push_back({x, i});
    }
    for (int i = 1; i <= n; i++)
    {
        if (mc[i].size() % 2 == 1)
        {
            cout << -1;
            return;
        }
    }
    stk.push(1);
    for (int i = 1; i <= m; i++)
    {
        // aici ce se intampla este ca simulam dfs ul cu o stiva
        // aceasta abordare e mai memory friendly

        int nod = stk.top();
        while (!mc[nod].empty())
        {
            int urm = mc[nod].back().first, idx = mc[nod].back().second;
            mc[nod].pop_back();
            if (uz[idx] == 1)
            {
                continue;
            }
            uz[idx] = 1;
            stk.push(urm);
            nod = urm;
        }
        stk.pop();
        ans.push_back(nod);
    }
    for (auto f : ans)
    {
        cout << f << " ";
    }
    cout << '\n';
}

signed main ()
{
#ifdef LOCAL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    freopen("ciclueuler.in", "r", stdin);
    freopen("ciclueuler.out", "w", stdout);
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