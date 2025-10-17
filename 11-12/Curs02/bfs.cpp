#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int maxN = 1e3 + 5;

int adj[maxN][maxN]; // Matrice de adiacență
queue <int> q;    // Coada pentru BFS
bool visited[maxN]; // Vector pentru a marca nodurile vizitate

void bfs (int start, int n)
{
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int nod = q.front();
        q.pop();

        // Explorăm toți vecinii nodului curent
        for (int i = 1; i <= n; i++)
        {
            // Dacă există muchie și nodul nu a fost vizitat
            if (adj[nod][i] == 1 && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main ()
{
    int n, m; // n = număr de noduri, m = număr de muchii
    cin >> n >> m;

    // Citirea muchiilor și completarea matricei de adiacență
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        adj[x][y] = 1;
        adj[y][x] = 1; // doar în cazul grafurilor NEORIENTATE
    }

    bfs(1, n); // vom porni BFS din nodul 1
    // în cazul în care graful nu este conex, putem apela bfs pentru fiecare nod nevizitat

    return 0;
}