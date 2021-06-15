#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE * fp;
    fp = fopen("synonyms.txt", "r");
    if(fp == NULL)
    {
        printf("error");
    }

    char sentence[1000];

    char userword[20];








    int nbofwords = 0;
    char c;
    int i = 1;
    while(!feof(fp))
    {
        fgets(sentence,1000,fp);

        printf("\n\nline nb %d : ",i);
        printf("%s",sentence);
        int size = strlen(sentence);

        int j = 0;
        while(sentence[j] != ' ')
        {
            j++;
        }

        char tempword[] = "";
        strncat(tempword,sentence,j);
        printf("word: %s\n",tempword);

        int k = j+2;

        char temp[] = "";
        while(k < size )
        {

            if(sentence[k] == ',')
            {
                k++;
                printf("\n\nsynonym: %s",temp);
                temp[0] = '\0';

            }
            if(k == size-1)
            {
                strncat(temp,&sentence[k],1);
                k++;

                printf("\n\nsynonym: %s",temp);
                temp[0] = '\0';

            }

            strncat(temp,&sentence[k],1);

            k++;
        }

        i++;

        char c;


        if(c == '\n')
        {
            nbofwords++;
        }




    }


    fclose(fp);
     /*printf("enter a word: \n");
    scanf("%s",&userword);
    char* newline = userword;
    printf("word : %s\n",newline);
    char temp[20] = " ";
    strncat(newline," - ",3);
    printf("word : %s\n",newline);

    while(1)
    {
        printf("enter a synonym,enter 'no' to quit: \n");
        scanf("%s",&temp);
        if(strcmp(temp,"no") == 0)
        {
            break;
        }
        char another_temp[20] = "";
        strncat(another_temp,temp,strlen(temp));
        strncat(another_temp,", ",2);
        strncat(newline,another_temp,strlen(another_temp));

    }
    newline[strlen(newline)-2] = ' ';
    printf("word : %s\n",newline);*/

    fp = fopen("synonyms.txt", "w");
    if(fp == NULL)
    {
        perror("\n\n error\n");
    }
    fprintf(fp,"%s","iuhdoihso soijspjp");
    fputs("siodo sodb", fp);
    fclose(fp);
    return 0;
}
