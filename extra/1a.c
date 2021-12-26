#include<stdio.h>
void main()
{
    int n;
    printf("enter n value");
    scanf("%d",&n);
    int array[n];
    printf("cxome on dude u can");
    if(n>0)
    {
    for(int i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    } 
     for(int i=0;i<n;i++)
    {
        printf("%d\n",array[i]);
    } 
    }
    if(n<0)
    {
        printf("wait a sec broo");
    }
}