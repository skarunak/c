#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
int a;
struct NODE *pnext;
}node;


void add(node **head, int i)
{
   node *temp = 0x0;
   if (*head == 0x0)
   {
     printf("head is null,so add the first element\n");
     *head = calloc(sizeof(node),1);
     (*head)->a = i;
   }
   else 
   {
     for (temp = *head; temp->pnext!= 0x0; temp=temp->pnext);
     temp->pnext = calloc(sizeof(node),1);
     temp = temp->pnext;
     temp->a = i;
   }
}

void del(node **head, int i)
{
   node *pdelnode = *head; node *ptempnode = *head;

   for (; pdelnode != 0x0; ptempnode = pdelnode, pdelnode=pdelnode->pnext)
   {
      if (pdelnode->a == i)
      {
         if (pdelnode == *head) { *head = pdelnode->pnext; free(pdelnode); return;}
         else { 
            ptempnode->pnext = pdelnode->pnext;
            free(pdelnode);
            return;           
         }
      }
   }
}

void recreverse (node **head)
{
   if (*head == 0x0) { return; }

   node *pfirst = *head;
   node *prest = pfirst->pnext;

   if (prest == 0x0) { return; }

   recreverse(&prest);

   pfirst->pnext->pnext = pfirst;
   pfirst->pnext = 0x0;

   *head = prest;
}

void reverse (node **head)
{
    if (*head == 0x0) { return; } 
    node *pprev = 0x0;
    node *p1 = *head;
    node *p2 = *head;
    node *rev = 0x0;

    while (p2)
    {
       p2 = p2->pnext;
       p1->pnext = pprev;
       rev = p1;
       pprev = p1;
       p1 = p2;
    }

    *head = rev;
}

void print(node *head)
{
   node *temp = 0x0;
   printf("Dump LL \n");

   for (temp = head; temp!= 0x0; temp=temp->pnext)
   {
     printf("%d-> ", temp->a);
   }
   printf("0x0\nEnd of LL\n");
}

main()
{
   node *head = 0x0;
   add(&head, 1);
   add(&head, 3);
   add(&head, 1);
   add(&head, 1);
   add(&head, 3);
   add(&head, 3);
   print(head);
   printf("Reversing ...\n");
   reverse(&head);
   print(head);
/*
   del(&head, 1);
   print(head);
   del(&head, 1);
   print(head);
   del(&head, 1);
   print(head);
   del(&head, 1);
   print(head);
*/
}
