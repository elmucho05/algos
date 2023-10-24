def linear_search(A,v):
    """
    Input: una sequenza di n numeri A, e un valore v
    Output: un indice 'i' tale che v=A[i] oppure NIL se 'v' non è presente in A
    """
    i=0
    while(i<len(A) and A[i] != v):
        i+=1
        print(i)

    if i<len(A):
        return i
    else:
        return NIL

def main():
    A = [2,4,5,1,3]
    print("hello world")
    print(linear_search(A,3))

if __name__ == "__main__":
    main()
