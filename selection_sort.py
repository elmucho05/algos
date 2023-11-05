"""
The login behind slection sort is the following:
- first we find the index of the samllest element and then we swap it for A[1]
- then we do the same for the second up until *n-1*
- note: we do not execute it the last time beacuse the last element is hte bigest one, so already in order
Selection sort is a Recursive procedure and not a fuction beacuse it does not return anything
"""

def indexMin(A,i,n):
    #say i have indexMin(A,0, 6)
    index_of_min = i #the index of the min value is the first value initially
    
    #scrolling the next elements
    for j in range(i+1, n):
        if A[j] < A[index_of_min]:
            index_of_min = j # i have found a smaller element so i save it's index 
    
    return index_of_min

def selection_sort(A, i, n):
    if i< n-1: # if i haven't finished chekcing all the elements
        #keep chekcing and save and save the index of the smallest element for each turn
        index_min_value = indexMin(A,i,n)
        
        #after finding the index of the min value, you
        #swap A[min_value] with A[1], the A[2] .... A[i]
        # so with A[i] which is the index that i'm using
        A[i],A[index_min_value] = A[index_min_value],A[i]
        return selection_sort(A,i+1, n)

if __name__ == "__main__":
    A = [2,4,3,5,6,1]
    print(A)
    #note that in this case we send the actual length, so 6
    selection_sort(A, 0, len(A))
    print(A)
