#include<iostream>
#include<string.h>
using namespace std;
char stak[50];
class ip
{
int top=-1;
public:
void push(char symb)
{
    if(top>=49)
    {
        cout<<"STACK OVERFLOW";
         return;
    }
    else
    {
          top=top+1;
         stak[top]=symb;
    }
}
char pop()
{
     char item;
     if(top==-1)
     {
            cout<<"STACK IS EMPTY";
            return(0);
      }
      else
     {
            item=stak[top];
            top--;
     }
     return(item);
}
int preced(char ch)
{
      if(ch=='/')
      {
             return(5);
      }
      else if(ch=='*')
      {
            return(4);
      }
      else if(ch=='+' || ch=='-')
      {
             return(3);
      }
      else
      return(2);
}
void post(char infixexp[])
{
      int l;
      int index=0,pos=0;
      char symbol,temp;
      char postfix[40];
      l=strlen(infixexp);
      push('#');
      while(index<l)
      {
             symbol=infixexp[index];
             switch(symbol)
             {
                    case '(': push(symbol);
                    break;
                    case ')': temp=pop();
                    while(temp!='(')
                    {
                            postfix[pos]=temp;
                            pos++;
                            temp=pop();
                    }
                    break;
                    case '+':
                    case '-':
                    case '*':
                    case '/':
                    case '^':
                    while(preced(stak[top])>=preced(symbol))
                    {
                            temp=pop();
                            postfix[pos]=temp;
                            pos++;
                    }
                    push(symbol);
                    break;
                    default: postfix[pos++]=symbol;
                    break;
            }
            index++;
      }
      while(top>0)
      {
               temp=pop();
               postfix[pos++]=temp;
      }
       postfix[pos++]='\0';
       cout<<postfix;
       return;
}
};
int main()
{
    ip p1;
    char infixexp[25];
    cout<<"ENTER THE INFIX EXPRESSION =";
    cin>>infixexp;
    p1.post(infixexp);
}