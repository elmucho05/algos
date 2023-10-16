def parent(i):
    return int(i/2)

def left(i):
    return 2i

def right(i):
    return 2i+1

def max_heapify(A,i):
    l = left(i)
    r = right(i)
    if l <= A.heap_size and A[l] > A[i]:
        massimo = l
    else:
        massimo = i
    if r <= A.heap.size and A[r] > A[massimo]:
        massimo = r

    if massimo != i:
        app = A[i]
        A[i] = A[massimo]
        A[massimo] = app
        max_heapify(A, massimo)


def build_max_heap(A):
    A.heap_size = A.length
    for i in range(int(A.length/2), 1):
        max_heapify(A,i)

def heapsort(A):
    build_max_heap(A)
    for i in range(A.length, 1):
        app = A[1]
        A[1] = A[i]
        A[i] = app
        A.heap_size = A.heap_size - 1
        max_heapify(A,1)

