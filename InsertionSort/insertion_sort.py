def insertion_sort(A):
    for j in range(1,len(A)):
        key=A[j]
        i = j-1
        while i>=0 and A[i]>key:
            A[i+1] = A[i]
            i = i-1
        A[i+1] = key
        print(A)

def main():
    A = [5,2,4,6,1,3]
    print("before : ", A)
    insertion_sort(A)
    print("after  : ", A) 
 #insertion_sort(A)
if __name__ == "__main__":
    main()
