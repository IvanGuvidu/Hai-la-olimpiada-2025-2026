#include <bits/stdc++.h>

using namespace std;

const long long max_size = 12e4 + 20;

pair <double, double> v[max_size];

double arie (pair <double, double> x, pair <double, double> y, pair <double, double> z)
{
    return x.first * (y.second - z.second) + y.first * (z.second - x.second) + z.first * (x.second - y.second);
}

void solve ()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    sort(v + 1, v + n + 1);
    vector <int> sus, jos;
    for (int i = 1; i <= n; i++)
    {
        while (sus.size() > 1 && arie(v[sus[sus.size() - 2]], v[sus[sus.size() - 1]], v[i]) >= 0)
        {
            sus.pop_back();
        }
        while (jos.size() > 1 && arie(v[jos[jos.size() - 2]], v[jos[jos.size() - 1]], v[i]) <= 0)
        {
            jos.pop_back();
        }
        sus.push_back(i);
        jos.push_back(i);
    }
    vector <int> ans;
    for (auto f : jos)
    {
        ans.push_back(f);
    }
    sus.pop_back();
    reverse(sus.begin(), sus.end());
    sus.pop_back();
    for (auto f : sus)
    {
        ans.push_back(f);
    }
    cout << ans.size() << '\n';
    cout << fixed << setprecision(6);
    for (auto f : ans)
    {
        cout << v[f].first << " " << v[f].second << '\n';
    }
    cout << '\n';
}

signed main ()
{
#ifdef LOCAL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    freopen("infasuratoare.in", "r", stdin);
    freopen("infasuratoare.out", "w", stdout);
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