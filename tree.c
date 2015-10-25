#include <stdio.h>
#include <stdlib.h>

typedef struct node {
int data;
struct node *pleft;
struct node *pright;
} Node;

printinorder (Node *proot)
{

if (proot == 0 )
{
  return;
}

printinorder(proot->pleft);
printf("%d ", proot->data);
printinorder(proot->pright);

}

printmin(Node *proot)
{
  if (proot == 0x0) { printf("Empty tree\n"); return; }

  while(proot->pleft != 0) { proot = proot->pleft; }

  printf("Min value is %d\n", proot->data);
}

printpreorder (Node *proot)
{

if (proot == 0 )
{
  return;
}

printf("%d ", proot->data);
printpreorder(proot->pleft);
printpreorder(proot->pright);

}

printpostorder(Node *proot)
{
  if (proot == 0x0) return;
  printpostorder(proot->pleft);
  printpostorder(proot->pright);
  printf("%d ", proot->data);
}

Node * add (Node *proot, int i)
{

if (proot == 0)
{
  proot = (Node *)malloc (sizeof(Node));
  proot->data = i;
  proot->pleft = 0;
  proot->pright = 0;
  printf("\n Added node %d", proot->data);

  return proot;
}

if (i > proot->data) { proot->pright = add(proot->pright, i); }
else { proot->pleft = add(proot->pleft, i); }

return proot;
}

int treesize(Node *pnode)
{
   static int size = 0;
   if (pnode == 0x0) return;

   size++;
   treesize(pnode->pleft);
   treesize(pnode->pright);

   return size;
}

int findnode(Node *pnode, int num)
{
   if (pnode == 0x0) { return 0; }

   if (pnode->data == num) { return 1; } 
   else if (pnode->data > num) { return(findnode(pnode->pleft, num)); }
   else { return(findnode(pnode->pright, num));}

}

Node *getnode(Node *pnode, int num)
{
   Node *gnode = 0x0;
   if (pnode == 0x0) return 0x0;

   if (pnode->data == num) { return pnode; }
   else if (pnode->data > num) { gnode = getnode(pnode->pleft, num); }
   else {  gnode = getnode(pnode->pright, num); }
   return gnode;
}

#if 0
Node * inorderSuc (Node *proot, Node *pcurrent)
{
   if (pcurrent->right != 0x0)
   {
      while(pcurrent
   }
   
   if (proot
}

Node *delete (Node *proot, int num)
{
   Node *pdelnode = 0x0;
   Node *pinordersuc = 0x0;
   if (proot == 0x0) { return proot; } 

   // Find the node
   // If the node has both left & right child, Get the in-order successor, ie the next greater number and replace.

   pdelnode = findnode(proot, num);

   if (pdelnode == 0x0) { return proot; }
 
   // No children
   if ((pdelnode->pleft == 0x0) && (pdelnode->pright == 0x0)) 
   { 
      free(pdelnode);
      pdelnode = 0x0;
      return proot;
   }

   if (pdelnode->pleft != null) 
   {
      pdelnode->data = pdelnode->pleft->data;
      free(pdelnode->pleft);
      pdelnode->pleft = 0x0;
   }
   else { 
      pdelnode->data = pdelnode->pright->data;
      free(pdelnode->pright);
      pdelnode->pright = 0x0;
   }

   pinordersuc = findInorderSuc(pdelnode); 
  
   if (pinordersuc != 0x0) 
   { 
     pdelnode->data = pinordersuc->data;

     delete();
   }
}
#endif

int height(Node *proot)
{
   int maxleft = 0;
   int maxright = 0;

   if (proot == 0x0)
     return 0;

   maxleft = height(proot->pleft);
   maxright = height(proot->pright);

   if (maxleft > maxright) { return maxleft+1; }
   else return maxright+1;

}
Node *a[100];
void printlevelorder(Node *proot) 
{
    int build_idx = 0;
    int read_idx = 0;
    Node *pnode = proot;
    if (pnode == 0x0) return;
    printf("\nPrinting level order: ");
    do { 
        printf ("%d ", pnode->data);
        if (pnode->pleft) a[build_idx++] = pnode->pleft;
        if (pnode->pright) a[build_idx++] = pnode->pright;
        pnode = a[read_idx++];
    }while(pnode);
}

int haspathsum(Node *proot, int sum)
{
   int subsum = 0;
   if (!proot) {
    return (sum==0);
   }else { 
      subsum = sum - proot->data;
      if (subsum <= 0 && (proot->pleft || proot->pright)) return 0; // Return false; as number given is less than the path sum
      return (haspathsum(proot->pleft, subsum) || haspathsum(proot->pright, subsum));
   }
}

void printpath(Node *proot, int *a, int len)
{
    int i = 0;
    if (!proot) { 
        return;
    }

    a[len++] = proot->data;
    if (!proot->pleft && !proot->pright) { 
        if (len) { printf ("\n Path: "); } else return;

        while(len) { printf(" %d ", a[i++]); len--; }
    }
    printpath(proot->pleft, a, len);
    printpath(proot->pright, a, len);
}

void mirror(Node *pnode) 
{
    Node *ptemp = 0x0;
    if (!pnode) return;
    ptemp = pnode->pleft;
    pnode->pleft = pnode->pright;
    pnode->pright = ptemp;

    mirror(pnode->pleft);
    mirror(pnode->pright);
}

void duplicate(Node *pnode)
{
    Node *ptemp = 0x0;
    if (pnode == 0x0) return;

    ptemp = (Node *)malloc (sizeof(Node));
    ptemp->data = pnode->data;
    ptemp->pleft = pnode->pleft;
    ptemp->pright = 0x0;

    pnode->pleft = ptemp;

    duplicate(ptemp->pleft);
    duplicate(pnode->pright);
}

int sametree(Node *pnode1, Node *pnode2)
{
    if (!pnode1 && !pnode2) return 1;
    if (pnode1 && !pnode2) return 0;
    if (!pnode1 && pnode2) return 0;
 
    if (pnode1->data != pnode2->data) return 0;
    return (sametree(pnode1->pleft, pnode2->pleft) && sametree(pnode1->pright, pnode2->pright));
}

static void join(Node *a, Node *b) {
    a->pright = b;
    b->pleft = a;
}

Node * append(Node *a, Node *b) {
    Node *aLast, *bLast;
    
    if (a==NULL) return(b);
    if (b==NULL) return(a);
    
    aLast = a->pleft;
    bLast = b->pright;
    
    join(aLast, b);
    join(bLast, a);
    
    return(a);
}
Node* treetolist(Node *pnode)
{
    Node *alist = 0x0;
    Node *blist = 0x0;
    if (!pnode) return 0;

    alist = treetolist(pnode->pleft);
    blist = treetolist(pnode->pright);

    pnode->pleft = pnode;
    pnode->pright = pnode;

    alist = append(alist, pnode);
    alist = append(alist, blist);

    return alist;
#if 0 
    //if (!pnode->pleft && !pnode->pright) return 0;

    // Set head if not set earlier 
    if (pnode->pleft && !(*phead)) *phead = pnode->pleft;
  
    pnode->pleft->pright = pnode; 
    pnode->pright->pleft = pnode;
    pnode->pright->pright = 0x0;

    *ptail = pnode->pright;
    (*ptail)->pleft = pnode;

    (*phead)->left = *ptail;
    pnode->left = (*ptail);
#endif
}

main ()
{
int pathsum = 26;
int a[100];
Node *proot = 0;
Node *gnode = 0x0;
Node *plist = 0x0;
Node *ptemp = 0x0;

proot = add(proot, 5);
proot = add(proot, 2);
proot = add(proot, 1);
proot = add(proot, 4);
proot = add(proot, 3);
proot = add(proot, 6);
proot = add(proot, 7);
proot = add(proot, 7);
proot = add(proot, 8);
proot = add(proot, 7);
proot = add(proot, -1);
printf("\n Same tree %d %d", sametree(proot, proot->pleft), sametree(proot, proot));
printf ("\n Print paths :"); 
printpath(proot, a, 0);
printf ("\npath sum %d is %d", pathsum, haspathsum(proot, pathsum));
printf("\n Print inorder: ");
printinorder(proot);
printlevelorder(proot);
printf("\n Print post order: ");
printpostorder(proot);
printf("\n Print pre order: ");
printpreorder(proot);
printf("\nHeight of the tree %d", height(proot));
printf("\nTree size %d", treesize(proot));
printf("\nFind 4 %d", findnode(proot, 4));
printf("\nFind 3 %d", findnode(proot, 3));
printf("\nFind 7 %d", findnode(proot, 7));
printf("\nFind 17 %d", findnode(proot, 17));
printf("\nFind 8 %d", findnode(proot, 8));
printf("\nFind 6 %d", findnode(proot, 6));
gnode = getnode(proot, 6);
printf("\nFind 0 %p %d", gnode, gnode->data);
gnode = getnode(proot, 0);
printf("\nFind 6 %p %d", gnode, gnode?gnode->data:-1);
#if 0
printmin(proot);
mirror(proot);
printlevelorder(proot);
printf ("\n Print paths :"); 
printpath(proot, a, 0);
printf ("\n Duplicate tree :");
duplicate(proot);
printf ("\n Print paths :"); 
printpath(proot, a, 0);
#endif
printf("\n Tree to list : ");
plist = treetolist(proot);

ptemp = plist;
do {
   printf("%d ", ptemp->data);
   ptemp = ptemp->pright;
}while(ptemp!= plist);

}
