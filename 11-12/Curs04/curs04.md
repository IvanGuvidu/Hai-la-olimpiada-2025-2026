# Dijkstra, 0-1 BFS, Roy-Floyd

Astăzi vom aborda cum tratăm o clasă specială de grafuri - cele cu muchii ponderate. Vom vedea trei algoritmi diferiți pentru a găsi cel mai scurt drum într-un astfel de graf: algoritmul lui Dijkstra, 0-1 BFS și algoritmul Roy-Floyd. Similar cu BFS / DFS, acești algoritmi sunt aplicați pe diferite tipuri de grafuri și au complexități diferite în funcție de structura datelor folosite.

## Dijkstra

Să presupunem următoarea problemă: avem un graf neorientat cu $N$ noduri și $M$ muchii, fiecare muchie având un cost **pozitiv** (pentru muchii negative vom vedea într-un alt curs cum putem rezolva problema). Trebuie să găsim cel mai scurt drum de la un nod sursă $S$ la toate celelalte noduri din graf.

O abordare banală ar fi să folosim un fel de BFS modificat, unde pentru fiecare nod vizitat, actualizăm distanțele către vecinii săi. Totuși, această abordare nu este eficientă pentru grafuri cu muchii ponderate.

Algoritmul lui Dijkstra se va folosi de următoarea euristică: vom folosi un min-heap (un `priority_queue` în C++) pentru a păstra nodurile de procesat, ordonate după distanța minimă cunoscută până în acel moment. La fiecare pas, vom extrage nodul cu distanța minimă și vom actualiza distanțele către vecinii săi. Astfel, vom asigura că fiecare nod este procesat o singură dată cu distanța minimă corectă. Astfel, complexitatea algoritmului este $O((N + M) \log N)$.

O implementare a algoritmului o găsiți în [`dijkstra.cpp`](dijkstra.cpp).

```cpp
struct str{ // vom folosi această structură pentru a putea defini relația de ordine în pq
    int nod, cost;
    bool operator < (const str & aux) const
    {
        return cost > aux.cost;
    }
};

int d[max_size]; // d[i] = distanța minimă de la sursă la nodul i
vector <pair <int, int>> mc[max_size];
priority_queue <str> pq; // min-heap pentru a păstra nodurile de procesat

void djk ()
{
    pq.push({1, 0}); // presupunem că sursa este nodul 1 și distanța până la el este 0
    while (!pq.empty())
    {
        int nod = pq.top().nod, cost = pq.top().cost;
        pq.pop();
        if (cost > d[nod]) // e posibil să avem de mai multe ori același nod în pq, dar cu costuri diferite
        {                  // deci ne asigurăm că procesăm doar cel mai mic cost
            continue;
        }
        for (auto f : mc[nod])
        {
            if (d[nod] + f.second < d[f.first]) // actualizăm distanța dacă am găsit un drum mai scurt
            {
                d[f.first] = d[nod] + f.second;
                pq.push({f.first, d[f.first]});
            }
        }
    }
}
```

## 0-1 BFS

Un caz particular al grafurilor ponderate este atunci când toate muchiile au costul fie $0$, fie $1$. În acest caz, putem folosi o variantă a BFS-ului numită $\text{0-1 BFS}$. Algoritmul folosește o coadă dublă (`deque` în C++) pentru a procesa nodurile. Când întâlnim o muchie cu cost $0$, adăugăm nodul la începutul cozii, iar pentru o muchie cu cost $1$, adăugăm nodul la sfârșitul cozii. Astfel, ne asigurăm că nodurile cu cost mai mic sunt procesate primele. Astfel, complexitatea acestui algoritm este $O(N + M)$.

O implementare a algoritmului o găsiți în [`01bfs.cpp`](01bfs.cpp).

```cpp
deque <pair <int, int>> dq;
 
void bfs01 ()
{
    while (!dq.empty())
    {
        int nod = dq.front().first, val = dq.front().second;
        dq.pop_front();
        if (val > d[nod]) // verificăm dacă mai avem nevoie să procesăm acest nod
        {
            continue;
        }
        for (auto f : mc[nod])
        {
            if (d[nod] + f.second < d[f.first])
            {
                d[f.first] = d[nod] + f.second;
                if (f.second == 0) // dacă muchia are cost 0, o adăugăm în fața cozii
                {          // astfel, procesăm mai repede nodurile cu cost mic
                    dq.push_front({f.first, d[f.first]});
                }
                else // altfel, o adăugăm la sfârșitul cozii pentru a fi procesată mai târziu
                {
                    dq.push_back({f.first, d[f.first]});
                }
            }
        }
    }
}
```

## Roy-Floyd

Similar ca la DFS / BFS, nu este mereu optim să aplicăm Dijkstra pentru a afla cel mai scurt drum. Ce se întâmplă dacă avem mai multe query-uri?

Dacă avem un graf relativ mic ($N \leq 500$), putem folosi algoritmul Roy-Floyd pentru a găsi cel mai scurt drum între toate perechile de noduri. Algoritmul se bazează pe o matrice de adiacență, unde `a[i][j]` reprezintă costul muchiei dintre nodurile $i$ și $j$. Dacă nu există o muchie directă, vom folosi valoarea $0$ pentru a indica acest lucru. Algoritmul parcurge toate nodurile intermediare și actualizează matricea de distanțe, astfel încât `a[i][j]` va conține costul minim pentru a ajunge de la nodul $i$ la nodul $j$ prin orice nod intermediar. Complexitatea acestui algoritm este $O(N^3)$. Astfel, pentru a răspunde la mai multe întrebări de forma "care este cel mai scurt drum între nodurile $u$ și $v$?", vom putea răspunde în timp constant $O(1)$.

O implementare a algoritmului o găsiți în [`royfloyd.cpp`](royfloyd.cpp).

```cpp
void rf ()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (a[i][k] > 0 && a[k][j] > 0 && (a[i][j] > a[i][k] + a[k][j] || a[i][j] == 0) && i != j)
                {
                    a[i][j] = a[i][k] + a[k][j];
                }
            }
        }
    }
}
```

## Probleme

* [Dijkstra - Infoarena](https://infoarena.ro/problema/dijkstra)
* [Roy-Floyd - Infoarena](https://infoarena.ro/problema/royfloyd)
* [Catun](https://www.infoarena.ro/problema/catun)
* [Patrol2](https://kilonova.ro/problems/362)
* [Dragoni](https://kilonova.ro/problems/32)
* [Ateleport](https://kilonova.ro/problems/17)
* [Rover](https://kilonova.ro/problems/888)
* [1941G](https://codeforces.com/contest/1941/problem/G)
* [AzugAND](https://kilonova.ro/problems/3305)

#### Cursul de azi a fost ținut de Ivan Andrei-Cristian.