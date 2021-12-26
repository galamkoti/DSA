#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int Stack[20],tos=-1;
void push(int x){
	Stack[++tos]=x;
}
int pop()
{
	return Stack[tos--];
}
void eval(char s[],int a[])
{
	int n=strlen(s),val1,val2;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
		{
			switch(s[i])
			{
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
	cout<<"The result:"<<pop();
}
int main()
{
	int n;
	cout<<"Enter number of variables:";
	cin>>n;
	char s[20];
	cout<<"Enter Expresion:";
	cin>>s;
	int a[n];
	cout<<"Enter values for variables:";
	for(int i=0;i<n;i++)
	cin>>a[i];
	eval(s,a);
}