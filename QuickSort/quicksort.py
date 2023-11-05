def partition(A, p, r):
    print(f"PRINTING P={p} and R={r}")
    x = A[r] #select the pivot, so the last element
    i = p-1 # i points to -1
    for j in range(p, r):
        if A[j] <= x:
            i = i+1 # increment i so that i points to the value of A[j] initially
            A[i],A[j] = A[j],A[i] #swap A[i] with A[j]
            print(A[i], A[j], f"ed {A}")
            #print(f"the if condition happens {A}")
        else:
            print("la parition non ha fatto nulla")
    A[r],A[i+1] = A[i+1],A[r]
    print(f"scambio finale della parition,{A[i+1]} con {A[r]}")
    print(f"after each partition parition {A} and q={i+1}")
    return i+1



def quicksort(A, p, r):
    if p<r:
        q = partition(A, p,r)
        print("COMINCIO CON LA METÀ DI SINISTRA\n")
        quicksort(A, p, q-1)
        print("Cominciio con la metà di destra\n")
        quicksort(A, q+1, r)

if __name__ == "__main__":
    A = [2,8,7,1,3,5,6,4]
    print(f"before {A}")
    quicksort(A,0, len(A)-1)
    print(f"after: {A}")
    