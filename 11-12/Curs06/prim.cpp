#include <bits/stdc++.h>

using namespace std;

struct str
{
    int nod, cost;
    bool operator < (const str & aux) const
    {
        return cost > aux.cost;
    }
};

const int max_size = 2e5 + 20, INF = 2e9 + 2;

int d[max_size], ult[max_size], uz[max_size], sum;
vector <pair <int, int>> mc[max_size], apm;
priority_queue <str> pq;

void djk ()
{
    pq.push({1, 0});
    while (!pq.empty())
    {
        int nod = pq.top().nod, val = pq.top().cost;
        pq.pop();
        if (uz[nod] == 1)
        {
            continue;
        }
        sum += val;
        uz[nod] = 1;
        if (nod != 1)
        {
            apm.push_back({ult[nod], nod});
        }
        for (auto f : mc[nod])
        {
            if (uz[f.first] == 1)
            {
                continue;
            }
            if (f.second < d[f.first])
            {
                d[f.first] = f.second;
                ult[f.first] = nod;
                pq.push({f.first, d[f.first]});
            }
        }
    }
}

void solve ()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int x, y, c;
        cin >> x >> y >> c;
        mc[x].push_back({y, c});
        mc[y].push_back({x, c});
    }
    for (int i = 2; i <= n; i++)
    {
        d[i] = INF;
    }
    djk();
    cout << sum << '\n' << n - 1 << '\n';
    for (auto f : apm)
    {
        cout << f.first << " " << f.second << '\n';
    }
    cout << '\n';
}

signed main ()
{
#ifdef LOCAL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    freopen("apm.in", "r", stdin);
    freopen("apm.out", "w", stdout);
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