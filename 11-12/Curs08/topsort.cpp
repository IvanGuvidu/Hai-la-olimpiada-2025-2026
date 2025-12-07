#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream in ("sortaret.in");
ofstream out ("sortaret.out");

const int max_size = 5e4 + 1;

int viz[max_size];
vector <int> mc[max_size], topsort;

void dfs (int nod)
{
    viz[nod] = 1;
    for (auto f : mc[nod])
    {
        if (!viz[f])
        {
            dfs(f);
        }
    }
    topsort.push_back(nod);
}

int main ()
{
    int n, m;
    in >> n >> m;
    while (m--)
    {
        int x, y;
        in >> x >> y;
        mc[x].push_back(y);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!viz[i])
        {
            dfs(i);
        }
    }
    reverse(topsort.begin(), topsort.end());
    for (auto f : topsort)
    {
        out << f << " ";
    }
    in.close();
    out.close();
    return 0;
}