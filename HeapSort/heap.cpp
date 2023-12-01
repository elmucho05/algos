#include <iostream>
using namespace std;

int Padre(int i){
    return (i/2)-1;
}

int FiglioSinistro(int i){
    return 2 * i + 1;
}

int FiglioDestro(int i){
    return 2*(i+1);
}

int MinimoHeap(int h[], size_t DimHeap){
    if(DimHeap < 0)
        return -11;
    return h[0];
}

void scambia(int &x, int &y){
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
}

//decrementa la chiave in posizione i, impostandola al valore k
void DecrementaChiaveHeap(int h[], size_t Dimheap, int i, int k){
    if(i>Dimheap || k>h[i])
        cout << "non sono riuscito a decrementare chiave";
    h[i] = k; //imposta il valore di h[i] a k

    while(i>0 && h[Padre(i)] > k){
        scambia(h[i], h[Padre(i)]);
        i = Padre(i);
    }
}

void InserzioneChiaveHeap(int H[],size_t &LungHeap, int &DimHeap, int k){
    if(DimHeap == LungHeap)
        cout << "error inserting key";
    
    DimHeap = DimHeap+1;
    H[DimHeap] = k;
    DecrementaChiaveHeap(H, DimHeap, DimHeap, k);
}

//ripristino della proprietà di ordinamento dopo l'incremento della chiave in poszione i
void Heapify(int H[], int &DimHeap, int i){
    if(i>DimHeap)
        cout << "error reseting order";
    int min = i;
    int s = FiglioSinistro(i);
    int d = FiglioDestro(i);

    if(s<= DimHeap && H[s] < H[i])
        min = s;
    
    if(d<= DimHeap && H[d] < min)
        min = d;
    
    if(min!=i){
        scambia(H[i], H[min]);
        Heapify(H, DimHeap, min);
    }
}

int EstrazioneMinimoDalHeap(int H[], int &DimHeap){
    if(DimHeap<0)
        return -11;
    
    int min = H[0];
    H[0] = H[DimHeap];
    DimHeap = DimHeap-1;
    Heapify(H, DimHeap, 0);
    return min;

}


int main(){
    int myheap[] = {5,7,10,14,8,19,13,17,20,11,21,22, 0, 0, 0, 0};
    size_t LungHeap = sizeof(myheap) / sizeof(myheap[0]);
    int DimHeap = 11;
    for(int i=0; i<LungHeap;i++)
        cout << myheap[i] << " ";
    cout << "\n\n";
    cout << "Minimo heap : "<<  MinimoHeap(myheap, LungHeap) << endl;
    DecrementaChiaveHeap(myheap, LungHeap, 3, 4);
    cout << "Decremento la chiave dell'indice 3 che ha dentro 14 e lo metto a 4 :\n" ;
    for(int i=0; i<LungHeap;i++)
        cout << myheap[i] << " ";

    InserzioneChiaveHeap(myheap, LungHeap, DimHeap, 6);
    cout << "\nInserting 6 in the array\n";
    for(int i=0; i<LungHeap;i++)
        cout << myheap[i] << " ";

    cout << "\nEstrazioneMinimo dal Heap : "<< EstrazioneMinimoDalHeap(myheap, DimHeap);
    cout << "\nPrinting new Heap\n";
    for(int i=0; i<LungHeap; i++)
        cout << myheap[i] << " ";

    return 0;
}