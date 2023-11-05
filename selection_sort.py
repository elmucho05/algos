"""
The login behind slection sort is the following:
- first we find the index of the samllest element and then we swap it for A[1]
- then we do the same for the second up until *n-1*
- note: we do not execute it the last time

Selection sort is a Recursive procedure and not a fuction beacuse it does not return anything
"""

def selection_sort(A,i,n):
    pass

def indexMin(A,i,n):
    #say i have indexMin(A,0,len(A)-1)
    index_of_min = i #the index of the min value is the first value initially
    
    #scrolling the next elements
    for j in range(i+1, n-1):
        if A[j] < A[index_of_min]:
            index_of_min = j # i have found a smaller element so i save it's index 
    
    return index_of_min


if __name__ == "__main__":
    A = [2,4,3,5,6,1]
    print(A)
    selection_sort(A, 0, len(A)-1)
    print(A)
