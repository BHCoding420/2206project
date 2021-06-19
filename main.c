#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LLNode {
	char e[20];
	int repetition;
	struct LLNode *next;
} LLNode;

typedef struct List {
	LLNode *head;
	LLNode *tail;
} List;

List createList()
{
	List l;
	l.head = l.tail = NULL;
	return l;
}

int isEmpty(List l)
{
    return (l.head==NULL && l.tail==NULL);
}

void insertTail(List *l, char* element)
{
	LLNode *n = (LLNode *)malloc(sizeof(LLNode));
	strcpy(n->e,element);
	n->repetition = 0;

	n->next = NULL;
	if(isEmpty(*l))
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
		printf("word: %s\t", l.head->e);
		printf("repetition: %d\t", l.head->repetition);
		printf("\n");
		l.head = l.head->next;
	}
	printf("\n");
}

void search_and_increment(List *l,char* x)
{
    LLNode* temp = l->head;

    while(temp != NULL)
    {
        if(strcmp(temp->e,x) == 0)
        {
            temp->repetition += 1;
            return;
        }
        temp = temp->next;
    }
    insertTail(l,x);
}
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

typedef struct node{
char val[20];
struct node *right, *left;
} *BT;

BT BTinit(){ return NULL;}

int BTempty(BT a){ return (a==NULL);}



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

             t->right=InsertBST(t->right,x);
        }

        else
        {

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










Main_BT InsertMain_BST(Main_BT t,BT syn,char* x)
{

    if(Main_BTempty(t))
    {

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

            t->right=InsertMain_BST(t->right,syn,x);
        }

        else
        {

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
int getfullCount_helper(BT root,int count)
{

    if (root ==NULL) return count;
    getfullCount_helper(root ->left,count);
    count++;


    getfullCount_helper(root ->right,count);
}

int getfullCount(BT root)
{
    return getfullCount_helper(root,0);
}



void Main_InOrder(Main_BT A)
{
    if (A ==NULL) return;
    Main_InOrder(A ->left);
    printf("word: %s \n\n", A->val);
    printf("synonyms: \n");
    InOrder(A->synonyms);
    printf("nb of synonyms : %d",getfullCount(A->synonyms));

    printf("\n---------- \n");
    Main_InOrder(A ->right);
}





void most_synonyms(Main_BT A,int* count,char* res)
{


    if(A==NULL) return;

    most_synonyms(A->left,count,res);


    if(getfullCount(A->synonyms) > *count)
    {

        *count = getfullCount(A->synonyms);


        strcpy(res,A->val);

    }
    most_synonyms(A->right,count,res);
}

char* most_synonyms_main(Main_BT root)
{
    char* s =(char*)malloc(20*sizeof(char));
    int count = 0;
    most_synonyms(root,&count,s);
    return s;
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

int search_in_synonyms(BT synonyms,char* key)
{
    if (synonyms == NULL)
       return 0;
    if(strcmp(synonyms->val,key) == 0)
    {
        return 1;
    }

    // Key is greater than root's key
    if (comparison(synonyms->val,key)==0)
       return search_in_synonyms(synonyms->right, key);

    // Key is smaller than root's key
    return search_in_synonyms(synonyms->left, key);
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


    if (comparison(root->val,key)==0)
    {

       return SynonymsOfWord(root->right, key);
    }


    else
    {

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

void words_having_synonym(Main_BT root,char* key)
{
    if (root ==NULL) return;
    words_having_synonym(root ->left,key);


    if(search_in_synonyms(root->synonyms,key) == 1)
    {
        printf("%s-",root->val);
    }

    words_having_synonym(root ->right,key);
}

void synonyms_to_list(BT root,List* l)
{
    if (root ==NULL) return;
    synonyms_to_list(root ->left,l);


    search_and_increment(l,root->val);



    synonyms_to_list(root ->right,l);
}





void most_repeated_synonym_helper(Main_BT root,List* l)
{
    if(root == NULL) return;
    most_repeated_synonym_helper(root->left,l);

    synonyms_to_list(root->synonyms,l);


    most_repeated_synonym_helper(root->right,l);
}

char* most_repeated_synonym(Main_BT root)
{
    List l = createList();
    most_repeated_synonym_helper(root,&l);
    LLNode* temp = l.head;
     int max = 0;
    char* result = (char*)malloc(20*sizeof(char));
    while(temp != NULL)
    {


        if(temp->repetition > max)
        {

            max = temp->repetition;
            strcpy(result,temp->e);


        }
        temp = temp->next;
    }

    return result;
}

char* synonyms_content(BT root,char* content)
{
    if(root == NULL) return content;
    synonyms_content(root->left,content);

    char word[20];
    strcpy(word,root->val);
    strcat(content,word);
    char c[] = ",";
    strcat(content,c);

    synonyms_content(root->right,content);
}

char* FileAddition_Helper(Main_BT root,char* content)
{
    if(root == NULL) return content;
    FileAddition_Helper(root->left,content);

    char word[20];
    strcpy(word,root->val);
    strcat(content,word);
    char space[] = " ";
    strcat(content,space);
    char c[] = "-";
    strcat(content,c);
    strcat(content,space);

    synonyms_content(root->synonyms,content);
    content[strlen(content)-1] = '\0';




    FileAddition_Helper(root->right,content);
}

char* FileAddition(Main_BT root)
{
    char* content = (char*)malloc(20000 * sizeof(char));
    content = FileAddition_Helper(root,content);
}

int n=1;

int CountNodes(Main_BT root)
{
	if(root==NULL)
		return 0;
	if(root->left!=NULL)
	{
		n=n+1;
		n=CountNodes(root->left);
	}
	if(root->right!=NULL)
	{
		n=n+1;
		n=CountNodes(root->right);
	}
	return n;
}

void storeBSTNodes(Main_BT root, Main_BT nodes[],int* i)
{

    if (root==NULL)
        return;


    storeBSTNodes(root->left, nodes,i);

    nodes[*i] = root;


    (*i)++;
    storeBSTNodes(root->right, nodes,i);
}


Main_BT balanceTreeUtil(Main_BT nodes[], int start,
                   int end)
{

    if (start > end)
        return NULL;


    int mid = (start + end)/2;
    Main_BT root = nodes[mid];




    root->left  = balanceTreeUtil(nodes, start, mid-1);
    root->right = balanceTreeUtil(nodes, mid+1, end);

    return root;
}


Main_BT balanceTree(Main_BT root)
{

    int n = CountNodes(root);
    Main_BT nodes[n];
    int i = 0;
    storeBSTNodes(root, nodes,&i);

    return balanceTreeUtil(nodes, 0, n-1);
}


int main()
{

    printf("welcome to the dictionary app : \n");
    int flag = 1;

    Main_BT Main_root = Main_BTinit();







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

        int i = 0;

           const char s[] = "- ,";
           char *token;
           token = strtok(sentence, s);

           BT syn = BTinit();

           char temp[20];
           int flag = 0;
           while( token != NULL ) {

              if(flag == 0)
              {
                  strcpy(temp,token);
              }
              else
              {
                  syn = InsertBST(syn,token);
              }

              flag = 1;
              token = strtok(NULL, s);
           }

            Main_root = InsertMain_BST(Main_root,syn,temp);



    }

    fclose(fp);





    while(flag)
    {
        int command;
        printf("**************************************************\n");
        printf("please enter one of the following commands : \n");
        printf("1-print the dictionary : \n");
        printf("2-check for a word : \n");
        printf("3-print synonyms of a certain word : \n");
        printf("4-add synonyms to a certain word : \n");
        printf("5-find the word with highest nb of synonyms : \n");
        printf("6-find the words that have a certain synonym : \n");
        printf("7-most repeated word as synonym : \n");
        printf("8-save current dictionary to file : \n");
        printf("9-balance the dictionary \n");
        printf("other-save & exit the program \n");
        printf("**************************************************\n");

        scanf("%d",&command);

        switch(command){
        case 1:
            {
                Main_InOrder(Main_root);
                break;
            }
        case 2:
            {
                char s[20];
                printf("enter the word you want to search for : \n");
                scanf("%s",s);
                printf("%d \n\n",search(Main_root,s));
                break;
            }
        case 3:
            {
                char s[20];
                printf("enter the word whose synonyms you want : \n");
                scanf("%s",s);
                SynonymsOfWord(Main_root,s);
                break;
            }
        case 4:
            {
                char s[20];
                printf("enter the word you want to add a synonym to : \n");
                scanf("%s",s);

                char synonym[20];
                printf("enter the synonym : \n");
                scanf("%s",synonym);

                AddSynonym(Main_root,s,synonym);
                break;
            }

        case 5:
            {
                char res[20];
               printf("the word with most synonyms is : %s \n",most_synonyms_main(Main_root));
                break;
            }
        case 6:
            {
                char s[20];
                printf("enter the synonym : \n");
                scanf("%s",s);
                words_having_synonym(Main_root,s);
                printf("\n\n");
                break;
            }
        case 7:
            {
                printf("the most repeated word as synonym is : %s \n",most_repeated_synonym(Main_root));
                break;
            }
        case 8:
            {
                char* res = FileAddition(Main_root);
                 fp = fopen("dictionary.txt","w");

                if(fp == NULL)
                {
                    perror("error:");
                }

                fprintf(fp,res);

                fclose(fp);

                printf("file succesfully updated \n");
                break;
            }
        case 9:
            {
                Main_root = balanceTree(Main_root);
                printf("tree succesfully balanced \n");
                n = 1;
                break;
            }
        default:
            {
                printf("\n\nBye!");
                flag = 0;
            }





        }




    }




    //Main_InOrder(Main_root);
    //InOrder(Main_root->synonyms);
    //printf("%d\n",search_in_synonyms(Main_root->synonyms,"truant"));
    //SynonymsOfWord(Main_root,"acquire");
    //Main_InOrder(search2(Main_root,"adamant"));
    //SynonymsOfWord(Main_root,"adamant");

    /*AddSynonym(Main_root,"absent","exist");
    AddSynonym(Main_root,"adamant","exist");
    AddSynonym(Main_root,"according","exist");
    AddSynonym(Main_root,"adder","exist");
    AddSynonym(Main_root,"abundance","exist");*/


    //printf("\n\nfinal result : %s",s);

    //words_having_synonym(Main_root,"give");
    //char content[10000];
    //char* res = FileAddition_Helper(Main_root,content);
    //printf("%s",FileAddition(Main_root));









    return 0;
}
