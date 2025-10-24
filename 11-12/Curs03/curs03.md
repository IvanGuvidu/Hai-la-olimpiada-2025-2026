# Programare dinamică

Programarea dinamică (în engleză Dynamic Programming - dp) presupune rezolvarea problemelor care pot fi împărțite în subprobleme mai mici, care se suprapun. Această tehnică este folosită pentru a optimiza algoritmii recursivi, evitând recalcularea rezultatelor pentru aceleași subprobleme. O să înțelegem acest concept astăzi prin câteva exemple introductive.

## Cum structurăm o soluție dp?

1. Definim stările dinamicii - adică ce reprezintă fiecare poziție din tabelul dp.
2. Definim condițiile inițiale - adică valorile de bază pentru stările dp.
3. Definim relația de recurență - adică cum putem calcula valoarea unei stări dp folosind alte stări dp.

## 1. Numărul de drumuri într-un grid

Enunț problemă: [Cladire #392 - Pbinfo](https://www.pbinfo.ro/probleme/392/cladire)

Această problemă este cel mai standard exemplu de dp. Să presupunem următoarea dinamică:

$$
dp[i][j] = \text{numărul de moduri de a ajunge în poziția } (i, j) \text{ din poziția } (1, 1).
$$

Astfel, condițiile inițiale sunt: $dp[1][1] = 1$ (există un singur mod de a fi în poziția inițială - să fii deja acolo). Relația de recurență este:

$$
dp[i][j] = dp[i-1][j] + dp[i][j-1]
$$

Totuși, de ce arată recurența așa? Păi dacă suntem în starea $(i, j)$, asta înseamnă că am venit fie din starea $(i-1, j)$ (adică de sus), fie din starea $(i, j-1)$ (adică din stânga). Astfel, numărul total de moduri de a ajunge în starea $(i, j)$ este suma modurilor de a ajunge în cele două stări precedente.

În final, rezultatul final se va afla în $dp[n][m]$, unde $n$ și $m$ sunt dimensiunile gridului.

O implementare a soluției o găsiți în [`cladire.cpp`](cladire.cpp).

## 2. Dice combinations

Enunț problemă: [Dice Combinations - CSES](https://cses.fi/problemset/task/1633)

Să presupunem următoarea dinamică:

$$
dp[i] = \text{numărul de moduri de a obține suma } i
$$

Inițial, vom considera că există un singur mod de a obține suma 0, și anume să nu aruncăm deloc zarurile ($dp[0] = 1$). Relația de recurență este:

$$
dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4] + dp[i-5] + dp[i-6]
$$

Această relație se bazează pe faptul că pentru a obține suma $i$, putem ajunge acolo aruncând un zar care arată 1, 2, 3, 4, 5 sau 6. Astfel, numărul de moduri de a obține suma $i$ este suma modurilor de a obține sumele $i-1$, $i-2$, $i-3$, $i-4$, $i-5$ și $i-6$.

Rezultatul final se va afla în $dp[n]$, unde $n$ este suma țintă. O implementare a soluției o găsiți în [`dice_combinations.cpp`](dice_combinations.cpp).

## 3. Coin combinations I și II

Enunț problemă: [Coin Combinations I - CSES](https://cses.fi/problemset/task/1635) și [Coin Combinations II - CSES](https://cses.fi/problemset/task/1636)

Prima problemă se rezolvă similar cu precedenta: putem face o dinamică în care pentru starea i ne obținem răspunsul din stările $i - y$ unde $y$ este fiecare dintre valorile monedelor. Obținem o dinamică care se construiește în $O(N \cdot X)$ unde $N$ este numărul de monede și $X$ este suma țintă.

Problema însă la această soluție este că ea nu ține cont de ordinea în care sunt folosite monedele. Astfel, pentru a extinde soluția precedentă la a doua problemă vom folosi următoarea dinamică:

$$
dp[i][j] = \text{numărul de moduri de a obține suma } i \text{ cu primele j monede}
$$

În acest mod, vom preveni folosirea monedelor în ordine diferită, deoarece vom considera doar primele j monede pentru a obține suma i.

Relația de recurență va fi:

$$
dp[i][j] = dp[i][j-1] + dp[i - value[j]][j - 1]
$$

Astfel, obținem complexitate $O(N \cdot X)$ unde $N$ este numărul de monede și $X$ este suma țintă. Răspunsul final se va afla în $dp[X][N]$. Soluția la a doua problemă o găsiți în [`coin_combinations_2.cpp`](coin_combinations_2.cpp).

## 4. Subșir crescător maximal (Longest increasing Subsequence - LIS)

Enunț problemă: [Subșir crescător maximal - Infoarena](https://infoarena.ro/problema/scmax)

Să considerăm următoarea dinamică:

$$
dp[i] = \text{lungimea celui mai lung subșir crescător care se termină la poziția } i
$$

Recurența este un pic mai complexă, deoarece nu mai putem formula o recurență simplă. Vom construi următorul tablou:

$$
best[i] = \text{cel mai mic element care poate încheia un subșir crescător de lungime } i
$$

Inițial, vom avea $best[0] = 0$ și toate celelalte valori vor fi setate la infinit. Pentru fiecare element din șirul nostru, vom găsi poziția sa în tabloul best folosind căutare binară și vom actualiza best corespunzător. Fie $poz$ poziția găsită, atunci vom face:

$$
best[poz + 1] = \min(best[poz + 1], v[i]) \\
dp[i] = poz + 1
$$

Astfel, complexitatea acestei soluții este $O(N \log N)$ datorită căutării binare pentru fiecare element din șir. Răspunsul final va fi lungimea maximă din tabloul dp. O implementare a soluției o găsiți în [`lis.cpp`](lis.cpp).


## 5. Problema rucsacului

Enunț problemă: [Problema rucsacului - Infoarena](https://infoarena.ro/problema/rucsac)

Să presupunem următoarea dinamică:

$$
dp[i] = \text{valoarea maximă care poate fi obținută cu o capacitate de } i
$$

Relația de recurență este:

$$
dp[i] = \max(dp[i], dp[i - weight[j]] + value[j])
$$

**Atenție!!** Până aici dinamica pare destul de inocentă, dar o implementare naivă unde, pentru fiecare element, iterăm crescător prin toate greutățile posibile va duce la o soluție incorectă. Acest lucru se întâmplă deoarece, în acest fel, putem folosi același element de mai multe ori. Pentru a preveni acest lucru, trebuie să iterăm **descrescător** prin greutăți atunci când procesăm fiecare element. Astfel, ne asigurăm că fiecare element este folosit o singură dată.


Astfel, complexitatea acestei soluții este $O(N \cdot G)$, unde $N$ este numărul de elemente și $G$ este capacitatea rucsacului. Răspunsul final se va afla în dinamica maximă. O implementare a soluției o găsiți în [`rucsac.cpp`](rucsac.cpp).

## 6. Birocrație (OJI 2024)

Enunț problemă: [Birocrație - OJI 2024](https://kilonova.ro/problems/2507)

Trebuie să găsim cum putem maximiza costul drumului prin matrice. Prima dilemă a problemei este cum putem să găsim un sens de parcurgere a dinamicii, astfel încât să nu avem dependențe circulare. Observăm că nu putem merge înapoi pe diagonala secundară, deci putem parcurge dinamica în ordinea crescătoare a sumei indicilor $i + j$ (de această relație depinde fiecare diagonală secundară).

Astfel, putem defini următoarele dinamici:

$$
dp1[i][j] = \text{costul maxim pentru a ajunge în poziția } (i, j) \text{ din dreapta sus} \\
dp2[i][j] = \text{costul maxim pentru a ajunge în poziția } (i, j) \text{ din stânga jos} \\
dp[i][j] = \text{costul maxim pentru a ajunge în poziția } (i, j)
$$

Relațiile de recurență sunt:

$$
dp1[i][j] = \max(dp1[i-1][j + 1], dp[i - 1][j-1]) + a[i][j] \\
dp2[i][j] = \max(dp2[i + 1][j - 1], dp[i - 1][j - 1]) + a[i][j] \\
dp[i][j] = \max(dp1[i][j], \ dp2[i][j])
$$

Astfel, complexitatea acestei soluții este $O(N^2)$. Răspunsul final se va afla în $dp[N][N]$.

#### Cursul de azi a fost ținut de Ivan Andrei-Cristian.
