#include <fstream>
#include <vector>
#include <stack>

using namespace std;

ifstream in ("biconex.in");
ofstream out ("biconex.out");

const int max_size = 1e5 + 1;

vector <int> mc[max_size];
int tin[max_size], tmin[max_size], viz[max_size];
vector <vector <int>> cbc;
stack <int> stiva;

void dfs (int nod, int par)
{
    viz[nod] = 1;
    tin[nod] = tin[par] + 1;
    tmin[nod] = tin[nod];
    stiva.push(nod);
    for (auto f : mc[nod])
    {
        if (f == par)
        {
            continue;
        }
        if (viz[f])
        {
            tmin[nod] = min(tmin[nod], tin[f]);
        }
        else
        {
            dfs(f, nod);
            tmin[nod] = min(tmin[nod], tmin[f]);
            if (tin[nod] <= tmin[f])
            {
                vector <int> aux;
                while (!stiva.empty() && stiva.top() != f)
                {
                    aux.push_back(stiva.top());
                    stiva.pop();
                }
                aux.push_back(f);
                aux.push_back(nod);
                stiva.pop();
                cbc.push_back(aux);
            }
        }
    }
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
        mc[y].push_back(x);
    }
    dfs(1, 0);
    out << cbc.size() << '\n';
    for (auto f : cbc)
    {
        for (auto ff : f)
        {
            out << ff << " ";
        }
        out << '\n';
    }
    in.close();
    out.close();
    return 0;
}