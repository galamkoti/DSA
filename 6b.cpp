#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class stack
{
    public:
    void push(int);
    int pop();
    void postfix(int a[],char s[]);
}


int main()
{
    stack s1;
    int n;
    cout<<"enter no of variables in exprn";
    cin>>n;
    char s[20];
    int arr[n];
    cout<<"enter values for ur expression";
    for (int i = 0; i < n; i++)
    {
        cout<<"enter"<<i+1<<"value";
        cin>>arr[i];
    }
    s1.postfix(arr,s);
}
void stack::push(int k)
{
    
}
void stack::pop()
{

}
void stack::postfix(int a[],char s[])
{
    int i,val2,val1;
    int n=strlen(s);
    for (int j = 0; j < n; j++)
    {
    if (s[j]=='+'||s[j]=='-'||s[j]=='*'||s[j]=='/')
    {
        switch(s[i]){
				case '+':push(pop()+pop());
				break;
				case '-':val1=pop();
				val2=pop();
				push(val2-val1);
				break;
				case '*':push(pop()*pop());
				break;
				case '/':val1=pop();
				val2=pop();
				push(val2/val1);
				break;
				default:cout<<"Error\n";
			}
	}
    else
    push(a[i]);
	}
    cout<<"the value is"<<pop();
    }
}