def partition(A,p,r):
    x = A[r]
    i = p-1
    for j in range(p,r-1):
        if A[j] <= x:
            i = i+1
            app=A[i]
            A[i] = A[j]
            A[j] = app
    tmp = A[i+1]
    A[i+1] = A[r]
    A[r] = app

    return i+1

def quicksort(A,p,r):
    if p<r:
        q = partition(A,p,r)
        quicksort(A,p,q-1)
        quicksort(A,q+1,r)
