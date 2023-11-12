class My_Stack:
    def __init__(self, size):
        self.size = size
        self.stack = [None] * size
        self.top = 0

    def __str__(self):
        return str(self.stack[:self.top])
        
def stack_empty(s):
    return s.top == 0

def my_push(s,x):
    s.stack[s.top] = x
    s.top = s.top+1
    

if __name__=="__main__":
    print("Hello")
    my_stack = My_Stack(size=5)
    print("Is stack empty=", stack_empty(my_stack))
    my_push(my_stack, 1)
    my_push(my_stack, 2)
    my_push(my_stack, 3)
    print("Is stack empty=", stack_empty(my_stack))
    print("Stack contents:", my_stack)  # or simply print("Stack contents:", my_stack)
