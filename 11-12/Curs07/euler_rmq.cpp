#include <fstream>
#include <vector>

using namespace std;

ifstream in ("lca.in");
ofstream out ("lca.out");

const int max_size = 2e5 + 1, rmax = 19;

int rmq[rmax][max_size], lvl[max_size], lg[max_size], poz[max_size], lin[max_size], timp;
vector <int> mc[max_size];

void dfs (int nod, int par)
{
    ++timp;
    lvl[nod] = lvl[par] + 1;
    lin[timp] = nod;
    poz[nod] = timp;
    for (auto f : mc[nod])
    {
        dfs(f, nod);
        lin[++timp] = nod;
    }
}

bool cmp (int x, int y)
{
    return lvl[x] < lvl[y];
}

int main ()
{
    int n, q;
    in >> n >> q;
    for (int i = 2; i <= n; i++)
    {
        int x;
        in >> x;
        mc[x].push_back(i);
    }
    dfs(1, 0);
    for (int i = 1; i <= timp; i++)
    {
        rmq[0][i] = lin[i];
        if (i != 1)
        {
            lg[i] = lg[i / 2] + 1;
        }
    }
    for (int e = 1; (1 << e) <= timp; e++)
    {
        for (int i = 1; i + (1 << (e - 1)) - 1 <= timp; i++)
        {
            rmq[e][i] = min(rmq[e - 1][i], rmq[e - 1][i + (1 << (e - 1))], cmp);
        }
    }
    while (q--)
    {
        int x, y;
        in >> x >> y;
        x = poz[x];
        y = poz[y];
        if (x > y)
        {
            swap(x, y);
        }
        int e = lg[y - x + 1];
        out << min(rmq[e][x], rmq[e][y - (1 << e) + 1], cmp) << '\n';
    }
    in.close();
    out.close();
    return 0;
}