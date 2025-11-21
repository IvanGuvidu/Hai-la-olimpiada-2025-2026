# Păduri de Mulțimi Disjuncte, Arbore parțial de cost minim

## Păduri de Mulțimi Disjuncte (Disjoint Set Union - DSU)

Pădurile de mulțimi disjuncte sunt o structură de date care permite gestionarea unui set de elemente împărțite în mai multe mulțimi disjuncte. Aceasta oferă două operații principale:

* $\text{root(X)}$ - găsirea rădăcinii mulțimii în care se află nodul $X$
* $\text{union(X, Y)}$ - unirea mulțimii în care se află nodurile $X$ și $Y$.

Pentru a optimiza aceste operații, se folosesc două tehnici:

* **Path Compression** - în timpul operației de găsire a rădăcinii, se face compresia drumului pentru a reduce adâncimea arborelui.
* **Union by Rank/Size** - în timpul unirii a două mulțimi, se atașează arborele cu adâncimea mai mică la rădăcina arborelui cu adâncimea mai mare. (această tehnică mai poate fi întâlnită și sub denumirea de _Small to Large_, când se unesc două mulțimi în funcție de mărimea lor).

În general, vom folosi doar Path Compression, Small to Large folosindu-l doar când facem operații de forma: vrem să mutăm toate elementele dintr-un `set` într-altul.

Datorită acestor optimizări, complexitatea acestor două operații este aproape $O(1)$.

O implementare a acestei structuri de date o găsiți în [`dsu.cpp`](dsu.cpp). Puteți trimite soluții [aici](https://infoarena.ro/problema/disjoint).

## Arbore parțial de cost minim (Minimum Spanning Tree - MST)

Un APM este un subgraf al unui graf neorientat ponderat care conectează toate nodurile cu cost minim și fără cicluri. Doi dintre cei mai cunoscuți algoritmi pentru găsirea APM sunt:

* **Kruskal**
* **Prim**

### 1. Algoritmul lui Kruskal

Algoritmul lui Kruskal sortează toate muchiile grafului în ordine crescătoare a costurilor și adaugă muchiile în APM, evitând formarea ciclurilor, până când toate nodurile sunt conectate. Pentru a verifica dacă adăugarea unei muchii formează un ciclu, se folosește DSU. Astfel, complexitatea acestui algoritm este $O(M \log M)$, unde $M$ este numărul de muchii din graf. O implementare a acestui algoritm o găsiți în [`kruskal.cpp`](kruskal.cpp). **Această abordare este recomandată atunci când graful este rar.**

### 2. Algoritmul lui Prim

Algoritmul lui Prim folosește o abordare similară cu Dijkstra. Pornind de la un nod, se adaugă treptat nodurile în APM, alegând mereu muchia cu costul minim care leagă un nod din APM de un nod din afara acestuia. Pentru a eficientiza selecția muchiei cu costul minim, se folosește un `priority_queue`. Astfel, complexitatea acestui algoritm este $O(M \log N)$, unde $N$ este numărul de noduri și $M$ este numărul de muchii din graf. O implementare a acestui algoritm o găsiți în [`prim.cpp`](prim.cpp). **Această abordare este recomandată atunci când graful este dens.**

Puteți trimite soluții [aici](https://infoarena.ro/problema/apm).

## Probleme

* [Bile](https://infoarena.ro/problema/bile)
* [Mexc](https://infoarena.ro/problema/mexc)
* [Curcubeu](https://infoarena.ro/problema/curcubeu)
* [Jstc](https://infoarena.ro/problema/jstc)
* [Desen](https://infoarena.ro/problema/desen)
* [Retea2](https://www.infoarena.ro/problema/retea2)
* [Ninjago](https://kilonova.ro/problems/27)

#### Cursul de azi a fost ținut de Ivan Andrei-Cristian.