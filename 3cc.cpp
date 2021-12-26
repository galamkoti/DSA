 //Quick sort
#include<iostream>
using namespace std;
int partition(int a[],int l,int h)
{
	int p=l,i=p,j=h-1;
	while(i<j)
	{
		while(a[i]<=a[p] && i<h)
		{
			i++;
		}
		while(a[j]>=a[p] && j>p)
		{
			j--;
		}
		if (i<j){
		int temp=a[i];
		a[i]=a[j];
		a[j]=temp;
		}
	}
	int temp=a[p];
	a[p]=a[j];
	a[j]=temp;
	return j;
}
void quicksort(int a[],int l,int h)
{
	if(l<h)
	{
		int j;
		j=partition(a,l,h);
		quicksort(a,l,j);
		quicksort(a,j+1,h);
	}
}
int main()
{
	int n;
	cout<<"Enter number of elements :";
	cin>>n;
	int a[n],i,j;
	cout<<"Enter "<<n<<" elements :";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	quicksort(a,0,n);
	cout<<"The sorted list is ";
	for(i=0;i<n;i++)
	cout<<a[i]<<" ";
}
