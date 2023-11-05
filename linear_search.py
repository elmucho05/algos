def linear_search(A,v):
    """
    Input: una sequenza di n numeri A, e un valore v
    Output: un indice 'i' tale che v=A[i] oppure NIL se 'v' non è presente in A
    """
    i=0
    while(i<len(A) and A[i] != v):
        i+=1

    if i<len(A):
        return i
    else:
        return None


if __name__ == "__main__":
    A = [2,4,5,1,3]
    print(linear_search(A,3))
