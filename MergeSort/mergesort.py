def merge(A,p,q,r):
    n1 = q-p + 1
    n2 = r-q
    
    L = [0 for x in range(n1+1)]
    R = [0 for x in range(n2+1)]
    for i in range(n1):
        L[i] = A[p+i]
    for j in range(n2):
        R[j] = A[q+1+j]

    L[n1]=-1
    R[n2]=-2
    i=0
    j=0

    print("L = ", L)
    print("R = ", R)
    for k in range(p,r):
        #we don't want to copy our "sentinel values" so we assign them numebers like infinite but since i don't know how, i just assign them -1
        if( (L[i] >=0) and R[j] >= 0):
            #if the first value of the left array is <= than that of the right one:
            if( (L[i] <= R[j]) ):    
                 #copy it's value inside the final array
                A[k] = L[i]
                i = i+1 # increment i
            else:
                #otherwise copy the right's array value inside the final array
                A[k]=R[j]
                j = j+1 # increment j
     #keep going untill you have stuffed the whole array           

def mergesort(A,p,r):
    if p<r:
        prova = (p+r)/2
        q = int(prova)
        mergesort(A,p,q)
        mergesort(A,q+1,r)
        merge(A,p,q,r)

def main():
    A = [2,4,5,7,1,2,3,6]
    print(A)
    mergesort(A, 0, 7)
    #mergesort(A,0,len(A)-1)
    print(A)
if __name__ == "__main__":
    main()
