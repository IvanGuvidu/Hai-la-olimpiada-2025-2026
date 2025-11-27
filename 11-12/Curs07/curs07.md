# Range Minimum Query (RMQ), Lowest Common Ancestor (LCA), DP pe Arbori

## Range Minimum Query (RMQ)

Enunț problemă - [RMQ (infoarena)](https://infoarena.ro/problema/rmq)

Ideea problemei este să răspundem la queryuri de tipul: care este valoarea minimă dintr-un interval dat al unui vector?

O să folosim o structură de date care are forma unui arbore binar, unde fiecare nod va stoca valoarea minimă dintr-un anumit interval al vectorului inițial. Să presupunem următorul tablou:

$$
rmq[e][i] = \text{valoarea minimă din intervalul } [i, i + 2^e)
$$

Inițial, pentru $e = 0$, avem $rmq[0][i] = v[i]$.

Pentru a construi restul arborelui, vom folosi următoarea relație de recurență:

$$
rmq[e][i] = \min(rmq[e-1][i], rmq[e-1][i + 2^{e-1}])
$$

Adică, valoarea minimă din intervalul $[i, i + 2^e)$ este minimul dintre valorile minime din cele două jumătăți ale acestui interval.

Dacă avem un query pentru intervalul $[L, R)$, putem să îl împărțim în două intervale de lungime $2^k$, unde $k = \lfloor \log_2 (R - L) \rfloor$. Astfel, putem răspunde la query folosind următoarea formulă:

$$
ans = \min(rmq[k][L], rmq[k][R - 2^k])
$$

Complexitatea construirii arborelui este $O(N \log N)$, iar complexitatea fiecărui query este $O(1)$. O implementare a acestei structuri de date o găsiți în [`rmq.cpp`](rmq.cpp).

Această soluție poate fi extinsă și la 2D, detalii [Plantatie](https://infoarena.ro/problema/plantatie) și [Matrice3](https://infoarena.ro/problema/matrice3).


Tehnica de RMQ poate fi aplicată și pentru GCD pe intervale, vezi problema [Xcmmdc](https://infoarena.ro/problema/xcmmdc).

## Lowest Common Ancestor (LCA)

Enunț problemă - [LCA (infoarena)](https://infoarena.ro/problema/lca)

LCA propune să se găsească cel mai adânc strămoș comun al două noduri într-un arbore cu rădăcină fixată. Pentru această problemă avem 2 metode principale: **Binary Lifting** și **Euler Tour + RMQ**.

### 1. Binary Lifting

O să ținem următoarea structură:

$$
t[e][nod] = \text{strămoșul lui nod la distanța } 2^e
$$

Inițial, pentru $e = 0$, avem $t[0][nod] = \text{părintele lui nod}$.

Pentru a construi restul structurii, vom folosi următoarea relație de recurență:

$$
t[e][nod] = t[e-1][t[e-1][nod]]
$$

Astfel, pentru a găsi LCA dintre două noduri $u$ și $v$, vom ridica nodul mai adânc la același nivel cu celălalt nod, apoi vom urca ambele noduri în arbore până când ajung la strămoșul comun.

Această abordare are complexitate $O(N \log N)$ pentru preprocesare și $O(\log N)$ pentru fiecare query. O implementare a acestei metode o găsiți în [`binary_lifting.cpp`](binary_lifting.cpp).

Exemple de probleme rezolvate cu Binary Lifting: [Atac](https://infoarena.ro/problema/atac), [Radiatie](https://infoarena.ro/problema/radiatie)

### 2. Euler Tour + RMQ

O altă metodă pentru a găsi LCA este folosind liniarizarea Euler a arborelui și RMQ pe adâncimi. Liniarizarea Euler este o parcurgere DFS a arborelui care adaugă un nod:

* când este vizitat prima dată
* când se revine la el după vizitarea unui copil

Astfel, pentru fiecare nod, reținem prima poziție în care apare în această parcurgere și adâncimea sa. Pentru a găsi LCA dintre două noduri $u$ și $v$, căutăm minimul adâncimii în intervalul dintre primele apariții ale lui $u$ și $v$ în parcurgerea Euler. Acest minim se poate găsi eficient folosind RMQ.

Astfel, complexitatea preprocesării este $O(N)$ pentru parcurgerea Euler și $O(N \log N)$ pentru RMQ, iar fiecare query se rezolvă în $O(1)$. O implementare a acestei metode o găsiți în [`euler_rmq.cpp`](euler_rmq.cpp).

## DP pe Arbori

Foarte des o să întâlnim probleme de dinamică pe arbori. De obicei, aceste probleme pot fi rezolvate prin 2 parcurgeri DFS: una care calculează un răspuns parțial pentru fiecare nod în funcție de copiii săi, și alta care propagă informația de la părinte la copii pentru a obține răspunsul final. Această tehnică este cunoscută sub numele de "rerooting".

### Probleme

* [Tairos](https://kilonova.ro/problems/22)
* [Iepuri (OJI 2008)](https://kilonova.ro/problems/45)
* [Arbore (ONI 2016)](https://kilonova.ro/problems/188)
* [Asmin](https://infoarena.ro/problema/asmin)
* [CosGigMax](https://kilonova.ro/problems/569)

#### Cursul de azi a fost ținut de Ivan Andrei-Cristian.