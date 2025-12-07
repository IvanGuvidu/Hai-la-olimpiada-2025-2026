# Bellman Ford, Ciclu Eulerian, Sortare Topologică, Componente Tare Conexe

## Bellman-Ford

Problema principală de la Dijkstra este că nu funcționează corect în prezența muchiilor de cost negativ. Algoritmul **Bellman-Ford** rezolvă această problemă, având complexitatea $O(N \cdot M)$, unde $N$ este numărul de noduri și $M$ este numărul de muchii. Bellman-Ford poate detecta și cicluri negative, dacă ajungem să vizităm un nod de mai multe ori (de obicei de $N + 1$ ori).

Puteți trimite surse [aici](https://infoarena.ro/problema/bellmanford). O implementare a acestui algoritm o găsiți în [`bellman_ford.cpp`](bellman_ford.cpp).

## Ciclu Eulerian

Un **ciclu eulerian** este un ciclu care trece prin fiecare muchie a unui graf o singură dată. Problema găsirii unui ciclu eulerian o vom rezolva pe multigrafuri (grafuri care pot avea muchii multiple între două noduri).

Ideal, ar fi dacă am intra într-un nod pe o muchie _de intrare_ și am ieși pe o muchie _de ieșire_. Astfel, pentru a exista un ciclu eulerian într-un graf neorientat, toate nodurile trebuie să aibă grad par.

De aceea, doar putem face o parcurgere DFS a grafului, iar de fiecare dată când ajungem într-un nod, continuăm pe o muchie nevizitată până când nu mai avem unde să mergem.

Puteți trimite surse [aici](https://infoarena.ro/problema/ciclueuler). O implementare a acestui algoritm o găsiți în [`ciclu_eulerian.cpp`](ciclu_eulerian.cpp).

## Sortare Topologică

**Sortarea topologică** este o ordonare a nodurilor unui graf orientat aciclic (DAG) astfel încât pentru fiecare muchie $(u, v)$, nodul $u$ să apară înaintea nodului $v$ în ordonare.

Pentru a realiza sortarea topologică, putem folosi o parcurgere DFS a grafului. În timpul parcurgerii, după ce am vizitat toți copiii unui nod, adăugăm nodul curent într-un vector. La final, inversăm vectorul și obținem ordinea topologică.

Puteți trimite surse [aici](https://infoarena.ro/problema/sortaret). O implementare a acestui algoritm o găsiți în [`topsort.cpp`](topsort.cpp).

## Componente Tare Conexe (CTC)

O **componentă tare conexă** într-un graf orientat este un subgraf în care există un drum între orice două noduri. Pentru a găsi toate componentele tare conexe ale unui graf, putem folosi algoritmul lui Kosaraju sau algoritmul lui Tarjan (pe care îl vom studia când vom discuta despre componente biconexe).

Kosaraju pleacă de la sortarea topologică a grafului inițial, apoi parcurge graful transpus (cu muchiile inversate) în ordinea sortării topologice, marcând nodurile vizitate ca aparținând aceleiași componente tare conexe. Astfel, complexitatea algoritmului este $O(N + M)$.

O proprietate foarte importantă a CTC-urilor este, dacă facem un graf nou în care fiecare CTC este un nod, atunci acest graf este un DAG (graf orientat aciclic).

Puteți trimite surse [aici](https://infoarena.ro/problema/ctc). O implementare a acestui algoritm o găsiți în [`ctc.cpp`](ctc.cpp).

## Probleme

* [Ciclu](https://infoarena.ro/problema/ciclu)
* [Johnie](https://infoarena.ro/problema/johnie)
* [Domino](https://infoarena.ro/problema/domino)
* [Cartite](https://infoarena.ro/problema/cartite)
* [Fotbal](https://infoarena.ro/problema/fotbal2)
* [Project Management](https://infoarena.ro/problema/pm2)
* [Drumuri](https://infoarena.ro/problema/drumuri5)

#### Cursul de azi a fost ținut de Ivan Andrei-Cristian.