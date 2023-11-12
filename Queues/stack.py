class Stack:
    stack = []
    top = 0

def stack_empty(s):
    return s.top == 0

def push(s, x):
    s.stack.append(x)
    s.top = s.top+1

def pop(s):
    if stack_empty(s):
        return "stack is empty"
    else:
        s.top = s.top -1
        return s.stack.pop() # s.stack[s.top]

if __name__ == "__main__":
    s = Stack()
    print(s.stack, s.top,stack_empty(s))
    push(s, 1)
    push(s, 2)
    print(s.stack, s.top,stack_empty(s))
    pop(s)
    print(s.stack, s.top,stack_empty(s))
