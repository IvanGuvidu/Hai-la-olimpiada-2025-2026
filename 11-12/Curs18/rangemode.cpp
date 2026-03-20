#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

ifstream in ("rangemode.in");
ofstream out ("rangemode.out");

const int max_size = 1e5 + 1, sz = 316;

struct str{
    int l, r, idx;
    bool operator < (const str & aux) const
    {
        return r < aux.r;
    }
};

int v[max_size], frecv[max_size], rez[max_size];
vector <str> qr[sz + 7];

int main ()
{
    int n, q;
    in >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        in >> v[i];
    }
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        in >> x >> y;
        int bktnr = (x + sz - 1) / sz;
        qr[bktnr].push_back({x, y, i});
    }
    for (int i = 1; i <= sz; i++)
    {
        if (qr[i].empty())
        {
            continue;
        }
        sort(qr[i].begin(), qr[i].end());
        int stb = (i - 1) * sz + 1, drb = stb + sz - 1, prevans = 0, ultr = drb;
        for (auto f : qr[i])
        {
            int l = f.l, r = f.r, ans = prevans;
            for (int j = max(ultr + 1, drb + 1); j <= r; j++)
            {
                frecv[v[j]]++;
                if (frecv[v[j]] == frecv[ans])
                {
                    ans = min(ans, v[j]);
                    prevans = ans;
                }
                if (frecv[v[j]] > frecv[ans])
                {
                    ans = v[j];
                    prevans = ans;
                }
            }
            for (int j = l; j <= min(r, drb); j++)
            {
                frecv[v[j]]++;
                if (frecv[v[j]] == frecv[ans])
                {
                    ans = min(ans, v[j]);
                }
                if (frecv[v[j]] > frecv[ans])
                {
                    ans = v[j];
                }
            }
            rez[f.idx] = ans;
            ultr = r;
            for (int j = l; j <= min(r, drb); j++)
            {
                frecv[v[j]]--;
            }
        }
        for (int j = 1; j < max_size; j++)
        {
            frecv[j] = 0;
        }
    }
    for (int i = 1; i <= q; i++)
    {
        out << rez[i] << '\n';
    }
    in.close();
    out.close();
    return 0;
}