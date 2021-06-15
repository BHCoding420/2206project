#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX(int x1,int x2)
{
    if(x1 > x2)
    {
        return x1;
    }
    else
    {
        return x2;
    }
}
int comparison(char *s,char *l)
{
    if(strcmp(s,l)==0)
       return 1;

  int i=0 , j=0;
  int size1 = strlen(s);
  int size2 = strlen(l);

  int max = MAX(size1,size2);





    while(i<max&&j<max)
    {
        if(s[i]>l[j])
        {
            //printf("%c is greater than %c \n\n",s[i],l[j]);
            return 1;
        }

        else if(s[i]<l[j])
        {
            //printf("%c is less than %c \n\n",s[i],l[j]);
            return 0;
        }

        else
        {
            i++;
            j++;
        }
    }

}

typedef struct node{
char* val;
struct node *right, *left;
} *BT;

BT BTinit(){ return NULL;}

int BTempty(BT a){ return (a==NULL);}


BT BTaddnode(char* e, BT l, BT r)
{
BT t= (BT)malloc(sizeof(struct node));
t->left=l;
t->right=r;
t->val=e;
return t;
}
BT InsertBST(BT t,char* x)
{
    if(BTempty(t))
    {
        struct node * n;
         n=(struct node *)malloc(sizeof(struct node));
         n->val=x;
         n->right=NULL;
         n->left=NULL;

         return n;

    }

    else
    {

        if(comparison(t->val,x) == 0)
        {
            //printf("%s is smaller than %s \n\n",t->val,x);
             t->right=InsertBST(t->right,x);
        }

        else
        {
            //printf("%s is greater than %s \n\n",t->val,x);
            t->left=InsertBST(t->left,x);
        }

        return t;
    }

}

typedef struct Main_node{
    char* val;
    BT synonyms;
    struct Main_node *right, *left;

} *Main_BT;

Main_BT Main_BTinit(){ return NULL;}

int Main_BTempty(Main_BT a){ return (a==NULL);}


Main_BT Main_BTaddnode(char* e,BT syn,BT l, BT r)
{
Main_BT t= (Main_BT)malloc(sizeof(struct Main_node));
t->left=l;
t->right=r;
t->synonyms = syn;
t->val=e;
return t;
}



Main_BT InsertMain_BST(Main_BT t,BT syn,char* x)
{
    if(Main_BTempty(t))
    {
        struct Main_node *n;
         n=(struct Main_node *)malloc(sizeof(struct Main_node));
         n->val=x;
         n->synonyms = syn;
         n->right=NULL;
         n->left=NULL;

         return n;

    }

    else
    {

        if(comparison(t->val,x)==0)
            t->right=InsertMain_BST(t->right,syn,x);
        else
            t->left=InsertMain_BST(t->left,syn,x);
        return t;
    }

}
void InOrder(BT A)
{
    if (A ==NULL) return;
    InOrder(A ->left);
    printf("word: %s \n", A->val);


    InOrder(A ->right);
}

void Main_InOrder(Main_BT A)
{
    if (A ==NULL) return;
    Main_InOrder(A ->left);
    printf("word: %s \n\n", A->val);
    printf("synonyms: \n");
    InOrder(A->synonyms);


    printf("---------- \n");
    Main_InOrder(A ->right);
}


int main()
{
    //accept-admit, assume, bear, consent, go, have, swallow
    //BT root = (BT*)malloc(sizeof(BT));
    BT root = BTinit();
    //printf("%d\n",BTempty(root));
    //root->val = "accept";
    //printf("%d\n",root->val);

    root = InsertBST(root,"admit");
    root = InsertBST(root,"assume");
    root = InsertBST(root,"bear");
    root = InsertBST(root,"consent");
    root = InsertBST(root,"go");
    root = InsertBST(root,"have");
    root = InsertBST(root,"swallow");

    //InOrder(root);



    Main_BT Main_root = Main_BTinit();
    Main_root = InsertMain_BST(Main_root,root,"accept");
    //Main_InOrder(Main_root);
    //printf("%s",root->val);
    //InsertBST(root,"absent");
    //printf("%s",root->val);



    //abroad - afield, beyond, foreign, overseas, over
     BT node1 = BTinit();
    node1 = InsertBST(node1,"beyond");
    node1 = InsertBST(node1,"overseas");
    node1 = InsertBST(node1,"foreign");
    node1 = InsertBST(node1,"afield");


    Main_BT Main_node1 = InsertMain_BST(Main_root,node1,"abroad");


    Main_InOrder(Main_root);

    return 0;
}
