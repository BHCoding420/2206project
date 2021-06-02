#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 50

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
            return 1;
        }

        else if(s[i]<l[j])
        {
            return 0;
        }

        else
        {
            i++;
            j++;
        }
    }

}


typedef struct LLNode {
	char* e;
	struct Node *next;
} LLNode;

typedef struct List {
	LLNode *head;
	LLNode *tail;
} List;

List* createList()
{
	List* l = (List*)malloc(sizeof(List));
	l->head = l->tail = NULL;
	return l;
}

int LLisEmpty(List l)
{
    return (l.head==NULL && l.tail==NULL);
}

void insertHead(List *l, char* e)
{
	LLNode *n = (LLNode *)malloc(sizeof(LLNode));
	n->e = e;
	if(LLisEmpty(*l))
	{
		n->next = NULL;
		l->tail = n;
	}
	else
		n->next = l->head;
	l->head = n;

}

void insertTail(List *l, char* e)
{
	LLNode *n = (LLNode *)malloc(sizeof(LLNode));
	n->e = e;
	n->next = NULL;
	if(LLisEmpty(*l))
	{
		l->tail = n;
		l->head = n;
	}
	else

	{
		l->tail->next = n;
		l->tail = n;
	}

}

void display(List l)
{
	while (l.head != NULL)
	{
		printf("%s\t", l.head->e);
		l.head = l.head->next;
	}
	printf("\n");
}

int removeHead(List *l)
{
	if(LLisEmpty(*l))
		return 0;
	else {
		LLNode *temp = l->head;
		l->head = l->head->next;
		free(temp);
		return 1;
	}
}

int removeTail(List *l)
{
	if(LLisEmpty(*l))
		return 0;
	else {
		LLNode *it = l->head;
		while (it->next != l->tail)
		{
			it = it->next;
		}
		it->next = NULL;
		LLNode *temp = l->tail;
		l->tail = it;
		free(temp);
		return 1;
	}
}

typedef struct dictionary {
    char* word;
    List* synonymsLists[N];

} dictionary;

typedef struct node{
     dictionary* obj;
    struct node *right, *left;
} *BT;

int empty(BT a){ return (a==NULL);}


BT addnode(dictionary d, BT l, BT r)
{
    BT t= (BT)malloc(sizeof(struct node));
    t->left=l;
    t->right=r;
    t->obj=&d;
    return t;
}

BT InsertBST(BT t,dictionary d)
{
    if(empty(t))
    {
        struct node * n;
         n=(struct node *)malloc(sizeof(struct node));
         n->obj=&d;
         n->right=NULL;
         n->left=NULL;

         return n;

    }

    else
    {

        if(comparison(t->obj->word,d.word)==0)
            t->right=InsertBST(t->right,d);
        else
            t->left=InsertBST(t->left,d);
        return t;
    }

}

int main()
{
    dictionary NodeTwodictionary;
    NodeTwodictionary.word = "sad";


    List* NodeTwodictionaryList1 = createList();
    insertTail(NodeTwodictionaryList1,"upset");
    insertTail(NodeTwodictionaryList1,"angry");
    display(*NodeTwodictionaryList1);

    for(int i = 0;i < N;i++)
    {
        NodeTwodictionary.synonymsLists[i] = createList();
    }
    NodeTwodictionary.synonymsLists[0] = NodeTwodictionaryList1;
    display(*NodeTwodictionary.synonymsLists[0]);

    BT node2 = addnode(NodeTwodictionary,NULL,NULL);
    display( *(node2->obj->synonymsLists[0]) );








    dictionary rootdictionary;
    rootdictionary.word = "happy";


    List* rootdictionaryList1 = createList();
    insertTail(rootdictionaryList1,"amused");
    insertTail(rootdictionaryList1,"overwhelmed");
    display(*rootdictionaryList1);

    for(int i = 0;i < N;i++)
    {
        rootdictionary.synonymsLists[i] = createList();
    }
    rootdictionary.synonymsLists[0] = rootdictionaryList1;
    display(*rootdictionary.synonymsLists[0]);

    BT rootnode = addnode(rootdictionary,node2,NULL);
    display( *(rootnode->obj->synonymsLists[0]) );




    //rootdictionary.synonymsLists = rootdictionaryLists;

    //display(*rootdictionary.synonymsLists[0]);

    //BT root = addnode()






    return 0;
}
