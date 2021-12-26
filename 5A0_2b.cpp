//binary search
#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"Enter number of elements :";
	cin>>n;
	int a[n],i,s,f,l,m;
	cout<<"Enter "<<n<<" elements in sorted order :";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"Enter search element :";
	cin>>s;
	f=0;
	l=n-1;
	m=(f+l)/2;
	while(f<=l)
	{
		if(s<a[m])
		{
			l=m-1;
		}
		else if(s>a[m])
		{
			f=m+1;
		}
		else if(s==a[m])
		{
			cout<<"The element "<<s<<" found at index "<<m;
			break;
		}
		m=(f+l)/2;
	 }
	 if(f>l)
	 cout<<"Not found!!!!";
	
}
