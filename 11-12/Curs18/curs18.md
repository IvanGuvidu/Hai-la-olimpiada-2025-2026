# SQRT Decomposition, Algoritmul lui Mo, Pinex

## SQRT Decomposition, Algoritmul lui Mo

**SQRT Decomposition** este o tehnică de preprocesare a datelor care permite răspunsuri rapide la interogări pe intervale. Ideea de bază este să împărțim datele în blocuri de dimensiune aproximativă $\sqrt{N}$ și să precalculam informații pentru fiecare bloc. Astfel, pentru o interogare pe un interval, putem combina rezultatele din blocurile complete și să procesăm separat elementele rămase.

**Algoritmul lui Mo** este un algoritm eficient pentru rezolvarea problemelor de interogare pe intervale, care utilizează ideea de SQRT Decomposition. Algoritmul lui Mo sortează queryurile în funcție de blocurile în care se află și procesează acestea într-o ordine optimă pentru a minimiza numărul de mutări ale capetelor de interval.

* [Rangemode](https://infoarena.ro/problema/rangemode) - soluție [aici](rangemode.cpp)
* [Infinity War](https://infoarena.ro/problema/infinitywar)
* [Piezișă](https://infoarena.ro/problema/piezisa)

## Principiul includerii și al excluderii (Pinex)

Principiul includerii și al excluderii este o tehnică combinatorică care permite calcularea numărului de elemente dintr-o reuniune de mulțimi, ținând cont de suprapunerea acestora. Formula generală este:

$$
|\bigcup_{i = 1}^{n} A_i| = \sum_{i=1}^{n} |A_i| - \sum_{1 \leq i < j \leq n} |A_i \cap A_j| + \sum_{1 \leq i < j < k \leq n} |A_i \cap A_j \cap A_k| - ... + (-1)^{n-1} |A_1 \cap A_2 \cap ... \cap A_n|
$$

### Funcția Möbius

Când lucrăm cu PINEX pe divizori, trebuie să avem grijă să nu numărăm de mai multe ori aceleași elemente. Pentru a face acest lucru, folosim funcția Möbius, care ne ajută să determinăm dacă un număr are un număr par sau impar de divizori primi. Funcția Möbius este definită astfel:

- $\mu(n) = 0$ dacă $n$ are în factorizare un factor prim cel puțin la puterea a 2-a
- $\mu(n) = 1$ dacă $n = 1$
- $\mu(n) = (-1)^k$ dacă $n$ se scrie ca produs de $k$ divizori primi distincți

* [Pinex](https://www.infoarena.ro/problema/pinex) - soluție [aici](pinex.cpp)
* [TreeGCD](https://www.infoarena.ro/problema/treegcd)
* [Secvxor](https://www.infoarena.ro/problema/secvxor)
* [Sum Tree](https://kilonova.ro/problems/305)

## Atenție! Acesta a fost ultimul curs de HLO XI-XII pe acest an școlar. Vă mulțumesc pentru prezența de anul acesta, mie mi-a plăcut mult să țin cursuri pentru grupa voastră și poate ne mai vedem pe viitor. Baftă la ONI și nu numai!

#### Cursul de azi a fost ținut de Ivan Andrei-Cristian.
