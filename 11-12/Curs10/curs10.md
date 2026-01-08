
# Arbori de intervale, arbori indexați binar


## Arbori de intervale


Arborele de intervale este o structură de date bazată pe arbori binari, care permite actualizarea și interogarea eficientă a unui set de intervale. Fiecare nod al arborelui reprezintă un interval și conține informații despre intervalul respectiv. În principiu, arborele de intervale este folosit pentru a rezolva probleme unde update-urile și query-urile pot fi intercalate (contrar cu șmecheria lui Mars, unde acolo rezolvăm întrebările obligatoriu după procesarea tuturor update-urilor).


Un nod al arborelui de intervale conține următoarele informații:
- Intervalul reprezentat de nod (de exemplu, $[l, r]$)
- Valoarea asociată intervalului (de exemplu, suma, minimul, maximul elementelor din interval)


De obicei, dacă indexul nodului este $x$, atunci fiul stâng are indexul $2x$, iar fiul drept are indexul $2x + 1$. O limită superioară pentru numărul de noduri este $4N$, unde $N$ este numărul de elemente din vectorul inițial. Fie $m = (l + r) / 2$. Atunci, fiul stâng al nodului $x$ va reprezenta intervalul $[l, m]$, iar fiul drept va reprezenta intervalul $[m + 1, r]$. Când ajungem la un nod care are $l = r$, înseamnă că am ajuns la o frunză, care reprezintă un singur element din vectorul inițial.

<p align="center">
  <img src="https://en.algorithmica.org/hpc/data-structures/img/segtree-path.png" alt="Segment Tree Path">
</p>


Când dorim să procesăm un update / query pentru un interval $[a, b]$, pornim de la rădăcina arborelui, care reprezintă întregul interval $[1, N]$. Dacă intervalul nodului curent este complet inclus în $[a, b]$, atunci putem actualiza / returna valoarea nodului curent. Dacă intervalul nodului curent nu se intersectează cu $[a, b]$, atunci nu facem nimic. În caz contrar, continuăm să parcurgem arborele recursiv pentru fiii stâng și drept ai nodului curent. Cum lungimea intervalelor se înjumătățește la fiecare pas, complexitatea unei operații de update / query este $O(\log N)$.


Mai jos, atașez o sursă care rezolvă suma pe intervale folosind un arbore de intervale:

```cpp
const int max_aint = 8e5 + 1, max_size = 2e5 + 1;
 
long long aint[max_aint], a[max_size];
 
void init (int nod, int l, int r)
{
    if (l == r)
    {
        aint[nod] = a[l];
        return;
    }
    int m = (l + r) / 2;
    init(2 * nod, l, m);
    init(2 * nod + 1, m + 1, r);
    aint[nod] = aint[2 * nod + 1] + aint[2 * nod];
}
 
void update (int val, int poz, int nod, int l, int r)
{
    if (l == r)
    {
        aint[nod] = val;
        return;
    }
    int m = (l + r) / 2;
    if (poz <= m)
    {
        update(val, poz, 2 * nod, l, m);
    }
    else
    {
        update(val, poz, 2 * nod + 1, m + 1, r);
    }
    aint[nod] = aint[2 * nod + 1] + aint[2 * nod];
}
 
long long query (int nod, int l, int r, int st, int dr)
{
    if (st <= l && r <= dr)
    {
        return aint[nod];
    }
    int m = (l + r) / 2;
    long long p1 = 0, p2 = 0;
    if (st <= m)
    {
        p1 = query(2 * nod, l, m, st, dr);
    }
    if (dr > m)
    {
        p2 = query(2 * nod + 1, m + 1, r, st, dr);
    }
    return p1 + p2;

...

    int op, x, y;
    cin >> op >> x >> y;
    if (op == 1)
    {
        update(y, x, 1, 1, n);
    }
    else
    {
        cout << query(1, 1, n, x, y) << '\n';
    }
}
```


Arborii de intervale pot fi folosiți pentru a rezolva o varietate de probleme, cum ar fi: suma pe interval, minimul / maximul pe interval, gcd etc. Go crazy!


## Arbori indexați binar


Varianta mai simplă a arborilor de intervale **dar cu restrângeri** este arborele indexat binar (Fenwick Tree). Acesta permite doar operații de tipul _update pe o poziție_ și _query pe prefix_. Complexitatea fiecărei operații este $O(\log N)$, iar implementarea este mai simplă decât cea a arborilor de intervale.


Vom nota $lsb(x) = x \& (-x)$, adică cel mai din dreapta (puțin semnificativ) bit setat al lui $x$. De exemplu, $lsb(12) = lsb(1100_2) = 4$.


Fiecare nod din AIB reprezintă suma unui interval de lungime $lsb(index\_nod)$. Mai exact, nodul cu indexul $x$ reprezintă suma elementelor din intervalul $[x - lsb(x) + 1, x]$.

<p align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/7/70/16-node_Fenwick_tree.svg/2560px-16-node_Fenwick_tree.svg.png">
</p>


Strategia de folosire a AIB-ului este următoarea: vom încerca să ne scriem query-urile pe un interval $[a, b]$ ca diferență între două query-uri pe prefixe: $query(b) - query(a - 1)$. Astfel, vom implementa doar operația de query pe prefix și operația de update pe o poziție. Când actualizăm o poziție $pos$ cu o valoare $val$, vom parcurge AIB-ul adăugând $val$ la toate nodurile care includ poziția $pos$ în intervalul lor. Când interogăm prefixul $[1, pos]$, vom parcurge AIB-ul adunând valorile din nodurile care acoperă acest prefix. La fiecare pas, ne vom deplasa cu $lsb(index\_nod)$ pentru a ajunge la următorul nod relevant. Astfel, complexitatea fiecărei operații rămâne $O(\log N)$.


Mai jos, atașez o sursă care rezolvă suma pe intervale folosind un arbore indexat binar:

```cpp
#define lsb(x)(x & (-x))

const int max_size = 1e5 + 1;

int aib[max_size], n;

void upd (int poz, int val)
{
    for (int i = poz; i <= n; i += lsb(i))
    {
        aib[i] += val;
    }
}

int query (int poz)
{
    int ans = 0;
    for (int i = poz; i > 0; i -= lsb(i))
    {
        ans += aib[i];
    }
    return ans;
}
...

    if (op == 0)
    {
        int x, y;
        in >> x >> y;
        upd(x, y);
    }
    if (op == 1)
    {
        int x, y;
        in >> x >> y;
        out << query(y) - query(x - 1) << '\n';
    }
```


**Atenție!!** AIB-urile nu pot fi adaptate pentru update-uri pe interval, sau operații mai complexe (minim, maxim, gcd). De asemenea, dacă încercați să folosiți AIB în loc de AINT în unele tipuri de probleme, vă puteți trezi cu complexitate $log^2 N$ în loc de $log N$. Vom vedea astfel de cazuri în problemele viitoare.


## Update-uri pe interval, AINT cu Lazy Propagation


Uneori, ni se va cere să facem update-uri pe intervale, nu doar pe poziții individuale. În acest caz, putem folosi o tehnică numită _lazy propagation_ pentru a îmbunătăți eficiența arborelui de intervale. Ideea principală este să amânăm actualizarea nodurilor până când este absolut necesar să le accesăm. Pentru fiecare nod, vom păstra o valoare suplimentară care indică dacă nodul are o actualizare _în așteptare_. Când accesăm un nod, vom aplica actualizarea în așteptare și vom propaga actualizarea către fiii săi, dacă este necesar.

```cpp
const int max_size = 2e5 + 20, max_seg = 8e5 + 20;
 
long long seg[max_seg], lazy[max_seg], v[max_size];
 
void init (int l, int r, int nod)
{
    if (l == r)
    {
        seg[nod] = v[l];
        return;
    }
    int m = (l + r) / 2;
    init(l, m, 2 * nod);
    init(m + 1, r, 2 * nod + 1);
}
 
void push (int l, int r, int nod)
{
    if (l != r)
    {
        seg[2 * nod] += lazy[nod];
        lazy[2 * nod] += lazy[nod];
        seg[2 * nod + 1] += lazy[nod];
        lazy[2 * nod + 1] += lazy[nod];
    }
    lazy[nod] = 0;
}
 
void upd (int l, int r, int st, int dr, long long val, int nod)
{
    if (st <= l && r <= dr)
    {
        seg[nod] += val;
        lazy[nod] += val;
        return;
    }
    push(l, r, nod);
    int m = (l + r) / 2;
    if (st <= m)
    {
        upd(l, m, st, dr, val, 2 * nod);
    }
    if (dr > m)
    {
        upd(m + 1, r, st, dr, val, 2 * nod + 1);
    }
}
 
long long query (int l, int r, int poz, int nod)
{
    if (l == r)
    {
        return seg[nod];
    }
    push(l, r, nod);
    int m = (l + r) / 2;
    if (poz <= m)
    {
        return query(l, m, poz, 2 * nod);
    }
    else
    {
        return query(m + 1, r, poz, 2 * nod + 1);
    }
}
```


Observați că în rest funcțiile de update și query rămân identice, doar adăugăm câte un apel de `push()` la începutul fiecărei funcții. Funcția `push()` se ocupă de aplicarea actualizării în așteptare și propagarea acesteia către fiii nodului curent. Astfel, putem face update-uri pe intervale și interogări pe poziții individuale în timp $O(\log N)$.


## Resurse și probleme


* [Segment tree - CPAlgorithms](https://cp-algorithms.com/data_structures/segment_tree.html)
* [Arbint - Infoarena](https://infoarena.ro/problema/arbint)
* [Aib - Infoarena](https://infoarena.ro/problema/aib)
* [Range update queries - CSES](https://cses.fi/problemset/task/1651)
* [Schi - Infoarena](https://infoarena.ro/problema/schi)
* [Maxq - Infoarena](https://infoarena.ro/problema/maxq)
* [Hotel - Infoarena](https://infoarena.ro/problema/hotel)
* [Order - Infoarena](https://infoarena.ro/problema/order)
* [Namlei - Infoarena](https://infoarena.ro/problema/namlei)
* [Connect the tree - Kilonova](https://kilonova.ro/problems/970)
* [Lexicografic - Kilonova](https://kilonova.ro/problems/7)

#### Cursul de azi a fost ținut de Ivan Andrei-Cristian.