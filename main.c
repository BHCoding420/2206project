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
char val[20];
struct node *right, *left;
} *BT;

BT BTinit(){ return NULL;}

int BTempty(BT a){ return (a==NULL);}


/*BT BTaddnode(char* e, BT l, BT r)
{
BT t= (BT)malloc(sizeof(struct node));
t->left=l;
t->right=r;
t->val=e;
return t;
}*/
BT InsertBST(BT t,char* x)
{
    if(BTempty(t))
    {
        struct node * n;
         n=(struct node *)malloc(sizeof(struct node));
         strcpy(n->val,x);
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
    char val[20];
    BT synonyms;
    struct Main_node *right, *left;

} *Main_BT;

Main_BT Main_BTinit(){ return NULL;}

int Main_BTempty(Main_BT a){ return (a==NULL);}


/*Main_BT Main_BTaddnode(char* e,BT syn,Main_BT l,Main_BT r)
{
Main_BT t= (Main_BT)malloc(sizeof(struct Main_node));
t->left=l;
t->right=r;
t->synonyms = syn;
t->val=e;
return t;
}*/




Main_BT InsertMain_BST(Main_BT t,BT syn,char* x)
{
    //printf("Inserting %s ...\n",x);
    if(Main_BTempty(t))
    {
        //printf("tree is empty:\n");
        struct Main_node *n;
         n=(struct Main_node *)malloc(sizeof(struct Main_node));
         strcpy(n->val,x);
         n->synonyms = syn;
         n->right=NULL;
         n->left=NULL;

         return n;

    }

    else
    {

        if(comparison(t->val,x)==0)
        {
             //printf("%s  >  %s:\n",x,t->val);
            t->right=InsertMain_BST(t->right,syn,x);
        }

        else
        {
            //printf("%s  <  %s:\n",x,t->val);
            t->left=InsertMain_BST(t->left,syn,x);
        }

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

int search(Main_BT root, char* key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL)
       return 0;
    if(strcmp(root->val,key) == 0)
    {
        return 1;
    }

    // Key is greater than root's key
    if (comparison(root->val,key)==0)
       return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}

Main_BT search2(Main_BT root, char* key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL)
       return root;
    if(strcmp(root->val,key) == 0)
    {
        return root;
    }

    // Key is greater than root's key
    if (comparison(root->val,key)==0)
       return search2(root->right, key);

    // Key is smaller than root's key
    return search2(root->left, key);
}
void SynonymsOfWord(Main_BT root, char* key)
{
    //printf("searching for your word \n");
    // Base Cases: root is null or key is present at root
    if (root == NULL)
    {
        printf("the word you entered is not available \n");
       return;
    }

    if(strcmp(root->val,key) == 0)
    {
        printf("the synonyms of %s are \n",root->val);
        InOrder(root->synonyms);
        return;

    }

    // Key is greater than root's key
    if (comparison(root->val,key)==0)
    {
        //printf("less than \n");
       return SynonymsOfWord(root->right, key);
    }


    else
    {
         //printf("greater than \n");
        return SynonymsOfWord(root->left, key);
    }


}

void AddSynonym(Main_BT root,char* word,char* synonym)
{
    Main_BT temp = search2(root,word);
    if(temp != NULL)
    {
        temp->synonyms = InsertBST(temp->synonyms,synonym);
    }

    else
    {
        BT new_synonym = BTinit();
        new_synonym = InsertBST(new_synonym,synonym);
        root = InsertMain_BST(root,new_synonym,word);
    }
}

int main()
{
    //accept-admit, assume, bear, consent, go, have, swallow
    //BT root = (BT*)malloc(sizeof(BT));
    //BT root = BTinit();
    //printf("%d\n",BTempty(root));
    //root->val = "accept";
    //printf("%d\n",root->val);

    /*root = InsertBST(root,"admit");
    root = InsertBST(root,"assume");
    root = InsertBST(root,"bear");
    root = InsertBST(root,"consent");
    root = InsertBST(root,"go");
    root = InsertBST(root,"have");
    root = InsertBST(root,"swallow");
*/
    //InOrder(root);




     //Main_root = InsertMain_BST(Main_root,NULL,"lol");
      //Main_root = InsertMain_BST(Main_root,NULL,"day");
    //InsertMain_BST(Main_root,NULL,"abroad");

    //Main_InOrder(Main_root);
    //Main_InOrder(Main_root);
    //printf("%s",root->val);
    //InsertBST(root,"absent");
    //printf("%s",root->val);



    //abroad - afield, beyond, foreign, overseas, over
    BT node1 = BTinit();
    node1 = InsertBST(node1,"absentminded");
    node1 = InsertBST(node1,"away");
    node1 = InsertBST(node1,"abstracted");


    Main_BT Main_root = Main_BTinit();
    //Main_root = InsertMain_BST(Main_root,node1,"abccept");
    //Main_root = InsertMain_BST(Main_root,NULL,"aabash");
    Main_root = InsertMain_BST(Main_root,node1,"absent");


    //BT node2 = BTinit();
    //node2 = InsertBST(node2,"embarrass");




    //Main_root = InsertMain_BST(Main_root,node1,"abccept");
    //Main_root = InsertMain_BST(Main_root,NULL,"aabash");
    //Main_root = InsertMain_BST(Main_root,node2,"abash");

    //Main_BT Main_node1 = InsertMain_BST(Main_root,node1,"abroad");


    //Main_InOrder(Main_root);


     FILE * fp;
    fp = fopen("dictionary.txt", "r");
    if(fp == NULL)
    {
        perror("error:");
    }
    char sentence[2000];

    int j = 0;

    char word[20]="";


    while(fgets(sentence, sizeof(sentence), fp) != NULL)
    {
        //fputs(sentence,stdout);
        int i = 0;

           const char s[] = "- ,";
           char *token;

           /* get the first token */
           token = strtok(sentence, s);

           BT syn = BTinit();

           char temp[20];

           /* walk through other tokens */
           int flag = 0;
           while( token != NULL ) {
              //printf( " %s\n", token );
              if(flag == 0)
              {
                  strcpy(temp,token);
                  //printf( " %s\n", token );
                  //InsertMain_BST(Main_root,NULL,token);
              }
              else
              {
                  //printf( " %s\n", token );
                  syn = InsertBST(syn,token);
                  //insert to synonyms
              }

              flag = 1;

              token = strtok(NULL, s);
           }
           //printf("MAIN : %s \n\n",temp);
           //InOrder(syn);
           //printf( " %s\n", temp );
            Main_root = InsertMain_BST(Main_root,syn,temp);


        /*while(sentence[i] != ' ')
        {
            //printf("%c",sentence[i]);
            strncat(word, &sentence[i], 1);
            i++;
        }*/


        //Main_root = InsertMain_BST(Main_root,NULL,word);
        //printf("%s \n",temp);
        //printf("%s \n",word);

        //printf("%s \n",word);
        //Main_root = InsertMain_BST(Main_root,NULL,word);
        //word[0] = '\0';

        //temp = word;

        //printf("%d\n",j++);

        //Main_InOrder(Main_root);
        //printf("*******************************8888888888888888888888888888888888888888888888888888888888888888888888888888888888888888\n\n");

    }




    //Main_InOrder(Main_root);
    printf("%d\n",search(Main_root,"absent"));
    //SynonymsOfWord(Main_root,"acquire");
    Main_InOrder(search2(Main_root,"adamant"));
    SynonymsOfWord(Main_root,"adamant");
    AddSynonym(Main_root,"adamant","newSynonym");
    AddSynonym(Main_root,"adamant","abe");

    SynonymsOfWord(Main_root,"adamant");
    fclose(fp);



    return 0;
}
