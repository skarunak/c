typedef struct node 
{
int data;
struct node *pnext;
} Node;

main ()
{
 Node *phead = 0;

 addnode (&phead, 1);
 addnode (&phead, 2);
 addnode (&phead, 3);
 addnode (&phead, 4);
 addnode (&phead, 5);

 printll (phead); 

 printf("\nDeleting node ...\n");
 delnode(&phead, 3);
 delnode(&phead, 1);
 delnode(&phead, 5);
 delnode(&phead, 2);
 delnode(&phead, 4);
 printll (phead);
 addnode (&phead, 7);
 addnode (&phead, 8);
 addnode (&phead, 9);
 printll (phead);
 delnode(&phead, 3);
 delnode(&phead, 1);
 delnode(&phead, 9);
 delnode(&phead, 5);
 printll (phead);
 addnode (&phead, 1);
 addnode (&phead, 2);
 addnode (&phead, 3);
 printll (phead);
 reversell (&phead);
 printll (phead);
  printf("Recursive Reversing the list ..");
 recreverse(&phead);
 printll (phead);
}

recreverse (Node **pphead)
{
Node *pfirst, *prest;

if (*pphead == 0) { printf ("\nHead is null ..."); return; }

pfirst = *pphead;
prest = pfirst->pnext;

if (prest == 0) { printf ("\nrest is null ..."); return; }

recreverse (&prest);

pfirst->pnext->pnext = pfirst;
pfirst->pnext = 0;

*pphead = prest;

}
reversell (Node **pphead)
{
Node *pn1, *pn2, *rev = 0;

pn1 = pn2 = *pphead;

printf("Reversing the list ..");

while (pn1)
{
  pn1 = pn1->pnext;
  pn2->pnext = rev;
  rev = pn2;
  pn2 = pn1;
}

*pphead = rev;

}
addnode (Node **pphead, int i)
{

Node *node, *tmphead;

if (*pphead == 0)
{
  *pphead = (Node *)malloc (sizeof(Node));
  (*pphead)->data = i;
  (*pphead)->pnext = 0;
  printf("\n Adding node to ll %d- head ", (*pphead)->data);
}
else
{
  tmphead = *pphead;
  for (; tmphead->pnext; tmphead=tmphead->pnext);
  
  tmphead->pnext = (Node *)malloc (sizeof(Node));

  tmphead->pnext->data = i;
  tmphead->pnext->pnext = 0;
  printf("\n Adding node to ll %d ", tmphead->pnext->data);
}

}

printll (Node *phead)
{

if (phead == 0)
{
printf("\nhead is null..."); return 0;
}

do 
{
printf("\nData %d ", phead->data);
phead=phead->pnext;
}while(phead);

}

delnode (Node **pphead, int i)
{

Node *tmpnode=*pphead, *prevnode=*pphead;

if (*pphead == 0)
{
printf("No nodes to delete ..");
return 0;
}

do {

if (tmpnode->data == i)
{

  if (*pphead == tmpnode)
  {
    *pphead = tmpnode->pnext;
    printf("\nhead deleted %d..", tmpnode->data);
    free (tmpnode);
    return 0;
   }

   prevnode->pnext = tmpnode->pnext;
   printf("\nNode deleted %d..", tmpnode->data);
   free(tmpnode);
   return 0;
}
prevnode = tmpnode;
tmpnode = tmpnode->pnext;

}while(tmpnode);

printf("\nNo nodes deleted ....");
}
