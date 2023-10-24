"""
Considering the following example: 
I am watching the price of the stock of a company and i want to maximize my profit.
The problem is that to maximize the profit, I can't simply "by low, sell high", but

I want to Buy in a certain day and sell in one so that i have the maximum difference 
of the price. (nevermind that i don't start numbering indexes from 0)
          0   1  2  3   4   5   6   7   8    9   10  11  12   13  14  15  16
     A = [13,-3,-25,20,-3, -16,-23, 18, 20, -7, 12, -5, -22, 15, -4,  7]

     Idealy, i want to buy on day 8, and sell on day 11, this way i would have a 43$ profit.

     So i want to find a subarray of A, which values have the maximum sum. 

Let's use a Divide-et-Impera approach
"""


"""
The following function considers the case in which the subarray is not simply a smaller problem 
of the main one. It considers that the maximum sum is found between --> i <= mid <= j
In this case, we have to divide the array from 'i' to 'j' A[i...j] in two smaller ones :
A[i...mid] and A[mid+1...j]. 

After i have found them, I need to Combine them. 

In the end i simply return the indexes 'i' and 'j' and also the maximum sum
"""
def find_max_crossing_subarray(A, low, mid, high):
    left_sum = float('-inf')
    sum = 0
    
    max_left = mid  # Index 'i' which is the beginning of the subarray
    max_right = mid + 1  # Index 'j' which is the end of the subarray

    for i in range(mid, low - 1, -1):  # Start scrolling from mid to left
        sum = sum + A[i]  # Sum every element
        if sum > left_sum:  # If sum is greater than the max_left_sum 
            left_sum = sum 
            max_left = i  # Memorize the index of the element that has the max sum
    
    right_sum = float('-inf')
    sum = 0
    # Same thing on the right subarray
    for j in range(mid + 1, high + 1):  # Corrected the loop range
        sum = sum + A[j]
        if sum > right_sum:
            right_sum = sum
            max_right = j
    return (max_left, max_right, left_sum + right_sum)  # Simply return the indexes of left and right with the maximum sum.



def find_max_subarray(A, low, high):
    if high == low:
        return (low, high, A[low])
    else:
        mid = (low+high)//2

        (left_low, left_high, left_sum) = find_max_subarray(A, low, mid)
        (right_low, right_high, right_sum) = find_max_subarray(A, mid+1, high)
        (cross_low, cross_high, cross_sum) = find_max_crossing_subarray(A, low, mid, high)

        if left_sum >= right_sum and left_sum >= cross_sum:
            return (left_low, left_high, left_sum)
        elif right_sum >= left_sum and right_sum >= cross_sum:
            return (right_low, right_high, right_sum)
        else:
            return (cross_low, cross_high, cross_sum)
            

"""
As for the cost of this algorithm we have:
    - T(n) --> a sequence of n elements
    - we divide the sequence in half everytime --> so b=n/2
    - since we have to solve 2 subproblems, we have 2T(n/2)
    - the "for" loops in 'find_max_crossing_subarray' cost us a total of O(n)
    - and the other operations O(1)
    
    In the end we have : 
        T(n) = 2T(n/2) + O(n) + O(1)
        T(n) = 2T(n/2) + O(n)
"""
if __name__ == "__main__":
    A = [13,-3,-25,20,-3, -16,-23, 18, 20, -7, 12, -5, -22, 15, -4, 7]
    print(A)
    result = find_max_subarray(A, 0, len(A)-1)
    print(result)
