#include <stdio.h>
#include <stdlib.h>

typedef struct node {
int data;
/*struct node *pparent;*/
struct node *pleft;
struct node *pright;
} Node;

void printinorder (Node *proot)
{

if (proot == 0 )
{
  return;
}

printinorder(proot->pleft);
printf("%d ", proot->data);
printinorder(proot->pright);

}

void printmin(Node *proot)
{
  if (proot == 0x0) { printf("Empty tree\n"); return; }

  while(proot->pleft != 0) { proot = proot->pleft; }

  printf("Min value is %d\n", proot->data);
}
// Get min node from this subtree
Node *getmin(Node *proot)
{
   if (proot->pleft == 0) return proot;

   return getmin(proot->pleft);
}

void printpreorder (Node *proot)
{

if (proot == 0 )
{
  return;
}

printf("%d ", proot->data);
printpreorder(proot->pleft);
printpreorder(proot->pright);

}

void printpostorder(Node *proot)
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
   if (pnode == 0x0) return 0;

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

#if 1

// Returns the new root
Node *deletenode (Node *proot, int num)
{
   Node *ptemp = 0x0;
   if (proot == 0x0) { return proot; } 

   // Find the node
   // If the node has both left & right child, Get the in-order successor, ie the next greater number and replace.

   if (num < proot->data) 
       proot->pleft = deletenode(proot->pleft, num); 
   else if (num > proot->data)
       proot->pright = deletenode(proot->pright, num);
   else { 
       // Node to be deleted 
       
       // No children
       if ((proot->pleft == 0x0) && (proot->pright == 0x0)) 
       { 
         free(proot);
         ptemp = 0x0;
         return ptemp;
       } else if (proot->pleft == 0x0)
       {
         ptemp = proot->pright;
         free(proot);
         return ptemp;
       } else if (proot->pright == 0x0)
       {
         ptemp = proot->pleft;
         free(proot);
         return ptemp;
       } // Else both the node exists ...
      /* Pick the in-order successor from right subtree and replace. Then 
         delete that successor node */
      
       ptemp = getmin(proot->pright);
       proot->data = ptemp->data;

       proot->pright = deletenode(proot->pright, ptemp->data);
   } 

   return proot;
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
int height1(Node *proot)
{
   int maxleft = 0;
   int maxright = 0;

   if (proot == 0x0)
     return 0;

   maxleft = height1(proot->pleft) + 1;
   maxright = height1(proot->pright) + 1;

   if (maxleft > maxright) { return maxleft; }
   else return maxright;

}
void printgivenlevel(Node *proot, int level)
{
     if (proot == NULL) return;

     if (level == 0) {
        printf ("%d ", proot->data);
     } else {
        printgivenlevel(proot->pleft, level-1);
        printgivenlevel(proot->pright, level-1);
     }
}

void printlevelorder1(Node *proot)
{
    int h = height(proot);
    int i = 0;

    printf("\nPrinting level order without stack: ");
    for (i=0; i< h; i++) {
        printgivenlevel(proot, i);
    }
}

Node *a[100];
void printlevelorder(Node *proot) 
{
    int build_idx = 0;
    int read_idx = 0;
    Node *pnode = proot;
    if (pnode == 0x0) return;
    printf("\nPrinting level order using stack: ");
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

Node *
common_ancestor(Node *proot, Node *p, Node *q)
{
    if (!proot || !p || !q) return 0;

    if (p->data < proot->data && q->data < proot->data) 
        return common_ancestor(proot->pleft, p, q);
    else if (p->data > proot->data && q->data > proot->data)
        return common_ancestor(proot->pright, p, q);
    // Base case where p & q are in different sub-tree ie common intersection
    return proot;
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
void mirror1(Node *pnode) 
{
    Node *ptemp = 0x0;
    if (!pnode) return;

    mirror1(pnode->pleft);
    mirror1(pnode->pright);

    ptemp = pnode->pleft;
    pnode->pleft = pnode->pright;
    pnode->pright = ptemp;
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

int main ()
{
int pathsum = 26;
int a[100];
Node *proot = 0;
Node *gnode = 0x0;
Node *plist = 0x0;
Node *ptemp = 0x0;
Node *pancestor = 0x0;

proot = add(proot, 5);
proot = add(proot, 3);
proot = add(proot, 6);
proot = add(proot, 2);
proot = add(proot, 4);
proot = add(proot, 7);
#if 0
proot = add(proot, 6);
proot = add(proot, 6);
proot = add(proot, 7);
proot = add(proot, 7);
proot = add(proot, 8);
proot = add(proot, 7);
proot = add(proot, -1);
#endif
printf("\n Same tree %d %d", sametree(proot, proot->pleft), sametree(proot, proot));
printf ("\n Print paths :"); 
printpath(proot, a, 0);
printf("\nHeight of the tree %d %d", height(proot), height1(proot));
//proot = deletenode(proot, 3);
//proot = deletenode(proot, 6);
printf ("\n Print paths :"); 
printpath(proot, a, 0);
printf ("\npath sum %d is %d", pathsum, haspathsum(proot, pathsum));
printf("\n Print inorder: ");
printinorder(proot);
printlevelorder(proot);
printlevelorder1(proot);
pancestor = common_ancestor(proot, getnode(proot, 2), getnode(proot, 4));
printf("\n Ancestor of %d , %d is %d \n", 2,4,pancestor->data);
#if 0
printf("\n Print post order: ");
printpostorder(proot);
printf("\n Print pre order: ");
printpreorder(proot);
printf("\nHeight of the tree %d %d", height(proot), height1(proot));
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
printmin(proot);
#endif
#if 1
printf("\nmirror function ..\n");
mirror(proot);
printlevelorder(proot);
printf ("\n Print paths :"); 
printpath(proot, a, 0);
//printf ("\n Duplicate tree :");
//duplicate(proot);
printf ("\n Print paths :"); 
printpath(proot, a, 0);
printf("\nAnother mirror function ..\n");
mirror1(proot);
printlevelorder(proot);
printf ("\n Print paths :"); 
printpath(proot, a, 0);
//printf ("\n Duplicate tree :");
//duplicate(proot);
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

  return 0;
}
