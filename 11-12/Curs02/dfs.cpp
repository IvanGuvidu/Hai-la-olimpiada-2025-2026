#include <iostream>
#include <vector>

using namespace std;

const int maxN = 1e5 + 5;

vector <int> muchii[maxN]; // listele de adiacență
bool vizitat[maxN];      // vector pentru a marca nodurile vizitate

void dfs (int nod)
{
    vizitat[nod] = true;
    for (auto vecin : muchii[nod]) // cu aceasta buclă iterăm prin toți vecinii nodului curent
    {
        if (!vizitat[vecin])
        {
            dfs(vecin);
        }
    }
}

int main ()
{
    int n, m; // n = număr de noduri, m = număr de muchii
    cin >> n >> m;

    // citirea muchiilor
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        muchii[x].push_back(y);
        muchii[y].push_back(x); // doar în cazul grafurilor NEORIENTATE
    }

    // Exemplu de parcurgere DFS
    for (int i = 1; i <= n; i++)
    {
        if (!vizitat[i])
        {
            dfs(i);
        }
    }
    return 0;
}