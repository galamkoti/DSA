#include<iostream>
using namespace std;
void merge_(int array[],int l,int m,int h)
{
	int  t,r,s;
	int q1=m-l+1,q2=h-m;
    int l1[q1],l2[q2];
	for(t=0;t<q1;t++)
	{
		l1[t]=array[t+l];
	}
	for(r=0;r<q2;r++)
	{
		l2[r]=array[r+m+1];
	}
    t=0;
	s=l;
	r=0;
	while(t<q1 && r<q2)
	{
		if(l1[t]<=l2[r])
		{
			array[s]=l1[t];
			t++;
		}
		else if(l1[t]>l2[r])
		{
			array[s]=l2[r];
			r++;
		}
		s++;
	}
	while(t<q1)
	{
		array[s]=l1[t];
		s++;
		t++;
	}
	while(t<q2)
	{
		array[s]=l2[r];
		s++;
		t++;
	}	
}
void sorting(int b[],int l ,int h)
{
	if(l<h)
	{
		int m=l+(h-l)/2;
		sorting(b,l,m);
		sorting(b,m+1,h);
		merge_(b,l,m,h);
	}
}
int main()
{
	int n;
	cout<<"Enter number of elements :";
	cin>>n;
	int a[n];
	cout<<"Enter elements";
	for(int u=0;u<n;u++)
	cin>>a[u];
	sorting(a,0,n-1);
    cout<<"elements after sorting are"<<endl;
	for(int u=0;u<n;u++)
    {
	cout<<a[u]<<" ";
    }
}