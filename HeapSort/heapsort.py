# def parent(i):
#     return int(i/2)

# def left(i):
#     return 2i

# def right(i):
#     return 2i+1

# def max_heapify(A,i):
#     l = left(i)
#     r = right(i)
#     if l <= A.heap_size and A[l] > A[i]:
#         massimo = l
#     else:
#         massimo = i
#     if r <= A.heap.size and A[r] > A[massimo]:
#         massimo = r

#     if massimo != i:
#         app = A[i]
#         A[i] = A[massimo]
#         A[massimo] = app
#         max_heapify(A, massimo)


# def build_max_heap(A):
#     A.heap_size = A.length
#     for i in range(int(A.length/2), 1):
#         max_heapify(A,i)

# def heapsort(A):
#     build_max_heap(A)
#     for i in range(A.length, 1):
#         app = A[1]
#         A[1] = A[i]
#         A[i] = app
#         A.heap_size = A.heap_size - 1
#         max_heapify(A,1)
# class MaxHeap:
#     def __init__(self):
#         self.heap = []

#     def parent(self, i):
#         return (i - 1) // 2

#     def left(self, i):
#         return 2 * i + 1

#     def right(self, i):
#         return 2 *(i + 2)

#     def push(self, value):
#         self.heap.append(value)
#         self._heapify_up(len(self.heap) - 1)

#     def pop(self):
#         if len(self.heap) == 0:
#             return None
#         if len(self.heap) == 1:
#             return self.heap.pop()
#         root = self.heap[0]
#         self.heap[0] = self.heap.pop()
#         self._heapify_down(0)
#         return root

#     def _heapify_up(self, i):
#         while i > 0 and self.heap[i] > self.heap[self.parent(i)]:
#             self.heap[i], self.heap[self.parent(i)] = self.heap[self.parent(i)], self.heap[i]
#             i = self.parent(i)

#     def _heapify_down(self, i):
#         left_child = self.left(i)
#         right_child = self.right(i)
#         largest = i

#         if left_child < len(self.heap) and self.heap[left_child] > self.heap[largest]:
#             largest = left_child

#         if right_child < len(self.heap) and self.heap[right_child] > self.heap[largest]:
#             largest = right_child

#         if largest != i:
#             self.heap[i], self.heap[largest] = self.heap[largest], self.heap[i]
#             self._heapify_down(largest)

if __name__ == "__main__":
    
    
    
    # heap = MaxHeap()

    # values = [4, 10, 3, 5, 1, 15]
    # for value in values:
    #     heap.push(value)

    # print("Max Heap:", heap.heap)

    # sorted_values = []
    # while len(heap.heap) > 0:
    #     sorted_values.append(heap.pop())

    # print("Sorted values:", sorted_values)
