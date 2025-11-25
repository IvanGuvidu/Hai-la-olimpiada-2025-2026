# DP pe configurații, Exponentiere pe matrice

## DP pe configurații

Când avem un număr mic de elemente (de obicei $N \leq 20$), putem folosi **DP pe configurații**. Fiecare configurație poate fi reprezentată printr-un număr binar, unde fiecare bit reprezintă dacă un element este inclus sau nu în configurație. Astfel, putem defini o dinamică $dp[mask]$, unde `mask` este un număr binar care reprezintă o configurație. Valoarea $dp[mask]$ va reprezenta soluția pentru acea configurație.

### 1. Ciclul Hamiltonian de cost minim

Enunț problemă: [Ciclul Hamiltonian de cost minim - Infoarena](https://infoarena.ro/problema/hamilton)

Vom defini dinamica astfel:

$$dp[i][j] = \text{costul minim pentru a ajunge în nodul } j \text{ după ce am vizitat nodurile din configurația } i$$

Vom presupune că nodul de start este nodul $0$, deci inițial avem:

$$dp[1][0] = 0$$

$$dp[i][j] = \infty \text{ pentru toate celelalte valori}$$

Pentru ca starea $(i, j)$ să fie relevantă, trebuie ca bitul $j$ din configurația $i$ să fie setat (adică nodul $j$ să fie vizitat în configurația reprezentată de configurația $i$).

Pentru fiecare vecin $k$ al nodului $j$, dacă vecinul nu este inclus în configurația $i$, putem actualiza dinamica astfel:

$$dp[i \ | \  2^k][k] = \min(dp[i \ | \ 2^k][k], dp[i][j] + cost[j][k])$$

În final, va trebui să găsim costul minim pentru a reveni la nodul de start după ce am vizitat toate nodurile. Astfel, răspunsul final va fi:

$$\min_{0 < i < N} (dp[2^N - 1][i] + cost[i][0])$$

Complexitatea acestei soluții este $O(N^2 \cdot 2^N)$, unde $N$ este numărul de noduri din graf. O implementare a soluției o găsiți în [`hamilton.cpp`](hamilton.cpp).

După ce rezolvați această problemă, puteți încerca și [Ubuntzei](https://kilonova.ro/problems/40).

### 2. RecycleBin

Enunț problemă: [RecycleBin - Kilonova](https://kilonova.ro/problems/19)

Vom defini dinamica astfel:

$$dp[i][j] = \text{suma maximă dacă pe prefixul } 1 \dots i \text{ am făcut eliminările din configurația } j$$

Recurențele sunt:

$$dp[i][j] = dp[i-1][j] + v[i] \text{ , cazul în care alegem să nu facem nicio eliminare}$$

Pentru fiecare poziție din subsecvență, vom lua fiecare configurație posibilă de eliminări și vom actualiza dinamica astfel:

$$dp[i][j] = \max(dp[i][j], dp[i-2^k][2^k \oplus j]) \text{ , dacă } k \text{ nu este în } conf(j)$$

În final, răspunsul va fi în $dp[N][i]$ maxim, unde $0 \leq i < 2^N$. Astfel, complexitatea acestei soluții este $\approx O(N^2)$. O implementare a soluției o găsiți în [`recyclebin.cpp`](recyclebin.cpp).

## Exponentiere în timp logaritmic (pe matrice)

O problemă des întâlnită este când vrem să calculăm $a^b$ pentru valori mari ale lui $b$. O metodă eficientă de a face acest lucru este **exponentierea rapidă**. Ideea este să folosim faptul că $a^{b+c} = a^b \cdot a^c$. Astfel, putem scrie $b$ în baza $2$ și să calculăm puterile lui $a$ corespunzătoare biților din reprezentarea lui $b$. Astfel, complexitatea acestei metode este $O(\log b)$. O implementare a acestei metode o găsiți în [`lgput.cpp`](lgput.cpp). Puteți trimite soluții [aici](https://infoarena.ro/problema/lgput).

```cpp
int lgput (long long baza, long long ord)
{
    long long ans = 1;
    while (ord > 0)
    {
        if (ord % 2 == 1)
        {
            ans = (ans * baza) % mod;
        }
        baza = (baza * baza) % mod;
        ord /= 2;
    }
    return ans;
}
```

### Exponentiere pe matrice (al K-lea termen Fibonacci)

Enunț problemă: [KFib - Infoarena](https://infoarena.ro/problema/kfib)

Pentru a calcula al $K$-lea termen Fibonacci, putem folosi exponentierea pe matrice. Observăm următoarea relație:

$$
\begin{pmatrix} F_n & F_{n-1} \end{pmatrix} \cdot
\begin{pmatrix} 1 & 1 \\
1 & 0 \end{pmatrix} =
\begin{pmatrix} F_n + F_{n-1} & F_{n} \end{pmatrix} =
\begin{pmatrix} F_{n+1} & F_n \end{pmatrix}
$$

Astfel, putem observa că:

$$
\begin{pmatrix} F_n & F_{n-1} \end{pmatrix} \cdot
\begin{pmatrix} 1 & 1 \\
1 & 0 \end{pmatrix}^k =
\begin{pmatrix} F_{n+k} & F_{n+k-1} \end{pmatrix}
$$

Deci, pentru a calcula $F_k$, trebuie doar să ridicăm matricea la puterea $k-1$ și să înmulțim cu vectorul inițial. O implementare a acestei metode o găsiți în [`kfib.cpp`](kfib.cpp).

### Probleme suplimentare

* [Iepuri](https://infoarena.ro/problema/iepuri)
* [Ecu](https://infoarena.ro/problema/ecu)
* [2șah](https://infoarena.ro/problema/2sah)

#### Cursul de azi a fost ținut de Ivan Andrei-Cristian.
