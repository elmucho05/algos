"""
The Binary Search is an algorith that uses the Divide-et-Impera
method to divide the problem in subproblems and resolve them recursevly. 

It is a really efficient method to find an element inside an ORDERED ARRAY.
The time efficiency is O(logn)
"""

def binary_search(A,i,j,x):
    mid = (i+j)//2
    
    if A[mid] == x:
        return mid
    if(A[mid] > x):
        return binary_search(A,i, mid, x)
    else:
        return binary_search(A,mid+1, j, x)
    
if __name__=="__main__":
    A = [1,2,3,4,5,6,7,8,9,10]
    print(A)
    to_find = 7
    print(f"L'indice di {to_find} è {binary_search(A,0,len(A)-1, to_find)}")