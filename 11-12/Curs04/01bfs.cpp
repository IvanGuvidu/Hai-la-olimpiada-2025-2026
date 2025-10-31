#include <bits/stdc++.h>

using namespace std;

const int max_size = 1e5 + 20, INF = 2e9 + 2;

vector <pair <int, int>> mc[max_size];
int d[max_size];
deque <pair <int, int>> dq;
 
void bfs01 ()
{
    while (!dq.empty())
    {
        int nod = dq.front().first, val = dq.front().second;
        dq.pop_front();
        if (val > d[nod]) // verificam daca mai avem nevoie sa procesam acest nod
        {
            continue;
        }
        for (auto f : mc[nod])
        {
            if (d[nod] + f.second < d[f.first])
            {
                d[f.first] = d[nod] + f.second;
                if (f.second == 0) // daca muchia are cost 0, o adaugam in fata cozii
                {          // astfel, procesam mai repede nodurile cu cost mic
                    dq.push_front({f.first, d[f.first]});
                }
                else // altfel, o adaugam la sfarsitul cozii pentru a fi procesata mai tarziu
                {
                    dq.push_back({f.first, d[f.first]});
                }
            }
        }
    }
}

int main ()
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
    bfs01();
}