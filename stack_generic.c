#include <stdio.h>

typedef struct _stack
{
   char *s; // Stack buffer, bottom of the stack
   int size; // Size of the stack
   int size_left; // Remaining size to grow
   void *tos; // Top of the stack
}stack;

typedef struct _stack_node
{
    void *msg;
    int msg_size;
}stack_node;

int push(stack *s, stack_node *node)
{
}

int pop(stack *s, stack_node *return_msg)
{
}

int peek(stack *s, stack_node *return_msg)
{
}

int is_empty(stack *s)
{
    return (size == size_left);
}

int main(void)
{

}
