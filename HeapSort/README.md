![Heap](./heapsort.png)

Un heap (binario) è una struttura dati composta da un array che possiamo consi-
derare come un albero binario quasi completo (vedere il Paragrafo B.5.3), come
illustra la Figura 6.1. Ogni nodo dell’albero corrisponde a un elemento dell’ar-
ray. Tutti i livelli dell’albero sono completamente riempiti, tranne eventualmente
l’ultimo che può essere riempito da sinistra fino a un certo punto.

Ci sono due tipi di heap binari: max-heap e min-heap. In entrambi i tipi, i valori
nei nodi soddisfano una proprietà dell’heap, le cui caratteristiche dipendono dal
tipo di heap. In un max-heap, la proprietà del max-heap è che per ogni nodo i
diverso dalla radice, si ha

A[parent(i)] >= A[i]


invece nel min-heap abbiamo:

A[parent(i)] >= A[i]

dove il più piccolo elemento è la radice.


In questi esempi useremo i max-heap. 
Se osserviamo un heap nella forma di albero, definiamo altezza di un nodo il
numero di archi nel cammino semplice più lungo che dal nodo scende fino a una
foglia. Definiamo altezza di un heap l’altezza della sua radice. Poiché un heap di
n elementi è basato un albero binario completo, la sua altezza.

 Vedremo che le operazioni fondamentali sugli heap vengono eseguite in un tempo che è al massimo proporzionale all’altezza dell’albero e, quindi, richiedono un tempo O(lg n).

