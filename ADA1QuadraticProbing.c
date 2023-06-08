#include<stdio.h>
#define size 7
int hash[size];

int h1(int x)
{
    return (x%size);
}
int probing(int key,int i)
{
    return((h1(key)+i*i)%size);
}
void QuadraticInsert(int key,int index)
{
    int probe=0;
    if(hash[index]==NULL)
    {
        hash[index]=key;
    }
    else
    {
        while(hash[index]!=NULL)
        {
            index=probing(key,probe++);
        }
        hash[index]=key;
    }
}

void display()
{
    int i;
    for(i=0;i<size;i++)
        printf("%d \n",hash[i]);
}

void main()
{
    int ch,x,i;
    printf("Menu\n");
    while(1)
    {
    printf("1.Insert with Quadratic Probing\n2.Display Hash Table\n3.Exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: printf("Enter the value to insert\n");
                scanf("%d",&x);
                i=h1(x)%size;
                QuadraticInsert(x,i);
                break;

        case 2: display();
                break;

        case 3: exit(0);

        default: printf("Wrong choice!!\n");
    }
    }
}
