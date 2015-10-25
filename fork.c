#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int x = 100;
int main ()
{
int i, *ptr1 = 0;
pid_t child_pid;
int *ptr = (int *)malloc(20);
for (i = 0; i < 5; i++) { printf ("Pointer b4 assignment %d\n",ptr[i]);  }

printf ("the main program process ID is %d\n", (int) getpid ());
child_pid = fork ();

if (child_pid != 0) {
ptr1 = (int *) malloc(12);
printf("pointer ptr1 value %p\n", ptr1);
for (i = 0; i < 5; i++) { ptr[i] = i; }
for (i = 0; i < 5; i++) { printf ("Pointer inside parent %d\n",ptr[i]);  }
printf("Pointer in parent %p", ptr);
free (ptr);
printf ("this is the parent process, with id %d\n", (int) getpid ());
x = 101;
printf ("the child’s process ID is %d x %d\n", (int) child_pid, x);
}
else {
printf ("sleeping in parent \n");
sleep(5);
for (i = 0; i < 5; i++) { printf ("Pointer inside child %d\n",ptr[i]);  }
printf ("this is the child process, with id %d %d\n", (int) getpid (), x);
printf("Pointer in child %p", ptr);
free (ptr);
printf("ptr1 value in child %p\n", ptr1);
}

return 0;

}

