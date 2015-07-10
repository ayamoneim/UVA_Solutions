//Anagrams
//Generate all possible permutations of numbers/alphabets having repeated digits/letters

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char word[12]={'\0'};
int taken[12]={'\0'};
char selected[12]={'\0'};
int length;
char sortme[100000000][12];
int k=0;

void permutations(int index)
{
    if(index==length)
    {
        selected[index]='\0';
        strcpy(sortme[k],selected);
        k++;
        return;
    }
    int i;
    for(i=0;i<length;i++)
    {
        if(!taken[i])
        {
            if(i>0 && word[i]==word[i-1] && !taken[i-1])
            {
            	continue;
            }else
            {
            selected[index]=word[i];
            taken[i]=1;
            permutations(index+1);
            taken[i]=0;
            }
        }
    }
}

void sortme_print()
{
    int j,flag=0;
    char temp[12]={'\0'};
    int i;
    for(i=0;flag==0;i++)
    {
        flag=-1;
        for(j=i+1;j<k;j++)
        {
            if(strcmp(sortme[i],sortme[j])>0)
            {
                strcpy(temp,sortme[i]);
                strcpy(sortme[i],sortme[j]);
                strcpy(sortme[j],temp);
                flag=0;
            }
        }
    }
    for(i=0;i<k-1;i++)
    {
        if(i>0 && strcmp(sortme[i],sortme[i-1])==0)
        {
            continue;
        }else
        {
        puts(sortme[i]);
        }
    }

}

int main()
{
    int test_cases,i,j;
    scanf("%d",&test_cases);
    while(test_cases)
    {
        scanf("%s",word);
        length=strlen(word);
        permutations(0);
        sortme_print();
        length=0;
        k=0;
        test_cases--;

    }
    return 0;
}
