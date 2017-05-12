#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _stack
{
   void *s; // Stack buffer, bottom of the stack
   int size; // Size of the stack
   int size_left; // Remaining size to grow
   int msg_size;
   void *tos; // Top of the stack
   void (*dump) (struct _stack *s);
}stack;

// return_msg is allocated by the caller
int peek(stack *s, void *return_msg)
{
   if (s->size == s->size_left) return -1;

   memcpy(return_msg, (char *)s->tos -s->msg_size, s->msg_size);
   return 0;   
}

int push(stack *s, void *node)
{
   // Test for space
   if (!s->size_left) {
       s->size_left += s->size;
       s->size *= 2; // So that amortized push is O(n). Every n values only ther e is a realloc done
       s->s = realloc(s->s, s->size);
       if (!s->s) return -1;
   }

   // Give space is found, push the msg
   memcpy(s->tos, node, s->msg_size);
   s->tos = (char *)s->tos + s->msg_size;
   s->size_left -= s->msg_size;

   return 0;
}

// return_msg is allocated by the caller
int pop(stack *s, void *return_msg)
{
   int ret = peek(s, return_msg); 
   if (!ret) {
      s->tos = (char *)s->tos - s->msg_size;
      s->size_left += s->msg_size;
   }
   return ret;
}


int is_empty(stack *s)
{
    return (s->size == s->size_left);
}

int init(stack *s, int msg_size, void (*dump_fn)(stack *s))
{
   s->size = 10 * msg_size;
   s->size_left = 10 * msg_size;
   s->msg_size = msg_size;
   s->s = malloc(s->size * s->msg_size);
   s->tos = s->s;
   s->dump = dump_fn;
}

// Dump for integer version
void dump_int_stack(stack *s)
{
   int i;
   peek(s, &i);
   printf("Stack:: size %d msg_size %d left %d tos %d \n",
      s->size, s->msg_size, s->size_left, i);
}

int main(void)
{
   int i , val;
   stack s;
   init(&s, sizeof(int), dump_int_stack);

   printf ("\nPushing values .. : ");
   for (i = 0; i < 10; i++)  {
     if (push(&s, &i)) { 
        printf("Push failed for %d \n", i);
        s.dump(&s);
        break;
     } else { 
	printf("%d ", i);
     }
   }
 
   printf ("\nPoping values .. : ");
   for (i =0; i < 5; i++) { 
      if (pop(&s, &val)) {
         printf(" Pop failed \n");
         s.dump(&s);
         break;
      } else {
	printf("%d ", val);
      }
   }
   
   s.dump(&s);

   printf ("\nPushing values .. : ");
   for (i = 11; i < 20; i++)  {
     if (push(&s, &i)) { 
        printf("Push failed for %d \n", i);
        s.dump(&s);
        break;
     } else { 
	printf("%d ", i);
     }
   }

   printf ("\nPoping values .. : ");
   for (i =0; i < 15; i++) { 
      if (pop(&s, &val)) {
         printf(" Pop failed \n");
         s.dump(&s);
         break;
      } else {
	printf("%d ", val);
      }
   }
}
