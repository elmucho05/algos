class Coda:
    coda = []
    head = 0
    tail = 0

def enqueue(q,x):
    #q.coda[q.tail] = x
    q.coda.append(x)
    if q.tail == len(q.coda):
        q.tail = 1
    else:
        q.tail = q.tail+1

def dequeue(q):
    x = q.head
    if q.head == len(q.coda):
        q.head = 1
    else:
        q.head = q.head +1
    return x
if __name__ == "__main__":
    coda = Coda()
    print(coda.coda)
    enqueue(coda, 1)
    print(coda.coda)
    print(dequeue(coda))
    